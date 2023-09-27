cmake_minimum_required(VERSION 3.12) 
project(applecatch-raylib-cpp-20230927)
# Generate compile_commands.json
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

#--3rdParty Download Stuff--

#webview

if(NOT EXISTS ${CMAKE_CURRENT_SOURCE_DIR}/3rdparty/include/webview/webview.h)
file(DOWNLOAD
https://raw.githubusercontent.com/webview/webview/master/webview.h
${CMAKE_CURRENT_SOURCE_DIR}/3rdparty/include/webview/webview.h)
endif()

#--Define Your Custom Project Here--

set(SOURCEFILE_COMMON 
"${CMAKE_CURRENT_SOURCE_DIR}/3rdparty/include/webview/*.cpp" 
"${CMAKE_CURRENT_SOURCE_DIR}/3rdparty/include/webview/*.h" 
)

file(GLOB_RECURSE SOURCEFILE_ALL CONFIGURE_DEPENDS
${SOURCEFILE_COMMON}
)

# Add source to this project's executable.
add_executable(${PROJECT_NAME} main.cpp ${SOURCEFILE_ALL})

set(INTERNALPARTY
"${CMAKE_CURRENT_SOURCE_DIR}/internal/" 
)

set(3RDPARTY 
"${CMAKE_CURRENT_SOURCE_DIR}/3rdparty/include" 
"${CMAKE_CURRENT_SOURCE_DIR}/3rdparty/include/fmt" 
"${CMAKE_CURRENT_SOURCE_DIR}/3rdparty/include/imgui" 
"${CMAKE_CURRENT_SOURCE_DIR}/3rdparty/include/raylib" 
"${CMAKE_CURRENT_SOURCE_DIR}/3rdparty/include/rlimgui" 
"${CMAKE_CURRENT_SOURCE_DIR}/3rdparty/include/webview" 
)

target_include_directories(${PROJECT_NAME} PUBLIC ${INTERNALPARTY} PUBLIC ${3RDPARTY})

set(3RDPARTY_LIB
# winmm.lib is necessary for raylib, without it unable to compile program
winmm.lib
# webview
advapi32.lib
ole32.lib
shell32.lib
shlwapi.lib
user32.lib
version.lib
${CMAKE_CURRENT_SOURCE_DIR}/3rdparty/lib/raylib/raylib.lib
${CMAKE_CURRENT_SOURCE_DIR}/3rdparty/lib/webview/webview.lib
${CMAKE_CURRENT_SOURCE_DIR}/3rdparty/lib/WebView2/WebView2LoaderStatic.lib
)

target_link_libraries(${PROJECT_NAME} ${3RDPARTY_LIB})

# TODO: Add tests and install targets if needed.

# Web Configurations
#if (${PLATFORM} STREQUAL "Web")
# Tell Emscripten to build an example.html file.
#set_target_properties(${PROJECT_NAME} PROPERTIES SUFFIX ".html")
#endif()

# Checks if OSX and links appropriate frameworks (Only required on MacOS)
if (APPLE)
    target_link_libraries(${PROJECT_NAME} "-framework IOKit")
    target_link_libraries(${PROJECT_NAME} "-framework Cocoa")
    target_link_libraries(${PROJECT_NAME} "-framework OpenGL")
endif()
