//
// Created by misterdortnal on 31.12.2018.
//

#include "MonitorX.h"

void monitorx::MonitorX::Init() {

    // Setup Dear ImGui context
    IMGUI_CHECKVERSION();
    ImGui::CreateContext();

    // Setup Dear ImGui style
    ImGui::StyleColorsDark();

    // Setup Platform/Renderer bindings
    ImGui_ImplSDL2_InitForOpenGL(window, context);
    ImGui_ImplOpenGL2_Init();
}

void monitorx::MonitorX::ProcessEvent(SDL_Event *event) {
    ImGui_ImplSDL2_ProcessEvent(event);
}

void monitorx::MonitorX::Destroy() {
    ImGui_ImplOpenGL2_Shutdown();
    ImGui_ImplSDL2_Shutdown();
    ImGui::DestroyContext();
}

void monitorx::MonitorX::ShowDemo(bool value) {
    showDemo = value;
}

void monitorx::MonitorX::ShowEntityEditor(bool value) {
    entityEditorFlag = value;
}

