#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ull = unsigned long long;

int main(){
    ll x, y, z;
    cin >> x >> y >> z;
    ll t1 = x*z;
    if(t1%y != 0) t1 += y - t1%y;
    ll t = t1/y - z;
    cout << max((ll)0, t);
    system("pause");
    return 0;
}