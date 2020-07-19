# 0x00. C - ls

## List directory contents.

### Compilation

`gcc -Wall -Werror -Wextra -pedantic *.c -o ls`

### Usage

`ls [OPTION]... [FILE]...`

### Options

- `-1`: list one file per line
- `-A`: do not list implied . and ..
- `-a`: do not ignore entries starting with .
- `-l`: use a long listing format
- `-R`: list subdirectories recursively
- `-r`: reverse order while sorting
- `-S`: sort by file size, largest first
- `-t`: sort by modification time, newest first

### Author

[Patrick DeYoreo](github.com/patrickdeyoreo)
