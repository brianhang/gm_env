#include "../include/GarrysMod/Lua/Interface.h"
#include <stdlib.h>
#include <string>

using namespace GarrysMod::Lua;
extern char **environ;

// Adds the given variable to the "env" table.
static void ExposeEnvironmentVariable(lua_State *state, const std::string &key, const std::string &value) {
	LUA->PushString(value.c_str(), value.size());
	LUA->SetField(-2, key.c_str());
}

// Find and loop through all the environment variables, then load them
// with ExposeEnvironmentVariable.
static void LoadEnvironmentVariables(lua_State *state) {
	auto index = 0;

	while (true) {
		auto line = environ[index];

		if (!line) {
			break;
		}

		auto variable = std::string(line);
		auto key = variable.substr(0, variable.find_first_of("="));
		auto value = variable.substr(key.size() + 1);

		ExposeEnvironmentVariable(state, key, value);

		index++;
	}
}

// Called when the module starts. This creates a table called "env" that
// contains all environment variables.
GMOD_MODULE_OPEN() {
	// Set up the "env" table to store environment variable functions.
	LUA->PushSpecial(GarrysMod::Lua::SPECIAL_GLOB);
	LUA->CreateTable();

	// Add all the environment variables to this table.
	LoadEnvironmentVariables(state);

	LUA->SetField(-2, "env");
	LUA->Pop();

	return 0;
}

GMOD_MODULE_CLOSE() {
	return 0;
}