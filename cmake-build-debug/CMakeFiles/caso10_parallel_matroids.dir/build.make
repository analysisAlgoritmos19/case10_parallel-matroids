# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.15

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Remove some rules from gmake that .SUFFIXES does not remove.
SUFFIXES =

.SUFFIXES: .hpux_make_needs_suffix_list


# Suppress display of executed commands.
$(VERBOSE).SILENT:


# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = "/Users/esteban/Library/Application Support/JetBrains/Toolbox/apps/CLion/ch-0/192.6817.32/CLion.app/Contents/bin/cmake/mac/bin/cmake"

# The command to remove a file.
RM = "/Users/esteban/Library/Application Support/JetBrains/Toolbox/apps/CLion/ch-0/192.6817.32/CLion.app/Contents/bin/cmake/mac/bin/cmake" -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = "/Users/esteban/Documents/TEC/IV Semestre/Análisis de algoritmos/caso10_parallel-matroids"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "/Users/esteban/Documents/TEC/IV Semestre/Análisis de algoritmos/caso10_parallel-matroids/cmake-build-debug"

# Include any dependencies generated for this target.
include CMakeFiles/caso10_parallel_matroids.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/caso10_parallel_matroids.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/caso10_parallel_matroids.dir/flags.make

CMakeFiles/caso10_parallel_matroids.dir/main.c.o: CMakeFiles/caso10_parallel_matroids.dir/flags.make
CMakeFiles/caso10_parallel_matroids.dir/main.c.o: ../main.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/Users/esteban/Documents/TEC/IV Semestre/Análisis de algoritmos/caso10_parallel-matroids/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/caso10_parallel_matroids.dir/main.c.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/caso10_parallel_matroids.dir/main.c.o   -c "/Users/esteban/Documents/TEC/IV Semestre/Análisis de algoritmos/caso10_parallel-matroids/main.c"

CMakeFiles/caso10_parallel_matroids.dir/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/caso10_parallel_matroids.dir/main.c.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E "/Users/esteban/Documents/TEC/IV Semestre/Análisis de algoritmos/caso10_parallel-matroids/main.c" > CMakeFiles/caso10_parallel_matroids.dir/main.c.i

CMakeFiles/caso10_parallel_matroids.dir/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/caso10_parallel_matroids.dir/main.c.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S "/Users/esteban/Documents/TEC/IV Semestre/Análisis de algoritmos/caso10_parallel-matroids/main.c" -o CMakeFiles/caso10_parallel_matroids.dir/main.c.s

# Object files for target caso10_parallel_matroids
caso10_parallel_matroids_OBJECTS = \
"CMakeFiles/caso10_parallel_matroids.dir/main.c.o"

# External object files for target caso10_parallel_matroids
caso10_parallel_matroids_EXTERNAL_OBJECTS =

caso10_parallel_matroids: CMakeFiles/caso10_parallel_matroids.dir/main.c.o
caso10_parallel_matroids: CMakeFiles/caso10_parallel_matroids.dir/build.make
caso10_parallel_matroids: CMakeFiles/caso10_parallel_matroids.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="/Users/esteban/Documents/TEC/IV Semestre/Análisis de algoritmos/caso10_parallel-matroids/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable caso10_parallel_matroids"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/caso10_parallel_matroids.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/caso10_parallel_matroids.dir/build: caso10_parallel_matroids

.PHONY : CMakeFiles/caso10_parallel_matroids.dir/build

CMakeFiles/caso10_parallel_matroids.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/caso10_parallel_matroids.dir/cmake_clean.cmake
.PHONY : CMakeFiles/caso10_parallel_matroids.dir/clean

CMakeFiles/caso10_parallel_matroids.dir/depend:
	cd "/Users/esteban/Documents/TEC/IV Semestre/Análisis de algoritmos/caso10_parallel-matroids/cmake-build-debug" && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" "/Users/esteban/Documents/TEC/IV Semestre/Análisis de algoritmos/caso10_parallel-matroids" "/Users/esteban/Documents/TEC/IV Semestre/Análisis de algoritmos/caso10_parallel-matroids" "/Users/esteban/Documents/TEC/IV Semestre/Análisis de algoritmos/caso10_parallel-matroids/cmake-build-debug" "/Users/esteban/Documents/TEC/IV Semestre/Análisis de algoritmos/caso10_parallel-matroids/cmake-build-debug" "/Users/esteban/Documents/TEC/IV Semestre/Análisis de algoritmos/caso10_parallel-matroids/cmake-build-debug/CMakeFiles/caso10_parallel_matroids.dir/DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/caso10_parallel_matroids.dir/depend

