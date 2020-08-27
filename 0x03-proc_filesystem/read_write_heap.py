#!/usr/bin/python3
"""Hack the VM."""

import argparse
import collections
import functools
import itertools
import operator
import os
import sys


class MapEntry:
    """A process memory-map entry."""
    # pylint: disable=too-few-public-methods
    pmap = {'r': 4, 'w': 2, 'x': 1, 'p': 0, 's': 0, '-': 0}
    Dev = collections.namedtuple('dev', ('major', 'minor'))

    def __init__(self, address, perms, offset, dev, inode, pathname):
        """Initialize a memory-map entry."""
        # pylint: disable=too-many-arguments
        self.address = tuple(int(x, 0x10) for x in address.split('-', 1))
        self.perms = functools.reduce(operator.or_, map(self.pmap.get, perms))
        self.offset = int(offset, 0x10)
        self.dev = self.Dev(dev.split(':', 1))
        self.inode = int(inode) or None
        self.pathname = pathname


def parse_args():
    """Parse command-line arguments."""
    parser = argparse.ArgumentParser(os.path.basename(__file__))
    parser.add_argument('pid', metavar='PID', type=int, help='process ID')
    parser.add_argument('search', metavar='SEARCH', help='search string')
    parser.add_argument('replace', metavar='REPLACE', help='replace string')
    return parser.parse_args()


def read_maps(**kwgs):
    """Get the memory-map of a process."""
    split = operator.methodcaller('split')
    with open('/proc/{pid}/maps'.format(**kwgs), 'r') as istream:
        return itertools.starmap(MapEntry, map(split, istream))


def read_heap(entry, **kwgs):
    """Read and write the process memory."""
    with open('/proc/{pid}/mem'.format(**kwgs), 'rb') as istreamb:
        istreamb.seek(entry.address[0])
        return istreamb.read(operator.sub(*entry.address[::-1]))


def search_heap(heap, **kwgs):
    """Find the index of a string in the heap."""
    return heap.index(kwgs['search'].encode())


def write_heap(entry, offset, **kwgs):
    """Read and write the process memory."""
    with open('/proc/{pid}/mem'.format(**kwgs), 'rb+') as iostreamb:
        iostreamb.seek(entry.address[0] + offset)
        return iostreamb.write(kwgs['replace'].encode())


def main():
    """Hack the virtual memory."""
    with sys.stdout as sys.stderr:
        kwgs = vars(parse_args())
    maps = {entry.pathname: entry for entry in read_maps(**kwgs)}
    heap = read_heap(maps['[heap]'], **kwgs)
    write_heap(maps['[heap]'], search_heap(heap, **kwgs), **kwgs)


if __name__ == '__main__':
    # pylint: disable=broad-except
    try:
        sys.exit(main())
    except SystemExit:
        sys.exit(1)
    except Exception:
        print(sys.exc_info())
        sys.exit(1)
