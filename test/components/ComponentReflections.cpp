//
// Created by Erdınc Kaya on 2019-01-02.
//

#include "Position.h"
#include "Size.h"

REFLECT_STRUCT_BEGIN(Position)
                    REFLECT_STRUCT_MEMBER(x)
                    REFLECT_STRUCT_MEMBER(y)
REFLECT_STRUCT_END()


REFLECT_STRUCT_BEGIN(Size)
                    REFLECT_STRUCT_MEMBER(w)
                    REFLECT_STRUCT_MEMBER(h)
REFLECT_STRUCT_END()