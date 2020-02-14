# 의사결정나무(Decision Tree)

## 정의

여러 가지 규칙을 순차적으로 적용하면서 독립변수 공간을 분할하는 분석 모형. 즉, 데이터의 특성에 대한 질문을 하고, 응답에 따라 데이터를 분류해가며 결정에 다다르는 알고리즘. 범주형 데이터를 분류(Classification)할 때도 쓸 수 있고, 연속형 데이터를 회귀(Regression)할 때도 쓸 수 있다.

- tree = node(질문) + edge(브랜치)

- node의 속성: 1) 범주형   e.g. Y/N

  ​                        2) 연속형   e.g.  > 80

- tree 알고리즘 중 가장 유명하고 많이 쓰는 알고리즘:
  - C5.0 (정보이득)
  - CHAID (카이제곱-범주, F검정-연속)
  - CART  (지니계수-범주, 분산차-연속)

- 과대적합을 막기 위해 각 node에 포함되는 관측데이터값의 최소 갯수를 제한해야 한다.(minsplit)



## 목적

- 세분화(Segmentation) : 데이터를 비슷한 특성을 갖는 몇 개의 그룹으로 분할해 그룹별 특성을 발견하는 경우 또는 각 고객이 어떤 집단에 속하는지를 파악하고자 하는 경우
  e.g. 시장세분화, 고객세분화
  
- 분류(Classification) : 관측개체를 여러 예측변수들에 근거해 목표변수의 범주를 몇 개의 등급으로 분류하고자 하는 경우
  e.g. 고객을 신용도에 따라 우량/불량으로 분류
  
- 예측(Prediction) : 자료에서 규칙을 찾아내고 이를 이용해 미래의 사건을 예측하고자 하는 경우
  
e.g. 고객속성에 따라서 대출한도액을 예측
  
- 차원축소 및 변수선택(Data reduction and variable screening) : 매우 많은 수의 예측변수 중에서 **목표변수에 큰 영향을 미치는 변수들을 골라내고자 하는 경우**
  
- 교효작용효과의 파악(Interaction effect identification) : 여러 개의 예측변수들을 결합해 목표변수에 작용하는 규칙(교호작용효과)을 파악하고자 하는 경우
  
- 범주의 병합 또는 연속형 변수의 이산화(Binning) : 범주형 목표변수의 범주를 소수의 몇 개로 병합하거나 연속형 목표변수를 몇 개의 등급으로 이산화 하고자 하는 경우



## 장/단점

| 장점                                                         | 단점                                                         |
| ------------------------------------------------------------ | ------------------------------------------------------------ |
| - 설명력이 높다.<br />- 빠르고 변수선택능력이 있다.<br />- 변수가 많을 때, 종속변수에 영향이 높은 변수를 선택할 수 있다.<br />- 모델의 시각화가 쉽고 가독성이 높다<br />- 변수의 표준화 작업이 필요 없다. | - 설명변수가 연속형일 때 예측력이 낮다.<br />- 자료를 추가함으로써 나무 구조가 바뀔 수 있다.<br />- 비선형데이터에 적합하지 못하다.<br />- 단일결정트리는 과대적합이 발생하여 일반화하기 어려울 수 있다.<br />- 수리통계적 기반이 아닌 모델이다.<br />- 다양하게 분할 가능한 변수가 다른 변수에 비해 선호되는 문제가 있다. |





## 불순도

의사결정나무는 분류에 있어서 불순도(불확실성)를 최소화시키는 방향으로 학습이 진행된다. 불순도란 데이터가 제대로 분류되지 않고 섞여있는 정도를 말한다.

- 리프의 불순도가 0이 될 때까지 의사결정나무를 뻗어나가기도 하는데 이런 경우 너무 세분화시킨 나머지 과적합(overfitting)되기 쉽다는 단점이 있다.
- 자식의 불순도는 부모의 불순도보다 항상 내려가는 방향이어야 한다.
- 계산을 단순화하기 위해 보통 결정트리에서 분기되는 자식 노드의 개수는 2개로 하는데, 이를 이진 의사결정트리(Binary Decision Tree)라고 한다.



[정보이득(Information Gain)]

