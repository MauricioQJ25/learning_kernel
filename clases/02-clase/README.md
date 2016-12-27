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

#Planificador de Procesos
analogia del mesero ciego.

CFS-Complety Fair Schedule

El kernel no sabe que recurso pide el usuario.

2 categorias. 
	Procesos dependientes de I/O
	Procesos dependientes de cpu

El I/O, espera input del teclado. estado de wait.
task switches, deja de usar el proceso

El kernel no sabe que es vi, lo sabe a través de 
Descriptor de proceso.

Un proceso que solo usa cpu, no espera la entrada de 
alguna informacion, sino que está procesando.

Preferencia de los procesos de I/O

#Prioridad de Procesos

-20 a 19, 0 por omision

los negativos con mayor prioridad.

los procesos con la misma prioridad se ejecutan enmodo 
round-robin

se puede observar con ps -el

comando nice

time -n19 find .

ps -el

ejemplos, writeback prioridad -20, khugepaged 19
malloc- función lenta y dormilona, reserva memoria
si no se encuentra dentro del caché de procesador,
tomar grandes cantidades de memoria.
transferencia de memoria principal a cache es lenta.

fragmentacion de un archivo
las partes quedan en memoria principal y memoria
secundaria.

hablando de discos duros.

Comportamiento impredecible de archivos.

busca el archivo y lo cambia.

varios spins, para leer el disco vueltas.


planificador de tiempo real de 0 a 99,
planificador estandar

ps -eo state, uid, pi, ppid, r
tprio,time, comm

watchdog, temporizador de interrupcion por hardware.

asignar 

#Timeslice, quantum, pedazos de tiempo

muy largo es lento
muy corto desperdicio de tiempo

el planificador necesita de tiempo de procesador.

CFS, no tiene un timeslice duro, sino que asigna
un quantum proporcional.

nice de -20 a 19, es proporcional

#Politica de planificación

#Algoritmo de Planificacion

clases: standar o de tiempo real.

costo al hace los cambios de contexto, volcados y
restaruracion de estados, actualizacion de contadores.

CFS, selecciona el procesos que menos tiempo ha estado
en ejecucion.

cuantum dinamico con base en la cantidad de procesos.

granularidad minima.

man nice

#Implementacion en linux

kernel/fair/sched.c

que es un tick

interrupcion que hace el timer de la computadora
18.6 por segundo.

un mecanismo de medicion del tiempo.

#Estructura de Entidad de Planificador.

struc sched_entity{
	u64	vruntime;
}

está dentro del task_struck

#vruntime, Virtual Runtime

vruntime almacena tiempo de ejecucion virtual
update_curr() hace todo esto,que si la hora.
calcula el tiempo de ejecucion del proceso en turno
guarda el valor en delta_exec.
update_curr()

##arbol rojinegro  
arbol rojinegro, algoritmo de busqueda
autobalanceable, a la izquierda del arbol es
el proceso sig a ejecutarse, mas bajo

siempre hay algo en el procesador: idle ocioso

#Procesos en el arbol

rbtree 

Los procesos nuevos son los primeros que entran en
el procesador. vruntime=0;

_enqueue_entity();
rb_link_node():

rb_erase();

#Punto de entrada del planificador

schedule();

kernel/sched/core.c

que son estas funciones
likely
unlikely

diferencia entre macros y funciones

son macros del compilador gcc

las condiciones sean mas rapidas

probabilidades. predice un valor.


pick_next_task();

la primera clase que regresa un puntero es la que tiene prioridad de ejecucion.

mas informacion en Documentation/scheduler/sched-design-cfs.c

#Dormir procesos

esperando semaforo

varias colas de espera, porque es conveniente.

por Prioridades. esperando una interrupcion.

wait_queue_head_t.
DECLARE_WAITQUEUE();
init_waitqueue_head();
dos colas de espera para eventos diferentes
importatante desbloquear, bloqueo muerto.

//hasta aqui se quedó!!!
#Despertar procesos

#Cambios de Contexto

En la Rasp, las herramientas en el proyecto final
compilación cruzada en el bicho y que funcione


Un hilo de kernel, que use module.h
kthread.h
sched.h encontrar funciones para un printk se duerma
para que se despierte y se vuelva a dormir.

ps -ef se encuentra en memoria al momento de cargar
el hilo de kernel se descarga de la cola de ejecucion


























































































































































































































