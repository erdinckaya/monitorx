//
// Created by misterdortnal on 31.12.2018.
//

#ifndef MONITORX_TEST_H
#define MONITORX_TEST_H

#include <SDL_scancode.h>
#include "../src/MonitorX.h"
#include "components/Position.h"
#include "components/Size.h"

void TestKey(SDL_Scancode scancode, monitorX::MonitorX &monitorX, entityx::EntityX &entityX) {
    switch (scancode) {
        case SDL_SCANCODE_D: {
            monitorX.ShowDemo(true);
            break;
        }
        case SDL_SCANCODE_C: {
            monitorX.ShowDemo(false);
            break;
        }
        case SDL_SCANCODE_A: {
            auto entity = entityX.entities.create();
            entity.assign<Position>(10, 10);
            entity.assign<Size>(30, 40);

            entityX.entities
            for (auto ent : entityX.entities.entities_for_debugging()) {
                auto tuple = ent.components();
                printf("123123123\n");
            }
            break;
        }
        default:
            break;
    }
}


#endif //MONITORX_TEST_H
