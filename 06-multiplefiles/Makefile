obj-m += startstop.o
startstop-objs := start.o stop.o
#obj-m += startstop.o

#startstop.o: start.o stop.o 

all:
	make -C /lib/modules/$(shell uname -r)/build M=$(PWM) modules

clean:
	make -C /lib/modules/$(shell uname -r)/build M=$(PWM) clean



