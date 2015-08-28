#include "../source/xdMatrix.h"
#include "string.h"
#include "math.h"
#include "xdVector.h"

xdMatrix3f::xdMatrix3f()
{
	memset(data, 0, sizeof(data));
	data[0] = data[4] = data[8] = 1.0f;
}

xdMatrix3f::xdMatrix3f(const xdMatrix3f &m)
{
	for (int idx = 0; idx < 9; ++idx)
	{
		data[idx] = m.GetData(idx);
	}
}

xdMatrix3f::xdMatrix3f(float f00, float f01, float f02,
						float f10, float f11, float f12,
						float f20, float f21, float f22)
{
	data[0] = f00;
	data[1] = f01;
	data[2] = f02;
	data[3] = f10;
	data[4] = f11;
	data[5] = f12;
	data[6] = f20;
	data[7] = f21;
	data[8] = f22;

}


float xdMatrix3f::GetData(int idx) const 
{
	if (idx < 9 && idx >= 0 )
	{
		return data[idx];
	}
}
float xdMatrix3f::GetData(int row, int col) const 
{
	if (row < 3 && row >= 0
		&& col < 3 && row >= 0)
	{
		return data[row * 3 + col];
	}
}

bool xdMatrix3f::SetData(int idx, float val)
{
	if (idx < 9 && idx >=0)
	{
		data[idx] = val;
		return true;
	}
	return  false;
}

bool xdMatrix3f::SetData(int row, int col, float val)
{
	if (row < 3 && row >= 0
		&& col < 3 && row >= 0)
	{
		data[row * 3 + col] = val;
		return true;
	}
	return false;

}

xdMatrix3f xdMatrix3f::operator *(const xdMatrix3f &m)
{
	xdMatrix3f res;
	for (int resRow = 0; resRow < 3; ++resRow )
	{
		for (int resCol = 0; resCol < 3; ++resCol)
		{
			float val = 0;
			for (int idx = 0; idx < 3; ++idx)
			{
				val += this->GetData(resRow, idx) * m.GetData(idx, resCol);
			}
			res.SetData(resRow, resCol, val);
		}
	}
	return res;
}

xdMatrix3f xdMatrix3f::operator -(const xdMatrix3f &m)
{
	xdMatrix3f res;
	for (int idx = 0; idx < 9; ++idx)
	{
		res.SetData(idx, this->GetData(idx) - m.GetData(idx));
	}
	return res;
}

xdMatrix3f xdMatrix3f::operator + (const xdMatrix3f &m)
{
	xdMatrix3f res;
	for (int idx = 0; idx < 9; ++idx)
	{
		res.SetData(idx, this->GetData(idx) + m.GetData(idx));
	}
	return res;
}

void xdMatrix3f::LoadIdentity()
{
	memset(data, 0, sizeof(data));
	data[0] = data[4] = data[8] = 1.0f;
}

void xdMatrix3f::Scale(float sc)
{
	for (int idx = 0; idx < 9; ++idx)
	{
		data[idx] *= sc;
	}
}
void xdMatrix3f::SetScale(float kx, float ky, float kz)
{
	LoadIdentity();
	data[0] = kx;
	data[4] = ky;
	data[8] = kz;

}

void xdMatrix3f::SetRotate(float x, float y, float z, float angle)
{
	data[0] = x * x * (1 - cos(angle)) + cos(angle);
	data[1] = x * y * (1 - cos(angle)) + z * sin(angle);
	data[2] = x * z * (1 - cos(angle)) - y * sin(angle);

	data[3] = x * y * (1 - cos(angle)) - x * sin(angle);
	data[4] = y * y * (1 - cos(angle)) + cos(angle);
	data[5] = y * z * (1 - cos(angle)) + x * sin(angle);

	data[6] = x * z * (1 - cos(angle)) + y * sin(angle); 
	data[7] = y * z * (1 - cos(angle)) - x * sin(angle);
	data[8] = z * z * (1 - cos(angle)) + cos(angle);
}

void xdMatrix3f::SetZero()
{
	memset(data, 0, sizeof(data));
}


//------------------------------------------------------xdMatrix4f_____________________________


xdMatrix4f::xdMatrix4f()
{
	memset(data, 0, sizeof(data));
	data[0] = data[5] = data[10] = data[15] = 1.0f;
}

xdMatrix4f::xdMatrix4f(const xdMatrix4f &m)
{
	for (int idx = 0; idx < 16; ++idx)
	{
		data[idx] = m.GetData(idx);
	}
}
xdMatrix4f::xdMatrix4f(const xdMatrix3f &m , float w)
{
	memset(data, 0, sizeof(data));
	data[15] = w;
	for (int row = 0; row < 4; ++row)
	{
		for (int col = 0; col < 4; ++col)
		{
			this->SetData(row, col, m.GetData(row, col));
		}
	}
}

xdMatrix4f::xdMatrix4f(float f00, float f01, float f02, float f03,
	float f10, float f11, float f12, float f13,
	float f20, float f21, float f22, float f23,
	float f30, float f31, float f32, float f33)
{
	data[0] = f00;
	data[1] = f01;
	data[2] = f02;
	data[3] = f03;
	data[4] = f10;
	data[5] = f11;
	data[6] = f12;
	data[7] = f13;
	data[8] = f20;
	data[9] = f21; 
	data[10] = f22;
	data[11] = f23;
	data[12] = f30;
	data[13] = f31;
	data[14] = f32;
	data[15] = f33;

}


