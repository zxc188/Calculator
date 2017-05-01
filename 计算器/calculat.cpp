// calculat.cpp: implementation of the calculat class.
//
//////////////////////////////////////////////////////////////////////

#include "calculat.h"

#include "calculat.h"
char s[5] = { '+', '-', '*', '/', '#' };
char Prior[5][5] = {     
	'>', '>', '<', '<',  '>',
	'>', '>', '<', '<',  '>',
	'>', '>', '>', '>',  '>',
	'>', '>', '>', '>',  '>',
	'<', '<', '<', '<',  '='
};
//数字栈的操作
void Init(SqStack *s){
	s->base = (int*)malloc(sizeof(int)* 100);
	if (!s->base)exit(-1);
	s->top = s->base;
	s->stacksize = startsize;
}
int gettop(SqStack s, int &e){
	if (s.top == s.base)return 0;
	e = *(s.top - 1);
	return e;
}
void push(SqStack *s, int e){
	if (s->top - s->base >= s->stacksize){
		s->base = (int *)realloc(s->base, (s->stacksize + addsize)*sizeof(int));
		if (!s->base)exit(-1);
		s->top = s->base + s->stacksize;
		s->stacksize += addsize;
	}
	*s->top++ = e;
}
void  pop(SqStack *s, int &e){
	if (s->top == s->base)exit(-1);
	e = *--s->top;
}
//判断是否是运算符
int In(char a[7],char e){
	int s = 0;
	for (int i = 0;i<7; i++){
		if (e == a[i]){
			s=1;
			break;
		}
	}
	return s;
}

//字符栈的操作
void Init(SqStackS *s){
	s->base = (int*)malloc(sizeof(char)* 100);
	if (!s->base)exit(-1);
	s->top = s->base;
	s->stacksize = startsize;
}
char gettop(SqStackS s, char &e){
	if (s.top == s.base)return 0;
	e = *(s.top - 1);
	return e;
}
void push(SqStackS *s, char e){
	if (s->top - s->base >= s->stacksize){
		s->base = (int *)realloc(s->base, (s->stacksize + addsize)*sizeof(char));
		if (!s->base)exit(-1);
		s->top = s->base + s->stacksize;
		s->stacksize += addsize;
	}
	*s->top++ = e;
}
void  pop(SqStackS *s, char &e){
	if (s->top == s->base)exit(-1);
	e = *--s->top;
}

//计算操作
int  Operation(int a,char t,int b){
	int result;
	switch (t){
	case '+':result = a + b; break;
	case '-':result = a - b; break;
	case '*':result = a*b; break;
	case '/':result = a / b; break;
	}
	return result;
}
int ReturnOpOrd(char op, char* TestOp) {
	int i;
	for (i = 0; i< 5; i++) {
		if (op == TestOp[i]) return i;
	}
	return 0;
}

char precede(char Aop, char Bop) {
	return Prior[ReturnOpOrd(Aop, s)][ReturnOpOrd(Bop, s)];
}

calculat::calculat()
{

}

calculat::~calculat()
{

}
