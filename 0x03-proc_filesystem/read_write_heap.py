#!/usr/bin/python3
"""Hack the virtual memory."""

import argparse
import os
import sys


def parse_args():
    """Parse program arguments."""
    parser = argparse.ArgumentParser(os.path.basename(__file__))
    parser.add_argument('pid', metavar='PID', type=int, help='process ID')
    parser.add_argument('search', metavar='SEARCH', help='search string')
    parser.add_argument('replace', metavar='REPLACE', help='replace string')
    stderr, sys.stderr = sys.stderr, sys.stdout
    try:
        args = parser.parse_args()
    finally:
        sys.stderr = stderr
    return args


def main():
    """Hack the virtual memory."""
    args = parse_args()


if __name__ == '__main__':
    sys.exit(main())
