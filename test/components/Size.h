//
// Created by misterdortnal on 31.12.2018.
//

#ifndef MONITORX_SIZE_H
#define MONITORX_SIZE_H

#include "../../src/3rdParty/FlexibleReflection/Reflect.h"

struct Size {
    explicit Size(float w = 0.0f, float h = 0.0f) : w(w), h(h) {}
    float w, h;
    REFLECT()
};


#endif //MONITORX_SIZE_H
