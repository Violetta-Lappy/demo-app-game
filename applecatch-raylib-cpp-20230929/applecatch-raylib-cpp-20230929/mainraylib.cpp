//ViolettaLappy-ProgramEngine target for Raylib
//Use raylib can target many format based on Raylib support

#include <raylib/raylib.h>
#include <fmt/format.h>
#include <rlImGui/rlImGui.h>
#include <imgui/imgui.h>

#include <vlpe/ProgramEditor.h>
#include <vlpe/ProgramRender.h>

int main(int argc, char* argv[]) {
	fmt::println("Hello World, Raylib");
	
	const int screenWidth = 1280;
	const int screenHeight = 720;

	InitWindow(screenWidth, screenHeight, "raylib [core] example - basic window");

	// Set our game to run at 60 frames-per-second
	SetTargetFPS(60);               	

	//Setup Imgui
	rlImGuiSetup(true);
	
	//Setup systems
	ProgramEditor editor;
	ProgramRender render;
	render.Start();

	//--imgui: setup--
	IMGUI_CHECKVERSION();		

	// Main game loop
	// Detect window close button or ESC key
	while (!WindowShouldClose()) {
		//--Raylib Start Render--
		//--Imgui--
		BeginDrawing();			
		rlImGuiBegin();		

		//--Render: Imgui Editor--
		editor.Update(0.0f, 0.0f);		

		//--Render: Raylib--
		render.Update(0.0f, 0.0f);
	
		//--Raylib End Render--
		rlImGuiEnd();
		EndDrawing();
	}

	//--Shutdown--
	//Close window and OpenGL context
	rlImGuiShutdown();
	CloseWindow();

	return 0;
}
