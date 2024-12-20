# Compiler and flags
CXX = g++
CXXFLAGS = -std=c++17 -DGL_SILENCE_DEPRECATION -I$(INCLUDE_DIR) -Iglfw-3.4/include -mmacosx-version-min=14.6
LDFLAGS = -framework Cocoa -framework IOKit -framework CoreVideo -L/opt/homebrew/lib -lglfw -mmacosx-version-min=14.6

# Directories
SRC_DIR = src
BUILD_DIR = build
INCLUDE_DIR = include

# Source files and output
SRC_FILES = $(wildcard $(SRC_DIR)/*.cpp) $(wildcard $(SRC_DIR)/*.c)
OBJ_FILES = $(patsubst $(SRC_DIR)/%.cpp,$(BUILD_DIR)/%.o,$(wildcard $(SRC_DIR)/*.cpp)) \
            $(patsubst $(SRC_DIR)/%.c,$(BUILD_DIR)/%.o,$(wildcard $(SRC_DIR)/*.c))
TARGET = rasterizer

# Build only
build: $(TARGET)

# Linking
$(TARGET): $(OBJ_FILES)
	$(CXX) -o $@ $^ $(LDFLAGS)

# Compiling source files
$(BUILD_DIR)/%.o: $(SRC_DIR)/%.cpp
	@mkdir -p $(BUILD_DIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(BUILD_DIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Run only (requires build first)
run:
	@if [ -f $(TARGET) ]; then ./$(TARGET); else echo "Error: Build the project first with 'make build'."; exit 1; fi

# Build and run
runplus: build run

# Clean build artifacts
clean:
	rm -rf $(BUILD_DIR) $(TARGET)

# Phony targets
.PHONY: build run runplus clean
