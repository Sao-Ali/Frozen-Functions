# Software Requirements Specification (SRS): Chess Game

---

2025-04-15  v0.0.0  Initial version
2025-04-20  v0.1.0  Added details on game loop and player switching

---

Client: Adam West High School, Principal Shepherd
Project Name: Project 1 - Chess Game

--- 

## 1. About this Document
This document defines the behavioral and functional requirements for a terminal-based chess game implemented in C.
The project is structured into modular components, each responsible for part of the system's operation.
This document specifies the interface and behavior of each function in a given module.

---

## 2. System Overview
The chess game runs in a terminal using ASCII graphics.
It supports two human players taking turns.
The game includes board management, move validation, turn control, and basic rule enforcement.
The game can detect check and checkmate conditions.
The game is played on an 8x8 board with standard chess pieces.
Input is provided through standard input (keyboard), and the display is printed to standard output.

---

## 3. Architecture Overview (Proposed)

```
                      ┌────────────┐
                      │  main.c    │
                      └────┬───────┘
                           │
                    ┌──────▼───────┐
                    │  game.c      │
                    └──────┬───────┘
                           │
   ┌────────────┬──────────┼──────────┬──────────────┐
   │            │          │          │              │
┌──▼───┐    ┌────▼────┐ ┌──▼───┐   ┌──▼─────┐   ┌────▼─────┐
│ ui   │    │  check  │ │  io  │   │ player │   │ validator│
└──┬───┘    └────┬────┘ └──┬───┘   └────────┘   └────┬─────┘
   │             │         │                         │
   │             │         │                         │
   ▼             ▼         ▼                         ▼
────────────  ───────────────  ───────────────  ─────────────
   board.c     (Shared Data Layer: 8x8 board state, pieces)
────────────  ───────────────  ───────────────  ─────────────
```

---

## 4. Functional Requirements

### 3.1 UI Module

- Description: Handles all user-facing output and interactions via the terminal. Depends on the `board` module to access board state for rendering.
- Depends on: `board`
- Used by: `game`

[REQ-XXX-000] `void ui_init()`  
- Initializes any UI-specific settings or state (e.g., terminal styling). Must be called once at the start of the game.

[REQ-XXX-000] `void ui_draw_board()`  
- Renders the current board state to the terminal using ASCII graphics.

[REQ-XXX-000] `void ui_show_message(const char* msg)`  
- Prints a message string to the terminal. Used for prompts, errors, and status updates.

[REQ-XXX-000] `void ui_cleanup()`  
- Performs any necessary cleanup of UI resources before exiting. Can be left empty.

### 3.2 Board Module

- Description: Manages the underlying board data structure and piece positions.
- Depends on: None
- Used by: `ui`, `move_validator`, `check`, `game`

[REQ-XXX-000] `void board_init()`  
- Initializes the internal 8x8 board with the standard chess starting positions.

[REQ-XXX-000] `char board_get(int row, int col)`  
- Returns the character representing the piece at a given board location. Returns `'.'` if the square is empty.

[REQ-XXX-000] `void board_set(int row, int col, char piece)`  
- Places the given piece character at the specified location on the board.

### 3.3 Player Module

- Description: Tracks the current player and handles switching turns.
- Depends on: None
- Used by: `game`, `check`, `move_validator`

[REQ-XXX-000] `char player_get_current()`  
- Returns `'W'` or `'B'` to indicate which player's turn it is.

[REQ-XXX-000] `void player_switch()`  
- Toggles the current player between `'W'` and `'B'`.

### 3.4 IO Module

- Description: Reads and parses user input into structured moves.
- Depends on: None
- Used by: `game`

[REQ-XXX-000] `typedef struct { int from_row, from_col, to_row, to_col; } Move;`  
- Represents a move from one board position to another.

[REQ-XXX-000] `bool io_get_move(Move* move)`  
- Prompts the user for input (e.g., `e2 e4`), parses it into the `Move` struct, and returns `true` if valid.

### 3.5 Move Validator Module

- Description: Validates if a move is legal based on piece rules.
- Depends on: `board`, `player`
- Used by: `game`, `check`

[REQ-XXX-000] `bool is_valid_move(Move move, char player)`  
- Returns `true` if the move is legal for the specified player and piece, according to simplified chess rules.

### 3.6 Check Module

- Description: Determines whether a player is in check or checkmate.
- Depends on: `board`, `move_validator`, `player`
- Used by: `game`

[REQ-XXX-000] `bool is_in_check(char player)`  
- Returns `true` if the current player's king is under attack.

[REQ-XXX-000] `bool is_checkmate(char player)`  
- Returns `true` if the player is in check and has no valid moves to escape.

### 3.7 Game Loop Module

- Description: Orchestrates the overall flow of the game.
- Depends on: All other modules
- Used by: `main`

[REQ-XXX-000] `void game_loop()`  
- Controls the main game flow: displays the board, gets input, validates and applies moves, checks win condition, and switches players.

## 4. Constraints
- Only standard C libraries may be used.
- The program must compile and run on a terminal environment.
- No graphical libraries or external dependencies allowed.

## 5. Assumptions
- The game will be played by two human players on the same machine.
- No pawn promotion, castling, or en passant are required.
- Draw conditions (like threefold repetition or stalemate) are not implemented.
- One game per execution.

