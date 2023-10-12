/*
Copyright 2023 ViolettaLappy - hoanglongplanner

Licensed under the Apache License, Version 2.0 (the "License");
you may not use this file except in compliance with the License.
You may obtain a copy of the License at

http://www.apache.org/licenses/LICENSE-2.0

Unless required by applicable law or agreed to in writing, software
distributed under the License is distributed on an "AS IS" BASIS,
WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
See the License for the specific language governing permissions and
limitations under the License.
*/

//ViolettaLappyProgramEngine target for Raylib 4.5.0

#include <raylib/raylib.h>
#include <rlImGui/rlImGui.h>
#include <imgui/imgui.h>
#include <fmt/format.h>

#include <pe/ProgramConfig.h>
#include <pe/ProgramEditor.h>
#include <pe/ProgramRender.h>

int main(int argc, char* argv[]) {	
	//Setup your own program engine systems here - programengine (pe)
	ProgramConfig config;
	config.SetProgramName("Demo Program");

	ProgramEditor editor;
	ProgramRender render;
	render.Start();

	//--raylib--
	//Initialize window
	InitWindow(config.GetScreenWidth(), config.GetScreenHeight(), config.GetProgramName().c_str());
	// Set our game to run at 60 frames-per-second
	SetTargetFPS(60);               	

	//--rlimgui--	
	rlImGuiSetup(true);	

	//--imgui--
	IMGUI_CHECKVERSION();		

	//--Program Loop--	
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

	//--Program Termination--	
	rlImGuiShutdown();
	CloseWindow();

	return 0;
}
