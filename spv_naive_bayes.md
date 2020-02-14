# 나이브베이즈 (Naive Bayes)



## 정의

목표변수의 범주를 학습시키기 위해 아래의 `베이즈 정리(Bayes' theorem)`를 사용

![bayes](https://user-images.githubusercontent.com/51535130/71504904-8fd1a580-28be-11ea-806c-01659384a4c6.png)

- 사전확률(prior probability): 이미 알고있는 사건의 확률
- 우도(likelihood probability): 이미 알고있는 사건이 발생했다는 조건 하에 다른 사건이 발생할 확률
- 사후확률(posterior probability): 사전확률과 우도를 통해 알게되는 조건부확률



다만, 영향을 끼치는 세부적인 요인(e.g. 무게, 크기, CPU성능 등)에 기반하여 목표변수(e.g. A사의 노트북 a 모델을 구매)의 확률을 구할 수는 있으나, 어떤 요인이 더 중요하고 덜 중요한지는 정확하게 알 수 없다. 이 때문에 각 요인들이 목표변수에 균등하게 영향을 미친다는 결함가정, 즉 Naive의 개념이 등장하게 된다.



---

## **장/단점**

| 장점                                                         | 단점                                                         |
| ------------------------------------------------------------ | ------------------------------------------------------------ |
| - 개념과 이론이 단순하고 계산이 빠르다.<br />- 노이즈 및 결측치가 있어도 잘 수행된다.<br />- 고차원의 데이터셋에 적합하다.<br />- 알고리즘이 단순한데도, 다른 복잡한 분류 알고리즘보다 예측결과가 더 효과적인 경우가 많다.<br />- 대량의 데이터가 있을수록 유리하다. | - 모든 속성이 동등하게 중요하고 독립적이라는 결함가정에 의존한다.<br />- 독립변수들이 범주 형태가 아닌 수치 형태일 경우 정확성이 떨어진다.<br />- 범주 분류문제에는 적합하나, 예측된 범주의 확률값을 활용해야 할 경우에는 적합하지 않다. |



---

## 활용 분야

- 스팸메일 필터
- 텍스트 데이터 등에 근거한 문서 분류
- 침입자 검출, 이상행동 검출, 컴퓨터 네트워크 진단, 질병 진찰, 이탈 예측, 민원 예측 등 빠르고 효율적인 분류가 필요한 분야



---

## R을 활용한 분석

```R
## iris 데이터 예시
idx = createDataPartition(iris$Species, p=0.7, list=F)

iris_train = iris[idx,]
iris_test = iris[-idx,]
table(iris_train$Species)
table(iris_test$Species)

library(e1071)
install.packages("e1071")

# 나이브베이즈 적합, 모델 훈련
naive.result = naiveBayes(iris_train, iris_train$Species, laplace=1)
# laplace(라플라스) 추정: 각 요인이 일어날 확률 중 하나라도 0이 껴있다면 곱셈에 의해 모든 확률을 0으로 만들어버린다. 이를 방지하기 위해 설정해주는 값.

# train 데이터로 학습한 내용을 가지고 test 데이터 예측
naive.pred = predict(naive.result, iris_test, type='class')
# 분류예측결과 도출
table(naive.pred, iris_test$Species)
# 예측모델 평가
confusionMatrix(naive.pred, iris_test$Species) # Accuracy=1: 100% 정확


## 실전문제1. 고객의 속성 데이터를 분석하여 영화 취향을 예측하는 모델을 만들어라.
movie = read.csv('movie.csv', header=T)
nm = naiveBayes(movie[1:5], movie$장르, laplace=0)
# feature가 많지 않으므로 그냥 train과 test를 나누지 않고 진행
result = predict(nm, movie[1:5])
sum(movie$장르 != result)
# 실제결과(movie$장르)와 예측결과(result)를 비교


## 실전문제2. 특정단어들이 포함된 메일이 spam일 확률을 구하라.
spam = read.csv('spam.csv', header=T)
spam[is.na(spam)] = 0
# na값을 0으로 만들어준다.
nm2 = naiveBayes(spam[2:13], spam$메일종류, laplace=0)
result2 = predict(nm2, spam[2:13])
sum(spam$메일종류 != result2)
# 확률값이 0에 가까워서 잘려서 0.000으로 나오는 값들은 분모로 들어갈 수 있게 0.001로 변환해주거나 한다.


```

