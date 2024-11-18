#include <bits/stdc++.h>
using namespace std;
int N, X[2][2 << 17];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    for (; T--;)
    {
        cin >> N;
        for (int y = 0; y < 2; y++)
            for (int x = 0; x <= N; x++)
                X[y][x] = 0;
        int Y0 = 0, Y1 = 0;
        for (int i = 0; i < N; i++)
        {
            int x, y;
            cin >> x >> y;
            X[y][x] = 1;
            if (y == 0)
                Y0++;
            else
                Y1++;
        }
        long long ans = 0;
        for (int x = 0; x <= N; x++)
        {
            if (X[0][x] && X[1][x])
                ans += Y0 + Y1 - 2;
            if (x >= 1 && x < N)
            {
                if (X[0][x - 1] && X[1][x] && X[0][x + 1])
                    ans++;
                if (X[1][x - 1] && X[0][x] && X[1][x + 1])
                    ans++;
            }
        }
        cout << ans << "\n";
    }
}
