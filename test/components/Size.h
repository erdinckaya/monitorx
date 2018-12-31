//
// Created by misterdortnal on 31.12.2018.
//

#ifndef MONITORX_SIZE_H
#define MONITORX_SIZE_H

struct Size {
    explicit Size(float w = 0.0f, float h = 0.0f) : w(w), h(h) {}
    float w, h;
};

#endif //MONITORX_SIZE_H
