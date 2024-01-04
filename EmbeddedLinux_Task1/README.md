# Task 1 Embedded Linux
## comparison between static and dynamic linking
### using **ldd** command
- static
- dynamic
### using **file** command
- static
- dynamic
### using **objdump** command
- static
- dynamic

---

## Static
### Compilation steps taken
#### 1. compile library source files 
``` gcc -c src/*.c -I headers/ ```
#### 2. create static library
``` ar -rcs liboperation.a *.o ```
#### 3. compile and link application with library statically 
``` gcc main.c -L ./src/ -I ./headers/ -loperation -static -o staticMain.elf	```


## Dynamic
### Compilation steps taken
#### 1. compile library source files 
``` gcc -c -fPIC src/*.c -I headers/ ```
#### 2. create shared library
``` gcc -shared -o liboperation.so *.o ```
#### 3. compile and link application with library dynamically 
``` gcc main.c -L ./src/ -loperation -shared -o dynamicMain.elf -Wl,-rpath=./src	```



## inquiries for later
added headers to /usr/include
added .a and .so to usr/lib
not in env path 
appended
still can't linkkkk

