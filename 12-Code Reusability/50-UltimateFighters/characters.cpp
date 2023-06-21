/* Filename: characters.cpp
 *
 * This program showcases the implementation of all the methods declared
 * in the header file.
 *
 * @author: gcastill
 * August 2023
 */
#include <array>
#include <cstdlib>
#include <iostream>
#include <string>
#include "characters.h"
using namespace std;

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
    save(out, character.c_items[0]);
    save(out, character.c_items[1]);
    return out;
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
    Item t_item_0;
    load(in, t_item_0);
    character.c_items[0] = t_item_0;
    Item t_item_1;
    load(in, t_item_1);
    character.c_items[1] = t_item_1;
    return in;
}

/**
 * @brief Method that will save the object into a file.
 * Observe that because we have a string in our struct, we have to
 * save it in a different way that represents two steps.
 *
 * @param ofs - The file stream to write on
 * @param item - The item we want to write.
 * @return ofstream& - The updated output file stream with the new data.
 */
ostream &save(ostream &out, Item const &item)
{
    size_t len = item.i_name.size();
    out.write(reinterpret_cast<char const *>(&len), sizeof(len));
    out.write(item.i_name.c_str(), len);
    out.write(reinterpret_cast<char const *>(&item.i_power), sizeof(int));
    return out;
}

/**
 * @brief Function that will load the information from a file.
 * Observe that because we have a string in our struct, we have to
 * load it in a different way that represents two steps.
 *
 * @param in - The file containing the information.
 * @param item - The object that will represent the data.
 * @return istream& - The input stream object.
 */
istream &load(istream &in, Item &item)
{
    size_t len;
    in.read(reinterpret_cast<char *>(&len), sizeof(len));
    char *name = new char[len + 1];
    in.read(name, len);
    name[len] = '\0';
    item.i_name = name;
    in.read(reinterpret_cast<char *>(&item.i_power), sizeof(int));
    delete[] name;
    return in;
}
