#pragma once
#ifndef RGB_3x3_H
#define RGB_3x3_H
#endif

#include "quantum.h"

#define LAYOUT( \
    k00, k01, k02,\
    k10, k11, k12,\
    k20, k21, k22\
) \
{ \
    { k00, k01, k02 }, \
    { k10, k11, k12 }, \
    { k20, k21, k22 }\
}

#endif