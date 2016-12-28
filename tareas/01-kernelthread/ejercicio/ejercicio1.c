/*
 *	Ejercicio1.c - Un hilo simple de kernel
 */

#include <linux/module.h>
#include <linux/init.h>
#include <linux/kernel.h>
#include <linux/sched.h>
#include <linux/kthread.h>
#include <linux/delay.h>

#define DRIVER_AUTHOR 	"Mauricio <mau@mau.org>"
#define DRIVER_DESC		"A simple kernel thread"
#define DRIVER_LIC 		"GPL"

MODULE_LICENSE 		(DRIVER_LIC);
MODULE_AUTHOR		(DRIVER_AUTHOR);
MODULE_DESCRIPTION 	(DRIVER_DESC);

struct task_struct *kmauhilo;


int kernelfuncion(void *data){
	int id = *(int *)data;
	int counter = 0;
	printk(KERN_INFO "Hilo en ejecucion con id: %d...\n", id);
    while(!kthread_should_stop())
    {
    	//schedule();
    	printk(KERN_INFO "Sigo en ejecucion jujuju! conter: %d\n", counter);
        counter++;
    	msleep(2000);
    }


    return id;
}


static int __init kernel_init(void){
	static int id_thread = 99;
	printk(KERN_INFO "----Un simple hilo de kernel---\n");
	kmauhilo = kthread_run(kernelfuncion, (void *)&id_thread, "Mau_hilo_kernel");
	
	if(IS_ERR(kmauhilo))
	{
		printk("Error en la creacion del hilo\n");
		return PTR_ERR(kmauhilo);
	}
	printk( KERN_INFO"Hilo de kernel crado %s con PID %d\n",kmauhilo->comm, kmauhilo->pid);
	return 0;
}

static void __exit kernel_exit(void){
	int valor_retorno_hilo= kthread_stop(kmauhilo);
	if(valor_retorno_hilo == -EINTR)
		printk (KERN_INFO "Error en la terminacion del hilo\n");
	else
		printk(KERN_INFO "Hilo de kernel con id: %d detenido\n", valor_retorno_hilo);
	printk(KERN_INFO "saliendo del kernel\n");
}

module_init(kernel_init);
module_exit(kernel_exit);