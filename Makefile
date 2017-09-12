ifneq ($(KERNELRELEASE),)
# kbuild part of makefile
ccflags-y += -I./inc/hello1.h
hello2.o: inc/hello1.h
obj-m  := hello1.o  hello2.o
else
# normal makefile
KDIR ?= /lib/modules/`uname -r`/build

default:
	$(MAKE) -C $(KDIR) M=$$PWD
clean:
	$(MAKE) -C $(KDIR) M=$$PWD clean
endif