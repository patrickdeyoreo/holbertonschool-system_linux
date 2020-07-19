# 0x00. C - ls

## `hls`

### Compilation

`gcc -Wall -Werror -Wextra -pedantic *.c -o hls`

### Synopsis

`ls` - list directory contents

### Usage

`ls [OPTION]... [FILE]...`

### Options

Name | Description
---- | ------------
`-1` | list one file per line
`-A` | do not list implied . and ..
`-a` | do not ignore entries starting with .
`-l` | use a long listing format
`-R` | list subdirectories recursively
`-r` | reverse order while sorting
`-S` | sort by file size, largest first
`-t` | sort by modification time, newest first

### Exit Status

Value | Description
----- | -----------
`0`   | if OK,
`1`   | if minor problems (e.g., cannot access subdirectory),
`2`   | if serious trouble (e.g., cannot access command-line argument).

### Author

[Patrick DeYoreo](github.com/patrickdeyoreo)
