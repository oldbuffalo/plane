#pragma once
#include"sys.h"


class CEmenyPlane
{
public:
	int m_x;
	int m_y;
	int width;
	int length;
	int blood;
	HANDLE hBitmap;
	int nShowID;
public:
	virtual void InitEmenyPlane(HINSTANCE hins) = 0; 
	virtual void ShowEmenyPlane(HDC hMemDC) = 0; 
	virtual void MoveEmenyPlane() = 0; 
	bool IsExplosion()
	{
		if(blood == 0)
			return true;
		else
			return false;
	}
public:
	CEmenyPlane(void);
	virtual ~CEmenyPlane(void);
};

