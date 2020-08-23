#include <Honey.h>
#include <Honey/Core/EntryPoint.h>

#include "GameLayer.h"

class Sandbox : public Honey::Application
{
public:
	Sandbox()
	{
		PushLayer(new GameLayer());
	}

	~Sandbox()
	{
	}
};

Honey::Application* Honey::CreateApplication()
{
	return new Sandbox();
}