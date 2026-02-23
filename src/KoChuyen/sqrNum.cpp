#include<bits/stdc++.h>
#define MaxN 1e6

using namespace std;
using ll = long long;

vector<int>A(MaxN, 0);

bool chinhPhuong(long long tmp) {
    if (tmp < 0) return false;
    long long r = sqrtl(tmp);
    return r * r == tmp;
}

int main(){
    ll minK = 1;
    int n;
    cin >> n;

    ll tmp;
    for (int i = 0; i < n; i++){
        cin >> tmp;
        if (chinhPhuong(tmp)){
            int x = sqrt(tmp);
            A[x] = 1;
        }
    }

    for (int i = 0; i < MaxN; i++){
        if(A[i] == 0){
            minK = i*i;
            break;
        }
    }

    cout << minK << endl;
    system("pause");
    return 0;
}