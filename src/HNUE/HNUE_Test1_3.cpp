#include<bits/stdc++.h>

using namespace std;

using ll = long long;
using str = string;
using ull = unsigned long long;

int main(){

    // freopen("DC.INP", "r", stdin);
    // freopen("DC.OUT", "w", stdout);

    map<ull, int> points;
    int n, k;
    ull a, b;

    cin >> n >> k;

    for (int i = 0; i < n; i++){
        cin >> a >> b;
        points[a]++;
        points[b+1]--;
    }

    int tmp = 0;
    for (auto &p : points) {
        p.second += tmp;
        tmp = p.second;
    }

    tmp = 0;
    int cnt = 0;
    for (auto &p : points) {
        if (tmp != 0) cnt += (p.first - tmp);
        if (p.second == k) tmp = p.first;
        else tmp = 0;
    }

    cout << cnt;

    system("pause");
    return 0;
}