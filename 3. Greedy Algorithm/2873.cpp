#include <bits/stdc++.h>
using namespace std;

int r, c;
int arr[1005][1005];

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> r >> c;
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            cin >> arr[i][j];
        }
    }
    if (r & 1) {
        for (int i = 0; i < r / 2; i++) {
            cout << string(c - 1, 'R') << 'D';
            cout << string(c - 1, 'L') << 'D';
        }
        cout << string(c - 1, 'R') << endl;
    } else if (c & 1) {
        for (int i = 0; i < c / 2; i++) {
            cout << string(r - 1, 'D') << 'R';
            cout << string(r - 1, 'U') << 'R';
        }
        cout << string(r - 1, 'D') << endl;
    } else {
        int min_val = arr[0][1];
        int min_y = 0;
        int min_x = 1;
        for (int i = 0; i < r; i++) {
            for (int j = (i + 1) & 1; j < c; j += 2) {
                if (min_val > arr[i][j]) {
                    min_val = arr[i][j];
                    min_y = i;
                    min_x = j;
                }
            }
        }

        for (int i = 0; i < min_y / 2; i++) {
            cout << string(c - 1, 'R') << 'D';
            cout << string(c - 1, 'L') << 'D';
        }

        for (int i = 0; i < min_x / 2; i++) {
            cout << "DRUR";
        }
        cout << (min_x & 1 ? "DR" : "RD");
        for (int i = 0; i < (c - min_x - 1) / 2; i++) {
            cout << "RURD";
        }

        for (int i = 0; i < (r - min_y - 1) / 2; i++) {
            cout << 'D' << string(c - 1, 'L');
            cout << 'D' << string(c - 1, 'R');
        }
        cout << endl;
    }
}