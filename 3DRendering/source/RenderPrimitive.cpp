#include "RenderPrimitive.h"
#include "../source/common.h"
#include "math.h"
#include "xdDevice.h"

enum enumDrawLineMethod{
	DDA,
	BRESENHAM
};

enumDrawLineMethod myDrawLineMethod = DDA;


void DrawLineScreenSpace(xdVector3i start, xdVector3i end, unsigned int color)
{
	float lenghSquare = (start.x - end.x) * (start.x - end.x)
					+ (start.y - end.y) * (start.y - end.y);


	if (start.x == end.x && start.y == end.y)
	{
		
		xdDevice::getSingleton().SetPixel(start.x, start.y, min(start.z, end.z), color);
		return;
	}
	else if (start.x == end.x)
	{
		xdVector3i bottom = start.y < end.y ? start : end;
		xdVector3i  top = start.y > end.y ? start : end;
		for (int yCur = bottom.y; yCur <= top.y; ++yCur)
		{
			float zCur = xdLerp(bottom.z, top.z, (float)(yCur - bottom.y) / (top.y - bottom.y));
			xdDevice::getSingleton().SetPixel(start.x, yCur, zCur, color);
		}
		return;
	}
	else if (start.y == end.y)
	{
		xdVector3i left = start.x < end.x ? start : end;
		xdVector3i right = start.x > end.x ? start : end;
		for (int xCur = left.x; xCur <= right.x; ++xCur)
		{
			float zCur = xdLerp(left.z, right.z, (float)(xCur - left.y) / (right.y - left.y));
			xdDevice::getSingleton().SetPixel(xCur, start.y, zCur , color);
		}
		return;
	}


	if (myDrawLineMethod == BRESENHAM)
	{
		DrawLineBresenhamScreenSpace(start, end, color);
	}
	else if (myDrawLineMethod == DDA)
	{
		DrawLineDDAScreenSpace(start, end, color);
	}

}



void DrawLineDDAScreenSpace(xdVector3i start, xdVector3i end, unsigned int color){
	
	int dx = end.x - start.x;
	int dy = end.y - start.y;
	int dz = end.z - start.z;

	int steps, k;

	float xInc, yInc, x = start.x, y = start.y, z = start.z;

	if (abs(dx) > abs(dy))
		steps = abs(dx);
	else
		steps = abs(dy);

	xInc = (float)dx / (float)steps;

	yInc = (float)dy / (float)steps;
	
	float lengthSquare = (end.x - start.x) * (end.x - start.x) + (end.y - start.y) * (end.y - start.y);

	float lentgthIncSquare = (yInc * yInc + xInc * xInc) / lengthSquare;

	float zInc = sqrt(lentgthIncSquare / lengthSquare)  * (start.z - end.z);

	for (k = 0; k < steps; ++k)
	{
		x += xInc;
		y += yInc;
		xdDevice::getSingleton().SetPixel(x, y, z, color);
	}
}

void DrawLineBresenhamScreenSpace(xdVector3i start, xdVector3i end, unsigned int color)
{
	int dx = abs(end.x - start.x), dy = abs(end.y - start.y);
	int p = 2 * dy - dx;
	int twoDy = 2 * dy, twoDyMinusDx = 2 * (dy - dx);

	int x, y;
	float z;
	if (start.x > end.x)
	{
		x = end.x;
		y = end.y;
		z = end.z;
		swap(start, end);
	}
	else
	{
		x = start.x;
		y = start.y;
		z = start.z;
	}
	xdDevice::getSingleton().SetPixel(x, y, z, color);

	float length = xdVector2f::Length(xdVector2f(end.x - start.x, end.y - start.y));
	while (x < end.x)
	{
		x++;
		if (p < 0)
		{
			p += twoDy;
		}
		else
		{
			y++;
			p += twoDyMinusDx;
		}
		float lengthCur = xdVector2f::Length(xdVector2f(x - start.x, y - start.y));
		z = xdLerp(start.z, end.z, xdVector2f::Length(xdVector2f(end.x - start.x, end.y - start.y)));
		xdDevice::getSingleton().SetPixel(x, y, z,color);

	}


}


