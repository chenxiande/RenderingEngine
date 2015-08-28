#ifndef COMMON_H
#define COMMON_H

#include "../source/xdVector.h"
#include "windows.h"

#define xdRGB(r,g,b)          ((COLORREF)(((BYTE)(b)|((WORD)((BYTE)(g))<<8))|(((DWORD)(BYTE)(r))<<16)))

#define xdGetBValue(rgb)      (LOBYTE(rgb))
#define xdGetGValue(rgb)      (LOBYTE(((WORD)(rgb)) >> 8))
#define xdGetRValue(rgb)      (LOBYTE((rgb)>>16))
#define EPS   1e-10

class xdVector3f;

float xdLerp(float a, float b, float t);

float xdLerpZ(xdVector3f start, xdVector3f end, float x, float y); //直线上z的lerp
float xdLerpZ(xdVector3i start, xdVector3i end, float x, float y); //直线上z的lerp

int xdRound(float f);

template <class T> void swap(T& a, T& b)
{
	T c(a); a = b; b = c;
}


#endif