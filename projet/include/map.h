#ifndef MAP_H
#define MAP_H
#include "zone.h"
#include "CodeurSauvage.h"
#include "Ingenieur.h"
#include <vector>

class Map
{
    public:
        Map();
        virtual ~Map();
        void generationCodeursSauvages(unsigned int nombreCodeurs);
        void generationIngenieurs(unsigned int nombreCodeurs);

        CodeurSauvage* getVectorCodeursSauvage(int i);
        Ingenieur* getVectorIngenieursSauvage(int i);

        unsigned int getSizeVectorCodeursSauvage();
        unsigned int getSizeVectorIngenieursSauvage();

        void replaceVectorCodeursSauvage(int i);
        void replaceVectorIngenieursSauvage(int i);

    protected:

    private:
       vector<CodeurSauvage*> vectorCodeursSauvage;
       vector<Ingenieur*> vectorIngenieursSauvage;
       unsigned short int xMin;
       unsigned short int xMax;
       unsigned short int yMin;
       unsigned short int yMax;
       Zone* php;
       Zone* cSharp;
       Zone* cPP;
       Zone* c;
       Zone* epsi;
       Zone* java;
       Zone* jS;
       Zone* html1;
       Zone* html2;
       Zone* html3;
       Zone* html4;
       Zone* html5;
       Zone* scratch1;
       Zone* scratch2;
       Zone* scratch3;
       Zone* zoneVide1;
       Zone* zoneVide2;
       Zone* zoneVide3;
       Zone* zoneVide4;
       Zone* zoneVide5;
       Zone* zoneVide6;
       Zone* zoneVide7;
       Zone* zoneVide8;
       Zone* zoneVide9;
       Zone* zoneVide10;
       Zone* zoneVide11;
};

#endif // MAP_H
