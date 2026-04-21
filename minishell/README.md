*This project has been created as part of the 42 curriculum by jslim and rghandou.*

# Minishell (42)

## Description
`minishell` is the mandatory shell project from 42.
The goal is to build a small interactive Unix shell that handles parsing, environment expansion, redirections, pipelines, signals, and a core set of built-in commands.

Project scope:
- Mandatory part only (`minishell`)
- Interactive prompt using `readline`
- Built-ins, pipes, redirections, and environment variable expansion
- Command execution via `fork`, `execve`, `pipe`, and `wait`

Implemented features:
- Prompt with history support
- Built-ins: `echo`, `cd`, `pwd`, `export`, `unset`, `env`, `exit`
- Pipes: `|`
- Redirections: `<`, `>`, `>>`, `<<`
- Quote handling with single and double quotes
- Environment expansion including `$VAR` and `$?`
- Signal handling for interactive shell behavior

Project summary:
- Program name: `minishell`
- Files present: `Makefile`, `*.h`, `*.c`
- Required Makefile rules: `all`, `clean`, `fclean`, `re`
- Output binary: `minishell`
- External dependency: `readline`

## Instructions
Build:
```bash
make
```

Useful targets:
```bash
make clean
make fclean
make re
```

Run:
```bash
./minishell
```

Examples:
```bash
echo hello
pwd
ls -la | grep minishell
echo $HOME
cat < infile | wc -l > outfile
<< EOF cat
```

Supported built-ins:
- `echo` with `-n`
- `cd`
- `pwd`
- `export`
- `unset`
- `env`
- `exit`

## Resources
Useful references:
- GNU Readline documentation: <https://tiswww.case.edu/php/chet/readline/rltop.html>
- `execve(2)`, `fork(2)`, `pipe(2)`, `dup2(2)`, `wait(2)` manual pages
- Bash reference manual: <https://www.gnu.org/software/bash/manual/bash.html>

AI usage disclosure:
- AI was used to review project structure, summarize implemented shell behavior, and improve README organization.
- Final project decisions, edits, and validations were done locally by the project author.
