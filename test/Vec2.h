//
// Created by misterdortnal on 03.01.2019.
//

#ifndef MONITORX_VEC2_H
#define MONITORX_VEC2_H

template<typename C>
struct Vec2 {
    explicit Vec2(C x = 0, C y = 0) : x(x), y(y) {}

    C x;
    C y;

    REFLECT_TEMPLATE(Vec2, C)
                        REFLECT_STRUCT_MEMBER_TEMPLATE(x)
                        REFLECT_STRUCT_MEMBER_TEMPLATE(y)
    REFLECT_STRUCT_END()

};
REFLECT_STRUCT_INIT_TEMPLATE(Vec2)

#endif //MONITORX_VEC2_H
