cmake_minimum_required(VERSION 3.13)
project(monitorx)

set(CMAKE_CXX_STANDARD 14)

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${PROJECT_SOURCE_DIR}/cmake")

find_package(SDL2 REQUIRED)
find_package(Entityx REQUIRED)
find_package(OpenGL REQUIRED)

include_directories(${ENTITYX_INCLUDE_DIR} ${SDL2_INCLUDE_DIR}  ${OPENGL_INCLUDE_DIR})

add_executable(monitorx main.cpp src/3rdParty/ImGui/imconfig.h src/3rdParty/ImGui/imgui.cpp src/3rdParty/ImGui/imgui.h
        src/3rdParty/ImGui/imgui_demo.cpp src/3rdParty/ImGui/imgui_draw.cpp src/3rdParty/ImGui/imgui_impl_opengl2.h
        src/3rdParty/ImGui/imgui_impl_opengl2.cpp src/3rdParty/ImGui/imgui_impl_sdl.h src/3rdParty/ImGui/imgui_impl_sdl.cpp
        src/3rdParty/ImGui/imgui_internal.h src/3rdParty/ImGui/imgui_widgets.cpp src/3rdParty/ImGui/imstb_rectpack.h
        src/3rdParty/ImGui/imstb_textedit.h src/3rdParty/ImGui/imstb_truetype.h src/MonitorX.cpp src/MonitorX.h)


target_link_libraries(monitorx ${ENTITYX_LIBRARY} ${SDL2_LIBRARY} ${OPENGL_gl_LIBRARY})