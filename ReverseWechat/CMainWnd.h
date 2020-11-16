#pragma once
#include "DUILIB_CONFIGURE.h"
#include DUILIB_H_PATH

using namespace DuiLib;
class CMainWnd :
	public WindowImplBase
{
public:
	CMainWnd();
	~CMainWnd();
	virtual LPCTSTR    GetWindowClassName() const { return _T("PunishWindow"); }
	virtual CDuiString GetSkinFile() { return _T("QQ/xmls/main.xml"); }
	virtual void InitWindow();
	virtual LRESULT OnClose(UINT /*uMsg*/, WPARAM /*wParam*/, LPARAM /*lParam*/, BOOL& bHandled);
	virtual void OnClick(TNotifyUI& msg);
	virtual CControlUI* CreateControl(LPCTSTR pstrClass);

};

