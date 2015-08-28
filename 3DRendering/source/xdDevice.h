#ifndef XDDEVICE_H
#define XDDEVICE_H

#include "../source/xdMatrix.h"
#include "../source/singleton.h"

class xdDevice : public Singleton<xdDevice>{
public:
	xdDevice();
	~xdDevice();


	bool Init(int sw, int sh);
	void SetScreenWidth(int w);
	void SetScreenHeight(int h);
	int  GetScreenWidth();
	int  GetScreenHeight();
	void SetPixel(int x, int y, float z, unsigned int color);
	void SetPixel(int x, int y, unsigned int color);
	unsigned int * GetFrameBufferData();

	void ClearFrameBuffer(unsigned int color);

	void SetModelMatrix(xdMatrix4f mat);
	void SetViewMatrix(xdMatrix4f mat);
	void SetProjectionMatrix(xdMatrix4f mat);

	void DrawTriangle(xdVector3f p1, xdVector3f p2, xdVector3f p3 ,unsigned int color);

	xdVector3f GetScreenSpacePos(xdVector3f pos);

private:
	void UpadteMVP();

private:
	xdMatrix4f model, view, projection;
	xdMatrix4f mvp; // mvp = model * view * projection

	int screenWidth;
	int screenHeight;

public:
	unsigned int *frameBuffer;      // 像素缓存：framebuffer[y] 代表第 y行
	float *zBuffer;

};



#endif // !XDDEVICE_H
