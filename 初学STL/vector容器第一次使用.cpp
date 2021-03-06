#include<iostream>
using namespace std;
#include<vector>
#include<algorithm>

//标准模板库
//vector容器存放内置数据类型

void myPrint(int val)
{
	cout << val << endl;
}


void test01()
{
	vector<int> v;//vector 其实是一个类 模板类

	//向容器中插入数据
	v.push_back(10);//尾插数据 本质是一个 类成员函数
	v.push_back(20);
	v.push_back(30);
	v.push_back(40);

	//通过迭代器访问容器中的数据
	vector<int>::iterator itBegin = v.begin();//起始迭代器 指向容器中的第一个元素
	vector<int>::iterator itEdn = v.end();//结束迭代器 指向容器中最后一个元素的下一个位置

	//第一种遍历方式
	while (itBegin != itEdn)
	{
		cout << *itBegin << endl;//迭代器当作指针使用 解引用操作
		itBegin++;
	}

	//第二种遍历方式
	for (vector<int>::iterator it = v.begin(); it != v.end(); it++)
	{
		cout << *it << endl;
	}

	//第三种遍历方式
	//利用STL中提供的遍历算法
	for_each(v.begin(), v.end(), myPrint);

}


int main()
{
	test01();
	return 0;
}


