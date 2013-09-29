// ���Գɼ�����.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include<iostream>
using namespace std;

struct Student{
	char name[30];
	long num;
	int ranking;
}students[100];

int nameCount=0;

void list();
void addStudent();
void deleteStudent();
void input(struct Student &student);
int find(char*name);

int main()
{
	int action;
	do{
		cout<<"--------ѧ������--------"<<endl;
		cout<<"��1���鿴ѧ������"<<endl;
		cout<<"��2��ѡ��"<<endl;
		cout<<"��3����ѡ"<<endl;
		cout<<"��4��¼��ɼ�"<<endl;
		cout<<"��5���˳�����"<<endl;

		cin>>action;
		switch(action){
		case 1:
				list();
				break;
		case 2:
			void addStudent();
			break;
		case 3:
			void deleteStudent();
			break;
		case 4:
            void input(struct Student &student);
			break;
		case 5:
			return 0;
		default:
			cout<<"�������˴���Ĳ˵��������ѡ��";
		}
	}while(1);
}

void list(){
	cout<<"------ѧ������------"<<endl;
	cout<<"����\t"<<"ѧ��"<<endl;
	for(int i=0;i<nameCount;i++){
		cout<<students[i].name<<"\t"<<students[i].num<<endl;
	}
	cout<<"-----ѧ������-----"<<endl;
}
void addStudent(){
	struct Student student;
	input(student);

	int i=find(student.name);
	if(i==nameCount){
		strcpy_s(students[i].name,student.name);
		students[i].num=student.num;
		nameCount++;
	}
	else{
		students[i].num+=student.num;
	}
}
void deleteStudent(){
	struct Student student;
	input(student);

	int i= find(student.name);
	if(i==nameCount){
		cout<<"wrong"<<endl;
	}else{
		students[i].num-=student.num;
	}
}

void input(struct Student &student){
	 cout<<"���֣�";
	 cin>>student.name;


	cout<<"ѧ�ţ�";
	cin>>student.num;
	cout<<"�ɼ�";
	cin>>student.ranking;
}

int find(char *name){
	int i;
	for(i=0;i<nameCount;i++){
		if(strcmp(students[i].name,name) == 0){
			break;
		}
	}
	return i;
}




