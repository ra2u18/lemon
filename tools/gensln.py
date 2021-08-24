import subprocess, sys

import globals

# Captures the failure of the subprocess calls
ret = 0

if globals.IsWindows():
    ret = subprocess.call(["cmd.exe", "/c", "premake\\premake5", "vs2019"])

if globals.IsLinux():
    ret = subprocess.call(["premake\\premake5.linux", "gmake2"])

if globals.IsMac():
    ret = subprocess.call(["premake\\premake5.darwin", "gmake2"])
    if ret == 0:
        subprocess.call(["premake\\premake5.darwin", "xcode4"])

sys.exit(ret)