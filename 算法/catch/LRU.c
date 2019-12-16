#include "stdio.h"
#include "stdlib.h"

#define OK 1
#define ERROR 0
#define OVERFLOW -1

typedef int status;
typedef int ELemType;
typedef status (*fp) (ELemType, ELemType);

// 缓存页面结点,用链表表示
typedef struct LNode
{
	ELemType data;
	struct LNode *next;
}LNode,*LinkList;

// 缓存页面
typedef struct 
{
	int num;// 允许的缓存数
	int total;// 当前缓存数
	struct LNode *Elem;
}cache;

status CreateCache(cache &C);
status AddLNode_C(cache &C,ELemType e);
status Locate_C(cache &C,ELemType e,fp compare);
void ShowLink(cache c);
status equal(ELemType a,ELemType b);

// 初始化LRU算法
status CreateCache(cache &C){
	int i;
	// 输入页面缓存个数
	printf("please input num:");
	scanf("%d",&i);
	if(i<1) return ERROR;
	C.num=i;
	C.total=0;
	C.Elem=NULL;
	return OK;
}

// 并查看当前内存个数是否大于可存放个数,大于则删除最后元素,最后增加新元素到第一节点,
status AddLNode_C(cache &C,ELemType e){
	LNode *p,*q;
	// 把新结点放到开头
	p=(LinkList)malloc(sizeof(LNode));
	if(!p) exit(OVERFLOW);
	p->next=C.Elem;
	p->data=e;
	C.Elem=p;
	if(C.total==C.num){
		q=C.Elem;
		// 寻找最后一个结点
		while(q->next){
			p=q;
			q=q->next;
		}
		p->next=NULL;
		printf("删除了缓存页面尾部的结点\n");
		free(q);
	}else{
		C.total++;
	}
	printf("在缓存页面头部新增页面结点\n");
	return OK;
}

// 遍历缓存C查找是否有元素e,有则放到第一个结点,没有则返回错误
status Locate_C(cache &C,ELemType e,fp compare){
	LNode *p,*q;
	q=C.Elem;
	p=C.Elem;
	// 不断遍历元素去寻找符合compare关系的元素
	while(p!=NULL){
		if(compare(p->data,e)){
			// 不是头结点,则需要移动到头结点
			if(q!=p){
				// 连接断点
				q->next=p->next;
				// 把p移到头结点前面,并把缓存记录的结点记录一下
				p->next=C.Elem;
				C.Elem=p;
			}
			printf("在原有的缓存页面里面找到了要使用的页面\n");
			return OK;
		}
		q=p;
		p=p->next;
	}
	printf("在原缓存里面没有找到要使用的页面\n");
	return ERROR;
}
void ShowLink(cache c){
	LinkList p;
	p=c.Elem;
	while(p!=NULL){
		printf("%d\n",p->data);
		p=p->next;
	}
}

// 判断两个缓存页面是否相同
status equal(ELemType a,ELemType b){
	return a==b?OK:ERROR;
}

int main(int argc, char const *argv[])
{
	// 测试缓存页面队列,不同数字代表不同的缓存页面
	ELemType a[] = { 1,2,3,4,2,1,5,6,2,1,2,3,7,6,3,2,1,2,3,6};
	int count = sizeof(a)/sizeof(a[0]);
	int i, j=0;
	cache C;
	CreateCache(C);
	for(i = 0; i < count;i++){
		if(!Locate_C(C,a[i],equal)){
			AddLNode_C(C,a[i]);
			j++;
		}
	}
	printf("页面置换次数%d\n",j);
	return 0;
}