V_MAJOR = 1
V_MINOR = 0

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