#include <bits/stdc++.h>
using namespace std;

int LCS(const char X[], const char Y[], int m, int n) {
    vector<vector<int>> f(m+1, vector<int>(n+1, 0));

    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (X[i-1] == Y[j-1])
                f[i][j] = f[i-1][j-1] + 1;
            else
                f[i][j] = max(f[i-1][j], f[i][j-1]);
        }
    }
    return f[m][n];
}

int main() {
    int m, n;
    cin >> m >> n;   // nhập độ dài hai dãy

    char X[m], Y[n];

    // nhập m phần tử cho X
    for (int i = 0; i < m; i++) {
        cin >> X[i];
    }

    // nhập n phần tử cho Y
    for (int j = 0; j < n; j++) {
        cin >> Y[j];
    }

    cout << LCS(X, Y, m, n) << "\n";
    return 0;
}
