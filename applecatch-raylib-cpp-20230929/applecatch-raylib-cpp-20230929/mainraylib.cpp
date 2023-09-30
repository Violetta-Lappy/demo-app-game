//ViolettaLappy-ProgramEngine target for Raylib
//Use raylib can target many format based on Raylib support

#include <raylib/raylib.h>
#include <fmt/format.h>
#include <rlImGui/rlImGui.h>
#include <imgui/imgui.h>

int main(int argc, char* argv[]) {
	fmt::println("Hello World, Raylib");
	
	const int screenWidth = 1280;
	const int screenHeight = 720;

	InitWindow(screenWidth, screenHeight, "raylib [core] example - basic window");

	// Set our game to run at 60 frames-per-second
	SetTargetFPS(60);               	
	rlImGuiSetup(true);

	// Main game loop
	// Detect window close button or ESC key
	while (!WindowShouldClose()) {
		BeginDrawing();
		ClearBackground(RAYWHITE);

		DrawText("Congrats! You created your first window!", 190, 200, 20, LIGHTGRAY);

		// start ImGui Conent
		rlImGuiBegin();

		// show ImGui Content
		bool open = true;
		ImGui::ShowDemoWindow(&open);

		// end ImGui Content
		rlImGuiEnd();

		EndDrawing();
	}
	rlImGuiShutdown();
	// Close window and OpenGL context
	CloseWindow();

	return 0;
}
