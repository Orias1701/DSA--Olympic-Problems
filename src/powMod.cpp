#include <bits/stdc++.h>

using namespace std;

#define MAX_N 10

int a, e, m;

long long mod_pow(int a, int e, int m){
    long long r = 1;
    a = a % m;
    while(e){
        if(e & 1) r = (r * a) % m;
        a = a * a % m;
        e >>= 1;
    }
    return r;
}

int main(){
    cin >> a >> e >> m;
    int s = mod_pow(a, e, m);
    cout << "a ^  e % m = " << s << endl;
    int x = mod_pow(a, m-2, m);
    cout << "a ^ -1 % m = " << x << endl;
    return 0;
}