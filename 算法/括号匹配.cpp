

[
  "((()))",
  "(()())",
  "(())()",
  "()(())",
  "()()()"
]
卡特兰数

dfs 剪枝



class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        func(res,"",0,0,n);                           //“”  代表空字符串
        return res;
    }
    
    void  func(vector<string> &res,string str,int l,int r,int n)
    {
        
        if(l>n||r>n||r>l)  return;                                 //注意条件  r>l
         
        if(l==n && r==n) {res.push_back(str);return;}               //      很像二叉树的先序递归遍历
            func(res,str+'(',l+1,r,n);
            func(res,str+')',l,r+1,n);
                
        
        
    }
};
