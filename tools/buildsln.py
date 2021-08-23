# Local imports
import globals

import os, subprocess

CONFIG = "debug"

# vs_build_path: environ variable in ~/.bash_env
if globals.IsWindows():
    # Splice the string to exclude quotations and the /mnt/c text 
    # Replace forward slashes with back slashes (for windows)
    VS_BUILD_PATH = os.environ["VS_BUILD_PATH"][8:-1].replace("/", "\\\\")
    VS_BUILD_PATH = "C:\\\\" + VS_BUILD_PATH

    subprocess.call(["cmd.exe", "/c", VS_BUILD_PATH, "{}.sln".format(globals.ENGINE_NAME), "/property:Configuration={}".format(CONFIG)])