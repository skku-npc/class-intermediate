# 3. 탐욕 알고리즘
개인적으로 PS하면 먼저 생각나는 알고리즘이 탐욕 알고리즘(탐욕법)입니다. 알고리즘 자체를 이해하는 것은 어렵지 않지만, 알고리즘 자체가 발상에 의존하는 경향이 있기에 흔히 말하는 "머리 좋은" 사람들이 잘 풀어내죠. 그래서 문제 난이도도 쉬운 문제는 쉽고, 어려운 문제는 (매우매우) 어려운 알고리즘이 탐욕법입니다.  

## 설명 🔍
<b>탐욕 알고리즘(Greedy Algorithm)이란</b> 지금 당장 가장 좋은 방법만을 선택하는 것입니다. 지난 시간에 배운 '모든 경우를 고려하는' 완전 탐색과 구분되죠.  

종만북에 따르면 탐욕적 알고리즘이 사용되는 경우는 크게 다음 두 가지입니다.  

1. 탐욕법을 사용해도 항상 최적해를 구할 수 있는 문제를 만난 경우, 빠른 시간안에 해를 구할 수 있습니다.  
2. 시간/공간적 제약으로 인해 최적해를 찾기 어려운 경우 근사해를 찾는 것으로 타협할 수 있습니다. 이 경우 탐욕법이 유용하게 쓰일 수 있습니다.  

보통 PS에서는 첫 번째 경우만 사용됩니다. 근사해를 구하는 문제가 거의 없기도 하고, 있더라도 조합 탐색이나 휴리스틱 같은 알고리즘이 더 많이 쓰입니다.  

종만북에서 '탐욕법은 가장 직관적인 알고리즘 설계 파라다임 중 하나'라고 언급합니다. 저도 이에 동의합니다. 하지만 이에 동시에 많은 경우에 최적해를 구하지 못하는 알고리즘이기도 합니다. 섣불리 직관에 의존해 탐욕법으로 코드를 짰다가는 WA를 받기 쉽습니다. 그래서 알고리즘의 정당성을 증명하는 과정이 매우 중요한 알고리즘입니다.  

또한, 직관에 어느 정도 의존하다보니 문제 난이도의 격차가 매우 큰 것으로 유명합니다. ~~(흔히 머리빨이라고도...)~~ 이러한 직관을 잘 얻기 위해 제가 강조하고 싶은 것은 충분한 <b>경험</b>과, 꾸준한 <b>관찰</b>입니다. 여러 시행착오를 겪어보며 문제에서 유추해낼 수 있는 조건, 특징 등을 잘 헤아리다 보면 직관을 얻어내는 과정도 점점 쉬워질 것입니다.  

이제 문제 풀이를 통해 탐욕법을 적용하는 과정을 알아보겠습니다.  

## 예제 🎲
1080번: 행렬 ([문제](https://www.acmicpc.net/problem/1080), [해설](https://github.com/skku-npc/class-intermediate/blob/master/3.%20Greedy%20Algorithm/1080.cpp))  
1339번: 단어 수학 ([문제](https://www.acmicpc.net/problem/1339), [해설](https://github.com/skku-npc/class-intermediate/blob/master/3.%20Greedy%20Algorithm/1339.cpp))  

## 연습 🏓
11047번: 동전 0 ([문제](https://www.acmicpc.net/problem/11047), [해설](https://github.com/skku-npc/class-intermediate/blob/master/3.%20Greedy%20Algorithm/11047.cpp))  
1138번: 한 줄로 서기 ([문제](https://www.acmicpc.net/problem/1138), [해설](https://github.com/skku-npc/class-intermediate/blob/master/3.%20Greedy%20Algorithm/1138.cpp))  
1744번: 수 묶기 ([문제](https://www.acmicpc.net/problem/1744), [해설](https://github.com/skku-npc/class-intermediate/blob/master/3.%20Greedy%20Algorithm/1744.cpp))  
2437번: 저울 ([문제](https://www.acmicpc.net/problem/2437), [해설](https://github.com/skku-npc/class-intermediate/blob/master/3.%20Greedy%20Algorithm/2437.cpp))  
1202번: 보석 도둑 ([문제](https://www.acmicpc.net/problem/1202), [해설](https://github.com/skku-npc/class-intermediate/blob/master/3.%20Greedy%20Algorithm/1202.cpp))  

#### Challenge ⚡
1071번: 소트 ([문제](https://www.acmicpc.net/problem/1071), [해설](https://github.com/skku-npc/class-intermediate/blob/master/3.%20Greedy%20Algorithm/1071.cpp))  
2873번: 롤러코스터 ([문제](https://www.acmicpc.net/problem/2873), [해설](https://github.com/skku-npc/class-intermediate/blob/master/3.%20Greedy%20Algorithm/2873.cpp))  