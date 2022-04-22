#include "Renderer.h"
#include "Window.h"
#include "Time.h"
#include "Light.h"
#include <math.h>
#include <iostream>
#include <string>
#include "MeshManager.h"


bool changeState = false;

const int SCREEN_WIDTH = 800;
const int SCREEN_HEIGHT = 600;
const float WATER_HEIGHT = -4.0f;

void LoadSkyboxTextures(std::vector<const char *> & faces);
void ReLoadShader(Renderer & renderer, MeshBuilder & meshBuilder);
void DrawScene(Light & light, MeshBuilder & lightMeshBuilder
	, MeshBuilder & cube
	, MeshBuilder & pyramid
	, MeshBuilder & sphere
	, MeshBuilder & terrain
	, MeshBuilder & water
	, MeshBuilder & skyBox
	, Camera & camera
	, Time & time
	, Renderer & renderer
	, glm::vec4 & clipPlaneVec4);
void DrawScene(Light & light, MeshBuilder & lightMeshBuilder
	, MeshBuilder & cube
	, MeshBuilder & pyramid
	, MeshBuilder & sphere
	, MeshBuilder & skyBox
	, MeshBuilder & terrain
	, Camera & camera
	, Time & time
	, Renderer & renderer
	, glm::vec4 & clipPlaneVec4);
std::vector<glm::vec3> meshPosition;


