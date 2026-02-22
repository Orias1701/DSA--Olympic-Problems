#include <bits/stdc++.h>

using namespace std;

const int MAXN = 100001;

string samestring(string P, string Q, int n){
    string S = "";
    int i = 0;
    int ex = 0;
    while (i < n/2 && ex < 2){
        if (P[i] == Q[i+ex]){
            S += P[i];
            i++;
        } else {
            ex++;
        }
    }
    return S;
}

int main(){
    string Z;
    string S = "No Solution";
    int n;
    cin >> n;
    if (n % 2 == 0) {
        cout << S << endl;
        return 0;
    }
    cin >> Z;

    // for (int i = 0; i < n; i++) {
    //     string T = Z.substr(0, i) + Z.substr(i + 1);
    //     string T1 = T.substr(0, n/2);
    //     string T2 = T.substr(n/2);
    //     // cout << "T1: " << T1 << "\nT2: " << T2 << endl;
    //     if(T1 == T2){
    //         if (S == "No Solution") S = T1; 
    //         else if (T1 != S){
    //             cout << "Multiple Solutions" << endl;
    //             system("Pause");
    //             return 0;
    //         } 
    //     }
    // }

    string T1 = Z.substr(0, n/2);
    string T2 = Z.substr(n/2);
    string T3 = Z.substr(0, n/2 + 1);
    string T4 = Z.substr(n/2 + 1);

    // cout << "T1: " << T1 << "\nT2: " << T2 << "\nT3: " << T3 << "\nT4: " << T4 << endl;

    string S1 = samestring(T1, T2, n);
    string S2 = samestring(T4, T3, n);
    
    // cout << "S1: " << S1 << "\nS2: " << S2 << endl;

    if (S1.length() == n/2) S = S1;
    else if (S2.length() == n/2) S = S2;

    if (S != "No Solution" && Z[0] == Z[n/2] && Z[n-1] == Z[n/2]) S = "Multiple Solutions";

    cout << S << endl;
    system("Pause");
    return 0;
}