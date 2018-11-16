#include "Player.h"




void CPlayer::InitPlayer(HINSTANCE hins)
{
	hBitmap = ::LoadBitmap(hins,MAKEINTRESOURCE(IDB_PLAYER));
}
void CPlayer::ShowPlayer(HDC hMemDC)
{
	HDC hTempDC = ::CreateCompatibleDC(hMemDC);

	SelectObject(hTempDC,hBitmap);

	//BitBlt(hMemDC,m_x,m_y,60,60,hTempDC,0,0,SRCCOPY);
	BitBlt(hMemDC,m_x,m_y,60,60,hTempDC,0,0,SRCAND);

	::DeleteObject(hTempDC);
}
void CPlayer::MovePlayer(int Fx)
{	
	switch(Fx)
	{
	case VK_DOWN:
		if(m_y <= 470 )
			m_y += 2;
		break;
	case VK_UP:
		if(m_y >= 2)
			m_y -= 2;
		break;
	case VK_LEFT:
		if(m_x >=2)
			m_x -= 2;
		break;
	case VK_RIGHT:
		if(m_x <=315)
			m_x += 2;
		break;
	default:
		break;
		
	}
}


void CPlayer::ShotBullet(CBulletManger& BulletManger,HINSTANCE hins)
{
	CBullet* bullet = new CBullet(m_x+27,m_y-9);
	bullet->InitBullet(hins);
	BulletManger.m_bulletlist.push_back(bullet);
}

CPlayer::CPlayer(void)
{

	m_x  = 160;
	m_y =  440;
	hBitmap = NULL;
}


CPlayer::~CPlayer(void)
{

	::DeleteObject(hBitmap);
	hBitmap =NULL;
}
