/* filename: objMain.cpp
 *
 * Implementation of the CD class defined in objHeader.h
 *
 * @author: gcastillo, 2014
 */
#include "objHeader.h"
#include <sstream>
using namespace std;

CD::CD() { }

CD::~CD() { }

void CD::setName(string name) {
    this->name = name;
}

void CD::setArtist(string artist){
    this->artist = artist;
}

void CD::setLabel(string label) {
    this->label = label;
}

void CD::setYear(int year) {
    this->year = year;
} 

void CD::setGenre(Genre genre) {
    this->genre = genre;
}

void CD::setTrackList(vector<string> list) {
    this->trackList = list;
}

void CD::addTrackToList(string track){
    this->trackList.push_back(track);
}

string CD::removeTrackFromList(string value) {
    int index = -1;
    for(int i=0; i<this->trackList.size(); i++) {
        if(value.compare(this->trackList[i]) == 0){
            index = i;
            break;
        }
    }
    if(index != -1) {
        try {
            this->trackList.erase(this->trackList.begin() + index);
        } catch (int ex) {
            return "Error al borrar";
        }
        return "Borrado";
    }
    return "No encontrado";
}

string CD::getName() {
    return this->name;
}

string CD::getArtist() {
    return this->artist;
}

string CD::getLabel() {
    return this->label;
}

int CD::getYear() {
    return this->year;
}

Genre CD::getGenre() {
    return this->genre;
}

vector<string> CD::getTrackList() {
    return this->trackList;
}

string CD::getTrack(int trackNum) {
    if(trackNum < getTracks()) {
        return this->trackList[trackNum];
    }
    return "";
}

int CD::getTracks() {
    return this->trackList.size();
}

string CD::showCD(DISPLAY_OPTS opts) {
    stringstream outputStr;
    if(opts == SIMPLE_DESC) {
        outputStr << this->getName() << ", " << this->getArtist() << endl;
    } else if(opts == MAIN_DESC || opts== FULL_DESC) {
        outputStr << "Name: " << this->getName() << endl;
        outputStr << "Artist: " << this->getArtist() << endl;
        outputStr << "Label: " << this->getLabel() << endl;
        outputStr << "Year: " << this->getYear() << endl;
        outputStr << "Genre: ";
        switch(this->getGenre()) {
            case POP_MUSIC:      outputStr << "Pop"; break;
            case ROCK_MUSIC:     outputStr << "Rock"; break;
            case FOLK_MUSIC:     outputStr << "Folk"; break;
            case PUNK_MUSIC:     outputStr << "Punk"; break;
            case COUNTRY_MUSIC:  outputStr << "Country"; break;
            case DISCO_MUSIC:    outputStr << "Disco"; break;
            case RAEGETON_MUSIC: outputStr << "Raegeton"; break;
            case CLASSIC_MUSIC:  outputStr << "Classic"; break;
            default:             outputStr << "Not specified"; break;
        } 
        outputStr << endl;
        outputStr << "Tracks: " << this->getTracks() << endl;
        if(opts== FULL_DESC) {
            for(int i=0; i<this->getTracks(); i++) {
                outputStr << i+1 << " - " << trackList[i] << endl;
            }
        }
    } 
    return outputStr.str();
}

void CD::saveCDToFile(ofstream &output) {
    output << this->getName() << endl;
    output << this->getArtist() << endl;
    output << this->getLabel() << endl;
    output << (int)this->getGenre(); 
    output << this->getYear() << endl;
    output << this->getTracks() << endl;
    for(int i=0; i<this->getTracks(); i++) {
        output << trackList[i];
        if(i+1 < this->getTracks()) {
            output << endl;
        }
    }
}

void Jukebox::loadFromFile(string filename) {
    int tempInt;
    string tempValue;
    ifstream file;

    file.open(filename);
    if(file.is_open()) {
        while(!file.eof()) {
            getline(file, tempValue);
            if(tempValue == "") break;
            CD record;
            record.setName(tempValue);
            getline(file, tempValue);
            record.setArtist(tempValue);
            getline(file, tempValue);
            record.setLabel(tempValue);
            file >> tempInt;
            record.setGenre(Genre(tempInt-1));
            file >> tempInt;
            record.setYear(tempInt);
            file >> tempInt;
            file.ignore(1, '\n');
            for(int i=0; i<tempInt; i++){
                getline(file, tempValue);
                record.addTrackToList(tempValue);
            }
            this->catalog.push_back(record);
        }
        file.close();
    } else {
        throw 10;
    }
}

void Jukebox::addToCatalog(CD cd) {
    this->catalog.push_back(cd);
}

vector<CD> Jukebox::getCatalog() {
    return this->catalog;
}

CD Jukebox::getFromCatalog(int index) {
    return this->catalog[index];
}

//Artist, disco, cancion
string Jukebox::getPlayAll() {
    stringstream output;
    output << "Catalog contains: \n";
    for(int i=0; i<this->catalog.size(); i++) {
        for(int j=0; j<this->catalog[i].getTracks(); j++){
            output << this->catalog[i].getName() << " by "
                   << this->catalog[i].getArtist() << ": "
                   << this->catalog[i].getTrack(j) << endl;
        }
    }
    return output.str();
}

string Jukebox::getShuffle(int qty) {
    return "";
}

string Jukebox::getByGenre(Genre genre) {
    stringstream output;
    int cnt = 0;
    output << "Discs with this genre are: \n";
    for(int i=0; i<this->catalog.size(); i++){
        if(this->catalog[i].getGenre() == genre) {
            output << this->catalog[i].getName() << " by "
                   << this->catalog[i].getArtist() << "\n";
            cnt ++;
        }
    }
    if(cnt == 0)
        return "No Discs available\n";
    return output.str();
}

string Jukebox::getByYearRange(int init, int end) {
    return "";
}

string Jukebox::getByArtist(string artist){
    stringstream output;
    output << "Discs by this artist are: \n";
    for(int i=0; i<this->catalog.size(); i++){
        if(this->catalog[i].getArtist() == artist) {
            output << this->catalog[i].getName() << " by "
                   << this->catalog[i].getArtist() << "\n";
        }
    }
    return output.str();
}