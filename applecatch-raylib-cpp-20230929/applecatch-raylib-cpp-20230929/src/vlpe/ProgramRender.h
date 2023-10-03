#pragma once

#include "ProgramConfig.h"
#include <raylib/raylib.h>

class ProgramRender {
private:
	ProgramConfig m_config;
public:
	ProgramRender();
	~ProgramRender();
public:
	ProgramConfig GetConfig() const {
		return m_config;
	}
	void SetConfig(ProgramConfig arg_config) {
		m_config = arg_config;
	}
public:
	void Start();
	void Update(float arg_dt, float arg_unscaledDt);
	void Terminate();
public:
	// Define the camera to look into our 3d world
	Camera3D camera = { 0 };
	Vector3 cubePosition = { 0.0f, 0.0f, 0.0f };
};