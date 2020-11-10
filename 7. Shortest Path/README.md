# 7. 최단 경로 탐색
지난 시간에 BFS를 설명하면서 '최단 경로 탐색'을 언급하였습니다. 그래프 문제로 빈번하게 나오는 최단 경로 탐색은 BFS로 구현 가능한 경우도 있지만, 그렇지 않은 문제들도 많습니다. 이번 시간에는 최단 경로 탐색에 쓰이는 대표적인 알고리즘들을 소개하겠습니다.

## 최단 경로 문제(shortest path problem) 🗺️
알고리즘 설명에 앞서, '최단 경로 문제'에 대해 조금 더 짚고 넘어가겠습니다.  

<b>최단 경로 문제(shortest path problem)</b>란 주어진 그래프에서 주어진 두 정점을 연결하는 가장 짧은 경로의 길이를 찾는 문제로, 다음과 같이 두 종류로 나뉩니다.  

- <b>Single-Source Shortest Path(SSSP)</b>: 하나의 시작점에서 다른 모든 정점까지 가는 최단 거리를 구해줍니다. (알고리즘: BFS, Dijkstra)
- <b>All-Pairs Shortest Path(APSP)</b>: 모든 정점의 쌍에 대해 최단 거리를 계산합니다. (알고리즘: Floyd-Warshall)

## 다익스트라 알고리즘(Dijkstra's Algorithm) 🔍
일반적으로 최단 경로 문제에서 SSSP의 비중이 더 크기에, SSSP를 먼저 다루겠습니다.  

저번 시간에도 설명한 것처럼, BFS도 SSSP를 해결할 수 있는 알고리즘입니다. 단, 여기에 중요한 제한 조건이 있습니다. 모든 간선(edge)의 무게(weight)가 1이어야 합니다. 즉, 간선들의 무게가 제각각인 경우 BFS를 쓰는 것은 적합하지 않습니다.  

간선들의 무게가 제각각인 경우 쓰이는 것이 바로 <b>다익스트라 알고리즘(Dijkstra's Algorithm)</b>입니다.  
다익스트라 알고리즘의 특징은 다음과 같습니다.

- 그리디 알고리즘을 기반으로 한 알고리즘이다.
- 너비 우선 탐색(BFS)과 유사한 형태이다.
- 가중치 값이 음수인 간선이 있으면 안된다. (음수인 간선이 있으면 Bellman-Ford 알고리즘 사용 - [설명](https://m.blog.naver.com/kks227/220796963742))

다익스트라 알고리즘의 핵심은, <b>가장 가까운 정점을 먼저 탐색하는 것</b>입니다. 이 때 BFS와 구분되는 것이, 모든 간선의 무게가 1이면(같으면) 새로 발견한 정점을 바로 queue에 넣어도 queue의 head에는 가장 가까운 정점이 있다는 것이 자명합니다. 하지만 간선의 무게가 제각각이라면 그렇지 않겠죠. 따라서 다익스트라 알고리즘은 새로 발견한 정점을 우선순위 큐(priority queue)에 넣습니다.  

알고리즘 자체는 BFS에서 일반 queue 대신 우선순위 큐를 쓴다는 것 외에는 차이가 없습니다. 다만 이를 관리하기 위한 각종 자료구조 때문에 BFS에 비해서 구현이 복잡합니다.  
의사 코드(psuedo code)는 다음과 같습니다.

```cpp
while (방문하지 않은 정점이 있음) {
    int u = (방문하지 않은 정점 중 가장 가까운 정점)
    for (int v : (u와 인접한, 방문하지 않은 정점들)) {
        dist[v]를 갱신  /* (dist[v] = min(dist[v], dist[u] + edge[u][v]) */
    }
}
```

시간복잡도를 계산하면, 우선순위 큐에는 정점이 최대 E개(V개 아님) 들어가고, 따라서 while loop을 E번 순회합니다. 각 while loop에서는 u를 pop하는 연산이 <img src="https://latex.codecogs.com/svg.latex?O(lg{V^2})=O(2lg{V})=O(lg{V})"/>가 소요됩니다.  
위 코드에서 for loop은 코드 전체를 통틀어 E번 순회하므로, 전체 시간복잡도는 <img src="https://latex.codecogs.com/svg.latex?O(ElgV+E)=O(ElgV)"/>입니다.

동작 과정을 살펴보며 동작 원리를 확인한 다음, 예제를 통해 구현을 연습해보겠습니다. (관련 설명: [링크](https://m.blog.naver.com/kks227/220796029558))  

### 예제 🎲
1753번: 최단 경로 ([문제](https://www.acmicpc.net/problem/1753), [해설](https://github.com/skku-npc/class-intermediate/blob/master/7.%20Shortest%20Path/1753.cpp))  
1504번: 특정한 최단 경로 ([문제](https://www.acmicpc.net/problem/1504), [해설](https://github.com/skku-npc/class-intermediate/blob/master/7.%20Shortest%20Path/1504x.cpp))  
