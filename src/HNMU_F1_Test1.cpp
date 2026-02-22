#include <bits/stdc++.h>

using namespace std;

int main(){
    int n;
    cin >> n;
    vector<long long> A(n + 1);

    long long temp;
    long long maxB = 0;
    for (int i = 0; i < n; i++) {
        cin >> temp;
        A[i] = temp*(i+1)-maxB;
        maxB += A[i];
    }
    
    for (int i = 0; i < n; i++) {
        cout << A[i] << " ";
    }

    system("pause");
    return 0;
}