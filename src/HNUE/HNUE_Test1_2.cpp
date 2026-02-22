#include<bits/stdc++.h>

using namespace std;

using ll = long long;
using str = string;
using ull = unsigned long long;

int main(){

    // freopen("DKT.INP", "r", stdin);
    // freopen("DKT.OUT", "w", stdout);

    ll n, res;

    cin >> n;

    res = (n*(n+1)/2)%26;

    cout << char(res+65);

    system("pause");
    return 0;
}