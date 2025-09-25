CC = gcc
CFLAGS = -g -Wall -std=c99 -pedantic -Iinclude

SRC_DIR  = src
TEST_DIR = tests
BIN_DIR  = bin
OBJ_DIR  = obj

SRC_FILES  = $(wildcard $(SRC_DIR)/*.c)
TEST_FILES = $(wildcard $(TEST_DIR)/*.c)

APP_OBJS   = $(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.o, $(SRC_FILES))
TEST_OBJS  = $(patsubst $(TEST_DIR)/%.c, $(OBJ_DIR)/%.o, $(TEST_FILES))

APP_TARGET  = $(BIN_DIR)/main.exe
TEST_TARGET = $(BIN_DIR)/tests.exe

.PHONY: all app test clean

all: app test

app: dirs $(APP_TARGET)

test: dirs $(TEST_TARGET)

$(APP_TARGET): $(APP_OBJS)
	$(CC) $(CFLAGS) $^ -o $@

$(TEST_TARGET): $(TEST_OBJS) $(filter-out $(OBJ_DIR)/main.o,$(APP_OBJS))
	$(CC) $(CFLAGS) $^ -o $@

# Generic compile rule
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_DIR)/%.o: $(TEST_DIR)/%.c
	$(CC) $(CFLAGS) -c $< -o $@

dirs:
	@if not exist $(OBJ_DIR) mkdir $(OBJ_DIR)
	@if not exist $(BIN_DIR) mkdir $(BIN_DIR)

clean:
	-del /Q $(OBJ_DIR)\*.o 2>nul
	-del /Q $(BIN_DIR)\*.exe 2>nul
