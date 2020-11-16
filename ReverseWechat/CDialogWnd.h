#pragma once
#include "DUILIB_CONFIGURE.h"
#include DUILIB_H_PATH
using namespace DuiLib;
class CDialogWnd :
	public WindowImplBase
{
public:
	CDialogWnd();
	~CDialogWnd();
	virtual LPCTSTR    GetWindowClassName() const { return _T("SellerWindow"); }
	virtual CDuiString GetSkinFile() { return _T("QQ/xmls/seller.xml"); }
	virtual CControlUI* CreateControl(LPCTSTR pstrClass);
	virtual LRESULT MessageHandler(UINT uMsg, WPARAM wParam, LPARAM /*lParam*/, bool& /*bHandled*/);

	virtual void OnClick(TNotifyUI& msg);


};

