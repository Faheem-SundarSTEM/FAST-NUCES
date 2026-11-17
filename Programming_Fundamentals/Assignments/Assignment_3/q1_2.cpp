#include <iostream>
using namespace std;

long long get_digit(long long x,int m){/// take dgt from right
    long long r = 1;
    for (int i = 0; i < m; i++)
        r *= 10;
    return (x / r) % 10;
}

int digit_count(long long num){
    int count = 0;
    for (long long temp = num; temp > 0; temp /= 10) {
        count++;
    }
    return count;
}
void print_triangle(int T, long long S){
    int len = digit_count(S);
    int idx = 0;
    for (int r = 1; r <= T; r++) {
        for (int s = 0; s < T - r; s++)
            cout << ' ';
        for (int c = 0; c < r; c++) {
            cout << get_digit(S, len - 1 - (idx % len));
            idx++;
        }
        cout << endl;
    }
}

void solve(int n){
    long long a = 0, b = 0, c = 1;  
    long long S = 0, below = 0, above = 0;
    int T = 0;
    bool flag = false;

    for(int i = 0;a <= n;i++){
        S += a;
        if (a == n) {                 
            flag = true;
            T = i + 1;
            break;
        }
        below = a;
        int t = a + b + c;
        a = b;
        b = c;
        c = t;
    }
    above = a;

    if(!flag){
        cout << "The Scroll rejects " << n << endl;
        cout << "Nearest Tribonacci: " << below << " (below) and " << above << " (above)" << endl;
        return;
    }

    cout << "Number: ";
    a = 0; b = 0; c = 1;
    for (int i = 0; i < T; i++) {
        cout << a;
        int t = a + b + c;
        a = b;
        b = c;
        c = t;
    }
    cout << endl;
    cout << "Terms used: " << T << endl;
    cout << "Accumulated Sum (S): " << S << endl;
    cout << "Pattern:" << endl;
    print_triangle(T, S);
}

int main() {
    int n;
    cout << "Enter the magic number: ";
    cin >> n;
    solve(n);
    return 0;
}