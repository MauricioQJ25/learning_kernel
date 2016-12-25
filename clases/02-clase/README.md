REPASO%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
#Compilacion de KERNEL

Si se modifica manualmente el .config

	make prepare //verifica que las opciones son validas sanity check

finalizan en y, imagen estatica del kernel bzimage
finalizan en m, va a ser un modulo

CONFIG_DF=y
CONFIG_SD=m
CONFIG_SE=3 

terminan en m son modulos

-----------------------------------

dato: NetBSD tiene toolkit para compilar en una tostadora

El Kernel Soporta 4 millones teoricamente

cat /proc/sys/kernel/pid_max

sudo sysctl -w kernel.pid_max=32768

-------------------------------------
INICIO_DE_CLASE%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
#Los Procesos

Segmentos Text: 
segmento de codigo que se asigna a un programa en ejecucion
variables globales
subrutinas, interrupciones, llamadas locales.


#Descriptor del proceso
struck task struck
identificadores, permisos, un monton de cosas

#thread info y taskstruck diferencia
El thread info maneja el estado y estadisticas del proceso corriendo,
se accede al proceso en ejecucion, el proceso anterior, guarda en un registro del procesador, o al final de la memoria mapeada



