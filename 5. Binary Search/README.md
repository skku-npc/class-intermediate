# 5. 이분 탐색
지금까지 배운 내용들은 범용적으로 쓰이는 '기법'에 관한 것이었습니다. 지난 차시까지의 내용들을 충분히 이해하고 예제와 연습 문제들을 많이 풀어봤다면, 웬만큼의 PS 기본기는 쌓였을 것이라 생각합니다. ~~(이제 코테 정도는 가볍게 볼 수 있지 않을까요... ㅎㅎ)~~ 이번 차시부터는 기법이라기보다는, 특수 상황에서 쓰일 '알고리즘'을 다룰 예정입니다. 이는 첫 시간에도 말했지만, 이러한 알고리즘 지식을 많이 아는 것보다 이전 차시까지 다룬 내용들을 충분히 체화하는 것이 우선이라는 점을 꼭 알아뒀으면 좋겠습니다!

## 설명 🔍
[위키](https://ko.wikipedia.org/wiki/%EC%9D%B4%EC%A7%84_%EA%B2%80%EC%83%89_%EC%95%8C%EA%B3%A0%EB%A6%AC%EC%A6%98)에 따르면, <b>이분 탐색(Binary Search)</b>이란 오름차순으로 정렬된 리스트에서 특정한 값의 위치를 찾는 알고리즘입니다. (이진 탐색으로도 불립니다) 이 위치를 찾는 방법은, 리스트의 중간값을 기준으로 리스트를 계속 절반으로 나누는 것입니다.  

이분 탐색이 2차시에서 다룬 '분할 정복'이 적용된 좋은 예시입니다. 조금 쉽게 설명하면, 흔히 책이나 사전에서 특정 페이지를 찾을 때 사용하는 방법과 비슷하다고 할 수 있습니다.  

### 동작 원리
위 설명으로는 잘 와닿지 않을테니 간단한 예를 들어 설명해보겠습니다. `A = [5, 11, 12, 13, 19, 20]`으로 초기화된 배열 A에서 값 13의 index를 찾는 것이 문제라고 해보죠.  

![example1](/image/5차시/ex1.PNG)

위와 같이 A를 절반으로 나눌 인덱스를 정합니다. 이 경우 (0+5)/2 = 2이니 기준 인덱스가 2가 되겠네요. 우리가 찾으려는 값인 13은 12보다 크기 때문에, 기준 인덱스 2를 포함한 왼쪽 부분에는 13이 없다는 것이 자명하죠. 그래서 이제 우리가 살펴볼 A를 오른쪽 부분인 인덱스 3~5로 제한합니다.  

![example2](/image/5차시/ex2.PNG)

이제 다음 기준 인덱스는 (3+5)/2 = 4입니다. 우리가 찾는 값은 19보다 작습니다. 이번에는 오른쪽 부분이 필요가 없네요. 따라서 우리가 살펴볼 A는 인덱스 3 하나로 줄어듭니다.

![example3](/image/5차시/ex3.PNG)

A를 줄이는 과정을 반복했더니, (우리가 살펴보는) A의 길이가 1이 되었습니다. 이 순간, 답은 인덱스 3이라는 것을 알 수 있죠.  

### 의의
이 알고리즘의 가장 큰 의의는 <b>탐색 시간</b>을 크게 줄인다는 것입니다. 이분 탐색을 쓰지 않으면 위 문제의 시간복잡도는 앞에서부터 하나씩 순회해야 하므로 자명하게 <img src="https://latex.codecogs.com/svg.latex?O(n)"/>입니다. 하지만 이분 탐색은 분할 정복에 따라 <img src="https://latex.codecogs.com/svg.latex?O(lg(n))"/>의 시간 복잡도를 갖습니다.  

그리고 생각보다 이분 탐색이 쓰일 수 있는 경우는 굉장히 다양합니다. 연습 문제를 풀어보면서도 알겠지만, 꼭 위와 같이 '정렬된 배열'이라는 전형적인 케이스 외에도 활용 방법은 무궁무진합니다.  

### 구현
일반적으로 이분 탐색의 구현은 다음과 같습니다.
```cpp
int lo = 0, hi = INF;

while (lo < hi) {
    int mid = (lo + hi) / 2;
    if (key < A[mid]) {  // 이 부분에 문제에 따른 조건(기준)이 들어감
        hi = mid - 1;
    } else {
        lo = mid;
    }
}
```
이는 하나의 예시일 뿐이고, `lo`와 `hi`를 중심으로 `while`문을 돈다는 점을 알아두면 되겠습니다.  

### 참고
쓸 수 있는 경우가 많진 않지만, C++에도 내장 함수로 이분 탐색이 구현되어 있습니다. `binary_search()`와 `lower_bound()`, `upper_bound()`가 그것입니다. `binary_search()`는 해당 값이 있는지 없는지를 `boolean`으로 return해주고, `lower_bound()`와 `upper_bound()`는 각각 주어진 값보다 크거나 큰, 주어진 값보다 큰 값의 index를 return합니다. `lower_bound()`, `upper_bound()`는 꽤 자주, 그리고 상당히 유용하게 쓰이는 함수이니 잘 알아두시길 바랍니다. (추가 설명: [링크](https://breakcoding.tistory.com/188))  

---

## 예제 🎲
2805번: 나무 자르기 ([문제](https://www.acmicpc.net/problem/2805), [해설](https://github.com/skku-npc/class-intermediate/blob/master/4.%20Dynamic%20Programming/2805.cpp))  
2110번: 공유기 설치 ([문제](https://www.acmicpc.net/problem/2110), [해설](https://github.com/skku-npc/class-intermediate/blob/master/4.%20Dynamic%20Programming/2110.cpp))  

## 연습 🏓
1654번: 랜선 자르기 ([문제](https://www.acmicpc.net/problem/1654), [해설](https://github.com/skku-npc/class-intermediate/blob/master/4.%20Dynamic%20Programming/1654.cpp))  
2470번: 두 용액 ([문제](https://www.acmicpc.net/problem/2470), [해설](https://github.com/skku-npc/class-intermediate/blob/master/4.%20Dynamic%20Programming/2470.cpp))  
16766번: Convention ([문제](https://www.acmicpc.net/problem/16766), [해설](https://github.com/skku-npc/class-intermediate/blob/master/4.%20Dynamic%20Programming/16766.cpp))  
7453번: 합이 0인 네 정수 ([문제](https://www.acmicpc.net/problem/7453), [해설](https://github.com/skku-npc/class-intermediate/blob/master/4.%20Dynamic%20Programming/7453.cpp))  
12015번: 가장 긴 증가하는 부분 수열 2 ([문제](https://www.acmicpc.net/problem/12015), [해설](https://github.com/skku-npc/class-intermediate/blob/master/4.%20Dynamic%20Programming/12015.cpp))  

#### Special 🎁
한 번쯤 풀어보면 재밌는 문제도 넣어봤습니다. 이분 탐색의 개념을 적용시키기 좋은 문제입니다.  
15641번: SUPER SUPER BINARY SEARCH DELUXE 2.5... ([문제](https://www.acmicpc.net/problem/15641))  

#### Challenge ⚡
2842번: 집배원 한상덕 ([문제](https://www.acmicpc.net/problem/2842), [해설](https://github.com/skku-npc/class-intermediate/blob/master/4.%20Dynamic%20Programming/2842.cpp))  
13303번: 장애물 경기 ([문제](https://www.acmicpc.net/problem/13303), [해설](https://github.com/skku-npc/class-intermediate/blob/master/4.%20Dynamic%20Programming/13303.cpp))  
19536번: 감자 농장 ([문제](https://www.acmicpc.net/problem/19536), [해설](https://github.com/skku-npc/class-intermediate/blob/master/4.%20Dynamic%20Programming/19536.cpp))  
