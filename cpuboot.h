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
    * 每一位表示一种状态. 扩展状态的范围
    */
    unsigned long long cur_state;                 // 当前cpu 热插拔状态
    unsigned long long tar_state;                 // 目标cpu 热插拔状态
    
   /*
    *  这个变量用于来判断在cpu 状态从 offline 到 online的过程中,
    *  是否需要 启用 AP 线程来进行操作
    *  这里不使用原生的 bool should_run 来进行判断.
    */
    unsigned int run_ap_thread;
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

/*
 * 状态跃迁/回落的状态机步骤
 */
struct cpu_machine_step {
    const char *name;
   /*
    *   状态跃迁时回调callback     
    */
    int (*bringup)(unsigned int cpu);
   /*
    *   状态回落时回调callback
    */
    int (*teardown)(unsigned int cpu);
};

