/* Filename: vehicles.cpp
 *
 * This piece of code holds the implementation of the vehicle's methods.
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

#ifndef VEHICLE_C_
#define VEHICLE_C_

/**
 * @brief Construct a new Vehicle:: Vehicle object
 *
 * @param n_wheels - The number of wheels
 * @param n_capacity - The capacity of the vehicle in people.
 */
Vehicle::Vehicle(int n_wheels, int n_capacity)
    : wheels(n_wheels), capacity(n_capacity) {}

// Getter methods
int Vehicle::getMilage() { return this->miles; }

string Vehicle::getModel() { return this->model; }

#endif