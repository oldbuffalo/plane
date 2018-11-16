#include "SmallPlane.h"


void CSmallPlane::InitEmenyPlane(HINSTANCE hins)
{
	hBitmap = ::LoadBitmap(hins,MAKEINTRESOURCE(IDB_SMALLPLANE));
}
void CSmallPlane::ShowEmenyPlane(HDC hMemDC)
{
	HDC TempDC = ::CreateCompatibleDC(hMemDC);

	::SelectObject(TempDC,hBitmap);

	::BitBlt(hMemDC,m_x,m_y,34,28,TempDC,0,(1-nShowID)*28,SRCAND);

	::DeleteObject(TempDC);
}
void CSmallPlane::MoveEmenyPlane()
{
	m_y += 10;
}




CSmallPlane::CSmallPlane(void)
{
	m_x = rand()%(380-34);
	m_y = -28;
	width = 34;
	length = 28;
	blood = 2;
	nShowID = 1;
	hBitmap = NULL;
}


CSmallPlane::~CSmallPlane(void)
{
	::DeleteObject(hBitmap);
	hBitmap = NULL;
}
