*This project has been created as part of the 42 curriculum by jslim.*

# Philosophers (42)

## Description
`philo` is the mandatory Dining Philosophers project from 42.
The goal is to simulate philosophers that eat, sleep, and think using threads and mutexes, while avoiding data races and respecting strict timing/output rules.

Project scope:
- Mandatory part only (`philo`)
- One thread per philosopher
- One mutex per fork
- No global variables

Subject compliance summary:
- Program name: `philo`
- Files to submit: `Makefile`, `*.h`, `*.c`
- Required Makefile rules: `NAME`, `all`, `clean`, `fclean`, `re`
- Mandatory directory for submission: `philo/`
- Libft: not authorized

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
./philo number_of_philosophers time_to_die time_to_eat time_to_sleep [number_of_times_each_philosopher_must_eat]
```

Arguments:
- `number_of_philosophers`: number of philosophers (and forks)
- `time_to_die` (ms): max time without starting to eat before death
- `time_to_eat` (ms): eating duration
- `time_to_sleep` (ms): sleeping duration
- `number_of_times_each_philosopher_must_eat` (optional): stop when all philosophers have eaten this many times

Expected log format:
- `timestamp_in_ms X has taken a fork`
- `timestamp_in_ms X is eating`
- `timestamp_in_ms X is sleeping`
- `timestamp_in_ms X is thinking`
- `timestamp_in_ms X died`

Quick examples:
```bash
./philo 1 800 200 200
./philo 2 800 200 200 2
./philo 5 800 200 200 3
```

## Resources
Classic references:
- POSIX threads manual pages: `man pthread_create`, `man pthread_mutex_lock`, `man pthread_join`
- `gettimeofday(2)` and `usleep(3)` manual pages
- Dining Philosophers overview: <https://en.wikipedia.org/wiki/Dining_philosophers_problem>

AI usage disclosure:
- AI was used to review code behavior, identify race/deadlock/starvation risks, and propose minimal fixes.
- AI was also used to suggest test cases and help improve README structure.
- Final code decisions, edits, and validations were done locally by the project author.
