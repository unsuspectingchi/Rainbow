SRC_DIR := src
OBJ_DIR := obj
BIN_DIR := bin
SDL_DIR := /opt/homebrew/Cellar

EXE := $(BIN_DIR)/main
SRC := $(wildcard $(SRC_DIR)/*.cpp)
OBJ := $(SRC:$(SRC_DIR)/%.cpp=$(OBJ_DIR)/%.o)

CXX      := g++
TARGET   := -target arm64-apple-macos11
CPPFLAGS := -I $(SDL_DIR)/sdl2/2.0.14_1/include/SDL2 -I $(SDL_DIR)/sdl2_image/2.0.5/include/SDL2 -I $(SDL_DIR)/sdl2_mixer/2.0.4/include/SDL2 -Iinc -MMD -MP
CXXFLAGS := -Wall -Wextra -std=c++17 -ggdb $(TARGET)
LDFLAGS  := -Llib -L $(SDL_DIR)/sdl2/2.0.14_1/lib -L $(SDL_DIR)/sdl2_image/2.0.5/lib -L $(SDL_DIR)/sdl2_mixer/2.0.4/lib
LDLIBS   := -l SDL2-2.0.0 -l SDL2_image-2.0.0 -l SDL2_mixer-2.0.0

.PHONY: all clean run

all: $(EXE)

$(EXE): $(OBJ) | $(BIN_DIR)
	$(CXX) $(LDFLAGS) $^ $(LDLIBS) $(TARGET) -o $@

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp | $(OBJ_DIR)
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -c $< -o $@

$(BIN_DIR) $(OBJ_DIR):
	mkdir -p $@

clean:
	@$(RM) -rv $(BIN_DIR) $(OBJ_DIR)

run:
	$(EXE)

-include $(OBJ:.o=.d)