#include <bits/stdc++.h>

// Điều kiện: a e không có ước chung, m là số nguyên tố
using namespace std;

#define MAX_N 1000000

int n, k, m;
long long G[MAX_N];

long long modPow(int a, int e, int m){
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

void gtCreate(int n){
    G[0] = 0;
    G[1] = 1;
    for(int i = 2; i <= n; i++){
        G[i] = G[i-1] * i;
    }
}

long long gt(int n){
    return G[n];
}

long long CMod(int k, int n, int m){
    int gtn =  modPow(gt(n), 1, m);
    int gtk =  modPow(gt(k), -1, m);
    int gtnk = modPow(gt(n-k), -1, m);
    cout << gtn << " " << gtk << " " << gtnk << " \n";
    return gtn*gtk*gtnk;
}


int main(){
    cin >> n >> k;
    cin >> m;
    gtCreate(n);
    cout << CMod(k, n, m);
    return 0;
}