#include <iostream>
extern "C" {
# include "lua.h"
# include "lauxlib.h"
# include "lualib.h"
}
#include <LuaBridge.h>

void printMessage(const std::string& s) {
    std::cout << s << std::endl;
}

int main() {
    lua_State* L = luaL_newstate();
    luaL_dofile(L, "LuaScripts/testScript.lua");
    luaL_openlibs(L);
    lua_pcall(L, 0, 0, 0);

    luabridge::getGlobalNamespace(L).beginNamespace("game").addFunction("printMessage", printMessage).endNamespace();

    luabridge::LuaRef sumNumbers = luabridge::getGlobal(L, "sumNumbers");
    int result = sumNumbers(5, 4);
    std::cout << "Result:" << result << std::endl;
}
