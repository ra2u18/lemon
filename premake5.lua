workspace "lemon"
    startproject "lemoneditor"
    architecture "x64"

    configurations
    {
        "Debug",
        "Release"
    }

project "lemoneditor"
    location "lemoneditor"
    kind "ConsoleApp"
    language "C++"
    cppdialect "C++17"

    files
    {
        "%{prj.name}/src/**.h",
        "%{prj.name}/src/**.cpp"
    }

    flags
    {
        "FatalWarnings"
    } 