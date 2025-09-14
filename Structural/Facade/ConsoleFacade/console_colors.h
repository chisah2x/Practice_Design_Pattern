#pragma once
#ifdef _WIN32
#include "Console.h"
#else defined (__linux__)
#include "linux/Console.h"
#endif
