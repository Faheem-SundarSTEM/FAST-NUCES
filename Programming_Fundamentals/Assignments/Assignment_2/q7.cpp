#include <iostream>

using namespace std;

int main() {
    int mealCategory,servingSize,customerType,diningMethod,spicePreference,dietaryRequirement,timeOfOrder,ingredientAvailable,customizationRequest,isGroupOrder;

    cout << "Enter Meal Category (1: Breakfast, 2: Main Course, 3: Dessert): ";
    cin >> mealCategory;

    cout << "Enter Serving Size (1: Small, 2: Large): ";
    cin >> servingSize;

    cout << "Enter Customer Type (1: Regular, 2: VIP): ";
    cin >> customerType;

    cout << "Enter Dining Method (1: Dine-in, 2: Takeaway, 3: Delivery): ";
    cin >> diningMethod;

    cout << "Enter Spice Preference (1: Mild, 2: Spicy): ";
    cin >> spicePreference;

    cout << "Enter Dietary Requirement(1: None, 2: Vegetarian): ";
    cin >> dietaryRequirement;

    cout << "Enter Time of order(Hour 0-23): ";
    cin >> timeOfOrder;

    cout << "Is ingredient available?(1: Yes, 0: No): ";
    cin >> ingredientAvailable;

    cout << "Enter customzation Request (0: None, 1: Extra Topping): ";
    cin >> customizationRequest;

    cout << "Is Group Order(1: Yes, 0: No): ";
    cin >> isGroupOrder;

    if (mealCategory < 1 || mealCategory > 3 ||
        servingSize < 1 || servingSize > 2 ||customerType < 1 || customerType > 2 ||
        diningMethod < 1 || diningMethod > 3 ||spicePreference < 1 || spicePreference > 2 ||
        dietaryRequirement < 1 || dietaryRequirement > 2 ||timeOfOrder < 0 || timeOfOrder > 23 ||
        ingredientAvailable < 0 || ingredientAvailable > 1 ||
        customizationRequest < 0 || customizationRequest > 1 ||isGroupOrder < 0 || isGroupOrder > 1) {
        
        cout << "Invalid input" << endl;
        return 0;
    }

    if (mealCategory == 1){ // 1. BREAKFAST
        if(servingSize == 1) { // Small
            if(customizationRequest == 1) {
                cout << "Order Rejection,Extra Topping for Small mealCategory not allow" << endl;
            }
            else{
                if(ingredientAvailable == 1){
                    if(diningMethod == 1){
                        cout << "Normal Preparation" << endl;
                    } 
                    else {
                        cout << "Separate Packaging" << endl;
                    }
                } 
                else{
                    cout << "Substitute Ingredient Preparation" << endl;
                }
            }
        } 
        else if(servingSize == 2) { // Large
            if(isGroupOrder == 1) {
                if(customerType == 2) {
                    cout << "Priority Kitchen Handling: VIP" << endl;
                } 
                else {
                    cout << "Normal Preparation" << endl;
                }
            } 
            else{
                if(dietaryRequirement == 2){
                    cout << "Special Dietary Preparation :Vegetarian" << endl;
                }else {
                    cout << "Normal Preparation" << endl;
                }
            }
        } 
        else {
            cout << "Order Rejection in Invalid servingSize" << endl;
        }

    } 
    else if(mealCategory == 2){ // 2. MAIN COURSE
        if(ingredientAvailable == 0){
            if (dietaryRequirement == 2){
                cout << "Substitute Ingredient Preparation :Vegetarian" << endl;
            } 
            else{
                cout << "Manual Confirmation" << endl;
            }
        } 
        else{ 
            if(diningMethod == 1) { // Dine-In
                if(customizationRequest == 1){
                    cout << "Modified Preparation extra Topping etc" << endl;
                } 
                else{
                    cout << "Normal Preparation" << endl;
                }
            }
            else if(diningMethod == 2) { // Takeaway
                cout << "Separate Packaging" << endl;
            } 
            else if(diningMethod == 3) { // Delivery
                if (timeOfOrder < 10 || timeOfOrder > 22) {
                    cout << "Order Rejection" << endl;
                } 
                else {
                    if (customerType == 2) {
                        cout << "Priority Kitchen Handling :VIP" << endl;
                    } 
                    else{
                        cout << "Separate Packaging" << endl;
                    }
                }
            } 
            else{
                cout << "Order Rejection,Invalid dining" << endl;
            }
        }

    } 
    else if(mealCategory == 3){ // 3. DESSERT
        if(spicePreference == 2){
            cout << "Order Rejection:Desserts cannot be spicy" << endl;
        } 
        else{
            if(ingredientAvailable == 1) {
                if(dietaryRequirement == 2) {
                    cout << "Special Dietary Preparation:Vegetarian" << endl;
                } 
                else if(diningMethod == 1) {
                    cout << "Normal Preparation" << endl;
                } 
                else{
                    cout << "Separate Packaging" << endl;
                }
            } 
            else{
                cout << "Manual Confirmation" << endl;
            }
        }
    } 
    else {
        cout << "Order Rejection Invalid meal category selected" << endl;
    }

    return 0;
}