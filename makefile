CC = g++

CFLAGS = 

TARGET = build/app
SRC_DIR = src
BUILD_DIR = build

SRCS = $(wildcard $(SRC_DIR)/*.cpp)
OBJS = $(SRCS:$(SRC_DIR)/%.cpp=$(BUILD_DIR)/%.o)

.DEFAULT_GOAL := run

all: $(TARGET)

$(TARGET): $(OBJS)
	@mkdir -p $(BUILD_DIR)
	@$(CC) $(OBJS) -o $@
	@echo "Linked Successfully" $<

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.cpp
	@mkdir -p $(BUILD_DIR)
	@$(CC) $(CFLAGS) -c $< -o $@
	@echo "Compiled Successfully" $<

clean:
	@rm -rf $(BUILD_DIR)
	@echo "Cleaned Successfully" $<

run: $(TARGET)
	./$(TARGET)

.PHONY: all clean run