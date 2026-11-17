#include <iostream>
using namespace std;

int main() {

    int A,B,C,D,E;
    cin >> A >> B >> C >> D >> E ;
    // cout << A << ' ' << B <<  ' ' << C << " " << D << ' ' << E << endl;

    bool invalid = false;
    if (A < -10000 || A > 10000) invalid = true;
    if (B < -10000 || B > 10000) invalid = true;
    if (C < -10000 || C > 10000) invalid = true;
    if (D < -10000 || D > 10000) invalid = true;
    if (E < -10000 || E > 10000) invalid = true;

    if (invalid) {
        std::cout << "Invalid input!" << std::endl;
        return 1;
    }
    int negative_numbers=0,positive_numbers=0;
    if(A<0){negative_numbers++;}
    if(B<0){negative_numbers++;}
    if(C<0){negative_numbers++;}
    if(D<0){negative_numbers++;}
    if(E<0){negative_numbers++;}
    int sum=0;
    sum = (A+B+C+D+E) ;
    if(A>0){positive_numbers++;}
    if(B>0){positive_numbers++;}
    if(C>0){positive_numbers++;}
    if(D>0){positive_numbers++;}
    if(E>0){positive_numbers++;}
    int min_pos = 2147483647; // Max int value
    if (A > 0 && A < min_pos) min_pos = A;
    if (B > 0 && B < min_pos) min_pos = B;
    if (C > 0 && C < min_pos) min_pos = C;
    if (D > 0 && D < min_pos) min_pos = D;
    if (E > 0 && E < min_pos) min_pos = E;
    int max_val; 
    if(A>=B and A>=C and A>=D and A>=E){
        max_val = A;
    }
    if(B>=A and B>=C and B>=D and B>=E){
        max_val = B;
    }
    if(C>=A and C>=B and C>=D and C>=E){
        max_val = C;
    }
    if(D>=A and D>=C and D>=B and D>=E){
        max_val = D;
    }
    if(E>=B and E>=C and E>=D and E>=A){
        max_val = E;
    }
    int min_val;
    if(A<=B and A<=C and A<=D and A<=E){
        min_val = A;
    }
    if(B<=A and B<=C and B<=D and B<=E){
        min_val = B;
    }
    if(C<=A and C<=B and C<=D and C<=E){
        min_val = C;
    }
    if(D<=A and D<=C and D<=B and D<=E){
        min_val = D;
    }
    if(E<=B and E<=C and E<=D and E<=A){
        min_val = E;
    }
    int count_less_A = (B < A) + (C < A) + (D < A) + (E < A);
    int count_eq_A = (B == A) + (C == A) + (D == A) + (E == A);
    int count_less_B = (A < B) + (C < B) + (D < B) + (E < B);
    int count_eq_B = (A == B) + (C == B) + (D == B) + (E == B);
    int count_less_C = (A < C) + (B < C) + (D < C) + (E < C);
    int count_eq_C = (A == C) + (B == C) + (D == C) + (E == C);
    int count_less_D = (A < D) + (B < D) + (C < D) + (E < D);
    int count_eq_D = (A == D) + (B == D) + (C == D) + (E == D);
    int count_eq_E = (A == E) + (B == E) + (C == E) + (D == E);

    int median = E;
    if(count_less_A <= 2 && (count_less_A + count_eq_A) >= 2){
        median = A;
    }
    if(count_less_B <= 2 && (count_less_B + count_eq_B) >= 2){
        median = B;
    }
    if(count_less_C <= 2 && (count_less_C + count_eq_C) >= 2){
        median = C;
    }
    if(count_less_D <= 2 && (count_less_D + count_eq_D) >= 2){
        median = D;
    }
    
    bool breach = ( (((A * C) % 7 == 0) && (abs(A - C) > 10)) || 
                    (((A * D) % 7 == 0) && (abs(A - D) > 10)) || 
                    (((A * E) % 7 == 0) && (abs(A - E) > 10)) ||
                    (((B * D) % 7 == 0) && (abs(B - D) > 10)) ||
                    (((B * E) % 7 == 0) && (abs(B - E) > 10)) ||
                    (((C * E) % 7 == 0) && (abs(C - E) > 10)));
    

    bool exactly_one_pair = (count_eq_A + count_eq_B + count_eq_C + count_eq_D + count_eq_E) == 2;

    int non_repeated_sum = 0;
    if (A == B) non_repeated_sum = C + D + E;
    if (A == C) non_repeated_sum = B + D + E;
    if (A == D) non_repeated_sum = B + C + E;
    if (A == E) non_repeated_sum = B + C + D;
    if (B == C) non_repeated_sum = A + D + E;
    if (B == D) non_repeated_sum = A + C + E;
    if (B == E) non_repeated_sum = A + C + D;
    if (C == D) non_repeated_sum = A + B + E;
    if (C == E) non_repeated_sum = A + B + D;
    if (D == E) non_repeated_sum = A + B + C;


    int odd_count = (A % 2) + (B % 2) + (C % 2) + (D % 2) + (E % 2);
    int even_count = 5 - odd_count;

    int second_largest = min_val;
    if (A < max_val && A > second_largest) second_largest = A;
    if (B < max_val && B > second_largest) second_largest = B;
    if (C < max_val && C > second_largest) second_largest = C;
    if (D < max_val && D > second_largest) second_largest = D;
    if (E < max_val && E > second_largest) second_largest = E;

    int max_count = (A == max_val) + (B == max_val) + (C == max_val) + (D == max_val) + (E == max_val);
    if (max_count > 1) {
        second_largest = max_val;
    }

    double remaining_avg = (sum - max_val - min_val) / 3.0;


    if (sum < 0 && negative_numbers >= 3) {
        cout << "LOCKDOWN" << endl;
    }
    else if(positive_numbers >= 1 && max_val > (3 * min_pos) && median % 2 == 0) {
        cout << "CRITICAL" << endl;
    }
    else if(breach) {
        cout << "BREACH" << endl;
    }
    else if(exactly_one_pair && (non_repeated_sum % 2 == 1)) {
        cout << "ANOMALY" << endl;
    }
    else if((odd_count > even_count) && (second_largest % 3 == 0) ) {
        cout << "WARNING" << endl;
    }
    else if ((max_val - min_val) > remaining_avg) {
        cout << "MONITOR" << endl;
    }
    else {
        cout << "SAFE" << endl;
    }

    return 0;
}
