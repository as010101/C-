
//当(vec[25]-1)*(n+1)+cnt )比tasks.size()大时，应当有足够的位置，使得所有的task插入空位，都能够执行（应该有数学严格的证明）
//而当(vec[25]-1)*(n+1)+cnt )小于tasks.size（）时，这是不存在的最优解，为tasks.size()为理想最优解，此时应该可以通过任务的调整，使得执行时间为tasks.size()

class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> vec(26,0);  //能初始化就初始化  要用[]时
        for(int i=0;i<tasks.size();i++)
        {
          vec[tasks[i]-'A']++;         //统计每个字母（任务）的次数  
            
        }
        sort(vec.begin(),vec.end());
        int cnt=0; // 有几组最大任务
        for(int i=0;i<vec.size();i++)
        {
            if(vec[i]==vec[25]){cnt++;}
            
        }
        
       return  ((vec[25]-1)*(n+1)+cnt )>tasks.size()? ((vec[25]-1)*(n+1)+cnt ):tasks.size();
        
        
    }
};
