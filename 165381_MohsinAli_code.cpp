/* this program is designed to calculate the profit earned by an investor. It also shows the predicted time to reach
the target profit */ 
#include <iostream>
#include <iomanip>
using namespace std;
int main()
{
    // variables used
    double total_investment, target_profit, profit_earned_per_year, profit_tax, net_profit, 
    base_profit, service_charge, penalty_charge, total_profit, profit_after_penalty_charge;
    int investor_age, investment_period, target_profit_time;
    target_profit = profit_earned_per_year = net_profit = service_charge = penalty_charge = total_profit = 0;
    char section;


    // input and their conditions 
    cout << "Enter the investment amount(MYR): ";
    cin >> total_investment;
    if (total_investment < 5000 || total_investment > 200000){
        cout << "Please enter amount between MYR 5000 to MYR 200000" ;
        return 0;
    }
    cout << "Enter your age: ";
    cin >> investor_age;
    if (investor_age < 18 || investor_age > 65){
        cout << "You are not eligible";
    return 0;
    }
    cout << "Enter the time you want to invest for(in years): ";
    cin >> investment_period;
    if (investment_period < 5 || investment_period > 25){
        cout << "Investment period should be between 5 to 25 years" ;
    return 0;
    }


    // using switch case 


    cout << "..........................MAIN MENU.........................."<<endl << "Choose from the following"<<endl;
    cout << "1. Profit Earned"<<endl << "2. Target Profit."<<endl << "3. Withdraw the money within 5 years" << endl << "4. Exit" << endl;
    cin >> section;
    switch(section)
    {

    // calculating profit earned
    
    case '1': cout << setprecision(2) << fixed;
    cout << "Enter the base profit(%): ";
        cin >> base_profit;
        base_profit = base_profit/100;

    // for investment less than 50000

        if (total_investment < 50000){
        for (int i = 0; i < investment_period; i++){
            profit_earned_per_year = total_investment * base_profit;
            total_investment += profit_earned_per_year;
            total_profit += profit_earned_per_year;
            cout << "Profit earned after " << i + 1 << " year: " << profit_earned_per_year << endl;
            base_profit += 0.0015;
        }
        
        cout<< "Total Profit earned = " << total_profit << endl;
        }

        // for investment greater than 50000 and less than 100000

        else if (total_investment > 50000 && total_investment < 100000){
            for (int i = 0; i < investment_period; i++){
                profit_earned_per_year = total_investment * base_profit;
                total_investment += profit_earned_per_year;
                total_profit += profit_earned_per_year;
                cout << "Profit earned after " << i+1 << " year: "  << profit_earned_per_year << endl;
                base_profit += 0.0025;
        }
        
        
              
        cout << "Total Profit = " << total_profit << endl;
        }
        // for investment greater than 100000

       else 
        {
            for (int i = 0; i <investment_period && i <10; i++){
                profit_earned_per_year = total_investment * base_profit;
                total_investment += profit_earned_per_year;
                total_profit += profit_earned_per_year;
                cout << "Profit earned after "<< i + 1 << " year: " << profit_earned_per_year << endl;
                base_profit += 0.0035;
            }
        

            for (int i=10; i <investment_period; i++){
                profit_earned_per_year = total_investment * base_profit;
                total_investment += profit_earned_per_year;
                total_profit += profit_earned_per_year;
                cout << "Profit earned after " << i + 1<< " year: "  << profit_earned_per_year << endl;
                base_profit += 0.0055;
            }
                
            
        
                
            cout << "Total Profit: " << total_profit << endl;
        }
        //calculating the service charge

         service_charge = total_profit * 0.025;
        cout << "Service Charge = " << service_charge << endl;
        cout << "Profit after Service Charge = " << total_profit - service_charge << endl;
        // calculating profit tax 

        if (total_profit < 70000){
            profit_tax = 0.03 * (total_profit - service_charge);
            cout << "Profit tax: " << profit_tax << endl;
        }
        else if (total_profit > 70000 && total_profit < 150000){
            profit_tax = 0.05 * (total_profit - service_charge);
            cout << "Profit tax: " << profit_tax << endl;
        }
        else{
            profit_tax = 0.07 * (total_profit - service_charge);
            cout << "Profit tax: " << profit_tax << endl;
        }
        // calculating net profit
        net_profit = total_profit - service_charge - profit_tax;
        cout << "Net profit: " << net_profit;
    
        
        
    


break;


        // calculating the time taken to reach the target profit

    case '2':
            cout << "Enter the target profit amount: ";
            cin >> target_profit;
            cout << "Enter base profit(%): ";
            cin >> base_profit;
            base_profit = base_profit/100;
            
            while (total_profit<=target_profit){
            if (total_investment < 50000){
            
            profit_earned_per_year = total_investment * base_profit;
            total_investment += profit_earned_per_year;
            total_profit += profit_earned_per_year;
            
            base_profit += 0.0015;
            
            target_profit_time++;
            
            
       
            }

        // for investment greater than 50000 and less than 100000
       
        else if (total_investment > 50000 && total_investment < 100000){
                
                profit_earned_per_year = total_investment * base_profit;
                total_investment += profit_earned_per_year;
                total_profit += profit_earned_per_year;
                
                base_profit += 0.0025;
        
        
        target_profit_time++;
        
        
        }
        // for investment greater than 100000

       else 
        {
               
                profit_earned_per_year = total_investment * base_profit;
                total_investment += profit_earned_per_year;
                total_profit += profit_earned_per_year;
                
                base_profit += 0.0035;
                  target_profit_time++;
                 
            
        
 } 
        
           target_profit_time++;       
            }
            
        cout << "Time taken to reach the target profit: " << target_profit_time/2;
        
            break;
        // calculating penalty charge

    case '3' : cout << setprecision(2) << fixed;
                cout << "Enter the new investment period: ";
                cin >> investment_period;
                
                 if (investment_period <= 5){ 
                    cout << "You will face a penalty charge of 7%\n";
                cout << "Enter base profit: ";
                cin >> base_profit;
                cout << endl;
                base_profit = base_profit/100;    
                        {
                        if (total_investment < 50000){
                            
                        for (int i = 0; i < investment_period; i++){
                            profit_earned_per_year = total_investment * base_profit;
                            total_investment += profit_earned_per_year;
                            total_profit += profit_earned_per_year;
                            cout << i + 1 << " " << " Profit per year = " << profit_earned_per_year << endl;
                            base_profit += 0.0015;

            } 
        
        penalty_charge = total_profit * 0.07;
        profit_after_penalty_charge = total_profit - penalty_charge;
        cout << "Total Profit after Penalty = " << profit_after_penalty_charge << endl;
        
        
                        }
                else if (total_investment>50000 && total_investment<100000){
                 for (int i = 0; i < investment_period; i++){
                profit_earned_per_year = total_investment * base_profit;
                total_investment += profit_earned_per_year;
                total_profit += profit_earned_per_year;
                cout << i + 1 << " " << "Profit earned: " << profit_earned_per_year << endl;
                base_profit += 0.0025;
        }   
                
                penalty_charge = total_profit * 0.07;
                profit_after_penalty_charge = total_profit - penalty_charge;
                cout << "Total Profit = " << profit_after_penalty_charge;
                }
                else if (total_investment < 200000)
                {
                    for (int i = 0; i <investment_period; i++){
                        profit_earned_per_year = total_investment * base_profit;
                        total_investment += profit_earned_per_year;
                        total_profit += profit_earned_per_year;
                        cout << i+1<< " " << "Profit Earned: " << profit_earned_per_year << endl;
                        base_profit += 0.0035;
            }
            penalty_charge = total_profit * 0.07;
            profit_after_penalty_charge = total_profit - penalty_charge;
            cout << "Total Profit: " << total_profit;
            cout << endl;
        }
        else
            cout << "Enter a valid input" << endl;
        }
            }
    
            

     if (investment_period > 5){
        cout << "Please choose the correct option\n";
     }
     //calculating the service charge

         service_charge = total_profit * 0.025;
        cout << "Service Charge = " << service_charge << endl;
        cout << "Profit after Service Charge = " << profit_after_penalty_charge - service_charge << endl;
        // calculating profit tax 

        if (total_profit < 70000){
            profit_tax = 0.03 * (profit_after_penalty_charge - service_charge);
            cout << "Profit tax: " << profit_tax << endl;
        }
        else if (total_profit > 70000 && total_profit < 150000){
            profit_tax = 0.05 * (profit_after_penalty_charge - service_charge);
            cout << "Profit tax: " << profit_tax << endl;
        }
        else{
            profit_tax = 0.07 * (profit_after_penalty_charge - service_charge);
            cout << "Profit tax: " << profit_tax << endl;
        }
        // calculating net profit
        net_profit = profit_after_penalty_charge - service_charge - profit_tax;
        cout << "Net profit: " << net_profit;
        cout << endl;
        break;

    case '4': cout  << "Thank you for using our app." << endl;
        break;
    default: cout << "Invalid input" << endl;
    }

    cout << endl << "------------------------------------------------------------";
    cout << endl;
    return 0;
    
 // end   
}

