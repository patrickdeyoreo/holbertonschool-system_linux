#!/usr/bin/python3
"""Hack the VM."""

import argparse
import collections
import contextlib
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

    def __init__(self, address, perms, offset, dev, inode, pathname=None):
        """Initialize a memory-map entry."""
        # pylint: disable=too-many-arguments
        self.address = tuple(int(x, 0x10) for x in address.split('-', 1))
        self.perms = functools.reduce(operator.or_, map(self.pmap.get, perms))
        self.offset = int(offset, 0x10)
        self.dev = self.Dev(*dev.split(':', 1))
        self.inode = int(inode) or None
        self.pathname = pathname


@contextlib.contextmanager
def stdout_as_stderr():
    """Temporarily redirect stderr to stdout."""
    stderr = sys.stderr
    sys.stderr = sys.stdout
    try:
        yield
    finally:
        sys.stderr = stderr


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
        return itertools.starmap(MapEntry, map(split, istream.readlines()))


def read_heap(entry, **kwgs):
    """Read and write the process memory."""
    with open('/proc/{pid}/mem'.format(**kwgs), 'rb') as istreamb:
        istreamb.seek(entry.address[0])
        return istreamb.read(operator.sub(*entry.address[::-1]))


def search_heap(heap, **kwgs):
    """Find the index of a string in the heap."""
    return heap.index('{search}\0'.format(**kwgs).encode())


def write_heap(entry, offset, **kwgs):
    """Read and write the process memory."""
    with open('/proc/{pid}/mem'.format(**kwgs), 'rb+') as iostreamb:
        iostreamb.seek(entry.address[0] + offset)
        return iostreamb.write('{replace}\0'.format(**kwgs).encode())


def main():
    """Hack the virtual memory."""
    try:
        with stdout_as_stderr():
            kwgs = vars(parse_args())
    except SystemExit:
        return 1
    try:
        maps = {entry.pathname: entry for entry in read_maps(**kwgs)}
        heap = read_heap(maps['[heap]'], **kwgs)
        offset = search_heap(heap, **kwgs)
        write_heap(maps['[heap]'], offset, **kwgs)
    except (IOError, KeyError, ValueError) as exc:
        print(exc, file=sys.stderr)
        return 1
    else:
        return 0


if __name__ == '__main__':
    sys.exit(main())
