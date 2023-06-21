/* Filename: vehicles.h
 *
 * This piece of code holds the declaration of the vehicles parent class
 * as well as the car and bike object.
 * In this exercise we want to highlight the use of abstract classes, thus
 * observe the declaration of the report and advance methods in the parent
 * class. With this declaration, we force the developer to implement such
 * classes, instead of providing a basic implementation they can relay on.
 *
 * Notice how we have to declare the implemented function in the class declaration
 * so the compiler knows this class is no longer an abstract class.
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
    // Declare them as pure virtual
    virtual string report() = 0;
    virtual void advance() = 0;

protected:
    string brand; // The brand of the vehicle
    string model; // The model of the vehicle
    int year;     // The year of the vehicle
    int miles;    // The miles it have gone.
    bool stopped; // A flag to signal if it is stopped or moving
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
    string report();
    void advance();

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
    string report();
    void advance();

private:
    int speed;
};
#endif