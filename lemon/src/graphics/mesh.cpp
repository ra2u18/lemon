#include "graphics/mesh.h"

#include <glad/glad.h>

namespace lemon::graphics
{
	/// <summary>
	/// The lifetime of the VBO/VAO/EBO will be maintained by this class
	/// When this object goes out of scope, so does the data; use 
	/// the concept of RAII (Resource Aquisition is Initialization)
	/// </summary>
	Mesh::Mesh(float* vertexArray, uint32_t vertexCount, uint32_t dimensions)
	{

	}

	Mesh::~Mesh()
	{

	}
}