void DrawTriangleScreenSpace(xdVector3i v1, xdVector3i v2, xdVector3i v3, unsigned int color)
{
	xdVector3i start = v1, end = v1; // 三点一线时候使用

	if (start.y > v2.y) start = v2;
	if (start.y > v3.y) start = v3;

	if (end.y < v2.y) end = v2;
	if (end.y < v3.y) end = v3;

	//排除三点一线情况
	if (v1.x == v2.x == v3.x)
	{


		DrawLineScreenSpace(start, end, color);
	}

	float k1, k2;
	k1 = float(v2.y - v1.y) / float(v2.x - v1.x);
	k2 = float(v3.y - v1.y) / float(v3.x - v1.x);
	if (k1 == k2) //3点一线 非三角形
	{
		DrawLineScreenSpace(start, end, color);
	}


	xdVector3i top = v1, middle = v2, bottom = v3;
	//top.x = v1.x;
	//top.y = v1.y;
	//middle.x = v2.x;
	//middle.y = v2.y;
	//bottom.x = v3.x;
	//bottom.y = v3.y;

	//==============排序=================
	if (top.y > middle.y)
	{
		swap(top, middle);
	}
	if (top.y > bottom.y)
	{
		swap(top, bottom);
	}
	if (middle.y > bottom.y)
	{
		swap(middle, bottom);
	}
	//=====================================
	
	if (middle.y == top.y) //平底三角形
	{
		DrawTriangleScreenSpace1(top, middle, bottom, color);

	}
	else if (middle.y == bottom.y) //平顶三角形
	{
		DrawTriangleScreenSpace2(middle, bottom, top, color);

	}
	else //普通三角形， 切割成一个平底一个平顶三角形
	{
		float dy = (bottom.x - top.x) / (bottom.y - top.y) ;
		xdVector3i middleTmp;

		middleTmp.x = (middle.y - bottom.y) * dy + bottom.x;
		middleTmp.y = middle.y;
		middleTmp.z = xdLerpZ(bottom, top, middle.x, middle.y);

		DrawTriangleScreenSpace1(middle, middleTmp, bottom, color);
		DrawTriangleScreenSpace2(middle, middleTmp , top, color);

	}


}


void DrawTriangleScreenSpace1(xdVector3i top1, xdVector3i top2, xdVector3i bottom, unsigned int color) //平顶三角形
{ 

	if ( top1.y != top2.y && bottom.y > top1.y)
	{
		return;
	}
	float dx1, dx2;

	dx1 = (top1.y - bottom.y != 0) ? (top1.x - bottom.y) / (top1.y - bottom.y) : 0;
	dx2 = (top2.y - bottom.y != 0) ? (top2.x - bottom.x) / (top2.y - bottom.y) : 0;

	for (int y = top1.y; y <= bottom.y; ++y)
	{
		int xStart = xdRound((float)(y - top1.y) * dx1 + top1.x);
		float zStart = xdLerpZ(top1, bottom, (float)(y - top1.y) * dx1 + top1.x, y);
		int xEnd = xdRound((float)(y - top2.y) * dx2 + top2.x);
		float zEnd = xdLerpZ(top2, bottom, (float)(y - top2.y) * dx2 + top2.x, y);
		DrawLineScreenSpace(xdVector3i(xStart, y, zStart), xdVector3i(xEnd, y, zEnd), color);
	}
}


void DrawTriangleScreenSpace2(xdVector3i bottom1, xdVector3i bottom2, xdVector3i top, unsigned int color) // 平底三角形
{
	if( bottom1.y != bottom2.y	&& bottom1.y > top.y)
	{
		return;
	}
	float dx1, dx2;

	dx1 = (top.y - bottom1.y != 0) ? (float)(top.x - bottom1.x) / (top.y - bottom1.y) : 0;
	dx2 = (top.y - bottom2.y != 0) ? (float)(top.x - bottom2.x) / (top.y - bottom2.y) : 0;


	for (int y = bottom1.y; y >= top.y; --y)
	{
		int xStart = xdRound((float)(y - bottom1.y) * dx1 + bottom1.x);
		float zStart = xdLerpZ(bottom1, top, (float)(y - bottom1.y) * dx1 + bottom1.x, y);
		int xEnd = xdRound((float)(y - bottom2.y) * dx2 + bottom2.x);
		float zEnd = xdLerpZ(bottom2, top, (float)(y - bottom2.y) * dx2 + bottom2.x, y);

		DrawLineScreenSpace(xdVector3i(xStart, y, zStart), xdVector3i(xEnd, y, zEnd), color);
	}
};

void DrawCube(xdVector3f pos, float size)
{
	float halfSize = size / 2;
}

