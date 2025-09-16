CC = gcc
CFLAGS = -g -Wall -std=c99 -pedantic

SRC_DIR = src
TEST_DIR = tests
BIN_DIR = bin
OBJ_DIR = obj


SRC_FILES  = $(SRC_DIR)/*.c
TEST_FILES = $(TEST_DIR)/*.c

APP_OBJS   = $(SRC_DIR)/%.c, $(OBJ_DIR)/%.o, $(SRC_FILES)
TEST_OBJS  = $(TEST_DIR)/%.c, $(OBJ_DIR)/%.o, $(TEST_FILES)

APP_TARGET  = $(BIN_DIR)/main.exe
TEST_TARGET = $(BIN_DIR)/tests.exe


.PHONY: all app test clean

all: app test

app: dirs $(APP_TARGET)

test: dirs $(TEST_TARGET)

$(APP_TARGET): $(APP_OBJS)
	$(CC) $(APP_OBJS) -o $@

$(TEST_TARGET): $(TEST_OBJS) $(filter-out $(OBJ_DIR)/main.o,$(APP_OBJS))
	$(CC) $(CFLAGS) -o $@ $^

# compilation
$(OBJ_DIR)/main.o: $(SRC_DIR)/main.c 
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_DIR)/code.o: code.c code2.c		# $(OBJ_DIR)/code.o: $(SRC_DIR)/code.c
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_DIR)/tests.o: $(TEST_DIR)/tests.c
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_DIR)/unity.o: $(TEST_DIR)/unity.c
	$(CC) $(CFLAGS) -c $< -o $@

dirs:
	@if not exist $(OBJ_DIR) mkdir $(OBJ_DIR)
	@if not exist $(BIN_DIR) mkdir $(BIN_DIR)

clean:
	-del /Q $(OBJ_DIR)\*.o 2>nul
	-del /Q $(BIN_DIR)\*.exe 2>nul

