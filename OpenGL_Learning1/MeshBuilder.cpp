#include "MeshBuilder.h"
#include "KeyInput.h"
#include <cstdlib>
#include <iostream>
#include <cmath>
#include "VertexArrayObjectPictureFactory.h"
#include "VertexArrayObjectStanderObjectFactory.h"
#include "VertexArrayObjectWaterFactory.h"

#define M_PI 3.14159265358979323846

MeshBuilder::MeshBuilder(std::shared_ptr<Mesh> mesh)
	:mesh(mesh)
{
	if (mesh->GetMeshType() == MeshType::Model)
	{
		Init(std::make_shared<VertexArrayObjectStanderObjectFactory>());
	}
	else if(mesh->GetMeshType() == MeshType::Picture)
	{
        Init(std::make_shared<VertexArrayObjectPictureFactory>());
	}
}

void MeshBuilder::ActiveAllTextures()
{
	shaderProgram->Bind();
	texture1->ActiveTexture(TEXTURE0);
	texture2->ActiveTexture(TEXTURE1);
}

void MeshBuilder::ActiveAllTexturesWithDUVD()
{
	shaderProgram->Bind();
	texture1->ActiveTexture(TEXTURE0);
	texture2->ActiveTexture(TEXTURE1);
	texture3->ActiveTexture(TEXTURE2);
}

void MeshBuilder::ActiveSkyBoxTextures()
{
	shaderProgram->Bind();
	texture1->ActiveSkyBoxTexture(TEXTURE0);
}

void MeshBuilder::ActiveReflectedTexture()
{
	shaderProgram->Bind();
	texture1->ActiveTexture(TEXTURE0);
	texture2->ActiveSkyBoxTexture(TEXTURE1);
}

void MeshBuilder::ActiveFirstTexture()
{
	shaderProgram->Bind();
	texture1->ActiveTexture(TEXTURE0);
}

void MeshBuilder::ActiveSecondTexture()
{
	shaderProgram->Bind();
	texture2->ActiveTexture(TEXTURE1);
}

void MeshBuilder::SetModel()
{
	shaderProgram->Bind();
	shaderProgram->SetMartix4Uniform(model, "model");
}

MeshBuilder::~MeshBuilder()
{
	delete texture1;
	delete texture2;
}

glm::mat4 & MeshBuilder::GetModelMatrix()
{
	return model;
}

void MeshBuilder::Scale(GLfloat x, GLfloat y, GLfloat z)
{
	this->model = glm::scale(this->model, glm::vec3(x, y, z));
}

void MeshBuilder::Rotate(GLfloat angle, glm::vec3 & vec)
{
	this->model = glm::rotate(this->model, glm::radians(angle), vec);
}

void MeshBuilder::Translate(glm::vec3 vec)
{
	this->model =  glm::translate(this->model, vec);
}
void MeshBuilder::CreateMesh(glm::vec3 cubePosition)
{
	this->model = glm::mat4();
	Translate(cubePosition);
}

void MeshBuilder::CreateMesh(glm::vec3 cubePosition,glm::vec3 cubeRoatatione, GLfloat angle)
{
	this->model = glm::mat4();
	
	Translate(cubePosition);
	Rotate(angle, cubeRoatatione);
}

void MeshBuilder::CreateTexture(const char * pathToFirstTexture, const char * pathToSecondTexture)
{
	texture1 = new Texture(pathToFirstTexture, LINEAR, CLAMP_TO_EDGE);
	texture2 = new Texture(pathToSecondTexture, LINEAR, REPEAT);

	shaderProgram->Bind();

	firstTexture = shaderProgram->UniformLocation("ourTexture1");
	secondTexture = shaderProgram->UniformLocation("ourTexture2");

	texture1->Set(firstTexture, 0);
	texture2->Set(secondTexture, 1);
}

void MeshBuilder::CreateFrameBufferTexture()
{
	shaderProgram->Bind();

	texture1 = new Texture(800,600);

	firstTexture = shaderProgram->UniformLocation("reflectedTex");

	texture1->Set(firstTexture, 0);

	texture1->UnBindFrameBuffer();
}

