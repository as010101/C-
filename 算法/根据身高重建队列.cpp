

class Solution {
public:
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        sort(people.begin(),people.end(),[](const vector<int>& a, const vector<int>& b)   
             { return a[0] > b[0] || (a[0] == b[0] && a[1] < b[1]); });    //&&优先级高于||
 
        vector<vector<int>> ans;
        for(auto v : people)
            ans.insert(ans.begin()+v[1], v);
        
        return ans;
    }
};


1.sort 重写排序算法，优先级v[0]高于v[1], v[0]相同情况下比较v[1]  v[0]由大到小，v[1]由小到大
2.对sort的结果进行插入
        // 先排序
        // [7,0], [7,1], [6,1], [5,0], [5,2], [4,4]
        
        // 再一个一个插入。
        // [7,0]
        // [7,0], [7,1]
        // [7,0], [6,1], [7,1]
        // [5,0], [7,0], [6,1], [7,1]
        // [5,0], [7,0], [5,2], [6,1], [7,1]
        // [5,0], [7,0], [5,2], [6,1], [4,4], [7,1]
