#pragma once
#include"sys.h"
#include"Bullet.h"
#include"BulletManger.h"
class CPlayer
{
public:
	int m_x;
	int m_y;
	HANDLE hBitmap;
public:
	void InitPlayer(HINSTANCE hins);
	void ShowPlayer(HDC hMemDC);
	void MovePlayer(int Fx);
	void ShotBullet(CBulletManger& BulletManger,HINSTANCE hins);
public:
	CPlayer(void);
	~CPlayer(void);
};

