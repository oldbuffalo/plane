#pragma once
#include"sys.h"
#include"EmenyPlane.h"
class CBoomEmenyPlane
{
public:
	list<CEmenyPlane*> m_BoomPlanelist;
public:
	void ShowAlBoomPlane(HDC hMemDC);
	void ChangeShowId();
public:
	CBoomEmenyPlane(void);
	~CBoomEmenyPlane(void);
};

