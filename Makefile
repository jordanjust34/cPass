# Compiler and flags
CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra -O2
DEBUG_FLAGS = -g -O0

# Directories
SRC_DIR = src
BUILD_DIR = build
BIN_DIR = bin

# Source files
MAIN_SOURCES = main.cpp src/CPass.cpp src/CPassFlags.cpp src/CPassOS.cpp src/CPassNew.cpp src/CPassList.cpp src/CPassRemove.cpp src/CPassEncrypt.cpp
TEST_SOURCES = test.cpp src/CPass.cpp src/CPassFlags.cpp src/CPassOS.cpp src/CPassNew.cpp src/CPassList.cpp src/CPassRemove.cpp src/CPassEncrypt.cpp

# Object files (compiled intermediate files)
MAIN_OBJECTS = $(addprefix $(BUILD_DIR)/,$(MAIN_SOURCES:.cpp=.o))
TEST_OBJECTS = $(addprefix $(BUILD_DIR)/,$(TEST_SOURCES:.cpp=.o))

# Output binaries
MAIN_BINARY = $(BIN_DIR)/cpass
TEST_BINARY = $(BIN_DIR)/test

# Default target
.PHONY: all
all: $(MAIN_BINARY)

# Build main executable
$(MAIN_BINARY): $(MAIN_OBJECTS) | $(BIN_DIR)
	$(CXX) $(CXXFLAGS) $^ -o $@
	@echo "✓ Built $(MAIN_BINARY)"

# Build test executable
.PHONY: test
test: $(TEST_BINARY)
	@echo "✓ Built $(TEST_BINARY)"
	./$(TEST_BINARY)

$(TEST_BINARY): $(TEST_OBJECTS) | $(BIN_DIR)
	$(CXX) $(CXXFLAGS) $^ -o $@

# Compile source files to object files
$(BUILD_DIR)/%.o: %.cpp | $(BUILD_DIR)
	@mkdir -p $(dir $@)
	$(CXX) $(CXXFLAGS) -c $< -o $@
	@echo "✓ Compiled $<"

# Debug build with optimization disabled and debug symbols
.PHONY: debug
debug: CXXFLAGS = -std=c++17 -Wall -Wextra $(DEBUG_FLAGS)
debug: clean $(MAIN_BINARY)
	@echo "✓ Debug build complete"

# Create directories if they don't exist
$(BUILD_DIR) $(BIN_DIR):
	@mkdir -p $@

# Clean build artifacts (keeps binaries)
.PHONY: clean
clean:
	@rm -rf $(BUILD_DIR)
	@echo "✓ Cleaned build artifacts"

# Full clean (removes everything including binaries)
.PHONY: distclean
distclean: clean
	@rm -rf $(BIN_DIR)
	@echo "✓ Full clean complete"

# Rebuild from scratch
.PHONY: rebuild
rebuild: distclean all

# Run main program
.PHONY: run
run: $(MAIN_BINARY)
	./$(MAIN_BINARY)

# Display help
.PHONY: help
help:
	@echo "cPass Makefile Targets:"
	@echo "  make all       - Build main executable (default)"
	@echo "  make test      - Build and run test executable"
	@echo "  make debug     - Build with debug symbols"
	@echo "  make run       - Build and run main program"
	@echo "  make clean     - Remove build artifacts"
	@echo "  make distclean - Remove all generated files"
	@echo "  make rebuild   - Clean and rebuild"
	@echo "  make help      - Show this help message"
