CONFIG_MODULE_SIG=n  # used for avoiding module verification error/warning
obj-m = helloworld.o
all:
	make -C /lib/modules/$(shell uname -r)/build/ M=$(PWD) modules
clean:
	make -C /lib/modules/$(shell uname -r)/build M=$(PWD) clean
load:
	sudo insmod helloworld.ko
unload:
	sudo rmmod helloworld
