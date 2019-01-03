//
// Created by misterdortnal on 31.12.2018.
//

#ifndef MONITORX_MONITORX_H
#define MONITORX_MONITORX_H

#include "3rdParty/ImGui/imgui.h"
#include "3rdParty/ImGui/imgui_impl_sdl.h"
#include "3rdParty/ImGui/imgui_impl_opengl2.h"
#include "3rdParty/FlexibleReflection/Reflect.h"
#include <stdio.h>
#include <SDL.h>
#include <SDL_opengl.h>

#include "../test/components/Position.h"
#include "../test/components/Size.h"


#include <entityx/entityx.h>

#include <type_traits>

struct end_of_list;

namespace monitorx {
    class MonitorX {
    public:
        MonitorX(entityx::EntityX *entityX, SDL_Window *window, SDL_GLContext *context) :
                entityX(entityX), window(window), context(context), showDemo(false),
                entityEditorFlag(false) {}

        ~MonitorX() = default;

        void Init();

        void ProcessEvent(SDL_Event *event);

        void Destroy();

        void ShowDemo(bool value);

        void ShowEntityEditor(bool value);

        template<typename... Components>
        void Render() {
            // Start the Dear ImGui frame
            ImGui_ImplOpenGL2_NewFrame();
            ImGui_ImplSDL2_NewFrame(window);
            ImGui::NewFrame();
            // Rendering


            //region IMGUI
            if (showDemo) {
                ImGui::ShowDemoWindow(&showDemo);
            }

            RenderEntityEditor<Components...>();
            //endregion

            // TODO: Add your ui to here!
            ImGui::Render();
            ImGui_ImplOpenGL2_RenderDrawData(ImGui::GetDrawData());
        }

    private:
        entityx::EntityX *entityX;
        SDL_Window *window;
        SDL_GLContext *context;

        entityx::Entity currentEntity;

        //region Flags
        bool showDemo;
        bool entityEditorFlag;
        //endregion


        template<typename... Components>
        void RenderEntityEditor() {
            if (!entityEditorFlag) {
                return;
            }

            ImGui::Begin("Entity Editor", &entityEditorFlag, 0);
            for (entityx::Entity entity : entityX->entities.entities_for_debugging()) {
                auto id = ("Entity_" + std::to_string(entity.id().id())).c_str();
                if (ImGui::CollapsingHeader(id)) {
                    currentEntity = entity;
                    RenderComponent<Components...>();
                }
            }
            ImGui::End();
        }

        template<typename C>
        void RenderComponent() {
            static_assert(std::is_same<C, end_of_list>::value, "error");
        }

        template<typename C, typename C1, typename... Components>
        void RenderComponent() {
            if (currentEntity.has_component<C>()) {
                auto *typeDesc = dynamic_cast<reflect::TypeDescriptor_Struct *>(reflect::TypeResolver<C>::get());
                if (ImGui::TreeNode(typeDesc->name)) {
                    auto pos = currentEntity.component<C>().get();
                    for (auto member : typeDesc->members) {
                        std::string guiIdStr = "##" + std::to_string(currentEntity.id().id()) + member.name;
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
                        } else if (strcmp(member.type->type(pos).c_str(), "bool") == 0) {
                            ImGui::Checkbox(guiIdStr.c_str(), (bool *) ((char *) pos + member.offset));
                        }

                        ImGui::SameLine(0);
                        ImGui::Text("%s %s", member.name, member.type->type(pos).c_str());
                    }

                    ImGui::TreePop();
                    ImGui::Separator();
                }
            }

            RenderComponent<C1, Components...>();
        }
    };
}


#endif //MONITORX_MONITORX_H
