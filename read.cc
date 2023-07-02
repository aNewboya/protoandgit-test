#include <iostream>
#include <cstdio>
#include <string>
#include <fstream>
#include "contacts.pb.h"

using namespace std;

void PrintContact(contacts::Contacts& contacts)
{
    for (int i = 0; i < contacts.contact_size(); ++i)
    {
        cout << "------------------联系人" << i + 1 << "-------------------" << endl;
        const contacts::PeopleInfo peopleinfo = contacts.contact(i);
        cout << "联系人姓名：" << peopleinfo.name() << endl
            << "联系人年龄：" << peopleinfo.age() << endl;
        for (int j = 0; j < peopleinfo.phone_size(); ++j)
        {
            const contacts::PeopleInfo_Phone phone = peopleinfo.phone(j);
            cout << "联系人电话" << j + 1 << "：" << phone.number() << '\n';
        }
    }
}

int main()
{
    contacts::Contacts contacts;
    ifstream input("contacts.bin", ios::in | ios::binary);
    if (!contacts.ParseFromIstream(&input)) {
        cout << "parse fail" << endl;
        input.close();
        return -1;
    }

    PrintContact(contacts);

    return 0;
}