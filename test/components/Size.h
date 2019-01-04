//
// Created by misterdortnal on 31.12.2018.
//

#ifndef MONITORX_SIZE_H
#define MONITORX_SIZE_H

#include "../../src/3rdParty/FlexibleReflection/Reflect.h"
#include "../Vec2.h"

struct Size {
    explicit Size(float w = 0.0f, float h = 0.0f, Vec2<float> pos = Vec2<float>(0, 0)) : w(w), h(h), pos(pos) {}
    float w, h;

    Vec2<float> pos;
    REFLECT()
};


#endif //MONITORX_SIZE_H
