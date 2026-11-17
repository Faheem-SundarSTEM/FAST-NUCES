#include <iostream>
using namespace std;

int main(){
	int status;
	cin >> status;
	
	cout << "Device Mode: ";
	if ((status&3) == 0){
		cout << "Normal" << endl;
	}
	else if((status&3) == 1){
		cout << "Silent" << endl;
	}
	else if((status&3) == 2){
		cout << "Performance" << endl;
	}
	else{
		cout << "Gaming" << endl;
	}
	status = status>>2;

	if (status & 1){
		cout << "Battery Saver is ON"<< endl;
	}
	else{
		cout << "Battery Saver is OFF" << endl;
	}
	status = status>>1;

	if (status & 1){
		cout << "GPS is ON"<< endl;
	}
	else{
		cout << "GPS is OFF" << endl;
	}
	status = status>>1;

	if (status & 1){
		cout << "Bluetooth is ON"<< endl;
	}
	else{
		cout << "Bluetooth is OFF" << endl;
	}
	status = status>>1;

	if (status & 1){
		cout << "Wifi is ON"<< endl;
	}
	else{
		cout << "Wifi is OFF" << endl;
	}

}