int main()
{
    SET_LOG_TYPE(LogType::ERR);
    LOG("Program Start", LogType::INF);
	std::vector<const char *> skyBoxTexture;

	LoadSkyboxTextures(skyBoxTexture);

	for (int i = 0; i < skyBoxTexture.size(); ++i)
	{
        std::string skyboxTex = skyBoxTexture[i];
        std::string msg = "Loading texture " + skyboxTex;
        LOG(msg, LogType::INF);
	}

	meshPosition.push_back(glm::vec3(-5.0f, 0.0f, 0.0f));
	meshPosition.push_back(glm::vec3(-7.0f, 0.0f, -2.0f));
	meshPosition.push_back(glm::vec3(-1.5f, 0.2f, -2.5f));
	meshPosition.push_back(glm::vec3(-3.8f, 0.0f, -12.3f));
	meshPosition.push_back(glm::vec3(0.0f, 0.0f, -3.5f));
	meshPosition.push_back(glm::vec3(-1.7f, -3.0f, -7.5f));
	meshPosition.push_back(glm::vec3(1.3f, -2.0f, -2.5f));
	meshPosition.push_back(glm::vec3(1.5f, 0.0f, -2.5f));
	meshPosition.push_back(glm::vec3(1.5f, 0.0f, -1.5f));
	meshPosition.push_back(glm::vec3(-1.3f, 0.0f, -1.5f));

	Time time;

	Window window(SCREEN_WIDTH, SCREEN_HEIGHT, "Shader_Wody");

	Renderer renderer;


    MeshManager m_meshManager;
    m_meshManager.setMeshStructureBuilder(std::make_shared<CubeBuilder>());
	MeshBuilder cube(m_meshManager.constructMesh("vertexShaderRef.vlsl", "fragmentShaderRef.flsl", ModelType::WithoutEBO, MeshType::Model));

    m_meshManager.setMeshStructureBuilder(std::make_shared<PictureBuilder>());

	MeshBuilder picture(m_meshManager.constructMesh("vertexShaderPicture.vlsl", "fragmentShaderPicture.flsl", ModelType::WithoutEBO, MeshType::Picture));

    m_meshManager.setMeshStructureBuilder(std::make_shared<SphereBuilder>());

	MeshBuilder sphere(m_meshManager.constructMesh("vertexShader.vlsl", "fragmentShader.flsl", ModelType::WithEBO, MeshType::Model));

    m_meshManager.setMeshStructureBuilder(std::make_shared<CubeBuilder>());

	MeshBuilder skyBox(m_meshManager.constructMesh("CubeMap.vlsl", "CubeMap.flsl", ModelType::WithoutEBO, MeshType::Model));

	MeshBuilder lightMeshBuilder(m_meshManager.constructMesh("vertexShaderLight.vlsl", "fragmentShaderLight.flsl", ModelType::WithoutEBO, MeshType::Model));

    m_meshManager.setMeshStructureBuilder(std::make_shared<PyramidBuilder>());

	MeshBuilder pyramid(m_meshManager.constructMesh("vertexShader.vlsl", "fragmentShader.flsl", ModelType::WithoutEBO, MeshType::Model));

    m_meshManager.setMeshStructureBuilder(std::make_shared<WaterBuilder>());

	MeshBuilder water(m_meshManager.constructMesh("vertexShaderWater.vlsl", "fragmentShaderWater.flsl", ModelType::WithEBO, MeshType::Model));

    m_meshManager.setMeshStructureBuilder(std::make_shared<TerrainBuilder>());

	MeshBuilder terrain(m_meshManager.constructMesh("vertexShaderTerrain.vlsl", "fragmentShaderTerrain.flsl", ModelType::WithEBO, MeshType::Model));


	cube.SetMaterial(glm::vec3(1.0f, 0.5f, 0.31f), glm::vec3(1.0f, 0.5f, 0.31f), glm::vec3(0.5f, 0.5f, 0.5f), 32.0f);
	sphere.SetMaterial(glm::vec3(1.0f, 0.5f, 0.31f), glm::vec3(1.0f, 0.5f, 0.31f), glm::vec3(0.5f, 0.5f, 0.5f), 32.0f);
	pyramid.SetMaterial(glm::vec3(1.0f, 0.5f, 0.31f), glm::vec3(1.0f, 0.5f, 0.31f), glm::vec3(0.5f, 0.5f, 0.5f), 32.0f);
	terrain.SetMaterial(glm::vec3(0.0f, 0.0f, 0.9f), glm::vec3(1.0f, 0.5f, 0.31f), glm::vec3(0.5f, 0.5f, 0.5f), 32.0f);

	Light light(glm::vec3(1.2f, 5.0f, 2.0f), glm::vec3(1.0f, 1.0f, 1.0f));

	Camera camera(window, glm::vec3(0.0f,  0.0f, -6.0f), 45.0f);

	cube.CreateRefletedTexture("Textures/Glass.jpg", skyBoxTexture);
	skyBox.CreateSkyBox(skyBoxTexture);
	sphere.CreateTexture("Textures/metal.jpg", "Textures/awesomeface.png");
	pyramid.CreateTexture("Textures/metal.jpg", "Textures/awesomeface.png");
	terrain.CreateTexture("Textures/grass.jpg", "Textures/grass.jpg");
	water.CreateFrameBufferTexture("Textures/Duvd.png");

	cube.SetObjectColor(glm::vec3(0.0f, 0.0f, 0.5f));
	sphere.SetObjectColor(glm::vec3(0.7f, 0.3f, 0.5f));
	pyramid.SetObjectColor(glm::vec3(0.7f, 0.3f, 0.5f));
	terrain.SetObjectColor(glm::vec3(0.0f, 0.8f, 0.2f));



	double rotationeTime;

	float beginTime = 0.0f;
	float endTime = 0.0f;

	while (window.IsOpen())
	{
		rotationeTime = glfwGetTime();

		glfwSwapBuffers(window.GetWindow());

		glEnable(GL_CLIP_DISTANCE0);

		water.BindReflectionFrameBufferObject();

		float distance = 2.0f * (camera.GetCameraPos().y - WATER_HEIGHT);

		camera.GetCameraPos().y -= distance;

		camera.InverPitch();

		camera.ResetMatrixView();

		renderer.Clear();

		DrawScene(light, lightMeshBuilder, cube, pyramid, sphere, skyBox, terrain, camera, time, renderer,glm::vec4(0.0f,1.0f,0.0f, -WATER_HEIGHT));

		water.UnReflectionBindFrameBufferObject();

        camera.GetCameraPos().y += distance;
		camera.BackToNormal();

		camera.ResetMatrixView();

		water.BindRefrectionFrameBufferObject();

		renderer.Clear();

		DrawScene(light, lightMeshBuilder, cube, pyramid, sphere, skyBox, terrain, camera, time, renderer, glm::vec4(0.0f, -1.0f, 0.0f, WATER_HEIGHT));

		water.UnRefrectionBindFrameBufferObject();

		renderer.Clear();

		camera.BackToNormal();

		DrawScene(light, lightMeshBuilder, cube, pyramid, sphere, terrain,water, skyBox, camera, time, renderer, glm::vec4(0.0f, -1.0f, 0.0f, 1000.0f));

		glDisable(GL_CLIP_DISTANCE0);

	}
    LOG("Program Stop", LogType::INF);
	return 0;
}


