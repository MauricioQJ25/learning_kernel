#4 Planificador de Procesos.


Este capitulo discute el planificador de proceso
El planificador de procesos discute 
que programa corre
cuando
y por cuanto tiempo
Da la ilusion de que multiples procesos se ejecutan al mismo tiempo

##Multitasking

Los sistemes operativos vienen en 2:
	cooperative multitasking
	preemtive multitasking *linux*

timeslice de un proceso

##Policy, I/O-bound versus processor-bound processes

##Process Priority

numeros desde -20 hasta +19

con default de 0

##Timeslice

CFS: complety Fair scheduler

##the scheduling policy in action


timeslice es llamado quantum 

##The linux scheduling Algorithm
###Scheduler Classes

kernel/sched.c

###Process scheduling in unix systems