void MeshBuilder::CreateFrameBufferTexture(const char * pathToDuvdMap)
{
	shaderProgram->Bind();

	texture1 = new Texture(800,600);
	texture2 = new Texture(pathToDuvdMap, LINEAR, REPEAT);

	firstTexture = shaderProgram->UniformLocation("reflectedTex");
	secondTexture = shaderProgram->UniformLocation("DUVDmap");

	texture1->Set(firstTexture, 0);
	texture2->Set(secondTexture, 1);

	texture1->UnBindFrameBuffer();

	texture3 = new Texture(800,600);

	thirdTexture = shaderProgram->UniformLocation("rafractedTex");

	texture3->Set(thirdTexture, 2);

	texture3->UnBindFrameBuffer();

}

void MeshBuilder::WatersWave(GLfloat speed)
{
	shaderProgram->SetFloat("moveWave", speed);
}

void MeshBuilder::BindReflectionFrameBufferObject()
{
	texture1->BindFrameBuffer();
	glDrawBuffer(GL_COLOR_ATTACHMENT0);
}

void MeshBuilder::BindRefrectionFrameBufferObject()
{
	texture3->BindFrameBuffer();
}

void MeshBuilder::UnReflectionBindFrameBufferObject()
{
	texture1->UnBindFrameBuffer();
}

void MeshBuilder::UnRefrectionBindFrameBufferObject()
{
	texture1->UnBindFrameBuffer();
}

void MeshBuilder::BindFrameBufferTexture(int width, int height,GLint textureId)
{
	shaderProgram->Bind();
	glBindTexture(GL_TEXTURE_2D, textureId);
}

void MeshBuilder::UnBindFrameBufferTexture(int width, int height)
{
	glViewport(0, 0, width, height);
}

void MeshBuilder::CreateSkyBox(std::vector<const char*> & pathsToTextures)
{
	texture1 = new Texture(pathsToTextures, LINEAR, CLAMP_TO_EDGE,CUBE_MAP);

	shaderProgram->Bind();

	skyboxTexture = shaderProgram->UniformLocation("skybox");

	texture1->Set(skyboxTexture,0);
}

void MeshBuilder::CreateRefletedTexture(const char * fTexture,std::vector<const char*> & pathsToTextures)
{
	texture1 = new Texture(fTexture, LINEAR, CLAMP_TO_EDGE);
	texture2 = new Texture(pathsToTextures, LINEAR, CLAMP_TO_EDGE, CUBE_MAP);

	shaderProgram->Bind();

	firstTexture = shaderProgram->UniformLocation("ourTexture1");
	skyboxTexture = shaderProgram->UniformLocation("enviroMap");

	texture1->Set(firstTexture, 0);
	texture2->Set(skyboxTexture, 1);
}

void MeshBuilder::CreateRefletedTextureWithDistorion(const char * fTexture,const char * DuvdPath, std::vector<const char*> & pathsToTextures)
{
	texture1 = new Texture(fTexture, LINEAR, CLAMP_TO_EDGE);
	texture2 = new Texture(pathsToTextures, LINEAR, CLAMP_TO_EDGE, CUBE_MAP);
	texture3 = new Texture(DuvdPath, LINEAR, CLAMP_TO_EDGE);

	shaderProgram->Bind();

	firstTexture = shaderProgram->UniformLocation("ourTexture1");
	duvdTexture = shaderProgram->UniformLocation("DUVDtexture");
	skyboxTexture = shaderProgram->UniformLocation("enviroMap");

	texture1->Set(firstTexture, 0);
	texture2->Set(skyboxTexture, 1);
	texture3->Set(duvdTexture, 2);
}


GLuint MeshBuilder::VaoGetId()
{
	return m_vao->getVao();
}

Texture * MeshBuilder::GetTexture1()
{
	return texture1;
}

Texture * MeshBuilder::GetTexture2()
{
	return texture2;
}

std::shared_ptr<Shader> MeshBuilder::GetVertexShader()
{
	return vertexShader;
}

std::shared_ptr<Shader> MeshBuilder::GetFragmentShader()
{
	return fragmentShader;
}

std::shared_ptr<ShaderProgram> MeshBuilder::GetShaderProgram()
{
	shaderProgram->Bind();
	return shaderProgram;
}

