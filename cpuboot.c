#include cpuboot.h

int cpuboot_generate_percpu_kthread(struct cpu_hotplug_kthread *hp_kthread)
{
    unsigned int cpu;
  
    mutex_lock(&cpuboot_hp_kthread_lock);
    
    for_each_online_cpu(cpu) {        // 为每个online cpu 创建热插拔内核线程
        
    }
  
    mutex_unlock(&cpuboot_hp_kthread_lock);
}
