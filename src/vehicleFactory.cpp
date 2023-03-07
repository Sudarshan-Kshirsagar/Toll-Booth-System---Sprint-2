#include "../include/vehicleFactory.h"


// static data member of Factory
std::vector <Vehicle*> TollBoothFactory ::  vehicleList;

// Friend Function
void showSpecificVehicleDetails(Vehicle &obj, std::string &numberplate, std::string &vehicleType) {
    int isFound = 0;
    for(const auto& row : obj.dataFrame)
    {
        if(row.numberPlate == numberplate && row.vehicleType == vehicleType)
        {    
            std::cout<<"\t\t";
            std::cout<<row.numberPlate<<" | "<<row.vehicleType<<" | "<<row.ticketType<<" | "<<row.dateTimeString<<" | "<<row.tollCharges<<" | "<<std::endl;
            ++isFound;
        }
    }
    if(isFound == 0)
    {    
        std::cout<<"\t\t[ No Data Found ]";
    }
    return;
}

// -----------------------------------------------------------------------------

int  TollBoothFactory :: showRevenueCollection() const {
    int totalCollection = 0;
    int revenue;
    std::cout<<"\t\tCollection From :"<<std::endl;
    
    revenue = ( (bikeClassObject.bikeTollCharge                     * bikeClassObject.getTicketInCount()) +
                (carClassObject.carTollCharge                       * carClassObject.getTicketInCount()) +
                (busClassObject.busTollCharge                       * busClassObject.getTicketInCount()) +
                (rickshawClassObject.rickshawTollCharge             * rickshawClassObject.getTicketInCount()) +
                (threeAxelPlusClassObject.threeAxelPlusTollCharge   * threeAxelPlusClassObject.getTicketInCount())
                );
    std::cout<<"\t\t\tIns : "<<revenue<<std::endl;
    totalCollection = totalCollection + revenue;
    
    revenue = ( (bikeClassObject.bikeTollCharge                     * bikeClassObject.getTicketOutCount()) + 
                (carClassObject.carTollCharge                       * carClassObject.getTicketOutCount()) + 
                (busClassObject.busTollCharge                       * busClassObject.getTicketOutCount()) + 
                (rickshawClassObject.rickshawTollCharge             * rickshawClassObject.getTicketOutCount()) + 
                (threeAxelPlusClassObject.threeAxelPlusTollCharge   * threeAxelPlusClassObject.getTicketOutCount())
              );
    std::cout<<"\t\t\tOuts : "<<revenue<<std::endl;
    totalCollection = totalCollection + revenue;
    
    revenue =( ((bikeClassObject.bikeTollCharge + bikeClassObject.bikeTollCharge - 5) * bikeClassObject.getTicketReturnCount())
              + ((carClassObject.carTollCharge + carClassObject.carTollCharge - 10) * carClassObject.getTicketReturnCount())
              + ((busClassObject.busTollCharge + busClassObject.busTollCharge - 20) * busClassObject.getTicketReturnCount())
              + ((rickshawClassObject.rickshawTollCharge + rickshawClassObject.rickshawTollCharge - 15) * rickshawClassObject.getTicketReturnCount())
              + ((threeAxelPlusClassObject.threeAxelPlusTollCharge + threeAxelPlusClassObject.threeAxelPlusTollCharge - 45) * threeAxelPlusClassObject.getTicketReturnCount())
            );
    totalCollection = totalCollection + revenue;
    std::cout<<"\t\t\tReturns : "<<revenue<<std::endl;
    std::cout<<"\t\tTotal Collection : "<<totalCollection<<std::endl;
    return 1;
}

void TollBoothFactory :: showAllData() const{
    bikeClassObject.showAllTollDataInTableStructure();
}

