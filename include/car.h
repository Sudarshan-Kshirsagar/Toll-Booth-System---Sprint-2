#pragma once
#include "vehicle.h"

class Car : public Vehicle
{
    private:
        static int carCount;
        static int carRevenueCollection;
        
        static int carTicketInCount;
        static int carTicketOutCount;
        static int carTicketReturnCount;
        
    public:
            static int carTollCharge;
        // Constructor
            Car();
            Car(std::string numberplate, std::string vehicletype, 
                        std::string tickettype, int tollcharges);
            Car(std::string &numberplate, std::string &vehicletype, 
                std::string &tickettype, std::string &dateString1, int &tollcharges);
        // Destructor
            virtual ~Car(){}
        // Virtual Member Function From Base Abstract Class
            int addVehicleToDataFrame(std::string &numberplate)  const;
        // Getters
            int getCarCount()              const;
            int getCarTollCharge(int ticketType = 0)         const;
            int getCarRevenueCollection()  const;
            int getTicketInCount()          const;
            int getTicketOutCount()         const;
            int getTicketReturnCount()      const;
        // Data Member Updating Member Functions
            void updateAllCount()               const;
            void updateCarCount()               const;
            void updateTicketInCount()          const;
            void updateTicketOutCount()         const;
            void updateTicketReturnCount()      const;
            void updateCarRevenueCollection(int &ticketType)  const;
            int takeInputOfTicketType(std::string &tickettype) const;
};
