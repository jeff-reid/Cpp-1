#include <iostream>
#include <fstream>
#include <iomanip>  //Fixed Manipulator

using namespace std;

double calcPaycheck(double gross, double bonus, double taxes){

    double paycheck, tempGross, temp;
    bonus *= 0.01;
    taxes *= 0.01;

    bonus *= gross;
    tempGross = gross + bonus;

    temp = tempGross * taxes;
    paycheck = tempGross - temp;

    return paycheck;

}

double calcAvgSpeed(double distance, double time){
    return distance / time;
}

double totalCoffeeSales(int cupsSold, double perCup){
    return cupsSold * perCup;
}

int main() {

    ifstream inFile("inData.txt");
    ofstream outFile("outData.txt");

    string firstName, lastName, department;
    double grossSalary, monthlyBonus, taxes, paycheck, distTraveled,
            travelTime, avgSpeed, costPerCup, salesAmount;
    int cupsSold;

    //Collect data from inData and initialize the variables
    inFile >> firstName >> lastName >> department;
    inFile >> grossSalary >> monthlyBonus >> taxes;
    inFile >> distTraveled >> travelTime;
    inFile >> cupsSold >> costPerCup;

    //write to outData
    outFile << "Name: " << firstName << " " << lastName
            << ", Department: " << department << endl;

    //using <iomanip> to display doubles properly
    outFile << fixed << showpoint;
    outFile << setprecision(2);
    outFile << "Monthly Gross Salary: $" << grossSalary;
    outFile << ", Monthly Bonus: " << monthlyBonus << "%";
    outFile << ", Taxes: " << taxes << "%" << '\n';
    outFile << "Paycheck: $" << calcPaycheck(grossSalary,monthlyBonus,taxes) << endl;

    outFile << '\n';
    outFile << "Distance Traveled: " << distTraveled << " miles, ";
    outFile << "Traveling Time: " << travelTime << " hours" << '\n';
    outFile << "Average speed: " << calcAvgSpeed(distTraveled,travelTime) << " mph" << '\n';

    outFile << "Number of Coffee Cups Sold: " << cupsSold;
    outFile << ", Cost: " << costPerCup << '\n';
    outFile << "Sales Amount = $" << totalCoffeeSales(cupsSold,costPerCup);

    inFile.close();
    outFile.close();

}