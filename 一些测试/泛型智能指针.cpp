
         return a; }
 
     void chars() {
         //使用智能指针指向 char[],以自动释放
         _PRTA(char,p,1024*1024);
         strcpy(p.get(), "std::shared_ptr<char*>");
         printf(p.get());
     }
     
 };
 int main() {
     B* ptrB0 = new B(1);
     ptrB0->Out();
 
     _PRT(B) ptrB1(new B(2));
     ptrB1->Out();
     _PRT(A) a = ptrB1->geta(5);
     a->Out();
     //复制了指针,增加引用计数
     _PRT(B) ptrB2 = ptrB1;
     _PRT(A) b = ptrB2->geta(6);
     b->Out();
     ptrB2->Out();
 
     //使用智能指针,会自动释放
     for(int i=100;i;i--)
         ptrB2->chars();
 }
