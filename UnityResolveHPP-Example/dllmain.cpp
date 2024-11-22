// dllmain.cpp : Defines the entry point for the DLL application.
#include <Windows.h>
#include <iostream>
#include "UnityResolve.hpp"
DWORD WINAPI MainThread() {
    UnityResolve::Init(GetModuleHandle((LPCWSTR)L"mono-2.0-bdwgc.dll"), UnityResolve::Mode::Mono);
    UnityResolve::ThreadAttach();
    MessageBoxA(0, "Injected!!!", "UnityResolveHPP-Example", MB_OK | MB_ICONHAND);
    return TRUE;
}

BOOL APIENTRY DllMain( HMODULE hModule,
                       DWORD  ul_reason_for_call,
                       LPVOID lpReserved
                     )
{
    switch (ul_reason_for_call)
    {
    case DLL_PROCESS_ATTACH:
        CreateThread(0, 0, (LPTHREAD_START_ROUTINE)MainThread, 0, 0, 0);
    case DLL_THREAD_ATTACH:
    case DLL_THREAD_DETACH:
    case DLL_PROCESS_DETACH:
        break;
    }
    return TRUE;
}

