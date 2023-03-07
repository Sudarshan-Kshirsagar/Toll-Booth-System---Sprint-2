#include "../include/bus.h"

// Initializing Static Data Member
    int Bus :: busTollCharge          = 65;
    int Bus :: busCount               = 0;
    int Bus :: busRevenueCollection   = 0;
    
    int Bus :: busTicketInCount           = 0;
    int Bus :: busTicketOutCount          = 0;
    int Bus :: busTicketReturnCount       = 0;
    
// Constructor
    Bus :: Bus() : Vehicle("Bus"){}

    Bus :: Bus(std::string numberplate, std::string vehicletype, std::string tickettype, int tollcharges) 
                : Vehicle(numberplate, vehicletype, tickettype, tollcharges){
    }
    
    Bus :: Bus(std::string &numberplate, std::string &vehicletype, std::string &tickettype, std::string &dateString1, int &tollcharges)
                : Vehicle(numberplate, vehicletype, tickettype, dateString1, tollcharges){
    }

// Getters
    int Bus :: getBusCount() const {
        return busCount;
    }
    int Bus :: getBusTollCharge(int ticketType) const {
        updateBusRevenueCollection(ticketType);
        if(ticketType == 3)
            return (busTollCharge + busTollCharge - 20);
        else
            return busTollCharge;
    }
    int Bus :: getBusRevenueCollection() const {
        return busRevenueCollection;
    }
    int Bus :: getTicketInCount() const {
        return busTicketInCount;
    }
    int Bus :: getTicketOutCount() const {
        return busTicketOutCount;
    }
    int Bus :: getTicketReturnCount() const {
        return busTicketReturnCount;
    }
    
    int Bus :: takeInputOfTicketType(std::string &tickettype) const {
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
                updateBusCount();
                return getBusTollCharge(val);
            }
        }
            
    }
    
// Data Member Updating Member Functions
    void Bus :: updateBusCount() const {
        ++busCount;
        return;
    }
    void Bus :: updateTicketInCount() const {
        ++busTicketInCount;
        return;
    }
    void Bus :: updateTicketOutCount() const {
        ++busTicketOutCount;
        return;
    }
    void Bus :: updateTicketReturnCount() const {
        ++busTicketReturnCount;
        return;
    }
    void Bus :: updateBusRevenueCollection(int &ticketType) const {
        if(ticketType == 3)
            busRevenueCollection = busRevenueCollection + (busTollCharge + busTollCharge - 20);
        else
            busRevenueCollection = busRevenueCollection + busTollCharge;
        return;
    }
    
// Virtual Function Defination

    int Bus :: addVehicleToDataFrame(std::string &numberplate)  const{
        
        std::string vehicletype = "Bus";
        std::string  tickettype;
        
        std::cout<<"\t\tEnter Bus Ticket Journey Type :"<<std::endl;
        std::cout<<"\t\t\t1. In"<<std::endl;
        std::cout<<"\t\t\t2. Out"<<std::endl;
        std::cout<<"\t\t\t3. Return"<<std::endl;
        int tollcharges = takeInputOfTicketType(tickettype);
        
        addDataInDataFrame(numberplate, vehicletype, tickettype, tollcharges);
        
        return 1;
    }



