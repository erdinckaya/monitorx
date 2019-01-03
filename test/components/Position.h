//
// Created by misterdortnal on 31.12.2018.
//

#ifndef MONITORX_POSITION_H
#define MONITORX_POSITION_H

#include "../../src/3rdParty/FlexibleReflection/Reflect.h"

struct Position {
    explicit Position(float x = 0.0f, float y = 0.0f) : x(x), y(y) {}

    float x, y;

    REFLECT()
};




#endif //MONITORX_POSITION_H
