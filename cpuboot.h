/*
 * cpu 可插拔线程描述符
 */
struct cpu_hotplug_kthread {
    void (*gener_kthread) (unsigned int cpu); // 为每个onine cpu生成对应的 kthread.
 
    struct list_head  list;                   // 链接到全局链表上.
};
