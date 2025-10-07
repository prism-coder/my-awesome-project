#pragma once

#include "Core/Core.h"
#include "Core/Layer.h"

#include <string>
#include <vector>

struct ApplicationSpecification {
	std::string Name = "App";
};

class Application {
public:
	Application(const ApplicationSpecification& specification = {});
	~Application();

	void Run();
	void PushLayer(Ref<Layer> layer);
	void Quit();

	const ApplicationSpecification& GetSpecification() const { return m_Specification; }
public:
	static Application& Get() { return *s_Instance; }
private:
	void Initialize();
	void Shutdown();
private:
	ApplicationSpecification m_Specification;
	bool m_Running = true;

	std::vector<Ref<Layer>> m_Layers;
	float m_LastTime = 0.0f;
private:
	inline static Application* s_Instance = nullptr;
};

Application* CreateApplication();