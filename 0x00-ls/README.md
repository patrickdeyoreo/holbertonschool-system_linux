# 0x00. C - ls

---

## `hls` - list directory contents

---

### Usage

`hls [OPTION]... [FILE]...`

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

---

### Examples

- List non-hidden entries in the current directory, one per line:

`hls -1`

- List all entries in the parent directory sorted by size:

`hls -aS ../`

- Recursively list the contents of the directory `/var/log`:

`hls -R /var/log`

---

### Compilation

#### `gcc -Wall -Werror -Wextra -pedantic *.c -o hls`

---

### Author

[Patrick DeYoreo](github.com/patrickdeyoreo)
