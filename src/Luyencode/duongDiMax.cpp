/*
Input: m, n, Arr[m][n];
Chỉ được đi qua 3 ô kề ở cột bên phải;
Output: Max Arr[i][n];
*/

#include <bits/stdc++.h>

using namespace std;
const int minVal = -101;

int max3(int a, int b, int c){
    return max(max(a, b),c);
}

int main(){
    int m, n;
    int A[101][101];
    cin >> m >> n;
    for (int i = 0; i < n; i++){
        A[0][i] = minVal;
        A[m+1][i] = minVal;
    }
    for (int i = 1; i <= m; i++){
        for(int j = 0; j < n; j++){
            cin >> A[i][j];
        }
    }
    for (int j = 1; j < n; j++){
        for(int i = 1; i <= m; i++){
            A[i][j] += max3(A[i-1][j-1], A[i][j-1], A[i+1][j-1]);
        }
    }
    // for (int i = 1; i <= m; i++){
    //     for(int j = 0; j < n; j++){
    //         cout << A[i][j] <<  " ";
    //     }
    //     cout << endl;
    // }

    int res = minVal;
    for (int i = 1; i <= m; i++){
        if (A[i][n-1] > res) res = A[i][n-1];
    }

    cout << res;
    system("pause");
    return 0;
}