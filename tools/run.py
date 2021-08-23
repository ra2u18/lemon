import globals
import os, subprocess

config = "Debug"
exepath = "{}/bin/{}/{}/".format(os.getcwd(), config, globals.PROJECT_NAME) 

if globals.IsWindows():
    # Run the .exe build from the directory bin/%{cfg}/%{prj.name}
    subprocess.call(["cmd.exe", "/c", "{}\\run.bat".format(globals.TOOLS_DIR),
            config, globals.PROJECT_NAME], cwd=os.getcwd())
    