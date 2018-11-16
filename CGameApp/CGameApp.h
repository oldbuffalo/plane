#pragma once


#ifndef GAMEAPP_H
#define GAMEAPP_H
#include<windows.h>


#define CREATE(ThisClass)\
CGameApp* Create()\
{				   \
	return new ThisClass;\
}


class CGameApp;
typedef  CGameApp* (*PFUNCREATE)();  //定义函数指针



#define DLEACRE  static CGameApp* Create();
#define IMPLEMENT(ThisClass)	 \
	CGameApp* ThisClass::Create(){ \
		return new 	ThisClass;	   \
	}\
	Init init##ThisClass(&ThisClass::Create);	   





class CGameApp{
protected:
	HINSTANCE m_hins;  //实例句柄
	HWND      m_hwnd;  //抽口句柄
public:
	static 	PFUNCREATE pFunCreate;
public:
	CGameApp(){
		m_hins = NULL;
		m_hwnd = NULL;
	}
	virtual ~CGameApp(){}  //虚析构  
	void SetHandle(HINSTANCE hins,HWND hwnd){
		this->m_hins = hins;
		this->m_hwnd = hwnd;
	}
public:
	virtual void CreateGame(){}		     //WM_CREATE		   初始化一些资源
	virtual void ShowGame(){}			 //WM_PAINT
	virtual void RunGame(WPARAM nTimerId){}             //WM_TIMER
	virtual void OnKeyDownMsg(WPARAM key){}		 //WM_KEYDOWN
	virtual void OnLButtonDownMsg(POINT point){}	 //WM_LBUTTONDOWN
	virtual void OnLButtonUpMsg(POINT point){}	 //WM_LBUTTONUP
	virtual void OnMouseMoveMsg(POINT point){}		 //WM_MOUSEMOVE

};

class Init{
public:
	Init(PFUNCREATE pfun){
		CGameApp::pFunCreate = pfun;
	}
};

#endif