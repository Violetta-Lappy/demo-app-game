cmake_minimum_required(VERSION 3.12) 
project(applecatch-raylib-cpp-20230927)
# Generate compile_commands.json
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

#--Define Your Custom Project Here--

set(SOURCEFILE_COMMON 
"${CMAKE_CURRENT_SOURCE_DIR}/internal/*.cpp" 
"${CMAKE_CURRENT_SOURCE_DIR}/internal/*.h" 
)

file(GLOB_RECURSE SOURCEFILE_ALL CONFIGURE_DEPENDS
${SOURCEFILE_COMMON}
)

# Add source to this project's executable.
add_executable(${PROJECT_NAME} main.cpp ${SOURCEFILE_ALL})

set(INTERNALPARTY
)

set(3RDPARTY 
)

target_include_directories(${PROJECT_NAME} PUBLIC ${INTERNALPARTY} PUBLIC ${3RDPARTY})

set(3RDPARTY_LIB
winmm.lib
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
