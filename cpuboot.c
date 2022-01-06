#include cpuboot.h

/*
 * 在Linux kernel中, 存储cpu 热插拔状态机使用的是一个数组 cpuhp_ho_states[].
 * 这里使用链表来代替它, 虽然性能上较为数组有所下降.
 */
static LIST_HEAD(cpu_hotplug_order);  // cpu热插拔步骤链表

/*
 * cpu 热插拔线程实现.
 */
static int cpu_hp_thread_fn(void *data)
{
    for (;;) {
        
        if (kthread_should_stop()) {
            
            return 0;
        }
    }
        
}

int cpuboot_generate_percpu_kthread(struct cpu_hotplug_kthread *hp_kthread)
{
    unsigned int cpu;
    struct task_struct *cpu_kthread;
  
    mutex_lock(&cpuboot_hp_kthread_lock);
    
    for_each_online_cpu(cpu) {        // 为每个online cpu 创建热插拔内核线程
        /*
         * 在 unsigned int cpu 上创建内核线程.
         */
        cpu_kthread = kthread_create_on_cpu(cpu_hp_thread_fn, NULL,
                        cpu, hp_kthread->kthread_name);
        if (IS_ERR(cpu_kthread))
            return PTR_ERR(cpu_kthread);
    }
  
    list_add(&hp_kthread->list, &hp_kthread_list);  // 添加到全局链表 hp_kthread_list 上
    
    mutex_unlock(&cpuboot_hp_kthread_lock);
}
