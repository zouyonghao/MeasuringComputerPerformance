# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.10

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
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/zyh/Desktop/计算机系统性能测试/作业2/gettimeofday

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/zyh/Desktop/计算机系统性能测试/作业2/gettimeofday/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/rdtsc.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/rdtsc.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/rdtsc.dir/flags.make

CMakeFiles/rdtsc.dir/rdtsc.cpp.o: CMakeFiles/rdtsc.dir/flags.make
CMakeFiles/rdtsc.dir/rdtsc.cpp.o: ../rdtsc.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/zyh/Desktop/计算机系统性能测试/作业2/gettimeofday/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/rdtsc.dir/rdtsc.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/rdtsc.dir/rdtsc.cpp.o -c /home/zyh/Desktop/计算机系统性能测试/作业2/gettimeofday/rdtsc.cpp

CMakeFiles/rdtsc.dir/rdtsc.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/rdtsc.dir/rdtsc.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/zyh/Desktop/计算机系统性能测试/作业2/gettimeofday/rdtsc.cpp > CMakeFiles/rdtsc.dir/rdtsc.cpp.i

CMakeFiles/rdtsc.dir/rdtsc.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/rdtsc.dir/rdtsc.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/zyh/Desktop/计算机系统性能测试/作业2/gettimeofday/rdtsc.cpp -o CMakeFiles/rdtsc.dir/rdtsc.cpp.s

CMakeFiles/rdtsc.dir/rdtsc.cpp.o.requires:

.PHONY : CMakeFiles/rdtsc.dir/rdtsc.cpp.o.requires

CMakeFiles/rdtsc.dir/rdtsc.cpp.o.provides: CMakeFiles/rdtsc.dir/rdtsc.cpp.o.requires
	$(MAKE) -f CMakeFiles/rdtsc.dir/build.make CMakeFiles/rdtsc.dir/rdtsc.cpp.o.provides.build
.PHONY : CMakeFiles/rdtsc.dir/rdtsc.cpp.o.provides

CMakeFiles/rdtsc.dir/rdtsc.cpp.o.provides.build: CMakeFiles/rdtsc.dir/rdtsc.cpp.o


# Object files for target rdtsc
rdtsc_OBJECTS = \
"CMakeFiles/rdtsc.dir/rdtsc.cpp.o"

# External object files for target rdtsc
rdtsc_EXTERNAL_OBJECTS =

rdtsc: CMakeFiles/rdtsc.dir/rdtsc.cpp.o
rdtsc: CMakeFiles/rdtsc.dir/build.make
rdtsc: /usr/lib/x86_64-linux-gnu/libboost_date_time.so
rdtsc: /usr/lib/x86_64-linux-gnu/libboost_filesystem.so
rdtsc: /usr/lib/x86_64-linux-gnu/libboost_system.so
rdtsc: CMakeFiles/rdtsc.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/zyh/Desktop/计算机系统性能测试/作业2/gettimeofday/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable rdtsc"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/rdtsc.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/rdtsc.dir/build: rdtsc

.PHONY : CMakeFiles/rdtsc.dir/build

CMakeFiles/rdtsc.dir/requires: CMakeFiles/rdtsc.dir/rdtsc.cpp.o.requires

.PHONY : CMakeFiles/rdtsc.dir/requires

CMakeFiles/rdtsc.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/rdtsc.dir/cmake_clean.cmake
.PHONY : CMakeFiles/rdtsc.dir/clean

CMakeFiles/rdtsc.dir/depend:
	cd /home/zyh/Desktop/计算机系统性能测试/作业2/gettimeofday/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/zyh/Desktop/计算机系统性能测试/作业2/gettimeofday /home/zyh/Desktop/计算机系统性能测试/作业2/gettimeofday /home/zyh/Desktop/计算机系统性能测试/作业2/gettimeofday/cmake-build-debug /home/zyh/Desktop/计算机系统性能测试/作业2/gettimeofday/cmake-build-debug /home/zyh/Desktop/计算机系统性能测试/作业2/gettimeofday/cmake-build-debug/CMakeFiles/rdtsc.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/rdtsc.dir/depend

