#include "../source/common.h"
#include "math.h"


float xdLerp(float a, float b, float t)
{
	return a + (a - b) * t;
}

xdVector3f Normalize(const xdVector3f &v)
{

	float length = sqrt(v.x * v.x + v.y * v.y + v.z * v.z);
	return xdVector3f(1 / length * v.x, 1 / length * v.y, 1 / length *v.z);
}

float Dot(const xdVector3f &v1, const xdVector3f &v2)
{
	return v1.x * v2.x + v1.y * v2.y + v1.z * v2.z;
}

float Dot(const xdVector2f &v1, const xdVector2f &v2)
{
	return v1.x * v2.x + v1.y * v2.y ;
}