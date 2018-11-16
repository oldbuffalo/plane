#include "BigPlane.h"



void CBigPlane::InitEmenyPlane(HINSTANCE hins)
{
	hBitmap = ::LoadBitmap(hins,MAKEINTRESOURCE(IDB_BIGPLANE));
}
void CBigPlane::ShowEmenyPlane(HDC hMemDC)
{
 	HDC TempDC = ::CreateCompatibleDC(hMemDC);

	::SelectObject(TempDC,hBitmap);

	::BitBlt(hMemDC,m_x,m_y,108,129,TempDC,0,(3-nShowID)*129,SRCAND);

	::DeleteObject(TempDC);
}
void CBigPlane::MoveEmenyPlane()
{
	m_y += 4;
}


CBigPlane::CBigPlane(void)
{
	m_x = rand()%(380-108);
	m_y = -130;
	width = 108;
	length = 129;
	blood = 8;
	nShowID = 3;
	hBitmap = NULL;
}


CBigPlane::~CBigPlane(void)
{
	::DeleteObject(hBitmap);
	hBitmap = NULL;
}