void TollBoothFactory :: showEachTypeOfVehiclesTravelled() const {
    std::cout<<"\t\tEach Type Of Vehicles Travelled"<<std::endl;
    
    std::cout<<"\t\tBike : "<<bikeClassObject.getBikeCount()<<std::endl;
    std::cout<<"\t\t\tBike In : "<<bikeClassObject.getTicketInCount()<<std::endl;
    std::cout<<"\t\t\tBike Out : "<<bikeClassObject.getTicketOutCount()<<std::endl;
    std::cout<<"\t\t\tBike Return : "<<bikeClassObject.getTicketReturnCount()<<std::endl;
    
    std::cout<<"\t\tRickshaw : "<<rickshawClassObject.getRickshawCount()<<std::endl;
    std::cout<<"\t\t\tRickshaw In : "<<rickshawClassObject.getTicketInCount()<<std::endl;
    std::cout<<"\t\t\tRickshaw Out : "<<rickshawClassObject.getTicketOutCount()<<std::endl;
    std::cout<<"\t\t\tRickshaw Return : "<<rickshawClassObject.getTicketReturnCount()<<std::endl;
    
    std::cout<<"\t\tCar : "<<carClassObject.getCarCount()<<std::endl;
    std::cout<<"\t\t\tCar In : "<<carClassObject.getTicketInCount()<<std::endl;
    std::cout<<"\t\t\tCar Out : "<<carClassObject.getTicketOutCount()<<std::endl;
    std::cout<<"\t\t\tCar Return : "<<carClassObject.getTicketReturnCount()<<std::endl;
    
    std::cout<<"\t\tBus : "<<busClassObject.getBusCount()<<std::endl;
    std::cout<<"\t\t\tBus In : "<<busClassObject.getTicketInCount()<<std::endl;
    std::cout<<"\t\t\tBus Out : "<<busClassObject.getTicketOutCount()<<std::endl;
    std::cout<<"\t\t\tBus Return : "<<busClassObject.getTicketReturnCount()<<std::endl;
    
    std::cout<<"\t\t3 Axel Plus : "<<threeAxelPlusClassObject.getThreeAxelPlusCount()<<std::endl;
    std::cout<<"\t\t\t3 Axel Plus In : "<<threeAxelPlusClassObject.getTicketInCount()<<std::endl;
    std::cout<<"\t\t\t3 Axel Plus Out : "<<threeAxelPlusClassObject.getTicketOutCount()<<std::endl;
    std::cout<<"\t\t\t3 Axel Plus Return : "<<threeAxelPlusClassObject.getTicketReturnCount()<<std::endl;
    return;
}

