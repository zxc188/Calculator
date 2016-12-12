#include<iostream>
#include <stdio.h>
#include <tchar.h>
#include<stdlib.h>
using namespace std;
#define startsize 100
#define addsize 10
char s[7] = { '+', '-', '*', '/', '(', ')', '#' };
//数字栈
typedef struct{
	int *base;
	int *top;
	int stacksize;
}SqStack;
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
//字符栈
typedef struct{
	int *base;
	int *top;
	int stacksize;
}SqStackS;
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
//运算
int  yunsuan(int a,char t,int b){
	int result;
	switch (t){
	case '+':result = a + b; break;
	case '-':result = a - b; break;
	case '*':result = a*b; break;
	case '/':result = a / b; break;
	}
	return result;
}
char Prior[7][7] = {     // 表3.1  算符间的优先关系
	'>', '>', '<', '<', '<', '>', '>',
	'>', '>', '<', '<', '<', '>', '>',
	'>', '>', '>', '>', '<', '>', '>',
	'>', '>', '>', '>', '<', '>', '>',
	'<', '<', '<', '<', '<', '=', ' ',
	'>', '>', '>', '>', ' ', '>', '>',
	'<', '<', '<', '<', '<', ' ', '='
};
int ReturnOpOrd(char op, char* TestOp) {
	int i;
	for (i = 0; i< 7; i++) {
		if (op == TestOp[i]) return i;
	}
	return 0;
}

char precede(char Aop, char Bop) {
	return Prior[ReturnOpOrd(Aop, s)][ReturnOpOrd(Bop, s)];
}
int main(){
	while (1){
		printf("请输入要进行计算的一串，以#号结束\n");
		char c, n;
		int val;
		SqStack sint;
		SqStackS schar;
		Init(&sint);
		Init(&schar);
		push(&schar, '#');
		cin >> c;
		while (c != '#' || gettop(schar, n) != '#'){
			if (isdigit(c)){
				cin.putback(c);
				cin >> val;
				push(&sint, val);
				c = getchar();
			}
			else{
				switch (precede(gettop(schar, n), c)){
				case '<':push(&schar, c);
					cin>>c; break;
				case '=':pop(&schar, n);
					cin>>c; break;
				case '>':char thela;
					int b, a;
					pop(&schar, thela);
					pop(&sint, b);
					pop(&sint, a);
					int g = yunsuan(a, thela, b);
					push(&sint, g); break;
				}
			}
		}
		int result;
		result = gettop(sint, result);
		cout << "运算结果为：" << result << endl;
		printf("\n");
	}
	return 0;
}