void MeshBuilder::SetLightPoint(glm::vec3 & lightPos,glm::vec3 & lightCol,glm::vec3 & specularLight)
{
	shaderProgram->Bind();
	shaderProgram->SetVec3("light.ambientLight", objectColor);
	shaderProgram->SetVec3("light.diiffuseLight", lightCol);
	shaderProgram->SetVec3("light.position", lightPos);
	shaderProgram->SetVec3("light.specularLight", specularLight);
}

void MeshBuilder::SetClippingPlane(glm::vec4 & vec4)
{
	shaderProgram->Bind();
	shaderProgram->SetVec4("Plane", vec4);
}

void MeshBuilder::SetWaves()
{
	float frequency = 1000.0f;
	float peroidOfFrequent = 1.0f / frequency;
	float dt = glfwGetTime() / 80.0f;
	float F1 = 10.0f;
	float F2 = 30.0f;
	float F3 = 70.0f;
	float F4 = 120.0f;
	shaderProgram->Bind();
	float y1 = std::sin(2 * M_PI * dt * F1);
	float y2 = (1.0f/2.0f) * std::sin(2 * M_PI * dt * F2);
	float y3 = (1.0f/4.0f) * std::sin(2 * M_PI * dt * F3);
	float y4 = (1.0f / 8.0f) * std::sin(2 * M_PI * dt * F4);
	float y5 = (y1 + y2 + y3+y4)/3.0f;
	//shaderProgram->SetFloat("sinUpCoords", y5);
	shaderProgram->SetFloat("sinUpCoords", glfwGetTime());
}

void MeshBuilder::SetLightPointChangeColor(glm::vec3 & lightPos, glm::vec3 & lightCol, glm::vec3 & specularLight)
{
	glm::vec3 lightColor;
	lightColor.x = sin(glfwGetTime() * 2.0f);
	lightColor.y = sin(glfwGetTime() * 0.7f);
	lightColor.z = sin(glfwGetTime() * 1.3f);

	glm::vec3 diffuse = lightColor * glm::vec3(0.5f);
	glm::vec3 ambient = diffuse * glm::vec3(0.2f);
	shaderProgram->Bind();
	shaderProgram->SetVec3("light.ambientLight", ambient);
	shaderProgram->SetVec3("light.diiffuseLight", diffuse);
	shaderProgram->SetVec3("light.position", lightPos);
	shaderProgram->SetVec3("light.specularLight", specularLight);
}

void MeshBuilder::SetMaterial(glm::vec3 & ambient, glm::vec3 & diffuse, glm::vec3 & specular, float shininess)
{
	shaderProgram->Bind();
	shaderProgram->SetVec3("material.ambient", ambient);
	shaderProgram->SetVec3("material.diffuse", diffuse);
	shaderProgram->SetVec3("material.specular", specular);
	shaderProgram->SetFloat("material.shininess", shininess);
}

void MeshBuilder::SetObjectColor(glm::vec3 & objColor)
{
	objectColor = objColor;
}

void MeshBuilder::SetViewPosition(glm::vec3 & viewPos)
{
	shaderProgram->Bind();
	shaderProgram->SetVec3("viewPos", viewPos);
}

void MeshBuilder::SetCameraPosition(glm::vec3 & cameraPos)
{
	shaderProgram->Bind();
	shaderProgram->SetVec3("cameraPosition", cameraPos);
}

int MeshBuilder::GetIndiciesSize()
{
	return mesh->GetIndiciesSize();
}

void MeshBuilder::SetFloatUniform(std::string uniformName,float value)
{
	shaderProgram->Bind();
	shaderProgram->SetFloat(uniformName, value);
}

ModelType & MeshBuilder::GetModelType()
{
	return mesh->GetModelType();
}

void MeshBuilder::Init(std::shared_ptr<VertexArrayObjectFactory> p_vaoFactory)
{
	std::string shaderPath = "Shaders/" + mesh->GetVertexShaderPath();
	vertexShader = std::make_shared<Shader>((char*)shaderPath.c_str(), VERTEX_SHADER);
	shaderPath = "Shaders/" + mesh->GetFragmentShaderPath();
	fragmentShader = std::make_shared<Shader>((char*)shaderPath.c_str(), FRAGMENT_SHADER);

	shaderProgram = std::make_shared<ShaderProgram>(vertexShader->GetShaderId(), fragmentShader->GetShaderId());

    m_vao = p_vaoFactory->createVertexArrayObject(mesh->GetMeshStructure());
}