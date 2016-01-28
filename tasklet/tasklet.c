/*************************************************************************
	> File Name: tasklet.c
	> Author: 
	> Mail: 
	> Created Time: 2015年12月10日 星期四 21时26分59秒
 ************************************************************************/

#include<linux/module.h>
#include<linux/init.h>
#include<linux/fs.h>
#include<linux/kdev_t.h>
#include<linux/cdev.h>
#include<linux/kernel.h>
#include<linux/interrupt.h>

static struct tasklet_struct my_tasklet;

static void tasklet_handler(unsigned long data)
{
    printk(KERN_ALERT"tasklet_handler is running.%ld\n", data);
}

static int __init test_init(void)
{
    int i=0;
    tasklet_init(&my_tasklet, tasklet_handler, 0);
    while (i<10) {
        printk("%d\n",i++);
    }
    tasklet_schedule(&my_tasklet);
    return 0;
}

static void __exit test_exit(void)
{
    tasklet_kill(&my_tasklet);
    printk(KERN_ALERT"text_exit running.\n");
}

MODULE_LICENSE("GPL");

module_init(test_init);
module_exit(test_exit);
