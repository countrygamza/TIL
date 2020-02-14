# DBSCAN

### DBSCAN이란?

밀도 기반 클러스터링 (Density-based clustering). k-means가 중심 기반 클러스터링이라면, DBSCAN은 <u>"동일한 클래스에 속하는 데이터는 서로 근접하게 분포할 것이다"</u>라는 가정을 기반으로 한다.

중심 기반 클러스터링은 클러스터의 중심을 기준으로 가까운 데이터들을 클러스터에 포함시키므로 원의 형태로 클러스터 모양이 형성되는 반면, 밀도 기반 클러스터링은 밀도 기반으로 서로 이웃한 데이터들을 같은 클러스터에 포함시키므로 불특정한, 기하학적 모양의 클러스터가 형성된다.

##### k-means와의 차이점

- 클러스터의 수를 지정할 필요 없다. (알고리즘이 찾아줌)
- 클러스터링을 수행하는 동시에 노이즈 데이터도 분류 가능하므로, outlier에 의해 클러스터링 성능이 하락하는 현상을 완화시켜준다.
- 데이터가 입력되는 순서에 따라 클러스터링 결과가 변한다.
- 데이터의 특성을 모를 경우, 알고리즘의 적절한 hyper-parameter를 설정하기 어렵다.



### DBSCAN의 주요개념

점 p가 있다고 할 때, p에서부터의 거리 e(epsilon) 내에 점이 m(minPts)개 있으면 하나의 군집으로 인식한다고 가정. 이때 거리 e 내에 점 m개를 가지고 있는 점 p를 core point(중심값)이라고 한다. 알고리즘 사용 시 epsilon값과 minPts는 hyper-parameter이다.(미리 인자로 전달)

- 중심점(core point): 점 p를 중심으로 epsilon반경 내에 점이 n개(=minPts) 이상 있으면 하나의 군집으로 판단이 되고, 점 p는 core point가 된다.

  -> 만약 p를 중심으로 하는 반경 내에 다른 core point P가 포함되어 있다면, p와 P는 연결되어 있다고 판단하여 하나의 군집으로 묶임

- 주변거리(ϵ, epsilon반경):  점 p로부터의 거리, 반경
- minPts: 한 군집이 최소한 가지고 있어야 하는 점의 개수
- 경계점(border point): 점 p2는 epsilon 반경 내의 점이 n개에 못 미친다고 가정. 따라서 core point는 되지 못하지만, 앞의 점 p를 core point로 하는 군집에는 속하므로 경계점이 된다.
- 노이즈(noise point): 어떤 점을 중심으로 하더라도 minPts=n을 만족하는 범위에 포함되지 않는 outlier





참고자료

https://untitledtblog.tistory.com/146

https://bcho.tistory.com/1205

https://blog.naver.com/thinketing/221571128034