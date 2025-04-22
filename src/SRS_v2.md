# Software Requirements Specification (SRS): Chess Game

## 1. Introduction
This document defines the behavioral and functional requirements for a terminal-based chess game implemented in C. The project is structured into modular components, each responsible for part of the system's operation. Students are provided with the architecture and function declarations; this document specifies what each function must do.

## 2. Overall Description
The chess game runs in a terminal using ASCII graphics. It supports two human players taking turns. The game includes board management, move validation, turn control, and basic rule enforcement including check and checkmate detection. Input is provided through standard input (keyboard), and the display is printed to standard output.

## 3. Functional Requirements

### 3.1 UI Module

[REQ-XXX-000] `void ui_init()`  
- Initializes any UI-specific settings or state (e.g., terminal styling). Must be called once at the start of the game.

[REQ-XXX-000] `void ui_draw_board()`  
- Renders the current board state to the terminal using ASCII graphics.

[REQ-XXX-000] `void ui_show_message(const char* msg)`  
- Prints a message string to the terminal. Used for prompts, errors, and status updates.

[REQ-XXX-000] `void ui_cleanup()`  
- Performs any necessary cleanup of UI resources before exiting. Can be left empty.

### 3.2 Board Module

[REQ-XXX-000] `void board_init()`  
- Initializes the internal 8x8 board with the standard chess starting positions.

[REQ-XXX-000] `char board_get(int row, int col)`  
- Returns the character representing the piece at a given board location. Returns `'.'` if the square is empty.

[REQ-XXX-000] `void board_set(int row, int col, char piece)`  
- Places the given piece character at the specified location on the board.

### 3.3 Player Module

[REQ-XXX-000] `char player_get_current()`  
- Returns `'W'` or `'B'` to indicate which player's turn it is.

[REQ-XXX-000] `void player_switch()`  
- Toggles the current player between `'W'` and `'B'`.

### 3.4 IO Module

[REQ-XXX-000] `typedef struct { int from_row, from_col, to_row, to_col; } Move;`  
- Represents a move from one board position to another.

[REQ-XXX-000] `bool io_get_move(Move* move)`  
- Prompts the user for input (e.g., `e2 e4`), parses it into the `Move` struct, and returns `true` if valid.

### 3.5 Move Validator Module

[REQ-XXX-000] `bool is_valid_move(Move move, char player)`  
- Returns `true` if the move is legal for the specified player and piece, according to simplified chess rules.

### 3.6 Check Module

[REQ-XXX-000] `bool is_in_check(char player)`  
- Returns `true` if the current player's king is under attack.

[REQ-XXX-000] `bool is_checkmate(char player)`  
- Returns `true` if the player is in check and has no valid moves to escape.

### 3.7 Game Loop Module

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

