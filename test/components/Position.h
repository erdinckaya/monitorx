//
// Created by misterdortnal on 31.12.2018.
//

#ifndef MONITORX_POSITION_H
#define MONITORX_POSITION_H

#include "../../src/MonitorX.h"

struct Position {
    explicit Position(float x = 0.0f, float y = 0.0f) : x(x), y(y) {}

    float x, y;

    REFLECT()
};


REFLECT_STRUCT_BEGIN(Position)
                    REFLECT_STRUCT_MEMBER(x)
                    REFLECT_STRUCT_MEMBER(y)
REFLECT_STRUCT_END()



#endif //MONITORX_POSITION_H
