# Compiler and flags
CXX = g++
CXXFLAGS = -std=c++11 -g -Wall -Wformat -Iinclude -Iimgui -Iimgui/backends

# Libraries
LDFLAGS = -lGL -lGLU -lGLEW -lglfw -ldl
IMGUI_DIR = imgui

# Source files
SOURCES = main.cpp src/gui_manager.cpp src/bubble_sort.cpp src/merge_sort.cpp src/quick_sort.cpp
IMGUI_SOURCES = $(IMGUI_DIR)/imgui.cpp \
                $(IMGUI_DIR)/imgui_demo.cpp \
                $(IMGUI_DIR)/imgui_draw.cpp \
                $(IMGUI_DIR)/imgui_tables.cpp \
                $(IMGUI_DIR)/imgui_widgets.cpp \
                $(IMGUI_DIR)/backends/imgui_impl_glfw.cpp \
                $(IMGUI_DIR)/backends/imgui_impl_opengl3.cpp

# Object files (moved to bin directory)
OBJECTS = $(SOURCES:%.cpp=bin/%.o) $(IMGUI_SOURCES:%.cpp=bin/%.o)

# Target executable
TARGET = bin/algorithm_visualizer

# Default rule
all: $(TARGET)

# Link the object files to create the final executable
$(TARGET): $(OBJECTS)
	$(CXX) -o $@ $^ $(LDFLAGS)

# Compile source files into object files
bin/%.o: %.cpp
	@mkdir -p $(dir $@)  # Create directory structure if it doesn't exist
	$(CXX) $(CXXFLAGS) -c -o $@ $<

# Clean up build files
clean:
	rm -f $(OBJECTS) $(TARGET)

# Run the program
run: $(TARGET)
	./$(TARGET)

.PHONY: all clean run
