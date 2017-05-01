#include"calculat.h"
int main(){
	int length,val,result,i,jin,look;
	while (1){
		char re[100],c,n;
		printf("请输入要进行计算的一串\n");
		scanf("%s",re);
		length=strlen(re);
		re[length]='#';
		val=0;
		SqStack sint;
		SqStackS schar;
		Init(&sint);
		Init(&schar);
		push(&schar,'#');
		while (re[val]!='#' || gettop(schar, n) != '#'){
			c=re[val];
			if (isdigit(c)){
				if(isdigit(re[val-1])){
					pop(&sint,jin);
					jin=(jin*10)+(c-48);
					push(&sint,jin);
					++val;
				}else{
					push(&sint, c-48);
					++val;
				}
			}else{
					switch (precede(gettop(schar, n), c)){
						case '<':
							push(&schar, c);
							++val;
							break;
						case '=':
							pop(&schar, n);
							++val;
						    break;
						case '>':
							char thela;
							int b, a;
							pop(&schar, thela);
							pop(&sint, b);
							pop(&sint, a);
							int g = Operation(a, thela, b);
							push(&sint, g);
							break;
							}
			}
		}
		result = gettop(sint, result);
		printf("%d\n",result);
		printf("\n");
	}
	return 0;
}
