SOURCES = $(wildcard src/*.cpp)

OBJ_DIR = obj
SOURCE_DIR = src

OBJECTS = $(SOURCES:src/%.cpp=$(OBJ_DIR)/%.o)

HEADERS = $(wildcard $(SOURCE_DIR)/*.h)

TARGET = build/game.out

CC = g++

CFLAGS = -D _DEBUG -ggdb3 -std=c++17 -Wall -Wextra -Weffc++ -Waggressive-loop-optimizations -Wc++14-compat -Wmissing-declarations -Wcast-align -Wcast-qual -Wchar-subscripts -Wconditionally-supported -Wconversion -Wctor-dtor-privacy -Wempty-body -Wfloat-equal -Wformat-nonliteral -Wformat-security -Wformat-signedness -Wformat=2 -Winline -Wlogical-op -Wnon-virtual-dtor -Wopenmp-simd -Woverloaded-virtual -Wpacked -Wpointer-arith -Winit-self -Wredundant-decls -Wshadow -Wsign-conversion -Wsign-promo -Wstrict-null-sentinel -Wstrict-overflow=2 -Wsuggest-attribute=noreturn -Wsuggest-final-methods -Wsuggest-final-types -Wsuggest-override -Wswitch-default -Wswitch-enum -Wsync-nand -Wundef -Wunreachable-code -Wunused -Wuseless-cast -Wvariadic-macros -Wno-literal-suffix -Wno-missing-field-initializers -Wno-narrowing -Wno-old-style-cast -Wno-varargs -Wstack-protector -fcheck-new -fsized-deallocation -fstack-protector -fstrict-overflow -flto-odr-type-merging -fno-omit-frame-pointer -Wlarger-than=30000 -Wstack-usage=8192 -pie -fPIE -Werror=vla -fsanitize=address,alignment,bool,bounds,enum,float-cast-overflow,float-divide-by-zero,integer-divide-by-zero,leak,nonnull-attribute,null,object-size,return,returns-nonnull-attribute,shift,signed-integer-overflow,undefined,unreachable,vla-bound,vptr

.DEFAULT_GOAL := run

$(OBJ_DIR)/%.o: $(SOURCE_DIR)/%.cpp $(HEADERS)
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) -c $< -o $@
	@echo "COMPILED" $<

$(TARGET): $(OBJECTS)
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) $^ -o $@
	@echo "LINKED"

run: $(TARGET)	
	@./$(TARGET)

all: $(TARGET)	

clean:
	@rm -rf $(OBJ_DIR)
	@rm -f $(TARGET)
	@echo "CLEANED"

.PHONY: all clean run