int  TollBoothFactory :: tollDataEntry() {
    std::string numberplate;
    std::cout<<"\t\tEnter Vehicle Type :"<<std::endl;
    std::cout<<"\t\t\t1. Bike"<<std::endl;
    std::cout<<"\t\t\t2. Bus/Truck"<<std::endl;
    std::cout<<"\t\t\t3. Car"<<std::endl;
    std::cout<<"\t\t\t4. Rickshaw"<<std::endl;
    std::cout<<"\t\t\t5. 3 Axel Plus :"<<std::endl;
    std::cout<<"\t\tEnter Choice :";
    int vehicleType = takeInputOfVehicleType();
    
    std::cout<<"\t\tEnter Vehicle Number Plate : ";
    std::getline(std::cin, numberplate);
    int isVehicleAlreadyPresent = bikeClassObject.isVehiclePresentInDataFreame(numberplate);
    switch(vehicleType)
    {
        case 1: {
                if(isVehicleAlreadyPresent)
                    bikeClassObject.addVehicleToDataFrame(numberplate);
                else
                    {
                        std::string tickettype;
                        std::cout<<"\t\tEnter Bike Ticket Journey Type :"<<std::endl;
                        std::cout<<"\t\t\t1. In"<<std::endl;
                        std::cout<<"\t\t\t2. Out"<<std::endl;
                        std::cout<<"\t\t\t3. Return\n\t\tEnter Choice : ";
                        int tollcharges = bikeClassObject.takeInputOfTicketType(tickettype);
                        Vehicle *ptr = (new Bike(numberplate, "Bike", tickettype, tollcharges));
                        vehicleList.push_back(ptr);
                        delete (ptr);
                    }
                break;
                }

        case 2: {
                if(isVehicleAlreadyPresent)
                    busClassObject.addVehicleToDataFrame(numberplate);
                else
                    {
                        std::string tickettype;
                        std::cout<<"\t\tEnter Bus Ticket Journey Type :"<<std::endl;
                        std::cout<<"\t\t\t1. In"<<std::endl;
                        std::cout<<"\t\t\t2. Out"<<std::endl;
                        std::cout<<"\t\t\t3. Return\n\t\tEnter Choice : ";
                        int tollcharges = busClassObject.takeInputOfTicketType(tickettype);
                        Vehicle *ptr = (new Bus(numberplate, "Bus", tickettype, tollcharges));
                        vehicleList.push_back(ptr);
                        delete (ptr);
                    }
                break;
                }

        case 3: {
                if(isVehicleAlreadyPresent)
                    carClassObject.addVehicleToDataFrame(numberplate);
                else
                    {
                        std::string tickettype;
                        std::cout<<"\t\tEnter Car Ticket Journey Type :"<<std::endl;
                        std::cout<<"\t\t\t1. In"<<std::endl;
                        std::cout<<"\t\t\t2. Out"<<std::endl;
                        std::cout<<"\t\t\t3. Return\n\t\tEnter Choice : ";
                        int tollcharges = carClassObject.takeInputOfTicketType(tickettype);
                        Vehicle *ptr = (new Car(numberplate, "Car", tickettype, tollcharges));
                        vehicleList.push_back(ptr);
                        delete (ptr);
                    }
                break;
                }

        case 4: {
                if(isVehicleAlreadyPresent)
                    rickshawClassObject.addVehicleToDataFrame(numberplate);
                else
                    {
                        std::string tickettype;
                        std::cout<<"\t\tEnter Rickshaw Ticket Journey Type :"<<std::endl;
                        std::cout<<"\t\t\t1. In"<<std::endl;
                        std::cout<<"\t\t\t2. Out"<<std::endl;
                        std::cout<<"\t\t\t3. Return\n\t\tEnter Choice : ";
                        int tollcharges = rickshawClassObject.takeInputOfTicketType(tickettype);
                        Vehicle *ptr = (new Rickshaw(numberplate, "Rickshaw", tickettype, tollcharges));
                        vehicleList.push_back(ptr);
                        delete (ptr);
                    }
                break;
                }

        case 5: {
                if(isVehicleAlreadyPresent)
                    threeAxelPlusClassObject.addVehicleToDataFrame(numberplate);
                else
                    {
                        std::string tickettype;
                        std::cout<<"\t\tEnter 3 Axel Vehicle Ticket Journey Type :"<<std::endl;
                        std::cout<<"\t\t\t1. In"<<std::endl;
                        std::cout<<"\t\t\t2. Out"<<std::endl;
                        std::cout<<"\t\t\t3. Return\n\t\tEnter Choice : ";
                        int tollcharges = threeAxelPlusClassObject.takeInputOfTicketType(tickettype);
                        Vehicle *ptr = (new ThreeAxelPlus(numberplate, "3 Axel Plus", tickettype, tollcharges));
                        vehicleList.push_back(ptr);
                        delete (ptr);
                    }
                break;
                }
    }
    return 0;
}

int  TollBoothFactory :: takeInputOfVehicleType() const {
    int val;
    while(true)
    {    
        std::cin>>val;
        std::cin.clear();
        std::cin.ignore(INT_MAX,'\n');
        if(val <= 0 || val > 5)
        {
            std::cout<<"\t\tInvalid Input\n\t\tRe-Enter Choice : ";
            continue;
        }
        break;
    }
    return val;
}

int TollBoothFactory :: showSpecificVehicleDetail() {
    
    std::cout<<"\t\tEnter Vehicle Type :"<<std::endl;
    std::cout<<"\t\t\t1. Bike"<<std::endl;
    std::cout<<"\t\t\t2. Bus/Truck"<<std::endl;
    std::cout<<"\t\t\t3. Car"<<std::endl;
    std::cout<<"\t\t\t4. Rickshaw"<<std::endl;
    std::cout<<"\t\t\t5. 3 Axel Plus :"<<std::endl;
    std::cout<<"\t\tEnter Choice :";
    int vehicleType = takeInputOfVehicleType();
    std::string numberplate;
    std::cout<<"\t\tEnter Vehicle Number Plate : ";
    std::getline(std::cin, numberplate);
    switch(vehicleType)
    {
        case 1: {
                std::string vehicletype = "Bike";
                showSpecificVehicleDetails(bikeClassObject, numberplate, vehicletype);
                break;
                }
                
        case 2: {
                std::string vehicletype = "Bus";
                showSpecificVehicleDetails(busClassObject, numberplate, vehicletype);
                break;
                }
        
        case 3: {
                std::string vehicletype = "Car";
                showSpecificVehicleDetails(carClassObject, numberplate, vehicletype);
                break;
                }
        
        case 4: {
                std::string vehicletype = "Rickshaw";
                showSpecificVehicleDetails(rickshawClassObject, numberplate, vehicletype);
                break;
                }
        
        case 5: {
                std::string vehicletype = "3 Axel Plus";
                showSpecificVehicleDetails(threeAxelPlusClassObject, numberplate, vehicletype);
                break;
                }
    }
    return 1;
}

