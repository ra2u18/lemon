V_MAJOR = 1
V_MINOR = 0

ENGINE_NAME = "lemon"
PROJECT_NAME = "lemoneditor"

TOOLS_DIR = "tools"

import sys, platform

PLATFORM = sys.platform

for platInfo in platform.uname():
    if "microsoft" in platInfo.lower():
        PLATFORM = "windows"
        break

def IsWindows():
    return PLATFORM == "windows"

def IsLinux():
    return PLATFORM == "linux"

def IsMac():
    return PLATFORM == "darwin"