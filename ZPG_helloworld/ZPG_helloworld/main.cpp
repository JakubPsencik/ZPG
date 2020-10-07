#pragma once
#include "Application.h"

int main(void)
{
	Application* application = Application::getInstance();
	application->run();
}