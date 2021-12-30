#include <linux/init.h>
#include <linux/module.h>
#include <linux/printk.h>
#include <linux/moduleparam.h>
#include <linux/ktime.h>
#include <linux/slab.h>

MODULE_AUTHOR("Snychenkov Daniil <danilka1231231232144423523432@gmail.com>");
MODULE_DESCRIPTION("Lab 5 AK");
MODULE_LICENSE("Dual BSD/GPL");

static uint amount = 1;

module_param(amount, uint, 0444);
MODULE_PARM_DESC(amount, "Amount of Hello world's");

struct my_struct 
{
    struct list_head tlist;
    ktime_t time;
};

static LIST_HEAD(my_list_head);

static int __init hello_init(void)
{

    if (amount == 0) 
    {
        printk(KERN_WARNING "The parameter is 0\n");
    } 
    else if (amount >= 5 && amount <= 10) 
    {
        printk(KERN_WARNING "The parameter is between 5 and 10\n");
    } 
    else if (amount > 10) 
    {
        printk(KERN_WARNING "The parameter is > 10)\n");
        return -EINVAL;
    }

    int i;
    for (i = 0; i < amount; i++) 
    {
        struct my_struct *ms = kmalloc(sizeof(struct my_struct), GFP_KERNEL);

        ms->time = ktime_get();
        list_add_tail(&ms->tlist, &my_list_head);

        printk(KERN_INFO "Hello, world!\n");
    }

    return 0;
}

static void __exit hello_exit(void)
{
    int count = 0;
    struct my_struct *t, *tmp;

    list_for_each_entry_safe(t, tmp, &my_list_head, tlist) 
    {
        pr_info("i: %d; ktime = %lld\n", count++, ktime_to_ns(t->time));
        list_del(&t->tlist);
        kfree(t);
    }
    
    printk(KERN_INFO "Module unloaded\n");
}

module_init(hello_init);
module_exit(hello_exit);
