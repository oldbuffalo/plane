#pragma once
#include "CGameApp.h"
#include"Back.h"
#include"Player.h"
#include"EmenyPlane.h"
#include"BulletManger.h"
#include"EmenyManger.h"
#include"BoomEmenyPlane.h"
#include"sys.h"


class CPlaneApp :
	public CGameApp
{
public:
	HDC dc; //窗口dc
	HDC hMemdc; //兼容性dc
	HBITMAP hBitamp;   //  创建位图   和 窗口dc 兼容的图片可以画颜色
public:
	CBack back;
	CPlayer player;
	CBulletManger m_bulletManger;
	CEmenyManger  m_emenyManger;
	CBoomEmenyPlane m_boomEmenyPlaneManger;
public:
	DLEACRE
public:
	virtual void CreateGame();		     //WM_CREATE		   初始化一些资源
	virtual void ShowGame();			 //WM_PAINT
	virtual void RunGame(WPARAM nTimerId);             //WM_TIMER
	virtual void OnKeyDownMsg(WPARAM key);		 //WM_KEYDOWN
	bool IsGameOver();
public:
	CPlaneApp(void);
	~CPlaneApp(void);
};

