#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ull = unsigned long long;

int main(){
    int n;
    string s, x;
    cin >> s >> x;
    int i = 0;
    int cnt = 0;
    while(i<s.length()){
        int idx = 0;
        while(s[i+idx] == x[idx]){
            idx++;
            if(idx == x.length()){
                cnt+=1;
                i+=idx-1;
                break;
            }
        }
        i++;
    }
    cout << cnt;
    system("pause");
    return 0;
}