void DrawScene(Light & light, MeshBuilder & lightMeshBuilder
	, MeshBuilder & cube
	, MeshBuilder & pyramid
	, MeshBuilder & sphere
	, MeshBuilder & terrain
	, MeshBuilder & water
	, MeshBuilder & skyBox
	, Camera & camera
	, Time & time
	, Renderer & renderer
	, glm::vec4 & clipPlaneVec4)
{
	camera.MoveCamera(2.0f * time.DeltaTime());

	camera.RotateCamera(0.1f, 0.1f);

	camera.ZoomCamera();

	if (KeyInput::inversPitch)
	{
		camera.setPitch(-35.0f);
	}

	light.MoveLight();

	lightMeshBuilder.CreateMesh(light.GetLightPos());
	lightMeshBuilder.SetClippingPlane(clipPlaneVec4);
	renderer.SetMesh(lightMeshBuilder, camera);
	renderer.Draw(lightMeshBuilder);

	float moveFactor = 0.0f;

	for (int i = 0; i < 10; i++)
	{
		if (i % 2 == 0)
		{
			cube.ActiveReflectedTexture();
			cube.SetClippingPlane(clipPlaneVec4);
			cube.SetCameraPosition(camera.GetCameraPos());
			cube.CreateMesh(meshPosition[i], glm::vec3(0.4f, 0.3f, 0.2f), 45.0f);
			renderer.SetMesh(cube, camera);
			renderer.Draw(cube);
		}
		else
		{
			pyramid.ActiveAllTextures();
			pyramid.SetClippingPlane(clipPlaneVec4);
			pyramid.SetLightPoint(light.GetLightPos(), light.GetLightColor(), glm::vec3(1.0f, 1.0f, 1.0f));
			pyramid.SetViewPosition(camera.GetCameraPos());
			pyramid.CreateMesh(meshPosition[i], glm::vec3(0.4f, 0.3f, 0.2f), 45.0f);
			pyramid.Rotate(45.0f * glfwGetTime(), glm::vec3(1.0f, 0.2f, 0.0f));
			renderer.SetMesh(pyramid, camera);
			renderer.Draw(pyramid);
		}
	}

	sphere.ActiveAllTextures();
	sphere.SetClippingPlane(clipPlaneVec4);
	sphere.SetLightPoint(light.GetLightPos(), light.GetLightColor(), glm::vec3(1.0f, 1.0f, 1.0f));
	sphere.CreateMesh(glm::vec3(0.0f, 1.0f, 0.0f));
	renderer.SetMesh(sphere, camera);
	renderer.Draw(sphere);

	terrain.ActiveAllTextures();
	terrain.SetClippingPlane(clipPlaneVec4);
	terrain.SetLightPoint(light.GetLightPos(), light.GetLightColor(), glm::vec3(1.0f, 1.0f, 1.0f));
	terrain.CreateMesh(glm::vec3(200.0f, -3.0f, 200.0f));
	terrain.Scale(2000.0f, 1.0f, 2000.0f);
	renderer.SetMesh(terrain, camera);
	renderer.Draw(terrain);


	water.ActiveAllTexturesWithDUVD();

	water.SetCameraPosition(camera.GetCameraPos());
	water.CreateMesh(glm::vec3(200.0f, WATER_HEIGHT, 200.0f));
	moveFactor += 0.03f * glfwGetTime();
	fmod(moveFactor, 1);
	water.WatersWave(moveFactor);
	water.Scale(2000.0f, 1.0f, 2000.0f);
	renderer.SetMesh(water, camera);
	renderer.Draw(water);

	skyBox.ActiveSkyBoxTextures();
	renderer.DrawSkyBox(skyBox, camera);

}

