#include<iostream>
#define MaxSize 100
#define EROOR false
#define OK true
using namespace std;
typedef int Elemtype;
typedef bool Status;
typedef struct{
	Elemtype data[MaxSize];
	int length;
}SqList;
Status InitList(SqList *L){
	L -> length = 0;
	return OK;
}
Status InsertList(SqList *L, int i, Elemtype e){
	if (L -> length == MaxSize)
	{
		return EROOR;
	}
	if(i < 0 || i > L -> length + 1)
		return EROOR;

	if(i <= L -> length){
		for (int k = L -> length - 1; k >= i - 1; --k)
			L -> data[k + 1] = L -> data[k];
	}
	L -> data[i - 1] = e;
	L -> length ++;	
	return OK;
}
Status DeleteList(SqList *L, int i){
	if (L -> length == MaxSize)
	{
		return EROOR;
	}
	if(i < 0 || i > L -> length + 1)
		return EROOR;

	if(i <= L -> length){
		for (int k = i - 1; k < L -> length; ++k)
			L -> data[k] = L -> data[k + 1];
	}
	L -> length --;	
	return OK;
}
Status CreateList(SqList *L, int n){

	for (int i = 0; i < n; ++i){
		L -> data[i] = i;
		L -> length ++;
	}
	return OK;

}
Status visit(Elemtype e){
	cout << e << endl;
	return OK;
}
Status ListEmpty(SqList L){
	if (L.length == 0)	
		return true;
	else
		return false;
}
Status ClearList(SqList *L){
	L -> length = 0;
	return OK;
}
void TravelList(SqList L){
	for (int i = 0; i < L.length; ++i)
	{
		visit(L.data[i]);
	}
}
int ListLength(SqList L){
	return L.length;
}

Elemtype GetElem(SqList L, int i){
	if (i < 1 || i > L.length)
		return EROOR;
	if (L.length == 0)
		return EROOR;
	return L.data[i-1];
}

int main(int argc, char const *argv[])
{
	SqList L;
	//初始化存储链表
	InitList(&L);
	//给定n，生成n个数据结点
	CreateList(&L, 5);
	//给定i，在i个位置之前插入结点
	InsertList(&L,3,8);
	//遍历整个链表
	TravelList(L);
	cout << endl;
	//给定i，删除指定位置的结点
	DeleteList(&L,3);
	TravelList(L);
	//给定i，返回指定位置的数据
	cout << GetElem(L,4);
	//判断是否为空表
	cout << ListEmpty(L);
	//清空链表
	cout << ClearList(&L);
	TravelList(L);
	return 0;
}