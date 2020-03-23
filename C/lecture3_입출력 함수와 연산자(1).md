# 3강. 입출력 함수와 연산자(1)

### 함수란?

특정한 작업(기능)을 수행하도록 설계된 독립적인 프로그램



### C언어에서의 함수

표준(입출력)함수: C언어 자체에서 제공하는 함수

사용자 정의함수: 사용자가 정의하여 사용하는 함수



### 표준출력함수

`printf()`: 화면(monitor)에 여러 종류의 자료를 출력

- 형식: printf("출력양식", 변수1, 변수2, ...)

- 예시: printf("This is an example\n"); printf("A=%d, B=%c\n", a,b);

  ![제목 없음](https://user-images.githubusercontent.com/51535130/77243859-375a3c00-6c52-11ea-8668-3219e82edef1.png)

  출력값:

  ```c
  간단한 출력 프로그램
  c=A, c의 아스키 코드 값은 65
  i=10, j=20, k=30
  ```

`putchar()`: 화면에 1개의 문자를 출력

- 형식: putchar(문자);

- 예시: putchar('A');

  괄호 안에 var, var+1, '\n', 'K', '\007'... 모두 들어갈 수 있다.

  char var='A'; putchar(var+1): A의 아스키코드값65 + 1 = 66. 66에 상응하는 문자값 출력

  \007 = \a: 경고음이 난다.

`puts()`: 화면에 문자열을 출력. s는 string

- 형식: puts(변수);

- 예시: char s[50]="seoul";  puts(s);

  ![제목 없음7](https://user-images.githubusercontent.com/51535130/77244417-efd6ae80-6c57-11ea-95c1-9ea544870aa4.png)

  출력결과:

  ```c
  Computer
  Science
  Computer Science  \n을 사용하지 않아도 자동으로 줄이 바뀌어 출력됨.
  ```



#### 출력양식 변환기호

![제목 없음1](https://user-images.githubusercontent.com/51535130/77243891-77b9ba00-6c52-11ea-997d-4c7b4bcb0774.png)

 

출력양식의 편집 예

![제목 없음2](https://user-images.githubusercontent.com/51535130/77243937-f3b40200-6c52-11ea-8504-ce7f79ff89d7.png)

- 출력결과:

  ```c
  |123|
  |  123|
  |123  |
  |00123|
  | 123.5|
  |0123.45|
  ```



### 표준입력함수

`scanf()`: 키보드를 통해 여러 종류의 자료를 입력받음

- 형식: scanf("입력양식", &변수1, &변수2, ...);

- 기능: 주어진 양식으로 자료를 입력받아 지정된 기억공간(변수)에 저장

- 예시: scanf("%d", &a); 

  ![제목 없음4](https://user-images.githubusercontent.com/51535130/77244016-e2b7c080-6c53-11ea-8bd2-21e2847f6f10.png)

  pragma warning(disable:4996): 권장하지 않는 함수 사용에 대한 경고 메시지 무시

  아니면 scanf_c 사용

  실행결과:

  ```c
  정수를 입력하시오 10 20 (Enter)
  실수를 입력하시오 3.14 6.28 (Enter)
  정수는 10 20 
  실수는 3.140000 6.280000
  ```

`getchar()`: 키보드를 통해 1개의 문자를 입력받음

- 형식: getchar();

- 예시: a=getchar();

  ![제목 없음5](https://user-images.githubusercontent.com/51535130/77244193-d46aa400-6c55-11ea-8bbe-e02a3c47bf87.png)

  출력결과:

  ```c
  문자를 하나 입력하세요
  S  (Enter)
  a = S
  ```

`gets()`: 키보드를 통해 문자열을 입력받음

- 형식: gets(변수);

- 예시: char s[50]; gets(s); s는 문자열

  일반적으로 변수를 선언하면 문자 당 기억공간 하나 차지. 문자열은 문자가 여러개이므로 기억공간 여러개를 갖고있어야 한다.(배열의 개념)

  ![제목 없음6](https://user-images.githubusercontent.com/51535130/77244339-2cee7100-6c57-11ea-8c5d-fdba1541c169.png)

  실행결과:

  ```c
  문자열 입력? 컴퓨터 과학과 (Enter)
  gets()로 문자열 입력= 컴퓨터 과학과
  문자열 입력? 컴퓨터 과학과 (Etner)
  
  // scanf()로 문자열 입력= 컴퓨터 scanf는 공백으로 데이터를 구분하므로
  ```



#### 입력양식 변환기호

![제목 없음3](https://user-images.githubusercontent.com/51535130/77244001-b56b1280-6c53-11ea-93fc-0917d32044aa.png)

