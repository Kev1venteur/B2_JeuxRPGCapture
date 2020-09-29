#ifndef CODEUR_H
#define CODEUR_H
#include <string>
#include "Capacite.h"
#include "Personne.h"
#include <vector>

using namespace std;


class Codeur : public Personne
{
    public:
        Codeur();
        virtual ~Codeur();

        float getPoucentageSkill();
        void setPourcentageSkill(float percentage);

        Capacite* getCapacite(short n);
        void setCapacite(short place, Capacite* cap);

    protected:
        float pourcentageSkill;
        Capacite* tabCapacites[4];
        vector<Capacite*> vectorCapTotalCsv;

    private:
};

#endif // CODEUR_H
