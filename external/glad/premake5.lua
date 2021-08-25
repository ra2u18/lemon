project "glad"
    kind "StaticLib"
    language "C"
    staticruntime "on"

    targetdir(tdir)
    objdir(odir)

    files
    {
        "include/**.h",
        "src/**.c",
    }

    sysincludedirs 
    { 
        "include",
    }

    -- [PLATFORM DEFINES]
    -- Windows
    filter {"system:windows"}
        systemversion "latest" -- target latest windows upgrade when "cli gensln"

    -- Darwin - MacOs
    filter {"system:macosx"}
        -- specific to xcode
        xcodebuildsettings
        {
            ["MACOSX_DEPLOYMENT_TARGET"] = "10.15", -- not the latest sys, to include more people
            ["UseModernBuildSystem"] = "NO"
        }    

    -- [CONFIGURATION DEFINES]: usually used to turn on optimization
    filter "configurations:Debug"
        runtime "Debug"
        symbols "on" -- pdb symbols / for release we don't want them

    filter "configurations:Release"
        runtime "Release"
        symbols "off"
        optimize "on"