public:
    int hIndex(vector<int>& citations) {
        int up=citations.size();  
        vector<int> mp(up+1,0); //为啥up+1  为了和h相对应 实际上可以改成 int up=citations.size()-1 在返回的时候加1  还是不行，应该应题目要求
        for(auto ele :citations)
        {
            if(ele>up)
            {
                mp[up]++;
            }
            else
            {
                mp[ele]++;
            }
        }
        
        for(;up>0;up--)
        {
            if(mp[up]>=up)
            {
                return up;
            }
            mp[up-1]+=mp[up];
            
        }
        return 0;
        
    }
};
