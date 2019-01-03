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
            entity.assign<Size>(30, 40);
            entity.assign<Visibility>(true);


            Position pos(10, 20);
            Size size(30, 40);

            reflect::TypeDescriptor *typeDesc = reflect::TypeResolver<Position>::get();
            typeDesc->dump(&pos);
            typeDesc = reflect::TypeResolver<Size>::get();
            typeDesc->dump(&size);

            printf("\n");
            for (auto member : Position::Reflection.members) {
                printf("Name %s Type %s Value %s\n", member.name, member.type->type(&pos).c_str(),
                       member.type->value(&pos, member.offset).c_str());
            }

            monitorX.ShowEntityEditor(true);

            break;
        }
        default:
            break;
    }
}


#endif //MONITORX_TEST_H