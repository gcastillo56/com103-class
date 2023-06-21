/* Filename: encapsulation.cpp
 *
 * This program showcases the use of encapsulation as part of the objects.
 * Observe that after making the attributes private, we can no longer access
 * the attributes of the object from the main method, thus we have to create
 * setter method to access them.
 *
 * @author: gcastill
 * August 2023
 */
#include <iostream>
#include <string>

#include <stdio.h>
#include <time.h>
#include <unistd.h>

using namespace std;

#define MAX_FUEL 100

class Car
{
public:
    Car();

    void fillTank();
    void advance();
    int getFuel();
    int getMilage();
    string getModel();
    void setMpl(int);
    void setYear(int);
    void setModel(string);
    void setBrand(string);

    void reportCar();

private:
    string brand;
    string model;
    int year;
    int fuel_level;
    int mpl;
    double miles;
    bool stopped;
};

int main()
{
    srand((unsigned)time(NULL));

    Car myCar;
    myCar.setYear(1965);
    myCar.setBrand("Ford");
    myCar.setModel("Mustang");
    myCar.setMpl(15);

    Car carObj1;
    carObj1.setYear(1999);
    carObj1.setBrand("BMW");
    carObj1.setModel("X5");
    carObj1.setMpl(22);

    myCar.fillTank();
    carObj1.fillTank();

    myCar.reportCar();
    carObj1.reportCar();

    int time_to_run = rand() % 100;
    cout << "The test will run for " << time_to_run << " uot. \n";
    // cout << myCar.model << " vs. " << carObj1.model << endl;
    cout << myCar.getModel() << " vs. " << carObj1.getModel() << endl;
    for (int i = 0; i < time_to_run; i++)
    {
        cout << i + 1 << " Running ..."
             //<< myCar.miles << " vs. " << carObj1.miles << endl;
             << myCar.getMilage() << " vs. " << carObj1.getMilage() << endl;
        myCar.advance();
        carObj1.advance();
        sleep(1);
    }

    // Print attribute values
    myCar.reportCar();
    carObj1.reportCar();
    return 0;
}

Car::Car()
{
    this->fuel_level = 0;
    this->miles = 0;
    this->mpl = 0;
    this->stopped = false;
}

void Car::fillTank()
{
    cout << this->brand << " " << this->model << ": Getting gas.\n";
    this->fuel_level = rand() % MAX_FUEL;
    if (this->fuel_level > 0)
        this->stopped = false;
}

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

int Car::getFuel()
{
    return this->fuel_level;
}

int Car::getMilage()
{
    return this->miles;
}

string Car::getModel()
{
    return this->model;
}

void Car::setMpl(int n_mpl)
{
    this->mpl = n_mpl;
}

void Car::setYear(int n_year)
{
    this->year = n_year;
}

void Car::setModel(string n_model)
{
    this->model = n_model;
}

void Car::setBrand(string n_brand)
{
    this->brand = n_brand;
}

void Car::reportCar()
{
    cout << this->brand << " " << this->model << "(" << this->year << ")"
         << "\nCurrent milage: " << this->miles
         << "\nTank level: " << this->fuel_level << "\n============\n";
}
