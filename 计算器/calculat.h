#include<iostream>
#include <stdio.h>
#include <tchar.h>
#include<stdlib.h>
using namespace std;
#define startsize 100
#define addsize 10
typedef struct{          //数字栈
	int *base;
	int *top;
	int stacksize;
}SqStack;
typedef struct{          //字符栈
	int *base;
	int *top;
	int stacksize;
}SqStackS;
//数字栈
void Init(SqStack *s);
int gettop(SqStack s, int &e);
void push(SqStack *s, int e);
void  pop(SqStack *s, int &e);
int In(char a[7],char e);              //判断是否是运算符

//字符栈
void Init(SqStackS *s);
char gettop(SqStackS s, char &e);
void push(SqStackS *s, char e);
void  pop(SqStackS *s, char &e);

//计算
int  Operation(int a,char t,int b);    //运算
int ReturnOpOrd(char op, char* TestOp);//字符所在的下标位置
char precede(char Aop, char Bop);      //比较优先级

#if !defined(AFX_CALCULAT_H__C6FBB32E_F7EC_44B9_B1EE_410DD8C2A1AB__INCLUDED_)
#define AFX_CALCULAT_H__C6FBB32E_F7EC_44B9_B1EE_410DD8C2A1AB__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class calculat  
{
public:
	calculat();
	virtual ~calculat();

};

#endif // !defined(AFX_CALCULAT_H__C6FBB32E_F7EC_44B9_B1EE_410DD8C2A1AB__INCLUDED_)
