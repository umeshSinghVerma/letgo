#include <bits/stdc++.h>

using u32 = unsigned;
using i64 = long long;
using u64 = unsigned long long;

void solve() {
    int n;
    std::cin >> n;
    
    std::vector<i64> a(n);
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
    }
    
    std::vector<bool> leaf(n, true);
    std::vector<int> p(n);
    p[0] = -1;
    for (int i = 1; i < n; i++) {
        std::cin >> p[i];
        p[i]--;
        leaf[p[i]] = false;
    }
    std::vector<std::vector<int>> adj(n);
    for (int i = 1; i < n; i++) {
        adj[p[i]].push_back(i);
    }
    std::vector<int> ord;
    ord.reserve(n - 1);
    auto dfs = [&](auto self, int x) -> void {
        if (x != 0) {
            ord.push_back(x);
        }
        for (auto y : adj[x]) {
            self(self, y);
        }
    };
    dfs(dfs, 0);
    
    std::vector<i64> f(n);
    auto check = [&](i64 x) {
        if (a[0] >= x) {
            return true;
        }
        f[0] = x - a[0];
        for (auto i : ord) {
            if (leaf[i] && f[p[i]] > a[i]) {
                return false;
            }
            f[i] = f[p[i]] + std::max(0LL, f[p[i]] - a[i]);
            if (f[i] > 1E9) {
                return false;
            }
        }
        return true;
    };
    
    i64 lo = 0, hi = 2E9;
    while (lo < hi) {
        i64 x = (lo + hi + 1) / 2;
        if (!check(x)) {
            hi = x - 1;
        } else {
            lo = x;
        }
    }
    std::cout << lo << "\n";
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
