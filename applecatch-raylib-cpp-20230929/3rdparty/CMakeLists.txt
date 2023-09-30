# Not included the followings because it already has precompiled already
# GFLW
# raylib

add_library(glad STATIC
${CMAKE_CURRENT_SOURCE_DIR}/include/glad/glad.c
${CMAKE_CURRENT_SOURCE_DIR}/include/glad/glad.h
${CMAKE_CURRENT_SOURCE_DIR}/include/KHR/khrplatform.h
)
set_target_properties(glad PROPERTIES
  ARCHIVE_OUTPUT_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/lib/glad"
)
target_include_directories(glad PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/include")

add_library(imgui STATIC
${CMAKE_CURRENT_SOURCE_DIR}/include/imgui/imconfig.h
${CMAKE_CURRENT_SOURCE_DIR}/include/imgui/imgui.cpp
${CMAKE_CURRENT_SOURCE_DIR}/include/imgui/imgui.h
${CMAKE_CURRENT_SOURCE_DIR}/include/imgui/imgui_demo.cpp
${CMAKE_CURRENT_SOURCE_DIR}/include/imgui/imgui_draw.cpp
${CMAKE_CURRENT_SOURCE_DIR}/include/imgui/imgui_impl_glfw.cpp
${CMAKE_CURRENT_SOURCE_DIR}/include/imgui/imgui_impl_glfw.h
${CMAKE_CURRENT_SOURCE_DIR}/include/imgui/imgui_impl_opengl3.cpp
${CMAKE_CURRENT_SOURCE_DIR}/include/imgui/imgui_impl_opengl3.h
${CMAKE_CURRENT_SOURCE_DIR}/include/imgui/imgui_impl_opengl3_loader.h
${CMAKE_CURRENT_SOURCE_DIR}/include/imgui/imgui_internal.h
${CMAKE_CURRENT_SOURCE_DIR}/include/imgui/imgui_tables.cpp
${CMAKE_CURRENT_SOURCE_DIR}/include/imgui/imgui_widgets.cpp
${CMAKE_CURRENT_SOURCE_DIR}/include/imgui/imstb_rectpack.h
${CMAKE_CURRENT_SOURCE_DIR}/include/imgui/imstb_textedit.h
${CMAKE_CURRENT_SOURCE_DIR}/include/imgui/imstb_truetype.h
)
set_target_properties(imgui PROPERTIES
  ARCHIVE_OUTPUT_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/lib/imgui"
)
target_include_directories(imgui PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/include")

add_library(fmt STATIC
${CMAKE_CURRENT_SOURCE_DIR}/include/fmt/core.h
${CMAKE_CURRENT_SOURCE_DIR}/include/fmt/format-inl.h
${CMAKE_CURRENT_SOURCE_DIR}/include/fmt/format.cpp
${CMAKE_CURRENT_SOURCE_DIR}/include/fmt/format.h
${CMAKE_CURRENT_SOURCE_DIR}/include/fmt/ostream.h
)
set_target_properties(fmt PROPERTIES
  ARCHIVE_OUTPUT_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/lib/fmt"
)

add_library(miniaudio INTERFACE)
target_include_directories(miniaudio INTERFACE "${CMAKE_CURRENT_SOURCE_DIR}/include/miniaudio/miniaudio.h")