// -----------------------------------------------------------------------------
void TollBoothFactory :: showHourlyAnalysisOfDay() {
    std::string date;
    std::cout<<"\t\tEnter Date : "<<std::endl;
    takeInputOfDate(date);
    std::cout<<"\t\tEntered Date = " << date<<std::endl;
    showHourlyOfDayAnalysis(bikeClassObject, date);
    std::cout<<"\t\t-----------------------------------"<<std::endl;
    std::cout<<"\t\tFrom 00:00 AM to 06:00 AM"<<std::endl;
    for(int i=0; i < 6; i++)
    {
        std::cout<<"\t\tHour : 0"<<i<<std::endl; 
        std::cout<<"\t\tTotal Revenue Collection : "<<hourlyRevenueCollectedHourly[i]<<std::endl; 
        std::cout<<"\t\t\tTotal Vehicle Passed : "<<hourlyVehiclesPassed[i]<<std::endl; 
        std::cout<<"\t\t\tTotal Vehicle Came In : "<<hourlyInVehicles[i]<<std::endl; 
        std::cout<<"\t\t\tTotal Vehicle Went Out : "<<hourlyOutVehicles[i]<<std::endl; 
        std::cout<<"\t\t\tVehicle Took Return Ticket : "<<hourlyReturnVehicles[i]<<std::endl; 
        std::cout<<"\t\t\tRevenue Collection From In Ticket Type : "<<inRevenueCollectedHourly[i]<<std::endl; 
        std::cout<<"\t\t\tRevenue Collection From In Ticket Type : "<<outRevenueCollectedHourly[i]<<std::endl; 
        std::cout<<"\t\t\tRevenue Collection From In Ticket Type : "<<returnRevenueCollectedHourly[i]<<std::endl; 
    }
    std::cout<<"\t\tFrom 06:00 AM to 11:59 AM"<<std::endl;
    for(int i=6; i < 12; i++)
    {
        if(i > 9)
            std::cout<<"\t\tHour : "<<i<<std::endl;
        else    
            std::cout<<"\t\tHour : 0"<<i<<std::endl; 
        std::cout<<"\t\tTotal Revenue Collection : "<<hourlyRevenueCollectedHourly[i]<<std::endl; 
        std::cout<<"\t\t\tTotal Vehicle Passed : "<<hourlyVehiclesPassed[i]<<std::endl; 
        std::cout<<"\t\t\tTotal Vehicle Came In : "<<hourlyInVehicles[i]<<std::endl; 
        std::cout<<"\t\t\tTotal Vehicle Went Out : "<<hourlyOutVehicles[i]<<std::endl; 
        std::cout<<"\t\t\tVehicle Took Return Ticket : "<<hourlyReturnVehicles[i]<<std::endl; 
        std::cout<<"\t\t\tRevenue Collection From In Ticket Type : "<<inRevenueCollectedHourly[i]<<std::endl; 
        std::cout<<"\t\t\tRevenue Collection From In Ticket Type : "<<outRevenueCollectedHourly[i]<<std::endl; 
        std::cout<<"\t\t\tRevenue Collection From In Ticket Type : "<<returnRevenueCollectedHourly[i]<<std::endl; 
    }
    std::cout<<"\t\tFrom 12:00 PM to 06:00 PM"<<std::endl;
    for(int i=12; i < 18; i++)
    {
        std::cout<<"\t\tHour : "<<i<<std::endl; 
        std::cout<<"\t\tTotal Revenue Collection : "<<hourlyRevenueCollectedHourly[i]<<std::endl; 
        std::cout<<"\t\t\tTotal Vehicle Passed : "<<hourlyVehiclesPassed[i]<<std::endl; 
        std::cout<<"\t\t\tTotal Vehicle Came In : "<<hourlyInVehicles[i]<<std::endl; 
        std::cout<<"\t\t\tTotal Vehicle Went Out : "<<hourlyOutVehicles[i]<<std::endl; 
        std::cout<<"\t\t\tVehicle Took Return Ticket : "<<hourlyReturnVehicles[i]<<std::endl; 
        std::cout<<"\t\t\tRevenue Collection From In Ticket Type : "<<inRevenueCollectedHourly[i]<<std::endl; 
        std::cout<<"\t\t\tRevenue Collection From In Ticket Type : "<<outRevenueCollectedHourly[i]<<std::endl; 
        std::cout<<"\t\t\tRevenue Collection From In Ticket Type : "<<returnRevenueCollectedHourly[i]<<std::endl; 
    }
    std::cout<<"\t\tFrom 06:00 PM to 11:59 PM"<<std::endl;
    for(int i=18; i < 24; i++)
    {
        std::cout<<"\t\tHour : "<<i<<std::endl; 
        std::cout<<"\t\tTotal Revenue Collection : "<<hourlyRevenueCollectedHourly[i]<<std::endl; 
        std::cout<<"\t\t\tTotal Vehicle Passed : "<<hourlyVehiclesPassed[i]<<std::endl; 
        std::cout<<"\t\t\tTotal Vehicle Came In : "<<hourlyInVehicles[i]<<std::endl; 
        std::cout<<"\t\t\tTotal Vehicle Went Out : "<<hourlyOutVehicles[i]<<std::endl; 
        std::cout<<"\t\t\tVehicle Took Return Ticket : "<<hourlyReturnVehicles[i]<<std::endl; 
        std::cout<<"\t\t\tRevenue Collection From In Ticket Type : "<<inRevenueCollectedHourly[i]<<std::endl; 
        std::cout<<"\t\t\tRevenue Collection From In Ticket Type : "<<outRevenueCollectedHourly[i]<<std::endl; 
        std::cout<<"\t\t\tRevenue Collection From In Ticket Type : "<<returnRevenueCollectedHourly[i]<<std::endl; 
    }
}

