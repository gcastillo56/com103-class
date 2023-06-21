/* Filename: vehicles.h
 *
 * This piece of code holds the declaration of the vehicles parent class
 * as well as the car and bike object. Observe how we introduce the
 * protected accessor and how now the private avoids children classes to access
 * such values.
 * Observe how the use of preprocessor directives encloses some pieces of code,
 * the reason behind it is because of the compilation process; without those
 * safeguards, some re-definition issues wouldn't allow us to compile properly.
 *
 * @author: gcastill
 * August 2023
 */

#include <string>

using namespace std;

#ifndef MAX_FUEL
#define MAX_FUEL 100
#endif

#ifndef MAX_BIKE_S
#define MAX_BIKE_S 35
#endif

#ifndef VEHICLE_H_
#define VEHICLE_H_
/**
 * @brief This is the parent object and will represent a vehicle
 *
 */
class Vehicle
{
public:
    // As a default constructor we need to get the number of wheels
    // and its capacity
    Vehicle(int, int);

    int getMilage();
    string getModel();
    virtual string report();
    virtual void advance();

protected:
    string brand; // The brand of the vehicle
    string model; // The model of the vehicle
    int year;     // The year of the vehicle
    int miles;    // The miles it have gone.
    bool stopped; // A flag to signal if it is stopped or moving

private:
    int wheels;   // The number of wheels.
    int capacity; // The capacity of passengers.
};

/**
 * @brief This class represents a car that is a type of vehicle.
 *
 */
class Car : public Vehicle
{
public:
    // The constructor will require the year, brand, model, mpl and capacity
    Car(int, string, string, int, int);
    void fillTank();
    int getFuel();
    // Overriden methods
    void advance();
    string report();

private:
    int fuel_level; // The current amount of fuel in the tank
    int mpl;        // The miles per liter of fuel.
};

/**
 * @brief A class that will represent a bike that is a vehicle.
 *
 */
class Bike : public Vehicle
{
public:
    // The constructor will require the year, brand and model
    Bike(int, string, string);
    // Overriden methods
    void advance();
    string report();

private:
    int speed;
};
#endif