#pragma once
#include "allHeaderFiles.h"

// Abstract Class
class Vehicle
{   
    private:
        static int totalRevenueCollection;
    public:
        static std::vector<rowData> dataFrame;
        // Constructor
            Vehicle() = default;
            Vehicle(std::string className);                             // Complete

            Vehicle(std::string &numberplate, std::string &vehicletype, 
                            std::string &tickettype, int &tollcharges); // Complete
            Vehicle(std::string &numberplate, std::string &vehicletype, 
                    std::string &tickettype, std::string &dateString1, int &tollcharges);
        // Destructor
            virtual ~Vehicle(){}
        // Friend Function
            friend void showSpecificVehicleDetails(Vehicle &obj, std::string &numberplate, 
                            std::string &vehicleType);                  // Complete
                            
            friend void showHourlyOfDayAnalysis(Vehicle &obj, std::string &date);                  
        // Getter
            int getTotalRevenueCollection() const;                      // Complete
        // Data Member Update Functions
            void updateTotalRevenueCollection(int& charge) const;       // Complete
            void addDataInDataFrame(std::string &numberplate, 
                    std::string &vehicletype, std::string &tickettype, 
                    int &tollcharges) const;                         // Complete
            void showAllTollDataInTableStructure() const;               // Complete
            int  isVehiclePresentInDataFreame(std::string &numberplate) const;
        // Pure Virtual Function
            virtual int addVehicleToDataFrame(std::string &numberplate) const = 0;
        // Save Data Function
            void saveData();
};  // End Of Class Vehicle


