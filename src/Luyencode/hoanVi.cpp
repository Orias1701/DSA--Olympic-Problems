#include <bits/stdc++.h>

using namespace std;

void c_out(int n, int k){
    for(int i = 0; i < n; i++){
        int res = i + k + 1 - i / k % 2 * 2 * k; 
        cout << res << " ";
    }
}

int main(){
    int n, k;
    cin >> n >> k;

    if(k == 0){
        for (int i = 0; i < n; i++){
            cout << i + 1 << " ";
        }
    } else {
        if(n / k % 2 != 0){
            cout << -1;
        } else {
            c_out(n, k);
        }
    }
    system("pause");
    return 0;
}