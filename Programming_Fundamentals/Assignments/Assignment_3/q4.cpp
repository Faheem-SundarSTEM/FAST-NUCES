#include <iostream>
using namespace std;

int main()
{
	long long N, K, P;
	cout << "Enter the number of people (N): ";
	cin >> N;
	cout << "Enter the step (K): ";
	cin >> K;
	cout << "Enter the person to track (P): ";
	cin >> P;

	if (N < 3 || K < 1 || P < 1 || P > N) {
		cout << "Invalid input (N >= 3, K >= 1, 1 <= P <= N)." << endl;
		return 0;
	}


	//   f = champ, r = runner-up, t = third
	long long f = 0, r = 0, t = 0;
	int lucky = 0;                         
	for (long long n = 1; n <= N; n++) {
		if (n == 1)
			f = 0;
		else
			f = (f + K) % n;               // f(n) = (f(n-1) + K) % n

		if (n == 2)
			r = (K - 1) % 2;               // runner-up
		else if (n >= 3)
			r = (r + K) % n;

		if (n == 3)
			t = (K - 1) % 3;               // third last
		else if (n >= 4)
			t = (t + K) % n;

		if (f == 0)
			lucky++;
	}

	long long pos = P - 1;
	long long turn = 0;
	for (long long m = N; m >= 1; m--) {
		long long e = (K - 1) % m;   
		if (pos == e) {
			turn = N - m + 1;
			break;
		}
		pos = (pos - e - 1 + m) % m; 
	}

	cout << "First eliminated: " << (K - 1) % N + 1 << endl;
	cout << "Third last: " << t + 1 << endl;
	cout << "Runner-up (2nd last): " << r + 1 << endl;
	cout << "Champion (last standing): " << f + 1 << endl;
	if (turn == N)
		cout << "Person " << P << " is the champion (last standing)." << endl;
	else
		cout << "Person " << P << " is eliminated in turn " << turn << endl;
	cout << "Lucky circles (champion at position 1) for sizes 1.." << N << ": " << lucky << endl;

	return 0;
}