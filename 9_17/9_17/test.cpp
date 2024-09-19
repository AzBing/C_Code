#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<map>
#include<string>
#include<list>
#include<vector>
#include<fstream>
#include<sstream>
using namespace std;

class Date
{
	friend ostream& operator << (ostream& out, const Date& d);
	friend istream& operator >> (istream& in, Date& d);
public:
	Date(int year = 1, int month = 1, int day = 1)
		:_year(year)
		, _month(month)
		, _day(day)
	{}

	operator bool()
	{
		// 这里是随意写的，假设输入_year为0，则结束
		if (_year == 0)
			return false;
		else
			return true;
	}
private:
	int _year;
	int _month;
	int _day;
};

istream& operator >> (istream& in, Date& d)
{
	in >> d._year >> d._month >> d._day;
	return in;
}

//ofs << winfo._date;
ostream& operator << (ostream& out, const Date& d)
{
	//out << d._year << "年" << d._month << "月" << d._day<<"日";
	//out << d._year << "/" << d._month << "/" << d._day;
	out << d._year << " " << d._month << " " << d._day;

	return out;
}

// C++ IO流，使用面向对象+运算符重载的方式
// 能更好的兼容自定义类型，流插入和流提取
//int main()
//{
//	// 自动识别类型的本质--函数重载
//	// 内置类型可以直接使用--因为库里面ostream类型已经实现了
//	int i = 1;
//	double j = 2.2;
//	cout << i << endl;
//	cout << j << endl;
//
//	// 自定义类型则需要我们自己重载<< 和 >>
//	Date d(2022, 4, 10);
//	cout << d;
//	while (d)
//	{
//		cin >> d;
//		cout << d;
//	}
//
//	return 0;
//}

//int main()
//{
//	int i = 0;
//	int j = 0;
//
//	scanf("%d", &j);
//	printf("xxxxxxxxxx\n");
//	cout << i << endl;
//
//	cin.sync_with_stdio(false);
//
//	cin >> i;
//
//	cout.sync_with_stdio(false);
//
//	cout << "yyyyyyyyyy" << endl;
//	printf("%d\n", j);
//	printf("%d\n", i);
//
//	return 0;
//}

//int main()
//{
//	int i = 0;
//	int j = 0;
//
//	cout.sync_with_stdio(false);
//
//	printf("xxxxxxxxxx\n");
//	cout << "yyyyyyyyyy" << endl << endl;
//	printf("xxxxxxxxxx\n");
//	cout << "yyyyyyyyyy" << endl << endl;;
//	printf("xxxxxxxxxx\n");
//	cout << "yyyyyyyyyy" << endl << endl;;
//	printf("xxxxxxxxxx\n");
//	cout << "yyyyyyyyyy" << endl << endl;;
//	printf("xxxxxxxxxx\n");
//	cout << "yyyyyyyyyy" << endl << endl;;
//	printf("xxxxxxxxxx\n");
//	cout << "yyyyyyyyyy" << endl << endl;;
//	printf("xxxxxxxxxx\n");
//	cout << "yyyyyyyyyy" << endl << endl;
//
//
//	vector<int>::iterator it;
//	cout << typeid(it).name() << endl;
//
//	return 0;
//}

struct ServerInfo
{
	//char _address[32];
	string _address;
	double _x;

	Date _date;
};

// 写到文件
// 从文件读出来
// 1、二进制读写
// 2、文本读写
class BinIO
{
public:
	BinIO(const char* filename = "info.bin")
		:_filename(filename)
	{}

	void Write(const ServerInfo& winfo)
	{
		ofstream ofs(_filename, ofstream::out | ofstream::binary);
		ofs.write((char*)&winfo, sizeof(winfo));
	}

	void Read(ServerInfo& rinfo)
	{
		ifstream ifs(_filename, ofstream::in | ofstream::binary);
		ifs.read((char*)&rinfo, sizeof(rinfo));
	}

private:
	string _filename;
};

// 写
//int main()
//{
//	ServerInfo winfo = { "https://legacy.cplusplus.com/reference/fstream/ifstream/ifstream/", 12.13, { 2022, 4, 10 } };
//
//	BinIO bin;
//	bin.Write(winfo);
//
//	return 0;
//}

//int main()
//{
//	ServerInfo info;
//	BinIO bin;
//	bin.Read(info);
//
//	cout << info._address << endl;
//	cout << info._x << endl;
//	cout << info._date << endl;
//
//	return 0;
//}

// 2、文本读写
class TextIO
{
public:
	TextIO(const char* filename = "info.text")
		:_filename(filename)
	{}

	void Write(const ServerInfo& winfo)
	{
		ofstream ofs(_filename);
		ofs << winfo._address << endl;
		ofs << winfo._x << endl;
		ofs << winfo._date << endl;
	}

	void Read(ServerInfo& rinfo)
	{
		ifstream ifs(_filename);
		ifs >> rinfo._address;
		ifs >> rinfo._x;
		ifs >> rinfo._date;
	}

private:
	string _filename;
};

// 写
//int main()
//{
//	ServerInfo winfo = { "https://legacy.cplusplus.com/reference/fstream/ifstream/ifstream/", 12.13, { 2022, 4, 10 } };
//
//	TextIO text;
//	text.Write(winfo);
//
//	// c
//	//double x = 1.111;
//	//char buff[128];
//	//sprintf(buff, "%lf", x);
//
//	// cpp
//	//to_string(x);
//
//	return 0;
//}

// 读
//int main()
//{
//	ServerInfo info;
//	TextIO text;
//	text.Read(info);
//
//	cout << info._address << endl;
//	cout << info._x << endl;
//	cout << info._date << endl;
//
//	return 0;
//}

//int main()
//{
//	char sql1[128];
//	char name[10];
//	scanf("%s", name);
//
//	sprintf(sql1, "select * from t_scroe where name = '%s'", name);
//	printf("%s\n", sql1);
//
//	string sql2;
//	sql2 += "select * from t_scroe where name = '";
//	sql2 += name;
//	sql2 += "'";
//	cout << sql2 << endl;
//
//	Date d(2024, 1, 19);
//
//	/*ostringstream oss;
//	oss << d;
//
//	string sql3;
//	sql3 += "select * from t_data where date = '";
//	sql3 += oss.str();
//	sql3 += "'";
//	cout << sql3 << endl;*/
//
//	ostringstream sqloss;
//	sqloss << "select * from t_data where date = '"<< d << "'";
//	cout << sqloss.str() << endl;
//
//	// 序列化
//	// 反序列化
//
//	return 0;
//}

// json
struct ChatInfo
{
	string _name; // 名字
	int _id;      // id
	Date _date;   // 时间
	string _msg;  // 聊天信息
};

int main()
{
	ChatInfo winfo = { "张三", 135246, { 2022, 4, 10 }, "晚上一起看电影吧" };
	stringstream oss;
	oss << winfo._name << endl;
	oss << winfo._id << endl;
	oss << winfo._date << endl;
	oss << winfo._msg << endl;
	cout << oss.str() << endl;

	// 网络输出
	ChatInfo rinfo;
	string str = oss.str();
	stringstream iss(str);
	iss >> rinfo._name;
	iss >> rinfo._id;
	iss >> rinfo._date;
	iss >> rinfo._msg;

	cout << "-------------------------------------------------------" << endl;
	cout << "姓名：" << rinfo._name << "(" << rinfo._id << ") ";
	cout << rinfo._date << endl;
	cout << rinfo._name << ":>" << rinfo._msg << endl;
	cout << "-------------------------------------------------------" << endl;

	return 0;
}
