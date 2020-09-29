#ifndef CAPACITE_H
#define CAPACITE_H
#include <string>

using namespace std;


class Capacite
{
    public:
        Capacite();
        virtual ~Capacite();

        void setPuissance(int power);
        int getPuissance();

        void setNom(string name);
        string getNom();

        void setId(int capId);
        int getId();

    protected:
        int puissance; //pas unsigned car possiblilité de soin
        string nom;
        int capId;

    private:
};

#endif // CAPACITE_H
