 more  https://www.jianshu.com/p/d20602e43f85
 
 单目运算参数表中无参数,调用该函数的对象为操作数
 双目运算参数表中有一个参数,调用该函数的对象为第一操作数,参数表中的参数为第二操作数;
 运算符函数体会对重载的运算符的含义做出新的解释，这种解释仅仅局限于重载该运算符的类之中,脱离类对象,该运算符具有系统预定义的含义
 
 
#include "stdafx.h"
#include <ostream>
#include <iostream>
using namespace std;

class CCounter {
public:
    CCounter() { 
        m_nValue = 0;
    };
    void operator++() {     //1th
    if (m_nValue<65535)
    {
        m_nValue++;
    }
    }
    int operator*() {  //2th
        return m_nValue;
    }

private:
    int m_nValue;
};

int main()
{
    CCounter objA;
    ++objA;         //隐式  ;调用1th
    objA.operator++();//显示,调用1th
    cout << *objA << endl;      //调用2处函数
    return 0;
}




#include "stdafx.h"
#include <ostream>
#include <iostream>
using namespace std;

class CCounter {
public:
    CCounter(int nNum) {
        m_nValue = nNum;
    };
    void operator+(CCounter &obj) {     //1th
    
            m_nValue+= obj.m_nValue;
        
    }
    int operator*() {  //2th
        return m_nValue;
    }

private:
    int m_nValue;
};

int main()
{
    CCounter objA(5),objB(5);
    objA+objB;          //隐式,调用1th
    objA.operator+(objB);//显示,调用1th
    cout << *objA << endl;  //调用2处函数
    return 0;
}

