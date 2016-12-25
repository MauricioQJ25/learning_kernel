#Compilando el kernel

Con base en el capitulo 2 del libro.

El archivo fuente se obtiene de:
	 www.kernel.org

Se descomprime el archivo

	tar xvzf archivo.tar.gz

El kernel es tipicamente instalado en /usr/src/linux

Instalar parches

	patch -pi < patch-x.y.z


Antes de compilar el kernel se necesita configurar

make config       uno por uno
make menucofig    modo grafico ncurses
make gconfig      gtk+-based graphical
make defconfig    default para la arcquitectura
make oldconfig    configuración guardada en el Kernel

Copiar la configuracion anterior

zcat /proc/config.gz > .config
 #si no aparece usar sudo modprobe configs, para visualizar
 #o en otro caso
 #cp /boot/config-`uname -r` .
make oldconfig


y por último make

-----------------------------
Minimizar el ruido 

make > ../detritus

make > /dev/null
-------------------------------
para mas rapidez

make -jn #donde j es el numero de trabajos por procesador, usualmente 2

make -j32 > /dev/null #Maquina de 16 nucleos

Para saber cuantos nucleos tiene nuestro equipo ver 

/proc/cpuinfo

--------------------------------------------
Instalando el nuevo kernel

copiar

cp arch/i386/boot/bzimage /boot/

#el nombre es algo así como: vmlinuz-version 

editar 

/boot/grub/grub.conf

/etc/lilo.conf y rerun lilo

-------------------------------------------------
Instalar modulos
make modules 

make modules_install

los instala en /lib/modules

se crea  System.map

--------------------------------
finalmente instalar el núcleo 

make install

#Resumen

bajar el kernel         wget .....   www.kernel.org
descomprimir            tar -xvfz archivo.tar.gz
entrar a la carpeta 	linux.x.y.z
generar archivo 		.config
compilar con make, o 	make -jn
compilar modulos,		make modules
instalar,               make modules_install
instalar el kernel      make install
reiniciar               reboot
verificar el Kernel     uname -r


