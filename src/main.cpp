#include "../include/allHeaderFiles.h"
#include "../include/vehicleFactory.h"

int main()
{
    TollSystemEmpoyees admin = {9128, "admin@108", "Admin"};

    std::vector<TollSystemEmpoyees> tollEmployee = {{1001, "defaultEmp@108", "Employee"}};
    
    TollBoothFactory factoryObject;
    
    std::thread dataLoadingThread(&TollBoothFactory::loadData, &factoryObject);

    dataLoadingThread.join();   // We Are Joining Here Because We Dont Want to Do Any Operation If We Are Still Loading The Data
    while(true)
    {   
        std::cout<<"\t\t_________________________________________________________________"<<std::endl;
        std::cout<<"\t\t|                                                               |"<<std::endl;
        std::string welcome = "\t\t|        Welcome To Maharashtra - Gujarat Toll System           |\n";
            
        for (const auto c : welcome) {
            std::cout << c << std::flush;
            std::this_thread::sleep_for(std::chrono::milliseconds(150));
        }
        std::cout<<"\t\t|     --------------------------------------------------        |"<<std::endl;
        std::cout<<"\t\t|     1. Login                                                  |"<<std::endl;
        std::cout<<"\t\t|     2. Add Or Remove Employee                                 |"<<std::endl;
        std::cout<<"\t\t|     3. Exit                                                   |"<<std::endl;
        std::cout<<"\t\t|     --------------------------------------------------        |"<<std::endl;
        std::cout<<"\t\t|     Enter Option : ";
        int option = factoryObject.takeValidInput();
        if(option == 1)
            option = factoryObject.login(admin, tollEmployee);
        else if (option == 2)
        {   
                    
            std::cout<<"\t\t|     --------------------------------------------------        |"<<std::endl;
            std::cout<<"\t\t|     1. Add Employee                                           |"<<std::endl;
            std::cout<<"\t\t|     2. Remove Employee                                        |"<<std::endl;
            std::cout<<"\t\t|     3. Go Back                                                |"<<std::endl;
            std::cout<<"\t\t|     --------------------------------------------------        |"<<std::endl;
            std::cout<<"\t\t|     Enter Option : ";
            option = factoryObject.takeValidInput();
            if(option == 1)
                option =  factoryObject.addEmployee(admin, tollEmployee);
            else if(option == 2)
                option =  factoryObject.removeEmployee(admin, tollEmployee);
            else
                continue;
        }
        if(option == 3)
        {   
            std::cout<<"\t\t|     --------------------------------------------------        |"<<std::endl;
            std::cout<<"\t\t|     Exiting...                                                |"<<std::endl;
            std::cout<<"\t\t|     --------------------------------------------------        |"<<std::endl;
            break;
        }
        if(option == 5) // For Admin
        {
            while(true)
            {
                int choice;
                std::cout<<"\t\t_________________________________________________________________"<<std::endl;
                std::cout<<"\t\t|                                                               |"<<std::endl;
                std::cout<<"\t\t|        Login : Admin                                          |"<<std::endl;
                std::cout<<"\t\t|     --------------------------------------------------        |"<<std::endl;
                std::cout<<"\t\t|     Enter 1 To Add Data Of Vehicle                            |"<<std::endl;
                std::cout<<"\t\t|     Enter 2 To See Total Revenue Collection                   |"<<std::endl;
                std::cout<<"\t\t|     Enter 3 To Show All Data                                  |"<<std::endl;
                std::cout<<"\t\t|     Enter 4 To Show Each Type Of Vehicle Travelled Data       |"<<std::endl;
                std::cout<<"\t\t|     Enter 5 To Show Specific Vehicle Detail                   |"<<std::endl;
                std::cout<<"\t\t|     Enter 6 To Show Hourly Analysis Of The Day                |"<<std::endl;
                std::cout<<"\t\t|     Enter 0 To Exit                                           |"<<std::endl;
                std::cout<<"\t\t|     Enter Option : ";
                std::cin>>choice;
                if(choice == 0)
                    break;
                else if(choice == 1)
                    factoryObject.tollDataEntry();
                else if(choice == 2)
                    factoryObject.showRevenueCollection();  // * Total Bill Amount Collected 
                else if(choice == 3)
                    factoryObject.showAllData();        // * Display list of all the vehicles travelled.
                else if(choice == 4)
                    factoryObject.showEachTypeOfVehiclesTravelled();    // * Count of each type of vehicle
                else if(choice == 5)
                    factoryObject.showSpecificVehicleDetail();
                else if(choice == 6)
                    factoryObject.showHourlyAnalysisOfDay();    // * Hourly analysis / Daily Analyis of Collection
                    
                std::cout<<"\t\t|                                                               |"<<std::endl;
                std::cout<<"\t\t|_______________________________________________________________|"<<std::endl;
            }
            std::thread saveDataThread(&TollBoothFactory::saveDataIntoFile, &factoryObject);
            saveDataThread.join();
        }   
        if(option == 4) // For Employee
        {
            while(true)
            {
                int choice;
                std::cout<<"\t\t_________________________________________________________________"<<std::endl;
                std::cout<<"\t\t|                                                               |"<<std::endl;
                std::cout<<"\t\t|        Login : Employee                                       |"<<std::endl;
                std::cout<<"\t\t|     --------------------------------------------------        |"<<std::endl;
                std::cout<<"\t\t|     Enter 1 To Add Data Of Vehicle                            |"<<std::endl;
                std::cout<<"\t\t|     Enter 2 To Show Each Type Of Vehicle Travelled Data       |"<<std::endl;
                std::cout<<"\t\t|     Enter 3 To Show Hourly Analysis Of The Day                |"<<std::endl;
                std::cout<<"\t\t|     Enter 0 To Exit                                           |"<<std::endl;
                std::cout<<"\t\t|     Enter Option : ";
                std::cin>>choice;
                if(choice == 0)
                    break;
                else if(choice == 1)
                    factoryObject.tollDataEntry();
                else if(choice == 2)
                    factoryObject.showEachTypeOfVehiclesTravelled();    // * Count of each type of vehicle
                else if(choice == 3)
                    factoryObject.showHourlyAnalysisOfDay();    // * Hourly analysis / Daily Analyis of Collection
                    
                std::cout<<"\t\t|                                                               |"<<std::endl;
                std::cout<<"\t\t|_______________________________________________________________|"<<std::endl;
            }
            std::thread saveDataThread(&TollBoothFactory::saveDataIntoFile, &factoryObject);
            saveDataThread.join();
        }   
    }
    return 0;
}

