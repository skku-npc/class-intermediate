# 2. 완전탐색과 분할 정복
PS를 할 때 가장 먼저 고려해야할 풀이는 문제에 주어진 그대로 "무식하게 푸는 것"입니다. 간과하기 쉬운 것이, 이 무식한 풀이로 풀리는 문제가 꽤 많은데 불구하고 많은 사람들은 쉬운 문제에 너무 어렵게 접근하곤 합니다. 오늘 다룰 알고리즘은 완전 탐색(brute-force)과 분할 정복(divide-and-conquer)입니다.  

## 완전 탐색 (brute-force) 👊
PS에서 "무식하게 푼다"라고 함은 가능한 경우의 수를 일일이 나열하면서 답은 찾는 방법을 의미합니다.  
이 알고리즘을 <b>완전 탐색(brute-force)</b>이라고 부르죠.  

이게 전부입니다. 처음 접하는 분들은 이런 것도 알고리즘으로 다룰 필요가 있을까 싶겠지만, 사실 컴퓨터와 가장 잘 어울리는 알고리즘이 완전 탐색입니다. 컴퓨터의 빠른 연산 속도를 잘 이용하기에 좋은 방법이죠. 그리고 이 완전 탐색을 구현하는 것이 생각만큼 쉽지만은 않습니다. 완전 탐색 문제를 잘 풀려면 충분한 구현력을 갖춰야죠.  

바로 문제 풀이를 통해 알아보겠습니다.  

### 예제 🎲
18111번: 마인크래프트 ([문제](https://www.acmicpc.net/problem/18111), [해설](https://github.com/skku-npc/class-intermediate/blob/master/2.%20Brute%20Force%20%26%20Divide%20and%20Conquer/18111.cpp))  

---  

## 백트래킹 🚩
완전 탐색 문제에서 흔하게 같이 나오는 개념이 백트래킹입니다. [위키 백과](https://ko.wikipedia.org/wiki/%ED%87%B4%EA%B0%81%EA%B2%80%EC%83%89)의 설명에 따르면 모든 조합을 시도하되, 탐색 중에 오답을 만나면 탐색을 중단하고 바로 이전 단계로 돌아가 다른 조합을 시도하는 것입니다. 깊이 우선 탐색(DFS)과 비슷하지만, 탐색을 끝까지 진행하지 않는다는 점에서 더 좋은 성능을 보여줍니다.  

말로 설명해도 이해가 어려울듯 하니, 바로 예제 풀이로 알아보겠습니다.

<img src="https://upload.wikimedia.org/wikipedia/commons/thumb/2/2c/Depthfirst.png/375px-Depthfirst.png" width=400>

### 예제 🎲
6987번: 월드컵 ([문제](https://www.acmicpc.net/problem/6987), [해설](https://github.com/skku-npc/class-intermediate/blob/master/2.%20Brute%20Force%20%26%20Divide%20and%20Conquer/6987.cpp))  

---  

## 분할 정복 (divide-and-conquer) ✂
분할 정복은 가장 유명한 알고리즘 디자인 패러다임입니다. 분할 정복 페러다임을 차용한 알고리즘들이 많기에, 잘 짚고 넘어가는 것이 좋습니다. 분할 정복(divide-and-conquer)이란 문제를 비슷한 크기를 가진 부분 문제들로 나누는 것입니다. 분할 정복을 사용하는 알고리즘들은 대개 세 가지의 구성 요소를 가지고 있습니다.  

1. 문제를 더 작은 문제로 분할하는 과정(divide)  
2. 각 문제에 대해 구한 답을 원래 문제에 대한 답으로 병합하는 과정(merge)  
3. 더이상 답을 분할하지 않고 곧장 풀 수 있는 매우 작은 문제(base case)  

분할 정복의 가장 큰 장점은 빠른 속도입니다. 많은 경우 <img src="https://latex.codecogs.com/svg.latex?O(log(n))"/> 또는 <img src="https://latex.codecogs.com/svg.latex?O(n%20log(n))"/> 의 시간복잡도를 갖습니다. 
참고로 <img src="https://latex.codecogs.com/svg.latex?O(log(n))"/> 의 알고리즘은 <img src="https://latex.codecogs.com/svg.latex?O(1)"/> 에 가까운 실행 속도를 보입니다.  

<img src="https://miro.medium.com/max/2544/1*yiyfZodqXNwMouC0-B0Wlg.png" width=400>

문제 풀이를 통해 어떻게 분할 정복이 쓰이는지 알아보겠습니다.  

### 예제 🎲
2630번: 색종이 만들기 ([문제](https://www.acmicpc.net/problem/2630), [해설](https://github.com/skku-npc/class-intermediate/blob/master/2.%20Brute%20Force%20%26%20Divide%20and%20Conquer/2630.cpp))

---  

## 연습 🏓
#### 완전 탐색
1038번: 감소하는 수 ([문제](https://www.acmicpc.net/problem/1038), [해설](https://github.com/skku-npc/class-intermediate/blob/master/2.%20Brute%20Force%20%26%20Divide%20and%20Conquer/1038.cpp))  
1107번: 리모컨 ([문제](https://www.acmicpc.net/problem/1107), [해설](https://github.com/skku-npc/class-intermediate/blob/master/2.%20Brute%20Force%20%26%20Divide%20and%20Conquer/1107.cpp))  
14658번: 하늘에서 별똥별이 빗발친다 ([문제](https://www.acmicpc.net/problem/14658), [해설](https://github.com/skku-npc/class-intermediate/blob/master/2.%20Brute%20Force%20%26%20Divide%20and%20Conquer/14658.cpp))  

#### 백트래킹
1182번: 부분수열의 합 ([문제](https://www.acmicpc.net/problem/1182), [해설](https://github.com/skku-npc/class-intermediate/blob/master/2.%20Brute%20Force%20%26%20Divide%20and%20Conquer/1182.cpp))  
9663번: N-Queen ([문제](https://www.acmicpc.net/problem/9663), [해설](https://github.com/skku-npc/class-intermediate/blob/master/2.%20Brute%20Force%20%26%20Divide%20and%20Conquer/9663.cpp))  
(참고) "N과 M" 시리즈 - [문제집](https://www.acmicpc.net/workbook/view/2052)

#### 분할 정복
1992번: 쿼드트리 ([문제](https://www.acmicpc.net/problem/1992), [해설](https://github.com/skku-npc/class-intermediate/blob/master/2.%20Brute%20Force%20%26%20Divide%20and%20Conquer/1992.cpp))  
1074번: Z ([문제](https://www.acmicpc.net/problem/1074), [해설](https://github.com/skku-npc/class-intermediate/blob/master/2.%20Brute%20Force%20%26%20Divide%20and%20Conquer/1074.cpp))  

#### Challenge ⚡
14601번: 샤워실 바닥 깔기 (Large) ([문제](https://www.acmicpc.net/problem/14601))  
1725번: 히스토그램 ([문제](https://www.acmicpc.net/problem/1725))  
16909번: 카드 구매하기 3 ([문제](https://www.acmicpc.net/problem/16909))  
