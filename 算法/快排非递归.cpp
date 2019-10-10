int   coreQuickSort(vector<int>& vec, int left, int right)
{

	int key = vec[left];

	while (left < right)
	{

		while (left<right && vec[right]>key) { right--; }

		if (left < right)
		{
			vec[left] = vec[right];
			left++;
		}
		while (left < right && vec[left] < key) { left++; }

		if (left < right)
		{
			vec[right] = vec[left];
			right--;
		}
		
	}
	vec[left] = key;
	return left;                  //要返回index给主程序判断
}

	void  noRecursionQuickSort(vector<int> vec,int left,int right)
	{
		stack<int> stac;
		stac.push(left);
		stac.push(right);

		while (!stac.empty())
		{
			int right= stac.top();
			stac.pop();
			int left = stac.top();
			stac.pop();
			int index = coreQuickSort(vec,left,right);
			if ((index-1)>left)
			{
				stac.push(left);
				stac.push(index - 1);
			}
			if ((index +1 )<right)       //如不满足条件，则应该是已经有序的了
			{
				stac.push(index+1);
				stac.push(right);
			}

		}
	
	
	}
