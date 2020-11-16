
#include "CFont.h"


CFont::CFont():m_font(NULL)
{
}


CFont::~CFont()
{
	this->FreeFont(m_font);
}

bool CFont::Load(const wchar_t * file)
{
	int nResult = AddFontResourceEx(file, FR_PRIVATE,NULL);
	if (nResult == 0)
	{
		//::MessageBox(NULL, _T("失败"), _T("提示2"), 0);  //实际使用时建议注释此行代码
		return false;
	}
	if (m_font == NULL) {
		m_font = new LoadedFont();
		wcscpy_s(m_font->path, file);
		m_font->next = NULL;
		return true;
	}
	LoadedFont *last = m_font;
	while (last->next != NULL) {
		last = last->next;
	}
	last->next= new LoadedFont();
	last = last->next;
	wcscpy_s(last->path, file);
	last->next = NULL;
	return true;
}

bool CFont::Load(LPVOID buffer, DWORD length)
{
	DWORD nFonts;
	HANDLE m_hFont = AddFontMemResourceEx(
		buffer,          // font resource
		length,          // number of bytes in font resource 
		NULL,         // Reserved. Must be 0.
		&nFonts);      // number of fonts installed
	//::CloseHandle(m_hFont);
	if (!m_hFont) return false;
	return true;
	//RemoveFontMemResourceEx()
}

bool CFont::Load(int iconfont_id)
{
	HRSRC hFont = ::FindResource(NULL, MAKEINTRESOURCE(iconfont_id), L"ICONFONT");
	if (hFont != NULL) {
		HGLOBAL hFontGlobal = ::LoadResource(NULL, hFont);
		if (hFontGlobal == NULL)
		{
			::FreeResource(hFont);
			//return 0L;
			return false;
		}
		else
		{
			DWORD dwSize = 0;
			dwSize = ::SizeofResource(NULL, hFont);
			if (dwSize != 0) {
				LPVOID buffer = ::LockResource(hFontGlobal);
				this->Load(buffer, dwSize);
				::FreeResource(hFontGlobal);
				return true;
			}
		}
	}
	return false;
}

void CFont::FreeFont(LoadedFont *font)
{
	if (font == NULL) return;
	if (font->next != NULL) {
		this->FreeFont(font->next);
		font->next = NULL;
	}
	else {
		RemoveFontResourceEx(font->path, FR_PRIVATE,NULL);
		delete font;
		font = NULL;
	}
}
