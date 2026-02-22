#include <bits/stdc++.h>

using namespace std;

void Bai1(){
    float a, b;
    cin >> a >> b;
    a = floor(a) + 1;
    b = floor(b);

    int s = (a+b)*(b-a+1)/2;
    cout << s << endl;
}

void Bai2(){
    int n;
    cin >> n;
    vector<int> A(n);
    for(int i = 0; i < n; i++){
        cin >> A[i];
    }
    int Max = A[0];
    int bestSum = INT_MIN, bestL = 0, bestR = -1;
    for (int i = 0; i < n; i++){
        int currentSum = 0;
        for (int j = i; j < n; j++){
            currentSum += A[j];
            if ((j - i + 1) % 3 == 0 && currentSum > bestSum){
                bestSum = currentSum;
                bestL = i;
                bestR = j;
            }
        }
    }
    if (bestR == -1)
        cout << "Not found";
    else{
        cout << bestSum << endl;
    }
}

void Bai3(){
    int n;
    cin >> n;
    vector<int> A(n);
    vector<int> B(n);
    for(int i = 0; i < n; i++){
        cin >> A[i];
    }
    for (int i = 0; i < n; i++){
        cin >> B[i];
    }
    sort(A.begin(), A.end());
    sort(B.begin(), B.end());

    int score = 0;
    int step = 0;
    for (int i = n-1; i >= 0; i--){
        while(i >= step){
            if(A[i - step] < B[i]) {
                score++;
                break;
            } else {
                step++;
            }
        }
    }
    cout << score << endl;
}

int main(){
    // cout << "\nBài 1: " << endl;
    // Bai1();
    // cout << "\nBài 2: " << endl;
    // Bai2();
    cout << "\nBài 3: " << endl;
    Bai3();
    return 0;
}

/*
0.3 2.89

11 
1 1 1 -9 1 1 1 1 -1 1 -9 

5 
10 15 30 20 25 
28 24 20 16 14 
*/