void TollBoothFactory :: takeInputOfDate(std::string &date) {
    std::string day, month, year;
    std::cout<<"\t\tEnter Day : ";
    while(true)
    {    
        std::cin>>day;
        if(day > "31" || day < "01")
        {
            std::cout<<"\t\tInvalid Input\n\t\tRe-Enter Day : ";
            continue;
        }
        break;
    }
    std::cout<<"\t\tEnter Month : ";
    while(true)
    {    
        std::cin>>month;
        if(month > "12" || month < "01")
        {
            std::cout<<"\t\tInvalid Input\n\t\tRe-Enter Month : ";
            continue;
        }
        break;
    }
    std::cout<<"\t\tEnter Year : ";
    while(true)
    {
        std::cin>>year;
        if(year < "2020" || year > "2024")
        {
            std::cout<<"\t\tInvalid Input\n\t\tRe-Enter Year : ";
            continue;
        }
        break;
    }
    date = day+'/'+month+'/'+year;
    std::cin.clear();
    std::cin.ignore(INT_MAX,'\n');
    return;
}

void TollBoothFactory :: updateHourlyData(std::string &tickettype, int &index, int &tollFare) {
    ++hourlyVehiclesPassed[index];
    ++hourlyRevenueCollectedHourly[index];
    if(tickettype == "In")
    {
        ++hourlyInVehicles[index];
        inRevenueCollectedHourly[index] = inRevenueCollectedHourly[index] + tollFare;
    }
    else if(tickettype == "Out")
    {
        ++hourlyOutVehicles[index];
        outRevenueCollectedHourly[index] = outRevenueCollectedHourly[index] + tollFare;
    }
    else
    {
        ++hourlyReturnVehicles[index];
        returnRevenueCollectedHourly[index] = returnRevenueCollectedHourly[index] + tollFare;
    }
    return;
}

