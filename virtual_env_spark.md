# Spark(스파크)

### Spark란?

`Hadoop(하둡)`: 대용량 데이터를 분산처리할</u> 수 있는 자바 기반의 오픈소스 프레임워크. 분산처리기술인 MapReduce와 분산저장기술인 HDFS를 사용. 분산 컴퓨팅 방식으로 구축 비용이 저렴하고 비용 대비 데이터 처리가 굉장히 빠르다.

`Spark(스파크)`: 빅데이터를 분산처리하는 오픈소스 프레임워크. 기존의 하둡은 데이터를 끌어올 때 시간 소요가 커서 실시간으로 분석하기가 어렵다는 단점이 있다. 스파크는 하둡에 비해 데이터 처리속도가 월등히 빠르나 분산저장기술(HDFS)이 없어 하둡과 함께 사용. e.g.스트리밍 서비스

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



*참고사이트:

https://spark.apache.org/ 

https://3months.tistory.com/511

https://12bme.tistory.com/434