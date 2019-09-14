#include<iostream>
#define ERROR false
#define OK true
#include <string>
using namespace std;
typedef struct Stu_Managerment
{	
	double math,English,Chinese;
	string name,Id;
	struct Stu_Managerment *next;	
	struct Stu_Managerment *prior;
}Stu_Managerment;
typedef struct Stu_Managerment *LinkList;
typedef int Status;
/**
	初始化链表，生成一个头结点
**/
Status InitList(LinkList *L){
	(*L) = (LinkList)malloc(sizeof(Stu_Managerment));
	if(!(*L))
		return ERROR;
	(*L) -> next = NULL;
	(*L) -> prior = NULL;
	return OK;
}
/**
	创建一个单链表，根据给定的n值插入相对应数量的结点
**/
Status CreateList(LinkList *L, int n){
	LinkList p,r;
	r = *L;
	double math,English,Chinese;
	string name,Id;
	for (int i = 0; i < n; ++i){
		cout << "Please enter student information : math score,English score, Chinese score ";
		cin >> English >> math >> Chinese;
		//生成新结点
		p = (LinkList)malloc(sizeof(Stu_Managerment));
		p -> math = math;
		p -> English = English;
		p -> Chinese = Chinese;
		/*p -> Id = Id;
		p -> name = name;*/
		p -> prior = r;
		r -> next = p;
		r = p;
	}
	r -> next = *L;
	(*L) -> prior = r;
}
/**
	遍历输出链表
**/
void ListTravelHead(LinkList L){
	LinkList p = L -> next;
	while(p != L){
		cout << "Math score: " << p -> math << " English score: "
             << p -> English << " Chinese score: " << p -> Chinese << endl;
         p = p -> next;
	}
}

void ListTravelTail(LinkList L){
	LinkList p = L -> prior;
	while(p != L){
		cout << "Math score: " << p -> math << " English score: "
             << p -> English << " Chinese score: " << p -> Chinese << endl;
         p = p -> prior;
	}
}

Status InsertList(LinkList *L, int i,double English, double math, double Chinese){
	cout << "Please enter student information : math score,English score, Chinese score ";
	LinkList p = (*L) -> next;
	LinkList q,s;
	int j = 1;
	while(p && j < i){
		++j;
		p -> next;
	}
	if (!p || j > i){
		return ERROR;
	}
	s = (LinkList)malloc(sizeof(Stu_Managerment));
	s -> English = English;
	s -> math = math;
	s -> Chinese = Chinese;
	s -> prior = p;
	s -> next = p -> next;
	p -> next = s;
	s -> next -> prior = s;
	return OK;
}

Status DeleteList(LinkList *L, int i){
	LinkList p =(*L) -> next;
	int j = 1;
	while(j < i && p){
		++j;
		p = p -> next;
	}
	if (j > i || !p){
		return ERROR;
	}
	p -> prior -> next = p -> next;
	p -> next -> prior = p -> prior;
	free(p);
}

int main(int argc, char const *argv[])
{
	LinkList L;
	Status i;
	InitList(&L);
	CreateList(&L,2);
	InsertList(&L,1,90,99,88);
	ListTravelHead(L);
	DeleteList(&L, 2);
	ListTravelHead(L);


	//ListTravelTail(L);
	return 0;
}