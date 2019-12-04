
stack1 stack2

stack1插入停止之后(即插入完成)

stack1要全部倒入stack2，而且要stack2全部pop之后才能再向stack2倒入，这样才能绝对满足队列要求
所以，在插入stack1时要检查是否为空，不为空不能push,不然里面还有残留元素就不满足队列要求了
