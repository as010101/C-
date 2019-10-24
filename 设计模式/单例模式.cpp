class Single
{

public:


	static Single *create()
	{
		if (m_Pisngle != nullptr)
		{
			m_Pisngle = new Single();
		}
		return  m_Pisngle;
	
	}

	void tes()    //这种定义是合法的，而作为类的成员 定义 Single a会报 不完整的类型
	{
		Single a = Single();
	}

private:

	Single()
	{
	}
	 static 	Single* m_Pisngle;

};
