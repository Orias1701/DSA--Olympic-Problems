#include <bits/stdc++.h>

using namespace std;

int main(){
    int n;
    cin >> n;
    vector <pair<long long, long long>> A(n);

    for (int i = 0; i < n; i++) {
        cin >> A[i].first >> A[i].second;
    }

    sort(A.begin(), A.end());

    long long maxcur = A[0].second - A[0].first;
    long long lastx = A[0].second;
    long long maxpre = 0;

    for (int i=1; i < n; i++) {
        if(A[i].first <= lastx){
            maxcur += max(0LL, A[i].second - lastx);
            lastx = max(lastx, A[i].second);
        } else {
            lastx = A[i].second;
            maxpre = max(maxcur, maxpre);
            maxcur = A[i].second - A[i].first;
        }
    }

    maxpre = max(maxcur, maxpre);
    cout << maxpre;
    
    system("pause");
    return 0;
}