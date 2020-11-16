#pragma once
#include <windows.h>
struct LoadedFont
{
	wchar_t path[MAX_PATH];
	LoadedFont* next;
};
class CFont
{
public:
	CFont();
	~CFont();
	bool Load(const wchar_t *file);
	bool Load(LPVOID buffer, DWORD length);
	bool Load(int iconfont_id);
private:
	LoadedFont *m_font;
	void FreeFont(LoadedFont *font);
};

