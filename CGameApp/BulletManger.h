#pragma once
#include"sys.h"
#include"Bullet.h"
#include"EmenyManger.h"
#include"BoomEmenyPlane.h"
class CBulletManger
{
public:
	list<CBullet*> m_bulletlist;
public:
	void AllBulletMove();
	void AllBulletShow(HDC hMemDC);
	void IsHitEmeny(CEmenyManger &EmenyManger,CBoomEmenyPlane &BoomEmenyManger);
public:
	CBulletManger(void);
	~CBulletManger(void);
};

