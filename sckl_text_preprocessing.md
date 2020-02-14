# Scikit-Learn의 텍스트 문서 전처리



## BoW(Bag of Words)

문서를 숫자벡터로 변환하는 가장 기본적인 방법. 전체 문서 {d1, d2,..., dn}를 구성하는 고정된 단어장 {t1, t2,...,t(m)}을 만들고 di라는 개별 문서에 단어장에 해당하는 단어들이 포함돼 있는지 표시.

x(ij) = 문서 d(i) 내의 단어 t(j)의 출현 빈도

x(ij) = 0, 만약 단어 t(j)가 문서 d(i) 안에 없으면

​           1, 만약 단어 t(j)가 문서 d(i) 안에 있으면 



## Vectorizer

단어의 개수를 세어 벡터화한다. feature_extraction 서브패키지와 feature_extraction.text 서브패키지에서 제공.

- `DictVectorizer`: 각 단어의 수를 세어놓은 사전에서 BoW 벡터를 만든다
- `CountVectorizer`: 문서집합에서 단어 토큰을 생성하고 각 단어의 수를 세어 BoW 인코딩한 벡터를 만든다.
- `TfidfVectorizer`: `CountVectorizer`와 비슷하지만, TF-IDF 방식으로 단어의 가중치를 조정한 BoW 벡터를 만든다.
- `HashingVectorizer`: 해시함수(hash function)을 사용하여 적은 메모리와 빠른 속도로 BoW 벡터를 만든다. 



## n-그램

단어장 생성에 사용할 토큰의 크기를 결정. 모노그램(1-그램)은 토큰 하나만 단어로 사용하며 바이그램(2-그램)은 두 개의 연결된 토큰을 하나의 단어로 사용. A문장과 B문장이 있을 때, 특정 단어 다음에 어떤 단어가 나오는지, 두 개의 문장이 의미가 비슷한지 알아볼 수 있다. (e.g. 논문표절 검사 시 사용)



## TF-IDF

단어-역문서빈도 기법. 단어 임베딩 기법 중 단어에 가중치를 주기 위한 방법. 기존의BoW(Bag-of-Words) 기법은 단어들이 각각 가지는 중요도를 계산하고 있지 않기 때문에 문서를 살펴볼 때 TF-IDF를 많이 사용한다. (e.g. 뉴스기사들의 카테고리 판별)

1. TF (Term Frequency, 단어빈도)

   TF는 특정 문서 안에 나타나는 특정 단어의 출현빈도를 측정한 것. 따라서 tf(termA, Document1)는 Document1에 등장한 termA의 갯수.

2. IDF (Inverse Document Frequency, 역문서빈도)

   IDF는 DF값을 역수 취한 값이다. 여러 문서에 항상 나타나는 용어는 유의미하다고 말하기가 어렵다. 예를 들어, This, I, and, so 등의 단어들은 어느 문서에서나 자주 쓰이지만 중요한 뜻을 가지는 단어라고 말하기가 어렵다. 따라서 DF값을 반대로 뒤집어 특정용어의 중요도를 나타낸다. IDF(termA, Doc1)은 log(N/DF).

![TFIDF1](https://user-images.githubusercontent.com/51535130/73836889-9f47f500-4853-11ea-85f6-433d74728522.png)

![TFIDF2](https://user-images.githubusercontent.com/51535130/73836898-a3741280-4853-11ea-8960-40a3cfffc112.png)



이때, TF값과 IDF값의 곱으로 단어의 가중치를 나타낸다. TF의 값이 커지면서 동시에 IDF값이 커질 때 TF * IDF값이 가장 극대화된다. 즉 전체 문서에서의 특정 단어 출현횟수(TF)가 높고, 그 단어를 포함하는 문서의 개수는 적을 때 TF*IDF값이 극대화되고 그 단어는 특정 문서를 구별하는 유의미한 단어가 된다.



참고자료:

https://datascienceschool.net/view-notebook/3e7aadbf88ed4f0d87a76f9ddc925d69/

https://blog.naver.com/pasudo123/221064463377

