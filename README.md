# gm_env
A small binary module for Garry's Mod that creates a table called `env` which contains all environment variables. The keys of `env` are the names of the environment variables and the values of `env` are the corresponding environment variable values.

# Requirements
* premake5
* Visual Studio 2017 (if building on Windows)

# Usage
Require the module using:
```lua
require("env")
```
Then, you can use the `env` table. For example, you can print all environment variables using
```lua
PrintTable(env)
```

# Building
Run `BuildProjects.sh` to generate the project files, then build them.