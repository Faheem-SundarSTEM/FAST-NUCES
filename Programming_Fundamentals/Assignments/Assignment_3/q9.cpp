#include <iostream>
#include <iomanip>
using namespace std;

bool isPrime(int x){
	for(int i=2;i <x;i++){
		if(x%i==0)
			return 0 ; 
	}
	return 1 ;
}
int gcd(int x,int y){
	for(int i=min(x,y);i >= 1 ;i--){
		if(x % i == 0 and y % i == 0){
			return i;
		}
	}
	return 1;
}
int main(){
	int n ;
	while(1){
		cout << "Enter N: " ;
		cin >> n;
		if(n<=1 or n>=30){
			cout << "N must be between 1 and 30" << endl;
		}
		else{
			break;
		}
	}
	int coprime=0,prime=0,comp=0 ,mxphi_idx=0,mxphi=0,F=1;

	for(int i=1;i <= n;i++){
		int phi=0;
		for(int j=1;j<=n;j++){
			int g = gcd(i,j) ;
			if(g == 1){
				cout << setw(3) << "*" ;
				coprime++;
			}
			else if(isPrime(g)){
				cout << setw(3) << g ;
				prime ++;
			}
			else{
				cout << setw(3) << "#" ;
				comp++;
			}
			if(j <=i and g == 1)
				phi ++ ;
		
		}
		cout << setw(9) << "| phi("<<i<<") = "<< phi << endl ;
		F += phi ;
		if(phi > mxphi){
			mxphi = phi;
			mxphi_idx = i ;
		}

	}
	cout << "Coprime cells: " << coprime << " of " << n*n<< " (" << coprime*100/(n*n)<<"%)" << endl;
	cout << "Prime-gcd cells: " << prime << " Composite-gcd cells: " << comp << endl;;
	cout << "Farey length F_" <<n << " = " << F << endl;
	cout << "Row with the largest phi:" << mxphi_idx << "(phi ="<< mxphi<< ")" << endl;
}