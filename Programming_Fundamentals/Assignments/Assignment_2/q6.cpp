#include <iostream>
#include <string>
using namespace std;
int main() {
    // Inputs
    int doc_status,importer_type,origin_category,verification_passed,declared_value,weight,num_restricted_items,dest_category,inspection_status,insurance_status,customs_flagged,priority_level;

    string decision="";

    cout << "Enter documentation status(1=Valid, 0=Incomplete): ";
    cin >> doc_status;

    cout << "Enter importer type (1=Licensed, 2=Regular, 3=First-Time): ";
    cin >> importer_type;

    cout << "Enter origin category (1= High-Risk, 2 =Standard): ";
    cin >> origin_category;

    cout << "Enter verification Status (1 =Passed, 0= Failed): ";
    cin >> verification_passed;

    cout << "Enter Declared value: ";
    cin >> declared_value;

    cout << "Enter shipment Weight: ";
    cin >> weight;

    cout << "Enter number of Restricted Items: ";
    cin >> num_restricted_items;

    cout << "Enter destination Category (1=Free-Trade Zone, 2=Domestic, 3=Restricted): ";
    cin >> dest_category;

    cout << "Enter Physical Inspection Status (1= Passed, 0=Failed/Pending): ";
    cin >> inspection_status;

    cout << "Enter Insurance Status (1 = Insured, 0 = Uninsured): ";
    cin >> insurance_status;

    cout << "Enter Customs Flag Status (1 = Previously Flagged, 0 = Clean): ";
    cin >> customs_flagged;

    cout << "Enter Priority Level (1 = High Priority, 0 = Normal): ";
    cin >> priority_level;

    if (declared_value < 0 || weight < 0 || origin_category < 1 || origin_category > 2 || dest_category < 1 || dest_category > 3 || 
        num_restricted_items < 0 || doc_status < 0 || doc_status > 1 || inspection_status < 0 || inspection_status > 1 || 
        insurance_status < 0 || insurance_status > 1 || importer_type < 1 || importer_type > 3 || 
        priority_level < 0 || priority_level > 1 || customs_flagged < 0 || customs_flagged > 1) {
    
        std::cout << "Invalid input" << std::endl;
        return 0;
    }

    if (doc_status == 0) {
        if (importer_type == 1) {
            decision = "TEMPORARY_CLEARANCE";
        } else {
            decision = "REJECTED_INCOMPLETE_DOCUMENTATION";
        }
    } 
    else {
        if(origin_category == 1 && importer_type == 3) {
            decision = "REJECTED_HIGH_RISK_FIRST_TIME";
        } 
        else if(origin_category == 1 && importer_type == 2 && verification_passed == 0){
            decision = "REJECTED_VERIFICATION_FAILED";
        } 
        else {
            if(declared_value >= 100000){
                if(weight > 5000) {
                    if(inspection_status == 0 || insurance_status == 0) {
                        decision = "MANUAL_REVIEW_HIGH_VALUE_HEAVY";
                    } 
                    else{
                        decision = "PROCEED_TO_RESTRICTED_CHECK";
                    }
                } 
                else if(inspection_status == 0) {
                    decision = "REJECTED_HIGH_VALUE_INSPECTION_FAILED";
                }
            } 
            else if(weight > 5000 && inspection_status == 0) {
                decision = "REJECTED_HEAVY_INSPECTION_FAILED";
            }
            if (decision == "" || decision == "PROCEED_TO_RESTRICTED_CHECK") {
                decision = ""; 
                if(num_restricted_items > 0) {
                    if(dest_category == 3) {
                        decision = "REJECTED_RESTRICTED_DESTINATION";
                    } 
                    else if(dest_category == 2 && num_restricted_items > 2) {
                        decision = "REJECTED_EXCESS_RESTRICTED_ITEMS";
                    } 
                    else if(dest_category == 2) {
                        decision = "MANUAL_REVIEW_RESTRICTED_ITEMS";
                    }
                }

                if(decision == ""){
                    if(customs_flagged == 1) {
                        if(priority_level == 1) {
                            decision = "MANUAL_REVIEW_CUSTOMS_FLAGGED_PRIORITY";
                        } 
                        else {
                            decision = "REJECTED_CUSTOMS_FLAGGED";
                        }
                    } 
                    else{
                        decision = "STANDARD_CLEARANCE";
                    }
                }
            }
        }
    }

    cout << "Clearance Decision: " << decision << endl;

    return 0;
}