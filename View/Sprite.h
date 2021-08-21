#ifndef SPRITE_H
#define SPRITE_H

#include <vector>

#include "Core/Texture.h"
#include "Core/Camera.h"
#include "Core/Mesh.h"

#include "../Model/Point.h"

class Sprite
{
public:
	Sprite(std::string textureFilePath);

	void Draw
	(
		Camera& camera,
		Shader& shader,
		Point size,
		glm::vec3 translation = glm::vec3(0.0f, 0.0f, 0.0f),
		glm::quat rotation = glm::quat(0.0f, 0.0f, 0.0f, 1.0f),
		glm::vec3 scale = glm::vec3(1.0f, 1.0f, 1.0f)
	);

protected:
	Mesh mesh1;
	Mesh mesh2;
	std::vector<Texture> loadedTex;

	void createMeshes(std::string textureFilePath);

	// Helps with the assembly from above by grouping floats
	std::vector<glm::vec2> groupFloatsVec2(std::vector<float> floatVec);
	std::vector<glm::vec3> groupFloatsVec3(std::vector<float> floatVec);
	std::vector<glm::vec4> groupFloatsVec4(std::vector<float> floatVec);

	// Assembles all the floats into vertices
	std::vector<Vertex> assembleVertices
	(
		std::vector<glm::vec3> positions,
		std::vector<glm::vec3> normals,
		std::vector<glm::vec2> texUVs
	);
};

#endif