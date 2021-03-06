
#include "printFreeHeap.h"

#include "../../../lua/lua.h"
#include "../../../lua/lauxlib.h"
#include "../../../lua/lualib.h"
#include "../../../lua/helper/luaHeap.h"
#include "../../../lua/luaconf.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void printFreeHeap(char* message)
{
  char buffer[16];

#ifdef DONT_USE_LUA_HEAP_MANAGEMENT_FUNCTIONS
  //Use the FreeRTOS function.
  size_t size = 0;
#else
  size_t size = LuaGetFreeHeapSize();
#endif

  snprintf(buffer, 16, "%i", size);
  lua_writestringWithoutsize(message);
  lua_writestringWithoutsize(buffer);
  lua_writeline();
}

void printMinimumFreeHeap()
{
  char buffer[16];

#ifdef DONT_USE_LUA_HEAP_MANAGEMENT_FUNCTIONS
  //Use the FreeRTOS function.
  size_t size = 0;
#else
  size_t size = LuaGetMinimumEverFreeHeapSize();
#endif

  snprintf(buffer, 16, "%i", size);
  lua_writestringWithoutsize("minimum free heap: ");
  lua_writestringWithoutsize(buffer);
  lua_writeline();
}
