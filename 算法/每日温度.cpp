


class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& T) {
        vector<int>  res(T.size(),0);    
        for(int i=T.size()-2;i>=0;i--)
        {
            for(int j=i+1;j<T.size();j+=res[j])               //注意j+=res[j]
            {
                
            if(T[i]<T[j])
            {
                res[i]=j-i;                     //注意j-i                
                break;
                
            }
                
            else if(res[j]==0)     //注意是  j
            {
                res[i]=0;
                break;
            }
                
            }       
        }
     return res;   
    }
};



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
