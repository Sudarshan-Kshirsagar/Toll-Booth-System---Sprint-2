#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <climits>
#include <cstdlib>
#include <fstream>
#include <time.h>
#include <sstream>
#include <iomanip>
#include <thread>

#include <stdio.h>
#include <unistd.h>
// The "rowData" structure will hold Data of Each Row of Table
struct rowData
{
    std::string numberPlate;    // "MH01 1234"
    std::string vehicleType;    // "Car"
    std::string ticketType;     // "In/Out/Return"
    std::string dateTimeString; // "27/02/23 12:45:00"
    int tollCharges;            // "45"
};

// Vector Of Structure                  (e.g std::vector <rowData> dataFrame;)
//------------------------------------------------------------------------------
// Number Plate | Vehicle Type | Ticket Type    | Date      Time    | Charges
// MH15 1234    | Car          | In             | 27/02/23 12:45:00 | 45
// MH15 1244    | Bike         | Out            | 27/02/23 12:45:00 | 05
// MH15 1233    | Car          | Return         | 27/02/23 12:45:00 | 75


struct TollSystemEmpoyees
{
    int id;
    std::string password;
    std::string employeePosition;
};

