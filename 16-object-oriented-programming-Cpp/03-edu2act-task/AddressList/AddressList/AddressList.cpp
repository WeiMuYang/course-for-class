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
		cout<<"1.��Ӽ�¼"<<endl;
		cout<<"2.ɾ����¼"<<endl;
		cout<<"3.�����¼"<<endl;
		cout<<"4.���Ҽ�¼"<<endl;
		cout<<"5.�˳�ϵͳ"<<endl;
		cout<<"��ѡ��:";
		cin >> chioce;

		int i;

		switch (chioce)
		{
		case '1':
			cout << "Ҫ��ӵ���ϵ�˵�����:";
			cin >> name;
			cout << "Ҫ��ӵ���ϵ�˵ĵ绰:";
			cin >> phone;
			cout << "Ҫ��ӵ���ϵ�˵ĵ�ַ:";
			cin >> address;

			record.setName(name);	   
            record.setPhone(phone);	
			record.setAddress(address);

            m_Reclist.push(record);
			break;

		case '2':
			cout << "Ҫɾ������ϵ�˵�����";
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
				cout << "ɾ�������������ڣ�" << endl;
			break;

		case '3':
			len = m_Reclist.length();
            for(int i=0; i<len; i++)
                cout << m_Reclist.at(i).getName() << " "
                    << m_Reclist.at(i).getPhone() << " "
                    << m_Reclist.at(i).getAddress() << endl;
			break;

		case '4':
			cout << "Ҫ���ҵ���ϵ�˵�����";
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
				cout << "���ҵ����������ڣ�" << endl;
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