#include<iostream>
using namespace std;
#include<set>

//set容器构造和赋值

//集合容器 属于 关联式容器

//set不允许容器中存在重复的元素
//multiset允许容器中有重

void printSet(const set<int>& s)
{
	for (set<int>::const_iterator it = s.begin(); it != s.end(); it++)
	{
		cout << *it << " ";

	}
	cout << endl;
}

void test01()
{
	set<int>s1;
	//插入数据只有insert方式
	s1.insert(10);
	s1.insert(20);
	s1.insert(30);
	s1.insert(40);
	s1.insert(-1);

	//遍历容器
	//set容器特点，所有元素插入时候会自动被排序
	//set容器不允许插入重复值
	printSet(s1);

	//拷贝构造
	set<int>s2(s1);
	printSet(s2);

	//赋值
	set<int>s3 = s2;
	printSet(s3);

}


int main()
{
	test01();
	return 0;
}
