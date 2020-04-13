#include "AddressList.h"
#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;

AddressList::AddressList()
{
}

void AddressList::start() 
{
    char chioce;
	Record record;
	string name;
	string phone;
	string address;
    int len;
    do 
	{
		system("cls");
		cout<<"1.添加记录"<<endl;
		cout<<"2.删除记录"<<endl;
		cout<<"3.浏览记录"<<endl;
		cout<<"4.查找记录"<<endl;
		cout<<"5.退出系统"<<endl;
		cout<<"请选择:";
		cin >> chioce;

		int i;

		switch (chioce)
		{
		case '1':
			cout << "要添加的联系人的姓名:";
			cin >> name;
			cout << "要添加的联系人的电话:";
			cin >> phone;
			cout << "要添加的联系人的地址:";
			cin >> address;

			record.setName(name);	   
            record.setPhone(phone);	
			record.setAddress(address);

            m_Reclist.push(record);
			break;

		case '2':
			cout << "要删除的联系人的姓名";
			cin >> name;
            len = m_Reclist.length();
            for(i=0; i<len; i++)
            {
                if(m_Reclist.at(i).getName() == name)
                {
                    m_Reclist.remove(i);
                    break;
                }
            }
			
			if(i==len)
				cout << "删除的姓名不存在！" << endl;
			break;

		case '3':
			len = m_Reclist.length();
            for(int i=0; i<len; i++)
                cout << m_Reclist.at(i).getName() << " "
                    << m_Reclist.at(i).getPhone() << " "
                    << m_Reclist.at(i).getAddress() << endl;
			break;

		case '4':
			cout << "要查找的联系人的姓名";
			cin >> name;
            len = m_Reclist.length();
            for(i=0; i<len; i++)
            {
                if(m_Reclist.at(i).getName() == name)
                {
                    record = m_Reclist.at(i);
                    break;
                }
            }

			if(i==len)
				cout << "查找的姓名不存在！" << endl;
			else
			{
				cout << record.getName() << " " 
                    << record.getPhone() << " " 
                    << record.getAddress() << endl;
			}
			break;

		case '5':
			return;
		}

		system("pause");
	} while (1);
}