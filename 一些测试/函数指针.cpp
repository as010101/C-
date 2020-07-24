
//     void (* p)(string&) ;
//p = myCall;
//readFile("D:/mydata/LmtFromTDX.csv", 1, p);
void readFile(const string&& AbsoluteSourcePath, int head, void (*cb)(string&))
{
	ifstream file(AbsoluteSourcePath);
	string str;
	if (head)
	{
		getline(file, str);
	}
	while (getline(file, str))
	{
		cb(str);
	}
}
