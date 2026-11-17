#include <iostream>
using namespace std;

int print_solid(int n) {
	int total = 0;
	for (int i = 0; i <= 2 * n; i++){
		for (int j = 0; j <= 2*n; j++){
			if (i<=j and (i<=(2*n-j))){
				cout << '#';
				total++;
			}
			else if(i>=j and (i>=(2*n-j))){
				cout << '#';
				total++;
			}
			else{cout << ' ';}
		}
		cout << endl;
	}
	return total;
}

int print_hollow(int n) {
	int total = 0;
	for (int i = 0; i <= 2 * n; i++){
		for (int j = 0; j <= 2*n; j++){
			if(i==j or (i==(2*n-j))){
				cout << '#';
				total++;
			}
			else if(i==0 or 2*n == i){
				cout << '#';
				total ++ ;
			}
			else{cout << ' ';}
		}
		cout << endl;
	}
	return total;
}

int print_checker(int n) {
	int total = 0;
	for (int i = 0; i <= 2 * n; i++){
		for (int j = 0; j <= 2*n; j++){
			if (i<=j and (i<=(2*n-j))){
				if(i%2==j%2){
					cout << '#';
					total++;
				}else{cout << "*" ;}
			}
			else if(i>=j and (i>=(2*n-j))){
				if(i%2==j%2){
					cout << '#';
					total++;
				}
				else{cout << "*";}
			}
			else{cout << ' ';}
		}
		cout << endl;
	}
	return total;
}

void solve(int x){
	long long c = 1, below = 1;
	int n = 0;
	bool flag = 0;
	for (int k = 0; c <= x; k++){
		if (c == x){
			flag = 1;
			n = k;
			break;
		}
		below = c;
		c = c * 2 * (2 * k + 1) / (k + 2);
	}
	if(!flag){
		cout << x << " is not a Catalan number." << endl;
		cout << "Nearest Catalan: " << below << " (below) and " << c << " (above)" << endl;
	}
	else{
		if (x == 1)
			n = 1;
		int total;
		cout << "Catalan Index (n): " << n << endl;
		if (n % 3 == 0) {
			cout << "Style: Checker" << endl;
			cout << "Pattern:" << endl;
			total = print_checker(n);
		}
		else if (n % 2 == 1) {
			cout << "Style: Hollow" << endl;
			cout << "Pattern:" << endl;
			total = print_hollow(n);
		}
		else {
			cout << "Style: Solid" << endl;
			cout << "Pattern:" << endl;
			total = print_solid(n);
		}
		cout << "Total runes (#): " << total << endl;
	}
}

int main()
{
	int x;
	cout << "Enter the Catalan code: ";
	cin >> x;
	solve(x);

	return 0;
}