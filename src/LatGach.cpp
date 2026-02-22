// Ý tưởng: N viên gạch => Có Fibo(N+1) Cách lát
#include <iostream>
#include <utility> 

using namespace std;

pair<long long, long long> F(int n) {
    if (n == 0)
        return {0, 1};

    auto p = F(n / 2);
    long long a = p.first;   // F(k)
    long long b = p.second;  // F(k+1)

    long long c = a * (2 * b - a);      // F(2k) = F(k) * [2*F(k+1) - F(k)]
    long long d = a * a + b * b;        // F(2k+1) = F(k)^2 + F(k+1)^2

    if (n % 2 == 0) return {c, d};      // F(n), F(n+1)
    else return {d, c + d};             // F(n), F(n+1) = F(n-1) + F(n) (Ở đây đã +1 vào n)
}

long long solve(int n) {
    return F(n).second;
}

int main() {
    int n;
    cout << "Nhap n: ";
    cin >> n;
    int kq = solve(n);
    cout << "So cach lat gach: " << kq << endl;
    return 0;
}