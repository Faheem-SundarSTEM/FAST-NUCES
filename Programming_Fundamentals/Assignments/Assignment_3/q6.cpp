#include <iostream>
using namespace std;

bool is_prime(int n){
	if(n < 2)
		return false;
	for(int i = 2; i * i <= n; i++){
		if(n % i == 0)
			return false;
	}
	return true;
}

int reverse_num(int n){
	int r = 0;
	for(; n > 0; n /= 10)
		r = r * 10 + n % 10;
	return r;
}

int digit_sum(int n){
	int s = 0;
	for(; n > 0; n /= 10)
		s += n % 10;
	return s;
}

int digit_count(int n){
	int c = 0;
	for(; n > 0; n /= 10)
		c++;
	return c;
}

int power(int b, int e){
	int r = 1;
	for(int i = 0; i < e; i++)
		r *= b;
	return r;
}

int proper_sum(int n){
	if (n == 1)
		return 0;
	int s = 1;
	for(int d = 2; d * d <= n; d++){
		if(n % d==0){
			s += d;
			if(d != n / d)
				s += n / d;
		}
	}
	return s;
}

int square_sum(int n){
	int s = 0;
	for(; n > 0; n /= 10)
		s += (n % 10) * (n % 10);
	return s;
}

bool is_emirp(int n){
	int rev = reverse_num(n);
	return is_prime(n) && rev != n && is_prime(rev);
}

bool is_palindrome(int n){
	return reverse_num(n) == n;
}

bool is_armstrong(int n){
	int len = digit_count(n);
	int sum = 0;
	for (int t = n; t > 0; t /= 10)
		sum += power(t % 10, len);
	return sum == n;
}

bool is_perfect(int n){
	return n > 1 && proper_sum(n) == n;
}

bool is_happy(int n){
	for(int i = 0; i < 50; i++){
		if (n == 1)
			return true;
		n = square_sum(n);
	}
	return n == 1;
}

bool is_harshad(int n){
	return n % digit_sum(n) == 0;
}

bool is_abundant(int n){
	return proper_sum(n) > n;
}

bool has_title(int n, int t) {
	if (t == 0) return is_prime(n);
	if (t == 1) return is_emirp(n);
	if (t == 2) return is_palindrome(n);
	if (t == 3) return is_armstrong(n);
	if (t == 4) return is_perfect(n);
	if (t == 5) return is_happy(n);
	if (t == 6) return is_harshad(n);
	return is_abundant(n);
}

void print_title_name(int t) {
	if (t == 0) cout << "Prime";
	else if (t == 1) cout << "Emirp";
	else if (t == 2) cout << "Palindrome";
	else if (t == 3) cout << "Armstrong";
	else if (t == 4) cout << "Perfect";
	else if (t == 5) cout << "Happy";
	else if (t == 6) cout << "Harshad";
	else cout << "Abundant";
}

int title_count(int n) {
	int c = 0;
	for (int t = 0; t < 8; t++) {
		if (has_title(n, t))
			c++;
	}
	return c;
}

int count_title(int L, int R, int t) {
	int c = 0;
	for (int n = L; n <= R; n++) {
		if (has_title(n, t))
			c++;
	}
	return c;
}

void print_decorated(int L, int R){
	for(int n = L; n <= R; n++){
		if(title_count(n) >= 4){
			cout << n << " :";
			for(int t = 0; t < 8; t++){
				if (has_title(n, t)){
					cout << ' ';
					print_title_name(t);
				}
			}
			cout << endl;
		}
	}
}

int max_titles(int L, int R){
	int best = 0;
	for (int n = L; n <= R; n++){
		int c = title_count(n);
		if (c > best)
			best = c;
	}
	return best;
}

int first_with(int L, int R, int mx){
	for(int n = L; n <= R; n++){
		if(title_count(n) == mx)
			return n;
	}
	return L;
}

void solve(int L, int R){
	if (L < 1 || R > 10000 || L > R){
		cout << "Invalid range." << endl;
		return;
	}
	print_decorated(L, R);
	cout << "Primes: " << count_title(L, R, 0) << " Emirps: " << count_title(L, R, 1)
	     << " Palindromes: " << count_title(L, R, 2) << endl;
	cout << "Armstrong: " << count_title(L, R, 3) << " Perfect: " << count_title(L, R, 4)
	     << " Happy: " << count_title(L, R, 5) << endl;
	cout << "Harshad: " << count_title(L, R, 6) << " Abundant: " << count_title(L, R, 7) << endl;
	int mx = max_titles(L, R);
	cout << "Most decorated: " << first_with(L, R, mx) << " with " << mx << " titles" << endl;
}

int main()
{
	int L, R;
	cout << "Enter range start (L): ";
	cin >> L;
	cout << "Enter range end (R): ";
	cin >> R;
	solve(L, R);

	return 0;
}