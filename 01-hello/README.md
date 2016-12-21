#Construcción de un simple módulo de  kernel

Para construir un hilo simple se tienen basicamente 2 funciones:

	int init_module(void); //lo que realiza el hilo exito = 0
	void cleanup_module(void); //lo que realiza al quitar el hilo

Requiere de la función 
	printk(KERN_INFO "hola mundo!1\n"); //funciona como printf pero con 
					    //una prioridad <4>

Las cabeceras del sistema son
	#include <linux/module.h>
	#include <linux/kernel.h>

Todo se registra en la bitácora del sistema
	dmesg o en /var/log/syslog
	Insertamos el módulo con insmod y lo retiramos con rmmod
	la lista de modulos se puede ver con lsmod

[Fuentes](http://www.tldp.org/LDP/lkmpg/2.6/html/lkmpg.html#AEN121)


Para compilar el modulo se usa el archivo Makefile

obj-m += hello-1.o

all:

	make -C /lib/modules/$(shell uname -r)/build M=$(PWD) modules

clean:
	make -C /lib/modules/$(shell uname -r)/build M=$(PWD) clea

------------------
Para limpiar ejecutar
	 make clean 

Para ver información del modulo ejecutar
	modinfo modulo.ko













