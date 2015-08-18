#ifndef XDVECTOR_H
#define XDVECTOR_H


class xdVector2f
{
public:
	xdVector2f();
	xdVector2f(float _x, float _y);
	xdVector2f(const xdVector2f &v);
	~xdVector2f();

public:
	xdVector2f operator +(const xdVector2f &v);
	xdVector2f operator -(const xdVector2f &v);
public:
	float x, y;
};

class xdVector3f
{
public:
	xdVector3f();
	xdVector3f(float _x, float _y,float _z);
	xdVector3f(const xdVector3f &v);
	~xdVector3f();

public:


public:
	xdVector3f operator +(const xdVector3f &v);
	xdVector3f operator -(const xdVector3f &v);
public:
	float x, y, z;
};



//template<class T> class xdVector3
//{
//public:
//	xdVector3();
//	~xdVector3();
//public:
//	T x, y, z;
//};
//
//template<class T> class xdVector4
//{
//public:
//	xdVector4();
//	~xdVector4();
//public:
//	T x, y, z ,w;
//};





#endif // !XDVECTOR_H
