#pragma once
#include "vehicle.h"

class Bike : public Vehicle
{
    private:
        static int bikeCount;
        static int bikeRevenueCollection;
        static int bikeTicketInCount;
        static int bikeTicketOutCount;
        static int bikeTicketReturnCount;
    public:
            static int bikeTollCharge;
        // Constructor
            Bike();
            Bike(std::string numberplate, std::string vehicletype, 
                        std::string tickettype, int tollcharges);
            Bike(std::string &numberplate, std::string &vehicletype, 
                std::string &tickettype, std::string &dateString1, int &tollcharges);
        // Destructor
            virtual ~Bike(){}
        // Virtual Member Function From Base Abstract Class
            int addVehicleToDataFrame(std::string &numberplate)  const;
        // Getters
            int getBikeCount()              const;
            int getBikeTollCharge(int ticketType = 0)         const;
            int getBikeRevenueCollection()  const;
            int getTicketInCount()          const;
            int getTicketOutCount()         const;
            int getTicketReturnCount()      const;
        // Data Member Updating Member Functions
            void updateBikeCount()              const;
            void updateTicketInCount()          const;
            void updateTicketOutCount()         const;
            void updateTicketReturnCount()      const;
            void updateBikeRevenueCollection(int &ticketType)  const;
            int takeInputOfTicketType(std::string &tickettype) const;
};
