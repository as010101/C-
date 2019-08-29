




class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& T) {
        vector<int> res;
        for(int j=0 ;j<T.size();j++)
        {
            
            for(int i=j+1 ;i < T.size();i++)
            {
                if(T[i]>T[j])
                {
                    res.push_back(i-j);
                    break;
                }
                else if(i==T.size()-1)
                {
                    res.push_back(0);
                }
                
                
            }
        }
        res.push_back(0);
        return res;
    }
};
