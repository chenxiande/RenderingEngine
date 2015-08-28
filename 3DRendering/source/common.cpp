#include "../source/common.h"
#include "math.h"
#include "../source/xdVector.h"

float xdLerp(float a, float b, float t)
{
	if (t > 1 || t < 0)
		return a;
	return a + (a - b) * t;
}

int xdRound(float f)
{
	return int(f + 0.5);
}

float xdLerpZ(xdVector3f start, xdVector3f end, float x, float y)
{
	float length = xdVector2f::Length(xdVector2f(end.x - start.x, end.y - start.y));

	float lengthCur = xdVector2f::Length(xdVector2f(x - start.x, y - start.y));

	return xdLerp(start.z, end.z, lengthCur / length);
}

float xdLerpZ(xdVector3i start, xdVector3i end, float x, float y)
{
	float length = xdVector2f::Length(xdVector2f(end.x - start.x, end.y - start.y));

	float lengthCur = xdVector2f::Length(xdVector2f(x - start.x, y - start.y));

	return xdLerp(start.z, end.z, lengthCur / length);
}