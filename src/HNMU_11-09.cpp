#include <bits/stdc++.h>
using namespace std;

vector<int> primeNum;

void sieve(int maxn){
    primeNum.push_back(2);
    for(int i = 3; i * i <= maxn; i += 2){
        bool flag = true;
        for(int p : primeNum){
            if(i % p == 0){
                flag = false;
                break;
            }
            if(p * p > i) break;
        }
        if(flag) primeNum.push_back(i);
    }
}

bool isSymmetry(int n){
    string s = to_string(n);
    int len = s.length();
    for(int i = 0; i < len / 2; i++){
        if(s[i] != s[len - 1 - i]) return false;
    }
    return true;
}

int main(){
    int a, b;
    cin >> a >> b;
    sieve(b);
    int sumSpc = 0;
    for (int i = a; i <= b; i++){
        if(isSymmetry(i)){
            int j = 0;
            int flag = 0;
            while(j < primeNum.size() && flag < 3){
                if(i % primeNum[j] == 0) flag++;
                j++;
            }
            if (flag >= 3) sumSpc+=i;
        }
    }
    cout << sumSpc << endl;
    system("pause");
    return 0;
}