정보이득은 어떤 속성을 선택함으로써 데이터를 더 잘 구분하게 되는 것을 의미. 의사결정트리 학습에서 각 노드가 최적으로 브랜치를 만들기 위해서는 <u>정보이득 값이 최대가 되도록 만들어줘야 한다</u>. 어느 특정 노드에서 m개의 자식 노드로 분기(branch)되는 경우 정보이득은 아래의 식으로 정의된다.

![의사결정트리](https://user-images.githubusercontent.com/51535130/72871391-13e84300-3d2e-11ea-9199-8318340ef89b.png)

즉, 자식노드의 불순도가 작을수록 정보이득값은 커진다.



[불순도 측정 방법]

이들 중 정보이득이 최대가 되는 것을 채택한다.

- 지니 인덱스
- 엔트로피
- 분류오류(권장안함)

![의사결정트리](https://user-images.githubusercontent.com/51535130/72872481-cf11db80-3d30-11ea-95b8-f3875bf6897e.png)

![의사결정트리](https://user-images.githubusercontent.com/51535130/72872624-287a0a80-3d31-11ea-96b4-2e3d0e68399c.png)



## 분석과정

1. 목표변수와 관련 있는 설명변수들의 선택
2. 분석목적과 자료의 구조에 따라 적절한 분리기준과 정지규칙을 정하여 의사결정나무 생성
3. 가지치기: 오차를 크게 할 위험이 높거나 부적절한 추론규칙을 가진 가지 제거
   - 너무 깊이가 깊은 모형은 자료를 과대적합하고, 너무 작은 모형은 과소적합의 위험이 있다.
   - node에 속한 데이터가 일정 수 이하일 경우, 분할을 정지하고 사전/사후가지치기 실시
   - 불순도에 따른 분할 측도
4. 이익(gain), 위험(risk), 비용(cost) 등을 고려하여 모형 타당성 평가
5. 분류(classification) 및 예측(prediction) 수행



```R
install.packages("caret")
library(caret)
idx = createDataPartition(iris$Species, p=0.7, list=F)
# createDataPartition: 알아서 비율값을 나눠준다.
# 보통 train / test data는 9:1, 8:2, 7:3 비율로
iris_train[idx,]
iris_test[-idx,]

install.packages("rpart")
library(rpart)
model = rpart(Species~., data=iris_train)
model1 = rpart(Species~., data=iris_train, control=rpart.control(minsplit=30))
# rpart(): 노드의 개수와 각 노드에 포함된 길이 데이터들을 특정 조건에 따라 나눈 뒤 몇 개가 이에 해당하는지 수치화하여 나타내준다.
# minsplit(): 최소가지치기 데이터의 개수. 크게 할 수록 트리가 간단해진다.
plot(model, margin=.2)
text(model, cex = 0.6)
# plot으로 틀을 잡아주고 text로 데이터를 표시하여 시각화
# 조건부 분류규칙이 제일 상단부에 올라옴 
install.packages("rpart.plot")
library(rpart.plot)
prp(m, type=4, extra=2, digits = 3)
# rpart.plot으로 시각화
# 분류규칙이 어떻게 바뀌는게 좋다는 것이 p-value ?

result = predict(model, iris_test, type="class")
# predict(): model을 바탕으로 iris_test의 값을 예측하라
# y값을 분류해야하니 type = "class"
head(result)
result
confusionMatrix(result, iris_test$Species)
# confusionMatrix: 평가매트릭스, 예측치 result와 실측치 iris_test$Species간 오차를 측정해준다.
# Accuracy 및 Kappa값을 볼 것

```

![decisiontree_rplot](https://user-images.githubusercontent.com/51535130/71504695-c78c1d80-28bd-11ea-9831-960cbbd7e378.png)

해석: versicol 49/54 -> 두 조건(Petal.Length<=2.5와 Petal.Width<1.75)을 만족하는 노드에 속하는 해당 개체가 54개이며, 이 가운데 versicolor가 49임을 의미. 따라서 이 노드에 해당하는 새로운 자료는 versicolor로 분류된다.

```R
# Ctree: Conditional Inference Tree
# 속성 30개 이하만 가능하다. 

install.packages("party")
library(party)

m2 <-ctree(Species~ ., data = iris)
m2
plot(m2)
# 최종노드의 막대그래프는 반응변수의 각 범주별 비율 나타낸다.
```

![ctree](https://user-images.githubusercontent.com/51535130/71504776-0b7f2280-28be-11ea-98d4-d80ffc482c22.png)

