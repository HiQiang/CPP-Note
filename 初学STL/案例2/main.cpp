#include<iostream>
#include<fstream>
#include"manager.h"
#include"teacher.h"
#include"student.h"
#include"globalFile.h"
using namespace std;

//进入学生子菜单界面
void studentMenu(Identity*& student)
{
	while (true)
	{
		//调用学生的子菜单
		student->openMenu();

		Student* stu = (Student*)student;

		int select = 0;//接收用户的选择
		cin >> select;
		if (select == 1)//申请预约
		{
			stu->applyOrder();
		}
		else if (select == 2)//查看自身预约
		{
			stu->showMyOrder();
		}
		else if (select == 3)//查看所有人预约
		{
			stu->showAllOrder();
		}
		else if (select == 4)//取消预约
		{
			stu->cancelOrder();
		}
		else//注销登录
		{
			delete student;
			cout << "注销成功" << endl;
			system("pause");
			system("cls");
			return;
		}
	}
}

//进入教师子菜单界面
void teacherMenu(Identity*& teacher)
{
	while (true)
	{
		//调用子菜单界面
		teacher->openMenu();
		Teacher* tea = (Teacher*)(teacher);

		int select = 0; //接收用户选择

		cin >> select;
		if (select == 1)//查看所有预约
		{
			tea->showAllOrder();
		}
		else if(select == 2)//审核预约
		{
			tea->validOrder();
		}
		else
		{
			delete teacher;
			cout << " 注销成功" << endl;
			system("pause");
			system("cls");
			return;
		}
	}
}

//进入管理员菜单界面
void nanagerMenu(Identity*& manager)
{
	do
	{
		//调用管理员的子菜单
		manager->openMenu();

		//将父类的指针转为子类的指针，调用子类里其它特有接口
		Manager* man = (Manager*)manager;
		int select = 0;
		//接收用户的选择
		cin >> select;
		if (select == 1)//添加账号
		{
			//cout << "添加账号" << endl;
			man->addPerson();
		}
		else if(select == 2) //查看账号
		{
			//cout << "查看账号" << endl;
			man->showPerson();
		}
		else if (select == 3) //查看机房
		{
			//cout << "查看机房" << endl;
			man->showComputer();
		}
		else if (select == 4) //清空预约
		{
			//cout << "清空预约" << endl;
			man->clearFile();
		}
		else
		{
			// 注销
			delete manager;//销毁掉堆区的对象
			cout << "注销成功" << endl;
			system("pause");
			system("cls");
			return;
		}
	} while (true);
}

//登录功能 参数 操作文件名 操作身份类型
void LoginIn(string fileName, int type)
{
	//父类指针，用于指向子类对象
	Identity* person = NULL;

	//读文件
	ifstream ifs;
	ifs.open(fileName, ios::in);
	//判断文件是否存在
	if (!ifs.is_open())
	{
		cout << "文件不存在" << endl;
		ifs.close();
		return;
	}

	//准备接收用户信息
	int id = 0;
	string name;
	string pwd;

	//判断身份
	if (type == 1)//学生身份
	{
		cout << "请输入您的学号：" << endl;
		cin >> id;
	}
	else if (type == 2)
	{
		cout << "请输入您的职工号" << endl;
		cin >> id;
	}
	cout << "请输入用户名：" << endl;
	cin >> name;
	cout << "请输入密码：" << endl;
	cin >> pwd;

	if (type == 1)
	{
		//学生身份验证
		int fId;//从文件中读取的id号
		string fName;//从文件中获取的姓名
		string fPwd;//从文件中获取的密码
		while (ifs>>fId && ifs>>fName && ifs>>fPwd)
		{
			//cout << fId << endl;
			//cout << fName << endl;
			//cout << fPwd << endl;

			//与用户输入的信息做对比
			if (fId == id && fName == name && fPwd == pwd)
			{
				cout << "学生的验证登录成功！" << endl;
				system("pause");
				system("cls");
				person = new Student(id, name, pwd);
				//进入到学生身份的子菜单
				studentMenu(person);

				return;
			}
		}
	}
	else if(type == 2)
	{
		//教师身份验证

		int fId;//从文件中读取的id号
		string fName;//从文件中获取的姓名
		string fPwd;//从文件中获取的密码
		
		while (ifs >> fId && ifs >> fName && ifs >> fPwd)
		{
			//cout << fId << endl;
			//cout << fName << endl;
			//cout << fPwd << endl;

			//与用户输入的信息做对比
			if (fId == id && fName == name && fPwd == pwd)
			{
				cout << "老师的验证登录成功！" << endl;
				system("pause");
				system("cls");
				person = new Teacher(id, name, pwd);
				//进入到老师身份的子菜单
				teacherMenu(person);
				return;
			}
		}
	}
	else if(type == 3)
	{
		//管理员身份验证
		//int fId;//从文件中读取的id号
		string fName;//从文件中获取的姓名
		string fPwd;//从文件中获取的密码

		while (ifs >> fName && ifs >> fPwd)
		{
			//cout << fId << endl;
			//cout << fName << endl;
			//cout << fPwd << endl;

			//与用户输入的信息做对比
			if (fName == name && fPwd == pwd)
			{
				cout << "管理员的验证登录成功！" << endl;
				system("pause");
				system("cls");

				person = new Manager(name, pwd);
				//进入到管理员身份的子菜单
				nanagerMenu(person);
				return;
			}
		}

	}

	cout << "验证登录失败！" << endl;
	system("pause");
	system("cls");
	return;
}

int main()
{
	int select = 0;

	do
	{
		cout << "\t\t========机房预约系统========" << endl;
		cout << endl;
		cout << "请输入您的身份：" << endl;
		cout << "\t\t+-------------------------+\n";
		cout << "\t\t|                         |\n";
		cout << "\t\t|       1.学生代表        |\n";
		cout << "\t\t|                         |\n";
		cout << "\t\t|       2.老    师        |\n";
		cout << "\t\t|                         |\n";
		cout << "\t\t|       3.管 理 员        |\n";
		cout << "\t\t|                         |\n";
		cout << "\t\t|       0.退    出        |\n";
		cout << "\t\t|                         |\n";
		cout << "\t\t+-------------------------+\n";
		cout << "请输入您的选择：" << endl;

		cin >> select;//接收用户选择

		switch (select)//根据用户选择 实现不同接口
		{
		case 1://学生身份
			LoginIn(STUDENT_FILE, 1);
			break;

		case 2://老师身份
			LoginIn(TEACHER_FILE, 2);
			break;

		case 3://管理员身份
			LoginIn(ADMIN_FILE, 3);
			break;

		case 0://退出系统
			cout << "欢迎下次使用" << endl;
			system("pause");

			return 0;
			
			break;

		default:
			cout << "输入有误，请重新选择！" << endl;
			system("pause");
			system("cls");
			break;
		}
	} while (true);
	return 0;
}