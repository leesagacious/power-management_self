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
};
