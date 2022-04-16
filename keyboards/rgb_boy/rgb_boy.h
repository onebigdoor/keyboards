#pragma once
#ifndef RGB_BOY_H
#define RGB_BOY_H

#include "quantum.h"

#define LAYOUT( \
    k00, k01, \
    k10, k11  \
) \
{ \
    { k00, k01 }, \
    { k10, k11 } \
}

#endif