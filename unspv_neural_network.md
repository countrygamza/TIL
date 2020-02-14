# 인공신경망(NN)

## 정의

생물체의 신경망을 모사하여, 입력 신호와 출력 신호 간의 관계를 모델화하는 기법으로 딥러닝의 기반이 된다.



입력신호 x1, x2, x3... 등의 입력신호(설명변수)들을 중요도에 따라 가중치 w값을 부여하여 가중합을 계산하고, 계산된 값에 활성함수 f를 적용하여 결과값 y를 출력하는 형태. 이를 표현한 것이 아래의 **단층 퍼셉트론**이다.

![nn(1)](https://user-images.githubusercontent.com/51535130/71504923-a24bdf00-28be-11ea-8952-f15dcfded483.png)

퍼셉트론: 뉴런을 도식화한 모델. 한 출력층은 시그마 + 판별함수(f)



하지만 위와 같은 단층 퍼셉트론은 XOR과 같은 비선형문제를 해결할 수 없다. (XOR은 입력값 중 한 쪽만 1일 때만 출력값이 1이고, 둘다 같은 값이면 출력값이 0이 되는 문제) 그래서 아래와 같이 Hidden Nodes를 추가하여 **다층 퍼셉트론**을 만든다.

![nn(2)](https://user-images.githubusercontent.com/51535130/71504946-b42d8200-28be-11ea-805d-9fcdaa56231a.png)



- 한 층 안에 있는 node의 개수 or 중간층(은닉층)의 개수가 중요하다.

- 인공신경망은 SVM과 마찬가지로 w값을 찾을 때 표준화 혹은 정규화를 꼭 해줘야 한다.

- 한 층 안에 있는 node의 개수는 보통 feature(행)의 개수에 비해 너무 적지 않도록 2의 n승을 활용하여 맞춰준다.

  e.g. feature 개수가 100이라고 가정하면, 2의 n승을 기준으로 하여 100 부근의 가장 가까운 값을 찾는다. 128(2의7승)은 너무 크니, 32(2의5승) ~ 64(2의6승) 사이로 대략 node 개수를 설정한다.



---

## 장/단점

| 장점                                                         | 단점                                                         |
| ------------------------------------------------------------ | ------------------------------------------------------------ |
| - 선형적으로 분류할 수 없는 복잡한 비선형 문제에 탁월한 성능을 보인다.<br/>- 분류 및 수치예측 문제에 모두 적용가능하다.<br/>- 통계적 기본 가정이 적고, 유연한 모델을 만든다.<br/>- 데이터 사이즈가 작거나, 불완전 데이터, 노이즈 데이터가 많은 경우에도 다른 모델에 비하여 예측 성능이 우수한 경우가 많다. | - 모델결과(w값) 해석이 어려워서 은닉층의 노드들이 무엇을 표현하는지, 왜 그러한 결과값이 나왔는지 설명이 필요한 모델링에는 적합하지 않다. (블랙박스 모형).<br/>- 나이브 베이즈나 로지스틱 회귀 모형 같은 보다 단순한 분류 알고리즘에 비하여 컴퓨팅 연산에 많은 자원이 필요하다.<br/>- 과적합화나 과소적합이 발생하기 쉽다.<br/>- 전체적 관점에서의 최적해가 아닌 지역 최적해가 선택될 수 있다. |



---

## 활용분야

- 분석 결과의 통찰력을 수립하거나 해석하는 분야보다는 정교한 예측이 필요한 분야에 적합
- 분류나 수치예측 문제에 모두 사용 가능, 특히 복잡한 비선형 분류 문제에 탁월
- 음성 및 필기체 인식, 이미지 인식, 주식 흐름 예측, 기후 예측
- 딥러닝 - 영상 인식, 무인자동차 운전, 드론, 스마트기기 자동화 서비스 등



---

## R을 활용한 분석

```R
## iris 데이터를 활용한 예제1
library(caret)
idx = createDataPartition(iris$Species, p=0.7, list=F)
iris_train
iris_test

# 인공신경망 기법을 사용하기 위해 nnet패키지 로드
library(nnet)
# scale 함수를 이용한 데이터표준화
iris_train_scale = as.data.frame(sapply(iris_train[,-5],scale))
iris_test_scale = as.data.frame(sapply(iris_test[,-5],scale))
iris_train_scale$Species = iris_train$Species
iris_test_scale$Species = iris_test$Species
# train데이터를 이용한 모형 만들기
nnet.result = nnet(Species~., iris_train_scale, size=3) #size는 한 층의 노드 수
# test데이터 평가
nnet.pred = predict(nnet.result, iris_test_scale, type="class")
# 분류결과 도출
table(nnet.pred, iris_test$Species)


## 실전문제1
prob = read.csv('problem.csv', header=T, stringsAsFactors = F)
head(prob)
# 정규화
normalize = function(x){
  return((x-min(x)) / diff(range(x)))   # diff():연속된 값 간의 차이
}
prob[1:30] = normalize(prob[1:30])
head(prob)
# 목표변수 전처리
prob$accident2 = with(prob, ifelse(accident=="suicide" | accident=="violence", 1, 0))
prob = prob[-31]
head(prob)
# 모형 만들기 및 예측
m1 = nnet(accident2 ~., data=prob, size=10)
r1 = predict(m1, prob)
# 실제데이터(prob$accident2)와 예측데이터(r1) 비교하기
# 예측값이 0.9333, 0.0001와 같은 실수가 나오기 때문에 0.5가 넘으면 1, 넘지 않으면 0으로 설정해준다. 
cbind(prob$accident2, r1>0.5)
sum(as.numeric(r1>0.5) != prob$accident2)

# neuralnet 패키지를 이용하여 문제 풀기
install.packages("neuralnet")
library(neuralnet)
xnam = paste("ans", 1:30, sep="")
str(xnam)
fmla = as.formula(paste("accident2 ~ ", paste(xnam, collapse= "+")))
# formula(): 처리할 데이터를 마치 수식처럼 사용하는 함수
m2 = neuralnet(fmla, data=prob, hidden=10)
?neuralnet
plot(m2)
```

<img src="https://user-images.githubusercontent.com/51535130/71504963-c0b1da80-28be-11ea-921d-361161f8d1c5.png" alt="nn(3)"  />