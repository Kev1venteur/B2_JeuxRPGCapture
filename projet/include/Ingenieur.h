#ifndef INGENIEUR_H
#define INGENIEUR_H
#include <string>
#include "Personne.h"
#include "vector"
#include "Codeur.h"
#include <iostream>
using namespace std;


class Ingenieur : public Personne
{
    public:
        Ingenieur();
        virtual ~Ingenieur();

        unsigned long getForceC();
        void setForceC(unsigned int value);

        unsigned long getForceJava();
        void setForceJava(unsigned int value);

        unsigned long getForceCPP();
        void setForceCPP(unsigned int value);

        unsigned long getForceHtmlCss();
        void setForceHtmlCss(unsigned int value);

        unsigned long getForcePhp();
        void setForcePhp(unsigned int value);

        unsigned long getForceCSharp();
        void setForceCSharp(unsigned int value);

        unsigned long getForceScratch();
        void setForceScratch(unsigned int value);

        unsigned long getForceJavaScript();
        void setForceJavaScript(unsigned int value);

        Codeur* getEquipeIndexN(unsigned int n);
        void addEquipe(Codeur* codeur);

        int getXMin();
        void setXMin(unsigned int value);

        int getYMin();
        void setYMin(unsigned int value);

        int getXMax();
        void setXMax(unsigned int value);

        int getYMax();
        void setYMax(unsigned int value);

        unsigned int getMontantArgent();
        void setMontantArgent(unsigned int montantArgent);

        bool estALinterieurDeToi(int xMin, int xMax, int yMin, int yMax);

        void moveUp(int num);
        void moveDown(int num);
        void moveLeft(int num);
        void moveRight(int num);

        unsigned int getTeamSize();

        Capacite* getCapacite(short n);
        void setCapacite(short place, Capacite* cap);

        void assignationZoneCap();

        void coordUpdate();

        vector<Codeur*> returnVectorEquipe();

    protected:

    private:
        Capacite* tabCapacites[4];
        vector<Capacite*> vectorCapTotalCsv;
        unsigned int nombreCodeurs;
        string nom;
        unsigned int montantArgent;
        float forceC;
        float forceJava;
        float forceCPP;
        float forceHtmlCss;
        float forcePhp;
        float forceCSharp;
        float forceScratch;
        float forceJavaScript;
        vector<Codeur*> equipe;
        int xMin;
        int yMin;
        int xMax;
        int yMax;
};

#endif // INGENIEUR_H
