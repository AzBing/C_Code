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
		// ����������д�ģ���������_yearΪ0�������
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
	//out << d._year << "��" << d._month << "��" << d._day<<"��";
	//out << d._year << "/" << d._month << "/" << d._day;
	out << d._year << " " << d._month << " " << d._day;

	return out;
}

// C++ IO����ʹ���������+��������صķ�ʽ
// �ܸ��õļ����Զ������ͣ������������ȡ
//int main()
//{
//	// �Զ�ʶ�����͵ı���--��������
//	// �������Ϳ���ֱ��ʹ��--��Ϊ������ostream�����Ѿ�ʵ����
//	int i = 1;
//	double j = 2.2;
//	cout << i << endl;
//	cout << j << endl;
//
//	// �Զ�����������Ҫ�����Լ�����<< �� >>
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

// д���ļ�
// ���ļ�������
// 1�������ƶ�д
// 2���ı���д
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

// д
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

// 2���ı���д
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

// д
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

// ��
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
//	// ���л�
//	// �����л�
//
//	return 0;
//}

// json
struct ChatInfo
{
	string _name; // ����
	int _id;      // id
	Date _date;   // ʱ��
	string _msg;  // ������Ϣ
};

int main()
{
	ChatInfo winfo = { "����", 135246, { 2022, 4, 10 }, "����һ�𿴵�Ӱ��" };
	stringstream oss;
	oss << winfo._name << endl;
	oss << winfo._id << endl;
	oss << winfo._date << endl;
	oss << winfo._msg << endl;
	cout << oss.str() << endl;

	// �������
	ChatInfo rinfo;
	string str = oss.str();
	stringstream iss(str);
	iss >> rinfo._name;
	iss >> rinfo._id;
	iss >> rinfo._date;
	iss >> rinfo._msg;

	cout << "-------------------------------------------------------" << endl;
	cout << "������" << rinfo._name << "(" << rinfo._id << ") ";
	cout << rinfo._date << endl;
	cout << rinfo._name << ":>" << rinfo._msg << endl;
	cout << "-------------------------------------------------------" << endl;

	return 0;
}
