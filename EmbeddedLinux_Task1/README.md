# Task 1 Embedded Linux
## comparison between static and dynamic linking
### using **ls -lh** command

![image](https://github.com/yasminEzF/Embedded-Linux/assets/109252157/844c34c6-04a2-4b65-a577-72be979a5a33)

statically linked file is much larger than the dynamically linked file

### using ```ldd``` command

#### - static

no shared library dependecies as everything is contained in a single file

![image](https://github.com/yasminEzF/Embedded-Linux/assets/109252157/95b1f583-3764-4ea4-86b3-8664381e4f08)

#### - dynamic

shared libraries dependecies such as **libc.so** and the user-created library **liboperation.so**

![image](https://github.com/yasminEzF/Embedded-Linux/assets/109252157/bab345e7-0f1d-403a-a69c-2575433535cc)

### using ```file``` command

![image](https://github.com/yasminEzF/Embedded-Linux/assets/109252157/22e2468d-f24a-474d-bd18-0d23f0e1bab3)

#### - static

a statically linked ELF executable for x86 machine

#### - dynamic

a dynamically linked ELF executable for x86 machine

### using ```objdump``` command

#### - static
all absolute addresses because statically linked & no undefined links

    objdump staticMain.elf -t

no symbols in dynamic symbol table

    objdump staticMain.elf -T
  
![image](https://github.com/yasminEzF/Embedded-Linux/assets/109252157/db38897a-5f25-4752-979f-ecbb437ae122)
![image](https://github.com/yasminEzF/Embedded-Linux/assets/109252157/9339ad67-3962-47d0-a08f-cb25fbd4abe0)

#### - dynamic
some absolute addresses such as main.c & some are undefined such as the calculator functions 

    objdump dynamicMain.elf -t

symbols in dynamic symbol table for calculator functions

    objdump dynamicMain.elf -T

![image](https://github.com/yasminEzF/Embedded-Linux/assets/109252157/300d6e63-fdf4-4b89-ba8c-39f0348c9aee)

![image](https://github.com/yasminEzF/Embedded-Linux/assets/109252157/4433365c-21ff-4155-9da4-d114c6b11701)


---
# Notes for self (pls ignore)
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

