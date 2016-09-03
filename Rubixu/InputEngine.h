#pragma once
#include "Classes.h"
#include "Rubixu.h"

#include <iostream>

class InputEngine
{
public:
	InputEngine(Rubixu *rubixu);
	~InputEngine();

	void Init();
	void CleanUp();

	void Keyboard();

private:
	Rubixu *rubixu = NULL;
	Camera *camera = NULL;

	bool stop_camera_direction = false;
};