/*
 *	thread-1.c
 *	A sample kernel thread
 */
#include <linux/init.h>		/*	Needed for init	*/
#include <linux/module.h>	/*	Needed for every module */
#include <linux/kernel.h>	/*	Needed for printk()	*/
#include <linux/kthread.h> 	/*	Needed for kthread	*/
#include <linux/sched.h>	/*	Needed for sched	*/

#define DRIVER_LIC		"GPL"
#define DRIVER_AUTHOR 	"Mauricio <mau@mau.org>"
#define DRIVER_DESC		"A sample kernel thread"

MODULE_LICENSE 		(DRIVER_LIC);
MODULE_AUTHOR 		(DRIVER_AUTHOR);
MODULE_DESCRIPTION	(DRIVER_DESC);

struct task_struct *khilo;
/*
 *	This function is running for kernel thread
 *	return value:
 *	It's return id
 */

int hilo_kernel(void *data)
{
	int id = *(int *)data;

	printk(KERN_INFO "thread running with id: %d...\n", id);
	while(!kthread_should_stop())/*End the kthread when kthread_stop is called*/
	{
		schedule(); /* bloking kthread by preestablished timeslice */
		//ssleep(2);	/* bloking kthread by *2* seconds */
	}
   return id;
}


/*
 *	The kthread function make and wake up a thread, it puts running.
 *	Exec a kthread_create() following a wake_up_process()
 *	Return value:
 *		return kernel thread or
 *		ERR_PTR(-ENOMEM )
 */

static int __init kernel_init(void)
{
	static int id_thread = 10;

	printk(KERN_INFO "-----------------------------------------------");
	khilo = kthread_run(hilo_kernel, (void *)&id_thread, "Mau's_thread" );

	if( IS_ERR(khilo))
	{
		printk("Error in kthread creation...\n");
		return PTR_ERR(khilo);
	}
	printk(KERN_INFO "kthread created: %s with PID %d \n", khilo->comm, khilo->pid);

	return 0;
}

/*
 *	The function kthread_stop realize the following below:
 *	1.- Active kthread->kthread_should_stop = true
 *	2.- Wake up a thread
 *	3.-	Wait until a thread ends.
 *	4.-	Return value:
 *			return  the result of hilo_kernel  or
 *			-EINTR if the function wake_up_process() is not called
 */

static void __exit kernel_exit(void)
{
	int ret_hilo_kernel = kthread_stop( khilo );

	if( ret_hilo_kernel == -EINTR )
		printk(KERN_INFO "Error in the kthred's end");
	else
		printk(KERN_INFO "kthread with id: %d stopped\n", ret_hilo_kernel);
}

module_init(kernel_init);
module_exit(kernel_exit);