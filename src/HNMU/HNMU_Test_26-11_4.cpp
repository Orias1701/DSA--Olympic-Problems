#include <bits/stdc++.h>

using namespace std;

using ull = unsigned long long;

ull DP[1001][1001];

ull GT[100001];

ull gtn(ull n) {
    if (n < 3) return n;
    if (GT[n] == 0) {
        GT[n] = gtn(n-1)*n;
        return GT[n];
    } else {
        return GT[n];
    }
}

ull ckn(ull n, ull k){
    ull res = (gtn(n)/gtn(k)/gtn(n-k)) % 1000000007;
    return res;
}

int main(){
    ull m, n, k, x, y;
    cin >> m >> n >> k;

    memset(DP, 0, sizeof(DP));
    memset(GT, 0, sizeof(GT));

    for(ull i = 0; i < k; i++) {
        cin >> x >> y;
        DP[x][y] = 1;
    }

    DP[0][1] = 1;

    for (int i = 1; i < 1001; i++){
        for (int j = 1; j < 1001; j++){
            if(DP[i][j] == 0) DP[i][j] = DP[i][j-1] + DP[i-1][j];
            else DP[i][j] = 0;
        }
    }

    if (m < 1001 && n < 1001) {
        cout << DP[m][n];
        return 0;
    }

    ull res = 0;
    if (m > 1000) {
        ull limn = min(n, (ull)1000);
        for(ull i = 1; i <= limn; i++){
            res += (ckn(m-1001 + n-i, m-1001) * (DP[1000][i] % 1000000007)) % 1000000007;
        }
    }
    
    if (n > 1000) {
        ull limm = min(m, (ull)1000);
        for(ull i = 1; i <= limm; i++){
            res += (ckn(n-1001 + m-i, n-1001) * (DP[i][1000] % 1000000007)) % 1000000007;
        }
    }

    cout << res % 1000000007;

    system("Pause");
    return 0;
} 