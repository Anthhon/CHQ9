# CHQ9

CHQ9 is a lightweight, cross-platform interpreter for the HQ9+ esoteric 
programming language, written in C. HQ9+ is a joke language with four simple 
commands that produce humorous outputs, making it a fun introduction to 
interpreter design.

## Features

- **Simple & Lightweight**: Minimal dependencies, pure C implementation
- **Cross-Platform**: Works on Windows, Linux, and macOS
- **Two Input Modes**: Execute code from files or directly from the command line
- **Standard HQ9+ Commands**: Implements all core language features

## Language Reference

HQ9+ consists of four commands:

| Command | Description | Output |
| --- | --- | --- | 
| H | Print "Hello, World!" | `Hello, World!` |
| Q | Print the program's source code | The entire code of the runnning program |
| 9 | Print the "99 Bottles of Beer" lyrics | Number 99 to 0 with "bottles of beer in the wall" |
| + | Increment accumulator | None, increments a useless accumulator |

## Installation

```bash
# Clone the repository
git clone https://github.com/yourusername/chq9.git
cd chq9

# Compile
gcc -o chq9 main.c

# Optional: Install to /usr/local/bin
sudo cp chq9 /usr/local/bin/
```

## Usage

```bash
Usage: ./build/hq9+ [OPTIONS] [INPUT]
Options:
  -f <file>    Read code from file
  -c <code>    Execute inline code
  -h, --help   Show this help message

Examples:
  ./build/hq9+ -f program.hq9
  ./build/hq9+ -c HHQ9Q
```

## About

This project was created as part of a Programming Paradigms academic 
presentation to demonstrate a functional interpreter for the esoteric HQ9+ 
language, showcasing its basic functionalities and unique properties.
