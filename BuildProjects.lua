solution "gmsv_env"
    language "c++"
    location ( os.target() .."-".. _ACTION )
    symbols "On"
    editandcontinue "Off"
    vectorextensions "SSE"
    flags { "NoPCH", "StaticRuntime" }
    targetdir ( "lib/" .. os.target() .. "/" )
    includedirs { "../include/" }
    
    configurations
    { 
        "Release"
    }
    
    configuration "Release"
        defines { "NDEBUG" }
        optimize "On"
        floatingpoint "Fast"
    
    project "gmsv_env"
        defines { "GMMODULE" }
        files { "src/**.*", "include/**.*" }
        kind "SharedLib"