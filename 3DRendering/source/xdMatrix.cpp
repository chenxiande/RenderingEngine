#include "../source/xdMatrix.h"
#include "string.h"

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