#include <iostream>
using namespace std;

int main(){
	int age,member,type,tickets;
	cin >> age >> member >> type >> tickets;

	int base_price =tickets;
	if(age < 13){
		base_price *= 500;
	}
	else{
		if(age < 59){
			base_price *= 800;
		}
		else{
			base_price *= 600;
		}
	}
	int bill = base_price;
	if(type == 1){ // for 3D
		bill += 200 * tickets; 
	}
	int discount =0;
	if(member == 1){
		discount = bill*0.10;
		bill *= 0.90;
	}
	if(tickets >= 5){
		discount = bill*0.05;
		bill *= 0.95;
	}
	if(bill >= 3000){
		discount += 300;
		bill -= 300 ;
	}
	cout << "base_price: " << base_price << endl;
	cout << "discount: "<< discount << endl;
	cout << "final bill: " << bill << endl;
}