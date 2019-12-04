typedef struct ListNode
{
	int data;
	ListNode * next;

};

void fun(ListNode* node)
{
	if (node == nullptr || node->next == nullptr)
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
	phead->next = nullptr;
	phead->data = 0;
	for(int i = 0; i < 10; i++)
	{
		ListNode* p=(ListNode *)malloc(sizeof(ListNode*));
		p->data = i;
		p->next = phead->next;  //头插     5 4 3 2  1  0
		phead->next = p;
}
	fun(phead);

	while (phead!= nullptr)
	
	{

		cout << phead->data;
		phead = phead->next;

	}

	int c = 0;
	cin >> c;

}
// 1234567890  09876543210
