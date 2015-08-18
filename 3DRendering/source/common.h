#ifndef COMMON_H
#define COMMON_H

#include "../source/xdVector.h"



xdVector3f Normalize(const xdVector3f &v);

float xdLerp(float a, float b, float t);

float Dot(const xdVector3f &v1, const xdVector3f &v2);

float Dot(const xdVector2f &v1, const xdVector2f &v2);




#endif