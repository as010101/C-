
//简单工厂


//抽象层
class Methodbstract
{

	virtual void  split()=0;


};


class  CreateObjectAbstract
{

	virtual  Methodbstract* create();

};



//具体层

class Methodconcreate:public  Methodbstract
{

	void split();

};


class  CreateObjectConcreate :public Methodconcreate
{

	CreateObjectConcreate* create()
	{
		return new  CreateObjectConcreate();
	}

};
