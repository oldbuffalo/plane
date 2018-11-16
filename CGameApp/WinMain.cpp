#include <windows.h>
#include<time.h>
#include"CGameApp.h"
// HINSTANCE ʵ�����           ����һ���ⲿ����Դ��Ҫ��
// HWND      ������           �ʹ�����صĲ���
// HDC       �����豸���       ��ͼ�Ĳ���

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
	//  1. ���
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
	//  2. ע��
	if( ::RegisterClassEx(&wndclass)==FALSE)
	{
		::MessageBox(0,"ע��ʧ��","��ʾ",MB_OK);
		return 0;
	}
	//  3. ����
	HWND hwnd = ::CreateWindow("ben","�ɻ���ս",WS_OVERLAPPEDWINDOW,500,200,380+16,550+20,0,0,hInstance,0);
	if(hwnd == 0)
	{
		::MessageBox(0,"����ʧ��","��ʾ",MB_OK);
		return 0;		
	}
	//  4. ��ʾ
	::ShowWindow(hwnd,SW_SHOW);
	//  5. ��Ϣѭ��
	MSG msg;
	while(::GetMessage(&msg,0,0,0))
	{
		//  ����
		::TranslateMessage(&msg);
		//  �ַ�
		::DispatchMessage(&msg);
	}


	return 0;
}

//CGameApp* Create();
PFUNCREATE CGameApp::pFunCreate = NULL;

CGameApp* pCtrl = NULL;

//  ��Ϣ�Ĵ�����
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
			::MessageBox(NULL,"������Ϸʧ��","��ʾ",MB_OK);
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