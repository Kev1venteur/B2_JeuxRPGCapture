#ifndef JEUX_H
#define JEUX_H
#include "Ingenieur.h"
#include "map.h"


class Jeux
{
    public:
        Jeux();
        virtual ~Jeux();
        void jouer();
        bool testCollisionMonJoueur();
        bool testOfBoundaries();
        void combat();
        short attaque();
        void degats(int numAttaque);
        void menu();

    protected:

    private:
        Map* maMap;
        Ingenieur* monJoueur;
        short numCodeurCombat;
        short numIngenieurCombat;
        short numCodeurDeIngenieurSauvage;
};

#endif // JEUX_H
