#include <iostream>
#include <cstdlib>     
#include <ctime>        
using namespace std;

int main()
{
	long long secret = 0;
	cout << "Enter 0 for a random code, or a 5-digit code (digits 1-8) for testing: ";
	cin >> secret;

	if (secret == 0){
		srand(time(0));
		for (int i = 0; i < 5; i++)
			secret = secret * 10 + (rand() % 8 + 1);
	}
	else {
		bool ok = (secret >= 10000 && secret <= 99999);
		for(long long t = secret; ok && t > 0; t /= 10){
			if (t % 10 < 1 || t % 10 > 8)
				ok = false;
		}
		if(!ok){
			cout << "Invalid secret code." << endl;
			return 0;
		}
	}

	cout << "The Sphinx's Code is ready. You have 7 tries." << endl;

	long long prev = 0;         
	bool won = false;

	for(int attempt = 1; attempt <= 7; attempt++){
		long long guess;
		cout << "Guess " << attempt << " (5 digits 1-8): ";
		cin >> guess;
	
		bool valid = (guess >= 10000 && guess <= 99999);
		for (long long t = guess; valid && t > 0; t /= 10){
			if (t % 10 < 1 || t % 10 > 8)
				valid = false;
		}

		if (!valid){
			cout << "Invalid guess! The Sphinx laughs. Attempt wasted." << endl;
			continue;
		}
		if(guess == prev){
			cout << "Repeated guess! The Sphinx yawns. Attempt wasted." << endl;
			continue;
		}
		prev = guess;

		int black = 0;
		long long s = secret, g = guess;
		for(int pos = 0; pos < 5; pos++){
			if (s % 10 == g % 10)
				black++;
			s /= 10;
			g /= 10;
		}

		int common = 0;
		for(int d = 1; d <= 8; d++){
			int inSecret = 0, inGuess = 0;
			s = secret;
			g = guess;
			for (int pos = 0; pos < 5; pos++){
				if (s % 10 == d)
					inSecret++;
				if (g % 10 == d)
					inGuess++;
				s /= 10;
				g /= 10;
			}
			common += (inSecret < inGuess) ? inSecret : inGuess;
		}
		int white = common - black;

		cout << "Black Pegs: " << black << endl;
		if (black == 5) {
			cout << "You cracked the code!" << endl;
			cout << "Score: " << 100 - 12 * (attempt - 1) << " / 100" << endl;
			won = true;
			break;
		}
		cout << "White Pegs: " << white << endl;
	}

	if (!won)
		cout << "The Sphinx wins! The code was " << secret << endl;

	return 0;
}