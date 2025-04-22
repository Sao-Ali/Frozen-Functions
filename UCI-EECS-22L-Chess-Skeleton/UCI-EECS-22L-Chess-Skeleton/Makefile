# Compiler and flags
CC = gcc
CFLAGS = -Wall -Wextra -g

# Source and output
SRC_DIR = src
UI_DIR = $(SRC_DIR)/ui
BUILD_DIR = build
OUT = $(BUILD_DIR)/chess

# All C source files
SRC = $(wildcard $(SRC_DIR)/*.c) $(wildcard $(UI_DIR)/*.c)
OBJ = $(patsubst %.c, $(BUILD_DIR)/%.o, $(subst $(SRC_DIR)/,,$(SRC)))

# Include directories
INCLUDES = -I$(SRC_DIR)

# Default target
all: $(OUT)

# Link object files into final binary
$(OUT): $(OBJ)
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -o $@ $^

# Compile each .c to .o
$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(BUILD_DIR)/ui/%.o: $(UI_DIR)/%.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

# Clean build artifacts
clean:
	rm -rf $(BUILD_DIR)

# Optional: run the game
run: all
	./$(OUT)

.PHONY: all clean run


UI_OBJ = $(patsubst %.c, $(BUILD_DIR)/ui/%.o, $(notdir $(wildcard $(UI_DIR)/*.c)))

$(OUT): $(OBJ) $(UI_OBJ)
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -o $@ $^

