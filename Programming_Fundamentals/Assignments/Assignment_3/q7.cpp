#include <iostream>
using namespace std;

int main(){
    int n;
    cout << "Enter size (N): ";
    cin >> n;

    if (n < 1) {
        cout << "N must be at least 1." << endl;
        return 0;
    }

    int sp = 6 * n;
    int sw = 5;
    int ls = 2;
    int d = 2 * n;
    int t = 3 * n / 2;
    bool flag = 0;  

    for (int i = 1; i <= 4 * n + 1; i++){
        bool tail = (d <= t);

        for (int j = 0; j < sp; j++)
            cout << ' ';

        if (d == 0){
            for(int j=0;j<10;j++)cout <<' ';
            for(int j = 0; j < sw; j++)
                cout << '*';
            for(int j = 0; j < ls - 3-10; j++)
                cout << '*';
        }
        else{
            if(d >= n/2 && d <= n - 1){
                int before  = 4 * n - 3 * d - 2;
                for (int j = 0; j < before; j++)
                    cout << '*';
                if(i < 2*n)cout << "  ";
                else cout << "**";
                for (int j = 0; j < sw - before - 2; j++)
                    cout << '*';
            }
            else {
                for (int j = 0; j < sw; j++)
                    cout << '*';
            }

            // gap and tail
            if (tail) {
                for (int j = 0; j < 6 * d - 3; j++)
                    cout << ' ';
                for (int j = 0; j < ls; j++)
                    cout << '*';
            }
        }
        cout << endl;

        // update for the next row
        if (d == 0)
            flag = 1;
        if (!flag) {
            sp -= 3;
            sw += 6;
            d--;
            if (tail)
                ls += 3;
        }
        else {
            sp += 3;
            sw -= 6;
            d++;
            if (tail)
                ls -= 3;
        }
    }

    return 0;
}