#pragma once
#define DUILIB_H_PATH "../third/includes/duilib/UIlib.h"
#if _DEBUG
#pragma comment(lib,"../third/libs/duilib/DuiLib_d.lib")
	#define DUILIB_L_PATH "../third/libs/duilib/DuiLib_d.lib"
#else
	#define DUILIB_L_PATH "../third/libs/duilib/DuiLib.lib"
#endif