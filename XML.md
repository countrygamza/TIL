# XML

### XML이란?

eXtensible Markup Language(확장될 수 있는 표시언어)로, 마크업 언어(HTML)를 정의하기 위한 확장가능한 언어. HTML에서는 이미 약속한 태그들(e.g. <h1></h1>은 글자를 키우는 태그)만 사용가능하다면, XML 태그는 사용자 임의로 만들 수 있고 데이터를 기술할 수 있다. 따라서 XML은 데이터를 구조화시켜서 저장하고 전달할 목적으로 만들어졌고, HTML은 동일한 데이터를 표시하고 꾸며서 보여주려는 목적으로 만들어졌다.



### XML의 구성요소

- DTD(Document Type Definition): 작성하는 문서가 어떤 문서인지 정의
- Style Sheet: 글, 문단 등에 대한 양식과 서식에 해당하는 문서
- 확장성 연결 언어:
  - XLink 방식: 1 대 다, 다 대 1 관계를 통해 마크업 언어를 링크시킬 수 있다.
  - XPointer: 문서의 특정 부분만 링크시킬 수 있다.
- Parser: xml 해석을 위한 프로그램



### XML의 특징

- 다른 시스템끼리 다양한 종류의 데이터를 손쉽게 교환할 수 있도록 해준다.
- 새로운 태그를 만들어 추가해도 계속해서 동작하므로 확장성이 좋다.
- 데이터를 보여주지 않고, 데이터를 전달하고 저장하는 것만을 목적으로 한다.
- 텍스트 데이터 형식의 언어로, 모든 XML문서는 유니코드 문자로만 이루어진다.



### AJAX

JavaScript의 라이브러리 중 하나로, Asynchronous Javascript And XMl(비동기식 자바스크립트와 xml)의 약자. 브라우저가 갖고 있는 XMLHttpRequest 객체를 이용해서 전체 페이지를 새로 고치지 않고도 페이지의 일부만을 위한 데이터를 로드하는 기법. 즉, JavaScript를 사용한 비동기 통신, 클라이언트와 서버 간 XML 데이터를 주고받는 기술.

![ajax](https://user-images.githubusercontent.com/51535130/75011113-28049900-54c2-11ea-98b0-35e18f9e8d4a.png)

[AJAX의 특징]

- XML을 통해 데이터 주고 받는다.
- 비동기식 통신: 요청 결과가 아직 오지 않더라도 다음 코드를 수행. 명령을 정의만 해놓고 다음 코드로 간 뒤, 응답이 오면 실행하는 call back 함수. 병렬 구조로 밑으로 내려가며, 명령어 순서대로 수행되지 않을 수 있다.
  - e.g. 인스타그램: 화면의 UI를 유지하면서 데이터는 계속 갖고 온다.
- 장점: 화면전환이 빠르다.
- 단점: 보안에 굉장히 취약하다.



### 웹 렌더링

```python
# Anaconda prompt에서 http 규격에 맞춰서 요청
>> python -m.http.server --cgi8000 # 포트번호 8000. 0~1024는 피하기.
   # cgi-bin 폴더에는 .py만 들어가야 하므로, 순수 html 파일일 경우 base 폴더에 넣는다.

# 로컬: http://127.0.0.1.8000/파일이름.html
```



참고사이트

XML이란: https://asfirstalways.tistory.com/98

XML기초: http://tcpschool.com/xml/xml_intro_basic