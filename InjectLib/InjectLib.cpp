#include <Windows.h>
#include "../BlackBone/src/BlackBone/Process/Process.h"

#pragma comment(lib, "BlackBone.x86.lib")

using namespace blackbone;

extern "C" __declspec(dllexport) void __cdecl Inject(char* buf)
{
	Process process;

	process.Attach(L"csgo.exe");

	auto size = sizeof(buf) / sizeof(buf[0]);

	process.mmap().MapImage(size, buf, false, WipeHeader);

	process.Detach();
}