#include <bits/stdc++.h>
 
using u32 = unsigned;
using i64 = long long;
using u64 = unsigned long long;
 
void solve() {
    int n;
    std::cin >> n;
    
    std::vector<int> a(n);
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
    }
    
    std::string s;
    std::cin >> s;
    
    std::vector<i64> pre(n + 1);
    for (int i = 0; i < n; i++) {
        pre[i + 1] = pre[i] + a[i];
    }
    
    i64 ans = 0;
    
    std::vector<int> L, R;
    L.reserve(n);
    R.reserve(n);
    for (int i = 0; i < n; i++) {
        if (s[i] == 'L') {
            L.push_back(i);
        } else {
            R.push_back(i);
        }
    }
    std::reverse(R.begin(), R.end());
    
    for (int i = 0; i < std::min(L.size(), R.size()); i++) {
        if (L[i] < R[i]) {
            ans += pre[R[i] + 1] - pre[L[i]];
        }
    }
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