float xdMatrix4f::GetData(int idx) const
{
	if (idx < 15 && idx >= 0)
	{
		return data[idx];
	}
}
float xdMatrix4f::GetData(int row, int col) const
{
	if (row < 4 && row >= 0
		&& col < 4 && row >= 0)
	{
		return data[row * 4 + col];
	}
}

bool xdMatrix4f::SetData(int idx, float val)
{
	if (idx < 16 && idx >= 0)
	{
		data[idx] = val;
		return true;
	}
	return  false;
}

bool xdMatrix4f::SetData(int row, int col, float val)
{
	if (row < 4 && row >= 0
		&& col < 4 && row >= 0)
	{
		data[row * 4 + col] = val;
		return true;
	}
	return false;

}

xdMatrix4f xdMatrix4f::operator *(const xdMatrix4f &m)
{
	xdMatrix4f res;
	for (int resRow = 0; resRow < 4; ++resRow)
	{
		for (int resCol = 0; resCol < 4; ++resCol)
		{
			float val = 0;
			for (int idx = 0; idx < 4; ++idx)
			{
				val += this->GetData(resRow, idx) * m.GetData(idx, resCol);
			}
			res.SetData(resRow, resCol, val);
		}
	}
	return res;
}

xdMatrix4f xdMatrix4f::operator -(const xdMatrix4f &m)
{
	xdMatrix4f res;
	for (int idx = 0; idx < 16; ++idx)
	{
		res.SetData(idx, this->GetData(idx) - m.GetData(idx));
	}
	return res;
}

xdMatrix4f xdMatrix4f::operator + (const xdMatrix4f &m)
{
	xdMatrix4f res;
	for (int idx = 0; idx < 16; ++idx)
	{
		res.SetData(idx, this->GetData(idx) + m.GetData(idx));
	}
	return res;
}

void xdMatrix4f::LoadIdentity()
{
	memset(data, 0, sizeof(data));
	data[0] = data[5] = data[10] = data[15] = 1.0f;
}

void xdMatrix4f::Scale(float sc)
{
	for (int idx = 0; idx < 16; ++idx)
	{
		data[idx] *= sc;
	}
}
void xdMatrix4f::SetScale(float kx, float ky, float kz, float kw/* =0 */)
{
	LoadIdentity();
	data[0] = kx;
	data[5] = ky;
	data[10] = kz;
	data[15] = kw;
}

void xdMatrix4f::SetRotate(float x, float y, float z, float angle)
{
	data[0] = x * x * (1 - cos(angle)) + cos(angle);
	data[1] = x * y * (1 - cos(angle)) + z * sin(angle);
	data[2] = x * z * (1 - cos(angle)) - y * sin(angle);

	data[3] = x * y * (1 - cos(angle)) - x * sin(angle);
	data[4] = y * y * (1 - cos(angle)) + cos(angle);
	data[5] = y * z * (1 - cos(angle)) + x * sin(angle);

	data[6] = x * z * (1 - cos(angle)) + y * sin(angle);
	data[7] = y * z * (1 - cos(angle)) - x * sin(angle);
	data[8] = z * z * (1 - cos(angle)) + cos(angle);
}

void xdMatrix4f::SetTranslate(float tx, float ty, float tz)
{
	LoadIdentity();
	data[12] = tx;
	data[13] = ty;
	data[14] = tz;
}

void xdMatrix4f::SetZero()
{
	memset(data, 0, sizeof(data));
}

void xdMatrix4f::SetOrthogonalProj(float left, float right, float top, float bottom, float far, float near)
{
	xdMatrix4f m1, m2;
	m1.SetTranslate(-(right + left) / (right - left), -(top + bottom) / (top - bottom),
		- near / (far - near));
	m2.SetScale(2 / (right - left), 2 / (top - bottom), 1 / (far - near) ,1.0f);

	*this = m1 * m2;
}

void xdMatrix4f::LookAt(xdVector3f eye, xdVector3f at, xdVector3f up)
{
	xdVector3f zaxis = at - eye;
	zaxis.Normalize();

	xdVector3f xaxis = xdVector3f::Cross(up, zaxis);
	xaxis.Normalize();

	xdVector3f yaxis = xdVector3f::Cross(xaxis, zaxis);
	/*
		xaxis.x           yaxis.x           zaxis.x           0
		xaxis.y           yaxis.y           zaxis.y           0
		xaxis.z           yaxis.z           zaxis.z           0
		- dot(xaxis, eye) - dot(yaxis, eye) - dot(zaxis, eye)  l*/

	float dataTmp[] = { xaxis.x, yaxis.x, zaxis.x, 0,
		xaxis.y, yaxis.y, zaxis.y, 0,
		xaxis.z, yaxis.z, zaxis.z, 0,
		-xdVector3f::Dot(xaxis, eye), -xdVector3f::Dot(yaxis, eye), -xdVector3f::Dot(zaxis, eye), 1.0f };


	for(size_t idx = 0; idx < 16; idx++)
	{
		data[idx] = dataTmp[idx];
	}
};


