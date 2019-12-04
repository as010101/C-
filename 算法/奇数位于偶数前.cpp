using namespace std;
//遍历一次数据，第一次遇见奇数，将其与位置1交换，  第二次遇见奇数，将其与位置2交换，依次向后推，如果第一个是奇数。。感觉对全奇数大数据不太友好  
//函数对象
template<class T>
struct IsOdd
{                         
	bool operator() (T x) {  //此处的括号虽然用了两个括号来重载，但是使用是用一个 （a）                
		return (x & 1) ? true : false;
	}
};
//函数功能 ： 调整数组顺序使奇数位于偶数前面  
//函数参数 ： pArray指向数组的指针，nLen为数组长度  
//返回值 ：   无  
template <class T, class F>
void PartionArray(T* pArray, int nLen, F func)
{
	int i = -1;
	for (int j = 0; j < nLen; j++)
	{
		if (func(pArray[j])) //满足调整条件                      此处temp是
		{
			i++;
			T tmp = pArray[j];
			pArray[j] = pArray[i];
			pArray[i] = tmp;
		}
	}
}
//测试用例
int main()
{
	short a[] = { 1,1,1,4,5,6 };
	long b[] = { 1,2,3,4,5,6 };
	PartionArray(a, 6, IsOdd<short>());    //实例化模板，函数对象作为参数传入和调用处应该是有别的，传入处只加()，调用处要加参数（i）
						//即实例化一个对象作为参数，在调用处以该对象作为变量加上（i）进行operator()调用
	PartionArray(b, 6, IsOdd<long>());
	return 0;
}
