# 가상환경에서 KoNLPy 사용하기



### 가상환경이란?

![가상환경](https://user-images.githubusercontent.com/51535130/73818711-50896380-4831-11ea-912f-220661cdeaeb.png)

### 아나콘다 가상환경 만들기

````python
# 파이썬 3.6 버전으로 py36이라는 이름의 가상환경 만들기
>conda create --name py36 python=3.6 jupyter  # name 대신 n도 가능

# 가상환경 활성화 & 비활성화
>conda activate py36  # base -> py36으로 바뀜
>conda deactivate

# 버젼 확인하고 업데이트 수시로 시키기
>conda --version
>conda update conda

# 설치된 패키지 확인하고 더 필요한 것들은 따로 설치(e.g. numPy, pandas)
# 설치utile: pip 과 conda 사용
>conda install numpy pandas
````

python 라이브러리 다운로드

3.6버젼: https://www.lfd.uci.edu/~gohlke/pythonlibs/#jpype

3.6버젼: https://pypi.org/project/JPype1-py3/#files

만약 기존 repository에 없는 라이브러리를 설치해야 한다면, 로컬에서 다운받은 뒤 .whl 파일로 가져온다.



### KoNLPy

KoNLPy는 python의 한국어 형태소분석기 라이브러리. Anaconda 가상환경은 JAVA가 홈설정 되어있으므로 KoNLPy를 Anaconda에서 쓰려면 Jpype1을 함께 설치해주어야 한다.

````python
>pip install JPype1_py3-0.5.5.4-cp37-cp37m-win_amd64.whl
>pip install konlpy
````

KoNLPy 공식사이트: https://konlpy-ko.readthedocs.io/ko/v0.4.3/

국립국어원 언어정보나눔터(텍스트자료): https://ithub.korean.go.kr/user/totalSearch/totalSearch.do



### 텍스트분석

가장 작은 단위로 쪼갠 뒤 품사태깅

![XML](https://user-images.githubusercontent.com/51535130/73820692-a6600a80-4835-11ea-94b6-3ef9d48f8807.png)

