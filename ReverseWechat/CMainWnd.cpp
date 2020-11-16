#include "resource.h"
#include "CMainWnd.h"
#include "CDialogWnd.h"
CMainWnd::CMainWnd()
{

}


CMainWnd::~CMainWnd()
{

}

void CMainWnd::InitWindow()
{



	wchar_t title[256] = L"DUILIB DEMO";

	m_pm.FindControl(L"Lbl_Main_Title")->SetText(title);

}

LRESULT CMainWnd::OnClose(UINT, WPARAM, LPARAM, BOOL & bHandled)
{
	::PostQuitMessage(0);
	return S_OK;
}

void CMainWnd::OnClick(TNotifyUI & msg)
{
	if (msg.pSender->GetName() == L"loginbtn") {
		CDialogWnd dialoger;
		dialoger.Create(m_hWnd, TEXT("DUILIB DeMO µÇÂ¼ÌÔ±¦"), UI_WNDSTYLE_FRAME& ~WS_MAXIMIZEBOX & ~WS_MINIMIZEBOX, UI_WNDSTYLE_EX_FRAME | WS_EX_APPWINDOW /*| WS_EX_TOPMOST| WS_EX_APPWINDOW*/);
		dialoger.CenterWindow();
		dialoger.SetIcon(IDI_SMALL);
		dialoger.ShowModal();
		//if (dialoger.ShowModal() == S_FALSE) return;
		
	}
	__super::OnClick(msg);
}

CControlUI * CMainWnd::CreateControl(LPCTSTR pstrClass)
{
	if (_tcscmp(pstrClass, _T("Miniblink")) == 0)
	{
		/*DuiLib::CMiniblink *web = new DuiLib::CMiniblink();
		return web;*/
	}
	return NULL;
}


