#!/usr/bin/python3
"""Hack the VM."""

import argparse
import contextlib
import os
import sys


class MapEntry:
    """Represent a memory-map entry."""
    # pylint: disable=too-few-public-methods
    def __init__(self, address, perms, offset, dev, inode, pathname=None):
        """Initialize a memory-map entry."""
        # pylint: disable=too-many-arguments
        self.address = tuple(int(x, 0x10) for x in address.split('-', 1))
        self.perms = perms
        self.offset = int(offset, 0x10)
        self.dev = dev
        self.inode = int(inode)
        self.pathname = pathname


class SearchString(argparse.Action):
    """Accept a string of non-zero length."""
    # pylint: disable=too-few-public-methods
    def __call__(self, parser, namespace, value, option_string=None):
        """Take action based on arguments."""
        if len(value) == 0:
            parser.error("{} cannot be the empty string".format(self.dest))
        setattr(namespace, self.dest, value)


@contextlib.contextmanager
def stdout_as_stderr():
    """Temporarily redirect stderr to stdout."""
    stderr, sys.stderr = sys.stderr, sys.stdout
    try:
        yield
    finally:
        sys.stderr = stderr


def parse_args():
    """Parse command-line arguments."""
    parser = argparse.ArgumentParser(os.path.basename(__file__))
    parser.add_argument('pid', type=int, help="process ID")
    parser.add_argument('search', action=SearchString, help="search string")
    parser.add_argument('replace', help="replacement string")
    with stdout_as_stderr():
        return parser.parse_args()


def read_maps(**kwgs):
    """Get the memory-map of a process."""
    with open('/proc/{pid}/maps'.format(**kwgs)) as istream:
        return [MapEntry(*line.split()) for line in istream]


def read_heap(mmap, **kwgs):
    """Read and write the process memory."""
    with open('/proc/{pid}/mem'.format(**kwgs), 'rb') as istreamb:
        istreamb.seek(mmap.address[0])
        return istreamb.read(mmap.address[1] - mmap.address[0])


def search_heap(heap, **kwgs):
    """Find the index of a string in the heap."""
    return heap.index('{search}'.format(**kwgs).encode())


def write_heap(mmap, offset, **kwgs):
    """Read and write the process memory."""
    with open('/proc/{pid}/mem'.format(**kwgs), 'rb+') as iostreamb:
        iostreamb.seek(mmap.address[0] + offset)
        return iostreamb.write('{replace}\0'.format(**kwgs).encode())


def main():
    """Hack the virtual memory."""
    # pylint: disable=broad-except
    try:
        kwgs = vars(parse_args())
    except SystemExit:
        return 1
    try:
        mmap = {mmap.pathname: mmap for mmap in read_maps(**kwgs)}['[heap]']
        heap = read_heap(mmap, **kwgs)
        hpos = search_heap(heap, **kwgs)
        write_heap(mmap, hpos, **kwgs)
    except Exception as exc:
        print(exc)
        return 1
    else:
        return 0


if __name__ == '__main__':
    sys.exit(main())
