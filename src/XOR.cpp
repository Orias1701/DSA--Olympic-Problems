#include <bits/stdc++.h>
using namespace std;

// SOS DP: f[mask] = XOR_{submask ⊆ mask} arr[submask]
void sos_xor(vector<long long> &f, int nbits) {
    int N = 1 << nbits;
    for (int i = 0; i < nbits; i++) {           // nbits <= 32
        for (int mask = 0; mask < N; mask++) {  // mask < N
            if (mask & (1 << i)) {
                // cout << (mask ^ (1 << i)) << " ";
                f[mask] ^= f[mask ^ (1 << i)];
            }
        }
        // cout << endl;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;
    vector<long long> arr(N);
    for (int i = 0; i < N; i++) cin >> arr[i];

    int nbits = 32 - __builtin_clz(N - 1);      // số bit để biểu diễn N-1
    // cout << "nbits: " << nbits << endl;

    int M = 1 << nbits;                         // làm tròn lên thành 2^nbits
    // cout << "M: " << M << endl;

    vector<long long> f(M, 0);
    for (int i = 0; i < N; i++) f[i] = arr[i];

    sos_xor(f, nbits);
    cout << f[N - 1];
    return 0;
}
