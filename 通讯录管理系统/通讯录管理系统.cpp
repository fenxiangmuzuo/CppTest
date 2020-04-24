// 通讯录管理系统.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <stdio.h>
#define MAX 1000
using namespace std;

void show_menu() 
{
    cout << "************************" << endl;
    cout << "***** 1.添加联系人 *****" << endl;
    cout << "***** 2.显示联系人 *****" << endl;
    cout << "***** 3.删除联系人 *****" << endl;
    cout << "***** 4.查找联系人 *****" << endl;
    cout << "***** 5.修改联系人 *****" << endl;
    cout << "***** 6.清空联系人 *****" << endl;
    cout << "***** 0.退出通讯录 *****" << endl;
    cout << "************************" << endl;
}

struct Person
{
    string m_name;
    int m_age;
    int m_gender;
    string m_phone;
    string m_addr;
};
struct AddressBooks
{
    struct Person personArray[MAX];
    int a_size;
};
void addPerson(AddressBooks* abs) {
    if (abs->a_size == MAX)
    {
        cout << "通讯录已满，无法添加" << endl;
        return;
    }
    else 
    {
        cout << "请输入姓名：" << endl;
        string name="";
        cin >> name;
        abs->personArray[abs->a_size].m_name = name;
        cout << "请输入年龄：" << endl;
        int age=0;
        cin >> age;
        abs->personArray[abs->a_size].m_age = age;
        cout << "请输入性别：" << endl;
        cout << "1 -- 男" << endl;
        cout << "0 -- 女" << endl;
        int gender=0;
        while (true) 
        {
            cin >> gender;
            if (gender == 1 || gender == 0)
            {
                abs->personArray[abs->a_size].m_gender = gender;
                break;

            }
            else 
            {
                cout << "输入的性别不正确，请重新输入..." << endl;
            }
        }
        cout << "请输入家庭住址：" << endl;
        string address="";
        cin >> address;
        abs->personArray[abs->a_size].m_addr = address;
        cout << "请输入电话号码：" << endl;
        string phone="";
        cin >> phone;
        abs->personArray[abs->a_size].m_phone = phone;

        abs->a_size++;
        cout << "添加成功" << endl;
        system("pause");
        system("cls");
    }
};
void showPerson(AddressBooks *abs)
{
    if (abs->a_size == 0)
    {
        cout << "通讯录为空！" << endl;
        system("pause");
        system("cls");
    }
    else 
    {
        for (int i = 0; i < abs->a_size; i++)
        {
            cout << "姓名：\t"+abs->personArray[i].m_name<<"\t";
            cout << "年龄：\t" << abs->personArray[i].m_age<<"\t";
            cout << "性别：\t" << (abs->personArray[i].m_gender == 1?"男":"女")<<"\t";
            cout << "电话号码：\t" + abs->personArray[i].m_phone<<"\t";
            cout << "家庭住址：\t" + abs->personArray[i].m_addr<<"\t"<<endl;
        }
        system("pause");
        system("cls");
    }
}
int isExist(AddressBooks * abs,string name)
{
   
    for (int i = 0; i < abs->a_size;i++) 
    {
        if (name == abs->personArray[i].m_name)
        {
            return i;
        }
    }
    return -1;
}
void deletePerson(AddressBooks* abs)
{
    cout << "请输入要删除的联系人：" << endl;
    string name;
    cin >> name;
    int ret = isExist(abs,name);
    if (ret != -1) {
        for (int i = ret; i < abs->a_size; i++)
        {
            abs->personArray[i] = abs->personArray[i + 1];
        }
        abs->a_size--;
        cout << "删除成功！" << endl;
    }
    else
    {
        cout << "查无此人！" << endl;
    }
    system("pause");
    system("cls");
}
void findPerson(AddressBooks* abs)
{
    cout << "请输入要查找的联系人：" << endl;
    string name="";
    cin >> name;
    int ret = isExist(abs, name);
    if (ret != -1)
    {
        {
            cout << "姓名：\t" + abs->personArray[ret].m_name << "\t";
            cout << "年龄：\t" + abs->personArray[ret].m_age << "\t";
            cout << "性别：\t" << (abs->personArray[ret].m_gender == 1 ? "男" : "女") << "\t";
            cout << "电话号码：\t" + abs->personArray[ret].m_phone << "\t";
            cout << "家庭住址：\t" + abs->personArray[ret].m_addr << "\t"<<endl;
        }
    }
    else
    {
        cout << "查无此人" << endl;
    }
    system("pause");
    system("cls");
}
void modifyPerson(AddressBooks* abs)
{
    cout << "请输入要修改的联系人：" << endl;
    string name;
    cin >> name;
    int ret = isExist(abs,name);
    if (ret != -1)
    {
        cout << "请输入姓名：" << endl;
        string name="";
        cin >> name;
        abs->personArray[ret].m_name = name;
        cout << "请输入年龄：" << endl;
        int age=0;
        cin >> age;
        abs->personArray[ret].m_age = age;
        cout << "请输入性别：" << endl;
        cout << "1 -- 男" << endl;
        cout << "0 -- 女" << endl;
        int gender=0;
        while (true)
        {
            cin >> gender;
            if (gender == 1 || gender == 0)
            {
                abs->personArray[ret].m_gender = gender;
                break;

            }
            else
            {
                cout << "输入的性别不正确，请重新输入..." << endl;
            }
        }
        cout << "请输入家庭住址：" << endl;
        string address="";
        cin >> address;
        abs->personArray[ret].m_addr = address;
        cout << "请输入电话号码：" << endl;
        string phone="";
        cin >> phone;
        abs->personArray[ret].m_phone = phone;

        cout << "修改成功!" << endl;
        system("pause");
        system("cls");
    }
    else
    {
        cout << "查无此人!" << endl;
    }
}
void cleanPerson(AddressBooks* abs)
{
    abs->a_size = 0;
    cout << "通讯录已清空！" << endl;
    system("pause");
    system("cls");
}
int main()
{
    AddressBooks abs;
    abs.a_size = 0;
    int select = 0;
    while (true)
    {
        system("cls");
        show_menu();
        cin >> select;
        switch (select)
        {
        case 1:    //添加联系人
            addPerson(&abs);
            break;
        case 2:     //显示联系人
            showPerson(&abs);
            break;
        case 3:     //删除联系人  
            deletePerson(&abs);
            break;
        case 4:      //查找联系人  
            findPerson(&abs);
            break;
        case 5:      //修改联系人
            modifyPerson(&abs);
            break;
        case 6:    //清空联系人
            cleanPerson(&abs);
            break;
        case 0:
            cout << "欢迎下次使用！" << endl;
            system("pause");
            return 0;
            break;  //退出通讯录
        default:
            break;


        }

    }
    system("pause");
    return 0;
};

// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门使用技巧: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件
