#include "Ingenieur.h"
#include "stdlib.h"
#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <vector>
#include "windows.h"
using namespace std;


Ingenieur::Ingenieur()
{
    this->setMontantArgent(2000);
    unsigned int teamSize = rand()%2+1;
    if(this->id/*!=0*/){
        for(unsigned int i=0;i<teamSize;i++){
            this->equipe.push_back(new Codeur());
        }
    }
    this->nombreCodeurs=teamSize;
    int coordValid = 0;
    while(coordValid!=1){
        this->setXMin(rand()%170);
        setXMax(this->xMin+4);
        setYMin(rand()%115);
        setYMax(this->yMin+4);
        if((this->xMin>95&&this->yMin>12)||(this->xMax<70&&this->yMax>12)){
            coordValid=1;
        }
    } //Boucle d'anti spawn des ingénieurs dans la zona de java

    this->assignationZoneCap();

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
            vectorCapTotalCsv[i]->setPuissance(capPower);
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

Ingenieur::~Ingenieur()
{
    //dtor
}

unsigned long Ingenieur::getForceC(){
    return this->forceC;
}

void Ingenieur::setForceC(unsigned int value){
    this->forceC=value;
}

unsigned long Ingenieur::getForceJava(){
    return this->forceJava;
}

void Ingenieur::setForceJava(unsigned int value){
    this->forceJava=value;
}

unsigned long Ingenieur::getForceCPP(){
    return this->forceCPP;
}

void Ingenieur::setForceCPP(unsigned int value){
    this->forceCPP=value;
}

unsigned long Ingenieur::getForceHtmlCss(){
    return this->forceHtmlCss;
}

void Ingenieur::setForceHtmlCss(unsigned int value){
    this->forceHtmlCss=value;
}

unsigned long Ingenieur::getForcePhp(){
    return this->forcePhp;
}

void Ingenieur::setForcePhp(unsigned int value){
    this->forcePhp=value;
}

unsigned long Ingenieur::getForceCSharp(){
    return this->forceCSharp;
}

void Ingenieur::setForceCSharp(unsigned int value){
    this->forceCSharp=value;
}

unsigned long Ingenieur::getForceScratch(){
    return this->forceScratch;
}

void Ingenieur::setForceScratch(unsigned int value){
    this->forceScratch=value;
}

unsigned long Ingenieur::getForceJavaScript(){
    return this->forceJavaScript;
}

void Ingenieur::setForceJavaScript(unsigned int value){
    this->forceJavaScript=value;
}

Codeur* Ingenieur::getEquipeIndexN(unsigned int n){
    return equipe[n];
}

void Ingenieur::addEquipe(Codeur* codeur){
    this->equipe.push_back(codeur);
    this->nombreCodeurs=nombreCodeurs+1;
}

int Ingenieur::getXMin(){
    return this->xMin;
}

void Ingenieur::setXMin(unsigned int value){
    this->xMin=value;
}

int Ingenieur::getYMin(){
    return this->yMin;
}

void Ingenieur::setYMin(unsigned int value){
    this->yMin=value;
}

int Ingenieur::getXMax(){
    return this->xMax;
}

void Ingenieur::setXMax(unsigned int value){
    this->xMax=value;
}

int Ingenieur::getYMax(){
    return this->yMax;
}

void Ingenieur::setYMax(unsigned int value){
    this->yMax=value;
}

unsigned int Ingenieur::getMontantArgent(){
    return this->montantArgent;
}

void Ingenieur::setMontantArgent(unsigned int montantArgent){
    this->montantArgent=montantArgent;
}

bool Ingenieur::estALinterieurDeToi(int xMin, int xMax, int yMin, int yMax){
    bool retour;
    if(((xMax>=this->xMin && xMax<=this->xMax)||(xMin>=this->xMin && xMin<=this->xMax)) &&
       ((yMax>=this->yMin && yMax<=this->yMax)||(yMin>=this->yMin && yMin<=this->yMax))){
        retour=1;
    }
    else{
        retour=0;
    }
    return retour;
}


void Ingenieur::moveUp(int num){
    this->setYMin(this->getYMin()-num);
    this->setYMax(this->getYMax()-num);
    this->coordUpdate();
}

void Ingenieur::moveDown(int num){
    this->setYMin(this->getYMin()+num);
    this->setYMax(this->getYMax()+num);
    this->coordUpdate();
}

void Ingenieur::moveLeft(int num){
    this->setXMin(this->getXMin()-num);
    this->setXMax(this->getXMax()-num);
    this->coordUpdate();
}

void Ingenieur::moveRight(int num){
    this->setXMin(this->getXMin()+num);
    this->setXMax(this->getXMax()+num);
    this->coordUpdate();
}

unsigned int Ingenieur::getTeamSize(){
    return this->nombreCodeurs;
}

Capacite* Ingenieur::getCapacite(short n){
    return this->tabCapacites[n];
}

void Ingenieur::setCapacite(short place, Capacite* cap){
    this->tabCapacites[place]=cap;
}

void Ingenieur::assignationZoneCap(){
    if((this->getXMin() >= 150 && this->getYMin() >= 0)  && (this->getXMax() <= 170 && this->getYMax() <= 15)){
        //cout<<"Ingénieur dans la zone c"<<endl;
        this->forceC=rand()%30+20;
    }
    else if((this->getXMin() >= 0 && this->getYMin() >= 105)  && (this->getXMax() <= 10 && this->getYMax() <= 115)){
        //cout<<"Ingénieur dans la zone cSharp"<<endl;
        this->forceCSharp=rand()%30+20;
    }
    else if((this->getXMin() >= 147 && this->getYMin() >= 98)  && (this->getXMax() <= 170 && this->getYMax() <= 115)){
        //cout<<"Ingénieur dans la zone PHP"<<endl;
        this->forcePhp=rand()%30+20;
    }
    else if((this->getXMin() >= 0 && this->getYMin() >= 0)  && (this->getXMax() <= 10 && this->getYMax() <= 10)){
        //cout<<"Ingénieur dans la zone js"<<endl;
        this->forceJavaScript=rand()%30+20;
    }
    else if((this->getXMin() >= 87 && this->getYMin() >= 105)  && (this->getXMax() <= 112 && this->getYMax() <= 115)){
        //cout<<"Ingénieur dans la zone cPP"<<endl;
        this->forceCPP=rand()%30+20;
    }
    else if((this->getXMin() >= 70 && this->getYMin() >= 0)  && (this->getXMax() <= 95 && this->getYMax() <= 12)){
        //cout<<"Ingénieur dans la zone java"<<endl;
        this->forceJava=rand()%30+70;
    }
    else if((this->getXMin() >= 61 && this->getYMin() >= 46)  && (this->getXMax() <= 97 && this->getYMax() <= 72)){
        //cout<<"Ingénieur dans la zone EPSI"<<endl;
        this->forceC=rand()%30+20;
        this->forceCPP=rand()%30+20;
        this->forceCSharp=rand()%30+20;
        this->forceHtmlCss=rand()%30+20;
        this->forceJavaScript=rand()%30+20;
        this->forcePhp=rand()%30+20;
        this->forceScratch=rand()%30+20;
    }
    else if((this->getXMin() >= 150 && this->getYMin() >= 36)  && (this->getXMax() <= 170 && this->getYMax() <= 98)){
        //cout<<"Ingénieur dans la zone html(1)"<<endl;
        this->forceHtmlCss=rand()%30+20;
    }
    else if((this->getXMin() >= 120 && this->getYMin() >= 72)  && (this->getXMax() <= 150 && this->getYMax() <= 98)){
        //cout<<"Ingénieur dans la zone html(2)"<<endl;
        this->forceHtmlCss=rand()%30+20;
    }
    else if((this->getXMin() >= 112 && this->getYMin() >= 93)  && (this->getXMax() <= 147 && this->getYMax() <= 115)){
        //cout<<"Ingénieur dans la zone html(3)"<<endl;
        this->forceHtmlCss=rand()%30+20;
    }
    else if((this->getXMin() >= 82 && this->getYMin() >= 93)  && (this->getXMax() <= 121 && this->getYMax() <= 105)){
        //cout<<"Ingénieur dans la zone html(4)"<<endl;
        this->forceHtmlCss=rand()%30+20;
    }
    else if((this->getXMin() >= 82 && this->getYMin() >= 93)  && (this->getXMax() <= 87 && this->getYMax() <= 115)){
        //cout<<"Ingénieur dans la zone html(5)"<<endl;
        this->forceHtmlCss=rand()%30+20;
    }
    else if((this->getXMin() >= 0 && this->getYMin() >= 33)  && (this->getXMax() <= 26 && this->getYMax() <= 105)){
        //cout<<"Ingénieur dans la zone scratch(1)"<<endl;
        this->forceScratch=rand()%30+20;
    }
    else if((this->getXMin() >= 10 && this->getYMin() >= 95)  && (this->getXMax() <= 40 && this->getYMax() <= 115)){
        //cout<<"Ingénieur dans la zone scratch(2)"<<endl;
        this->forceScratch=rand()%30+20;
    }
    else if((this->getXMin() >= 26 && this->getYMin() >= 55) && (this->getXMax() <= 53 && this->getYMax() <= 95)){
        //cout<<"Ingénieur dans la zone scratch(3)"<<endl;
        this->forceScratch=rand()%30+20;
    }
    else{
        //cout<<"Ingénieur dans la zone vide"<<endl;
        this->forceC=rand()%10+5;
        this->forceCPP=rand()%10+5;
        this->forceCSharp=rand()%10+5;
        this->forceHtmlCss=rand()%10+5;
        this->forceJavaScript=rand()%10+5;
        this->forcePhp=rand()%10+5;
        this->forceScratch=rand()%10+5;
    }
}

void Ingenieur::coordUpdate(){
    system("cls");
    if(this->getVie()<=0){
        cout<<"                                       ___           ___           ___           ___                       "<<endl;
        cout<<"                                      /\\  \\         /\\  \\         /\\__\\         /\\  \\              "<<endl;
        cout<<"                                     /::\\  \\       /::\\  \\       /::|  |       /::\\  \\               "<<endl;
        cout<<"                                    /:/\\:\\  \\     /:/\\:\\  \\     /:|:|  |      /:/\\:\\  \\           "<<endl;
        cout<<"                                   /:/  \\:\\  \\   /::\\~\\:\\  \\   /:/|:|__|__   /::\\~\\:\\  \\        "<<endl;
        cout<<"                                  /:/__/_\\:\\__\\ /:/\\:\\ \\:\\__\\ /:/ |::::\\__\\ /:/\\:\\ \\:\\__\\   "<<endl;
        cout<<"                                  \\:\\  /\\ \\/__/ \\/__\\:\\/:/  / \\/__/~~/:/  / \\:\\~\\:\\ \\/__/     "<<endl;
        cout<<"                                   \\:\\ \\:\\__\\        \\::/  /        /:/  /   \\:\\ \\:\\__\\         "<<endl;
        cout<<"                                    \\:\\/:/  /        /:/  /        /:/  /     \\:\\ \\/__/               "<<endl;
        cout<<"                                     \\::/  /        /:/  /        /:/  /       \\:\\__\\                  "<<endl;
        cout<<"                                      \\/__/         \\/__/         \\/__/         \\/__/                  "<<endl;
        cout<<"                                      ___           ___           ___           ___                        "<<endl;
        cout<<"                                     /\\  \\         /\\__\\         /\\  \\         /\\  \\               "<<endl;
        cout<<"                                    /::\\  \\       /:/  /        /::\\  \\       /::\\  \\                "<<endl;
        cout<<"                                   /:/\\:\\  \\     /:/  /        /:/\\:\\  \\     /:/\\:\\  \\            "<<endl;
        cout<<"                                  /:/  \\:\\  \\   /:/__/  ___   /::\\~\\:\\  \\   /::\\~\\:\\  \\         "<<endl;
        cout<<"                                 /:/__/ \\:\\__\\  |:|  | /\\__\\ /:/\\:\\ \\:\\__\\ /:/\\:\\ \\:\\__\\    "<<endl;
        cout<<"                                 \\:\\  \\ /:/  /  |:|  |/:/  / \\:\\~\\:\\ \\/__/ \\/_|::\\/:/  /         "<<endl;
        cout<<"                                  \\:\\  /:/  /   |:|__/:/  /   \\:\\ \\:\\__\\      |:|::/  /             "<<endl;
        cout<<"                                   \\:\\/:/  /     \\::::/__/     \\:\\ \\/__/      |:|\\/__/              "<<endl;
        cout<<"                                    \\::/  /       ~~~~          \\:\\__\\        |:|  |                   "<<endl;
        cout<<"                                     \\/__/                       \\/__/         \\|__|                    \n\n\n\n"<<endl;
        exit(0);
    }
        string text = "Pas de zone";
    if((this->getXMin() >= 150 && this->getYMin() >= 0)  && (this->getXMax() <= 170 && this->getYMax() <= 15)){
        //cout<<"Ingénieur dans la zone c"<<endl;
        text = "C";
    }
    else if((this->getXMin() >= 0 && this->getYMin() >= 105)  && (this->getXMax() <= 10 && this->getYMax() <= 115)){
        //cout<<"Ingénieur dans la zone cSharp"<<endl;
        text = "CSharp";
    }
    else if((this->getXMin() >= 147 && this->getYMin() >= 98)  && (this->getXMax() <= 170 && this->getYMax() <= 115)){
        //cout<<"Ingénieur dans la zone PHP"<<endl;
        text = "PHP";
    }
    else if((this->getXMin() >= 0 && this->getYMin() >= 0)  && (this->getXMax() <= 10 && this->getYMax() <= 10)){
        //cout<<"Ingénieur dans la zone js"<<endl;
        text = "JavaScript";
    }
    else if((this->getXMin() >= 87 && this->getYMin() >= 105)  && (this->getXMax() <= 112 && this->getYMax() <= 115)){
        //cout<<"Ingénieur dans la zone cPP"<<endl;
        text = "C++";
    }
    else if((this->getXMin() >= 70 && this->getYMin() >= 0)  && (this->getXMax() <= 95 && this->getYMax() <= 12)){
        //cout<<"Ingénieur dans la zone java"<<endl;
        text = "Java";
    }
    else if((this->getXMin() >= 61 && this->getYMin() >= 46)  && (this->getXMax() <= 97 && this->getYMax() <= 72)){
        //cout<<"Ingénieur dans la zone EPSI"<<endl;
        text = "EPSI";
    }
    else if((this->getXMin() >= 150 && this->getYMin() >= 36)  && (this->getXMax() <= 170 && this->getYMax() <= 98)){
        //cout<<"Ingénieur dans la zone html(1)"<<endl;
        text = "Html/Css";
    }
    else if((this->getXMin() >= 120 && this->getYMin() >= 72)  && (this->getXMax() <= 150 && this->getYMax() <= 98)){
        //cout<<"Ingénieur dans la zone html(2)"<<endl;
        text = "Html/Css";
    }
    else if((this->getXMin() >= 112 && this->getYMin() >= 93)  && (this->getXMax() <= 147 && this->getYMax() <= 115)){
        //cout<<"Ingénieur dans la zone html(3)"<<endl;
        text = "Html/Css";
    }
    else if((this->getXMin() >= 82 && this->getYMin() >= 93)  && (this->getXMax() <= 121 && this->getYMax() <= 105)){
        //cout<<"Ingénieur dans la zone html(4)"<<endl;
        text = "Html/Css";
    }
    else if((this->getXMin() >= 82 && this->getYMin() >= 93)  && (this->getXMax() <= 87 && this->getYMax() <= 115)){
        //cout<<"Ingénieur dans la zone html(5)"<<endl;
        text = "Html/Css";
    }
    else if((this->getXMin() >= 0 && this->getYMin() >= 33)  && (this->getXMax() <= 26 && this->getYMax() <= 105)){
        //cout<<"Ingénieur dans la zone scratch(1)"<<endl;
        text = "Scratch";
    }
    else if((this->getXMin() >= 10 && this->getYMin() >= 95)  && (this->getXMax() <= 40 && this->getYMax() <= 115)){
        //cout<<"Ingénieur dans la zone scratch(2)"<<endl;
        text = "Scratch";
    }
    else if((this->getXMin() >= 26 && this->getYMin() >= 55) && (this->getXMax() <= 53 && this->getYMax() <= 95)){
        //cout<<"Ingénieur dans la zone scratch(3)"<<endl;
        text = "Scratch";
    }
    else{
        //cout<<"Ingénieur dans la zone vide"<<endl;
        text = "vide";
    }
    cout<<"Coordonnees : "<<"|Bords de map :                        "<<"PV : "<<this->getVie()<<" | Argent : "<<this->getMontantArgent()<<"                            (E) -> Menu"<<endl;
    cout<<"  xMin : "<<this->getXMin()<<"   |  xMin : 0                                                                               (Z) -> Avancer"<<endl;
    cout<<"  xMax : "<<this->getXMax()<<"   |  xMax : 170                                                                             (S) -> Reculer"<<endl;
    cout<<"  yMin : "<<this->getYMin()<<"   |  yMin : 0                                                                               (Q) -> Gauche"<<endl;
    cout<<"  yMax : "<<this->getYMax()<<"   |  yMax : 115                                                                             (D) -> Droite"<<endl;
    cout<<"\n  Zone : "<<text<<endl;
}

vector<Codeur*> Ingenieur::returnVectorEquipe(){
    return this->equipe;
}
