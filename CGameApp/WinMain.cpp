#include <windows.h>
#include<time.h>
#include"CGameApp.h"
// HINSTANCE 实例句柄           加载一个外部的资源需要用
// HWND      代表窗口           和窗口相关的操作
// HDC       环境设备句柄       绘图的操作

// Window Message
// WM_LBUTTONDOWN
// WM_KEYDOWN
// WM_PAINT
// WM_TIMER
// ........

LRESULT CALLBACK WndProc(HWND hwnd,UINT uMsg,WPARAM wParam,LPARAM lParam);
HINSTANCE g_hIns;

int CALLBACK WinMain(HINSTANCE hInstance,HINSTANCE hPreInstance,LPSTR pCmdLine,int nCmdShow)
{
	g_hIns = hInstance;
	srand((unsigned int)time(NULL));
	//  1. 设计
	WNDCLASSEX wndclass;
	wndclass.cbClsExtra = 0;
	wndclass.cbWndExtra = 0;
	wndclass.cbSize = sizeof(WNDCLASSEX);
	wndclass.hbrBackground = (HBRUSH)(COLOR_WINDOW+1);
	wndclass.hCursor = ::LoadCursor(0,MAKEINTRESOURCE(IDC_ARROW));
	wndclass.hIcon = 0;
	wndclass.hIconSm = 0;
	wndclass.hInstance = hInstance;
	wndclass.lpfnWndProc = WndProc;
	wndclass.lpszClassName = "ben";
	wndclass.lpszMenuName = 0;
	wndclass.style = CS_VREDRAW|CS_HREDRAW;
	//  2. 注册
	if( ::RegisterClassEx(&wndclass)==FALSE)
	{
		::MessageBox(0,"注册失败","提示",MB_OK);
		return 0;
	}
	//  3. 创建
	HWND hwnd = ::CreateWindow("ben","飞机大战",WS_OVERLAPPEDWINDOW,500,200,380+16,550+20,0,0,hInstance,0);
	if(hwnd == 0)
	{
		::MessageBox(0,"创建失败","提示",MB_OK);
		return 0;		
	}
	//  4. 显示
	::ShowWindow(hwnd,SW_SHOW);
	//  5. 消息循环
	MSG msg;
	while(::GetMessage(&msg,0,0,0))
	{
		//  翻译
		::TranslateMessage(&msg);
		//  分发
		::DispatchMessage(&msg);
	}


	return 0;
}

//CGameApp* Create();
PFUNCREATE CGameApp::pFunCreate = NULL;

CGameApp* pCtrl = NULL;

//  消息的处理函数
LRESULT CALLBACK WndProc(HWND hwnd,UINT uMsg,WPARAM wParam,LPARAM lParam)
{
	switch (uMsg)
	{
	case WM_CREATE:
		//pCtrl = Create();
		pCtrl = CGameApp::pFunCreate();
		if(pCtrl != NULL){
			pCtrl->SetHandle(g_hIns,hwnd);
			pCtrl->CreateGame();
		}
		else
		{
			::MessageBox(NULL,"创建游戏失败","提示",MB_OK);
		}
		break;
	case  WM_PAINT:
		pCtrl->ShowGame();
		break;
	case WM_TIMER:
		pCtrl->RunGame(wParam);
		break;
	case WM_KEYDOWN:
		pCtrl->OnKeyDownMsg(wParam);
		break;
	case WM_LBUTTONDOWN:
		{
			POINT point;
			point.x = LOBYTE(lParam);
			point.y = HIBYTE(lParam);
			pCtrl->OnLButtonDownMsg(point);
		}
		break;
	case WM_LBUTTONUP:
		{
			POINT point;
			point.x = LOBYTE(lParam);
			point.y = HIBYTE(lParam);
			pCtrl->OnLButtonUpMsg(point);
		}
		break;
	case WM_MOUSEMOVE:
		{
			POINT point;
			point.x = LOBYTE(lParam);
			point.y = HIBYTE(lParam);
			pCtrl->OnMouseMoveMsg(point);
		}
		break;
	case WM_CLOSE:
		delete pCtrl;
		::PostQuitMessage(0);
		break;
	}
	return ::DefWindowProc( hwnd, uMsg, wParam, lParam);
}