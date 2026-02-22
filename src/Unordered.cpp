#include <iostream>
#include <unordered_map>

using namespace std;
using ll = long long;

unordered_map<ll, ll> memo;

ll f(ll n) {
    if (n == 0 || n == 1) return 1;
    if (n == 2) return 2;
    if (memo.count(n)) return memo[n];

    ll res;
    if (n % 3 == 0) {
        res = f(2 * (n / 3));
    } else if (n % 3 == 1) {
        ll k = n / 3;
        res = f(2 * k) + f(2 * k + 1);
    } else {
        ll k = n / 3;
        res = f(2 * k) + f(2 * k + 1) + f(2 * k + 2);
    }

    memo[n] = res;
    return res;
}

int main() {
    ll n;
    cout << "Nhap n (n < 1e10): ";
    cin >> n;
    cout << "f(" << n << ") = " << f(n) << endl;
    return 0;
}