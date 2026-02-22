#include <bits/stdc++.h>

// Điều kiện: a e không có ước chung, m là số nguyên tố
using namespace std;

#define MAX_N 1000000

long long n, k, m;
long long G[MAX_N];

long long modPow(long long a, long long e, long long m){
    if(e == -1) e = m - 2;
    long long r = 1;
    a = a % m;
    while(e){
        if(e & 1) r = (r * a) % m;
        a = a * a % m;
        e >>= 1;
    }
    return r;
}

void gtCreate(long long n, long long m){
    G[0] = 1;
    for(long long i = 1; i <= n; i++){
        G[i] = (G[i-1] * i) % m;
    }
}

long long gt(long long n){
    return G[n];
}

long long CMod(long long k, long long n, long long m){
    long long gtn  = gt(n);
    long long gtk  = modPow(gt(k), -1, m);
    long long gtnk = modPow(gt(n-k), -1, m);
    return ((gtn * gtk) % m * gtnk) % m;
}

int main(){
    cin >> n >> k;
    // cin >> m;
    m = 1000000007;
    gtCreate(n, m);
    cout << CMod(k, n, m);
    return 0;
}