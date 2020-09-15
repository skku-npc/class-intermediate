#include <bits/stdc++.h>
using namespace std;

int n;
vector<int> v;

int largest(int left, int right) {
    if (left == right) return v[left];

    int mid = (left + right) / 2;
    int ret = max(largest(left, mid), largest(mid + 1, right));

    int left_idx = mid, right_idx = mid + 1;
    int height = min(v[left_idx], v[right_idx]);
    ret = max(ret, height * 2);

    while (left_idx > left || right_idx < right) {
        if (left_idx > left &&
            (right_idx == right || v[left_idx - 1] > v[right_idx + 1])) {
            height = min(height, v[--left_idx]);
        } else {
            height = min(height, v[++right_idx]);
        }
        ret = max(ret, height * (right_idx - left_idx + 1));
    }

    return ret;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    v.resize(n);
    for (int &i : v) cin >> i;
    cout << largest(0, n - 1) << endl;
}

/////// 풀이: 분할 정복 ///////
// largest함수는 범위 [left, right]에 속하는 히스토그램에서
// 최대 넓이를 반환하는 함수이다.
// (left + right)/2 를 mid라 하면 이러한 직사각형은
// 1. mid의 왼편에, 즉[left, mid]범위에 존재할 수 있다.
// 2. [mid +1, right]에 존재할 수 있다.
// 3. mid에 걸쳐 있을 수 있다.
//
// 1번과 2번은 재귀적으로 처리할 수 있다.
// 3번 case 같은 경우 greedy하게 처리할 수 있다.
// 걸쳐있는 경우, 가장 작은 사각형부터 잡아서 확장해 나간다.
// (즉 mid, mid + 1의 사각형을 선택한 상태)
// 이때 한 칸씩 확장해 나가는 식으로 진행한다. 왼쪽으로 한칸 확장하기 vs
// 오른쪽으로 한칸 확장하기 둘 중에서 greedy하게 선택해 나간다.