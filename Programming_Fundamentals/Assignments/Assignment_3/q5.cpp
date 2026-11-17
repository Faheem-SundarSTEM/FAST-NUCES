#include <iostream>
using namespace std;

bool is_prime(int n){
	if (n < 2)
		return false;
	for(int i = 2; i * i <= n; i++){
		if (n % i == 0)
			return false;
	}
	return true;
}

bool is_square(int n){
	for(int r = 1; r * r <= n; r++){
		if (r * r == n)
			return true;
	}
	return false;
}

int spiral_value(int i, int j, int N){
	int r = i;
	if (j < r)
		r = j;
	if (N - 1 - i < r)
		r = N - 1 - i;
	if (N - 1 - j < r)
		r = N - 1 - j;

	int s = N - 2 * r;
	int offset;       
	if (i == r)       
		offset = (N - 1 - r) - j;
	else if (j == r) 
		offset = (s - 1) + (i - r);
	else if (i == N - 1 - r) 
		offset = 2 * (s - 1) + (j - r);
	else
		offset = 3 * (s - 1) + (N - 1 - r - i);

	return s * s - offset;
}

char symbol(int v){
	if (v == 1)
		return '.';
	if (is_square(v))
		return 'S';
	if (is_prime(v)){
		if (is_prime(v - 2) || is_prime(v + 2))
			return 'T';
		return 'P';
	}
	return 'C';
}

void print_spiral(int N){
	for (int i = 0; i < N; i++){
		for (int j = 0; j < N; j++){
			cout << symbol(spiral_value(i, j, N));
			if (j < N - 1)
				cout << ' ';
		}
		cout << endl;
	}
}

int count_symbol(int N, char ch){
	int count = 0;
	for (int i = 0; i < N; i++){
		for (int j = 0; j < N; j++){
			if (symbol(spiral_value(i, j, N)) == ch)
				count++;
		}
	}
	return count;
}

void solve(int N){
	if (N < 1 || N > 12){
		cout << "N must be between 1 and 12." << endl;
		return;
	}
	print_spiral(N);
	cout << "C: " << count_symbol(N, 'C') << " T: " << count_symbol(N, 'T')
	     << " P: " << count_symbol(N, 'P') << " S: " << count_symbol(N, 'S') << endl;
}

int main()
{
	int N;
	cout << "Enter N: ";
	cin >> N;
	solve(N);

	return 0;
}