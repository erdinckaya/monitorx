//
// Created by misterdortnal on 31.12.2018.
//

#ifndef MONITORX_SIZE_H
#define MONITORX_SIZE_H

#include "../../src/MonitorX.h"

struct Size {
    explicit Size(float w = 0.0f, float h = 0.0f) : w(w), h(h) {}
    float w, h;
    REFLECT()
};

REFLECT_STRUCT_BEGIN(Size)
                    REFLECT_STRUCT_MEMBER(w)
                    REFLECT_STRUCT_MEMBER(h)
REFLECT_STRUCT_END()

#endif //MONITORX_SIZE_H
