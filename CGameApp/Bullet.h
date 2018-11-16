#pragma once
#include"sys.h"
class CBullet
{
public:
	int m_x;
	int m_y;
	HBITMAP hBitmap; 
public:
	void InitBullet(HINSTANCE hins);
	void ShowBullet(HDC hMemDC);
	void MoveBullet();
public:
	CBullet(int x,int y);
	~CBullet(void);
};

