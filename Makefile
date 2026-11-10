# ==========================================
# Compiler and Flags Configuration
# ==========================================
CC        := gcc
CFLAGS    := -Wall -Wextra -Werror -O2 -std=c11
CPPFLAGS  := -Iinclude

# ==========================================
# Directory Paths
# ==========================================
SRC_DIR   := src
BUILD_DIR := build
BIN_DIR   := bin

# ==========================================
# Target Binary Name
# ==========================================
TARGET    := $(BIN_DIR)/gb

# ==========================================
# Source and Object File Discovery
# ==========================================
# Automatically finds all .c files in the src/ directory
SRCS      := $(wildcard $(SRC_DIR)/*.c)

# Maps src/filename.c to build/filename.o
OBJS      := $(patsubst $(SRC_DIR)/%.c, $(BUILD_DIR)/%.o, $(SRCS))

# Maps build/filename.o to build/filename.d (dependency files)
DEPS      := $(OBJS:.o=.d)

# ==========================================
# Build Rules
# ==========================================
.PHONY: all clean directories

# Default target
all: directories $(TARGET)

# Rule to link the final executable
$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) $^ -o $@

# Rule to compile source files into object files
# Includes -MMD to generate dependency trackers (.d files)
$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c | directories
	$(CC) $(CFLAGS) $(CPPFLAGS) -MMD -MP -c $< -o $@

# Create output directories if they do not exist
directories:
	@mkdir -p $(BUILD_DIR) $(BIN_DIR)

# Clean up build artifacts
clean:
	rm -rf $(BUILD_DIR) $(BIN_DIR)
	@echo "🧹 Cleaned up build and bin directories."

# Include automatically generated header dependency rules
-include $(DEPS)
