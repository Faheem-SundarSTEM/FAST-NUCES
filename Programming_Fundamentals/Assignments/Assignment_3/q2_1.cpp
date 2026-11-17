#include <iostream>
using namespace std;

int main(){
	int N;
	cout << "Enter side length (N): ";
	cin >> N;

	if(N < 3 || N > 17){
		cout << "N must be between 3 and 17." << endl;
		return 0;
	}

	for(int i = 0; i < N; i++){
		for(int j = 0; j < N; j++){
			if ((i == j) && (i + j == N - 1))
				cout << '@';
			else if(i == j)
				cout << '*';
			else if(i+j == N-1)
				cout << '#';
			else{
				int m = max(abs(i - (N/2)), abs(j - (N/2)));
				int n = N/2+1-m-(N%2==0 and i>=N-j-1);   //expection

				if (n % 2 == 1)
					cout << n;                 
				else
					cout << char('A' + n - 1); 
			}
			cout << ' ';
		}
		cout << endl;
	}

	return 0;
}