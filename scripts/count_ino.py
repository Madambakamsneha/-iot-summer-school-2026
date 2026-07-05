#!/usr/bin/env python3
"""
---------------------------------------------------------
 Project : IoT Summer School 2026
 File    : count_ino.py
---------------------------------------------------------
 Description:
     Recursively searches the repository for all Arduino
     sketch files (*.ino) and prints the total count.
     Used by the GitHub Actions CI workflow (lint.yml) to
     sanity-check that Arduino sketches are present and
     trackable on every push.

 Usage:
     python scripts/count_ino.py
---------------------------------------------------------
"""

import os
import sys

# Directories that should never be scanned (build artifacts, VCS internals, etc.)
EXCLUDED_DIRS = {".git", "build", ".vscode", "__pycache__", ".pio"}


def find_ino_files(root_dir="."):
    """
    Walk the directory tree starting at root_dir and return
    a list of relative paths to every .ino file found.
    """
    ino_files = []

    for current_dir, dirnames, filenames in os.walk(root_dir):
        # Prune excluded directories in-place so os.walk skips them
        dirnames[:] = [d for d in dirnames if d not in EXCLUDED_DIRS]

        for filename in filenames:
            if filename.lower().endswith(".ino"):
                full_path = os.path.join(current_dir, filename)
                ino_files.append(os.path.relpath(full_path, root_dir))

    return sorted(ino_files)


def main():
    repo_root = os.getcwd()
    ino_files = find_ino_files(repo_root)

    if ino_files:
        print("Arduino sketch files found:")
        for path in ino_files:
            print(f"  - {path}")

    print(f"Total Arduino Files: {len(ino_files)}")

    # Exit non-zero if no sketches are found at all, which likely
    # indicates the workflow is running against the wrong directory.
    if len(ino_files) == 0:
        print("Warning: No .ino files found in repository.", file=sys.stderr)
        sys.exit(1)

    sys.exit(0)


if __name__ == "__main__":
    main()
