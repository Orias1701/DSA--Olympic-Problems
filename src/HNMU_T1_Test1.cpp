#include <bits/stdc++.h>

using namespace std;

const int MAXN = 100001;
const float EPS = 0.0001;

bool equal(float x, float y) {
    return fabs(x - y) < EPS;
}

vector <long long> GT(MAXN, -1);

long long gt(int n){
    if (n < 2) GT[n] = n;
    else if (GT[n] == -1) GT[n] = gt(n-1)*n;
    return GT[n];
}

long long ckn(int k, int n){
    long long res = gt(n)/(gt(k)*gt(n-k));
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
    int cnt = 1;
    for (int i = 0; i < N; i++){
        if (a[i] > MaxA) {
            MaxA = a[i];
            cnt = 1;
        }
        else if (a[i] == MaxA) cnt++;
    }
    cout << cnt;
}

void task3(){
    long long N;
    cin >> N;
    int i = 2;
    map<int, int> dem;

    for (int i = 2; i*i <= N; i++) {
        while (N % i == 0){
            dem[i]++;
            N/=i;
        }
    }

    if (N>1) {
        dem[N]++;
    }

    cout << dem.size();
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
    long long cnt=0;
    int cntemp=1;

    for (int i = 1; i <= N; i++){
        if(Prefix[i] == Prefix[i-1]){
            cntemp++;
        } else {
            cnt+=ckn(2, cntemp);
            cntemp=1;
        }
    }
    cout << cnt << endl;
}

int main(){
    // ios::sync_with_stdio(false);
    // cin.tie(nullptr);

    task4();
    system("pause");
    return 0;
}