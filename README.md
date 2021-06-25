<a href="logo Shell"><img src="https://blog.hyunsub.kim/covers/bash.jpg" align="middle" width="800" height="400"></a> 0x16. C - Simple Shell

---
> ## Table of Contents

* [Introduction](#Introduction)
* [Description](#description)
* [Requirements](#requirements)
* [Installation](#installation)
* [Compilation](#Compilation)
* [Usage](#usage)
* [Extra Information](#Extra-information)
  * [What’s Included?](#What’s-Included?)
  * [Output](#Output)
  * [Testing](#Testing)
  * [Tasks](#Tasks)
    * [0. README, man, AUTHORS](#0.-README,-man,-AUTHORS)
    * [1. Betty would be proud](#1.-Betty-would-be-proud)
    * [3. Simple shell 0.1](#3.-Simple-shell-0.1)
    * [5. Simple shell 0.2](#5.-Simple-shell-0.2)
    * [7. Simple shell 0.3](#7.-Simple-shell-0.3)
    * [8. Simple shell 0.4](#8.-Simple-shell-0.4)
    * [11. Simple shell 1.0](#11.-Simple-shell-1.0)
    * [22. What happens when you type ls -l in the shell](#22.-What-happens-when-you-type-ls--l-in-the-shell)
* [Example of Use](#example-of-use)
* [Contact](#Contact)
* [License](#license)
---

## Introduction
The simple shell project is a collaboration between **`Victor Paz`** and **`Ricardo Camayo`**, Full Stack Software Engineering students at **`Holberton School`**, with which we can emulate the operation of a shell, which contains some of its most basic characteristics, such as : Handle `PATH`, Handle command lines with `arguments`, Must handle "`end of file`" condition
## Description
Simple_shell is a Command line interpreter, which includes the basic functionality of a Unix shell
## Requirements
simple_shell is designed to run in the `Ubuntu 14.04 LTS` linux environment and to be compiled using the GNU compiler collection v. `gcc 4.8.4` with flags`-Wall, -Werror, -Wextra, and -pedantic.`
## Installation
Clone this repository: `"https://github.com/ricardo1470/simple_shell"`
   * Change directories into the repository: `cd simple_shell`
   * Compile: see installation instructions later
   * Run the shell: `./hsh`
## Compilation
* Compile: `gcc -Wall -Werror -Wextra -pedantic *.c -o hsh`
* Our main files will include your main header file (`holberton.h`): `#include holberton.h`
## Usage
The simple_shell is designed to execute commands in a similar manner to sh, however with more limited functionality.
> ## Extra Information
### What’s Included?
| File  | Description  |
|---|---|
| `_calloc.c`  | simulates original calloc  |
| `_strcat.c`  | simulates original strcat |
| `_strcmp.c`  | simulates original strcmp |
| `_strcpy.c`  | simulates original strcpy |
| `_strdup.c`  | simulates original strdup |
| `_strlen.c`  | simulates original strlen  |
| `shell.c`  | simple shell  |
| `holberton.h`  | contains prototypes and libraries  |
| `list_path.c`  | simulates original PATH  |

### Output
Unless specified otherwise, your program *must have the exact same output* as `sh` (`/bin/sh`) as well as the exact same error output.
The only difference is when you print an error, the name of the program must be equivalent to your `argv[0]` (See below)

* Example of error with `sh`:
```bash
$ echo "qwerty" | /bin/sh
/bin/sh: 1: qwerty: not found
$ echo "qwerty" | /bin/../bin/sh
/bin/../bin/sh: 1: qwerty: not found
$
```

* Same error with your program `hsh`:
```bash
$ echo "qwerty" | ./hsh
./hsh: 1: qwerty: not found
$ echo "qwerty" | ./././hsh
./././hsh: 1: qwerty: not found
$
```
### Testing
Your shell should work like this in interactive mode:
```bash
$ ./hsh
($) /bin/ls
hsh main.c shell.c
($)
($) exit
$
```
But also in non-interactive mode:

```bash
$ echo "/bin/ls" | ./hsh
hsh main.c shell.c test_ls_2
$
$ cat test_ls_2
/bin/ls
/bin/ls
$
$ cat test_ls_2 | ./hsh
hsh main.c shell.c test_ls_2
hsh main.c shell.c test_ls_2
$
```
### 0. [README](./README.md), [MAN](./man_1_simple_shell), [AUTHORS](./AUTHORS)
* Write a `README`
* Write a `man` for your `shell`.
* You should have an `AUTHORS` file at the root of your repository, listing all individuals having contributed content to the repository. Format, see `Docker`
### [1. Betty would be proud]()
Write a beautiful code that passes the Betty checks
### [3. Simple shell 0.1](./shell.c)
Write a UNIX command line interpreter.
* Usage: `simple_shell`
Your Shell should:

* Display a prompt and wait for the user to type a command. A command line always ends with a new line.
* The prompt is displayed again each time a command has been executed.
* The command lines are simple, no semicolons, no pipes, no redirections or any other advanced features.
* The command lines are made only of one word. No arguments will be passed to programs.
* If an executable cannot be found, print an error message and display the prompt again.
* Handle errors.
* You have to handle the “end of file” condition (`Ctrl+D`)
You don’t have to:
* use the `PATH`
* implement built-ins
* handle special characters : `"`, `'`, ```, `\`, `*`, `&`, `#`.
* be able to move the cursor
* handle commands with arguments
### [5. Simple shell 0.2](./shell.c)
Simple shell 0.1 +
* Handle command lines with arguments
### [7. Simple shell 0.3](./shell.c)
Simple shell 0.2 +
* Handle the `PATH`
### [8. Simple shell 0.4](./shell.c)
Simple shell 0.3 +
* mplement the `exit` built-in, that exits the shell
* Usage: `exit`
* You don’t have to handle any argument to the built-in `exit`
### [11. Simple shell 1.0](./shell.c)
Simple shell 0.4 +
Implement the `env` *built-in*, that prints the current environment
### 22. What happens when you type ls -l in the shell
Write a blog post describing step by step what happens when you type `ls -l` and hit Enter in a shell. Try to explain every step you know of, going in as much details as you can, give examples and draw diagrams when needed. You should merge your previous knowledge of the shell with the specifics of how it works under the hoods (including syscalls).
* Have at least one picture, at the top of the blog post
* Publish your blog post on Medium or LinkedIn
* Share your blog post at least on LinkedIn
* Only one blog post by team
* The blog post must be done and published before the first deadline (it will be part of the manual review)
* Please, remember that these blogs must be written in English to further your technical ability in a variety of settings

## Example of Use

* Compile the program to create the `hsh` executable file (see instructions above).
* run the executable as follows `./hsh`
* Enter basic commands like: `ls`, you can add flags along with `ls` command such as `-l`, `-la`(`ls -l`, `ls -la`)
* press enter after entering the command
* to end the execution of the `simple_shell` program press `ctrl + d` or write the word `exit`

---
> ## Built with
this project was built in `C language`

---
> ## Expressions of Gratitude
---
* `Tell others about this project`
* `Invite a beer` 🍺 `or a coffee` ☕ `to someone on the team.`
---
> ## Contact 💬
> Ricardo Camayo
### | [twitter](https://twitter.com/RICARDO1470) | [linkedin](https://www.linkedin.com/in/ricardo-alfonso-camayo/) | [mail](1466@holbertonschool.com) | [github](https://github.com/ricardo1470/README/blob/master/README.md) |

> Victor Paz
### | [twitter](https://twitter.com/VictorP1312) | [linkedin](https://www.linkedin.com/in/victor-paz-11b56b84/) | [mail](1555@holbertonschool.com) | [github](https://github.com/VMP1312) |
---
## License
*`simple_shell` is open source and therefore free to download and use without permission.*

<a href="url"><img src="https://www.holbertonschool.com/holberton-logo.png" align="middle" width="100" height="30"></a>

---
