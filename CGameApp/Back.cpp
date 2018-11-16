#include "Back.h"
#include"sys.h"

CBack::CBack(void)
{
	m_x = 0;
	m_y = 0;
	hBackbitmap[0] = NULL;
	hBackbitmap[1] = NULL;
}


CBack::~CBack(void)
{
	::DeleteObject(hBackbitmap[0]);
	hBackbitmap[0] = NULL;
	::DeleteObject(hBackbitmap[1]);
	hBackbitmap[1] = NULL;
}

void CBack::InitBack(HINSTANCE hins)
{
	hBackbitmap[0] = ::LoadBitmap(hins,MAKEINTRESOURCE(IDB_BACK));	
	hBackbitmap[1] = ::LoadBitmap(hins,MAKEINTRESOURCE(IDB_BACK));
}
void CBack::ShowBack(HDC hMemDc)
{
	HDC hTempDC = ::CreateCompatibleDC(hMemDc);
	SelectObject(hTempDC,hBackbitmap[0]);
	BitBlt(hMemDc,m_x,m_y-550,380,550,hTempDC,0,0,SRCCOPY);
	SelectObject(hTempDC,hBackbitmap[1]);
	BitBlt(hMemDc,m_x,m_y,380,550,hTempDC,0,0,SRCCOPY);

	::DeleteObject(hTempDC);
}
void CBack::MoveBack()
{
	if(m_y <=550){
		m_y += 3;
	}
	else
		m_y  = 0;
}