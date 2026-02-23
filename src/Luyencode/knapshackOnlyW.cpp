/*
Input: n, W;
Arr w[n] là khối lượng các vật
Tìm cách lấy được khối lượng lớn nhất.
Output: maxW;
*/

#include <bits/stdc++.h>

#define MaxN 50002

using namespace std;

int main(){
    int n, W;
    
    cin >> n >> W;
    vector<int> w(n+2, 0);
    vector<vector<int>> DP(n+2, vector<int>(W+2, 0));
    for (int i = 1; i <= n; i++){
        cin >> w[i];
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= W; j++){
            if(j < w[i]) DP[i][j] = DP[i-1][j];
            else DP[i][j] = max(DP[i-1][j], w[i] + DP[i-1][j-w[i]]);
        }
    }
    cout << DP[n][W];
    system("pause");
    return 0;
}