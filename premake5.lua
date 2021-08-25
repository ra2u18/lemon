workspace "lemon"
    startproject "lemoneditor"
    architecture "x64"

    configurations
    {
        "Debug",
        "Release"
    }

-- Bin / Bin-obj directory paths defined as global variables
tdir = "bin/%{cfg.buildcfg}/%{prj.name}"
odir = "bin-obj/%{cfg.buildcfg}/%{prj.name}"

-- Define all external dependencies
externals = {}
externals["sdl2"] = "external/sdl2"
externals["maclibs"] = "external/maclibs"
externals["spdlog"] = "external/spdlog"
externals["glad"] = "external/glad"

-- Process Glad before anything else
include "external/glad" -- find any premake5.lua that reside in this path

project "lemon"
    location "lemon"
    kind "StaticLib"
    language "C++"
    cppdialect "C++17"
    staticruntime "on"

    targetdir(tdir)
    objdir(odir)

    files
    {
        "%{prj.name}/include/**.h",
        "%{prj.name}/src/**.h",
        "%{prj.name}/src/**.cpp"
    }

    sysincludedirs 
    { 
        "%{prj.name}/include/lemon",
        "%{externals.sdl2}/include",
        "%{externals.spdlog}/include",
        "%{externals.glad}/include"
    }

    flags { "FatalWarnings" } 

    -- [PLATFORM DEFINES]
    -- All platform defines
    defines
    {
        "GLFW_INCLUDE_NONE" -- Ensures glad doesn't include glfw
    }

    -- Windows
    filter {"system:windows", "configurations:*"}
        systemversion "latest" -- target latest windows upgrade when "cli gensln"
        defines{ "LEMON_PLATFORM_WINDOWS" }
    
    -- Linux
    filter {"system:linux", "configurations:*"}
        defines{ "LEMON_PLATFORM_LINUX" }
    
    -- Darwin - MacOs
    filter {"system:macosx", "configurations:*"}
        -- specific to xcode
        xcodebuildsettings
        {
            ["MACOSX_DEPLOYMENT_TARGET"] = "10.15", -- not the latest sys, to include more people
            ["UseModernBuildSystem"] = "NO"
        }    
    
        defines{ "LEMON_PLATFORM_MAC" }
    
    -- [CONFIGURATION DEFINES]: usually used to turn on optimization
    filter "configurations:Debug"
        defines "LEMON_CONFIG_DEBUG"
        runtime "Debug"
        symbols "on" -- pdb symbols / for release we don't want them

    filter "configurations:Release"
        defines "LEMON_CONFIG_RELEASE"
        runtime "Release"
        symbols "off"
        optimize "on"

-- The sandbox editor, external to any engine functionality
project "lemoneditor"
    location "lemoneditor"
    kind "ConsoleApp"
    language "C++"
    cppdialect "C++17"
    staticruntime "on"
    links "lemon"

    targetdir(tdir)
    objdir(odir)

    files
    {
        "%{prj.name}/src/**.h",
        "%{prj.name}/src/**.cpp"
    }

    sysincludedirs { "lemon/include" }

    flags { "FatalWarnings" } 

    -- COPIED FROM ABOVE [PLATFORM DEFINES]
    -- Windows
    filter {"system:windows", "configurations:*"}
        systemversion "latest" -- target latest windows upgrade when "cli gensln"
        defines{ "LEMON_PLATFORM_WINDOWS" }
        
        libdirs
        {
            "%{externals.sdl2}/lib"
        }

        links
        {
            "SDL2",
            "glad" -- will be available because we process glad first
        }
    
    -- Linux
    filter {"system:linux", "configurations:*"}
        defines{ "LEMON_PLATFORM_LINUX" }

        links
        {
            "SDL2",
            "glad"
        }
    
    -- Darwin - MacOs
    filter {"system:macosx", "configurations:*"}
        -- specific to xcode
        xcodebuildsettings
        {
            ["MACOSX_DEPLOYMENT_TARGET"] = "10.15", -- not the latest sys, to include more people
            ["UseModernBuildSystem"] = "NO"
        }

        abspath = path.getabsolute("%{externals.maclibs}")
        linkoptions {"-F " .. abspath}

        links 
        {
            "SDL2.framework",
            "glad"
        }

        defines{ "LEMON_PLATFORM_MAC" }
    
    -- [CONFIGURATION DEFINES]: usually used to turn on optimization
    filter "configurations:Debug"
        defines "LEMON_CONFIG_DEBUG"
        runtime "Debug"
        symbols "on" -- pdb symbols / for release we don't want them

    filter "configurations:Release"
        defines "LEMON_CONFIG_RELEASE"
        runtime "Release"
        symbols "off"
        optimize "on"