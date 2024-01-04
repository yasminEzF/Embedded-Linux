#include <add.h>
#include <sub.h>
#include <mul.h>
#include <div.h>
#include <mod.h>
#include<stdio.h>
int main() {
	
	printf("%d + %d = %d\n",1,2,add(1,2));
	printf("%d - %d = %d\n",4,5,sub(4,5));
	printf("%d x %d = %d\n",3,6,mul(3,6));
	printf("%d / %d = %f\n",8,4,div(8,4));
	printf("%d % %d = %d",14,10,mod(14,10));	
	
	return 0;
}
