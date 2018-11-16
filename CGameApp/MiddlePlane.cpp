#include "MiddlePlane.h"



void CMiddlePlane::InitEmenyPlane(HINSTANCE hins)
{
	hBitmap = ::LoadBitmap(hins,MAKEINTRESOURCE(IDB_MIDPLANE));
}
void CMiddlePlane::ShowEmenyPlane(HDC hMemDC)
{
	HDC TempDC = ::CreateCompatibleDC(hMemDC);

	::SelectObject(TempDC,hBitmap);

	::BitBlt(hMemDC,m_x,m_y,70,90,TempDC,0,(2-nShowID)*90,SRCAND);

	::DeleteObject(TempDC);
}
void CMiddlePlane::MoveEmenyPlane()
{
	 m_y += 6;
}




CMiddlePlane::CMiddlePlane(void)
{
	blood = 4;
	m_x = rand()%(380-70);
	m_y = -90;
	width = 70;
	length = 90;
	nShowID = 2;
	hBitmap = NULL;
}


CMiddlePlane::~CMiddlePlane(void)
{
	::DeleteObject(hBitmap);
	hBitmap = NULL;
}
