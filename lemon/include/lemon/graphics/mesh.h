#pragma once

#include <cstdint>

namespace lemon::graphics
{
	/// <summary>
	/// Handles VAO/VBO/EBO setup
	/// </summary>
	class Mesh
	{
	public:
		Mesh(float* vertexArray, uint32_t vertexCount, uint32_t dimensions);
		~Mesh();
	private:
		uint32_t mVertexCount;
		uint32_t mPositionVBO;
		uint32_t mVAO;
	};
}