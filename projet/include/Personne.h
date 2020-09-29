#ifndef PERSONNE_H
#define PERSONNE_H
#include <string>
using namespace std;


class Personne
{
    public:
        Personne();
        virtual ~Personne();
        float getVie();
        void setVie(int vie);
        void degats(int degats);
        unsigned long getId();
        void setId();
        string getTypeSkill();
        void setTypeSkill(string type);

    protected:
        static unsigned long staticVar;
        float vie;
        unsigned long id;
        string typeSkill;

    private:
};

#endif // PERSONNE_H
