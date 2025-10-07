#include "Application.h"

#include <iostream>
#include <chrono>

Application::Application(const ApplicationSpecification& specification)
	: m_Specification(specification)
{
	// This is a comment
	s_Instance = this;
	Initialize();
}

Application::~Application()
{
	Shutdown();
}

void Application::Run()
{
	while (m_Running)
	{
		auto now = std::chrono::high_resolution_clock::now();
		float time = std::chrono::duration<float>(now.time_since_epoch()).count();
		Timestep timestep = time - m_LastTime;
		m_LastTime = time;

		for (Ref<Layer>& layer : m_Layers)
		{
			layer->OnUpdate(timestep);
		}
	}
}

void Application::PushLayer(Ref<Layer> layer)
{
	std::cout << "New Layer is being pushed" << std::endl;

	m_Layers.push_back(layer);
	layer->OnAttach();
}

void Application::Quit()
{
	m_Running = false;
}

void Application::Initialize()
{
	std::cout << "Application initialized" << std::endl;
}

void Application::Shutdown()
{
	std::cout << "Application shut down" << std::endl;
}
