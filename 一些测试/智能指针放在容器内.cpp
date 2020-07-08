
#include <memory>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <Thread>
#include <time.h>
#include <iostream>
#include <thread>
#include "ThreadPool.h"
#include <sys\stat.h>
#include <fstream>
#include <memory>





 void funvec(const shared_ptr<int> & p)
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
