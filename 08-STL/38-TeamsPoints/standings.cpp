/**
 * filename: standings.cpp
 *
 * In this program we simulate a system that keeps tracks of
 * the standings in the mexican soccer league.
 *
 * @author: gcastillo, 2023
 */

#include <iostream>
#include <string>
#include <map>
#include <algorithm>

using namespace std;

void showStandings(map<string, int>);

int main()
{
    string teams[] = {"Monterrey",
                      "Toluca",
                      "América",
                      "León",
                      "Pachuca",
                      "Chivas",
                      "Tigres",
                      "Cruz Azul",
                      "Club Querétaro",
                      "Puebla",
                      "Santos",
                      "Atlético de San Luis",
                      "Atlas",
                      "FC Juárez",
                      "Pumas",
                      "Necaxa",
                      "Club Tijuana",
                      "Mazatlán"};
    map<string, int> standings;

    int len = sizeof(teams) / sizeof(teams[0]);
    sort(teams, teams + len);
    // initializing
    for (string team : teams)
        standings[team] = rand() % 3;
    cout << "After the first week, this are the standings\n\n";
    showStandings(standings);

    cout << "\n\nAfter the second week, this are the standings\n\n";
    // simulate one week
    for (string team : teams)
        standings[team] += rand() % 3;
    showStandings(standings);

    return 0;
}

void showStandings(map<string, int> m_map)
{
    map<string, int>::iterator it;
    for (it = m_map.begin(); it != m_map.end(); ++it)
    {
        cout << it->first << " => " << it->second << '\n';
    }
}