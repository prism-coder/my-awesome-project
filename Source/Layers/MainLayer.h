#pragma once

#include "Core/Layer.h"

#include <string>

class MainLayer : public Layer {
public:
	MainLayer();
	virtual ~MainLayer() = default;

	virtual void OnAttach() override;
	virtual void OnDetach() override;
	virtual void OnUpdate(Timestep timestep) override;
private:
	std::string m_HelloWorld = "Hello World!";
};