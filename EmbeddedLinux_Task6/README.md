# Embedded Linux Task 6

## the usage of `/dev/loop`

it is used to emulate the existence of a HW device when it is only a virtual image. Mainly used with emulation of block devices using regular files.

## Steps for creating a virtual sd-card

1. creating an sd card image of size *1GB* & formatting it

```bash
dd if=/dev/zero of=sd.img bs=2M count=500
```

using `du` to check created img size 

```bash
du -sh sd.img
```

2. configuring partitions

```bash
cfdisk sd.img
```

- select `dos`

- choose `New` to create new partition
- define size to be `200MB` and `primary` section
- raise `Bootable` flag and choose `Type` as `FAT16`
- choose `write` to apply changes

- repeat steps for `EXT4` partition * called `Linux` * for `rootfs` 
- partition will not be `bootable` and will be selected as `extended`


3. use `loop` to emulate image as a HW device

```bash
sudo losetup -f --partscan sd.img
```

device is found in `/dev` as `loop16` with its 2 partitions as `loop16p1` and `loop16p2`

to release device 

```bash
sudo losetup -d /dev/loop16 
```

4. formatting partitions 

- for the `FAT` partition *boot*

```bash
sudo mkfs.vfat -F 16 -n boot /dev/loop16p1
```

- for the `EXT4` partition *rootfs*

```bash
sudo mkfs.ext4 -L rootfs /dev/loop16p2
```

5. open `file explorer`

`boot` and `rootfs` partitions are listed as device that can be mounted and unmounted


