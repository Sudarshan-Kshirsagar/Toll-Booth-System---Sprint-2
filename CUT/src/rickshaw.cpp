#include "../include/rickshaw.h"

// Initializing Static Data Member
    int Rickshaw :: rickshawTollCharge          = 20;
    int Rickshaw :: rickshawCount               = 0;
    int Rickshaw :: rickshawRevenueCollection   = 0;
    
    int Rickshaw :: rickshawTicketInCount           = 0;
    int Rickshaw :: rickshawTicketOutCount          = 0;
    int Rickshaw :: rickshawTicketReturnCount       = 0;
    
// Constructor
    Rickshaw :: Rickshaw() : Vehicle("Rickshaw"){}

    Rickshaw :: Rickshaw(std::string numberplate, std::string vehicletype, std::string tickettype, int tollcharges) 
                : Vehicle(numberplate, vehicletype, tickettype, tollcharges){
    }
    
    Rickshaw :: Rickshaw(std::string &numberplate, std::string &vehicletype, std::string &tickettype, std::string &dateString1, int &tollcharges)
                : Vehicle(numberplate, vehicletype, tickettype, dateString1, tollcharges){
    }

// Getters
    int Rickshaw :: getRickshawCount() const {
        return rickshawCount;
    }
    int Rickshaw :: getRickshawTollCharge(int ticketType) const {
        updateRickshawRevenueCollection(ticketType);
        if(ticketType == 3)
            return (rickshawTollCharge + rickshawTollCharge - 15);
        else
            return rickshawTollCharge;
    }
    int Rickshaw :: getRickshawRevenueCollection() const {
        return rickshawRevenueCollection;
    }
    int Rickshaw :: getTicketInCount() const {
        return rickshawTicketInCount;
    }
    int Rickshaw :: getTicketOutCount() const {
        return rickshawTicketOutCount;
    }
    int Rickshaw :: getTicketReturnCount() const {
        return rickshawTicketReturnCount;
    }
    
    int Rickshaw :: takeInputOfTicketType(std::string &tickettype) const {
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
                updateRickshawCount();
                return getRickshawTollCharge(val);
            }
        }
            
    }
    
// Data Member Updating Member Functions
    void Rickshaw :: updateRickshawCount() const {
        ++rickshawCount;
        return;
    }
    void Rickshaw :: updateTicketInCount() const {
        ++rickshawTicketInCount;
        return;
    }
    void Rickshaw :: updateTicketOutCount() const {
        ++rickshawTicketOutCount;
        return;
    }
    void Rickshaw :: updateTicketReturnCount() const {
        ++rickshawTicketReturnCount;
        return;
    }
    void Rickshaw :: updateRickshawRevenueCollection(int &ticketType) const {
        if(ticketType == 3)
            rickshawRevenueCollection = rickshawRevenueCollection + (rickshawTollCharge + rickshawTollCharge - 15);
        else
            rickshawRevenueCollection = rickshawRevenueCollection + rickshawTollCharge;
        return;
    }
    
// Virtual Function Defination

    int Rickshaw :: addVehicleToDataFrame(std::string &numberplate)  const{
        
        std::string vehicletype = "Rickshaw";
        std::string  tickettype;
        
        std::cout<<"\t\tEnter Rickshaw Ticket Journey Type :"<<std::endl;
        std::cout<<"\t\t\t1. In"<<std::endl;
        std::cout<<"\t\t\t2. Out"<<std::endl;
        std::cout<<"\t\t\t3. Return"<<std::endl;
        int tollcharges = takeInputOfTicketType(tickettype);
        
        addDataInDataFrame(numberplate, vehicletype, tickettype, tollcharges);
        
        return 1;
    }



