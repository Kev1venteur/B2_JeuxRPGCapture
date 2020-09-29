#include "Codeur.h"
#include "time.h"
#include "stdlib.h"
#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <vector>
using namespace std;

Codeur::Codeur()
{
    setPourcentageSkill(rand()%49+1);
    short tailleTabCapCodeur = 0;
    this->tabCapacites[tailleTabCapCodeur]=new Capacite();
    while(this->tabCapacites[tailleTabCapCodeur+1]!=NULL && tailleTabCapCodeur<3){
        tailleTabCapCodeur++;
        this->tabCapacites[tailleTabCapCodeur]=new Capacite();
    }
    ifstream myfile("../csv/attaques.csv");
    if (myfile.is_open()){
        myfile.clear();
        myfile.seekg(0, ios::beg);
        short capId, capPower, i = 0;
        string capName;
        while(myfile >> capId >> capName >> capPower){
            vectorCapTotalCsv.push_back(new Capacite());
            vectorCapTotalCsv[i]->setId(capId);
            vectorCapTotalCsv[i]->setNom(capName);
            vectorCapTotalCsv[i]->setPuissance(capPower/2);
            //cout<<vectorCapTotalCsv[i]->getId()<<" "<<vectorCapTotalCsv[i]->getNom()<<" "<<vectorCapTotalCsv[i]->getPuissance()<<"\n"<<endl;
            i++;
        }
        for(short n=0; n<4; n++){
            bool validBoucleInterne;
            bool capOk = false;
            while(!capOk){
                validBoucleInterne = true;
                tabCapacites[n] = vectorCapTotalCsv[rand()%(vectorCapTotalCsv.size()-1)+1];
                for(int g = tailleTabCapCodeur; g >= 0 && validBoucleInterne;g--){
                    if(n!=g){
                        if(this->tabCapacites[n]->getId()!=this->tabCapacites[g]->getId()){}
                        else{
                            validBoucleInterne = false;
                        }
                    }
                }
                if(validBoucleInterne){
                    capOk = true;
                    //cout<<id<<" "<<tabCapacites[n]->getId()<<" "<<tabCapacites[n]->getNom()<<" "<<tabCapacites[n]->getPuissance()<<"\n"<<endl;
                }
            }
        }
    }
    else{
        cerr<<"ERROR: The file isnt open.\n";
    }
}

Codeur::~Codeur()
{
    //dtor
}

float Codeur::getPoucentageSkill(){
    return this->pourcentageSkill;
}

void Codeur::setPourcentageSkill(float percentage){
    this->pourcentageSkill=percentage;
}

Capacite* Codeur::getCapacite(short n){
    return this->tabCapacites[n];
}

void Codeur::setCapacite(short place, Capacite* cap){
    this->tabCapacites[place]=cap;
}
