/* filename: objHeader.h
 *
 * Header file to define a simple CD class.
 *
 * @author: gcastillo, 2014
 */
#include <string>
#include <vector>
#include <fstream>
using namespace std;

enum Genre {
    POP_MUSIC,
    ROCK_MUSIC,
    FOLK_MUSIC,
    PUNK_MUSIC,
    COUNTRY_MUSIC,
    DISCO_MUSIC,
    RAEGETON_MUSIC,
    CLASSIC_MUSIC
};

enum DISPLAY_OPTS {
    FULL_DESC,
    MAIN_DESC,
    SIMPLE_DESC
};

enum SEARCH_OPTS {
    GENRE_SEARCH,
    DATE_SEARCH
};

class CD {
private:
    string name;
    string artist;
    string label;
    int tracks;
    vector<string> trackList;
    int year;
    Genre genre;
public:
    CD();
    ~CD();

    void setName(string);
    void setArtist(string);
    void setLabel(string);
    void setYear(int);
    void setGenre(Genre);
    void setTrackList(vector<string>);
    void addTrackToList(string);
    string removeTrackFromList(string);

    string getName();
    string getArtist();
    string getLabel();
    int getYear();
    Genre getGenre();
    vector<string> getTrackList();
    string getTrack(int);
    int getTracks();

    string showCD(DISPLAY_OPTS);
    void saveCDToFile(ofstream &);
};

class Jukebox {
private:
    vector<CD> catalog;
public:
    void loadFromFile(string);
    void addToCatalog(CD);
    vector<CD> getCatalog();
    CD getFromCatalog(int);

    string getPlayAll();
    string getShuffle(int);
    string getByGenre(Genre);
    string getByYearRange(int, int);
    string getByArtist(string);
};