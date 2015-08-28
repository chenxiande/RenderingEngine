#ifndef XDMATRIX_H
#define XDMATRIX_H

class xdVector3f;
/////////////左手系， 在计算旋转时注意
class xdMatrix3f
{
public:
	xdMatrix3f();
	xdMatrix3f(float, float, float,
				float, float, float,
				float, float, float);
	xdMatrix3f(const xdMatrix3f &m);

	xdMatrix3f operator +(const xdMatrix3f &m);
	xdMatrix3f operator -(const xdMatrix3f &m);
	xdMatrix3f operator *(const xdMatrix3f &m);


	float  GetData(int idx) const;
	float  GetData(int row, int col) const;
	bool   SetData(int idx, float val);
	bool   SetData(int row, int col, float val);


	void   Scale(float sc);
	void   SetScale(float kx, float ky, float kz);


	// http://blog.sina.com.cn/s/blog_a401a1ea0101dwq5.html
	// 沿起点为原点的轴 (x,y,z)旋转 angle 度。 (x,y,z)为单位向量
	void   SetRotate(float x, float y, float z, float angle);

	void   LoadIdentity();
	void   SetZero();

private:
	float data[9];

};

class xdMatrix4f
{
public:
	xdMatrix4f();
	xdMatrix4f(float, float, float, float ,
				float, float, float, float,
				float, float, float, float,
				float, float, float, float);
	xdMatrix4f(const xdMatrix4f &m);

	xdMatrix4f(const xdMatrix3f &m , float w = 1.0f);

	xdMatrix4f operator +(const xdMatrix4f &m);
	xdMatrix4f operator -(const xdMatrix4f &m);
	xdMatrix4f operator *(const xdMatrix4f &m);


	float  GetData(int idx) const;
	float  GetData(int row, int col) const;
	bool   SetData(int idx, float val);
	bool   SetData(int row, int col, float val);


	void   Scale(float sc);
	void   SetScale(float kx, float ky, float kz, float kw = 0);


	// http://blog.sina.com.cn/s/blog_a401a1ea0101dwq5.html
	// 沿起点为原点的轴 (x,y,z)旋转 angle 度。 (x,y,z)为单位向量
	void   SetRotate(float x, float y, float z, float angle);

	void   SetTranslate(float tx, float ty, float tz);

	void   LoadIdentity();

	void   SetOrthogonalProj(float left, float right, float top, float bottom,  float far ,float near);

	void   SetZero();

	void   LookAt(xdVector3f eye, xdVector3f at, xdVector3f up);

private:
	float data[16];

};






#endif // !XDMATRIX_H

