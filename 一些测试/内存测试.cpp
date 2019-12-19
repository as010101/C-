int main()
{
	int a = 1;
	int b = 1;

	int* k = (int*)malloc(sizeof(int) * 2);
	k[0] = 111;//111
	cout << k[0]<<endl;
	printf("%p\n", k);
	free(k);
	printf("%p", k);
	cout << k[0];//-23445243534

//free掉仍然可以访问，操作系统没有回收这片内存
	getchar();

}