void TollBoothFactory :: showHourlyOfDayAnalysis(Vehicle &obj, std::string &date) {
    for(int i=0; i < 24; i++) {    
        hourlyVehiclesPassed[i]             = 0;
        hourlyInVehicles[i]                 = 0;
        hourlyOutVehicles[i]                = 0;
        hourlyReturnVehicles[i]             = 0;
        inRevenueCollectedHourly[i]         = 0;
        outRevenueCollectedHourly[i]        = 0;
        returnRevenueCollectedHourly[i]     = 0;
        hourlyRevenueCollectedHourly[i]     = 0;
    }    
    for(const auto& row : obj.dataFrame)
    {
        // Checking Date
        if( row.dateTimeString[0] == date[0] && row.dateTimeString[1] == date[1] &&
            row.dateTimeString[3] == date[3] && row.dateTimeString[4] == date[4] &&
            row.dateTimeString[6] == date[6] && row.dateTimeString[7] == date[7] &&
            row.dateTimeString[8] == date[8] && row.dateTimeString[9] == date[9] )
        {
            std::string tickettype = row.ticketType;
            int  toll = row.tollCharges;
            if(row.dateTimeString[11] == '0')   // For 00-09 Hours
            {
                int twoDigit = ( int(row.dateTimeString[12]) - 48 );
                updateHourlyData(tickettype, twoDigit, toll);
            }
            else if(row.dateTimeString[11] == '1')   // For 10-19 Hours
            { 
                int twoDigit = ( int(row.dateTimeString[12]) - 48 ) + 10;
                updateHourlyData(tickettype, twoDigit, toll);
            }
            else if(row.dateTimeString[11] == '2')   // For 20-24 Hours
            { 
                int twoDigit = ( int(row.dateTimeString[12]) - 48 ) + 20;
                if(twoDigit > 24) // For any unexpected Input
                    std::cout<<"Error In if(twoDigit > 24) "<<std::endl;
                updateHourlyData(tickettype, twoDigit, toll);
            }
        }
    }
    return;
}

// -----------------------------------------------------------------------------

int TollBoothFactory :: takeValidInput() const {
    int val;
    while(true)
    {
        std::cin>>val;
        std::cin.clear();
        std::cin.ignore(INT_MAX,'\n');
        if(val < 1 || val > 3)
        {
            std::cout<<"\t\t|     [ Invalid Input ] Re-Enter : ";
            continue;
        }
        break;
    }
    return val;
}

int TollBoothFactory :: login(TollSystemEmpoyees &admin, std::vector<TollSystemEmpoyees> &tollEmployee) const {

    std::cout<<"\t\t|     --------------------------------------------------        |"<<std::endl;
    std::cout<<"\t\t|     1. Admin                                                  |"<<std::endl;
    std::cout<<"\t\t|     2. Employee                                               |"<<std::endl;
    std::cout<<"\t\t|     3. Exit                                                   |"<<std::endl;
    std::cout<<"\t\t|     --------------------------------------------------        |"<<std::endl;
    std::cout<<"\t\t|     Enter Option : ";
    int choice = takeValidInput();
    if(choice == 3)
        return 0;
    if(choice == 1) // Admin Login
    {
        while(true)
        {
            int id;
            std::string password;
            std::cout<<"\t\t|     Enter Id : ";
            std::cin >> id;
            std::cout<<"\t\t|     Enter Password : ";
            std::cin >> password;
            if(admin.id == id && password == admin.password)    // Credentials Matched
            {
                return 5;
            }
            std::cout<<"\t\t|     Invalid Credentials...                                    |"<<std::endl;
            std::cout<<"\t\t|     Enter"<<std::endl;
            std::cout<<"\t\t|     1. Retry"<<std::endl;
            std::cout<<"\t\t|     Any Other Key To Exit"<<std::endl;
            std::cout<<"\t\t|     Enter Option : ";
            std::cin>>id;
            if(id == 1)
                continue;
            std::cout<<"\t\t|     --------------------------------------------------        |"<<std::endl;
            std::cout<<"\t\t|     Operation Unsuccessful...                                 |"<<std::endl;
            std::cout<<"\t\t|     --------------------------------------------------        |"<<std::endl;
            break;
        }
    }
    else if(choice == 2) // Employee Login
    {
        while(true)
        {
            int id;
            std::string password;
            std::cout<<"\t\t|     Enter Id : ";
            std::cin >> id;
            std::cout<<"\t\t|     Enter Password : ";
            std::cin >> password;
            for(const auto& row : tollEmployee)
            {
                if(row.id == id && password == row.password)    // Credentials Matched
                {
                    return 4;
                }
            }    
            std::cout<<"\t\t|     Invalid Credentials...                                    |"<<std::endl;
            std::cout<<"\t\t|     Enter"<<std::endl;
            std::cout<<"\t\t|     1. Retry"<<std::endl;
            std::cout<<"\t\t|     Any Other Key To Exit"<<std::endl;
            std::cout<<"\t\t|     Enter Option : ";
            std::cin>>id;
            if(id == 1)
                continue;
                
            std::cout<<"\t\t|     --------------------------------------------------        |"<<std::endl;
            std::cout<<"\t\t|     Operation Unsuccessful...                                 |"<<std::endl;
            std::cout<<"\t\t|     --------------------------------------------------        |"<<std::endl;
            break;
        }
    }
    return 0;
}

