/* Filename: loading.cpp
 *
 * This program showcases the creation and use of a structure,
 * and how to load it from a binary file
 *
 * @author: gcastill
 * August 2023
 */
#include <cstdlib>
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

#define MAX_STAMINA 100;

// The "teams" we define in our program
enum Faction
{
    ALLY,
    ENEMY,
    NEUTRAL
};

// PROTOTYPES for auxiliary functions
string getRandomValue(const string[], size_t size);
string getRandomName();
string labelFaction(Faction);

// The data set where values of characters created will come from
const string NAMES[] = {"Charlie", "Robert", "Dave", "Anna", "Karen"};

/**
 * @brief The __Character__ struct represents an agent in our simulation.
 * The strength of the character is defined by the MAX_STAMINA macro, and
 * Its allegiance by the __Faction__ enum.
 *
 */
struct Character
{
    // Name of the character. Comes from NAMES array.
    string c_name;
    // Allegiance of the character. Comes from Faction enum
    Faction c_group;
    // Stamina of the character
    int c_stamina;

    /**
     * @brief Construct a new empty Character object
     *
     */
    Character() {}

    /**
     * @brief Construct a new Character object
     *
     * @param name - The name of the character
     * @param stamina - The initial stamina of the character
     * @param group - Its original allegiance.
     */
    Character(string name, int stamina, Faction group = NEUTRAL)
    {
        c_name = name;
        c_stamina = stamina;
        c_group = group;
    }
    /**
     * @brief Overload of the == operator. We will use this to
     * compare character's names.
     *
     * @param other
     * @return true
     * @return false
     */
    inline bool operator==(const Character &other) const
    {
        return c_name.compare(other.c_name);
    }
};

/**
 * @brief Overload of the output operator to write the values
 * of the Character.
 *
 * @param os - The stream to write on
 * @param character - The character we want to write.
 * @return ostream& - The updated output stream with the new data.
 */
inline ostream &operator<<(ostream &os, const Character &character)
{
    os << character.c_name << "(" << labelFaction(character.c_group)
       << ") : " << character.c_stamina << "\n";
    os << endl;
    return os;
}

// Redefinition of characters to clearly differentiate between
// enemies and heroes.
typedef Character enemy;
typedef Character hero;

istream &load(istream &, Character &);

int main()
{
    // Initialize randomization
    srand(time(0));

    hero myHero;
    enemy myEnemy;
    Character third;

    ifstream rf("characters.dat", ios::in | ios::binary);
    if (!rf)
    {
        cout << "Cannot open file!" << endl;
        return 1;
    }
    load(rf, myHero);
    load(rf, myEnemy);
    load(rf, third);

    rf.close();
    if (!rf.good())
    {
        cout << "Error occurred at reading time!" << endl;
        return 1;
    }
    cout << myHero << endl;
    cout << myEnemy << endl;
    cout << third << endl;
}

/**
 * @brief Returns the label to clearly state the allegiance of
 * the character.
 *
 * @param fact - The faction we want to show the label of.
 * @return string - The label of the faction
 */
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

/**
 * @brief Function that will load the information from a file.
 * Observe that because we have a string in our struct, we have to
 * load it in a different way that represents two steps.
 *
 * @param in - The file containing the information.
 * @param character - The object that will represent the data.
 * @return istream& - The input stream object.
 */
istream &load(istream &in, Character &character)
{
    size_t len;
    in.read(reinterpret_cast<char *>(&len), sizeof(len));
    char *name = new char[len + 1];
    in.read(name, len);
    name[len] = '\0';
    character.c_name = name;
    in.read(reinterpret_cast<char *>(&character.c_group), sizeof(Faction));
    in.read(reinterpret_cast<char *>(&character.c_stamina), sizeof(int));
    delete[] name;
    return in;
}
