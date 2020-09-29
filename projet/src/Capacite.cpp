#include "Capacite.h"

Capacite::Capacite()
{
    this->capId=0;
}

Capacite::~Capacite()
{
    //dtor
}

int Capacite::getPuissance(){
    return this->puissance;
}

void Capacite::setPuissance(int power){
    this->puissance=power;
}

string Capacite::getNom(){
    return this->nom;
}

void Capacite::setNom(string name){
    this->nom=name;
}

int Capacite::getId(){
    return this->capId;
}

void Capacite::setId(int capId){
    this->capId=capId;
}
