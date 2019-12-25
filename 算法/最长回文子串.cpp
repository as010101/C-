	
  
  maxbegin 返回字符的起始位置
  
  maxend 返回字符的串长度
  
  string longestPalindrome(string s) {

		int maxlen = 0;
		int maxbegin = 0;
		int maxend = 0;
		string str;
		for (int i = 0; i < s.size(); i++)
		{
			int begin = 0, end = 0;
			int tem = midOdd(i, s.size(), s, begin, end);
			if (tem > maxlen)
			{
				maxbegin = begin;
				maxend = end;
				maxlen = tem;

			}


		}

		string str1 = s.substr(maxbegin, maxend);

		return s.substr(maxbegin, maxend);

	}


	int midOdd(int i, int size, string str, int& maxbegin, int& maxend)

	{
		int left = i - 1, right = i + 1, maxO = 0, maxE = 0;

		while ((left >= 0) && (right < size))
		{
			if (str[left] == str[right])
			{
				maxO++;
				left--;
				right++;
				continue;
			}
			else
			{
				break;
			}


		}

		left = i; right = i + 1;
		while ((left >= 0) && (right < size))
		{
			if (str[left] == str[right])
			{
				maxE++;
				left--;
				right++;
				continue;
			}
			else
			{
				break;
			}


		}

		if (maxO >= maxE&&(maxO!=0))           //  maxO!=0 考虑只有单个回文字符情况   情况要分明，不然越理越乱，能不外放分支的就不要外放分支，变量能
                                         //少则少，不然稍有变动，代码一塌糊涂，同时也要注意各个变量之间的独立性，防止相互干扰
		{
			maxbegin = i - maxO;
			maxend = 2 * maxO+1;

		}
		else if (maxO <maxE && (maxE != 0))
		{
			maxbegin = i - maxE + 1;
			maxend = 2 * maxE ;
		}
		else
		{
			maxbegin = i;
			maxend = 1;
		}

		return maxend ;
	}
    
    
    
};
