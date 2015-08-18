#ifndef XDMATRIX_H
#define XDMATRIX_H


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


	// http://blog.sina.com.cn/s/blog_a401a1ea0101dwq5.html
	// 沿起点为原点的轴 (x,y,z)旋转 angle 度。 (x,y,z)为单位向量
	void   SetRotate(float x, float y, float z, float angle);

	void   LoadIdentity();

private:
	float data[9];

};

//class xdMatrix4f
//{
//public:
//	xdMatrix4f();
//
//
//};
//
//







#endif // !XDMATRIX_H

