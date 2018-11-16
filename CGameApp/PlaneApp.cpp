#include "PlaneApp.h"
#include"SmallPlane.h"
#include"MiddlePlane.h"
#include"BigPlane.h"

IMPLEMENT(CPlaneApp)




void CPlaneApp::CreateGame()
{

	dc = ::GetDC(m_hwnd);
	hMemdc = ::CreateCompatibleDC(dc);
	hBitamp = ::CreateCompatibleBitmap(dc,380,550);
	::SelectObject(hMemdc,hBitamp);

	//加载资源
	back.InitBack(m_hins);
	player.InitPlayer(m_hins);


	//开启定时器
	::SetTimer(m_hwnd,BACK_MOVE_TIMER,100,NULL);
	::SetTimer(m_hwnd,KEY_STATE_TIMER,1,NULL);
	::SetTimer(m_hwnd,SEND_BULLET_TIMER,300,NULL);
	::SetTimer(m_hwnd,BULLET_MOVE_TIMER,20,NULL);
	::SetTimer(m_hwnd,EMENY_PLANE_CREATE_TIMER,1500,NULL);
	::SetTimer(m_hwnd,EMENY_PLANE_MOVE_TIMER,100,NULL);
	::SetTimer(m_hwnd,CHANGE_SHOWID_TIMER,200,NULL);
}

void CPlaneApp::ShowGame()
{
	back.ShowBack(hMemdc);
	player.ShowPlayer(hMemdc);
	m_bulletManger.AllBulletShow(hMemdc);
	m_emenyManger.ALLSurviveEmenyShow(hMemdc);
	m_boomEmenyPlaneManger.ShowAlBoomPlane(hMemdc);
	::BitBlt(dc,0,0,380,550,hMemdc,0,0,SRCCOPY);
}
void CPlaneApp::RunGame(WPARAM nTimerId)
{
	switch (nTimerId)
	{
	case  BACK_MOVE_TIMER:	   //背景移动
		back.MoveBack();
		break;
	case KEY_STATE_TIMER:	 //玩家飞机移动
		if(::GetAsyncKeyState(VK_DOWN))
			player.MovePlayer(VK_DOWN);
		if(::GetAsyncKeyState(VK_UP))
			player.MovePlayer(VK_UP);
		if(::GetAsyncKeyState(VK_LEFT))
			player.MovePlayer(VK_LEFT);
		if(::GetAsyncKeyState(VK_RIGHT))
			player.MovePlayer(VK_RIGHT);
		break;
	case SEND_BULLET_TIMER:  //玩家发射炮弹
		player.ShotBullet(m_bulletManger,m_hins);
		break;
	case BULLET_MOVE_TIMER:
		m_bulletManger.AllBulletMove();
		m_bulletManger.IsHitEmeny(m_emenyManger,m_boomEmenyPlaneManger);
		break;
	case EMENY_PLANE_CREATE_TIMER:
		{
		int x = rand()%15;
		CEmenyPlane* pEmenyPlane = NULL;
		if(x >=0 &&x<=7)
			pEmenyPlane = new CSmallPlane;	
		else if(x>=8 && x<=12)
			pEmenyPlane = new CMiddlePlane;
		else
			pEmenyPlane = new CBigPlane;
		pEmenyPlane->InitEmenyPlane(m_hins);
		m_emenyManger.m_emerylist.push_back(pEmenyPlane);
		break;
		}
	case EMENY_PLANE_MOVE_TIMER:
		m_emenyManger.ALLSurviveEmenyMove();
		if(IsGameOver())
		{
			//杀死定时器
			::KillTimer(m_hwnd,BACK_MOVE_TIMER);
			::KillTimer(m_hwnd,KEY_STATE_TIMER);
			::KillTimer(m_hwnd,SEND_BULLET_TIMER);
			::KillTimer(m_hwnd,BULLET_MOVE_TIMER);
			::KillTimer(m_hwnd,EMENY_PLANE_CREATE_TIMER);
			::KillTimer(m_hwnd,EMENY_PLANE_MOVE_TIMER);
			::KillTimer(m_hwnd,CHANGE_SHOWID_TIMER);
			::MessageBox(NULL,"辣鸡","辣鸡人",MB_OK);
			return;
		}
		break;

	case CHANGE_SHOWID_TIMER:
		m_boomEmenyPlaneManger.ChangeShowId();
		break;
	default:
		break;
	}

	this->ShowGame();
}
void CPlaneApp::OnKeyDownMsg(WPARAM key)
{

	//this->ShowGame();
}

bool CPlaneApp::IsGameOver()
{
	auto ite =	m_emenyManger.m_emerylist.begin();

	while(ite != m_emenyManger.m_emerylist.end())
	{
		//玩家飞机上选三个点
		//x+30 y
		if(player.m_x+30>=(*ite)->m_x && player.m_x+30 <= (*ite)->m_x+(*ite)->width
			&& player.m_y>=(*ite)->m_y && player.m_y <= (*ite)->m_y+(*ite)->length)
			return true;

		//  x,y+50
		if(player.m_x>= (*ite)->m_x  && player.m_x<= (*ite)->m_x+(*ite)->width
			&& player.m_y+50 >= (*ite)->m_y && player.m_y+50 <= (*ite)->m_y+(*ite)->length)
			return true;
		//  x+60,y+50
		if(player.m_x+60 >= (*ite)->m_x && player.m_x+60 <= (*ite)->m_x+(*ite)->width
			&& player.m_y+50 >= (*ite)->m_y && player.m_y+50 <= (*ite)->m_y+(*ite)->length)
			return true;
		ite++;
	}
	return false;
}


CPlaneApp::CPlaneApp(void)
{	
	dc =  NULL;
	hMemdc = NULL;
	hBitamp = NULL;
}


CPlaneApp::~CPlaneApp(void)
{

	::DeleteObject(hBitamp);
	::DeleteDC(hMemdc);
	::ReleaseDC(m_hwnd,dc);
}
