# 데이터 수치요약

### 자료의 구분

- 원자료(raw data): 표본에서 조사된 처음 자료
- 양적자료(quantitative data): 수의 크기로 조사된 자료(몸무게, 키, 나이)
- 질적자료(qualitative data): 특성에 의해 구분된 자료(성별, 종교), 수학적 연산 X



### 통계자료의 측정척도

- 명목척도( nominal scale): e.g. 남자1 여자2, 매체유형(프린트물, 휴대폰, PC...)
- 서열척도(ordinal scale): 수의 방향(크기 아님). e.g. 지능 상/중/하
- 구간척도(interval scale): 구간의 값을 모두 취함. 절대영을 가정할 수 없다. e.g. 물가지수(어떤 기준시점을 0으로 놓고 얼마나 변했느냐)
- 비율척도(ration scale): 절대영 가정 가능. e.g. 몸무게, 세금, 허리둘레



### 중간을 나타내는 값

`평균(mean)`: 자료의 총합을 표본의 크기로 나누어준 값. 전체분포가 균형을 이루는 무게중심. 

- 모든 자료가 반영된다
- 이상치에 민감하다
- 유일성을 갖는다 - 하나의 값만 나온다

`중앙값(median)`: 자료를 크기순으로 나열할 때 가장 가운데 오는 값

![제목 없음](https://user-images.githubusercontent.com/51535130/77222237-d4569f80-6b94-11ea-88a1-6e77400848d2.png)

- 이상치의 영향을 받지 않는다
- 중앙값을 중심으로 좌우 분포의 면적이 같다

`최빈값(mode)`: 자료 중 발생 빈도가 가장 높은 값

- 질적 자료에 대한 대표값
- 쉽게 구할 수 있다
- 두 번 이상 발생하지 않으면 값이 존재하지 않는다
- 유일하지 않을 수도 있다

`조화평균(H)`

 ![제목 없음1](https://user-images.githubusercontent.com/51535130/77222339-89895780-6b95-11ea-8650-c01390bcc038.png)

`기하평균(G)`

![제목 없음2](https://user-images.githubusercontent.com/51535130/77222368-cc4b2f80-6b95-11ea-9f58-39b04e851dd7.png)

`가중평균(W)`

![제목 없음3](https://user-images.githubusercontent.com/51535130/77222388-f4d32980-6b95-11ea-9c53-452c5d443ca9.png)



### 변동을 나타내는 값

`범위(Range)`: 자료의 최대값에서 최소값을 뺀 값 = Xmax-Xmin

`사분위수 범위(IQR, Interquartile Range)`: 사분위수 중 1사분위수와 3사분위수의 차이 

`상자그림(Box plot)`: 다섯수치요약(최소값, Q1, Q2, Q3, 최대값)을 그래프로 나타낸 것

![제목 없음4](https://user-images.githubusercontent.com/51535130/77222593-0b7a8000-6b98-11ea-8931-a32a917c3472.png)

- 특이점 찾을 때:
  - 사분위수의 1.5배한 step을 구한다.
  - step = 1.5 * IQR
  - Q1-1.5*IQR, Q3+1.5 * IQR
  - 위를 벗어나는 바깥쪽 관찰치를 특이점으로 정의

`표준편차(Standard Deviation)`: 평균으로부터 관찰값까지의 거리의 평균, 자료가 평균을 중심으로 얼마나 광범위하게 분포하고 있는가를 나타냄.  다 더하면 0.

`분산(Variance)`: 표준편차의 제곱

![제목 없음5](https://user-images.githubusercontent.com/51535130/77222663-a1aea600-6b98-11ea-83dc-dd44f8185825.png)

`변이계수(Coefficient of Variation)`: 측정단위가 다르거나 자료 값의 차이가 큰 경우 표준편차를 평균으로 나눈 통계량  e.g. 초등학생의 몸무게와 성인의 몸무게 비교

![제목 없음6](https://user-images.githubusercontent.com/51535130/77222749-45985180-6b99-11ea-8f04-15136245a47d.png)



### R을 활용한 그래프 그리기

R Commander 설치: install.packages("Rcmdr")

MDI -> SDI로 변경: Program files - Rconsole - MDI=yes -> no