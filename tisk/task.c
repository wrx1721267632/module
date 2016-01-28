/*************************************************************************
	> File Name: task.c
	> Author: 
	> Mail: 
	> Created Time: 2015年11月24日 星期二 01时20分01秒
 ************************************************************************/

#include<linux/kernel.h>
#include<linux/module.h>
#include<linux/slab.h>
#include<linux/list.h>
#include<linux/init.h>
#include<linux/sched.h>

MODULE_LICENSE("GPL");

static int __init print_pid(void)
{
    struct task_struct *task, *p;
    struct list_head *pos;
    int count = 0;
    
    printk("hello world enter begin: \n");
    task = &init_task;
    list_for_each(pos, &task->tasks) {
        p=list_entry(pos, struct task_struct, tasks);
        count++;
        printk("%d-->%s-->", p->pid, p->comm);
	if (p->state > 0) {
		printk("stopped\n");
	} else if (p->state < 0) {
		printk("unrunnable\n");
	} else  printk("runnable\n");
    }
    printk("the number of process is: %d\n", count);
    return 0;
}

static void __exit task_exit(void)
{
    printk("END!\n");
}

module_init(print_pid);
module_exit(task_exit);
