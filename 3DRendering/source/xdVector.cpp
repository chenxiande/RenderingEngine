#include "xdVector.h"
#include "xdMatrix.h"
#include "math.h"

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

void xdVector2f::Normalize()
{
	float len = xdVector2f::Length(*this);

	x = x / len;
	y = y / len;
}

float xdVector2f::Length(const xdVector2f &v)
{

	return sqrt(v.x * v.x + v.y * v.y);
}

float xdVector2f::Dot(const xdVector2f &v1, const xdVector2f &v2)
{
	return v1.x * v2.x + v1.y * v2.y;
}

//////////////////////////////////////////////////////////////////////////
//vector3
//////////////////////////////////////////////////////////////////////////
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

float xdVector3f::Dot(const xdVector3f &v1,const xdVector3f &v2)
{
	return v1.x * v2.x + v1.y * v2.y + v1.z * v2.z;

}

float xdVector3f::Length(const xdVector3f &v)
{
	return sqrt(v.x * v.x + v.y * v.y + v.z * v.z);
}

void  xdVector3f::Normalize()
{
	float len = xdVector3f::Length(*this);
	x = x / len;
	y = y / len;
	z = z / len;
}

xdVector3f xdVector3f::Cross(const xdVector3f &v1, const xdVector3f &v2)
{
	return xdVector3f(v1.y * v2.z - v2.y * v1.z, v1.z * v2.x - v1.x * v2.z,
						v1.x * v2.y - v2.x * v1.y);
}
//////////////////////////////////////////////////////////////////////////
//                              xdVector4f                              //
//////////////////////////////////////////////////////////////////////////
xdVector4f::xdVector4f()
{
	x = y = z = 0;
	w = 1.0;
}

xdVector4f::~xdVector4f()
{
}
xdVector4f::xdVector4f(float _x, float _y, float _z, float _w /* = 1.0 */)
{
	x = _x;
	y = _y;
	z = _z;
	w = _w;
}

xdVector4f::xdVector4f(const xdVector4f &v)
{
	x = v.x;
	y = v.y;
	z = v.z;
}

xdVector4f::xdVector4f(const xdVector3f &v, float w)
{

}

xdVector4f xdVector4f::operator-(const xdVector4f &v)
{
	return xdVector4f(x - v.x, y - v.y, z - v.z, w - v.w);
}

xdVector4f xdVector4f::operator+(const xdVector4f &v)
{
	return xdVector4f(x + v.x, y + v.y, z + v.z, w + v.w);
}

xdVector4f xdVector4f::MulMatrix(const xdVector4f &v, const xdMatrix4f &m)
{

	float res[4];
	for (int idx = 0; idx < 4;++ idx)
	{
		res[idx] = v.x * m.GetData(0, idx) + v.y * m.GetData(1, idx)
			+ v.z * m.GetData(2, idx) + v.w * m.GetData(3, idx);
	}			
	return xdVector4f(res[0], res[1], res[2], res[3]);
}

float xdVector4f::Length(const xdVector4f &v)
{
	return sqrt(v.x * v.x +  v.y * v.y +  v.z * v.z + v.w * v.w);
}

float xdVector4f::Dot(const xdVector4f &v1, const xdVector4f &v2)
{
	return  v1.x * v2.x + v1.y * v2.y + v1.z * v2.z + v1.w * v2.w;
}

void xdVector4f::Normalize()
{
	float len = xdVector4f::Length(*this);
	x = x / len;
	y = y / len;
	z = z / len;
	w = w / len;

}

//////////////////////////////////////////////////////////////////////////
//                              xdVector3i                              //
//////////////////////////////////////////////////////////////////////////

xdVector3i::xdVector3i()
{
	x = 0;
	y = 0;
	z = 0;
}

xdVector3i::xdVector3i(int _x, int _y, int _z)
{
	x = _x;
	y = _y;
	z = _z;
}

xdVector3i::xdVector3i(const xdVector3i &v)
{
	x = v.x;
	y = v.y;
	z = v.z;
}

xdVector3i::~xdVector3i()
{

}
xdVector3i xdVector3i::operator+(const xdVector3i &v)
{
	return xdVector3i(x + v.x, y + v.y, z + v.z);

}

xdVector3i xdVector3i::operator-(const xdVector3i &v)
{
	return xdVector3i(x - v.x, y - v.y, z - v.z);
}

float xdVector3i::Dot(const xdVector3i &v1, const xdVector3i &v2)
{
	return v1.x * v2.x + v1.y * v2.y + v1.z * v2.z;

}

float xdVector3i::Length(const xdVector3i &v)
{
	return sqrt(float(v.x * v.x + v.y * v.y + v.z * v.z));
}

void  xdVector3i::Normalize()
{
	float len = xdVector3i::Length(*this);
	x = x / len;
	y = y / len;
	z = z / len;
}

xdVector3i xdVector3i::Cross(const xdVector3i &v1, const xdVector3i &v2)
{
	return xdVector3i(v1.y * v2.z - v2.y * v1.z, v1.z * v2.x - v1.x * v2.z,
		v1.x * v2.y - v2.x * v1.y);
}