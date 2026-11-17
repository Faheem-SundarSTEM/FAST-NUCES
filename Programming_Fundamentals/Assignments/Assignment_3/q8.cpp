#include <iostream>
using namespace std;


int abs_val(int x){
	if (x < 0)
		return -x;
	return x;
}

char cell_char(int i, int j, int N){
	int d = abs_val(i - N) + abs_val(j - N);

	if (d == 0)
		return '@';
	if (d > N)
		return '.';
	if (d == N){              
		if (i < N)
			return '0' + i % 10;      
		if (i > N)
			return '0' + j % 10;    
		if (j < N)
			return '<';            
		return '>';    
	}
	if (d % 2 == 1)
		return '*';
	if (i == N || j == N)
		return '+';
	return ' ';
}

void print_border(int N){
	cout << '+';
	for(int k = 0; k < 2 * N + 1; k++)
		cout << '-';
	cout << '+' << endl;
}

void print_fortress(int N){
	int S = 2 * N + 1;
	print_border(N);
	for(int i = 0; i < S; i++){
		cout << '|';
		for(int j = 0; j < S; j++)
			cout << cell_char(i, j, N);
		cout << '|' << endl;
	}
	print_border(N);
}

int count_char(int N, char ch){
	int count = 0;
	int S = 2 * N + 1;
	for(int i = 0; i < S; i++){
		for(int j = 0; j < S; j++){
			if(cell_char(i, j, N) == ch)
				count++;
		}
	}
	return count;
}

int count_outline(int N){
	int count = 0;
	int S = 2 * N + 1;
	for(int i = 0; i < S; i++){
		for(int j = 0; j < S; j++) {
			if(abs_val(i - N) + abs_val(j - N) == N)
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
	print_fortress(N);
	cout << "Stars: " << count_char(N, '*') << " Outline stones: " << count_outline(N)
	     << " Sand: " << count_char(N, '.') << endl;
}

int main()
{
	int N;
	cout << "Enter size (N): ";
	cin >> N;
	solve(N);

	return 0;
}