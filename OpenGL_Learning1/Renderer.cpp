#include "Renderer.h"
#include <sstream>


Renderer::Renderer()
{


	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
	{
		std::cerr << "Failed to initialize GLAD" << std::endl;
		exit(0);
	}


	lastFrameTime = 0.0f;
	deltaTime = 0.0f;
}

void Renderer::Clear()
{
	glfwPollEvents();

	glEnable(GL_DEPTH_TEST);

	glClearColor(0.1f, 0.1f, 0.1f, 1.0f);

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}

void Renderer::SetMesh(MeshBuilder & meshBuilder,Camera & camera)
{
	meshBuilder.GetShaderProgram()->SetMartix4Uniform(camera.GetProjectionMatrix(), "projection");
	meshBuilder.GetShaderProgram()->SetMartix4Uniform(camera.GetViewMatrix(), "view");
}

std::string Renderer::ReLoadPathToTexture(std::string pathToTexture)
{
	std::fstream fileToTexturesPath;

	std::stringstream source;
	std::string stringsource;

	fileToTexturesPath.open(pathToTexture,std::ios::in);
	source << fileToTexturesPath.rdbuf();
	fileToTexturesPath.close();
	stringsource = source.str();

	std::cout << stringsource << std::endl;

	return stringsource;
}

void Renderer::ReloadShader(std::string pathToFirstTexture, std::string pathToSecondTexture,MeshBuilder & meshBuilder)
{
	if (KeyInput::reLoadShader)
	{
		system("cls");
		meshBuilder.GetVertexShader()->ReLoadShader("Shaders/vertexShader.vlsl");
		meshBuilder.GetFragmentShader()->ReLoadShader("Shaders/fragmentShader.flsl");
		meshBuilder.GetShaderProgram()->ReLoad(meshBuilder.GetVertexShader()->GetShaderId(), meshBuilder.GetFragmentShader()->GetShaderId());
		meshBuilder.GetTexture1()->ReLoadTexture(pathToFirstTexture);
		meshBuilder.GetTexture2()->ReLoadTexture(pathToSecondTexture);
		KeyInput::reLoadShader = false;
	}
}

void Renderer::Draw(MeshBuilder & meshBuilder)
{
	meshBuilder.SetModel();

	glBindVertexArray(meshBuilder.VaoGetId());
	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);

	if(meshBuilder.GetModelType() == ModelType::WithEBO)
		glDrawElements(GL_TRIANGLES, meshBuilder.GetIndiciesSize(), GL_UNSIGNED_INT, 0);
	else
		glDrawArrays(GL_TRIANGLES, 0, 36);

	glBindVertexArray(0);

}

void Renderer::DrawSkyBox(MeshBuilder & meshBuilder,Camera & camera)
{
	camera.SetViewMatrix();
	SetMesh(meshBuilder, camera);
	glDepthFunc(GL_LEQUAL);
	glBindVertexArray(meshBuilder.VaoGetId());

	glDrawArrays(GL_TRIANGLES, 0, 36);
	
	glBindVertexArray(0);
	glDepthFunc(GL_LESS);

}

void Renderer::Draw(MeshBuilder & meshBuilder,DRAW_TYPE drawingType)
{
	meshBuilder.SetModel();

	glBindVertexArray(meshBuilder.VaoGetId());
	glPolygonMode(GL_FRONT_AND_BACK, drawingType);
	if (meshBuilder.GetModelType() == ModelType::WithEBO)
		glDrawElements(GL_TRIANGLES, meshBuilder.GetIndiciesSize(), GL_UNSIGNED_INT, 0);
	else
		glDrawArrays(GL_TRIANGLES, 0, 36);

	glBindVertexArray(0);

}

void Renderer::DrawFrameBuffer(MeshBuilder & meshBuilder, int s_width, int s_height)
{
	glBindVertexArray(meshBuilder.VaoGetId());
	glDrawArrays(GL_TRIANGLES, 0, 6);
	glBindVertexArray(0);
	//glViewport(0, 0, s_width, s_height);
}