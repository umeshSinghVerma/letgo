#include <bits/stdc++.h>
using namespace std;

void solve(){
	int N;
	cin >> N;
	vector<int> A(N);
	vector<int> b(N-1);
	for(int& x : b) cin >> x;
	for(int i = 0; i < N-1; i++){
		A[i] |= b[i];
		A[i+1] |= b[i];
	}
	for(int i = 0; i < N-1; i++){
		if((A[i] & A[i+1]) != b[i]){
			cout << -1 << '\n';
			return;
		}
	}
	for(int x : A) cout << x << ' ';
	cout << '\n';
}

int main(){
	ios_base::sync_with_stdio(false), cin.tie(nullptr);
	int T;
	cin >> T;
	while(T--) solve();
}
