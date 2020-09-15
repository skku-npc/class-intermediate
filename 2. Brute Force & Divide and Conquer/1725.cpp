#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

int n;
vector<int> v;

int largest(int left, int right)
{
    if (left == right)
        return v[left];
    //////////////////////////////////////////////////
    int mid = (left + right) / 2;
    int ret = max(largest(left, mid), largest(mid + 1, right));

    int left_idx = mid, right_idx = mid + 1;
    int height = min(v[left_idx], v[right_idx]);
    ret = max(ret, height * 2);
    while (left_idx > left || right_idx < right)
    {
        if (left_idx > left && (right_idx == right || v[left_idx - 1] > v[right_idx + 1]))
            height = min(height, v[--left_idx]);
        else
            height = min(height, v[++right_idx]);
        ret = max(ret, height * (right_idx - left_idx + 1));
    }
    return ret;
}

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    v.resize(n);
    for (int &i : v)
        cin >> i;

    cout << largest(0, n - 1) << endl;
    return 0;
}
