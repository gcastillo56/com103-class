/* filename: cdCatalog.cpp
 * 
 * Creates a program to manage a CD catalog.
 * 
 * @author: gcastillo, 2014
 */
#include <iostream>
#include <string>
#include <vector>
using namespace std;

#define OLD_RECORD_EXCEPTION 10

enum Quality {
    VERY_BAD,
    BAD,
    OK,
    GOOD,
    VERY_GOOD
};

struct CD {
  string albumName;     //Contains the name of the record
  string artist;        //Contains the name of the performer
  string companyLabel;
  int year;
  int numSongs;
  Quality albumQuality; //Stores the value of the qualification by the user
                        //of the current record. It's domain is set in the
                        //Quality enum.
};

CD inputCDData() throw (int, string);
void displayCDData(vector<CD>);

int main() {
    vector<CD> catalog;
    int menuOpt;
    do {
        cout << "Que deseas hacer:\n1-Capturar\n2-Mostrar\n3-Salir\n:";
        cin >> menuOpt;
        cin.ignore(1, '\n');
        if(menuOpt == 1) {
             try {
                   catalog.push_back(inputCDData());
            } catch (int exceptionCode) {
                if(exceptionCode == 20) {
                    cout << "Rango erroneo.\n";
                } else if(exceptionCode == OLD_RECORD_EXCEPTION) {
                    cout << "Disco viejo\n";
                }
             } 
        } else if(menuOpt == 2) {
            displayCDData(catalog);
        }
    } while(menuOpt != 3);
    system("pause");
}

CD inputCDData() throw (int) {
    CD record;
    int tQuality;
    cout << "Dame el titulo del album: ";
    getline(cin, record.albumName);
    cout << "Dame el artista: ";
    getline(cin, record.artist);
    cout << "De que a\244o es el album: ";
    cin >> record.year;
    if(record.year < 1980) throw OLD_RECORD_EXCEPTION;
    cout << "Cuantas canciones tiene: ";
    cin >> record.numSongs;
    cout << "Que calidad tiene (1-VERY BAD  ...  5-VERY GOOD): ";
    cin >> tQuality;
    if(tQuality < 1 || tQuality > 5) throw 20;
    switch(tQuality-1) {
        case VERY_BAD:  record.albumQuality = VERY_BAD; break;
        case BAD:       record.albumQuality = BAD; break;
        case OK:        record.albumQuality = OK; break;
        case GOOD:      record.albumQuality = GOOD; break;
        case VERY_GOOD: record.albumQuality = VERY_GOOD; break;
        default: record.albumQuality = OK;
    }
    cin.ignore(1,'\n');
    cout << "De que compa\244ia es: ";
    getline(cin, record.companyLabel);
    return record;
}

void displayCDData(vector<CD> catalog) {
    CD record;
    for(int i=0; i<catalog.size(); i++){
        record = catalog[i];
        cout << endl;
        cout << "Album:   " << record.albumName << endl;
        cout << "Artist:  " << record.artist << endl;
        cout << "Year:    " << record.year << endl;
        cout << "# songs: " << record.numSongs << endl;
        cout << "Quality: ";
        switch(record.albumQuality) {
            case VERY_BAD:  cout << "Very bad"; break;
            case BAD:       cout << "Bad"; break;
            case OK:        cout << "Ok"; break;
            case GOOD:      cout << "Good"; break;
            case VERY_GOOD: cout << "Very good"; break;
        }
        cout << endl;
        cout << "Compa\244ia: " << record.companyLabel << endl;
        cout << endl;
    }
    cout << endl;
}