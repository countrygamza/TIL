# Spark(스파크)

### Hadoop / Spark란?

`Hadoop(하둡)`: 대용량 데이터를 분산처리할</u> 수 있는 자바 기반의 오픈소스 프레임워크. 분산처리기술인 MapReduce와 분산저장기술인 HDFS를 사용. 분산 컴퓨팅 방식으로 구축 비용이 저렴하고 비용 대비 데이터 처리가 굉장히 빠르다.

- 하둡의 저장 시스템은 보통 행 단위로 데이터를 분산저장하는데, parquet는 열 단위로 저장된 데이터들이다.
- 하둡은 데이터를 디스크에서 가져와서 사용한다.

`Spark(스파크)`: 빅데이터를 분산처리하는 오픈소스 프레임워크. 기존의 하둡은 데이터를 끌어올 때 시간 소요가 커서 실시간으로 분석하기가 어렵다는 단점이 있다. 스파크는 하둡에 비해 데이터 처리속도가 월등히 빠르나 분산저장기술(HDFS)이 없어 하둡과 함께 사용. e.g.스트리밍 서비스

- 스파크는 디스크 상에서 읽고 쓰는 것을 방지하기 위해 데이터를 메모리로 가져와서 사용한다. 그래서 메모리를 많이 잡아먹는다.
- features: 벡터 / label: double형, 수치 (e.g. 1->1.0, 2->2.0)
- SparkContext: 한 애플리케이션이 스파크에 연동되려면 우선 프로그램 내에서 관련 스파크 패키지들을 import하고 SparkContext 객체를 생성해야 한다.



 -> download -> archive release -> 2.4.4 ver download

![spark](https://user-images.githubusercontent.com/51535130/74830800-4437f700-5357-11ea-937c-4107886d117c.png)



### AWS(PuTTY)에서 Spark / Scala 사용하기

```python
기존에 설정해놓은 PuTTY, AWS에 접속 후
>>>pwd # 현재 위치 확인
>>>ls  # 현재 위치에 설치된 폴더, 파일 확인
>>>man ls / ls -al
>>>clear # 현재 내역 삭제

Spark 접속하기
>>>cd /opt/spark  # spark가 설치된 경로로 이동

Scala 접속하기
>>>/bin/spark-shell
# Error!! spark-shell은 bin에 설치돼있긴 하나 bin에 대한 실행권한이 없으므로, 내가 권한 갖고있는 상위폴더인 spark에서 실행해줘야 한다. 단, home 디렉토리보다 더 상위인 root계정으로 올라가면 또 권한이 없어서 mkdir 불가능.
scala> var a:Int = 1 # 변수a를 int형으로 선언하고 값을 1로 선언
scala> var a=3 # 값 바꿀 수 있다.(var:가변변수)
scala> val b=3 # 값을 못 바꾼다.(value:상수, constant변수)

함수만들기
scala>def display(x:String)={println(x)}

Class만들기
scala>class Test={
        var a=1
        def set(n:Int)={
          a=n
        }
        def print() = {println(a)}
        }
val tobj = new Test()  # 실체(객체)만들기
tobj.set(10)  # a값 변경하기
tobj.print() >>> 10

# val은 언제 사용?
# 내부의 메소드가 아닌 그 주소지를 바꾸려고 할 때 바꾸지 못하게 하는 기능을 한다.
e.g. var tobj2 = new Test()
>>>tobj = tobj2 >>> error!

Array 만들기
>>>val a = new Array[String](2) >>> Array[String]=Array(null,null)
>>>a(0) = "Hello"
>>>val a2 = Array[String](3) >>> error: type mismatch;
# val로 만들었어도 array는 값 변경 가능. 그러나 list는 sequence가 있어서 값을 변경 못한다.(파이썬 튜플과 비슷)

scala 나가기
>>> exit or ctrl+d
```

### AWS(PuTTY)에서 Spark 접속하기

```python
Anaconda로 가상환경 만들기
>>>conda activate
>>>conda create -n 가상환경이름 python=3.6 jupyter tensorflow # base(cd ~)에서 해야 함

가상환경에서 pyspark, findspark 설치하기
>>>conda activate 가상환경이름 # 가상환경으로 들어가서 anaconda 실행
>>>pip install pyspark=2.3.2
>>>pip install findspark

주피터노트북 띄우기
>>>jupyter-notebook --ip=0.0.0.0 --no-browser --port=포트번호
>>>http://127.0.0.1로 시작하는 url주소 드래그하여 웹에서 열기
```



### FileZilla로 AWS서버에 데이터 전송하기

FileZilla는 오픈소스이며, FTP, SFTP, FTPS를 지원하는 FTP 관리 소프트웨어이다.  즉, TCP/IP 상의 컴퓨터들끼리 파일을 주고받을 때 쓰는 파일 전송 프로토콜이다.

[설정]

```
프로토콜: SFTP
호스트: AWS서버 IP
로그온유형: 키 파일
사용자: lab18
키 파일: aws_azure\ml-multi-a.ppk
```





*참고사이트

아파치스파크 공식: https://spark.apache.org/ 

하둡과 맵리듀스 스파크의 관계: https://3months.tistory.com/511

RDD: https://12bme.tistory.com/434

In-memory computing: https://blog.lgcns.com/176