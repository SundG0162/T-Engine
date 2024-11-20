#pragma once

#pragma comment(lib, "T-Engine.lib")

#include<Windows.h>
#include<tchar.h>
#include<memory>
#include<vector>
#include<random>
#include<list>
#include<map>
#include<unordered_map>
#include<set>
#include<unordered_set>
#include<string>
#include<algorithm>
#include<ctime>
#include<format>
#include<fstream>
#include<filesystem>
#include<functional>
namespace fs = std::filesystem;

using std::vector;
using std::list;
using std::map;
using std::wstring;

#pragma comment(lib, "winmm.lib")
#pragma comment(lib, "msimg32.lib")

#define PI 3.14159265f
#define SCREEN_WIDTH  800
#define SCREEN_HEIGHT 600
#define GRAVITY 9.8f

#define SAFE_DELETE(inst) if(inst != nullptr) delete inst; inst = nullptr


#define _CRTDEBG_MAP_ALLOC

#include<crtdbg.h>
#ifdef _DEBUG
#define new new(_NORMAL_BLOCK, __FILE__, __LINE__)
#endif
#include <functional>
