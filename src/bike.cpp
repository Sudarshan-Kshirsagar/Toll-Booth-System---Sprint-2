#include "../include/bike.h"

// Initializing Static Data Member
    int Bike :: bikeTollCharge          = 10;
    int Bike :: bikeCount               = 0;
    int Bike :: bikeRevenueCollection   = 0;
    int Bike :: bikeTicketInCount           = 0;
    int Bike :: bikeTicketOutCount          = 0;
    int Bike :: bikeTicketReturnCount       = 0;
    
// Constructor
    Bike :: Bike() : Vehicle("Bike"){}

    Bike :: Bike(std::string numberplate, std::string vehicletype, std::string tickettype, int tollcharges) 
                : Vehicle(numberplate, vehicletype, tickettype, tollcharges){
    }
    
    Bike :: Bike(std::string &numberplate, std::string &vehicletype, std::string &tickettype, std::string &dateString1, int &tollcharges)
                : Vehicle(numberplate, vehicletype, tickettype, dateString1, tollcharges){
    }
// Getters  Vehicle(std::string &numberplate, std::string &vehicletype, std::string &tickettype, std::string &dateString1, int &tollcharges)
    int Bike :: getBikeCount() const {
        return bikeCount;
    }
    int Bike :: getBikeTollCharge(int ticketType) const {
        updateBikeRevenueCollection(ticketType);
        if(ticketType == 3)
            return (bikeTollCharge + bikeTollCharge - 5);
        else
            return bikeTollCharge;
    }
    int Bike :: getBikeRevenueCollection() const {
        return bikeRevenueCollection;
    }
    int Bike :: getTicketInCount() const {
        return bikeTicketInCount;
    }
    int Bike :: getTicketOutCount() const {
        return bikeTicketOutCount;
    }
    int Bike :: getTicketReturnCount() const {
        return bikeTicketReturnCount;
    }
    
    int Bike :: takeInputOfTicketType(std::string &tickettype) const {
        int val;
        while(true)
        {    
            std::cin>>val;
            std::cin.clear();
            std::cin.ignore(INT_MAX,'\n');
            if(val <= 0 || val > 3)
            {
                std::cout<<"\t\tInvalid Input\n\t\tRe-Enter Choice : ";
                continue;
            }
            else
            {
                if(val == 1)
                {    
                    tickettype = "In";
                    updateTicketInCount();
                }
                else if(val == 2)
                {    
                    tickettype = "Out";
                    updateTicketOutCount();
                }
                else
                {    
                    tickettype = "Return";
                    updateTicketReturnCount();
                }
                updateBikeCount();
                return getBikeTollCharge(val);
            }
        }
            
    }
    
// Data Member Updating Member Functions
    void Bike :: updateBikeCount() const {
        ++bikeCount;
        return;
    }
    void Bike :: updateTicketInCount() const {
        ++bikeTicketInCount;
        return;
    }
    void Bike :: updateTicketOutCount() const {
        ++bikeTicketOutCount;
        return;
    }
    void Bike :: updateTicketReturnCount() const {
        ++bikeTicketReturnCount;
        return;
    }
    void Bike :: updateBikeRevenueCollection(int &ticketType) const {
        if(ticketType == 3)
            bikeRevenueCollection = bikeRevenueCollection + (bikeTollCharge + bikeTollCharge - 5);
        else
            bikeRevenueCollection = bikeRevenueCollection + bikeTollCharge;
        return;
    }
    
// Virtual Function Defination

    int Bike :: addVehicleToDataFrame(std::string &numberplate)  const{
        std::string vehicletype = "Bike";
        std::string  tickettype;
        
        std::cout<<"\t\tEnter Bike Ticket Journey Type :"<<std::endl;
        std::cout<<"\t\t\t1. In"<<std::endl;
        std::cout<<"\t\t\t2. Out"<<std::endl;
        std::cout<<"\t\t\t3. Return"<<std::endl;
        int tollcharges = takeInputOfTicketType(tickettype);
        
        addDataInDataFrame(numberplate, vehicletype, tickettype, tollcharges);
        
        return 1;
    }

