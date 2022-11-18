#include <map>
#include "dostring_cache.h"

namespace DoStringCache
{

std::map<std::string, int> refList;
std::string tableName;

void init(lua_State *L, const std::string &tabname)
{
	int top = lua_gettop(L);
	tableName = tabname;
	lua_pushlstring(L, tabname.c_str(), tabname.length());
	lua_newtable(L);
	lua_pushstring(L, "imgui");
	lua_pushvalue(L, top - 1);
	lua_rawset(L, -3);
	lua_pushstring(L, "love");
	lua_pushvalue(L, top);
	lua_rawset(L, -3);
	lua_rawset(L, LUA_REGISTRYINDEX);
}

int doString(lua_State *L, const std::string &str)
{
	int r;

	// get table in registry
	lua_pushlstring(L, tableName.c_str(), tableName.length());
	lua_rawget(L, LUA_REGISTRYINDEX); // +1
	lua_pushlstring(L, str.c_str(), str.length());
	lua_rawget(L, -2); // +1

	if (lua_isnil(L, -1))
	{
		// Load new string
		static std::string prepend = "local imgui, love = ... ";
		std::string luastr = prepend + str;
		lua_pop(L, 1); // remove nil -1

		if ((r = luaL_loadbuffer(L, luastr.c_str(), luastr.length(), luastr.c_str()))) // +1
		{
			// leave error message in stack
			lua_remove(L, -2); // -1
			return r;
		}

		lua_pushlstring(L, str.c_str(), str.length()); // +1
		lua_pushvalue(L, -2); // +1
		lua_rawset(L, -4); // -2
	}

	// function is in -1
	lua_pushstring(L, "imgui");
	lua_rawget(L, -3); // +1
	lua_pushstring(L, "love");
	lua_rawget(L, -4); // +1
	lua_remove(L, -4);
	r = lua_pcall(L, 2, LUA_MULTRET, 0);
	return r;
}

void getImgui(lua_State *L)
{
	lua_pushlstring(L, tableName.c_str(), tableName.length());
	lua_rawget(L, LUA_REGISTRYINDEX);
	lua_pushstring(L, "imgui");
	lua_rawget(L, -2);
	lua_remove(L, -2);
}

void getLOVE(lua_State *L)
{
	lua_pushlstring(L, tableName.c_str(), tableName.length());
	lua_rawget(L, LUA_REGISTRYINDEX);
	lua_pushstring(L, "love");
	lua_rawget(L, -2);
	lua_remove(L, -2);
}

}
