/*
Input: n;
Phân tích n ra thừa số nguyên tố
Output: số lượng số nguyên tố : danh sách;
*/

#include <bits/stdc++.h>

using namespace std;

int main(){
    long long n;
    map<long long, long long> PrimeN;
    cin >> n;
    long long i = 2;
    while(i*i <= n) {
        if(n%i == 0){
            PrimeN[i]++;
            n /= i;
        } else i++;
    }
    if(n>1) PrimeN[n]++;
    cout << PrimeN.size() << endl;
    for (auto &x : PrimeN) {
        cout << x.first << " " << x.second << "\n";
    }
    system("pause");
    return 0;
}