#ifndef XDVECTOR_H
#define XDVECTOR_H

class xdMatrix4f;

class xdVector2f
{
public:
	xdVector2f();
	xdVector2f(float _x, float _y);
	xdVector2f(const xdVector2f &v);
	~xdVector2f();

public:
	static float Dot(const xdVector2f &v1, const xdVector2f &v2);
	static float Length(const xdVector2f &v);

public:
	void Normalize();

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
	static float Dot(const xdVector3f &v1, const xdVector3f &v2);
	static float Length(const xdVector3f &v);

	static xdVector3f Cross(const xdVector3f &v1, const xdVector3f &v2);

public:
	void Normalize();

public:
	xdVector3f operator +(const xdVector3f &v);
	xdVector3f operator -(const xdVector3f &v);
public:
	float x, y, z;
};

class xdVector4f
{
public:
	xdVector4f();
	xdVector4f(float _x, float _y, float _z,float _w = 1.0);
	xdVector4f(const xdVector4f &v);
	xdVector4f(const xdVector3f &v, float w = 1.0f);
	~xdVector4f();



public:
	static float Dot(const xdVector4f &v1, const xdVector4f &v2);
	static float Length(const xdVector4f &v);
	static xdVector4f MulMatrix(const xdVector4f &v, const xdMatrix4f &m);


public:
	void Normalize();


public:
	xdVector4f operator +(const xdVector4f &v);
	xdVector4f operator -(const xdVector4f &v);
public:
	float x, y, z,w;
};



class xdVector3i
{
public:
	xdVector3i();
	xdVector3i(int _x, int _y, int _z);
	xdVector3i(const xdVector3i &v);
	~xdVector3i();

public:
	static float Dot(const xdVector3i &v1, const xdVector3i &v2);
	static float Length(const xdVector3i &v);

	static xdVector3i Cross(const xdVector3i &v1, const xdVector3i &v2);

public:
	void Normalize();

public:
	xdVector3i operator +(const xdVector3i &v);
	xdVector3i operator -(const xdVector3i &v);
public:
	int x, y, z;
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
