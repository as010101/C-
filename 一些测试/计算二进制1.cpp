int version3(int a)
{
	int count = 0;
	while (a)
	{
		a &= a - 1;
		count++;
	}
	return count;
}

int version2(int a)
{
	int count = 0;
	while (a)
	{
		count += (a & 0x00000001);
		a >>= 1;
	}
	return count;
}


int main()
{
	int b=version3(8);//1001

	int c=version2(9);//1001

	return 0;
}
