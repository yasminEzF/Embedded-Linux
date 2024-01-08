
add_Library(operation STATIC add.c div.c mod.c mul.c sub.c)

target_include_directories(operation INTERFACE ${CMAKE_HOME_DIRECTORY}/Inc)


