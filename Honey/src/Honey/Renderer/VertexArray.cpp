#include "hnpch.h"
#include "Honey/Renderer/VertexArray.h"

#include "Honey/Renderer/Renderer.h"
#include "Platform/OpenGL/OpenGLVertexArray.h"

namespace Honey {

	Ref<VertexArray> VertexArray::Create()
	{
		switch (Renderer::GetAPI())
		{
			case RendererAPI::API::None:    HN_CORE_ASSERT(false, "RendererAPI::None is currently not supported!"); return nullptr;
			case RendererAPI::API::OpenGL:  return CreateRef<OpenGLVertexArray>();
		}

		HN_CORE_ASSERT(false, "Unknown RendererAPI!");
		return nullptr;
	}

}