void DrawScene(Light & light, MeshBuilder & lightMeshBuilder
	, MeshBuilder & cube
	, MeshBuilder & pyramid
	, MeshBuilder & sphere
	, MeshBuilder & skyBox
	, MeshBuilder & terrain
	, Camera & camera
	, Time & time
	, Renderer & renderer
	, glm::vec4 & clipPlaneVec4)
{

	lightMeshBuilder.CreateMesh(light.GetLightPos());
	lightMeshBuilder.SetClippingPlane(clipPlaneVec4);
	renderer.SetMesh(lightMeshBuilder, camera);
	renderer.Draw(lightMeshBuilder);

	for (int i = 0; i < 10; i++)
	{
		if (i % 2 == 0)
		{
			cube.ActiveReflectedTexture();
			cube.SetClippingPlane(clipPlaneVec4);
			cube.SetCameraPosition(camera.GetCameraPos());
			cube.CreateMesh(meshPosition[i], glm::vec3(0.4f, 0.3f, 0.2f), 45.0f);
			renderer.SetMesh(cube, camera);
			renderer.Draw(cube);
		}
		else
		{
			pyramid.ActiveAllTextures();
			pyramid.SetClippingPlane(clipPlaneVec4);
			pyramid.SetLightPoint(light.GetLightPos(), light.GetLightColor(), glm::vec3(1.0f, 1.0f, 1.0f));
			pyramid.SetViewPosition(camera.GetCameraPos());
			pyramid.CreateMesh(meshPosition[i], glm::vec3(0.4f, 0.3f, 0.2f), 45.0f);
			pyramid.Rotate(45.0f * glfwGetTime(), glm::vec3(1.0f, 0.2f, 0.0f));
			renderer.SetMesh(pyramid, camera);
			renderer.Draw(pyramid);
		}
	}


	sphere.ActiveAllTextures();
	sphere.SetClippingPlane(clipPlaneVec4);
	sphere.SetLightPoint(light.GetLightPos(), light.GetLightColor(), glm::vec3(1.0f, 1.0f, 1.0f));
	sphere.CreateMesh(glm::vec3(0.0f, 1.0f, 0.0f));
	renderer.SetMesh(sphere, camera);
	renderer.Draw(sphere);

	terrain.ActiveAllTextures();
	terrain.SetClippingPlane(clipPlaneVec4);
	terrain.SetLightPoint(light.GetLightPos(), light.GetLightColor(), glm::vec3(1.0f, 1.0f, 1.0f));
	terrain.CreateMesh(glm::vec3(200.0f, WATER_HEIGHT-1.0f, 200.0f));
	terrain.Scale(2000.0f, 1.0f, 2000.0f);
	renderer.SetMesh(terrain, camera);
	renderer.Draw(terrain);


	skyBox.ActiveSkyBoxTextures();
	renderer.DrawSkyBox(skyBox, camera);

}


void ReLoadShader(Renderer & renderer, MeshBuilder & meshBuilder)
{
	if (KeyInput::reLoadShader)
	{
		std::string firstTexturePath = renderer.ReLoadPathToTexture("Textures/FirstTexturePath.txt");
		std::string secondTexturePath = renderer.ReLoadPathToTexture("Textures/SecondTexturePath.txt");
		renderer.ReloadShader(firstTexturePath, secondTexturePath, meshBuilder);
	}
}

void LoadSkyboxTextures(std::vector<const char *> & faces)
{
	faces.push_back("Textures/SkyBox/Cloud/xpos.png");
	faces.push_back("Textures/SkyBox/Cloud/xneg.png");
	faces.push_back("Textures/SkyBox/Cloud/ypos.png");
	faces.push_back("Textures/SkyBox/Cloud/yneg.png");
	faces.push_back("Textures/SkyBox/Cloud/zpos.png");
	faces.push_back("Textures/SkyBox/Cloud/zneg.png");
}
