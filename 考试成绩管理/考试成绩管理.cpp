// 考试成绩管理.cpp : 定义控制台应用程序的入口点。
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
		cout<<"--------学生名单--------"<<endl;
		cout<<"（1）查看学生名单"<<endl;
		cout<<"（2）选课"<<endl;
		cout<<"（3）退选"<<endl;
		cout<<"（4）录入成绩"<<endl;
		cout<<"（5）退出程序"<<endl;

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
			cout<<"您输入了错误的菜单项，请重新选择！";
		}
	}while(1);
}

void list(){
	cout<<"------学生名单------"<<endl;
	cout<<"姓名\t"<<"学号"<<endl;
	for(int i=0;i<nameCount;i++){
		cout<<students[i].name<<"\t"<<students[i].num<<endl;
	}
	cout<<"-----学生名单-----"<<endl;
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
	 cout<<"名字：";
	 cin>>student.name;


	cout<<"学号：";
	cin>>student.num;
	cout<<"成绩";
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




