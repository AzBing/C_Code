#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include<set>
#include<map>
using namespace std;


void test_map1()
{
	map<string, string> dict;
	dict.insert(pair<string, string>("sort", "����"));
	dict.insert(pair<string, string>("insert", "����"));
	dict.insert(pair<const char*, const char*>("left", "���"));

	dict.insert(make_pair("right", "�ұ�")); // �Ƽ����

	dict["erase"];  // ����
	cout << dict["erase"] << endl; // ����
	dict["erase"] = "ɾ��"; // �޸�
	cout << dict["erase"] << endl;// ����
	dict["test"] = "����";  // ����+�޸�
	dict["left"] = "��ߡ�ʣ��"; // �޸�



	// 
	string s1("xxx"), s2("yyy");
	dict.insert(make_pair(s1, s2));

	map<string, string>::iterator it = dict.begin();
	while (it != dict.end())
	{
		cout << (*it).first << ":" << (*it).second << endl;
		cout << it.operator->()->first << ":" << it.operator->()->second << endl;
		cout << it->first << ":" << it->second << endl;

		++it;
	}
	cout << endl;

	for (auto& kv : dict)
	{
		// kv.first += 'x';
		kv.second += 'x';

		cout << kv.first << ":" << kv.second << endl;
	}
}

void test_map2()
{
	string arr[] = { "ƻ��", "����", "ƻ��", "����", "ƻ��", "ƻ��", "����", "ƻ��", "�㽶", "ƻ��", "�㽶" };
	map<string, int> countMap;
	//for (auto& str : arr)
	//{
	//	//auto ret = countMap.find(str);
	//	//if (ret == countMap.end())
	//	//{
	//	//	// ô�б�ʾ��һ�γ��֣�����
	//	//	countMap.insert(make_pair(str, 1));
	//	//}
	//	//else
	//	//{
	//	//	// ����++
	//	//	ret->second++;
	//	//}
	//	countMap[str]++;
	//}

	for (auto& str : arr)
	{
		countMap[str]++;
	}

	for (auto& kv : countMap)
	{
		cout << kv.first << ":" << kv.second << endl;
	}
}

int main()
{
	test_map1();

	return 0;
}