#include <iostream>
#include <cstdio>
#include <string>
#include <fstream>
#include "contacts.pb.h"

using namespace std;

void AddPeopleInfo(contacts::PeopleInfo* peopleinfo)
{
    cout << "--------------------新增联系人--------------------" << endl;    
    
    cout << "请输入联系人姓名：";
    string name;
    getline(cin, name);
    peopleinfo->set_name(name);

    cout << "请输入联系人年龄：";
    int age;
    cin >> age;
    peopleinfo->set_age(age);
    cin.ignore(256, '\n');

    for (int i = 0; ; i++) {
        cout << "请输入联系人电话" << i + 1 << "(只输入回车完成新增)：";
        string number;
        getline(cin, number);
        if (number.empty()) {
            break;
        }

        contacts::PeopleInfo_Phone* phone = peopleinfo->add_phone();
        phone->set_number(number);
    }

    cout << "------------------添加联系人成功--------------------" << endl;
}

int main()
{
    contacts::Contacts contacts;
    // 读取本地文件
    fstream input("contacts.bin", ios::in | ios::binary);

    if (!input) {
        cout << "contacts.bin has not found, create new file" << endl;
    } else if (!contacts.ParseFromIstream(&input)) {
        cout << "prase fail" << '\n';
        input.close();
        return -1;
    }

    // 添加联系人
    AddPeopleInfo(contacts.add_contact());

    // 将讲通讯录写入本地文件
    fstream output("contacts.bin", ios::out | ios::trunc | ios::binary);
    if (!contacts.SerializeToOstream(&output)) {
        cout << "serialize fail" << endl;
        input.close();
        output.close();
        return -1;
    }

    cout << "write success" << endl;
    input.close();
    output.close();

    return 0;
}