#include "../source/xdDevice.h"
#include "malloc.h"
#include "string.h"
#include "common.h"
#include "RenderPrimitive.h"

xdDevice::xdDevice()
{
	screenHeight = 0;
	screenWidth = 0;
	frameBuffer = NULL;

}

xdDevice::~xdDevice()
{
	delete frameBuffer;
	delete zBuffer;
}

bool xdDevice::Init(int sw, int sh)
{
	screenWidth = sw;
	screenHeight = sh;

	frameBuffer = (unsigned int *)malloc(sw * sh * sizeof(unsigned int));
	zBuffer = (float *)malloc(sw * sh * sizeof(float));

	for (int i = 0; i < sw * sh; ++i)
	{
		frameBuffer[i] = 0;
	}

	for (int i = 0; i < sw * sh; ++i)
	{
		zBuffer[i] = 1;
	}



	//memset((char*)framebuffer, 0xff , sizeof(sw * sh * sizeof(unsigned int)));
	//ClearFrameBuffer(xdRGB(0, 0, 0));
	return true;

}

void xdDevice::SetScreenHeight(int h)
{
	screenHeight = h;
}

void xdDevice::SetScreenWidth(int w)
{
	screenWidth = w;
}

int xdDevice::GetScreenHeight()
{
	return screenHeight;
}

int xdDevice::GetScreenWidth()
{
	return screenWidth;
}

void xdDevice::SetPixel(int x, int y, unsigned int color)
{
	frameBuffer[x + y * screenWidth] = color;
}

void xdDevice::SetPixel(int x, int y, float z, unsigned int color)
{
	if (z < zBuffer[x + y * screenWidth])
	{
		frameBuffer[x + y * screenWidth] = color;
		zBuffer[x + y * screenWidth] = z;
	}
	else
	{
		int a = 20;
	}
}

unsigned int * xdDevice::GetFrameBufferData()
{
	return frameBuffer;
}

void xdDevice::ClearFrameBuffer(unsigned int color)
{
	for (int i = 0; i < screenWidth; ++i)
		for (int j = 0; j < screenHeight; ++j)
		{
			SetPixel(i, j,  color);
		}

}

void xdDevice::SetModelMatrix(xdMatrix4f mat)
{
	model = mat;
	UpadteMVP();

}

void xdDevice::SetViewMatrix(xdMatrix4f mat)
{
	view = mat;
	UpadteMVP();
}

void xdDevice::SetProjectionMatrix(xdMatrix4f mat)
{
	projection = mat;
	UpadteMVP();
}

void xdDevice::UpadteMVP()
{
	mvp = model * view * projection;
}

xdVector3f xdDevice::GetScreenSpacePos(xdVector3f pos)
{
	//  1.0 > x > -1.0  1 > y > -1.0  1.0f > z > 0
	return xdVector3f(	(pos.x + 1) / 2 * screenWidth,
						(1 - pos.y) / 2 * screenHeight, pos.z);
}

void xdDevice::DrawTriangle(xdVector3f p1, xdVector3f p2, xdVector3f p3 ,unsigned int color)
{
	xdVector4f t1(p1,1.0f), t2(p2,1.0f), t3(p3 ,1.0f);

	p1 = GetScreenSpacePos(p1);
	p2 = GetScreenSpacePos(p2);
	p3 = GetScreenSpacePos(p3);


	DrawTriangleScreenSpace(xdVector3i(p1.x, p1.y, p1.z), xdVector3i(p2.x, p2.y, p2.z), 
									xdVector3i(p3.x, p3.y, p3.z), color		);


}