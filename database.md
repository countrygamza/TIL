# 데이터베이스

### 기본개념

![database](https://user-images.githubusercontent.com/51535130/74406586-691dfd00-4e73-11ea-8a4b-52121625acbc.png)

- 기본연산: CRUD

- Server : Client = 1 : n

- 프로토콜(규격): 서버와 클라이언트 간의 규약, 약속. 서버가 만약 TCP를 사용한다고 선언하면 클라이언트도 그 규격을 맞춰줘야 데이터를 주고받을 수 있다.

- Transaction: 데이터베이스의 상태를 변화시키기 위해 수행하는 작업의 단위(세트). 질의어(select, insert, delete, update)를 이용하여 데이터베이스에 접근한다.

  - e.g. 사용자가 게시판에 글올리기 버튼을 누르면 (insert)

    ​       게시판에 최신글이 반영되어 데이터가 바뀐다 (select)

    ​       -> insert + select가 하나의 작업단위

- 데이터베이스는 권한이 있는 사용자만 접근 및 사용 가능

- 인덱스가 아닌 key값으로 데이터를 찾는다.

- Listener: 네트워크를 이용하여 클라이언트에서 오라클 서버로 연결하기 위한 오라클 네트워크 관리자. demon의 일종. 프로토콜에 포함.



<TCP와 UDP의 차이>

| TCP                                               | UDP                                                 |
| ------------------------------------------------- | --------------------------------------------------- |
| 연결형 프로토콜                                   | 비연결형 프로토콜                                   |
| 데이터의 경계 구분 X<br />(Byte-Stream Service)   | 데이터의 경계 구분 O<br />(Datagram)                |
| 신뢰성 있는 데이터 전송<br />(데이터 재전송 존재) | 신뢰성 없는 데이터 전송<br />(데이터의 재전송 없음) |
| 1:1 (Unicast) 통신                                | 1:1, 1:N(Broadcast), N:N(Multicast) 통신            |
| 전송 순서 보장                                    | 전송 순서 바뀔 수 있음                              |
| 수신 여부 확인 O                                  | 수신 여부 확인 X                                    |
| 속도 느림                                         | 속도 빠름                                           |

항상 TCP/IP 방식을 사용하지는 않는 것은 아니다.

- e.g. 인터넷방송은 무조건 수신이 아니라 선택이므로 UDP방식 사용



### 관계형데이터베이스(RDB)

![database(2)](https://user-images.githubusercontent.com/51535130/74409907-22340580-4e7b-11ea-820f-f318dfeebf55.png)

- 대용량 관리에 좋은 패러다임. RDB에서 유의미하며 가장 중요한 단위는 행(row)



### 언어 종류

- 정형데이터: Oracle, MySQL 등
- 비정형데이터: NoSQL, mongoDB, 카산드라 등



### SQL

Structured Query Language. 관계형 DB를 처리하기 위해 고안된 언어로, 데이터베이스에 저장된 데이터를 조회, 입력, 수정, 삭제하는 등의 조작이나, 테이블을 비롯한 다양한 객체(sequence, index 등)들을 생성 및 제어하는 역할을 한다. 모든 row는 column의 구성이 같다. 



SQL의 종류

- <u>데이터 정의어(DDL)</u>: 데이터베이스 관리자나 응용 프로그래머가 테이블과 같은 **데이터베이스의 구조**를 정의하기 위한 언어로, 데이터 사전(data dictionary)에 저장된다.
  - e.g. create, alter, drop, rename, truncate...
- <u>데이터 조작어(DML)</u>: 데이터베이스에 저장된 **데이터를 조작**하기 위해 사용하는 언어로서 데이터검색(Retrieval), 추가(Insert), 삭제(Delete), 갱신(Update) 작업을 수행
  - e.g. select, insert, update, delete...
- <u>데이터 제어어(DCL)</u>: 데이터에 대한 접근 권한 부여 등의 데이터베이스 시스템의 트랜잭션을 관리하기 위한 목적으로 사용되는 언어 
  - e.g. grant, revoke...



### SQL*Plus

SQL언어를 구현하여 Oracle의 RDBMS를 관리할 수 있다.



### Oracle, SQL*Plus 다운로드

- Oracle database XE downloads 는 별도로 하기
- 폴더2에 있는 Components를 폴더1의 Components로 옮기기
  보안갱신수신 체크해제
- sys, system은 기본이나 scott, hr은 앞의 두 계정으로 들어가서 lock을 풀어줘야 사용할 수 있다. (release버전 사용 시)



SQL Plus

```sql
>> exit # 나가기
>> alter user scott identified by tiger account unlock; 
   # scott unlock하여 사용하기
   # tiger는 비밀번호, 맘대로 지정가능
>> alter user hr identified by tiger account unlock;
   # hr unlock하여 사용하기
>> select username from dba_users 
   2 ;
   # 허가된 user(계정)정보 보기
>> connect scott
   # 자기계정으로 데이터에 접근
>> connect system/비밀번호
   # 한번에 다시 system으로 온다.
>> select table_name from tabs;
   # 내가 가진 table정보를 보여주는 tabs(table)를 보여줘라
>> select * from dept;  
   # dept 데이터를 다 보여줘라
>> select dname,loc from dept where dname='research'
   # dname과 loc만 가져와라
```

SQL Developer
```
비밀번호: tiger
포트: 1521
SID: orcl
```