#include<iostream>
using namespace std;
const int MAX = 10000;
const int MOD = 1000000007;
long long f[MAX];
long long powMod(long long a, long long e){
	long long r = 1;
	a %=MOD;
	while(e){
		if(e%2==1){
			r *=a;
			r %=MOD;
		}
		a *=a;
		a %=MOD;
		e /=2; //<=>(e >>=1)
	}
	return r;
}
long long tinhNgichDao(long long a){
	return powMod(a,MOD-2);
}
long long giaiThua(long long n){
	f[0]=1;
	for(int i=1; i<=n; i++){
		f[i] = i* f[i-1];
		f[i] %=MOD;
	}
	return f[n];	
}
long long C(long long n, long long k){
	return giaiThua(n)%MOD *tinhNgichDao(giaiThua(k))%MOD
	*tinhNgichDao(giaiThua(n-k))%MOD;
}
int main(){
	int a, b;
	cin >> a >>b;
	//cout << powMod(a,b) <<endl;
	//cout << "Tinh nghich dao \n";
	//cout <<tinhNgichDao(a);
	cout << C(a,b) <<endl;

return 0;
}

