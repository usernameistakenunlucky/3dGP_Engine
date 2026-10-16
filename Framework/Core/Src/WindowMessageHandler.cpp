#include "Precompiled.h"
// ^^ put this at top of ALL cpp files

#include "WindowMessageHandler.h"
#include "DebugUtil.h"

using namespace ChungusEngine;
using namespace ChungusEngine::Core;

void WindowMessageHandler::Hook(HWND window, Callback cb)
{
	mWindow = window;
	mPreviousCallback = (Callback)GetWindowLongPtrA(window, GWLP_WNDPROC);
	SetWindowLongA(window, GWLP_WNDPROC, (LONG_PTR)cb);
}

void WindowMessageHandler::Unhook()
{
	SetWindowLongPtrA(mWindow, GWLP_WNDPROC, (LONG_PTR)mPreviousCallback);
	mWindow = nullptr;
}

LRESULT WindowMessageHandler::ForwardMessage(HWND window, UINT msg, WPARAM wParam, LPARAM lParam)
{
	ASSERT(mPreviousCallback != nullptr, "WindowMessageHandler: no callback is hooked!");
	return CallWindowProcA((WNDPROC)mPreviousCallback, window, msg, wParam, lParam);
}