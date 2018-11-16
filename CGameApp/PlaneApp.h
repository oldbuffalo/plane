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
	HDC dc; //����dc
	HDC hMemdc; //������dc
	HBITMAP hBitamp;   //  ����λͼ   �� ����dc ���ݵ�ͼƬ���Ի���ɫ
public:
	CBack back;
	CPlayer player;
	CBulletManger m_bulletManger;
	CEmenyManger  m_emenyManger;
	CBoomEmenyPlane m_boomEmenyPlaneManger;
public:
	DLEACRE
public:
	virtual void CreateGame();		     //WM_CREATE		   ��ʼ��һЩ��Դ
	virtual void ShowGame();			 //WM_PAINT
	virtual void RunGame(WPARAM nTimerId);             //WM_TIMER
	virtual void OnKeyDownMsg(WPARAM key);		 //WM_KEYDOWN
	bool IsGameOver();
public:
	CPlaneApp(void);
	~CPlaneApp(void);
};

