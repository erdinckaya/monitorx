//
// Created by misterdortnal on 31.12.2018.
//

#include "MonitorX.h"

void monitorX::MonitorX::Render() {
    // Start the Dear ImGui frame
    ImGui_ImplOpenGL2_NewFrame();
    ImGui_ImplSDL2_NewFrame(window);
    ImGui::NewFrame();
    // Rendering

    if (showDemo) {
        ImGui::ShowDemoWindow(&showDemo);
    }

    // TODO: Add your ui to here!
    ImGui::Render();
    ImGui_ImplOpenGL2_RenderDrawData(ImGui::GetDrawData());
}

void monitorX::MonitorX::Init() {

    // Setup Dear ImGui context
    IMGUI_CHECKVERSION();
    ImGui::CreateContext();

    // Setup Dear ImGui style
    ImGui::StyleColorsDark();

    // Setup Platform/Renderer bindings
    ImGui_ImplSDL2_InitForOpenGL(window, context);
    ImGui_ImplOpenGL2_Init();
}

void monitorX::MonitorX::ProcessEvent(SDL_Event *event) {
    ImGui_ImplSDL2_ProcessEvent(event);
}

void monitorX::MonitorX::Destroy() {
    ImGui_ImplOpenGL2_Shutdown();
    ImGui_ImplSDL2_Shutdown();
    ImGui::DestroyContext();
}

void monitorX::MonitorX::ShowDemo(bool value) {
    showDemo = value;
}
