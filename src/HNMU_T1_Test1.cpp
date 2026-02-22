#include <bits/stdc++.h>

using namespace std;

const int MAXN = 100001;
const float EPS = 1e-6;

bool equal(float x, float y) {
    return fabs(x - y) < EPS;
}

int gt(int n){
    int res = 1;
    for (int i = 2; i <= n; i++){
        res*=i;
    }
    return res;
}

int ckn(int k, int n){
    int res = gt(n)/(gt(k)*gt(n-k));
    return res;
}

void task1(){
    int T;
    float a[101], b[101], c[101];
    cin >> T;

    for (int i = 0; i < T; i++){
        cin >> a[i] >> b[i] >> c[i];
    }

    for (int i = 0; i < T; i++){
        float sum = a[i] + b[i] + c[i];
        if (a[i] <= 0 || b[i] <= 0 || c[i] <= 0 || !equal(sum, 180)) cout << "0\n";
        else {
            if (equal(a[i], 90) || equal(b[i], 90) || equal(c[i], 90)) cout << "VUONG\n";
            else if (a[i] > 90 || b[i] > 90 || c[i] > 90) cout << "TU\n";
            else cout << "NHON\n";
        }
    }
}

void task2(){
    int N;
    long long a[MAXN];

    cin >> N;
    if (N < 0 || N > MAXN) return;
    for (int i = 0; i < N; i++){
        cin >> a[i];
    }
    long long MaxA = 0;
    int count = 1;
    for (int i = 0; i < N; i++){
        if (a[i] > MaxA) {
            MaxA = a[i];
            count = 1;
        }
        else if (a[i] == MaxA) count++;
    }
    cout << count;
}

void task3(){
    unsigned long long N;
    unsigned long long Nprime[MAXN][2];
    memset(Nprime, 0, sizeof(Nprime));

    cin >> N;

    int count = 0;
    if (N % 2 == 0){
        count++;
        Nprime[count][0] = 2;
        while (N % 2 == 0) {
            Nprime[count][1]++;
            N /= 2;
        }
    }

    for (long long i = 3; i * i <= N; i+=2){
        if (N % i == 0){
            count++;
            Nprime[count][0] = i;
            while (N % i == 0){
                Nprime[count][1]++;
                N /= i;
            }
        }
    }

    if (N > 1) {
        count++;
        Nprime[count][0] = N;
        Nprime[count][1] = 1;
    }

    cout << count << endl;
    for (int i = 1; i <= count; i++) cout << Nprime[i][0] << " " << Nprime[i][1] << endl;
}

void task4(){
    int N;
    int Prefix[MAXN];
    int temp;
    cin >> N;
    Prefix[0] = 0;
    for (int i = 1; i <= N; i++) {
        cin >> temp;
        Prefix[i] = Prefix[i-1] + temp;
    }

    sort(Prefix, Prefix + N + 1);
    int count=0, countemp=1;

    for (int i = 1; i <= N; i++){
        if(Prefix[i] == Prefix[i-1]){
            countemp++;
        } else {
            count+=ckn(2, countemp);
            countemp=1;
        }
    }
    cout << count << endl;
}

int main(){
    // ios::sync_with_stdio(false);
    // cin.tie(nullptr);

    task4();
    system("pause");
    return 0;
}