# Software Requirements Specification (SRS) Document

# Software Requirements Specification (SRS)

## 1. Introduction
This document defines the functional requirements and key specifications for the implementation of a terminal-based chess video game in C. Students are provided with the architectural skeleton and header files, and are responsible for implementing each module according to the interface and behavior described here.

## 2. Overall Description
The chess game is a two-player, turn-based game playable via the terminal. The game maintains the full state of a standard chess board, validates moves according to simplified chess rules, detects check and checkmate, and displays the board after each turn.

- Display is ASCII-based.
- Game runs in the terminal.
- Input is through standard input in algebraic notation (e.g., `e2 e4`).

## 3. Functional Requirements

### 3.1 Board Module (`board.c/h`)
- `void board_init();`
  - Initializes the board with all pieces in standard starting positions.
- `char board_get(int row, int col);`
  - Returns the character representing the piece at the given position.
- `void board_set(int row, int col, char piece);`
  - Sets the given piece at the specified position.
- Board is an 8x8 `char` matrix.
- Empty squares use `'.'`.
- White pieces are uppercase (`P`, `R`, `N`, `B`, `Q`, `K`).
- Black pieces are lowercase (`p`, `r`, `n`, `b`, `q`, `k`).

### 3.2 Player Module (`player.c/h`)
- `char player_get_current();`
  - Returns `'W'` or `'B'` for current player.
- `void player_switch();`
  - Switches to the other player.
- Game starts with White.

### 3.3 Input/Output Module (`io.c/h`)
- `typedef struct { int from_row, from_col, to_row, to_col; } Move;`
- `bool io_get_move(Move* move);`
  - Prompts the user to enter a move (e.g., `e2 e4`).
  - Parses and fills in the `Move` structure.
  - Returns `true` if valid format and in bounds, else `false`.

### 3.4 UI Module (`ascii_ui.c/h`)
- `void ui_init();`
  - Initializes any UI-related data (can be empty).
- `void ui_draw_board();`
  - Displays the current board state.
- `void ui_show_message(const char* msg);`
  - Prints the message string to the terminal.
- `void ui_cleanup();`
  - Cleans up resources (can be empty).

### 3.5 Move Validator Module (`move_validator.c/h`)
- `bool is_valid_move(Move move, char player);`
  - Returns `true` if the move is legal based on the piece type.
  - Only basic rules: no castling, no en passant, no promotion.
  - Moves must follow piece-specific motion:
    - Pawn: forward, no diagonal capture
    - Rook: straight lines
    - Bishop: diagonals
    - Knight: `L` shape
    - Queen: straight + diagonal
    - King: one square in any direction

### 3.6 Check Module (`check.c/h`)
- `bool is_in_check(char player);`
  - Returns `true` if the player's king is under attack.
- `bool is_checkmate(char player);`
  - Returns `true` if the player is in check and has no legal moves.
- Implementation may simulate moves and undo them.

### 3.7 Game Loop Module (`game.c/h`)
- `void game_loop();`
  - Controls the main game sequence:
    - Draws board
    - Gets input
    - Validates move
    - Applies move
    - Detects check/checkmate
    - Switches player
  - Ends on checkmate

## 4. Constraints
- No external libraries except standard C headers.
- Game must compile via `gcc` using the provided `Makefile`.
- Target platform: Windows (MSYS2), Linux, or macOS terminal.

## 5. Assumptions
- No saving/loading games.
- No draw detection (e.g., stalemate, 50-move rule).
- No pawn promotion.
- One game per run.

## 6. Appendix
- `row` is `0` at top (rank 8), `7` at bottom (rank 1).
- `col` is `0` at 'a', `7` at 'h'.

---
This SRS provides all the behavioral expectations necessary for students to begin implementing each function. The design (files, declarations) is assumed to be pre-provided.

