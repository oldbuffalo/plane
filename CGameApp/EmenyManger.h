#pragma once	
#include"sys.h"
#include"EmenyPlane.h"

class CEmenyManger
{
public:
	list<CEmenyPlane*> m_emerylist;	
public:
	void ALLSurviveEmenyMove();
	void ALLSurviveEmenyShow(HDC hMemDC);
public:
	CEmenyManger(void);
	~CEmenyManger(void);
};

