#include <bits/stdc++.h>
using namespace std;

long long binarySearch(long long x, const vector<long long>& B) {
    int n = B.size();
    if (x <= B[0]) return B[0] - x;
    if (x >= B[n - 1]) return x - B[n - 1];

    int l = 0, r = n - 1;
    while (r - l > 1) {
        int mid = (l + r) / 2;
        if (B[mid] <= x) l = mid;
        else r = mid;
    }
    return min(x - B[l], B[r] - x);
}

long long arrMin(int L, int R, const vector<long long>& A) {
    long long minA = A[L-1];
    for(int i = L; i < R; i++){
        if(minA > A[i]) minA = A[i];
    }
    return minA;
}

void Task1(){
    int m, n, k;
    cin >> m >> n >> k;
    vector<long long> A(m), B(n);
    for (int i = 0; i < m; i++) cin >> A[i];
    for (int i = 0; i < n; i++) cin >> B[i];
    sort(B.begin(), B.end());
    
    for (int i = 0; i < m; i++) {
        A[i] = binarySearch(A[i], B);
    }
    int L, R;
    for (int i = 0; i < k; i++){
        cin >> L >> R;
        cout << arrMin(L, R, A) << endl;
    }
}

void overL(int idx, int n, const vector<long long>& V, const vector<long long>& H, vector<vector<long long>>& overF) {
    int val = (V[idx]-1)*H[idx];
    int block = 0;
    for(int i = idx-1; i >= 0; i--){
        if(H[i] > H[idx]) {
            val = (V[idx]-V[i]-1)*H[idx] + overF[i][0];
            break;
        }
        block += H[i];
    }
    overF[idx][0] = val - block;
}

void overR(int idx, int n, const vector<long long>& V, const vector<long long>& H, vector<vector<long long>>& overF) {
    int val = (n - V[idx] - 1)*H[idx];
    int block = 0;
    for(int i = idx+1; i < n; i++){
        if(H[i] > H[idx]) {
            val = (V[i]-V[idx]-1)*H[idx] + overF[i][1];
            break;
        }
        block += H[i];
    }
    overF[idx][1] = val - block;
}

int overCount(long long K, int n, const vector<vector<long long>>& overF) {
    int count = 0;
    for(int i = 0; i < n; i++){
        if(K > overF[i][0]) count++;
        if(K > overF[i][1]) count++;
    }
    return count;
}

void Task2() {
    int n, m, q;
    cin >> n >> m;

    vector<long long> V(n), H(n);
    vector<vector<long long>> overF(n, vector<long long>(3, 0));

    for (int i = 0; i < n; i++) cin >> V[i];
    for (int i = 0; i < n; i++) cin >> H[i];

    for (int i = 0; i < n; i++) {
        overL(i, n, V, H, overF);
        overR(n-i-1, n, V, H, overF);
    }

    for (int i = 0; i < n; i++) {
        cout << overF[i][0] << " " << overF[n-i-1][1] << endl;
    }

    // cin >> q;
    // long long K;
    // for (int i = 0; i < q; i++) {
    //     cin >> K;
    //     int overC = min(n, overCount(K, n, overF));
    //     cout << overC << endl;
    // }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // Task1();
    Task2();

    return 0;
}
