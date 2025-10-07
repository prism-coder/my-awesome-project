#include "MainLayer.h"

#include <iostream>

MainLayer::MainLayer() {
	std::cout << "Main Layer constructed" << std::endl;
}

void MainLayer::OnAttach() {
	std::cout << "Main Layer attached" << std::endl;
}

void MainLayer::OnDetach() {
	std::cout << "Main Layer detached" << std::endl;
}

void MainLayer::OnUpdate(Timestep timestep) {
	std::cout << m_HelloWorld << std::endl;
}
