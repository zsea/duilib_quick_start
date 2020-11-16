// ReverseWechat.cpp : 定义应用程序的入口点。
//

#include "framework.h"
#include "ReverseWechat.h"
#include "DUILIB_CONFIGURE.h"
#include DUILIB_H_PATH
#pragma comment(lib,DUILIB_L_PATH)
#include "CMainWnd.h"
#include "CFont.h"
using namespace DuiLib;

int APIENTRY wWinMain(_In_ HINSTANCE hInstance,
	_In_opt_ HINSTANCE hPrevInstance,
	_In_ LPWSTR    lpCmdLine,
	_In_ int       nCmdShow)
{
	UNREFERENCED_PARAMETER(hPrevInstance);
	UNREFERENCED_PARAMETER(lpCmdLine);
	//加载自定义字体
	CFont fonter;
	fonter.Load(IDR_ICONFONT);

	CPaintManagerUI::SetInstance(hInstance);
#ifdef _DEBUG
	CPaintManagerUI::SetResourcePath(CPaintManagerUI::GetResourcePath() + L"skin");
#else
	//::SetUnhandledExceptionFilter(ExceptionFilter);
	//DisableSetUnhandledExceptionFilter();
	CPaintManagerUI::SetCurrentPath(CPaintManagerUI::GetInstancePath());
	CPaintManagerUI::SetResourceZip(_T("skin.zip"));
	CPaintManagerUI::ReloadSkin();
	//thread(Safer).detach();

	//从资源中加载zip
	HRSRC hResource = ::FindResource(CPaintManagerUI::GetResourceDll(), MAKEINTRESOURCE(IDR_SKIN), _T("ZIPRES"));
	if (hResource == NULL)
		return 0L;
	DWORD dwSize = 0;
	HGLOBAL hGlobal = ::LoadResource(CPaintManagerUI::GetResourceDll(), hResource);
	if (hGlobal == NULL)
	{
		::FreeResource(hResource);
		return 0L;
	}
	dwSize = ::SizeofResource(CPaintManagerUI::GetResourceDll(), hResource);
	if (dwSize == 0)
		return 0L;
	LPBYTE g_lpResourceZIPBuffer = new BYTE[dwSize];
	if (g_lpResourceZIPBuffer != NULL)
	{
		::CopyMemory(g_lpResourceZIPBuffer, (LPBYTE)::LockResource(hGlobal), dwSize);
	}
	::FreeResource(hResource);
	CPaintManagerUI::SetResourceZip(g_lpResourceZIPBuffer, dwSize);
#endif // _DEBUG
	//CPaintManagerUI::SetResourceZip();
	CMainWnd main;
	main.Create(NULL, L"DUILIB DEMO", UI_WNDSTYLE_FRAME, WS_EX_WINDOWEDGE);
	//ShowWindow(main.GetHWND(), SW_MAXIMIZE);
	main.CenterWindow();
	main.SetIcon(IDI_SMALL);
	//::ShowWindow(main.GetHWND(), SW_MAXIMIZE);
	//ABWriteLoginfo(LOG_TYPE::LOG_TYPE_STARTUP, true, NULL, L"启动成功。");
	CPaintManagerUI::MessageLoop();
	return 0;
}
