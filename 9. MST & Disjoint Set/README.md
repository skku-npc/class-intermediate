# 9. 최소 스패닝 트리
사실 최소 스패닝 트리가 PS에서 그렇게 자주 등장하는 주제는 아닙니다. 하지만 오늘 최소 스패닝 트리와 함께 다룰 '서로소 집합(Disjoint Set)'을 익히기 좋기도 하고, 최소 스패닝 트리를 비슷한 형태로 응용할 수 있는 경우가 종종 있습니다. 자료구조 수업 시간에 이 내용을 비중있게 다루는 이유가 있는 거죠. 오늘 다룰 내용은 그래프 활용 문제인 최소 스패닝 트리 문제입니다.

## 스패닝 트리(Spanning Tree) 🔍
알고리즘을 소개하기에 앞서, 스패닝 트리란 무엇인지 간략하게 짚고 넘어가겠습니다.  

<b>스패닝 트리(Spanning Tree)</b>란, 무향 연결 그래프의 모든 정점을 포함하는 tree 형태의 subgraph입니다. 즉, 스패닝 트리에는 사이클이 존재하지 않아야 하며, 두 정점을 잇는 경로는 하나만 존재해야 합니다. 그래프에 스패닝 트리는 여러 개가 존재할 수 있습니다. 아래 그림을 스패닝 트리의 예시로 보면 되겠습니다.  

![Spanning Tree](/image/9차시/spanning_tree.png)  

<b>최소 스패닝 트리(Minimum Spanning Tree, MST)</b>는 간선의 weight가 주어진 그래프의 스패닝 트리들 중 weight의 합이 가장 작은 그래프입니다. 즉, 스패닝 트리 중 가장 '저렴한' 것을 말합니다.  

최소 스패닝 트리 문제를 해결하는 알고리즘은 여러가지가 있고, 다음 세 알고리즘이 잘 알려져 있습니다.

- 크루스칼 알고리즘(Kruskal's Algorithm)
- 프림 알고리즘(Prim's Algorithm)
- 솔린 알고리즘(Sollin's Algorithm)

오늘은 이 중 가장 많이 쓰이고 비교적 구현이 쉬운 크루스칼 알고리즘을 다루겠습니다.

---

## 서로소 집합(Disjoint Set) 🔗
크루스칼 알고리즘을 이해하려면 우선 Union-Find라고도 불리는 서로소 집합 구조를 알아야 합니다.  

<b>서로소 집합(Disjoint Set)</b>은 수학적 의미 그대로 공통 원소가 없는 부분 집합들을 표현하는 자료구조입니다. Union-Find라는 이름처럼, 이 자료구조에는 Union 연산과 Find 연산 두 가지만 존재합니다. 내용은 다음과 같습니다.  

- 초기에 모든 원소는 각각 자신을 유일한 원소로 하는 집합에 포함됩니다.  
- `union(x, y)` : `x`가 속한 집합과 `y`가 속한 집합을 합칩니다.  
- `find(x, y)` : `x`가 속한 집합의 대표 원소(root)를 찾습니다.  

예를 들어 원소 1과 원소 2를 union한다고 하면, 두 원소는 하나의 집합이 되고, root는 둘 중 임의의 값이 됩니다. 여기서는 1이 root가 됐다고 가정합시다.  

![](/image/9차시/disjoint_set_1.png)  

이 때 원소 3과 4로 이루어진, 3을 root로 갖는 집합과 union한다고 합시다. 그러면 다음과 같이 3의 parent를 1로 만들면, 모든 원소의 root가 1이 되면서 하나의 집합이 됩니다.

![](/image/9차시/disjoint_set_2.png)  

이를 구현하는 것은 `parent` 배열을 만들어 관리하면 어렵지 않습니다.  
처음에는 모든 원소의 `parent` 값을 자기 자신으로 지정하고, union 연산과 find 연산마다 값을 update하면 됩니다.  

구현은 다음과 같습니다.

```cpp
int find(int x) {
    if (x == parent[x]) return x;
    return parent[x] = find(parent[x]);
}

void union(int x, int y) {
    x = find(x);
    y = find(y);
    parent[x] = y;
}
```

이 때, `find(int)` 구현의 두 번째 줄에 주목할 필요가 있습니다.  
`return find(parent[x]);`가 아니라, `return parent[x] = find(parent[x]);`로 구현하는 것은 성능에 있어 큰 차이를 보입니다. n개의 원소가 있고 총 m번의 find 연산을 수행한다고 할 때, 전자로 구현한 것은 최악의 경우 <img src="https://latex.codecogs.com/svg.latex?O(mn)"/>의 시간복잡도를 갖지만, 후자의 경우 <img src="https://latex.codecogs.com/svg.latex?O(m+n)"/>의 시간복잡도를 갖습니다. 즉, 각 union, find 연산의 시간복잡도는 사실상 <img src="https://latex.codecogs.com/svg.latex?O(1)"/>으로 봐도 무관합니다.  

간단한 예시로 개념을 적용해보겠습니다.

### 예제 🎲
1717번: 집합의 표현 ([문제](https://www.acmicpc.net/problem/1717))  

---

## 크루스칼 알고리즘(Kruskal's Algorithm) 🧲
<b>크루스칼 알고리즘(Kruskal's Algorithm)</b>은 앞서 설명한 서로소 집합을 활용한 대표적인 예시입니다.  
작동 방식은 다음과 같습니다.

- 간선들을 가중치 순으로 오름차순 정렬한다.  
- 정점들을 각각 집합의 유일한 원소가 되도록 초기화한다. (Disjoin Set과 마찬가지)
- 가중치가 작은 간선부터 순서대로 탐색한다.
- 간선의 양쪽 정점이 서로 다른 집합에 있다면(Find), 간선을 Spanning Tree에 포함하고, 두 정점의 집합을 합친다(Union).  

위 흐름을 보면, Union-Find가 주된 연산인 것을 알 수 있습니다.  

다음 링크를 통해 동작 과정 예시를 참고하면 되겠습니다. ([링크](https://m.blog.naver.com/PostView.nhn?blogId=kks227&logNo=220799105543&proxyReferer=https:%2F%2Fwww.google.com%2F))  

시간 복잡도는 간선들을 정렬하는 데에 <img src="https://latex.codecogs.com/svg.latex?O(E\lg%20E)"/>, 각 간선마다 연산을 수행하는 데에는 거의 상수 시간이 들기에 총 <img src="https://latex.codecogs.com/svg.latex?O(E)"/>, 따라서 전체 시간 복잡도는 <img src="https://latex.codecogs.com/svg.latex?O(E\lg%20E)+O(E)=O(E\lg%20E)"/>입니다.  

### 예제 🎲
1197번: 최소 스패닝 트리 ([문제](https://www.acmicpc.net/problem/1197))  

---

## 연습 🏓

#### Disjoint Set 🔗
3108번: 로고 ([문제](https://www.acmicpc.net/problem/3108))  
4195번: 친구 네트워크 ([문제](https://www.acmicpc.net/problem/4195))  

#### Kruskal's Algorithm 🧲
1922번: 네트워크 연결 ([문제](https://www.acmicpc.net/problem/1922))  
2887번: 행성 터널 ([문제](https://www.acmicpc.net/problem/2887))  
1944번: 복제 로봇 ([문제](https://www.acmicpc.net/problem/1944))  

#### Challenge ⚡
3830번: 교수님은 기다리지 않는다 ([문제](https://www.acmicpc.net/problem/3830))  
1185번: 유럽 여행 ([문제](https://www.acmicpc.net/problem/1185))  
