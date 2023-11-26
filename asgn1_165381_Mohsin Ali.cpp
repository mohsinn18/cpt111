//this program is designed to calculate the income earned by farmers
#include <iostream>
#include <iomanip>
using namespace std;
//class for info about the paddy price,subsidy price and cost for planting like
class PaddyInfo{
    private:
    
    double PaddyBasePrice;
    double SubsidyPrice;
    double PlantingCost;
    public:
    PaddyInfo(){PaddyBasePrice=SubsidyPrice=PlantingCost=0;}//default constructor
    PaddyInfo(double BasePaddyPrice, double PriceSubsidy, double CostPlanting){
        PaddyBasePrice=BasePaddyPrice;
        SubsidyPrice=PriceSubsidy;
        PlantingCost=CostPlanting;
    }
    // using getters
    double getPaddyPrice(){
        return PaddyBasePrice;
    }
    double getSubsidyPrice(){
        return SubsidyPrice;
    }
    double getPlantingCost(){
        return PlantingCost;
    }
    //friend function for input
    friend void inputPaddyInfo(PaddyInfo& baseinfo);
};



void inputPaddyInfo(PaddyInfo& baseInfo) {
    cout << "Enter base paddy price per metric ton (RM): ";
    while (!(cin >> baseInfo.PaddyBasePrice) || baseInfo.PaddyBasePrice < 0) {
        cout << "Invalid Input. Enter a positive number: ";
        cin.clear(); // Clear input stream    
    }

    cout << "Enter subsidy price per metric ton (RM): ";
    while (!(cin >> baseInfo.SubsidyPrice) || baseInfo.SubsidyPrice < 0) {
        cout << "Invalid Input. Enter a positive number: ";
        cin.clear(); // Clear input stream
    }

    cout << "Enter paddy planting cost per relong (RM): ";
    while (!(cin >> baseInfo.PlantingCost) || baseInfo.PlantingCost < 0) {
        cout << "Invalid Input. Enter a positive number: ";
        cin.clear(); // Clear input stream
    }
}



//class to get the info about the farmer
class Farmer{
    private:
    string farmerName;
    int id;
    double Fieldsize;
    public:
    Farmer(){farmerName=id=Fieldsize=0;}//default constructor

    Farmer( string name, int i, double size){
        farmerName=name;
        id=i;
        Fieldsize=size;
    }
    //using getters
    string getFarmerName(){
        return farmerName;
    }
    int getID(){
        return id;
    }
    double getFieldsize(){
        return Fieldsize;
    }
    //friend function for input
    friend void inputInfo(Farmer& farmer);
};
 
void inputInfo(Farmer& farmer) {
    cout << "Enter farmer's name: ";
    cin>>farmer.farmerName;
    
    cout << "Enter farmer's ID: ";
    while(!(cin>>farmer.id)|| farmer.id<0){
    cout<<"Invalid Input. Enter a positive number: ";
    cin.clear(); //clear input stream
    }


    cout << "Enter size of paddy field (relong): ";
    while (!(cin>>farmer.Fieldsize)|| farmer.Fieldsize<0){
    cout<<"Invalid Input. Enter a positive number: ";    
        cin.clear();//clear input stream
    }
    
   
}
//class to calculate the necessary things to get the right output
class PaddySale : public PaddyInfo {
private:
    Farmer farmer; 
    double PaddyWeight;
    double WeightDeduction;

public:
PaddySale(){PaddyWeight=WeightDeduction=0;}//default

    PaddySale(double weight, double deduction, double BasePaddyPrice, double PriceSubsidy, double CostPlanting)
        : PaddyInfo(BasePaddyPrice, PriceSubsidy, CostPlanting){
        PaddyWeight=weight;
        WeightDeduction=deduction;
        }

    //calculate net weight
    double calculateNetWeight(){
        return PaddyWeight - (PaddyWeight * (WeightDeduction / 100));
    }

    //calclate paddy price
    double calculateTotalPaddyPrice(){
        return calculateNetWeight() * getPaddyPrice();
    }

    //calculate subsidy 
    double calculateTotalSubsidy(){
        return calculateNetWeight() * getSubsidyPrice();
    }

    //calculate incentive cost
    double calculateIncentive(){
    double productivityRate = calculateNetWeight() / farmer.getFieldsize();

    if (productivityRate > 1.5) {
        return 200.0 * farmer.getFieldsize();  // Incentive is per relong, so multiply by the field size
    }

    return 0.0;
}

