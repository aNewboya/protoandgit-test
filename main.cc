#include <iostream>
#include <cstdio>
#include <string>
#include "contacts.pb.h"

using namespace std;

int main()
{
    string people_str;
    {
        contacts::PeopleInfo people_info;
        people_info.set_name("张三");
        people_info.set_age(18);
        if (!people_info.SerializeToString(&people_str))
        {
            std::cerr << "序列化联系人失败!" << std::endl;
            return -1;
        }
        std::cout << "序列化成功:" << people_str << std::endl;
    }
    {
        contacts::PeopleInfo people_info;
        if (!people_info.ParseFromString(people_str))
        {
            std::cout << "反序列化联系人失败" << std::endl;
            return -1;
        }
        std::cout << "反序列化成功!" << std::endl
                << people_info.name() << std::endl
                << people_info.age() << std::endl;
    }
    return 0;
}