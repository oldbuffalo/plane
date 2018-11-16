#pragma once
#include "emenyplane.h"

class CSmallPlane :
	public CEmenyPlane
{
public:
	virtual void InitEmenyPlane(HINSTANCE hins); 
	virtual void ShowEmenyPlane(HDC hMemDC); 
	virtual void MoveEmenyPlane(); 
public:
	CSmallPlane(void);
	~CSmallPlane(void);
};

