# 4. 다이내믹 프로그래밍
지금까지 배운 것을 간략하게 짚어보겠습니다. 1차시는 문제 해결 기법, 즉 PS에서 문제에 접근하는 방법론을 다뤘습니다. 문제에 접근하면서 고려하면 좋을 여러 단계와 아이디어를 알아보았습니다. 2차시는 완전 탐색과 분할 정복으로, 자기가 생각한 내용을 코드로 옮기는 능력인 구현력을 기르는 연습을 했습니다. 3차시는 그리디 알고리즘으로, 시간 제한을 맞추기 위해 더 효율적인 알고리즘을 짜기 위한 발상을 떠올리는 과정을 연습해보았습니다.  

이번 주에는 다이내믹 프로그래밍을 통해 알고리즘에서 중복된 연산을 줄이는 방법을 알아보겠습니다.

## 설명 🔍
위에서 언급했듯이, <b>다이내믹 프로그래밍(Dynamic Programming)</b>은 중복된 연산을 막는 방법입니다.  

수학적인 예시를 들어보죠. 점화식이 주어진 길이가 <img src="https://latex.codecogs.com/svg.latex?n"/>인 수열 <img src="https://latex.codecogs.com/svg.latex?\{a_n\}"/>이 있다고 해봅시다. 이 때 문제는 <img src="https://latex.codecogs.com/svg.latex?q"/>개의 <img src="https://latex.codecogs.com/svg.latex?{a_i}"/>(i는 자연수)를 구하는 것이라고 해보죠. 그냥 문제 그대로 코드를 짜면 <img src="https://latex.codecogs.com/svg.latex?O(qn)"/>의 시간복잡도를 갖습니다. 이 때 다이내믹 프로그래밍을 이용해서 <img src="https://latex.codecogs.com/svg.latex?O(q+n)"/>의 시간복잡도로 낮출 수 있습니다. 

바로 여기서 메모이제이션(memoization)이라는 기술이 사용됩니다. 위키백과에 따르면, 이전에 계산한 값을 메모리에 저장하는 방법이라고 합니다. 위의 예시에 적용하면, <img src="https://latex.codecogs.com/svg.latex?q"/>개의 입력이 들어오기 전, <img src="https://latex.codecogs.com/svg.latex?a_i"/> 를 모두 미리 계산해놓으면 됩니다. 점화식이 <img src="https://latex.codecogs.com/svg.latex?a_{i+1}=f(a_i)"/>라고 하면, 수학적 귀납법과 비슷한 방법으로 <img src="https://latex.codecogs.com/svg.latex?a_i"/>를 계산할 수 있겠죠. 이런 식으로 <img src="https://latex.codecogs.com/svg.latex?n"/> 개의 <img src="https://latex.codecogs.com/svg.latex?a_i"/> 값을 <img src="https://latex.codecogs.com/svg.latex?O(n)"/>에 저장할 수 있습니다. 이제 <img src="https://latex.codecogs.com/svg.latex?q"/>개의 입력 각각에 대해, 저장된 값을 바로 출력하면 되니까 <img src="https://latex.codecogs.com/svg.latex?O(1)"/>, 총 <img src="https://latex.codecogs.com/svg.latex?O(q)"/>가 걸리죠. 따라서 전체 시간복잡도는 <img src="https://latex.codecogs.com/svg.latex?O(q+n)"/>입니다.  

지난 시간에 다룬 그리디 알고리즘과 '시간복잡도를 낮춘다'는 면에서는 비슷하지만, 다이내믹 프로그래밍은 그리디에 비해 제약이 적어, 사용되는 경우가 훨씬 빈번합니다. 그리디는 바로 이전 결과만 사용하는 반면, 다이내믹 프로그래밍은 이전 전체 결과를 고려한다는 것이 차이라고 할 수 있죠. 따라서 그리디에 비해 발상을 필요로 하는 면이 덜하기도 합니다.  

개인적으로 다이내믹 프로그래밍은 수학적 귀납법을 떠올리게 한다고 생각합니다. 초깃값과 점화식만 잘 정해놓으면 알고리즘이 바로 완성됩니다. 이번 주 연습은 이 두 가지, <b>초깃값과 점화식</b>에 초점을 맞추는 것이 제 바람입니다.

## 예제 🎲
11053번: 가장 긴 증가하는 부분 순열 ([문제](https://www.acmicpc.net/problem/11053), [해설](https://github.com/skku-npc/class-intermediate/blob/master/2.%20Brute%20Force%20%26%20Divide%20and%20Conquer/11053.cpp))  

## 연습 🏓


#### Challenge ⚡

