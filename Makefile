# Compiler and tools
CXX      = C:/Users/oneic/Downloads/mingw64/bin/g++.exe
RM       = rm -f
CP       = cp -u   # -u = only copy if newer

# Project settings
TARGET   = sfml_app
SOURCES  = main.cpp
OBJECTS  = $(SOURCES:.cpp=.o)
DEPENDS  = $(SOURCES:.cpp=.d)

# Paths
SFML_DIR = C:/Users/oneic/Desktop/SFML-3.0.1
MINGW_DIR = C:/Users/oneic/Downloads/mingw64
INC      = -I"$(SFML_DIR)/include"
LIB      = -L"$(SFML_DIR)/lib"

# Resource setup (optional - only if you need fonts)
ASSETS   = tuffy.ttf
ASSET_SRC = $(SFML_DIR)/examples/assets
ASSET_DST = .

# Common compiler flags
CXXFLAGS = -std=c++20 -MMD -MP -Wall -Wextra -Wpedantic

# Build type (default = Debug). Override with `make BUILD=Release`
BUILD ?= Debug

ifeq ($(BUILD),Debug)
    CXXFLAGS += -g -O0
    SFML_LIBS = -lsfml-graphics-d -lsfml-window-d -lsfml-system-d
else ifeq ($(BUILD),Release)
    CXXFLAGS += -O3 -DNDEBUG
    SFML_LIBS = -lsfml-graphics -lsfml-window -lsfml-system
endif

# Linker flags
LDFLAGS = $(LIB) $(SFML_LIBS) -lopengl32 -lwinmm -lgdi32

# Default rule
.PHONY: all clean assets run

all: $(TARGET).exe

# Build executable
$(TARGET).exe: $(OBJECTS)
	@echo "Linking $(TARGET).exe..."
	$(CXX) $(OBJECTS) -o $@ $(LDFLAGS)
	@echo "Build complete!"

# Compile source files
%.o: %.cpp
	@echo "Compiling $<..."
	$(CXX) $(CXXFLAGS) $(INC) -c $< -o $@

# Optional: Copy assets (only if needed)
assets: $(ASSETS)

$(ASSETS):
	@echo "Copying assets..."
	$(CP) "$(ASSET_SRC)/$@" "$(ASSET_DST)/"

# Run the application
run: $(TARGET).exe
	@echo "Running $(TARGET).exe..."
	@./$(TARGET).exe

# Clean build artifacts
clean:
	@echo "Cleaning..."
	$(RM) $(OBJECTS) $(DEPENDS) $(TARGET).exe
	@echo "Clean complete!"

# Include dependency files
-include $(DEPENDS)