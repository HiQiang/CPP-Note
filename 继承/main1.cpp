#include<iostream>
using namespace std;
//继承的好处：减少重复代码
// 语法：class 子类 : 继承方式 父类
// 子类 也称为 派生类
// 父类 也称为 基类
//继承实现页面
class BasePage 
{
public:
	void header() {
		cout << "首页、公开课、登录、注册。。。（公共头部）" << endl;
	}
	void footer() {
		cout << "帮助中心、交流合作、站内地图。。。（公共底部）" << endl;
	}
	void left() {
		cout << "Java,Python,C++,。。。(公共分类列表)" << endl;
	}
};
//Java页面
class Java :public BasePage {
public:
	void content()
	{
		cout << "Java学习视频" << endl;
	}
};
//Python页面
class Python :public BasePage {
public:
	void content()
	{
		cout << "Python学习视频" << endl;
	}
};
//C++页面
class CPP :public BasePage {
public:
	void content()
	{
		cout << "CPP学习视频" << endl;
	}
};
void test01() {
	Java ja;
	ja.header();
	ja.footer();
	ja.left();
	ja.content();
	cout << "******************" << endl;
	Python py;
	py.header();
	py.footer();
	py.left();
	py.content();
	cout << "******************" << endl;
	CPP cpp;
	cpp.header();
	cpp.footer();
	cpp.left();
	cpp.content();
	cout << "******************" << endl;
}
int main()
{
	test01();
	return 0;
}
