#include<bits/stdc++.h>

using namespace std;

int main(){
    int n;
    cin >> n;
    int maxU = -1;
    int maxK = -1;
    vector<int> PrimeN;
    for (int i = 2; i < n; i++){
        int k = i;
        int Ui = 1;
        for (int j = 0; j < PrimeN.size(); j++){
            int U = 1;
            while (k % PrimeN[j]) {
                k /= PrimeN[j];
                U++;
            }
            Ui *= U;
        }

        if (Ui == 1){
            PrimeN.push_back(i);
            cout << "Pushback: " << i << endl;
        }
        
        if (Ui > maxU) {
            maxU = Ui;
            maxK = i;
        }
    }

    cout << maxK << endl;
    system("pause");
    return 0;
}