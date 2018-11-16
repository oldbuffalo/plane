#pragma once
#include "emenyplane.h"
class CBigPlane :
	public CEmenyPlane
{
public:
	virtual void InitEmenyPlane(HINSTANCE hins); 
	virtual void ShowEmenyPlane(HDC hMemDC); 
	virtual void MoveEmenyPlane(); 
public:
	CBigPlane(void);
	~CBigPlane(void);
};

