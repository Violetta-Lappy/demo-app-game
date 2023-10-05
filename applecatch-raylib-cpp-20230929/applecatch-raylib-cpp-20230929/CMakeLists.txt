project(applecatch-raylib-cpp-20230929)

# Add excutable only need entry point file, do not add extra file
add_executable (${PROJECT_NAME} mainraylib.cpp)

# Get all source file for the project (.cpp & .h)
file(GLOB_RECURSE SOURCEFILE_ALL CONFIGURE_DEPENDS
${CMAKE_CURRENT_SOURCE_DIR}/include/*.h
${CMAKE_CURRENT_SOURCE_DIR}/include/*.cpp
)
# Add all source files related to the project
target_sources(${PROJECT_NAME} PUBLIC ${SOURCEFILE_ALL})
# Add include files
target_include_directories (${PROJECT_NAME} 
PUBLIC ${CMAKE_SOURCE_DIR}/${PROJECT_NAME}/include/
PUBLIC ${CMAKE_SOURCE_DIR}/3rdparty/include
)

set(LIB_3RDPARTY
# standard library
winmm.lib
opengl32.lib
# 3rdparty
${CMAKE_SOURCE_DIR}/3rdparty/lib/raylib/raylib.lib
${CMAKE_SOURCE_DIR}/3rdparty/lib/GLFW/glfw3.lib
${CMAKE_SOURCE_DIR}/3rdparty/lib/glad/glad.lib
${CMAKE_SOURCE_DIR}/3rdparty/lib/imgui/imgui.lib
${CMAKE_SOURCE_DIR}/3rdparty/lib/rlImGui/rlImGui.lib
${CMAKE_SOURCE_DIR}/3rdparty/lib/fmt/fmt.lib
)

target_link_libraries(${PROJECT_NAME} 
PUBLIC ${LIB_3RDPARTY}
INTERFACE miniaudio
)

# After build, copy all necessary file to the build folder
add_custom_target(copy_assets    
    COMMAND ${CMAKE_COMMAND} -E copy_directory ${CMAKE_CURRENT_LIST_DIR}/data ${CMAKE_CURRENT_BINARY_DIR}/data
)
add_dependencies(${PROJECT_NAME} copy_assets)

# Not using below - conflict with fmt library
#if (CMAKE_VERSION VERSION_GREATER 3.12)
#set_property(TARGET testge PROPERTY CXX_STANDARD 20)
#endif()
# TODO: Add tests and install targets if needed.