int TollBoothFactory :: addEmployee(TollSystemEmpoyees &admin, std::vector<TollSystemEmpoyees> &tollEmployee) const {
    
    std::cout<<"\t\t|     --------------------------------------------------        |"<<std::endl;
    std::cout<<"\t\t|     [     Only Admin Can Add Or Remove Employees      ]       |"<<std::endl;
    while(true)
    {
        std::cout<<"\t\t|                                                               |"<<std::endl;
        int id;
        std::string password;
        std::cout<<"\t\t|     Enter Admin Id : ";
        std::cin >> id;
        std::cout<<"\t\t|     Enter Password : ";
        std::cin >> password;
        if(admin.id == id && password == admin.password)
        {
            break;
        }
        std::cout<<"\t\t|     Invalid Credentials...                                    |"<<std::endl;
        std::cout<<"\t\t|     Enter"<<std::endl;
        std::cout<<"\t\t|     1. Retry"<<std::endl;
        std::cout<<"\t\t|     Any Other Key To Exit"<<std::endl;
        std::cout<<"\t\t|     Enter Option : ";
        std::cin>>id;
        if(id == 1)
            continue;
       
        std::cout<<"\t\t|     --------------------------------------------------        |"<<std::endl;
        std::cout<<"\t\t|     Operation Unsuccessful...                                 |"<<std::endl;
        std::cout<<"\t\t|     --------------------------------------------------        |"<<std::endl;
        return 0;
    }
    
    std::cout<<"\t\t|                                                               |"<<std::endl;
    int id;
    std::string password;
    std::string empPosition = "Employee";
    std::cout<<"\t\t|     Enter Employee Id : ";
    std::cin >> id;
    std::cout<<"\t\t|     Enter Password : ";
    std::cin >> password;
    TollSystemEmpoyees temp = {id, password, empPosition};
    tollEmployee.push_back(temp);
    std::cout<<"\t\t|     --------------------------------------------------        |"<<std::endl;
    std::cout<<"\t\t|     Employee Added                                            |"<<std::endl;
    std::cout<<"\t\t|     --------------------------------------------------        |"<<std::endl;
    return 1;
}

int TollBoothFactory :: removeEmployee(TollSystemEmpoyees &admin, std::vector<TollSystemEmpoyees> &tollEmployee) const {
    std::cout<<"\t\t|     --------------------------------------------------        |"<<std::endl;
    std::cout<<"\t\t|     [     Only Admin Can Add Employee Or Remove       ]       |"<<std::endl;
    while(true)
    {
        std::cout<<"\t\t|                                                               |"<<std::endl;
        int id;
        std::string password;
        std::cout<<"\t\t|     Enter Admin Id : ";
        std::cin >> id;
        std::cout<<"\t\t|     Enter Password : ";
        std::cin >> password;
        if(admin.id == id && password == admin.password)
        {
            break;
        }
        std::cout<<"\t\t|     Invalid Credentials...                                    |"<<std::endl;
        std::cout<<"\t\t|     Enter"<<std::endl;
        std::cout<<"\t\t|     1. Retry"<<std::endl;
        std::cout<<"\t\t|     Any Other Key To Exit"<<std::endl;
        std::cout<<"\t\t|     Enter Option : ";
        std::cin>>id;
        if(id == 1)
            continue;
        return 0;
    }
    while(true)
    {
        int id;
        std::cout<<"\t\t|                                                               |"<<std::endl;
        std::cout<<"\t\t|     Enter Employee Id : ";
        std::cin >> id;
        for(auto it = tollEmployee.begin(); it !=  tollEmployee.end(); ++it)
        {
            if(it->id == id)
            {
                std::cout<<"\t\t|     --------------------------------------------------        |"<<std::endl;
                std::cout<<"\t\t|     Employee Removed Successlly........                       |"<<std::endl;
                std::cout<<"\t\t|     --------------------------------------------------        |"<<std::endl;
                tollEmployee.erase(it);
                return 1;
            }
        }
        std::cout<<"\t\t|     --------------------------------------------------        |"<<std::endl;
        std::cout<<"\t\t|     Entered Employee Id Not Found                             |"<<std::endl;
        std::cout<<"\t\t|     --------------------------------------------------        |"<<std::endl;
        break;
    }
    return 0;
}

