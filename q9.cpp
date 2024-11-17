#include <bits/stdc++.h>

using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;
using u128 = unsigned __int128;

void solve() {
    int n;
    std::cin >> n;
    
    std::string s, r;
    std::cin >> s >> r;
    
    int sum = n - 1;
    for (int i = 0; i < n - 2; i++) {
        sum -= r[i] - '0';
    }
    
    if (std::count(s.begin(), s.end(), '1') == sum) {
        std::cout << "YES\n";
    } else {
        std::cout << "NO\n";
    }
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