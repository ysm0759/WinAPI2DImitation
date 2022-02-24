// header.h: 표준 시스템 포함 파일
// 또는 프로젝트 특정 포함 파일이 들어 있는 포함 파일입니다.


#pragma once // 한번만 선언 하겠다.

#include "targetver.h"
#define WIN32_LEAN_AND_MEAN             // 거의 사용되지 않는 내용을 Windows 헤더에서 제외합니다.

// Windows 헤더 파일
#include <windows.h>

// C 런타임 헤더 파일입니다.
#include <stdlib.h>
#include <malloc.h>
#include <memory.h>
#include <tchar.h>
#include <string>
#include <vector>

using std::vector;
using std::string;
using std::wstring;



// 제작 헤더파일
#include "Define.h"
#include "Singleton.h"
#include "fPoint.h"
#include "Core.h"
#include "GameObject.h"
#include "TimeManager.h"
#include "KeyManager.h"
#include "Player.h"
#include "SceneManager.h"



//전역변수(인스턴스, 윈도우 핸들)


extern HINSTANCE hInst;
extern HWND hWnd;

