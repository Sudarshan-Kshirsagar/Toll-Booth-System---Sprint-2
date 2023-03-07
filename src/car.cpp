#include "../include/car.h"

// Initializing Static Data Member
    int Car :: carTollCharge          = 35;
    int Car :: carCount               = 0;
    int Car :: carRevenueCollection   = 0;
    
    int Car :: carTicketInCount           = 0;
    int Car :: carTicketOutCount          = 0;
    int Car :: carTicketReturnCount       = 0;
    
// Constructor
    Car :: Car() : Vehicle("Car"){}

    Car :: Car(std::string numberplate, std::string vehicletype, std::string tickettype, int tollcharges) 
                : Vehicle(numberplate, vehicletype, tickettype, tollcharges){
    }
    
    Car :: Car(std::string &numberplate, std::string &vehicletype, std::string &tickettype, std::string &dateString1, int &tollcharges)
                : Vehicle(numberplate, vehicletype, tickettype, dateString1, tollcharges){
    }

// Getters
    int Car :: getCarCount() const {
        return carCount;
    }
    int Car :: getCarTollCharge(int ticketType) const {
        updateCarRevenueCollection(ticketType);
        if(ticketType == 3)
            return (carTollCharge + carTollCharge - 10);
        else
            return carTollCharge;
    }
    int Car :: getCarRevenueCollection() const {
        return carRevenueCollection;
    }
    int Car :: getTicketInCount() const {
        return carTicketInCount;
    }
    int Car :: getTicketOutCount() const {
        return carTicketOutCount;
    }
    int Car :: getTicketReturnCount() const {
        return carTicketReturnCount;
    }
    
    int Car :: takeInputOfTicketType(std::string &tickettype) const {
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
                updateCarCount();
                return getCarTollCharge(val);
            }
        }
            
    }
    
// Data Member Updating Member Functions
    void Car :: updateCarCount() const {
        ++carCount;
        return;
    }
    void Car :: updateTicketInCount() const {
        ++carTicketInCount;
        return;
    }
    void Car :: updateTicketOutCount() const {
        ++carTicketOutCount;
        return;
    }
    void Car :: updateTicketReturnCount() const {
        ++carTicketReturnCount;
        return;
    }
    void Car :: updateCarRevenueCollection(int &ticketType) const {
        if(ticketType == 3)
            carRevenueCollection = carRevenueCollection + (carTollCharge + carTollCharge - 10);
        else
            carRevenueCollection = carRevenueCollection + carTollCharge;
        return;
    }
    
// Virtual Function Defination

    int Car :: addVehicleToDataFrame(std::string &numberplate)  const{
        
        std::string vehicletype = "Car";
        std::string  tickettype;
        
        std::cout<<"\t\tEnter Car Ticket Journey Type :"<<std::endl;
        std::cout<<"\t\t\t1. In"<<std::endl;
        std::cout<<"\t\t\t2. Out"<<std::endl;
        std::cout<<"\t\t\t3. Return"<<std::endl;
        int tollcharges = takeInputOfTicketType(tickettype);
        
        addDataInDataFrame(numberplate, vehicletype, tickettype, tollcharges);
        
        return 1;
    }
