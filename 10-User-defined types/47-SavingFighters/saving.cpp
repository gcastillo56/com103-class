/* Filename: saving.cpp
 *
 * This program showcases the creation and use of a structure,
 * and how to store it in a binary file
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
string getRandomValue(const string[], size_t);
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

// PROTOTYPES for auxiliary methods to create characters.
const hero getAlly();
const enemy getEnemy();
const Character getThird();
const Character makeChar(Faction);
ostream &save(ostream &, Character const &);

int main()
{
    // Initialize randomization
    srand(time(0));
    hero myHero = getAlly();
    enemy myEnemy = getEnemy();
    Character third = getThird();

    cout << myHero << endl;
    cout << myEnemy << endl;
    cout << third << endl;

    ofstream wf("characters.dat", ios::out | ios::binary);
    if (!wf)
    {
        cout << "Cannot open file!" << endl;
        return 1;
    }
    save(wf, myHero);
    save(wf, myEnemy);
    save(wf, third);
    wf.close();
    if (!wf.good())
    {
        cout << "Error occurred at writing time!" << endl;
        return 1;
    }
    cout << "All characters saved. \n";
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
 * @brief Get the Random Value object out of our database arrays
 *
 * @param arr - The array we are taking from
 * @param size - The size of the array.
 * @return string - The value we want to get out of.
 */
string getRandomValue(const string arr[], size_t size)
{
    return arr[rand() % size];
}

/**
 * @brief Get the Random Name object out of the NAMES array
 *
 * @return string - A random name out of the database.
 */
string getRandomName() { return getRandomValue(NAMES, 5); }

/**
 * @brief Creates a new character with the given faction. The initial
 * stamina is assigned here.
 *
 * @param faction - The faction to which this character will belong.
 * @return const Character - The Character that was created.
 */
const Character makeChar(Faction faction)
{
    int stamina = rand() % MAX_STAMINA;
    const Character myCharacter(getRandomName(), stamina, faction);
    return myCharacter;
}

/**
 * @brief Get an Ally object
 *
 * @return const hero - The Ally character
 */
const hero getAlly() { return makeChar(ALLY); }

/**
 * @brief Get an Enemy object
 *
 * @return const enemy - The Enemy character
 */
const enemy getEnemy() { return makeChar(ENEMY); }

/**
 * @brief Get a new character of a random faction
 *
 * @return const Character - The Character created.
 */
const Character getThird()
{
    return makeChar(static_cast<Faction>(rand() % 3));
}

/**
 * @brief Method that will save the object into a file.
 * Observe that because we have a string in our struct, we have to
 * save it in a different way that represents two steps.
 *
 * @param ofs - The file stream to write on
 * @param character - The character we want to write.
 * @return ofstream& - The updated output file stream with the new data.
 */
ostream &save(ostream &out, Character const &character)
{
    size_t len = character.c_name.size();
    out.write(reinterpret_cast<char const *>(&len), sizeof(len));
    out.write(character.c_name.c_str(), len);
    out.write(reinterpret_cast<char const *>(&character.c_group), sizeof(Faction));
    out.write(reinterpret_cast<char const *>(&character.c_stamina), sizeof(int));
    return out;
}
