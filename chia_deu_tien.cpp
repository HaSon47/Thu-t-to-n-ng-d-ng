//C++
#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    int total = 0;

    for (int i = 0; i < n; i++) {
        cin >> a[i];
        total += a[i];
    }

    int half = total / 2;
    vector<bool> dp(half + 1, false);
    dp[0] = true; // Có thể tạo tổng 0 bằng cách không chọn phần tử nào

    for (int i = 0; i < n; i++) {
        for (int j = half; j >= a[i]; j--) {
            if (dp[j - a[i]]) {
                dp[j] = true;
            }
        }
    }

    // Tìm tổng lớn nhất <= half mà có thể đạt được
    int best = 0;
    for (int j = half; j >= 0; j--) {
        if (dp[j]) {
            best = j;
            break;
        }
    }

    int diff = total - 2 * best;
    cout << diff;

    return 0;
}

