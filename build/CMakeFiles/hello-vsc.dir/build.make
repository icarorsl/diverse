# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.12

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

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "C:\Program Files\CMake\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\CMake\bin\cmake.exe" -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = C:\_projects\git\diverse

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\_projects\git\diverse\build

# Include any dependencies generated for this target.
include CMakeFiles/hello-vsc.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/hello-vsc.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/hello-vsc.dir/flags.make

CMakeFiles/hello-vsc.dir/src/main.cpp.obj: CMakeFiles/hello-vsc.dir/flags.make
CMakeFiles/hello-vsc.dir/src/main.cpp.obj: CMakeFiles/hello-vsc.dir/includes_CXX.rsp
CMakeFiles/hello-vsc.dir/src/main.cpp.obj: ../src/main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\_projects\git\diverse\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/hello-vsc.dir/src/main.cpp.obj"
	cd /d C:\_projects\git\diverse\build && C:\_projects\tools\mingw32\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\hello-vsc.dir\src\main.cpp.obj -c C:\_projects\git\diverse\src\main.cpp

CMakeFiles/hello-vsc.dir/src/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/hello-vsc.dir/src/main.cpp.i"
	cd /d C:\_projects\git\diverse\build && C:\_projects\tools\mingw32\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\_projects\git\diverse\src\main.cpp > CMakeFiles\hello-vsc.dir\src\main.cpp.i

CMakeFiles/hello-vsc.dir/src/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/hello-vsc.dir/src/main.cpp.s"
	cd /d C:\_projects\git\diverse\build && C:\_projects\tools\mingw32\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\_projects\git\diverse\src\main.cpp -o CMakeFiles\hello-vsc.dir\src\main.cpp.s

CMakeFiles/hello-vsc.dir/src/core/DSObject.cpp.obj: CMakeFiles/hello-vsc.dir/flags.make
CMakeFiles/hello-vsc.dir/src/core/DSObject.cpp.obj: CMakeFiles/hello-vsc.dir/includes_CXX.rsp
CMakeFiles/hello-vsc.dir/src/core/DSObject.cpp.obj: ../src/core/DSObject.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\_projects\git\diverse\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/hello-vsc.dir/src/core/DSObject.cpp.obj"
	cd /d C:\_projects\git\diverse\build && C:\_projects\tools\mingw32\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\hello-vsc.dir\src\core\DSObject.cpp.obj -c C:\_projects\git\diverse\src\core\DSObject.cpp

CMakeFiles/hello-vsc.dir/src/core/DSObject.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/hello-vsc.dir/src/core/DSObject.cpp.i"
	cd /d C:\_projects\git\diverse\build && C:\_projects\tools\mingw32\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\_projects\git\diverse\src\core\DSObject.cpp > CMakeFiles\hello-vsc.dir\src\core\DSObject.cpp.i

CMakeFiles/hello-vsc.dir/src/core/DSObject.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/hello-vsc.dir/src/core/DSObject.cpp.s"
	cd /d C:\_projects\git\diverse\build && C:\_projects\tools\mingw32\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\_projects\git\diverse\src\core\DSObject.cpp -o CMakeFiles\hello-vsc.dir\src\core\DSObject.cpp.s

# Object files for target hello-vsc
hello__vsc_OBJECTS = \
"CMakeFiles/hello-vsc.dir/src/main.cpp.obj" \
"CMakeFiles/hello-vsc.dir/src/core/DSObject.cpp.obj"

# External object files for target hello-vsc
hello__vsc_EXTERNAL_OBJECTS =

hello-vsc.exe: CMakeFiles/hello-vsc.dir/src/main.cpp.obj
hello-vsc.exe: CMakeFiles/hello-vsc.dir/src/core/DSObject.cpp.obj
hello-vsc.exe: CMakeFiles/hello-vsc.dir/build.make
hello-vsc.exe: CMakeFiles/hello-vsc.dir/linklibs.rsp
hello-vsc.exe: CMakeFiles/hello-vsc.dir/objects1.rsp
hello-vsc.exe: CMakeFiles/hello-vsc.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:\_projects\git\diverse\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable hello-vsc.exe"
	cd /d C:\_projects\git\diverse\build && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\hello-vsc.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/hello-vsc.dir/build: hello-vsc.exe

.PHONY : CMakeFiles/hello-vsc.dir/build

CMakeFiles/hello-vsc.dir/clean:
	cd /d C:\_projects\git\diverse\build && $(CMAKE_COMMAND) -P CMakeFiles\hello-vsc.dir\cmake_clean.cmake
.PHONY : CMakeFiles/hello-vsc.dir/clean

CMakeFiles/hello-vsc.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\_projects\git\diverse C:\_projects\git\diverse C:\_projects\git\diverse\build C:\_projects\git\diverse\build C:\_projects\git\diverse\build\CMakeFiles\hello-vsc.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/hello-vsc.dir/depend

