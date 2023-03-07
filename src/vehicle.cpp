#include "../include/vehicle.h"

// Initializing Static Data Member

int Vehicle :: totalRevenueCollection = 0;
std::vector<rowData> Vehicle :: dataFrame;

// Constructor

Vehicle :: Vehicle(std::string className) {
    std::cout<<"Vehicle Class Inheritade By "<<className<<" Class"<<std::endl;
}    // Complete

Vehicle :: Vehicle(std::string &numberplate, std::string &vehicletype, std::string &tickettype, int &tollcharges) {
    // Extracting Current Time
    time_t currTime;
    time(&currTime);
    tm* currTm = localtime(&currTime);
    char dateString1[60]; 
    strftime(dateString1, 50, "%d/%m/%Y %H:%M:%S", currTm);
    rowData temporaryRow = {numberplate, vehicletype, tickettype, dateString1, tollcharges};
    dataFrame.push_back(temporaryRow);
    totalRevenueCollection = totalRevenueCollection + tollcharges;
}           // Complete

Vehicle :: Vehicle(std::string &numberplate, std::string &vehicletype, std::string &tickettype, std::string &dateString1, int &tollcharges) {
    rowData temporaryRow = {numberplate, vehicletype, tickettype, dateString1, tollcharges};
    dataFrame.push_back(temporaryRow);
    totalRevenueCollection = totalRevenueCollection + tollcharges;
}           // Complete

// Getter

int Vehicle :: getTotalRevenueCollection() const {
    return totalRevenueCollection;
}  // Complete

// Data Member Update Functions

void Vehicle :: updateTotalRevenueCollection(int& charge) const {
    totalRevenueCollection = totalRevenueCollection + charge;
    return;
}   // Complete

void Vehicle :: addDataInDataFrame(std::string &numberplate, std::string &vehicletype, std::string &tickettype, int &tollcharges) const {
    char dateString1[60]; 
    time_t currTime;
    time(&currTime);
    tm* currTm = localtime(&currTime);
    strftime(dateString1, 50, "%d/%m/%Y %H:%M:%S", currTm);
    rowData temporaryRow = {numberplate, vehicletype, tickettype, dateString1, tollcharges};
    dataFrame.push_back(temporaryRow);
    return;
}   // Complete

int  Vehicle :: isVehiclePresentInDataFreame(std::string &numberplate) const {
    for(const auto& row : dataFrame)
    {
        if(row.numberPlate == numberplate)  // If Vehicle Present
        {    
            std::cout<<"Found"<<std::endl;
            return 1;
        }
    }
    return 0;  // If Vehicle Not Present
}

void Vehicle :: showAllTollDataInTableStructure() const {
    // Adding "const" and "&" is important for efficiency as it avoids unnecessary copying
    for(const auto& row : dataFrame)
    {
        std::cout<<"\t\t\t";
        std::cout<<row.numberPlate<<" | "<<row.vehicleType<<" | "<<row.ticketType<<" | "<<row.dateTimeString<<" | "<<row.tollCharges<<" | "<<std::endl;
    }
    return;
}

void Vehicle :: saveData() {
    
    std::fstream fp;
    fp.open("../data/data.txt", std::ios::out);
    for(const auto& row : dataFrame)
    {
        fp<<row.numberPlate<<"|"<<row.vehicleType<<"|"<<row.ticketType<<"|"<<row.dateTimeString<<"|"<<row.tollCharges<<"|"<<std::endl;
    }
    fp.close();
    return;
}

