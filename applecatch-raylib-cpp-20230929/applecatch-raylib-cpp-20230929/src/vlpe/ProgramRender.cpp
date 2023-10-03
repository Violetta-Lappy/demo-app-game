#include "ProgramRender.h"

ProgramRender::ProgramRender() {
}

ProgramRender::~ProgramRender() {
}

void ProgramRender::Start() {
	// Camera position
	camera.position = { 10.0f, 10.0f, 10.0f };
	// Camera looking at point
	camera.target = { 0.0f, 0.0f, 0.0f };
	// Camera up vector (rotation towards target)
	camera.up = { 0.0f, 1.0f, 0.0f };
	// Camera field-of-view Y
	camera.fovy = 45.0f;
	// Camera projection type
	camera.projection = CAMERA_FREE;
}

void ProgramRender::Update(float arg_dt, float arg_unscaledDt) {
	UpdateCamera(&camera, CAMERA_FIRST_PERSON);

	if (IsKeyDown('Z')) {
		camera.target = { 0.0f, 0.0f, 0.0f };
	}

	ClearBackground(BLACK);	

	BeginMode3D(camera);

	DrawCube(cubePosition, 2.0f, 2.0f, 2.0f, WHITE);
	DrawCubeWires(cubePosition, 2.0f, 2.0f, 2.0f, WHITE);

	DrawGrid(10, 1.0f);

	EndMode3D();

	DrawRectangle(10, 10, 320, 133, Fade(SKYBLUE, 0.5f));
	DrawRectangleLines(10, 10, 320, 133, BLUE);

	DrawText("Free camera default controls:", 20, 20, 10, WHITE);
	DrawText("- Mouse Wheel to Zoom in-out", 40, 40, 10, WHITE);
	DrawText("- Mouse Wheel Pressed to Pan", 40, 60, 10, WHITE);
	DrawText("- Alt + Mouse Wheel Pressed to Rotate", 40, 80, 10, WHITE);
	DrawText("- Alt + Ctrl + Mouse Wheel Pressed for Smooth Zoom", 40, 100, 10, WHITE);
	DrawText("- Z to zoom to (0, 0, 0)", 40, 120, 10, WHITE);
}

void ProgramRender::Terminate() {
}
