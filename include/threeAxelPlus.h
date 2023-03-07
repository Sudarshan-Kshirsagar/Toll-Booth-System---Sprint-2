#pragma once
#include "vehicle.h"

class ThreeAxelPlus : public Vehicle
{
    private:
        static int threeAxelPlusCount;
        static int threeAxelPlusRevenueCollection;
        static int threeAxelPlusTicketInCount;
        static int threeAxelPlusTicketOutCount;
        static int threeAxelPlusTicketReturnCount;
        
    public:
            static int threeAxelPlusTollCharge;
        // Constructor
            ThreeAxelPlus();
            ThreeAxelPlus(std::string numberplate, std::string vehicletype, 
                        std::string tickettype, int tollcharges);
            ThreeAxelPlus(std::string &numberplate, std::string &vehicletype, 
                std::string &tickettype, std::string &dateString1, int &tollcharges);
        // Destructor
            virtual ~ThreeAxelPlus(){}
        // Virtual Member Function From Base Abstract Class
            int addVehicleToDataFrame(std::string &numberplate)  const;
        // Getters
            int getThreeAxelPlusCount()              const;
            int getThreeAxelPlusTollCharge(int ticketType = 0)         const;
            int getThreeAxelPlusRevenueCollection()  const;
            int getTicketInCount()          const;
            int getTicketOutCount()         const;
            int getTicketReturnCount()      const;
        // Data Member Updating Member Functions
            void updateAllCount()               const;
            void updateThreeAxelPlusCount()     const;
            void updateTicketInCount()          const;
            void updateTicketOutCount()         const;
            void updateTicketReturnCount()      const;
            void updateThreeAxelPlusRevenueCollection(int &ticketType)  const;
            int takeInputOfTicketType(std::string &tickettype) const;
};
