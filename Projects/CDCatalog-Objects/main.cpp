/* filename: main.cpp
 *
 * Archivo principal que ejecutara las funciones
 * del CD.
 *
 * @author: gcastillo, 2014
 */
#include <iostream>
#include <fstream>
using namespace std;

#include "objHeader.h"

CD inputCDData() throw(int);
void displayCDData(vector<CD>);
void saveCatalog(vector<CD>);

int main()
{
    Jukebox jukebox;
    int menuOpt, searchOpt;
    Jukebox *ptrJB = &jukebox;
    jukebox.loadFromFile("catalog.txt");
    do
    {
        cout << "Que deseas hacer:\n1-Capturar\n2-Cargar"
             << "\n3-Mostrar\n4-Buscar por genero\n5-Salir\n:";
        cin >> menuOpt;
        cin.ignore(1, '\n');
        if (menuOpt == 1)
        {
            try
            {
                CD ccd = inputCDData();
                ptrJB->addToCatalog(ccd);
            }
            catch (int exceptionCode)
            {
                cerr << "Error en lectura.\n";
            }
        }
        else if (menuOpt == 2)
        {
            string filename;
            try
            {
                cout << "Que archivo quieres cargar: ";
                cin >> filename;
                (*ptrJB).loadFromFile(filename);
            }
            catch (int exceptionCode)
            {
                cerr << "Error en lectura.\n";
            }
        }
        else if (menuOpt == 3)
        {
            // displayCDData(catalog);
            system("cls");
            cout << jukebox.getPlayAll();
            system("pause");
            system("cls");
        }
        else if (menuOpt == 4)
        {
            system("cls");
            cout << "Que genero deseas buscar:\n1 - Pop\n2 - Rock\n"
                 << "3 - Folk\n4 - Punk\n5 - Country\n6 - Disco\n"
                 << "7 - Raegeton\n8 - Clasico\n";
            cin >> searchOpt;
            cout << jukebox.getByGenre((Genre)(searchOpt - 1));
            // system("pause");
            system("cls");
        }
    } while (menuOpt != 5);
    // saveCatalog(catalog);
}

CD inputCDData() throw(int)
{
    CD record;
    int tempInt;
    string tempValue;
    system("cls");
    cout << "Dame el titulo del album: ";
    getline(cin, tempValue);
    record.setName(tempValue);

    cout << "Dame el artista: ";
    getline(cin, tempValue);
    record.setArtist(tempValue);

    cout << "De que compa\244ia es: ";
    getline(cin, tempValue);
    record.setLabel(tempValue);

    cout << "A que genero pertenece:\n1 - Pop\n2 - Rock\n"
         << "3 - Folk\n4 - Punk\n5 - Country\n6 - Disco\n"
         << "7 - Raegeton\n8 - Clasico\n";
    cin >> tempInt;
    record.setGenre(Genre(tempInt - 1));

    cout << "De que a\244o es el album: ";
    cin >> tempInt;
    record.setYear(tempInt);

    cout << "Cuantas canciones tiene: ";
    cin >> tempInt;
    cin.ignore(1, '\n');
    for (int i = 0; i < tempInt; i++)
    {
        cout << "Dame la cancion #" << i + 1 << ": ";
        getline(cin, tempValue);
        record.addTrackToList(tempValue);
    }
    system("cls");
    return record;
}

void displayCDData(vector<CD> catalog)
{
    system("cls");
    for (int i = 0; i < catalog.size(); i++)
    {
        cout << catalog[i].showCD(FULL_DESC);
        cout << "==================================" << endl;
    }
    system("pause");
    system("cls");
}

void saveCatalog(vector<CD> catalog)
{
    ofstream output;
    output.open("catalog.txt", ios::ate | ios::app);
    if (output.is_open())
    {
        for (int i = 0; i < catalog.size(); i++)
        {
            catalog[i].saveCDToFile(output);
        }
        output.close();
    }
}