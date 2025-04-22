# Proposed Directory Structure for a Chess Game in ANSI-C

chess-game/
├── Makefile
├── README.md
├── .gitignore
├── compile_flags.txt                # for debugging tools like clangd
├── src/
│   ├── main.c                       # entry point, game loop
│   ├── board.c                      # board state management
│   ├── board.h
│   ├── move_validator.c            # rule-based move legality
│   ├── move_validator.h
│   ├── game.c                       # turn control, win condition
│   ├── game.h
│   ├── player.c                     # player switching, names
│   ├── player.h
│   ├── io.c                         # parses user input, like "e2 e4"
│   ├── io.h
│   ├── check.c                      # check/checkmate detection
│   ├── check.h
│   ├── ai.c                         # optional: AI opponent logic
│   ├── ai.h
│   ├── clock.c                      # optional: per-player timer
│   ├── clock.h
│   ├── ui/
│   │   ├── ui.h                     # abstract UI interface
│   │   ├── ascii_ui.c               # ASCII-based implementation
│   │   └── sdl_ui.c                 # SDL2-based alternative
├── include/                         # (optional) central headers
│   └── config.h                     # game config macros/constants
├── assets/                          # (optional for SDL2)
│   └── pieces/                      # chess piece images
├── build/                           # compiled objects
│   └── (empty, gitignored)
└── docs/
    ├── design.md
    └── diagrams/
        └── architecture.png
