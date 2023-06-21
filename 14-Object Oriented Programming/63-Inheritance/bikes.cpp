/* Filename: bikes.cpp
 *
 * This piece of code holds the implementation of the bike's methods.
 * Observe how the use of preprocessor directives encloses some pieces of code,
 * the reason behind it is because of the compilation process; without those
 * safeguards, some re-definition issues wouldn't allow us to compile properly.
 *
 * @author: gcastill
 * August 2023
 */
#include <iostream>
using namespace std;

#include "vehicles.h"

#ifndef BIKE_C_
#define BIKE_C_

/**
 * @brief Construct a new Car:: Car object, notice how we also have to call the
 * parent constructor in order to save the basic info of the car, thus, we can
 * not use the technique of auto-assignment for the shared and own properties,
 * therefore we have to do it explicitly.
 *
 * @param n_year - The year of the car
 * @param n_brand - The brand of the car
 * @param n_model - The model of the car
 * @param n_cap - The capacity of the car
 */
Bike::Bike(int n_year, string n_brand, string n_model) : Vehicle(2, 1)
{
    this->year = n_year;
    this->brand = n_brand;
    this->model = n_model;
    this->miles = 0;
    this->speed = 0;
    this->stopped = false;
}

/**
 * @brief Method that simulates some movement of the vehicle.
 * @Override
 */
void Bike::advance()
{
    if (this->stopped)
    {
        // If it is stopped, we will give it a 25% chance of starting
        if (rand() % 20 < 5)
        {
            this->stopped = false;
            this->speed = 1;
            cout << "Let's start rolling!\n";
        }
    }
    else
    {
        // If it is rolling, we will give it a 10% chance of stopping
        if (rand() % 20 < 2)
        {
            this->stopped = true;
            this->speed = 0;
            cout << "Let's take a rest!\n";
        }
        else
        {
            if (this->speed < MAX_BIKE_S)
            {
                this->speed++;
            }
        }
    }
    this->miles += this->speed;
}

/**
 * @brief Reports on the basics of the bike.
 *
 * @return string - A string showing the data of the Car.
 */
string Bike::report()
{
    return this->brand + " " + this->model + "(" + to_string(this->year) + ")" +
           "\nCurrent milage: " + to_string(this->miles) +
           "\n" + Vehicle::report() +
           "\n============\n";
}
#endif
