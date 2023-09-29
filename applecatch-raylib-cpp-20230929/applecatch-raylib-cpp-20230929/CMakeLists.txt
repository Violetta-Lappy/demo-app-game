project(applecatch-raylib-cpp-20230929)
add_executable (${PROJECT_NAME} main.cpp)

# Get all source file for the project (.cpp & .h)
file(GLOB_RECURSE SOURCEFILE_ALL CONFIGURE_DEPENDS
${CMAKE_CURRENT_SOURCE_DIR}/*.h
${CMAKE_CURRENT_SOURCE_DIR}/*.cpp
)

target_sources(${PROJECT_NAME} PUBLIC ${SOURCEFILE_ALL})

target_include_directories (applecatch-raylib-cpp-20230929 
PUBLIC ${CMAKE_SOURCE_DIR}/${PROJECT_NAME}/src/
PUBLIC ${CMAKE_SOURCE_DIR}/3rdparty/include
)

set(LIB_3RDPARTY
winmm.lib
opengl32.lib

# 3rdparty
#${CMAKE_SOURCE_DIR}/3rdparty/lib/raylib/raylib.lib
${CMAKE_SOURCE_DIR}/3rdparty/lib/GLFW/glfw3.lib
${CMAKE_SOURCE_DIR}/3rdparty/lib/glad/glad.lib
${CMAKE_SOURCE_DIR}/3rdparty/lib/imgui/imgui.lib
${CMAKE_SOURCE_DIR}/3rdparty/lib/fmt/fmt.lib
miniaudio
)

target_link_libraries(${PROJECT_NAME} PUBLIC ${LIB_3RDPARTY})

# After build, copy all necessary file to the build folder
add_custom_target(copy_assets    
    COMMAND ${CMAKE_COMMAND} -E copy_directory ${CMAKE_CURRENT_LIST_DIR}/data ${CMAKE_CURRENT_BINARY_DIR}/data
)
add_dependencies(${PROJECT_NAME} copy_assets)

#target_link_libraries(testge)

# Not using below - conflict with fmt library

#if (CMAKE_VERSION VERSION_GREATER 3.12)
#set_property(TARGET testge PROPERTY CXX_STANDARD 20)
#endif()

# TODO: Add tests and install targets if needed.
