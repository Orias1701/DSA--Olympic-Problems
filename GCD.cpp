#include<iostream>
using namespace std;
const int MOD = 1000000007;
long long powMod(long long a, long long b, long long m){
	long long res = 1;
	a %=m;
	while(b){
		if(b%2==1){
			res *=a;
			res %=m;
		}
		a *=a;
		a %=m;
		b /=2;
	}
	return res;
}

long long inverse(long long a, long long m){
	return powMod(a, m-2, m);
}

int main(){
	long long a, b;
	cin >> a >> b;
	long long kq;
	kq = inverse(a, b);
	cout << kq<<endl;
return 0;
}


// GCD(f(a), f(b)) = f(GCD(a,b))