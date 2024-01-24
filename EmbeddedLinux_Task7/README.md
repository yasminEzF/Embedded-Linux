# Embedded Linux Task 7

## Question

how u-boot application communicates with hardware if its compiled using the cross compiler that generates system calls if no kernel is loaded yet?

u-boot is an OS with a shrink kernel image for handling its system calls until it loads main kernel image which is also why u-boot needs .dtb file to know HW 

## Task steps

### configuring u-boot 

clone repo and checkout to `v2022.07` 
list available default configurations

```bash
ls configs/
``` 

load default configuration for vexpress machine

```bash
make vexpress_ca9x4_defconfig
```

changed configurations summary
- autoboot = 5 seconds
- bootcmd = echo haiii
- shell prompt = `~('-')~ => ` 
- bdinfo
- bootd
- run
- editenv
- saveenv
- md, mm, nm, ...
- meminfo
- lsblk
- echo
- source
- tftpboot
- support FAT
- not flash
- not MMC (vexpress doesn't have mounted memory)
- device & partitions to store env in FAT
- no EXT4

define cross compiler path (exclude `gcc`) and architecture

```bash
export CROSS_COMPILE=~/x-tools/arm-cortexa9_neon-linux-musleabihf/bin/arm-cortexa9_neon-linux-musleabihf-
export ARCH=arm
```

congratulations, now make
```bash
make
```

### running qemu 

machine name, sd image, u-boot path on local machine, no GUI
sd.img needs to be 1024M not 1000 for qemu to work

```bash
qemu-system-arm -machine vexpress-a9 -sd ~/bootloader/sd.img -kernel ~/u-boot/u-boot -nographic
```

![Screenshot from 2024-01-24 11-30-57](https://github.com/yasminEzF/Embedded-Linux/assets/109252157/7b298b95-47a0-4d16-84c0-0af7da79083a)

### loading file from FAT to RAM

viewing files on FAT partition

```bash
ls mmc 0:1
```
`mmc`: interface 
`0`: block 0
`1`: partition
![Screenshot from 2024-01-24 11-32-07](https://github.com/yasminEzF/Embedded-Linux/assets/109252157/7f141e53-7438-40ad-8c19-245260903dc4)


```bash
fatload mmc 0:1 0x60000000 binarySearch.elf
```

using `md` to display memory before and after loading

```bash
md 0x60000000
```

![Screenshot from 2024-01-24 11-35-58](https://github.com/yasminEzF/Embedded-Linux/assets/109252157/c44c51ae-776f-40b3-8bff-dba27a86fad5)

### for autoload without reconfiguring and building

editing `bootcmd` variable to store `fatload` command to run through autoboot

```bash
setenv bootcmd "echo haiii; fatload mmc 0:1 0x60000000 binarySearch.elf
saveenv
```

![Screenshot from 2024-01-24 11-41-33](https://github.com/yasminEzF/Embedded-Linux/assets/109252157/a10f45fa-b027-4639-a0f1-13a0cc4744a8)

restarting qemu for autoboot to load the file automatically

![Screenshot from 2024-01-24 12-08-26](https://github.com/yasminEzF/Embedded-Linux/assets/109252157/b976774e-056d-466b-8a72-d98581950dfd)


