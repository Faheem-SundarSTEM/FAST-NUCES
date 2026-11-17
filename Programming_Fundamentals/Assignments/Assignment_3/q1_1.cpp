#include <iostream>
#include <cmath>
using namespace std;

long long get_digit(long long x,int m) {
    long long r = 1;
    for (int i = 0; i < m; i++) 
    	r *= 10;
    return (x/r) %10;
} 


int digit_count(long long num){
    int count = 0;
    for (long long temp = num; temp > 0; temp /= 10) {
        count++;
    }
    return count;
}
void printRow(long long x, int D, int k) {
    for (int s = 0; s < D - k; s++) 
    	cout << ' ';
    for (int m = k - 1; m >= 0; m--) 
    	cout << get_digit(x, m); 
    for (int m = 1; m <= k - 1; m++) 
    	cout << get_digit(x, m); 
    cout << endl;
}
void print_diamond(long long x, int D) {
    for (int k = 1; k <= D; k++) 
    	printRow(x, D, k);
    for (int k = D - 1; k >= 1; k--) 
    	printRow(x, D, k);
}

long long reverse(long long x){
	long long xx = 0;
	for (;x>0;x/=10){
		xx = xx*10+(x%10) ;
	}
	return xx ;
}

void solve(int n ){
	long long int x = 21;
	int ind = 0 ;
	int a=2;
	int b=1;
	if(n == a){
		x = a;
		cout << "Position: L" << 0 << endl;
		cout << "Number: " << 2 << endl ;
		cout << "Digits: "<< 1 <<" Digit sum: " << 2 << endl;
		cout << "Pattern:" << endl;
		cout << x << endl;
	}
	else if(n ==b){
		x = a*10+b;
		x = a;
		cout << "Position: L" << 1 << endl;
		cout << "Number: " << 12 << endl ;
		cout << "Digits: "<< 2 <<" Digit sum: " << 3 << endl;
		cout << "Pattern:" << endl;
		cout << " 2\n121\n 2\n" ;
	}
	else{
		int nx=a+b,bew;
		bool flag=0;
		int sum = 3 ,cnt=0;
		for(;nx<=n;nx=a+b){
			int tmp = b;
			b=(a+b);
			a=tmp;
			cnt ++ ;
			if(nx==n){
				ind = cnt;
				flag = 1;
			}
			x=x*pow(10,digit_count(nx))+nx;
			bew = nx;
			sum+=nx ;
		}
		if(!flag){
			cout << n << " is NOT a Lucas number. The door stays sealed." << endl;
			cout << "Nearest Lucas numbers: "<< bew << " (below) and " << nx <<" (above)"<< endl;
		}
		else{
			int D = digit_count(x) ;
			x=reverse(x) ;
			cout << "Position: L" << ind+1 << endl;
			cout << "Number: " << x << endl ;
			cout << "Digits: "<< D <<" Digit sum: " << sum << endl;
			cout << "Pattern:" << endl;
			print_diamond(x,D);
		} 
	}
}

int main()
{
	int n;
	cout << "Enter a number to check: " ;
	cin >> n;
	solve(n) ;

	return 0;
}