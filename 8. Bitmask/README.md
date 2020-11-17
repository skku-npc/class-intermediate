# 8. 비트마스크
이번 시간에는 알고리즘이라기보다는, 종종 유용하게 쓰일만한 '기법'을 다루고자 합니다.  
이번 시간에 다룰 내용은 비트마스크(bitmask)입니다.

## 비트마스크(bitmask) 🔍
비트마스크의 내용을 설명하기에 앞서, 컴퓨터의 기본이 되는 '비트'와 '바이트'에 대해 설명하겠습니다.  

컴퓨터는 모든 정수형 변수를 이진수로 표현합니다. 이때 이진수의 한 자리를 비트(bit)라고 부릅니다. 즉, 비트는 0 혹은 1의 값을 가질 수 있습니다. 예를 들어 부호 없는 8비트 정수형은 여덟 자리 이진수로 표시할 수 있는 모든 정수를 표현할 수 있고 최소값은 <img src="https://latex.codecogs.com/svg.latex?0000\ 0000_2 = 0"/>, 최대값은 <img src="https://latex.codecogs.com/svg.latex?1111\ 1111_2 = 255"/>입니다.  

#### 비트 연산자
| 연산자            | 설명          | 예시  |
|:----------------:|:-------------:|:-----:|
| AND (`&`) | 두 정수의 해당 bit가 모두 1이면 1 | `1010 & 1100 == 1000` |
| OR  (`\|`) | 두 정수의 해당 bit가 하나라도 1이면 1 | `1010 | 1100 == 1110` |
| XOR (`^`) | 두 정수의 해당 bit가 하나만 1이면 1 | `1010 ^ 1100 == 0110`  |
| NOT (`~`) | 정수의 해당 bit가 0이면 1, 1이면 0 | `~1011 == 0100` |
| Left Shift (`<<`) | 정수의 bit들을 왼쪽으로 이동 | `1010 << 1 == 0100` |
| Right Shift (`>>`) | 정수의 bit들을 오른쪽으로 이동 | `1010 >> 1 == 0101` |


#### 집합의 구현
집합을 `int s`에 저장한다고 합시다. 이 때, 다음 연산으로 `i`번째 값의 포함 여부를 알 수 있습니다.  

```cpp
((s >> i) & 1) == 1
```

`i == 0`이라면 `(s & 1)`, `i == 1`이라면 `(s & 2)`, `i == 2`라면 `(s & 4)` 등으로 0인지 1인지 flag 값을 알 수 있습니다.  

또한, `i`번째 값을 바꾸고자 할 때 다음 연산을 이용할 수 있습니다.

```cpp
s |= (1 << i);
s ^= (1 << i);
```

첫 번째 식은 `i`번째 값을 1로 바꾸는, 두 번째 식은 `i`번째 값에 NOT 연산을 적용하는 식으로 이해할 수 있습니다.  

위와 같이 비트연산자를 활용하여 여러 문제에 적용할 수 있습니다.  

이제 예제 풀이를 통해 비트마스킹을 적용해보겠습니다.

## 예제 🎲
앞서 설명한 집합 연산을 연습해봅니다.  
11723번: 집합 ([문제](https://www.acmicpc.net/problem/11723), [해설](https://github.com/skku-npc/class-intermediate/blob/master/8.%20Bitmask/11723.cpp))  

비트마스크는 DP와 함께 쓰이는 경우가 많습니다.  
2098번: 외판원 순회 ([문제](https://www.acmicpc.net/problem/2098), [해설](https://github.com/skku-npc/class-intermediate/blob/master/8.%20Bitmask/2098.cpp))  

## 연습 🏓
비트마스크를 쓰지 않고 풀 수 있는 문제도 있지만, 가능하면 비트마스크를 적용해보기 바랍니다!

1562번: 계단 수 ([문제](https://www.acmicpc.net/problem/1562), [해설](https://github.com/skku-npc/class-intermediate/blob/master/8.%20Bitmask/1562.cpp))  
1062번: 가르침 ([문제](https://www.acmicpc.net/problem/1062), [해설](https://github.com/skku-npc/class-intermediate/blob/master/8.%20Bitmask/1062.cpp))  
2718번: 타일 채우기 ([문제](https://www.acmicpc.net/problem/2718), [해설](https://github.com/skku-npc/class-intermediate/blob/master/8.%20Bitmask/2718.cpp))  
1102번: 발전소 ([문제](https://www.acmicpc.net/problem/1102), [해설](https://github.com/skku-npc/class-intermediate/blob/master/8.%20Bitmask/1102.cpp))  
1029번: 그림 교환 ([문제](https://www.acmicpc.net/problem/1029), [해설](https://github.com/skku-npc/class-intermediate/blob/master/8.%20Bitmask/1029.cpp))  

#### Challenge ⚡
10649번: 프리스비 ([문제](https://www.acmicpc.net/problem/10649), [해설](https://github.com/skku-npc/class-intermediate/blob/master/8.%20Bitmask/10649.cpp))  
1014번: 컨닝 ([문제](https://www.acmicpc.net/problem/1014), [해설](https://github.com/skku-npc/class-intermediate/blob/master/8.%20Bitmask/1014.cpp))  
