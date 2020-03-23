// 예제 2-1. 다음은 C언어의 자료형에 대한 크기를 나타내는 프로그램이다.

#include <stdio.h>
int main(){
	printf("char 자료형 크기: %d byte\n", sizeof(char));
	printf("signed char 자료형 크기: %d byte\n", sizeof(signed char));
	printf("unsigned char 자료형 크기: %d byte\n", sizeof(unsigned char));
} 
