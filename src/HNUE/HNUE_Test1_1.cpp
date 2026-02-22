#include<bits/stdc++.h>

using namespace std;

using ll = long long;
using str = string;
using ull = unsigned long long;

int main(){

    // freopen("TBS.INP", "r", stdin);
    // freopen("TBS.OUT", "w", stdout);

    str A;
    int cnt=0;
    for (int i = 0; i < 4; i++){
        cin >> A;

        if(A[0] == '0'){
            cout << 0;
            system("pause");
            return 0;
        }

        if (A[0] == '-') cnt++;
    }
    if (cnt % 2 == 0) cout << 1;
    else cout << -1;

    system("pause");
    return 0;
}