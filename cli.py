# The script that interacts with everything in the tools directory

import os, sys
import subprocess # run external commands

TOOLS_DIR = "tools"

def RunCommand(cmd):
    subprocess.call(["python3", "{}/{}/{}.py".format(os.getcwd(), TOOLS_DIR, cmd)])

for i in range(1, len(sys.argv)):
    cmd = sys.argv[i]

    print("\n----------------------")
    print("Executing command: ", cmd)

    RunCommand(cmd)