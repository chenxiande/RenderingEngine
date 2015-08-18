#include "xdVector.h"

//vector2 func-----------------------------------------

xdVector2f::xdVector2f()
{
	x = 0;
	y = 0;
}

xdVector2f::xdVector2f(float _x, float _y)
{
	x = _x;
	y = _y;
}

xdVector2f::xdVector2f(const xdVector2f &v)
{
	x = v.x;
	y = v.y;
}

xdVector2f::~xdVector2f()
{

}
xdVector2f xdVector2f::operator+(const xdVector2f &v)
{
	return xdVector2f(v.x + x, v.y + y);

}

xdVector2f xdVector2f::operator-(const xdVector2f &v)
{
	return xdVector2f(v.x - x, v.y - y);
}

//vector3

xdVector3f::xdVector3f()
{
	x = 0;
	y = 0;
	z = 0;
}

xdVector3f::xdVector3f(float _x, float _y, float _z)
{
	x = _x;
	y = _y;
	z = _z;
}

xdVector3f::xdVector3f(const xdVector3f &v)
{
	x = v.x;
	y = v.y;
	z = v.z;
}

xdVector3f::~xdVector3f()
{

}
xdVector3f xdVector3f::operator+(const xdVector3f &v)
{
	return xdVector3f(x + v.x, y + v.y ,z + v.z);

}

xdVector3f xdVector3f::operator-(const xdVector3f &v)
{
	return xdVector3f(x - v.x, y - v.y ,z - v.z);
}

