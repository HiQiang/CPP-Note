#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

//互换两个容器的元素
void myPrint(int val)
{
	cout << val << " ";
}
void test01()
{
	vector<int> v1;
	for (int i = 0; i < 10; i++)
	{
		v1.push_back(i);
	}

	vector<int> v2;
	for (int i = 10; i > 0; i--)
	{
		v2.push_back(i);
	}

	cout << "互换前：" << endl;
	for_each(v1.begin(), v1.end(), myPrint);
	cout << endl;
	for_each(v2.begin(), v2.end(), myPrint);
	cout << endl;

	//互换
	//v1.swap(v2);
	swap(v1,v2);
	cout << "互换后：" << endl;
	for_each(v1.begin(), v1.end(), myPrint);
	cout << endl;
	for_each(v2.begin(), v2.end(), myPrint);
	cout << endl;
}


int main()
{
	test01();
	return 0;
}
