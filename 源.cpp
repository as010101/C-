

/* 

#include <algorithm>
#include <vector>
#include <stdio.h>
#include "fast_ring_queue.h"

��˶ �۲���ģʽ
class Observable;

class Observer
{
public:
    virtual ~Observer();
    virtual void update() = 0;

    void observe(Observable* s);

protected:
    Observable* subject_;
};

class Observable
{
public:
    void register_(Observer* x);
    void unregister(Observer* x);

    void notifyObservers()
    {
        for (size_t i = 0; i < observers_.size(); ++i)
        {
            Observer* x = observers_[i];
            if (x) {
                x->update(); // (3)
            }
        }
    }

private:
    std::vector<Observer*> observers_;
};

Observer::~Observer()
{
    subject_->unregister(this);
}

void Observer::observe(Observable* s)
{
    s->register_(this);
    subject_ = s;
}

void Observable::register_(Observer* x)
{
    observers_.push_back(x);
}

void Observable::unregister(Observer* x)
{
    std::vector<Observer*>::iterator it = std::find(observers_.begin(), observers_.end(), x);
    if (it != observers_.end())
    {
        std::swap(*it, observers_.back());
        observers_.pop_back();
    }
}

// ---------------------

class Foo : public Observer
{
    virtual void update()
    {
        printf("Foo::update() %p\n", this);
    }
};

int main()
{
    LockFreeQueue<int> *s = new LockFreeQueue<int>(10);
    Foo* p = new Foo;
    Observable subject;
    p->observe(&subject);
    subject.notifyObservers();
    delete p;
    subject.notifyObservers();
}

*/


/*

����ָ�����
#include <memory>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <Thread>

#include <iostream>


#include <fstream>
#include <memory>

using namespace std;



void funvec(const shared_ptr<int>& p)
{
    vector<shared_ptr<int>>  vecs;
    vecs.push_back(p);
    cout << p.use_count() << endl;

}
int main() {

    int c = 1;
    shared_ptr<int> s;
    s.reset(&c);

    cout << s.use_count() << endl;
    funvec(s);
    //vector<shared_ptr<int>>  vecs;
    //vecs.push_back(s);
    //*s = 2;
    //cout<<vecs[0].use_count()<<endl;
    cout << s.use_count() << endl;
}
*/

/*
����ָ�����
// shared_ptr ��֤������ԭ�Ӳ��� ���������̰߳�ȫ�� ���Ƕ��� shared_ptr ������������˵�������������֣���׼������µĲ�δ����֤
#include <iostream>

#include <memory>

using namespace std;
class myPtr
{
public:
    unique_ptr<char> m_pUnique;
    
};

int main()
{
    int c;
    myPtr class1;
    class1.m_pUnique = make_unique<char>('c');
    c = *(class1.m_pUnique);
    cout << char(c);

    shared_ptr<char>  sp2;
    sp2 = make_shared<char>('d');

    weak_ptr<char> sp3;
    cout << sp3.use_count()<<endl;
    sp3 = sp2;
    cout << sp3.use_count() << endl;
  
    cout << *sp2 << endl;
    if (sp3.expired()) //�鿴shared_ptr �Ƿ����
    {
        cout << *(sp3.lock()) << endl;       //��ȡshared_ptr  
    }


}

*/

    
// stl �㷨

#include <iostream>
#include <algorithm>
#include <vector>
#include <iterator>

using namespace std;
int main()
{

    vector<int> vec1;
    for (int k = 0; k < 10; k++)
    {
        vec1.push_back(k);
    }
    rotate(vec1.begin(), vec1.begin() + 5, vec1.end());
    for_each(vec1.begin(), vec1.end(), [](int i) {cout << i << endl; });

    rotate(vec1.begin(),find(vec1.begin(), vec1.end(),7), vec1.end());
    for_each(vec1.begin(), vec1.end(), [](int i) {cout << i << endl; });
  
    return 0;
}