//
// Created by Erdınc Kaya on 2019-01-03.
//

#ifndef MONITORX_VISIBILITY_H
#define MONITORX_VISIBILITY_H

#include "../../src/3rdParty/FlexibleReflection/Reflect.h"

struct Visibility {
    explicit Visibility(bool value = false, std::string name = "visibility") : value(value), name(name) {}

    std::string name;
    bool value;
    REFLECT()
};

#endif //MONITORX_VISIBILITY_H
