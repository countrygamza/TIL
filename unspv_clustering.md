# 군집화(clustering)

## 정의

 대표적인 자율학습(비지도학습)으로써, 데이터들에 존재하는 유사성 혹은 비유사성에 근거하여 패턴화를 하는 기법. 무엇을 예측하기 위해 실행하기보다는 지식 발견 그 자체를 위한 목적으로 주로 <u>유사한 사람들을 그룹화 및 세분화</u>하여 비즈니스에 활용하거나 유사한 개체들을 묶어 필요한 정보를 압축하여 활용하거나, <u>유사성 기반의 그룹화를 응용하여 역으로 이상치(Outlier) 등의 특이점 혹은 비정상 패턴을 찾는 분야</u> 등에 활용된다.

 분류목적의 지도학습 머신러닝에서는 목적변수(Y)의 라벨이 주어진 상태에서 해당 목적변수의 범주 속성으로 분류되는 개체를 유사성이나 다른 기준으로 판별하는 것이 목적이었다면, 군집분석은 목적변수가 없는 상태에서 유사한 특성을 가진 개체끼리 그룹화를 한다는 점이 다르다.



---

## 주요기법

![cluster](https://user-images.githubusercontent.com/51535130/71506368-fdcc9b80-28c3-11ea-872a-5c38c5d77951.png)

- **계층적 클러스터**:

  각 관측치는 자신을 하나의 최초 군집으로 시작. 이후 유사도를 이용해 한 번에 두 개씩 모든 군집들이 하나의 군집이 될 때까지

  - 대략적인 그룹(K)의 개수 파악
  - cuttree(계층결과, k=군집수)

![cluster(1)](https://user-images.githubusercontent.com/51535130/71509179-c82cb000-28cd-11ea-9601-6bdddbe9e98b.png)

```R
library(ggplot2)
data(diamonds)
head(diamonds)
str(diamonds)

# 테스트데이터 뽑기
t = sample(1:nrow(diamonds),1000) 
test = diamonds[t,]
dim(test)
test
mydia = test[c("price","carat","depth","table")] #subset 써도 됨

# hclust()를 활용한 계층적 군집화 - 거리값을 이용
# method="ave": 군집의 대표값으로 평균을 쓰겠다.
# hclust 할 때 원본을 넣으면 안되고 거리값을 구해놓은 매트릭스(dist(mydia))를 넣음
result = hclust(dist(mydia), method="ave") 

# 시각화
# plot을 보고 눈대중으로 대충 그룹을 나눈 다음에 각각의 데이터를 보며 성격을 파악한다.
plot(result, hang=-1)

```

<img src="https://user-images.githubusercontent.com/51535130/71509602-38880100-28cf-11ea-83e9-a9e11c5a0200.png" alt="cluster(2)" style="zoom:80%;" />



---

## 활용분야

- 마케팅 등 분야에서의 고객세분화(Segmentation)
- 질병 및 환자 특성에 따른 유사 그룹화
- 개체 유사성에 근거한 문서 분류
- 디지털 이미지 인식을 통한 사물 및 안면 인식
- 금융 분야에서의 알려진 군집 이외의 사용패턴 식별(신용카드 사기, 보험료 과다청구 등)
- 공학 분야에서의 이상치 탐지(제조과정에서의 불량품 자동탐지, 통화음질개선을 위한 노이즈 구별 등)
- 컴퓨터 네트워크에 비인가된 침입 등 비정상적 행위 탐지



## 평가척도

- 내부평가 (internal evaluation):

  - 데이터 집합을 클러스터링한 결과 그 자체를 놓고 평가하는 방식. 클러스터링 내 높은 유사도를 갖고, 클러스터 간 낮은 유사도를 가진 결과물에 높은 점수를 준다. 오로지 데이터를 클러스터링한 결과물만을 보고 판단하기 때문에 점수가 높다고 해서 실제 참값에 가깝다는 것을 반드시 보장하지는 않는다.

  - 실루엣 기법:

    데이터들이 얼마나 잘 클러스터링 되었는지를 나타내는 하나의 기법. 실루엣이 1에 가까울수록 데이터는 올바른 클러스터에 분류된 것이며, -1에 가까울수록 잘못된 클러스터에 분류됐음을 나타낸다.

- 외부평가(external evaluation):

  - 클러스터링의 결과물은 클러스터링에 사용되지 않은 데이터로 평가. 다시 말해 클러스터링의 결과물을 전문가들이 미리 정해놓은 답안지를 이용하여 알고리즘의 정확도 평가.



참고자료: [https://ko.wikipedia.org/wiki/K-%ED%8F%89%EA%B7%A0_%EC%95%8C%EA%B3%A0%EB%A6%AC%EC%A6%98#%EB%82%B4%EB%B6%80_%ED%8F%89%EA%B0%80](https://ko.wikipedia.org/wiki/K-평균_알고리즘#내부_평가)