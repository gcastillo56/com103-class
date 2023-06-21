/* Filename: characters.cpp
 *
 * This program showcases the creation and use of a structure,
 * as well as defining a constructor and overloading an operator
 * to it.
 *
 * @author: gcastill
 * August 2022
 */
#include <array>
#include <cstdlib>
#include <iostream>
#include <string>
using namespace std;

#define MAX_STAMINA 100;
#define MAX_STRENGHT 10;

/**
 * @brief This function uses templates to return the size of an array.
 * We need this function to extract the implicit value of the array.
 *
 * @tparam T - The type of the array
 * @tparam N - The items in the array (implicit)
 * @return size_t - The size of the array
 */
template <typename T, size_t N>
inline size_t SizeOfArray(const T (&)[N])
{
    return N;
}

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
string getRandomItem();
string labelFaction(Faction);

// The data set where values of items created will come from
const string NAMES[] = {"Charlie", "Robert", "Dave", "Anna", "Karen"};
const string ITEMS[] = {"Axe", "Nunchucks", "Bow", "Knife", "Spoon"};

/**
 * @brief The __Item__ struct represents a weapon that our characters
 * can use to attack or defend themselves.
 * The strength of the items will be defined by the MAX_STRENGHT macro.
 *
 */
struct Item
{
    // Name of the item. Comes from ITEMS array
    string i_name;
    // The attack/defense power the item has
    int i_power;

    /**
     * @brief Construct a new Item object
     */
    Item()
    {
        i_name = "Toothpick";
        i_power = 0;
    };
    /**
     * @brief Construct a new Item object
     *
     * @param name - The assigned item from the items dataset
     * @param power - The power of the item
     */
    Item(string name, int power)
    {
        i_name = name;
        i_power = power;
    }
    /**
     * @brief Overloading of the equal operator to compare items
     * amongst them
     *
     * @param other - The item to which this will be compared.
     * @return true - If items have the same name.
     * @return false - If items have different names.
     */
    inline bool operator==(const Item &other) const
    {
        return i_name.compare(other.i_name);
    }
    /**
     * @brief Overloading of the minus sign. We will use this
     * operator to simulate the wear of the items
     *
     * @param other - The item against which our item is interacting
     * @return int - The difference in powers between items.
     */
    inline int operator-(const Item &other) const
    {
        return i_power - other.i_power;
    }
};

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
    // Array holding the items, it can only hold 2, one per hand.
    Item c_items[2];

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
        // We define the strength of each item when assigned.
        int t_Strength = rand() % MAX_STRENGHT;
        c_items[0] = Item(getRandomItem(), t_Strength);
        t_Strength = rand() % MAX_STRENGHT;
        c_items[1] = Item(getRandomItem(), t_Strength);
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
 * of the Items.
 *
 * @param os - The stream to write on
 * @param item - The item we want to write.
 * @return ostream& - The updated output stream with the new data.
 */
inline ostream &operator<<(ostream &os, const Item &item)
{
    if (item.i_power > 0)
        os << item.i_name << " (" << item.i_power << ") - ";
    else
        os << item.i_name << " DEPLETED - ";
    return os;
}

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
    Item it;
    os << character.c_name << "(" << labelFaction(character.c_group)
       << ") : " << character.c_stamina << "\n";
    os << "Inventory: - ";
    os << character.c_items[0];
    os << character.c_items[1];
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
string getRandomName() { return getRandomValue(NAMES, SizeOfArray(NAMES)); }

/**
 * @brief Get the Random Item object out of the ITEMS array.
 *
 * @return string - A random name of the item we get out of the database.
 */
string getRandomItem() { return getRandomValue(ITEMS, SizeOfArray(ITEMS)); }

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
 * @todo TODO: Create all the interaction between characters,
 * such as encounters, fights, destructions, etc.
 *
 */