#pragma once
#include "vehicle.h"

class Rickshaw : public Vehicle
{
    private:
        static int rickshawCount;
        static int rickshawRevenueCollection;
        static int rickshawTicketInCount;
        static int rickshawTicketOutCount;
        static int rickshawTicketReturnCount;
        
    public:
            static int rickshawTollCharge;
        // Constructor
            Rickshaw();
            Rickshaw(std::string numberplate, std::string vehicletype, 
                        std::string tickettype, int tollcharges);
            Rickshaw(std::string &numberplate, std::string &vehicletype, 
                std::string &tickettype, std::string &dateString1, int &tollcharges);
        // Destructor
            virtual ~Rickshaw(){}
        // Virtual Member Function From Base Abstract Class
            int addVehicleToDataFrame(std::string &numberplate)  const;
        // Getters
            int getRickshawCount()              const;
            int getRickshawTollCharge(int ticketType = 0)         const;
            int getRickshawRevenueCollection()  const;
            int getTicketInCount()          const;
            int getTicketOutCount()         const;
            int getTicketReturnCount()      const;
        // Data Member Updating Member Functions
            void updateAllCount()               const;
            void updateRickshawCount()          const;
            void updateTicketInCount()          const;
            void updateTicketOutCount()         const;
            void updateTicketReturnCount()      const;
            void updateRickshawRevenueCollection(int &ticketType)  const;
            int takeInputOfTicketType(std::string &tickettype) const;
};
