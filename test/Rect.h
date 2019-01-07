//
// Created by Erdınc Kaya on 2019-01-04.
//

#ifndef MONITORX_RECT_H
#define MONITORX_RECT_H


#include "../src/3rdParty/FlexibleReflection/Reflect.h"

template<typename C>
struct Rect {
    explicit Rect(C x = 0, C y = 0, C w = 0, C h = 0) : x(x), y(y), w(w), h(h) {}

    C x;
    C y;
    C w;
    C h;

    REFLECT_TEMPLATE(Rect, C)
                        REFLECT_STRUCT_MEMBER_TEMPLATE(x)
                        REFLECT_STRUCT_MEMBER_TEMPLATE(y)
                        REFLECT_STRUCT_MEMBER_TEMPLATE(w)
                        REFLECT_STRUCT_MEMBER_TEMPLATE(h)
    REFLECT_STRUCT_END()

};

REFLECT_STRUCT_INIT_TEMPLATE(Rect)

#endif //MONITORX_RECT_H
