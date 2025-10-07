#include "Core/Application.h"
#include "Core/EntryPoint.h"

#include "Layers/MainLayer.h"

Application* CreateApplication() {
	ApplicationSpecification specification;
	specification.Name = "My Epic Project";

	Application* app = new Application(specification);
	app->PushLayer(CreateRef<MainLayer>());

	return app;
}