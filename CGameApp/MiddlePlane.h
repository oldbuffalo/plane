#pragma once
#include "emenyplane.h"
class CMiddlePlane :
	public CEmenyPlane
{
public:
	virtual void InitEmenyPlane(HINSTANCE hins); 
	virtual void ShowEmenyPlane(HDC hMemDC); 
	virtual void MoveEmenyPlane(); 

public:
	CMiddlePlane(void);
	~CMiddlePlane(void);
};

