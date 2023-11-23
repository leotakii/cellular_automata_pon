#ifndef G_INCLUDES
#define G_INCLUDES

#define LIBNOP_DISABLE_PARALLEL

#include <libnop/framework.h>

#include <iostream>
#include <vector>
#include <chrono>

#define NOW() std::chrono::system_clock::now();
#define TO_MS(time) std::chrono::duration_cast<std::chrono::milliseconds>(time).count();

#endif