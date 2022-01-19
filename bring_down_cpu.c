#include "cpuboot.h"
/*
 *    #func . 把 cpu id 为 cpu的状态 唤醒到热插拔 target_state 状态.
 *    @cpu . 要操作的cpu id
 *    @target_state . 把cpu 唤醒到 热插拔的状态
 */
static int bring_cpu(unsigned int cpu, unsigned int 
            target_state)
{
    int ret = 0;
    
   /*
    *  如果 cpu的hp状态已经大于或者等于了所要唤醒的状态
    *  那么执行该函数后续的唤醒状态操作是无用的.
    */
    if ()
      
    
  
    return ret;
}

/*
 *  唤醒内核线程来处理cpu的状态迁移.
 */
static void wake_up_ap_thread(struct cpu_hotplug_state  *chs)
{
   /*
    *  唤醒在系统启动时已经创建好的内核线程.
    *  当cpu热插拔状态处于该线程管理的范围内的话.
    */        
    wake_up_process(chs->cpu_hp_kthread);
   
   /*
    *  等待该内核线程执行完各个状态的callback.
    */        
    wait_for_completion(chs->bringup_comp);
}
