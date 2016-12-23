#Instrucciones

copiar el archivo .config en la carpeta fuente del kernel

	cp /boot/config-`uname -r` /usr/src/linux-`uname -r`/.config.

Examinar el archivo Makefile el cual empezará como sigue:

	
VERSION = 2
PATCHLEVEL = 6
SUBLEVEL = 5
EXTRAVERSION = -1.358custom
...
	

copiar el Makefile del kernel que está en un backup 

	cp /lib/modules/`uname -r`/build/Makefile /usr/src/linux-`uname -r`

la version se encuentra:
	/usr/src/linux-2.6.x/include/linux/version.h

acorde al archivo:
	/lib/modules/2.6.x/build/include/linux/version.h

Para compilar usar make, se puede interrumpir la operacion con CTRL-C.

