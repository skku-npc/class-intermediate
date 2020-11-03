# 5. DFS & BFS
그래프는 PS에서 매우 중요한 개념 중 하나입니다. 그래프의 모든 정점들을 특정한 순서에 따라 방문하는 알고리즘들을 그래프의 탐색(search) 알고리즘이라고 합니다. 오늘은 탐색 알고리즘 중 가장 널리 사용되는 깊이 우선 탐색(DFS)과 너비 우선 탐색(BFS)을 다루겠습니다. 이미 초급반에서도 다뤘을테니, 이번 시간에는 기본적인 것보단 활용에 초점을 맞춰 진행하겠습니다.  

![DFS & BFS](/image/dfs-and-bfs.gif)  
(이미지 출처: 마이구미의 Hello World https://mygumi.tistory.com/102)  

## 깊이 우선 탐색(DFS) 🔍
가장 일반적이고 단순한 탐색 알고리즘으로, 주로 재귀를 이용하여 구현합니다. 사실 백트래킹과 일맥상통하는 알고리즘이기도 합니다.  
그래프 내 정점의 집합을 V, 간선의 집합을 E라고 하면 각 정점마다 `dfs()`가 한 번 호출되고, 각 간선은 최대 두 번 확인하므로 전체 시간 복잡도는 <img src="https://latex.codecogs.com/svg.latex?O(|V|+|E|)"/>입니다.  

깊이 우선 탐색 알고리즘의 핵심은 다음 두 가지입니다:  
- 방문하지 않은 인접한 간선이 있으면, 바로 그 간선을 따라간다.  
- 더이상 갈 곳이 없으면, 방금 따라온 간선으로 돌아간다.  

이를 이용한 동작 방식은 위 GIF를 보면 이해될 거라고 생각합니다.  

### DFS의 활용
DFS는 상대적으로 단순한 알고리즘이지만, 강력하고 활용도가 매우 높습니다.  
그 중 몇 가지 예시를 들면 다음과 같습니다.

- __Flood Fill__: 어떤 칸과 연결된 영역을 찾는 알고리즘입니다. 간단한 예로 포토샵에서 특정 영역을 색칠할 때 쓰입니다. 이는 BFS로도 구현 가능하지만, 일반적으로 구현이 더 간단한 DFS가 쓰입니다.  

- __두 정점의 연결 여부__: Flood Fill과 비슷한 맥락으로, 그래프에서 두 정점이 연결되었는지 판단할 때 유용합니다. `u`와 `v`의 연결 여부를 판단하려고 할 때, `dfs(u)`만 실행하면 간단하게 알 수 있죠.  

- __연결된 부분집합의 개수__: 서로 연결된 정점들을 하나의 '연결된 부분집합'이라고 할 때, 전체 그래프에 이 집합이 몇 개나 있는지 알 수 있습니다.  

- __위상 정렬__: 의존성이 있는 작업들이 주어질 때, 즉 다른 어떤 작업들이 완료되어야만 수행할 수 있는 작업들이 주어질 때, 이들을 어떤 순서로 수행해야 하는지 계산하는 알고리즘입니다. 자세히 설명하려면 내용이 길어지니 여기서는 생략하겠습니다. (참고 설명: [링크](https://m.blog.naver.com/ndb796/221236874984))  

- __강결합 컴포넌트(SCC)__: 방향 그래프에서 두 정점 `u`와 `v`에 대해 양 방향으로 가는 경로가 모두 있을 때 두 정점은 같은 SCC에 속해 있다고 말합니다. 주로 타잔(Tarjan) 알고리즘 또는 코사라주(Kosaraju) 알고리즘이 쓰이며, 이 또한 설명할 분량이 많기 때문에 여기서는 생략하겠습니다. (참고 설명: [링크](https://m.blog.naver.com/PostView.nhn?blogId=kks227&logNo=220802519976&proxyReferer=https%3A%2F%2Fwww.google.com%2F))  

- __루트 없는 트리__: 루트가 정해지지 않은 트리에서, 원하는 정점 하나를 루트로 정해 트리 형태로 바꿀 수 있습니다. 더 나아가, 트리가 아닌 그래프를 트리로 변환하는 것도 가능합니다.  

- __Subtree (HLD)__: 각 정점의 방문 순서를 저장하면 트리를 선형으로 만들고, 각 정점의 자식을 선형 구간으로 저장할 수 있습니다. 이를 확장한 것이 HLD(Heavy Light Decomposition) 알고리즘으로, 후에 세그먼트 트리를 공부하면 같이 익혀두면 좋습니다. 이는 분량도 많지만 난이도도 높기에, 추가 설명은 다음 링크를 참고해 주세요: [링크](https://justicehui.github.io/hard-algorithm/2020/01/24/hld/)  

이외에도 활용 예시는 수없이 많지만, 난이도도 높고 분량이 너무 많아 나중에 차근차근 하나씩 익혀보길 바랍니다.  
Codeforces에 올라온 다음 글에 정리가 잘 되어있어 한 번쯤 읽어보길 권해드립니다.  
__The DFS tree and its applications__ (https://codeforces.com/blog/entry/68138)  

### 예제 🎲
앞서 언급한 Flood Fill을 연습하는 문제입니다.  
2583번: 영역 구하기 ([문제](https://www.acmicpc.net/problem/2583), [해설](https://github.com/skku-npc/class-intermediate/blob/master/6.%20DFS%20&%20BFS/2583.cpp))  

## 너비 우선 탐색(BFS) 🚦
DFS는 주로 재귀, 즉 스택을 이용하여 구현하는 반면 BFS는 큐를 이용하여 구현합니다. 시간복잡도는 DFS와 같은 <img src="https://latex.codecogs.com/svg.latex?O(|V|+|E|)"/>입니다.  

너비 우선 탐색 알고리즘의 핵심은 다음과 같습니다:  
- 방문하지 않은 인접한 정점들이 있으면, 우선 해당 정점들을 순서대로 방문합니다.  
- DFS와 달리 정점의 발견과 방문이 동시에 일어나지 않습니다. 즉, 각 정점에 대해 다음 세 가지 상태가 존재합니다.  
    - 아직 발견되지 않은 상태  
    - 발견되었지만 아직 방문되지는 않은 상태 (큐에 저장된 상태)  
    - 방문된 상태  

마찬가지로 위 GIF를 보면 동작 방식을 이해할 수 있습니다.  

### BFS의 활용
BFS는 활용되는 곳이 DFS처럼 다양하진 않습니다. DFS가 활용되는 곳 중에 BFS로도 구현 가능한 것이 있지만, DFS가 구현이 더 간단하기 때문에 DFS를 쓰는 것이 일반적입니다.  

다만, 특정 문제에서는 BFS로만 구현이 가능하여 BFS가 많이 쓰입니다. 바로 <b>최단 경로 문제</b>입니다. 다음 시간에 다익스트라(Dijkstra) 알고리즘과 같은 최단 경로 알고리즘을 더 자세히 다루겠지만, 그 알고리즘도 모두 BFS를 변형한 것이나 다름 없습니다. 예제 풀이를 통해 알아보겠습니다.  

### 예제 🎲
7562번: 나이트의 이동 ([문제](https://www.acmicpc.net/problem/7562), [해설](https://github.com/skku-npc/class-intermediate/blob/master/6.%20DFS%20&%20BFS/7562.cpp))  

## 연습 🏓
2606번: 바이러스 ([문제](https://www.acmicpc.net/problem/2606), [해설](https://github.com/skku-npc/class-intermediate/blob/master/6.%20DFS%20&%20BFS/2606.cpp))  
1697번: 숨바꼭질 ([문제](https://www.acmicpc.net/problem/1697), [해설](https://github.com/skku-npc/class-intermediate/blob/master/6.%20DFS%20&%20BFS/1697.cpp))  
2206번: 벽 부수고 이동하기 ([문제](https://www.acmicpc.net/problem/2206), [해설](https://github.com/skku-npc/class-intermediate/blob/master/6.%20DFS%20&%20BFS/2206.cpp))  
14442번: 벽 부수고 이동하기 2 ([문제](https://www.acmicpc.net/problem/14442), [해설](https://github.com/skku-npc/class-intermediate/blob/master/6.%20DFS%20&%20BFS/14442.cpp))  
1167번: 트리의 지름 ([문제](https://www.acmicpc.net/problem/1167), [해설](https://github.com/skku-npc/class-intermediate/blob/master/6.%20DFS%20&%20BFS/1167.cpp))  
2146번: 다리 만들기 ([문제](https://www.acmicpc.net/problem/2146), [해설](https://github.com/skku-npc/class-intermediate/blob/master/6.%20DFS%20&%20BFS/2146.cpp))  

#### Challenge ⚡
2842번: 집배원 한상덕 ([문제](https://www.acmicpc.net/problem/2842), [해설](https://github.com/skku-npc/class-intermediate/blob/master/6.%20DFS%20&%20BFS/2842.cpp))  
2424번: 부산의 해적 ([문제](https://www.acmicpc.net/problem/2424), [해설](https://github.com/skku-npc/class-intermediate/blob/master/6.%20DFS%20&%20BFS/2424.cpp))  
