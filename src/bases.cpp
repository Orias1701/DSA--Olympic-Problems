#include <bits/stdc++.h>

#define MaxN 1e5;

using namespace std;

using ull = unsigned long long;
using ll = long long;

struct Stc{int stc1, stc2;};

using pairStc = pair<int, Stc>;

const int num1 = MaxN;
const int num2 = MaxN + 1;

vector<pair<int, int>> PR(num1, {0, 0});
vector<vector<int>> DP(num1, vector<int>(num2, 0));
map<int, pair<int, Stc>> mp1;
map<int, pairStc> mp2;

int main(){
    // ios_base::sync_with_stdio(false);
    // cin.tie(NULL);

    int n, m;

    cin >> n >> m;


    system("pause");
    return 0;
}