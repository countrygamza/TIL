# K-Means Clustering

### K-Means Clustering이란?

K-평균 클러스터링은 사전에 결정된 군집 수 k개의 평균과 각 데이터 점들 간의 거리를 이용하여 전체 데이터셋을 상대적으로 유사한 K개의 군집으로 나눈다. 즉, 군집 수 k에 대하여 군집 내 거리 제곱 합의 합을 최소화하는 것을 목적으로 한다.

![kmeans1](https://user-images.githubusercontent.com/51535130/73841638-58abc800-485e-11ea-96e7-7c6f01245b13.png)

데이터 점 간의 비유사성 측도로 '거리'를 사용하며, 대표적으로 유클리디안의 거리 사용.

![kmeans2](https://user-images.githubusercontent.com/51535130/73841750-9872af80-485e-11ea-8c2e-97c2b2e72983.png)

### 특징

- 개념이 이해하기 쉽고, 다른 clustering 기법에 비해 계산량이 적은 편이라 실행속도가 빠르다.
- 노이즈나 이상치에 민감하고, 사전에 무작위로 군집 중심점을 할당하기 때문에 전역적 최적해가 아닌 지역적 최적해에 빠져 성능이 저하될 우려가 있다.
  - <u>이러한 성능 저하를 줄이기 위해 고안된 것이 K-means++</u>으로, K-means 클러스터링 알고리즘의 초기값을 선택하는 알고리즘이다. 초기값 설정에 추가적인 시간이 들지만 이후 선택된 초기값은 최적의 K-means 답을 찾는 것을 보장한다.
- k를 수학적으로 구할수있는 알고리즘이 없어서 임의로 넣어보고 조정하면서 최적의 k를 설정해야한다는 번거로움이 있다. (초기값이 어떤 값이냐에 따라 계산이 오래 걸릴 수 있음)
- 연속형 변수를 이용한 거리측도에만 사용 가능하다.
- 데이터 관측치가 여러 군집 간 중복될 수 있는 경우를 고려하지 못한다.



### 알고리즘

1) 평균값 k의 개수를 임의로 정한다.

2) 평균값을 기준으로 가장 가까이 있는 데이터값들을 그룹화하여 나눈다.

3) 형성된 각 그룹의 중간값을 찾아 평균값으로 다시 바꾼다.

4) 바뀐 평균값에 따라 다시 그룹화한다.

5) 관측치들이 더 이상 재배정되지 않거나 최대 반복 수에 도달할 때까지 단계 3과 4를 계속한다. 



### R에서의 구현

````R
result2<-kmeans(mydia,3) # 군집수=3
names(result2)
result2

#군집별통계
g1<-subset(mydia, result2$cluster==1)
summary(g1)
g2<-subset(mydia, result2$cluster==2)
g3<-subset(mydia, result2$cluster==3)
summary(g2)
summary(g3)
str(mydia)

#비계층적모델
mydia$cluster<-result2$cluster
head(mydia)
cor(mydia[,-5], method="pearson")
plot(mydia[,-5])
plot(mydia$carat, mydia$price,col=mydia$cluster)
````

````R
> iris2<-iris[,1:4] #목표변수(Species) 제외
> km.out.withness<-c()
> km.out.between<-c()
> for (iin 2:7){ #군집수를k=2~7까지변화시켜가며클러스터링시행
+ set.seed(1)
+ km.out<-kmeans(iris2, centers=i)
+ km.out.withness[i-1]<-km.out$tot.withinss#군집내제곱합의합
+ km.out.between[i-1]<-km.out$betweenss#군집간제곱합의합
+ }
> data.frame(km.out.withness, km.out.between)
````

![kmeans3](https://user-images.githubusercontent.com/51535130/73842676-62cec600-4860-11ea-8065-ff2784dd38ff.png)

위의 결과에서 군집 내 제곱합(km.out.withness)과 군집 간 제곱합(km.out.between)을 군집 개수 k=2부터 k=7까지 변화시켜가며 비교해보았다. k가 증가함에 따라 군집 내 제곱합은 감소하고 군집 간 제곱합은 증가하는데, k=7개가 되면서 오히려 반대 양상을 띤다. 이는 군집 개수가 지나치게 많이 설정됐음을 의미.

![kmeans4](https://user-images.githubusercontent.com/51535130/73842858-c48f3000-4860-11ea-8b05-b6604ff74a09.png)

군집 내 제곱합 감소 폭의 기울기가 급감하는 엘보우 점은 k=3이다.



위키피디아: https://ko.wikipedia.org/wiki/K-%ED%8F%89%EA%B7%A0_%EC%95%8C%EA%B3%A0%EB%A6%AC%EC%A6%98#%EC%99%B8%EB%B6%80_%ED%8F%89%EA%B0%80