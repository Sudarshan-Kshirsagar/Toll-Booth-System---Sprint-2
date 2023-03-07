#pragma once
#include "vehicle.h"

class Bus : public Vehicle
{
    private:
        static int busCount;
        static int busRevenueCollection;
        static int busTicketInCount;
        static int busTicketOutCount;
        static int busTicketReturnCount;
        
    public:
            static int busTollCharge;
        // Constructor
            Bus();
            Bus(std::string numberplate, std::string vehicletype, 
                        std::string tickettype, int tollcharges);
            Bus(std::string &numberplate, std::string &vehicletype, 
                std::string &tickettype, std::string &dateString1, int &tollcharges);
        // Destructor
            virtual ~Bus(){}
        // Virtual Member Function From Base Abstract Class
            int addVehicleToDataFrame(std::string &numberplate)  const;
        // Getters
            int getBusCount()              const;
            int getBusTollCharge(int ticketType = 0)         const;
            int getBusRevenueCollection()  const;
            int getTicketInCount()          const;
            int getTicketOutCount()         const;
            int getTicketReturnCount()      const;
        // Data Member Updating Member Functions
            void updateAllCount()               const;
            void updateBusCount()               const;
            void updateTicketInCount()          const;
            void updateTicketOutCount()         const;
            void updateTicketReturnCount()      const;
            void updateBusRevenueCollection(int &ticketType)  const;
            int takeInputOfTicketType(std::string &tickettype) const;
};
