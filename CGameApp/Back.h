#pragma once
#include"sys.h"
class CBack
{
public:
	HBITMAP hBackbitmap[2];
	int m_x;
	int m_y;
public:
	void InitBack(HINSTANCE hins);
	void ShowBack(HDC hMemDc);
	void MoveBack();
public:
	CBack(void);
	~CBack(void);
};

