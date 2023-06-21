/* Filename: cars.cpp
 *
 * This piece of code holds the implementation of the car's methods.
 *
 * @author: gcastill
 * August 2023
 */
#include <iostream>
using namespace std;

#include "vehicles.h"

#ifndef CAR_C_
#define CAR_C_

/**
 * @brief Construct a new Car:: Car object, notice how we also have to call the
 * parent constructor in order to save the basic info of the car, thus, we can
 * not use the technique of auto-assignment for the shared and own properties,
 * therefore we have to do it explicitly.
 *
 * @param n_year - The year of the car
 * @param n_brand - The brand of the car
 * @param n_model - The model of the car
 * @param n_mpl - The miles per liter
 * @param n_cap - The capacity of the car
 */
Car::Car(int n_year, string n_brand, string n_model, int n_mpl, int n_cap)
    : Vehicle(4, n_cap)
{
    this->year = n_year;
    this->brand = n_brand;
    this->model = n_model;
    this->mpl = n_mpl;
    this->fuel_level = 0;
    this->miles = 0;
    this->stopped = false;
}

int Car::getFuel() { return this->fuel_level; }

/**
 * @brief A method that will randomly add fuel when the tank is empty,
 * randomly assigning a quantity from 0 to MAX_FUEL
 *
 */
void Car::fillTank()
{
    cout << this->brand << " " << this->model << ": Getting gas.\n";
    this->fuel_level = rand() % MAX_FUEL;
    if (this->fuel_level > 0)
        this->stopped = false;
}

/**
 * @brief Method that simulates some movement of the vehicle.
 * @Override
 */
void Car::advance()
{
    // If it is stopped, we will give it a 25% chance of
    // getting some extra gas every time.
    if (this->stopped)
    {
        if (rand() % 20 < 5)
            this->fillTank();
        return;
    }
    if (this->fuel_level > 0)
    {
        this->fuel_level--;
        this->miles += this->mpl;
    }
    else
    {
        this->stopped = true;
        cout << this->brand << " " << this->model << ": Run out of fuel!\n";
    }
}

/**
 * @brief Reports on the basics of the car.
 *
 * @return string - A string showing the data of the Car.
 */
string Car::report()
{
    return this->brand + " " + this->model + "(" + to_string(this->year) + ")" +
           "\nCurrent milage: " + to_string(this->miles) +
           "\nTank level: " + to_string(this->fuel_level) + "\nThis is a " +
           to_string(this->wheels) +
           "-wheel(s) vehicle with a max. capacity of " +
           to_string(this->capacity) + "\n============\n";
}
#endif
