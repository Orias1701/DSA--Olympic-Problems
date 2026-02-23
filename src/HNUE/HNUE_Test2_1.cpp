#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ull = unsigned long long;

int main(){
    string s, x;
    cin >> s >> x;
    size_t i = 0;
    int cnt = 0;
    while(i<s.length()){
        size_t idx = 0;
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