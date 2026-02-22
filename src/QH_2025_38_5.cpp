#include <bits/stdc++.h>
using namespace std;

int main() {
    int a, b, c;
    cin >> a;
    cin >> b;
    cin >> c;

    if (b > max(a,c)) cout << "NO";
    else if (a + b == c) cout << a << "+" << b << "=" << c << endl;
    else if (a * b == c) cout << a << "*" << b << "=" << c << endl;
    else if (a == b + c) cout << a << "=" << b << "+" << c << endl;
    else if (a == b * c) cout << a << "=" << b << "*" << c << endl;
    else cout << "NO";

    system("pause");
    return 0;
}
