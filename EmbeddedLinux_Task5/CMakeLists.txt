cmake_minimum_required(VERSION 3.22.1)

project(calculatorApp 
      DESCRIPTION "embedded linux task 5")

add_subdirectory(${CMAKE_HOME_DIRECTORY}/Src)

add_executable(${PROJECT_NAME} App/main.c)

target_include_directories(${PROJECT_NAME} INTERFACE ${CMAKE_HOME_DIRECTORY}/Inc)

target_Link_Libraries(${PROJECT_NAME} PRIVATE operation)
