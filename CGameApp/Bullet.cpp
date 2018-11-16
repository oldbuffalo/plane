#include "Bullet.h"




void CBullet::InitBullet(HINSTANCE hins)
{
	hBitmap = ::LoadBitmap(hins,MAKEINTRESOURCE(IDB_BULLET));
}
void CBullet::ShowBullet(HDC hMemDC)
{
	HDC TempDC = ::CreateCompatibleDC(hMemDC);

	::SelectObject(TempDC,hBitmap);

	BitBlt(hMemDC,m_x,m_y,6,9,TempDC,0,0,SRCCOPY);

	::DeleteObject(TempDC);
}
void CBullet::MoveBullet()
{
	this->m_y -= 10;
}

CBullet::CBullet(int x,int y)
{
	this->m_x = x;
	this->m_y = y;
	hBitmap = NULL;
}


CBullet::~CBullet(void)
{
	::DeleteObject(hBitmap);
	hBitmap = NULL;
}
