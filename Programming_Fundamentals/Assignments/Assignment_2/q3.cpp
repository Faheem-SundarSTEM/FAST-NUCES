#include <iostream>
using namespace std;

int main(){
	int roomSignal;
	cin >> roomSignal;

	int mainDoor = roomSignal & 1;
    int window = (roomSignal >> 1) & 1;
    int motion = (roomSignal >> 2) & 1;
    int emergency = (roomSignal >> 3) & 1;
    int zone = (roomSignal >> 4) & 7;
    int accessLevel = (roomSignal >> 7) & 3;
    int incidentCode = ((roomSignal >> 9) & 15) ^ 5;
    int maintenance = (roomSignal >> 13) & 1;
    if (emergency == 1) {
        cout << "EMERGENCY\n";
    } 
    else if (maintenance == 1) {
        cout << "MAINTENANCE\n";
    } 
    else if ((mainDoor == 1 || window == 1) && accessLevel == 0) {
        cout << "UNAUTHORIZED ACCESS\n";
    } 
    else if (motion == 1 && incidentCode >= 9) {
        cout << "SECURITY ALERT\n";
    } 
    else if (mainDoor + window + motion + emergency + incidentCode) {
        cout << "ROOM SECURE\n";
    } 
    else {
        cout << "MONITOR REQUIRED\n";
    }
    return 0;
}