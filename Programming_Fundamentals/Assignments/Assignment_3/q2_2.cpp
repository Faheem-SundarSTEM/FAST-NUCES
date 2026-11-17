#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
	// --- Part A:
	int N;
	cout << "Enter rows for Pascal's Triangle (1-10): ";
	cin >> N;

	if(N < 1 || N > 10){
		cout << "N must be between 1 and 10." << endl;
		return 0;
	}

	for(int i = 0; i < N; i++){
		for (int s = 0; s < 2 * (N - 1 - i); s++)
			cout << ' ';

		long long c = 1;     
		long long sum = 0;       
		for(int k = 0; k <= i; k++){
			cout << setw(4) << c;
			sum += c;
			c = c * (i - k) / (k + 1);   
		}
		cout << " | sum = " << sum << endl;
	}

	// --- Part B:
	int M;
	cout << "Enter rows for the Sierpinski Seal (1-40): ";
	cin >> M;

	if (M < 1 || M > 40){
		cout << "M must be between 1 and 40." << endl;
		return 0;
	}

	for(int i = 0; i < M; i++){
		for (int s = 0; s < M - 1 - i; s++)
			cout << ' ';

		long long c = 1;
		for(int k = 0; k <= i; k++){
			if (c % 3 == 1)
				cout << "* ";
			else if (c % 3 == 2)
				cout << "+ ";
			else
				cout << "  ";
			c = c * (i - k) / (k + 1);
		}
		cout << endl;
	}

	return 0;
}