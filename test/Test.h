//
// Created by misterdortnal on 31.12.2018.
//

#ifndef MONITORX_TEST_H
#define MONITORX_TEST_H

#include <SDL_scancode.h>
#include "../src/MonitorX.h"
#include "components/Position.h"
#include "components/Size.h"
#include "components/Visibility.h"
#include "components/RenderContext.h"


void TestKey(SDL_Scancode scancode, monitorx::MonitorX &monitorX, entityx::EntityX &entityX) {
    switch (scancode) {
        case SDL_SCANCODE_D: {
            monitorX.ShowDemo(true);
            break;
        }
        case SDL_SCANCODE_C: {
            monitorX.ShowDemo(false);
            monitorX.ShowEntityEditor(false);
            break;
        }
        case SDL_SCANCODE_A: {
            auto entity = entityX.entities.create();
            entity.assign<Position>(10, 20);
            entity.assign<Size>(30, 40, Vec2<float>(100, 200));
            entity.assign<Visibility>(true);

            entity = entityX.entities.create();
            entity.assign<Position>(30, 40);
            entity.assign<Size>(50, 50, Vec2<float>(400, 500));
            entity.assign<Visibility>(false);
            entity.assign<RenderContext>(4, Rect<float>(10, 20, 30, 40));

            monitorX.ShowEntityEditor(true);

            break;
        }
        default:
            break;
    }
}


#endif //MONITORX_TEST_H
