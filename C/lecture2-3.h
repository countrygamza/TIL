//예제 2-3. 매크로 정의가 된 자신의 헤더 파일을 만들어서 사용하는 프로그램
// 주의: exam2-3.h파일과 exam2-3.c파일로 작성하되, 예제의 경우, 2개의 파일은 같은 디렉토리에 존재해야함

 #include <stdio.h>
 #define ADD(x, y) ((x)+(y))
 #define SUB(x, y) ((x)-(y))
 
