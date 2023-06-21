/* Filename: constructor.cpp
 *
 * This program showcases the use of constructors as part of the objects.
 * Observe that some attributes of the object are never modified again
 * after initial creation, thus, we can pass them at creation time and avoid
 * creating setter methods for some of the attributes. Also observe how can
 * we set default values.
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
    Car(int, string, string, int);
    void fillTank();
    void advance();
    int getFuel();
    int getMilage();
    string getModel();

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

    Car myCar(1965, "Ford", "Mustang", 15);
    Car carObj1(1999, "BMW", "X5", 22);

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
    this->stopped = false;
}

Car::Car(int n_year, string n_brand, string n_model, int n_mpl) : year(n_year), brand(n_brand), model(n_model), mpl(n_mpl), fuel_level(0), miles(0.0), stopped(false)
{
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

void Car::reportCar()
{
    cout << this->brand << " " << this->model << "(" << this->year << ")"
         << "\nCurrent milage: " << this->miles
         << "\nTank level: " << this->fuel_level << "\n============\n";
}
