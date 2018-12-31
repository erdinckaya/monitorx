// dear imgui: standalone example application for SDL2 + OpenGL
// If you are new to dear imgui, see examples/README.txt and documentation at the top of imgui.cpp.
// (SDL is a cross-platform general purpose library for handling windows, inputs, OpenGL/Vulkan graphics context creation, etc.)

// **DO NOT USE THIS CODE IF YOUR CODE/ENGINE IS USING MODERN OPENGL (SHADERS, VBO, VAO, etc.)**
// **Prefer using the code in the example_sdl_opengl3/ folder**
// See imgui_impl_sdl.cpp for details.

#include "src/3rdParty/ImGui/imgui.h"
#include "src/3rdParty/ImGui/imgui_impl_sdl.h"
#include "src/3rdParty/ImGui/imgui_impl_opengl2.h"
#include "src/MonitorX.h"
#include <stdio.h>
#include <SDL.h>
#include <SDL_opengl.h>
#include <entityx/entityx.h>


using namespace entityx;

int main(int, char **) {

    // Setup SDL
    if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_TIMER) != 0) {
        printf("Error: %s\n", SDL_GetError());
        return -1;
    }

    // Setup window
    SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);
    SDL_GL_SetAttribute(SDL_GL_DEPTH_SIZE, 24);
    SDL_GL_SetAttribute(SDL_GL_STENCIL_SIZE, 8);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 2);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 2);
    SDL_DisplayMode current;
    SDL_GetCurrentDisplayMode(0, &current);
    SDL_Window *window = SDL_CreateWindow("Dear ImGui SDL2+OpenGL example", SDL_WINDOWPOS_CENTERED,
                                          SDL_WINDOWPOS_CENTERED, 1280, 720, SDL_WINDOW_OPENGL | SDL_WINDOW_RESIZABLE);
    SDL_GLContext gl_context = SDL_GL_CreateContext(window);
    SDL_GL_SetSwapInterval(1); // Enable vsync


    EntityX entityX;
    monitorX::MonitorX monitorX(&entityX, window, &gl_context);
    monitorX.Init();


    // Main loop
    bool done = false;
    while (!done) {
        SDL_Event event;
        while (SDL_PollEvent(&event)) {
            monitorX.ProcessEvent(&event);
            if (event.type == SDL_QUIT)
                done = true;
            if (event.type == SDL_KEYDOWN) {
                switch (event.key.keysym.scancode) {
                    case SDL_SCANCODE_D: {
                        monitorX.ShowDemo(true);
                        break;
                    }
                    case SDL_SCANCODE_C: {
                        monitorX.ShowDemo(false);
                        break;
                    }
                    default:
                        break;
                }
            }
        }

        monitorX.Render();
        SDL_GL_MakeCurrent(window, gl_context);
        SDL_GL_SwapWindow(window);
        glClear(GL_COLOR_BUFFER_BIT);
    }

    // Cleanup
    monitorX.Destroy();

    SDL_GL_DeleteContext(gl_context);
    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;
}
