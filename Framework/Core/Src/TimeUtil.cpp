#include "Precompiled.h"
// ^^ put this at top of ALL cpp files

#include "TimeUtil.h"

using namespace ChungusEngine;
using namespace ChungusEngine::Core;

float TimeUtil::GetTime()
{
	static const auto startTime = std::chrono::high_resolution_clock::now();
	const auto currentTime = std::chrono::high_resolution_clock::now();
	const auto milliseconds = std::chrono::duration_cast<std::chrono::milliseconds>(currentTime - startTime).count();
	return milliseconds / 1000.f;
}

float TimeUtil::GetDeltaTime()
{
	static auto lastCallTime = std::chrono::high_resolution_clock::now();
	const auto currentTime = std::chrono::high_resolution_clock::now();
	const auto milliseconds = std::chrono::duration_cast<std::chrono::milliseconds>(currentTime - currentTime).count();
	lastCallTime = currentTime;
	return milliseconds / 1000.f;
}