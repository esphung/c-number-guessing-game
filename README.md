# Number Guessing Game (C++)

**Author:** Eric Scott Phung
**Created:** January 26, 2014
**Language:** C++
**Platform:** macOS / Linux (CLI)

---

An interactive command-line game where an AI named **Rusty** guesses a number you're thinking of — in 7 tries or fewer.

You pick any number from 1 to 100, then tell Rusty whether each guess is too high, too low, or correct. Rusty uses a **binary search strategy** to zero in on the answer efficiently, which is mathematically guaranteed to find any number in that range within 7 guesses.

## Features

- Conversational CLI interface — responds to plain-text commands like `too high`, `too low`, `correct`, and `quit`
- Binary search guessing logic that narrows the range with every turn
- Graceful handling of unexpected input with helpful re-prompts
- Clean exit paths for winning, quitting, or reaching the guess limit

## How to Run

Requires `g++` and `make`.

```shell
make clean   # remove any previous build
make all     # compile the program
make run     # start the game
```

## Skills Demonstrated

- **C++** — standard I/O, string comparison, control flow
- **Algorithm design** — binary search applied to an interactive guessing problem
- **CLI UX** — natural-language input parsing and user-friendly prompts
- **Build tooling** — Makefile-based compilation workflow


