#include "bike.h"
#include "car.h"
#include "bus.h"
#include "rickshaw.h"
#include "threeAxelPlus.h"

class TollBoothFactory
{
    private:
        Bike                        bikeClassObject;
        Car                         carClassObject;
        Bus                         busClassObject;
        Rickshaw                    rickshawClassObject;
        ThreeAxelPlus               threeAxelPlusClassObject;
    public:
        // Vehicle Sub-Class Instance
            static std::vector <Vehicle*> vehicleList;
        //  Mandatory Requirment Of Sprint Project
            // Complete
            int showRevenueCollection() const;                  // Total Bill Amount Collected
            // Complete
            void showAllData() const;                           // Display List Of All The Vehicles Travelled 
            // Complete
            void showEachTypeOfVehiclesTravelled() const;       // Count Each Type Of Vehicles Travelled
            // Complete
            int tollDataEntry();                                /* [ Read the type of Vehicle and Create an Instance accordingly ]
                                                                    + [ Log the vehicle details and the time in a Data Structure (STL) ] */
            // Complete
            int showSpecificVehicleDetail();
        // Member Function Used Inside Of Class
            int takeInputOfVehicleType() const;
            void updateVehicleList(std::string &numberPlate, std::string &vechileType, std::string &inOrOut, int &toll);
        // Array For Hourly Analysis
            int hourlyVehiclesPassed[24];
            int hourlyInVehicles[24];
            int hourlyOutVehicles[24];
            int hourlyReturnVehicles[24];
            int inRevenueCollectedHourly[24];
            int outRevenueCollectedHourly[24];
            int returnRevenueCollectedHourly[24];
            int hourlyRevenueCollectedHourly[24];
        // Functions Required For Analysis
            void showHourlyAnalysisOfDay();
            void takeInputOfDate(std::string &date);
            void updateHourlyData(std::string &tickettype, int &index, int &tollFare);
            void showHourlyOfDayAnalysis(Vehicle &obj, std::string &date);
        // Toll Employee Login Functions
            int takeValidInput() const;
            int login(TollSystemEmpoyees &admin, std::vector<TollSystemEmpoyees> &tollEmployee) const;
            int addEmployee(TollSystemEmpoyees &admin, std::vector<TollSystemEmpoyees> &tollEmployee) const;
            int removeEmployee(TollSystemEmpoyees &admin, std::vector<TollSystemEmpoyees> &tollEmployee) const;
        // Load Data From File
            void loadData();
            void saveDataIntoFile();
};

