#include "../source/xdVector.h"
#include "stdio.h"
#include "../source/xdMatrix.h"
//#pragma comment(lib, "../lib/3DRenderingLib.lib")
int main()
{
	xdMatrix3f m1(1.0, 2.0, 2.0,
				  2.0 , 4.0 , 7.5,
				  -1.0, -3.0 ,3.5);

	xdMatrix3f m2(1.0, 2.0, 2.0,
					2.0, 4.0, 7.5,
					-1.0, -3.0, 3.5);

	xdMatrix3f m3 = m1 + m2;

	xdMatrix3f m4 = m1 - m2;

	m3 = m1 * m2;

	m4.LoadIdentity();

	m3 = m4 * m1;
	getchar();

}