    //calculate planting cost
    double calculateTotalPlantingCost(){
        return farmer.getFieldsize() * getPlantingCost();
    }

    //calculate the total income earned by the farmer
    double calculateTotalNetIncome(){
        double totalIncome = calculateTotalPaddyPrice() + calculateTotalSubsidy() + calculateIncentive();
        double totalExpenses = calculateTotalPlantingCost();
        return totalIncome - totalExpenses;
    }

    // Friend function for input
    friend void inputInfo(PaddySale& paddySale);
    // Function to display Paddy Sale and Revenue information
    void displayPaddySaleInfo();
};

void inputInfo(PaddySale& paddySale) {
    
    inputInfo(paddySale.farmer);  // Input farmer information

    cout << "Enter paddy weight (metric tons): ";
    while(!(cin>>paddySale.PaddyWeight)||paddySale.PaddyWeight<0){
    cout<<"Invalid Input. Enter a positive number: ";
    cin.clear(); //clear input stream
    }

    cout << "Enter weight deduction (%): ";
    while(!(cin>>paddySale.WeightDeduction)||paddySale.WeightDeduction<0||paddySale.WeightDeduction>10){
    cout <<"Invalid Input. Enter a positive number: ";
    cin.clear(); //clear input stream
    }
}

// display paddy sale and the revenue information
void PaddySale::displayPaddySaleInfo(){
    cout << "\n-------------- Paddy Sale and Revenue Information ---------------\n";
    cout << "Farmer's Name: " << farmer.getFarmerName() << endl;
    cout << "Farmer's ID: " << farmer.getID() << endl;
    cout << "Size of Paddy Field (relong): " << farmer.getFieldsize() << endl;
    cout << "Paddy Weight: " << PaddyWeight << " metric tons" << endl;
    cout << "Weight Deduction: " << WeightDeduction << "%" << endl;

    double netWeight = calculateNetWeight();
    cout << "Paddy Net Weight: " << netWeight << " metric tons" << endl;

    cout << fixed << setprecision(2);
    cout << "Total Paddy Price: RM" << calculateTotalPaddyPrice() << endl;
    cout << "Total Subsidy: RM" << calculateTotalSubsidy() << endl;
    cout << "Incentive: RM" << calculateIncentive() << endl;
    cout << "Total Planting Cost: RM" << calculateTotalPlantingCost() << endl;

    double netIncome = calculateTotalNetIncome();
    cout << "Total Net Income: RM" << netIncome << endl;

    // Display productivity rate category
    double productivityRate = netWeight / farmer.getFieldsize();
    if (productivityRate > 1.5) {
        cout << "Productivity Rate Category: High\n";
    } else if (productivityRate >= 1.0) {
        cout << "Productivity Rate Category: Moderate\n";
    } else {
        cout << "Productivity Rate Category: Low\n";
    }

    cout << "-------------------------------------------------------------------------\n";
}
int main() {
    const int MAX_FARMERS = 30;  // Maximum number of farmers
   PaddySale paddySales[MAX_FARMERS];
 

    char choice;
    do {
        // Display menu
        cout << "\n-------------- MyPaddy Apps Menu --------------\n";
        cout << "1. Input Paddy Base Information\n";
        cout << "2. Input Paddy Sale Information\n";
        cout << "3. Display Paddy Sale and Revenue\n";
        cout << "4. Exit\n";
        cout << "Enter your choice (1-4): ";
        cin >> choice;
       
        
    
        switch (choice) {
            case '1':
                // Input Paddy Base Information
                inputPaddyInfo(paddySales[0]);  // Assume we are working with the first farmer
                break;
               
                
            case '2':
                // Input Paddy Sale Information
                inputInfo(paddySales[0]);  // Assume we are working with the first farmer
                break;
                
                
            case '3':
                // Display Paddy Sale and Revenue Information
                paddySales[0].displayPaddySaleInfo();  // Assume we are working with the first farmer
                break;

            case '4':
                // Exit the program
                cout << "Exiting MyPaddy Apps. Goodbye!\n";
                break;
            default:
                cout << "Invalid choice. Please enter a number between 1 and 4.\n";
        }
    } while (choice != '4');

    return 0;
}