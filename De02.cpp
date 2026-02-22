#include <bits/stdc++.h>

using namespace std;

void Bai1(){
    string S;
    cin >> S;
    int len = S.length();
    int reward = 0;
    int result = 0;
    for (int i = 0; i < len; i++){
        if(S[i] == 'C'){
            reward++;
            result += reward;
        } else reward = 0;
    }
    cout << result << endl;
}

void Bai2(){
    int n;
    cin >> n;
    vector<int> A(n);
    vector<int> B(1000000);
    B[n] = -1;
    for(int i = 0; i < n; i++){
        cin >> A[i];
    }
    sort(A.begin(), A.end());
    for(int i = 0; i < n-1; i++){
        for(int j = i + 1; j < n; j++){
            B[max(A[j]-A[i], A[i]-A[j])] = -1;
        }
    }
    for(int i = n; i < 1000000; i++){
        if (B[i] != -1 ) {
            cout << i << endl;
            break;
        }
    }
}

void Bai3(){
    int n;
    cin >> n;
    vector<vector<int>> pu(4, vector<int>(n));
    for (int i = 0; i < n; i++){
        cin >> pu[0][i] >> pu[1][i] >> pu[2][i] >> pu[3][i];
    }
    // for (int i = 0; i < n; i++){
        
    // }
}

void Bai4() {
    int m, n;
    cin >> m >> n;

    vector<pair<int,int>> A(n);
    for (int i = 0; i < n; i++) {
        cin >> A[i].first >> A[i].second;
    }

    sort(A.begin(), A.end());
    if (A[0].first > 0 || A[n-1].second < m) {
        cout << "Khong\n";
    }
    else {
        int maxR = A[0].second;
        for (int i = 1; i < n; i++) {
            if (A[i].first <= maxR) {
                maxR = max(maxR, A[i].second);
            }
            else {
                cout << "Khong\n";
                break;
            }
        }
        if (maxR == m){
            cout << "Co\n";
        }
    }   
}


int main(){
    // cout << "\nBài 1: " << endl;
    // Bai1();
    // cout << "\nBài 2: " << endl;
    // Bai2();
    // cout << "\nBài 3: " << endl;
    // Bai3();
    cout << "\nBài 4: " << endl;
    Bai4();
    return 0;
}

/*
Bài 1:
CCNNCNNCCC

-> 10


Bài 2
5
2 4 7 10 15

-> 7


Bài 3:
2 
A B C D 
C D C V 
A B X Y 

-> 2 1 2


2 
A B C D 
C D E F 
A B X Y 

-> -1



Bài 4:
20 5
0 5
8 12
4 9
16 20
12 16

-> Co


20 5
0 5
8 12
4 9
16 20
13 16

-> Khong
*/