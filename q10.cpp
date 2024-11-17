#include <bits/stdc++.h>

using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;
using u128 = unsigned __int128;

void solve() {
    int n;
    std::cin >> n;
    
    std::vector<i64> a(n);
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
    }
    
    i64 ans = 0;
    if (n % 2 == 0) {
        for (int i = 0; i < n; i += 2) {
            ans = std::max(ans, a[i + 1] - a[i]);
        }
    } else {
        ans = 1E18;
        for (int i = 0; i < n; i += 2) {
            i64 res = 0;
            for (int j = 0; j < n; j += 2) {
                if (j == i) {
                    j--;
                    continue;
                }
                res = std::max(res, a[j + 1] - a[j]);
            }
            ans = std::min(ans, res);
        }
    }
    ans = std::max(ans, 1LL);
    std::cout << ans << "\n";
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int t;
    std::cin >> t;
    
    while (t--) {
        solve();
    }
    
    return 0;
}