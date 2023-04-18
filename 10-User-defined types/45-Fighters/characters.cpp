/* Filename: characters.cpp
 *
 * This program showcases the creation and use of a structure,
 * as well as defining a constructor and overloading an operator
 * to it.
 *
 * @author: gcastill
 * August 2023
 */

#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;

#define MAX_STAMINA 100;
#define MAX_STRENGHT 10;

enum Faction
{
    ALLY,
    ENEMY,
    NEUTRAL
};

string getRandomName(const string[]);

const string NAMES[] = {"Charlie", "Robert", "Dave", "Anna", "Karen"};
const string ITEMS[] = {"Axe", "Nunchucks", "Bow", "Knife", "Spoon"};
struct Item
{
    string i_name;
    int i_power;
    Item()
    {
        i_name = "Toothpick";
        i_power = 0;
    };
    Item(string name, int power)
    {
        i_name = name;
        i_power = power;
    }
    inline bool operator==(const Item &other) const
    {
        return i_name.compare(other.i_name);
    }
    inline int operator-(const Item &other) const
    {
        return i_power - other.i_power;
    }
    inline ostream &operator<<(ostream &os)
    {
        os << i_name << " (" << i_power << ") - ";
        return os;
    }
};

struct Character
{
    string c_name;
    Faction c_group;
    int c_stamina;
    Item c_items[2];
    Character(string name, int stamina, Faction group = NEUTRAL)
    {
        c_name = name;
        c_stamina = stamina;
        c_group = group;
        c_items[0] = Item();
        c_items[1] = Item();
    }
    inline bool operator==(const Character &other) const
    {
        return c_name.compare(other.c_name);
    }
};

inline ostream &operator<<(ostream &os, const Character &character)
{
    Item it;
    cout << "in writing\n";
    os << character.c_name << "(" << labelFaction(character.c_group) << ") : " << character.c_stamina << "\n";
    os << "Inventory: - ";
    /*for (int i=0)
    {
        it = character.c_items[i]
        if (it.i_power > 0)
            os << it.i_name << " (" << it.i_power << ") - ";
    }*/
    os << endl;
    return os;
}

typedef Character enemy;
typedef Character hero;

string labelFaction(Faction);

const hero getAlly();
const enemy getEnemy();
const Character makeChar(Faction);

int main()
{
    hero myHero = getAlly();
    enemy myEnemy = getEnemy();

    cout << myHero << endl;
    cout << myEnemy << endl;
}

string labelFaction(Faction fact)
{
    switch (fact)
    {
    case ALLY:
        return "Ally";
    case ENEMY:
        return "Enemy";
    default:
        return "Passerby";
    }
}

string getRandomName(const string arr[])
{
    return arr[rand() % 5];
}

const Character makeChar(Faction faction)
{
    int stamina = rand() % MAX_STAMINA;
    const Character myCharacter(getRandomName(NAMES), stamina, faction);
    return myCharacter;
}

const hero getAlly()
{
    return makeChar(ALLY);
}

const enemy getEnemy()
{
    return makeChar(ENEMY);
}
