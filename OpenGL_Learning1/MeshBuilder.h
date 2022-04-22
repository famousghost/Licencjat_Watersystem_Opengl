#include <glad.h>
#include <GLFW\glfw3.h>
#include "KeyInput.h"
#include "Mesh.h"
#include "Shader.h"
#include "ShaderProgram.h"
#include "Texture.h"
#include <string>
#include <vector>
#include <memory>
#include "VertexArrayObjectFactory.h"

#pragma once

enum TypeOfShader
{
	modelShader = 0,
	lightShader
};

class MeshBuilder
{
public:

	MeshBuilder(std::shared_ptr<Mesh>);

	~MeshBuilder();
	
	glm::mat4 & GetModelMatrix();

	void Scale(GLfloat x, GLfloat y, GLfloat z);

	void Rotate(GLfloat radians, glm::vec3 & vec);

	void Translate(glm::vec3 vec);

	void CreateMesh(glm::vec3 cubePosition);

	void ActiveAllTextures();

	void ActiveAllTexturesWithDUVD();

	void ActiveSkyBoxTextures();

	void ActiveReflectedTexture();

	void ActiveFirstTexture();

	void ActiveSecondTexture();

	void SetModel();

	void CreateMesh(glm::vec3 cubePosition,glm::vec3 cubeRoatatione, GLfloat radians);

	void CreateTexture(const char * pathToFirstTexture, const char * pathToSecondTexture);

	void CreateFrameBufferTexture(const char * pathToDuvdMap);

	void WatersWave(GLfloat speed);

	void BindReflectionFrameBufferObject();

	void BindRefrectionFrameBufferObject();

	void UnReflectionBindFrameBufferObject();

	void UnRefrectionBindFrameBufferObject();

	void CreateFrameBufferTexture();

	void BindFrameBufferTexture(int width, int height, GLint textureId);

	void UnBindFrameBufferTexture(int width, int height);

	void CreateSkyBox(std::vector<const char *> & pathsToTextures);

	void CreateRefletedTexture(const char * fTexture, std::vector<const char*>& pathsToTextures);

	void CreateRefletedTextureWithDistorion(const char * fTexture, const char * DuvdPath, std::vector<const char*>& pathsToTextures);

	GLuint VaoGetId();

	Texture * GetTexture1();

	Texture * GetTexture2();

	std::shared_ptr<Shader> GetVertexShader();

	std::shared_ptr<Shader> GetFragmentShader();

	std::shared_ptr<ShaderProgram> GetShaderProgram();

	void SetLightPoint(glm::vec3 & lightPos, glm::vec3 & lightCol, glm::vec3 & specularLight);

	void SetClippingPlane(glm::vec4 & vec4);

	void SetWaves();

	void SetLightPointChangeColor(glm::vec3 & lightPos, glm::vec3 & lightCol, glm::vec3 & specularLight);

	void SetMaterial(glm::vec3 & ambient, glm::vec3 & difusse, glm::vec3 & specular, float shininess);

	void SetObjectColor(glm::vec3 & objColor);

	void SetViewPosition(glm::vec3 & viewPos);

	void SetCameraPosition(glm::vec3 & cameraPos);

	int GetIndiciesSize();

	void SetFloatUniform(std::string,float);

	ModelType & GetModelType();

private:

    void Init(std::shared_ptr<VertexArrayObjectFactory> p_vaoFactory);
	GLint textureUniformLocation;
	GLint firstTexture;
	GLint secondTexture;
	GLint thirdTexture;
	GLint skyboxTexture;
	GLint duvdTexture;

	std::shared_ptr<Mesh> mesh;

	std::shared_ptr<ShaderProgram> shaderProgram;
	std::shared_ptr<Shader> vertexShader;
	std::shared_ptr<Shader> fragmentShader;

	std::shared_ptr<IVertexArrayObject> m_vao;

	Texture * texture1;
	Texture * texture2;
	Texture * texture3;

	glm::vec3 objectColor;

	glm::mat4 model;

	glm::mat4 rotatemat;
};
