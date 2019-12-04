

typedef struct ListNode
{
	int data;
	ListNode * next;

};

void fun(ListNode* node)
{
	if (node == nullptr)
	{
		return;

	}
	fun(node->next);
	cout << node->data;

}

int main()
{
	ListNode head;
	head.data = 1000;
	head.next = nullptr;
	ListNode* phead= &head;    ///此处要么取地址，要么malloc出地址
	ListNode* q = &head;
	phead->next = nullptr;
	for(int i = 0; i < 10; i++)
	{
		ListNode* p=(ListNode *)malloc(sizeof(ListNode*));
		p->data = i;
		p->next = phead->next;  //头插     5 4 3 2  1  0
		phead->next = p;
}
	fun(phead);   //  phead是指向1000  phead的next是指向9的  不是phead指向9   phead一直是头结点
			//也可以不要头结点，每新增一个节点就是头结点
	cout << endl;
	while (phead!= nullptr)
	
	{

		cout << phead->data;
		phead = phead->next;

	}

	int c = 0;
	cin >> c;

}
// 0123456789 1000         1000 9876543210