// -----------------------------------------------------------------------------

void TollBoothFactory :: loadData() {
    std::fstream f;
    std::string line;
    std::cout<<"Loading Data..."<<std::endl;
    f.open("../data/data.txt", std::ios::in);
    while(getline(f, line))
    {
        std::string numberplate;
        std::string vehicletype;
        std::string tickettype;
        std::string datetime;
        int toll;
        std::stringstream check1(line);
        std::string token;
        int i=0;
        while(getline(check1, token, '|'))
        {
            if(i==0)
            {
                numberplate = token;
            }
            else if(i==1)
            {
                vehicletype = token;
            }
            else if(i==2)
            {
                tickettype = token;
            }
            else if(i==3)
            {
                datetime = token;
            }
            else if(i==4)
            {
                toll = stoi(token);
            }
            i++;
        }
        
        if(vehicletype == "Bike") {              
            Vehicle *ptr = (new Bike(numberplate, vehicletype, tickettype, datetime, toll));
            vehicleList.push_back(ptr);
            delete(ptr);
            // Update The Counter Variable Of Class 
            if(tickettype == "In")
                bikeClassObject.updateTicketInCount();
            else if(tickettype == "Out")
                bikeClassObject.updateTicketOutCount();
            else
                bikeClassObject.updateTicketReturnCount();
            bikeClassObject.updateBikeCount();
        }
        else if(vehicletype == "Car") {                       
            Vehicle *ptr = (new Car(numberplate, vehicletype, tickettype, datetime, toll));
            vehicleList.push_back(ptr);
            delete (ptr);
            // Update The Counter Variable Of Class 
            if(tickettype == "In")
                carClassObject.updateTicketInCount();
            else if(tickettype == "Out")
                carClassObject.updateTicketOutCount();
            else
                carClassObject.updateTicketReturnCount();
            carClassObject.updateCarCount();
        }
        else if(vehicletype == "Bus") {                       
            Vehicle *ptr = (new Bus(numberplate, vehicletype, tickettype, datetime, toll));
            vehicleList.push_back(ptr);
            delete (ptr);
            // Update The Counter Variable Of Class 
            if(tickettype == "In")
                busClassObject.updateTicketInCount();
            else if(tickettype == "Out")
                busClassObject.updateTicketOutCount();
            else
                busClassObject.updateTicketReturnCount();
            busClassObject.updateBusCount();
        }
        else if(vehicletype == "Rickshaw") {                       
            Vehicle *ptr = (new Rickshaw(numberplate, vehicletype, tickettype, datetime, toll));
            vehicleList.push_back(ptr);
            delete (ptr);
            // Update The Counter Variable Of Class 
            if(tickettype == "In")
                rickshawClassObject.updateTicketInCount();
            else if(tickettype == "Out")
                rickshawClassObject.updateTicketOutCount();
            else
                rickshawClassObject.updateTicketReturnCount();
            rickshawClassObject.updateRickshawCount();
        }
        else {           
            vehicletype = "3 Axel Plus";
            Vehicle *ptr = (new ThreeAxelPlus(numberplate, vehicletype, tickettype, datetime, toll));
            vehicleList.push_back(ptr);
            delete (ptr);
            // Update The Counter Variable Of Class 
            if(tickettype == "In")
                threeAxelPlusClassObject.updateTicketInCount();
            else if(tickettype == "Out")
                threeAxelPlusClassObject.updateTicketOutCount();
            else
                threeAxelPlusClassObject.updateTicketReturnCount();
            threeAxelPlusClassObject.updateThreeAxelPlusCount();
        }
    }
}

void TollBoothFactory :: saveDataIntoFile() {
    bikeClassObject.saveData();
}

