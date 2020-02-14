# 머신러닝(Machine Learning)

## 머신러닝이란?

> 컴퓨터 과학의 영역에 속하는 인공지능의 한 분야로서 컴퓨터 프로그램이 어떤 것에 대한 학습을 통해 기존의 모델이나 결과물을 개선하거나 예측하게끔 구축하는 과정.  즉, 훈련 데이터에서 여러 가지 통계적, 컴퓨터 알고리즘적, 수치적 방법 등을 통해서 규칙성이나 패턴을 학습한 뒤 훈련에 사용하지 않은 새로운 데이터(테스트 데이터)를 통해서 필요한 답을 얻어내는 것을 의미

![머신러닝](https://user-images.githubusercontent.com/51535130/71504872-6a449c00-28be-11ea-9e71-1aaa0255ac4a.png)

---



## 머신러닝의 종류

### 1. 지도학습(Supervised Learning)

설명변수(혹은 독립변수, 특성, Feature 등)와 목적변수(혹수, 종속변수, label 등) 간의 관계성을 표현해내거나 미리 예측하는 것에 초점

[features] x0, x1, x2, x3 ... xi -------> [label] y 

*label은 범주형(e.g. 카이제곱) or 연속형(e.g. T분포)*



#### 지도학습 유형

- **분류예측(classification)**

  - **K-최근접 이웃(K-Nearest Neighbors)**

    특정 데이터 좌표점과 다른 나머지 데이터 좌표점들 간 거리에 기반을 두어 가장 가까운 K개점들의 목적변수(y) 값들의 다수결로 분류. 게으른 학습(Lazy Learning)

    장점: 로직이 간단 - 가까운 값들과 비슷할 것이다!

    단점: 정확도가 떨어지는 편

    ```R
    install.packages("ggvis")
    library(ggvis)
    library(class)
    iris_train[idx,]
    iris_test[-idx,]
    set.seed(1234)  
    # set.seed(): 랜덤추출할 때 내가 지정한 임의의 숫자를 기준으로 '진짜' 무작위 숫자가 나올 수 있도록 설정. (보통 랜덤샘플링 해도 어느 정도 비슷한 숫자가 나와서)
    
    model = knn(train=iris_train[,-5], test=iris_test[,-5], cl=iris_train$Species, k=3)
    # 레이블값 빼줘야 해서 [,-5] ->y값을 포함하면 안된다
    # k=3은 임의로 찍은 것
    
    summary(model)
    # 다른 모델은 predict()에 따로 test데이터를 넣어줘야 하는데, knn은 아예 학습할 때부터 test데이터를 넣어주므로 따로 predict()를 할 필요 없이 예측치가 바로 나온다.
    confusionMatrix(model, iris_test[,5])
    ```

  - **로지스틱 회귀(Logistic Regression)**

    설명변수 값이 주어졌을 때, 목표변수 값이 특정 부류에 속할 확률이 로지스틱 함수 형태를 따른다고 가정하여 최대우도 추정방법으로 목표변수의 확률을 추정

  - **인공신경망 분석(Artificial Neural Network)**

  - **의사결정트리(Decision Tree)**

    목표변수와 가장 연관성이 높은 변수의 순서대로 불순도나 엔트로피 등이 낮아지는 방향으로 나무 형태로 가지를 분할하면서 분류 규칙을 만들어냄. 오차가 날 확률이 높다는 단점이 있다.

  - **서포트 벡터 머신(Support Vector Machine)**
  
  - **나이브 베이즈(Naive Bayes)**
  
  - **앙상블 기법(랜덤 포레스트 등)**
  
    랜덤포레스트: 주어진 데이터로부터 여러 개의 다양한 의사결정트리를 만들어 각 의사결정트리의 예측결과를 투표형식으로 집계하여 최종 분류 결과를 결정하는 앙상블 형태
  
    ```R
    # randomForest
    library(rpart)
    library(e1071)
    library(randomForest)
    rdf = randomForest(Species~., data=iris_train, importance=T)
    # importance=T 변수중요도값을 볼 수 있음
    rdf.pred = predict(rdf, newdata=iris_test, type="response")
    #type = "response" 레이블값을 그대로 보여준다
    confusionMatrix(rdf.pred, iris_test$Species, positive="versicolor")
    # 예측치 rdf.pred와 실측치 iris_test$Species 사이의 차를 보여줘라
    
    ```
  
- **수치예측(regression. 혹은 회귀)**

  - **선형 회귀(Linear Regression)**
  - **확장된 회귀분석(e.g. 다항회귀, 비선형회귀, 벌점화 회귀 등)**
  - **인공신경망 분석(Artificial Neural Network)**
  - **의사결정트리(Decision Tree)**
  - **서포트 벡터 머신 회귀(Support Vector Machine(Regression))**
  - **PLS(Partial Least Squares)**
  - **앙상블 기법(랜덤 포레스트 등)**



### 2. 비지도학습(Unsupervised Learning) 혹은 자율학습

y값에 대한 정보가 없이 학습이 이루어지는 형태. 예측 문제보다는 주로 현상의 기술이나 특징 도출, 패턴 도출 등의 문제에 많이 활용된다.

x0  x1  x2  x3  ...  xi

 .     .     .     .           .  행1

 .     .     .     .           .  행2

행 간의 유사성(거리 벡터)이 중요하다.



#### 비지도학습 유형

- 군집화(Clustering): 어디에 속했는지에 대한 정답이 없이 학습
  - 계층적 군집화
  - 비계층적 군집화
- 차원축소기법
- 연관관계분석(장바구니분석)
- 자율학습 인공신경망(SOM 등)
- 딥러닝(Deep Learning)



### 3. 강화학습(Reinforcement Learning)



---



## 혼동행렬(Confusion Matrix)

​                                                                              **예측 범주값**

|      | Y                           | N                           |
| ---- | --------------------------- | --------------------------- |
| Y    | O<br />(TP: True Positivie) | X<br />(FN: False Negative) |
| N    | X<br />(FP: False Positive) | O<br />(TN: True Negative)  |

**실제 범주값**

---



## 머신러닝 모델 평가 지표

| 평가지표                                               | 계산식                                                       | 지표의 의미                                                  |
| ------------------------------------------------------ | ------------------------------------------------------------ | ------------------------------------------------------------ |
| 정확도(accuracy)                                       | (TP+TN) / (TP+TN+FP+FN)                                      | 실제 분류 범주를 정확하게 예측한 비율<br/>(전체 예측에서 참 긍정(TP)과 참부정(TN)이 차지하는<br/>비율) |
| 오차비율<br/>(error rate)                              | (FP+FN) / (TP+TN+FP+FN)                                      | 실제 분류 범주를 잘못 분류한 비율<br/>(1-정확도 와 동일함)   |
| 민감도<br/>(sensitivity)<br/>= 참 긍정률<br/>(TP Rate) | (TP) / (TP+FN)                                               | 실제로 ‘긍정(positive)’인 범주 중에서‘긍정’으로<br/>올바르게 예측 (True Positive)한 비율<br/>(혹은 Recall, Hit Ratio, TP Rate 로도 지칭함) |
| 특이도<br/>(specificity)                               | (TN) / (TN+FP)                                               | 실제로 ‘부정(negative)’인 범주 중에서‘부정’으<br/>로 올바르게 예측 (True Negative)한 비율 |
| 거짓 긍정률<br/>(FP Rate)                              | (FP) / (TN+FP)                                               | 실제로 ‘부정(negative)’인 범주 중에서 ‘긍정’으<br/>로 잘못 예측 (False Positive)한 비율 = 1-특이도 |
| 정밀도<br/>(precision)                                 | (TP) / (TP+FP)                                               | ‘긍정(positive)’으로 예측한 비율 중에서 실제로<br/>‘긍정’(True Positive)인 비율 |
| F-Measure<br/>(F1-Score)                               | {2*(precision)*(recall) } ÷<br/>(precision+recall)<br/>= (2*TP)/(2*TP+FP+FN) | 정밀도와 민감도(재현율)을 하나로 합한 성능 평가지<br/>표(정밀도와 민감도(재현율)의 조화 평균) 로서, 0~1<br/>사이의 범위를 가지며, 정밀도와 민감도 양쪽 다 클<br/>때 F-Measure도 큰 값을 가지는 특성이 있음 |
| 카파 통계<br/>(Kappa<br/>Statistic)                    | {Pr(a) –Pr(e)}÷ (1-Pr(e))                                    | 모델의 예측값과 실제값이 우연히 일치할 확률을 제<br/>외한 뒤의 값 (0~1까지의 값을 가지며 1에 가까울수<br/>록 모델의 예측값과 실제값이 정확히 일치하며, 0에<br/>가까울수록 모델의 예측값과 실제값이 불일치하게<br/>됨) |