

[
  "((()))",
  "(()())",
  "(())()",
  "()(())",
  "()()()"
]
卡特兰数

dfs 剪枝

深度递归可能的遍历
1.不加任何条件时
(((((((((((((((((((((((............
2.限定 l>n  return
((())))))))))))))))))))))))))))))))))....
3.限定 l>n  r>n return
  (((   )))
  ((     )))  
  
  
1 表示加（   2表示加）  f最后面表示执行顺序

f(0,0,1  )1

f(1,0,1  )2

f(2,0,1  )3
  f(2,1,2  )10
f(3,1,1  )11
  f(3,1,2  )12

f(3,0,1)4
  f(3,1,2)6
  f(3,2,2)7
  f(3,3,2)8
  f(3,4,2)9

f(4,0,1)5
  
  
  

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
