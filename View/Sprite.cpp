#include "Sprite.h"

Sprite::Sprite(std::string textureFilePath)
{
	createMeshes(textureFilePath);
}

void Sprite::Draw(Camera& camera, Shader& shader, glm::vec3 translation, glm::quat rotation, glm::vec3 scale)
{
	mesh1.Draw(shader, camera, glm::mat4(1.0f), translation, rotation, scale);
	mesh2.Draw(shader, camera, glm::mat4(1.0f), translation, rotation, scale);
}

void Sprite::createMeshes(std::string textureFilePath)
{
	Texture texture((textureFilePath).c_str(), "diffuse", loadedTex.size());
	std::vector<Texture> textures;
	textures.push_back(texture);
	loadedTex.push_back(texture);

	std::vector<float> posVec1 =
	{
		-0.05f, 0.0f, -0.05f,
		-0.05f, 0.0f, 0.05f,
		0.05f, 0.0f, 0.05f
	};
	std::vector<float> posVec2 =
	{
		-0.05f, 0.0f, -0.05f,
		0.05f, 0.0f, 0.05f,
		0.05f, 0.0f, -0.05f
	};
	std::vector<glm::vec3> positions1 = groupFloatsVec3(posVec1);
	std::vector<glm::vec3> positions2 = groupFloatsVec3(posVec2);
	std::vector<float> normalVec =
	{
		0.0f, 1.0f, 0.0f,
		0.0f, 1.0f, 0.0f,
		0.0f, 1.0f, 0.0f
	};
	std::vector<glm::vec3> normals = groupFloatsVec3(normalVec);
	std::vector<float> texVec1 =
	{
		0.0f, 1.0f,
		1.0f, 1.0f,
		1.0f, 0.0f
	};
	std::vector<float> texVec2 =
	{
		0.0f, 1.0f,
		1.0f, 0.0f,
		0.0f, 0.0f
	};
	std::vector<glm::vec2> texUVs1 = groupFloatsVec2(texVec1);
	std::vector<glm::vec2> texUVs2 = groupFloatsVec2(texVec2);

	// Combine all the vertex components and also get the indices and textures
	std::vector<Vertex> vertices1 = assembleVertices(positions1, normals, texUVs1);
	std::vector<GLuint> indices1 = { 0, 2, 1 };
	std::vector<Vertex> vertices2 = assembleVertices(positions2, normals, texUVs2);
	std::vector<GLuint> indices2 = { 0, 2, 1 };

	mesh1 = Mesh(vertices1, indices1, textures, 1, {});
	mesh2 = Mesh(vertices2, indices2, textures, 1, {});
}

std::vector<glm::vec2> Sprite::groupFloatsVec2(std::vector<float> floatVec)
{
	std::vector<glm::vec2> vectors;
	for (int i = 0; i < floatVec.size(); i)
	{
		vectors.push_back(glm::vec2(floatVec[i++], floatVec[i++]));
	}
	return vectors;
}

std::vector<glm::vec3> Sprite::groupFloatsVec3(std::vector<float> floatVec)
{
	std::vector<glm::vec3> vectors;
	for (int i = 0; i < floatVec.size(); i)
	{
		vectors.push_back(glm::vec3(floatVec[i++], floatVec[i++], floatVec[i++]));
	}
	return vectors;
}

std::vector<glm::vec4> Sprite::groupFloatsVec4(std::vector<float> floatVec)
{
	std::vector<glm::vec4> vectors;
	for (int i = 0; i < floatVec.size(); i)
	{
		vectors.push_back(glm::vec4(floatVec[i++], floatVec[i++], floatVec[i++], floatVec[i++]));
	}
	return vectors;
}

std::vector<Vertex> Sprite::assembleVertices(std::vector<glm::vec3> positions, std::vector<glm::vec3> normals, std::vector<glm::vec2> texUVs)
{
	std::vector<Vertex> vertices;
	for (int i = 0; i < positions.size(); i++)
	{
		vertices.push_back
		(
			Vertex
			{
				positions[i],
				normals[i],
				glm::vec3(1.0f, 1.0f, 1.0f),
				texUVs[i]
			}
		);
	}
	return vertices;
}
