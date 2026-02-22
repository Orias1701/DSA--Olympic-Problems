#include <bits/stdc++.h>

using namespace std;

int main(){
    int n;
    long long C;
    cin >> n >> C;
    vector <pair<long long, long long>> A(n);
    for(int i = 0; i < n; i++) {
        cin >>  A[i].first;
    }
    for(int i = 0; i < n; i++) {
        cin >>  A[i].second;
    }

    sort(A.begin(), A.end());

    long long minC = 1000000001;

    for(int i = 0; i < n-1; i++) {
        long long maxCi = 0;
        long long sumCi = A[i].second;
        // cout << A[i].first;
        for (int j = i+1; j < n; j++){
            long long ex = A[j].first - A[j-1].first;
            // cout << " " << A[j].first;
            maxCi = max(maxCi, ex);
            sumCi += A[j].second;
            if(sumCi > C) break;
        }
        if(sumCi > C) minC = min(maxCi, minC);
        // cout << "\nmaxCi: " << maxCi << " minC: " << minC << endl;
    }

    // cout << "\n";
    cout << minC;
    system("Pause");
    return 0;
}