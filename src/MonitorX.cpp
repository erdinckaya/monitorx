//
// Created by misterdortnal on 31.12.2018.
//

#include "MonitorX.h"

void monitorx::MonitorX::Render() {
    // Start the Dear ImGui frame
    ImGui_ImplOpenGL2_NewFrame();
    ImGui_ImplSDL2_NewFrame(window);
    ImGui::NewFrame();
    // Rendering


    //region IMGUI
    if (showDemo) {
        ImGui::ShowDemoWindow(&showDemo);
    }
    RenderEntityEditor();
    //endregion

    // TODO: Add your ui to here!
    ImGui::Render();
    ImGui_ImplOpenGL2_RenderDrawData(ImGui::GetDrawData());
}

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

void monitorx::MonitorX::RenderEntityEditor() {
    if (!entityEditorFlag) {
        return;
    }

    int guiId = 0;
    ImGui::Begin("Entity Editor", &entityEditorFlag, 0);
    for (entityx::Entity entity : entityX->entities.entities_for_debugging()) {
        auto id = ("Entity_" + std::to_string(entity.id().id())).c_str();
        if (ImGui::CollapsingHeader(id)) {
            if (entity.has_component<Position>()) {
                if (ImGui::TreeNode(Position::Reflection.name)) {
                    auto pos = entity.component<Position>().get();
                    for (auto member : Position::Reflection.members) {
                        std::string guiIdStr = "##" + std::to_string(guiId++);
                        if (strcmp(member.type->type(pos).c_str(), "float") == 0) {
                            ImGui::DragFloat(guiIdStr.c_str(), (float *) ((char *) pos + member.offset),
                                             0.02f, FLT_MIN, FLT_MAX, "%.2f", 2.0f);
                        } else if (strcmp(member.type->type(pos).c_str(), "int") == 0) {
                            ImGui::DragInt(guiIdStr.c_str(), (int *) ((char *) pos + member.offset),
                                           0.02f, INT_MIN, INT_MAX, "%.2f");
                        } else if (strcmp(member.type->type(pos).c_str(), "double") == 0) {
                            ImGui::DragFloat(guiIdStr.c_str(), (float *) ((char *) pos + member.offset),
                                             0.02f, FLT_MIN, FLT_MAX, "%.2f", 2.0f);
                        } else if (strcmp(member.type->type(pos).c_str(), "string") == 0) {
                            ImGui::Text("%s", member.type->value(pos, member.offset).c_str());
                        }
                        ImGui::SameLine(0);
                        ImGui::Text("%s", member.type->type(pos).c_str());
                    }


                    ImGui::TreePop();
                    ImGui::Separator();
                }


            }
        }
    }
    ImGui::End();
}
