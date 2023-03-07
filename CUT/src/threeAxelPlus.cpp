#include "../include/threeAxelPlus.h"

// Initializing Static Data Member
    int ThreeAxelPlus :: threeAxelPlusTollCharge          = 100;
    int ThreeAxelPlus :: threeAxelPlusCount               = 0;
    int ThreeAxelPlus :: threeAxelPlusRevenueCollection   = 0;
    
    int ThreeAxelPlus :: threeAxelPlusTicketInCount           = 0;
    int ThreeAxelPlus :: threeAxelPlusTicketOutCount          = 0;
    int ThreeAxelPlus :: threeAxelPlusTicketReturnCount       = 0;
    
// Constructor
    ThreeAxelPlus :: ThreeAxelPlus() : Vehicle("3 Axel Plus"){}

    ThreeAxelPlus :: ThreeAxelPlus(std::string numberplate, std::string vehicletype, std::string tickettype, int tollcharges) 
                : Vehicle(numberplate, vehicletype, tickettype, tollcharges){
    }
    
    ThreeAxelPlus :: ThreeAxelPlus(std::string &numberplate, std::string &vehicletype, std::string &tickettype, std::string &dateString1, int &tollcharges)
                : Vehicle(numberplate, vehicletype, tickettype, dateString1, tollcharges){
    }
    
// Getters
    int ThreeAxelPlus :: getThreeAxelPlusCount() const {
        return threeAxelPlusCount;
    }
    int ThreeAxelPlus :: getThreeAxelPlusTollCharge(int ticketType) const {
        updateThreeAxelPlusRevenueCollection(ticketType);
        if(ticketType == 3)
            return (threeAxelPlusTollCharge + threeAxelPlusTollCharge - 45);
        else
            return threeAxelPlusTollCharge;
    }
    int ThreeAxelPlus :: getThreeAxelPlusRevenueCollection() const {
        return threeAxelPlusRevenueCollection;
    }
    int ThreeAxelPlus :: getTicketInCount() const {
        return threeAxelPlusTicketInCount;
    }
    int ThreeAxelPlus :: getTicketOutCount() const {
        return threeAxelPlusTicketOutCount;
    }
    int ThreeAxelPlus :: getTicketReturnCount() const {
        return threeAxelPlusTicketReturnCount;
    }
    
    int ThreeAxelPlus :: takeInputOfTicketType(std::string &tickettype) const {
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
                updateThreeAxelPlusCount();
                return getThreeAxelPlusTollCharge(val);
            }
        }
            
    }
    
// Data Member Updating Member Functions
    void ThreeAxelPlus :: updateThreeAxelPlusCount() const {
        ++threeAxelPlusCount;
        return;
    }
    void ThreeAxelPlus :: updateTicketInCount() const {
        ++threeAxelPlusTicketInCount;
        return;
    }
    void ThreeAxelPlus :: updateTicketOutCount() const {
        ++threeAxelPlusTicketOutCount;
        return;
    }
    void ThreeAxelPlus :: updateTicketReturnCount() const {
        ++threeAxelPlusTicketReturnCount;
        return;
    }
    void ThreeAxelPlus :: updateThreeAxelPlusRevenueCollection(int &ticketType) const {
        if(ticketType == 3)
            threeAxelPlusRevenueCollection = threeAxelPlusRevenueCollection + (threeAxelPlusTollCharge + threeAxelPlusTollCharge - 45);
        else
            threeAxelPlusRevenueCollection = threeAxelPlusRevenueCollection + threeAxelPlusTollCharge;
        return;
    }
    
// Virtual Function Defination

    int ThreeAxelPlus :: addVehicleToDataFrame(std::string &numberplate)  const{        
        std::string vehicletype = "3 Axel Plus";
        std::string  tickettype;
        
        std::cout<<"\t\tEnter 3 Axel Vehicle Ticket Journey Type :"<<std::endl;
        std::cout<<"\t\t\t1. In"<<std::endl;
        std::cout<<"\t\t\t2. Out"<<std::endl;
        std::cout<<"\t\t\t3. Return"<<std::endl;
        int tollcharges = takeInputOfTicketType(tickettype);
        
        addDataInDataFrame(numberplate, vehicletype, tickettype, tollcharges);
        
        return 1;
    }

