#include "Personne.h"
#include "stdlib.h"

Personne::Personne()
{
    setVie(rand()%49+51);
    setId();
}

Personne::~Personne()
{
    //dtor
}

unsigned long Personne::getId(){
    return this->id;
}

void Personne::setId(){
    this->id=staticVar++;
}

float Personne::getVie(){
    return this->vie;
}

void Personne::setVie(int vie){
    this->vie=vie;
}

void Personne::degats(int degats){
    this->vie=this->vie-degats;
}

string Personne::getTypeSkill(){
    return this->typeSkill;
}

void Personne::setTypeSkill(string type){
    this->typeSkill=type;
}

unsigned long Personne::staticVar = 0;
