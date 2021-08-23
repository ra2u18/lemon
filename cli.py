# The script that interacts with everything in the tools directory

import os, sys
import subprocess # run external commands

TOOLS_DIR = "tools"

def RunCommand(cmd):
    script = "{}/{}/{}.py".format(os.getcwd(), TOOLS_DIR, cmd)

    # Check for script's existance
    if os.path.exists(script):
        print("Executing command:", cmd)
        subprocess.call(["python3", script])
    else:
        print("Invalid command:", cmd)

for i in range(1, len(sys.argv)):
    cmd = sys.argv[i]
    print("\n----------------------")
    RunCommand(cmd)