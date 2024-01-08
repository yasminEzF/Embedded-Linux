# Embedded Linux Task 5

This task is about creating a cmake file to automate the steps of task 1

## Instructions

After cloning, go to `build` directory and run `cmake` command. Run `make` command afterwards and run the final generated executable `calculatorApp`

## File hierarchy
- CMakeLists.txt
- App
	- main.c

- build

- Inc
	- add.h
	- div.h
	- mod.h
	- mul.h
	- sub.h
	
- Src
	- CMakeLists.txt
	- add.c
	- div.c
	- mod.c
	- mul.c
	- sub.c
	

## CMakeLists.txt

### 1. checking cmake version

after running `cmake --version` to check existent version

```cmake
cmake_minimum_required(VERSION 3.22.1)
```

### 2. adding project name and description

final executable output file name `calculatorApp` 

```cmake
project(calculatorApp 
      DESCRIPTION "embedded linux task 5")
```

### 3. adding subdirectory for cmake chaining 

adding the directory that includes source files for the library and the second `CMakeLists.txt` file 

```cmake
add_subdirectory(${CMAKE_HOME_DIRECTORY}/Src)
```

### 4. adding executable source for target

final executable dependent on its source file 

```cmake
add_executable(${PROJECT_NAME} App/main.c)
```

### 5. adding include directory 

headers are always added as `INTERFACE`

```cmake
target_include_directories(${PROJECT_NAME} INTERFACE ${CMAKE_HOME_DIRECTORY}/Inc)
```

### 6. linking target with the generated library 

linking with the library as `PRIVATE` as no other app is using it through this project output file

```cmake
target_Link_Libraries(${PROJECT_NAME} PRIVATE operation)
```

## Src/CMakeLists.txt for library creation

### 1. adding library

configuring static library to be created

```cmake
add_Library(operation STATIC add.c div.c mod.c mul.c sub.c)
```

### 2. adding include directory

headers are always added as `INTERFACE`

```cmake
target_include_directories(operation INTERFACE ${CMAKE_HOME_DIRECTORY}/Inc)
```

## generating the desired application

### 1. run `cmake` in `/build` directory

```bash
mkdir build
cd build
cmake ..
```

### 2. run generated makefile

```bash
make
```

### 3. run final generated executable

```bash
./calculatorApp
```

## generated files descreption

### `build/`

- `calculatorApp`: final target executable

- `Makefile`: makefile to generate final target

- `Src/`: directory that includes generated library related files

### `build/Src`

- `Makefile`: makefile to generate static library
 
- `liboperation.a`: static library 

