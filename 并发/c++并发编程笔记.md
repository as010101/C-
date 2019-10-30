- 多进程并发 多线程并发<br>

- 共享数据会带来问题，以双向链表举例

- 使用互斥量保护共享数据，可能带来死锁  一种解决办法就是让两个互斥量总以相同的顺序上锁：总在互斥量B之前锁住互斥量A，就永远不会死锁，另一种方式是
lock()同时锁住两个变量，然后将锁住的转给lock_guard(std::adopt_lock是参数)

- unique_lock 允许何时、及如何锁定互斥量

- 保护共享变量的替代措施  可以用std::call_once来处理这种情况

- 单例模式中使用双检查锁的问题，在new的时候分为三步( 1分配内存 2初始化对象 3赋值指针  有可能1 3先执行，发生一些意外的事情)

- 内存模型

  顺序一致性主要约定了两件事情：
（1）从单个线程的角度来看，每个线程内部的指令都是按照程序规定的顺序（program order）来执行的；
（2）从整个多线程程序的角度来看，整个多线程程序的执行顺序是按照某种交错顺序来执行的，且是全局一致的


  atomic类函数参数：Store操作 Load操作  Read-modify-write(读-改-写)操作    所有操作的默认顺序都是memory_order_seq_cst
  首先以std::atom_flag为例，该值需要初始化为ATOMIC_FLAG_INIT（清除）
  
  当你的标志对象已初始化，那么你只能做三件事情：销毁，清除或设置(查询之前的值)。这些事情对应的函数分别是：clear()成员函数，和test_and_set()成员函数。clear()和test_and_set()成员函数可以指定好内存顺序。clear()是一个存储操作，所以不能有memory_order_acquire或memory_order_acq_rel语义，但是test_and_set()是一个“读-改-写”操作，所有可以应用于任何内存顺序标签


atomic不接受拷贝和赋值，因为这样的操作会破坏原子性


  acquire release ordering对顺序性的约束程度介于sequential consistency（顺序一致性）和relaxed ordering之间，因为它不要求全局一致性，但是具有        synchronized with的关系。Relaxed ordering最弱，因为它对顺序性不做任何要求。由此可见，除非非常必要，我们一般不建议使用relaxed ordering，因为这不    能保证任何顺序性
  
  
  



