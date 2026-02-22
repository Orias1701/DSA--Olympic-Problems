#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

typedef unsigned long long ull;

vector<int> Primes;
ull n1;

void sieveOfEratosthenes(int n) {
    // Khởi tạo vector đánh dấu số nguyên tố, ban đầu gán true cho tất cả
    vector<bool> isPrime(n + 1, true);
    isPrime[0] = isPrime[1] = false;

    // Sàng số nguyên tố
    for (int p = 2; p <= n; p++) {
        if (isPrime[p]) {
            Primes.push_back(p);
            for (int i = p * p; i <= n; i += p) {
                isPrime[i] = false;
            }
        }
    }
}

int main(){
    cout << "Nhập n: ";
    cin >> n1;
    int n = sqrt(n1);

    sieveOfEratosthenes(n);
    
    return 0;
}