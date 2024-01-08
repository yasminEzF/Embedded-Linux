# Embedded Linux Task 4

## Why use a static library with AVR

AVR is used with baremetal applications as there is no OS and no **system loader** to find any missing libraries during runtime and load them to RAM then resolve their linking.

This is due to the limitation of the AVR hardware resources overall.  

## Creating `libmcal.a`

### 1. creating soft links to gcc binaries (compiler & archive) 

```bash
sudo ln -s ~/x-tools/avr/bin/avr-gcc /usr/local/bin/avr-gcc
sudo ln -s ~/x-tools/avr/bin/avr-ar /usr/local/bin/avr-ar
```

### 2. compile library source files 

```bash
avr-gcc -c Src/*.c -I Inc/
```

### 3. create static library

```bash
avr-ar --target=elf32-avr -rcs libmcal.a *.o 
```

### 4. compile and link application with library statically 

```bash
avr-gcc -mmcu=atmega32 App/main.c -L . -I ./Inc/ -lmcal -o app.elf -static
```

## Application

The application utilizes both the `port` and `dio` drivers where:

- `port` driver is responsible for initialization of pins.

- 'dio' driver is responsible for runtime functionalities which are read and write operations on pins.

An overall look of the application, it contains a pushbutton that increments a value from 0 to 15 then displays its binary equivalent on 4 LEDs.



