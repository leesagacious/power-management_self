#include <linux/completion.h>

/*
 * cpu 可插拔线程描述符
 */
struct cpu_hotplug_kthread {
    const char *kthread_name;
    void (*gener_kthread) (unsigned int cpu); // 为每个onine cpu生成对应的 kthread.
 
    struct list_head  list;                   // 链接到全局链表上.
};

struct cpu_hotplug_state {
   /*
    * 这里不使用枚举来表示cpu 热插拔的状态.
    */
    unsigned int cur_state;                 // 当前cpu 热插拔状态
    unsigned int tar_state;                 // 目标cpu 热插拔状态
   /*
    * cpu 从 offline 状态迁移到 online 状态时 唤醒 cpu 热插拔线程用的完成量.
    */
    struct completion bringup_comp;
   /*
    * cpu_hotplug_state 持有 cpu 热插拔线程.
    * 这样的用意是可以根据 state 来唤醒该线程做一些callback操作.
    */
    struct task_struct *cpu_hp_kthread;     // 指向cpu 热插拔线程 
};
