#pragma once

#include <string>
#include <fmt/format.h>

#define K_ProgramReleasePrefix "D"
#define K_ProgramYearMonth 202309
#define K_ProgramVersion "0.0.0"
#define K_ProgramTech "Raylib 4.5.0"

#define K_ProgramConfig_Check "Output a lot of string about the config here"

class ProgramConfig {
private:
	std::string str_programName = "ViolettaLappyProgramEngine - Program Example - PLEASE CHANGE CONFIG IF SEE THIS TITLE";
	std::string str_programSpec = "Raylib OpenGL Windows x64";
	//def: 800
	int i32_screenWidth = 1280; 
	//def: 600
	int i32_screenHeight = 720; 
	//def: 60
	int i32_targetFps = 60; 
	//def: 30
	int i32_refreshRate = 30; 
	//def: 1
	int i32_dpi = 1;
public:
	ProgramConfig() {}
	~ProgramConfig() {}
public:
	//--GLOBAL CONFIG--
	void SetProgramName(std::string arg_name) {
		str_programName = arg_name;
	}

	//--PROGRAM SYSTEM CONFIG--
	void SetTargetFps(int arg_value) {
		i32_targetFps = arg_value;
	}
	void SetRefreshRate(int arg_value) {
		i32_refreshRate = arg_value;
	}

	//--DISPLAY CONFIG--
	void SetScreenWidth(int arg_value) {
		i32_screenWidth = arg_value;
	}
	void SetScreenHeight(int arg_value) {
		i32_screenHeight = arg_value;
	}		
	void SetDpi(int arg_value) {
		i32_dpi = arg_value;
	}

	//--GRAPHIC CONFIG--	
	//--AUDIO CONFIG--
public:
	std::string GetProgramName() {
		return fmt::format("{0} - {1}", str_programSpec, str_programName);
	}
	int GetScreenWidth() const {
		return i32_screenWidth;
	}
	int GetScreenHeight() const {
		return i32_screenHeight;
	}
	int GetDpi() const {
		return i32_dpi;
	}
	int GetTargetFps() const {
		return i32_targetFps;
	}
};