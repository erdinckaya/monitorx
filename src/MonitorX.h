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

namespace monitorx {
    class MonitorX {
    public:
        MonitorX(entityx::EntityX *entityX, SDL_Window *window, SDL_GLContext *context) :
                entityX(entityX), window(window), context(context), showDemo(false) {}

        void Init();

        void Render();

        ~MonitorX() = default;

        void ProcessEvent(SDL_Event *event);

        void Destroy();

        void ShowDemo(bool value);

        void ShowEntityEditor(bool value);

    private:

        void RenderEntityEditor();

        entityx::EntityX *entityX;
        SDL_Window *window;
        SDL_GLContext *context;


        //region Flags
        bool showDemo;
        bool entityEditorFlag;
        //endregion

    };
}


#endif //MONITORX_MONITORX_H
