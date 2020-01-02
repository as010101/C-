//几个问题 multimap 没有[]因为该容器是一对多
//map的key给定就不能改变，可以给multimap让其重新排序


class Solution {
public:
   string frequencySort(string s) {
	map<char, int> mp;
	
	for (int i = 0; i < s.size(); i++)
	{
		mp[s[i]]++;
	}
	multimap<int, char> mp1;
	for (auto ele : mp)
	{
		mp1.insert({ ele.second, ele.first });
	}
	
	string rs("");
	for (auto ele : mp1)
	{

		string substr(ele.first,ele.second);
		
		//string substr(&ele.first, ele.second);
		rs = substr + rs;
	}
	return rs;
}
};
