#include "stdio.h"
#include "stdlib.h"

#define OK 1
#define ERROR 0
#define OVERFLOW -1

typedef int status;
typedef int ElemType;

typedef struct {
	ElemType data;
	int nums;
}Node;

typedef struct 
{
	Node *base;
	int length;
	int listsize;
}Cache;

status InitCache(Cache &L);
status ListInsert_Sq(Cache &L , int i, ElemType e);
status Push(Cache &L ,  ElemType e);
status Pop(Cache &L);
status EQ(ElemType a,ElemType b);
status LT(ElemType a,ElemType b);
status ShowCache(Cache L);
int LocateCache_nums(Cache L,ElemType e);
int LocateCache_data(Cache L,ElemType e);
status start(Cache &L , ElemType e);



int main(int argc, char const *argv[])
{
	Cache L;
	int arr[] = { 1,2,3,4,2,1,5,6,2,1,2,3,7,6,3,2,1,2,3,6};
	int count;
	int i;
	count = sizeof(arr)/sizeof(int);
	InitCache(L);
	for(i=0;i<count;i++){
		printf("-----%d\n",i+1);
		start(L,arr[i]);
		ShowCache(L);
	}
	return 0;
}


status InitCache(Cache &L){
	if(!L.base) exit(OVERFLOW);
	printf("please input cache nums:");
	scanf("%d",&L.listsize);
	L.base = (Node*)malloc(sizeof(Node)*L.listsize);
	L.length = 0;
	return OK;
}
/**
 * 1.先查找是否在缓存里面
 * 2.在找出位置，返回位置数
 * 3.然后查出的相同次数缓存的第一个位置
 * 4.把缓存调到该位置的前一个。：1.取出该元素，2该元素的原来位置到第一个元素的位置之间元素向后移一位，插入元素到第一个位置
 * 5.不在则判断是否已满
 * 6.不满直接插入元素到最后位置，否则删除最后元素，然后插入元素
 * @param  L [description]
 * @param  e [description]
 * @return   [description]
 */
status start(Cache &L , ElemType e){
	int site,nums,firstElem,temp;
	Node p;
	// 查找有该元素
	if((site=LocateCache_data(L,e))!=-1){
		nums = L.base[site].nums;
		firstElem = LocateCache_nums(L,nums);
		printf("%d %d\n",nums,firstElem );
		p = L.base[site];
		// 把顺序表的结点一个个向后移一位
		for(temp=firstElem;temp<site;temp++){
			L.base[temp+1] = L.base[temp];
			printf("fuckfuck\n");
		}
		// 顺序表该增加调用的改为第一个
		L.base[firstElem] = p;
		L.base[firstElem].nums++;
	}else{
		// 没有该元素，直接删除最后一位，增加新的元素
		if(L.length==L.listsize)
			Pop(L);
		Push(L,e);
	}
}


// 查找第一个出现的对应元素，折半查找元素（根据使用次数）
int LocateCache_nums(Cache L,int nums){
	int low,high,mid;
	low = L.length-1;
	high = 0;
	// printf("%d\n", mid);exit(-1);
	while(low >= high){
		mid = (high+low)/2;
		if(EQ(L.base[mid].nums,nums)){
			// 如果出现了相同的次数，查找第一个出现的次数
			while(mid!=0){
				// 查找前一个元素是否符合次数
				if(!EQ(L.base[--mid].nums,nums)){
					mid++;
					break;
				}
			}
			return mid;
		}else {
			if(LT(L.base[mid].nums,nums)) low = mid-1;
			else high = mid+1;
		}
	}
	return -1;
}

// 查找元素
int LocateCache_data(Cache L,ElemType e){
	int i=0;
	// 设置哨兵
	L.base[L.length].data = e;
	for(;!EQ(L.base[i].data,e);i++);
	if(i==L.length) return -1;
	else return i;
}

// 在尾部插入元素，调用次数为1
status Push(Cache &L , ElemType e){
	Node *p;
	if(L.length>=L.listsize) return ERROR;
	p = (Node*)malloc(sizeof(Node));
	p->data = e;
	p->nums = 1;
	L.base[L.length] = *p;
	L.length++;
}

// 删除尾部元素
status Pop(Cache &L){
	if(L.length<1) return ERROR;
	L.length--;
}

status ShowCache(Cache L){
	int i=0;
	while(i<L.length){
		printf("cache Id nums:%d %d\n",L.base[i].data,L.base[i].nums);
		i++;
	}	
}

status EQ(ElemType a,ElemType b){
	return a==b?OK:ERROR;
}
status LT(ElemType a,ElemType b){
	return a<b?OK:ERROR;
}