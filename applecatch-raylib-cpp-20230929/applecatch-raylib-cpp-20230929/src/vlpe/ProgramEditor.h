/*
Copyright 2023 Violetta & Lappy - hoanglongplanner

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

#pragma once

#include <imgui/imgui.h>
#include <imgui/imgui_internal.h>
#include <fmt/format.h>

#include "ProgramProcessor.h"

class ProgramEditor {
public:
	ProgramEditor();
	~ProgramEditor();
public:	
	void Update(float arg_dt, float arg_unscaledDt);	
private:
	static void ShowWorkspaceScene(bool* arg_status);
	static void ShowWorkspaceGame(bool* arg_status);
	static void ShowOverlay(bool* arg_status);
	static void ShowAboutWindow(bool* arg_status);
	static void ShowContentDrawer(bool* arg_status);
};