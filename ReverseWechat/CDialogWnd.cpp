#include "CDialogWnd.h"

CDialogWnd::CDialogWnd()
{
}


CDialogWnd::~CDialogWnd()
{

}

CControlUI * CDialogWnd::CreateControl(LPCTSTR pstrClass)
{

	return NULL;
}

LRESULT CDialogWnd::MessageHandler(UINT uMsg, WPARAM wParam, LPARAM lParam, bool &bHandled)
{
	if (uMsg == WM_KEYDOWN && wParam == VK_TAB)
	{
		CControlUI *m_pFocus = m_pm.GetFocus();
		if (m_pFocus && m_pFocus->IsVisible() && m_pFocus->IsEnabled() && (_tcsstr(m_pFocus->GetClass(), _T("TBWeb")) != NULL || _tcsstr(m_pFocus->GetClass(), _T("Miniblink")) != NULL)) {
			TEventUI event = { 0 };
			event.Type = UIEVENT_KEYDOWN;
			event.pSender = m_pFocus;
			event.wParam = wParam;
			event.lParam = lParam;
			event.chKey = (TCHAR)wParam;
			event.ptMouse = m_pm.GetMousePos();
			event.wKeyState = 0;
			event.dwTimestamp = ::GetTickCount();
			m_pFocus->Event(event);
			bHandled = true;
			return S_OK;
		}
	}

	return __super::MessageHandler(uMsg, wParam, lParam, bHandled);
}

void CDialogWnd::OnClick(TNotifyUI & msg)
{
	if (msg.pSender->GetName() == L"closebtn") {
		this->Close(S_FALSE);
		return;
	}
	__super::OnClick(msg);
}

