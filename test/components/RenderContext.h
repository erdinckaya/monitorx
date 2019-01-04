//
// Created by Erdınc Kaya on 2019-01-04.
//

#ifndef MONITORX_RENDERCONTEXT_H
#define MONITORX_RENDERCONTEXT_H


#include "../../src/3rdParty/FlexibleReflection/Reflect.h"
#include "../Rect.h"

struct RenderContext {
    explicit RenderContext(int priority = 0, Rect<float> context = Rect<float>(0, 0, 0, 0)) : priority(priority), context(context) {}

    int priority;
    Rect<float> context;

    REFLECT()
};

#endif //MONITORX_RENDERCONTEXT_H
