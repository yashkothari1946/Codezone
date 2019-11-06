
//Euler Totient or phi function is used to calculate number of coprimes from 1 to n with n.
//Formula  : res = n*(1-1/p1)*(1-1/p2)*.... where p1, p2 etc are prime factors;
#include <bits/stdc++.h>
using namespace std;
#define ll long long int
ll euler_totient(ll n){
	ll res=n;
	for(ll i=2;i*i<=n;i++){
		if(n%i==0){
			while(n%i==0){
				n=n/i;
			}
			res-=res/i;
		}
	}
	if (n > 1)
		 res-=res/n;
	return res;
}

int main() {
	ll n;
    for (n = 1; n <= 10; n++)
        printf("phi(%lld) = %lld\n", n, euler_totient(n));
    return 0;
}
