#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ull = unsigned long long;

int main(){
    int n, q, qi;
    cin >> n;
    vector<ll>A(n+1);
    A[0] = 0;
    for(int i = 1; i <= n; i++){
        cin >> A[i];
    }
    ll maxVal = A[n];
    A[n] = 0;
    for(int i = n-1; i > 0; i--){
        if(A[i] > maxVal){
            maxVal = A[i];
            A[i] = A[i+1];
        } else {
            A[i] = A[i+1] + maxVal - A[i];
        }
    }
    cin >> q;
    for (int i = 0; i < q; i++){
        cin >> qi;
        cout << A[qi] << endl;
    }
    system("pause");
    return 0;
}