#include <linux/init.h>
#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/slab.h>
#include <asm/bitops.h>
#define SIZE 1

void dummy_func (void * a)
{
static int count = 0 ;

count++;
printk("Dummy called count = %d\n", count);
}

static int __init helloworld_init(void) {
//#ifdef CONFIG_NET_EMATCH_STACK
void (*func_ptr)(void *) ;
int a = 0 ;
pr_info("Hello world with CONFIG_NET_EMATCH_STACK!\n");
int bit_test;

func_ptr = dummy_func ;

bit_test = 0x10;

printk("find_first_bit(&bit_test,1) = %d\n", find_first_bit((unsigned long *)(&bit_test),3));

//struct kmem_cache * ptr2 = kmem_cache_create ("First_cache" , SIZE , 1 , SLAB_POISON ,func_ptr);

//int *ptr = kmem_cache_alloc (ptr2,GFP_KERNEL) ;

void *ptr = kzalloc(16*1024, GFP_KERNEL);

if (!ptr)
{
printk("Can't Allocate memory \n");
return 1 ;
}
printk("Ksize() = %d, count = %d\n", ksize(ptr), a);
kfree(ptr);
// kmem_cache_free(ptr2,ptr);
//kmem_cache_destroy(ptr2);
//#endif
return 0;
}
static void __exit helloworld_exit(void) {
pr_info("End of the worlds\n");
}
module_init(helloworld_init);
module_exit(helloworld_exit);
MODULE_LICENSE("GPL");
