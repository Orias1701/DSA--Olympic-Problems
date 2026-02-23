#include<bits/stdc++.h>

using namespace std;

using ll = long long;

bool isSquare(ll x) {
    ll r = sqrtl(x);
    return r * r == x;
}

bool isFibo(ll n) {
    return isSquare(5*n*n + 4) || isSquare(5*n*n - 4);
}

int main(){
    ll a, b, m;
    cin >> a >> b >> m;
    ll res = gcd(a, b);
}