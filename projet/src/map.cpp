#include "map.h"
#include "Codeur.h"
#include "stdlib.h"

using namespace std;

Map::Map()
{
    this->c=new Zone();
    this->c->setType("c");

    this->cSharp=new Zone();
    this->cSharp->setType("cSharp");

    this->php=new Zone();
    this->php->setType("php");

    this->jS=new Zone();
    this->jS->setType("jS");

    this->cPP=new Zone();
    this->cPP->setType("cPP");

    this->java=new Zone();
    this->java->setType("java");

    this->epsi=new Zone();
    this->epsi->setType("epsi");

    this->html1=new Zone();
    this->html1->setType("html");
    this->html2=new Zone();
    this->html2->setType("html");
    this->html3=new Zone();
    this->html3->setType("html");
    this->html4=new Zone();
    this->html4->setType("html");
    this->html5=new Zone();
    this->html5->setType("html");

    this->scratch1=new Zone();
    this->scratch1->setType("scratch");
    this->scratch2=new Zone();
    this->scratch2->setType("scratch");
    this->scratch3=new Zone();
    this->scratch3->setType("scratch");

    this->zoneVide1=new Zone();
    this->zoneVide1->setType("vide");
    this->zoneVide2=new Zone();
    this->zoneVide2->setType("vide");
    this->zoneVide3=new Zone();
    this->zoneVide3->setType("vide");
    this->zoneVide4=new Zone();
    this->zoneVide4->setType("vide");
    this->zoneVide5=new Zone();
    this->zoneVide5->setType("vide");
    this->zoneVide6=new Zone();
    this->zoneVide6->setType("vide");
    this->zoneVide7=new Zone();
    this->zoneVide7->setType("vide");
    this->zoneVide8=new Zone();
    this->zoneVide8->setType("vide");
    this->zoneVide9=new Zone();
    this->zoneVide9->setType("vide");
    this->zoneVide10=new Zone();
    this->zoneVide10->setType("vide");
    this->zoneVide11=new Zone();
    this->zoneVide11->setType("vide");
    //allocation de mémoire et attribution des types pour les zones de la map

    //taille de la map
    this->xMin = 0;
    this->xMax = 170;
    this->yMin = 0;
    this->yMax = 115;

    //taille zone c
    c->setXmin(150);
    c->setXmax(170);
    c->setYmin(0);
    c->setYmax(15);

    //taille zone cSarp
    cSharp->setXmin(0);
    cSharp->setXmax(10);
    cSharp->setXmin(105);
    cSharp->setYmax(115);

    //taille zone php
    php->setXmin(147);
    php->setXmax(170);
    php->setYmin(98);
    php->setYmax(115);

    //taille zone jS
    jS->setXmin(0);
    jS->setXmax(10);
    jS->setYmin(0);
    jS->setYmax(10);

    //taille zone cPP
    cPP->setXmin(87);
    cPP->setXmax(112);
    cPP->setYmin(105);
    cPP->setYmax(115);

    //taille zone java
    java->setXmin(70);
    java->setXmax(95);
    java->setYmin(0);
    java->setYmax(12);

    //taille zone epsi
    epsi->setXmin(61);
    epsi->setXmax(97);
    epsi->setYmin(46);
    epsi->setYmax(72);

    //taille zone html1
    html1->setXmin(150);
    html1->setXmax(170);
    html1->setYmin(36);
    html1->setYmax(98);

    //taille zone html2
    html2->setXmin(120);
    html2->setXmax(150);
    html2->setYmin(72);
    html2->setYmax(98);

    //taille zone html3
    html3->setXmin(112);
    html3->setXmax(147);
    html3->setYmin(93);
    html3->setYmax(115);

    //taille zone html4
    html4->setXmin(82);
    html4->setXmax(121);
    html4->setYmin(93);
    html4->setYmax(105);

    //taille zone html5
    html5->setXmin(82);
    html5->setXmax(87);
    html5->setYmin(93);
    html5->setYmax(115);

    //taille zone scratch1
    scratch1->setXmin(0);
    scratch1->setXmax(26);
    scratch1->setYmin(33);
    scratch1->setYmax(105);

    //taille zone scratch2
    scratch2->setXmin(10);
    scratch2->setXmax(40);
    scratch2->setYmin(95);
    scratch2->setYmax(115);

    //taille zone scratch3
    scratch3->setXmin(26);
    scratch3->setXmax(53);
    scratch3->setYmin(55);
    scratch3->setYmax(95);

    //taille zone zoneVide1
    //Corrigée
    this->zoneVide1->setXmin(0);
    this->zoneVide1->setXmax(10);
    this->zoneVide1->setYmin(11);
    this->zoneVide1->setYmax(32);

    //taille zone zoneVide2
    //Corrigée
    this->zoneVide2->setXmin(11);
    this->zoneVide2->setXmax(79);
    this->zoneVide2->setYmin(0);
    this->zoneVide2->setYmax(32);

    //taille zone zoneVide3
    //Corrigée
    this->zoneVide3->setXmin(27);
    this->zoneVide3->setXmax(60);
    this->zoneVide3->setYmin(33);
    this->zoneVide3->setYmax(54);

    //taille zone zoneVide4
    //Corrigée
    this->zoneVide4->setXmin(61);
    this->zoneVide4->setXmax(97);
    this->zoneVide4->setYmin(13);
    this->zoneVide4->setYmax(45);

    //taille zone zoneVide5
    //Corrigée
    this->zoneVide5->setXmin(98);
    this->zoneVide5->setXmax(149);
    this->zoneVide5->setYmin(0);
    this->zoneVide5->setYmax(45);

    //taille zone zoneVide6
    //Corrigée
    this->zoneVide6->setXmin(150);
    this->zoneVide6->setXmax(170);
    this->zoneVide6->setYmin(16);
    this->zoneVide6->setYmax(35);

    //taille zone zoneVide7
    //Corrigée
    this->zoneVide7->setXmin(98);
    this->zoneVide7->setXmax(149);
    this->zoneVide7->setYmin(35);
    this->zoneVide7->setYmax(71);

    //taille zone zoneVide8
    //Corrigée
    this->zoneVide8->setXmin(54);
    this->zoneVide8->setXmax(119);
    this->zoneVide8->setYmin(71);
    this->zoneVide8->setYmax(92);

    //taille zone zoneVide9
    //Corrigée
    this->zoneVide9->setXmin(54);
    this->zoneVide9->setXmax(60);
    this->zoneVide9->setYmin(55);
    this->zoneVide9->setYmax(115);

    //taille zone zoneVide10
    //Corrigée
    this->zoneVide10->setXmin(41);
    this->zoneVide10->setXmax(81);
    this->zoneVide10->setYmin(96);
    this->zoneVide10->setYmax(115);

    //taille zone zoneVide11
    //Corrigée
    this->zoneVide11->setXmin(54);
    this->zoneVide11->setXmax(81);
    this->zoneVide11->setYmin(93);
    this->zoneVide11->setYmax(95);

    unsigned int randCodeurs = rand()%20+20;

    this->generationCodeursSauvages(randCodeurs);
    this->generationIngenieurs(randCodeurs);
}

Map::~Map()
{
    //dtor
}

void Map::generationCodeursSauvages(unsigned int randCodeurs){
    this->vectorCodeursSauvage.push_back(new CodeurSauvage());
    for(unsigned int i=0; i<randCodeurs; i++){
        bool valid = false;
        bool validBoucleInterne = true;
        while(!valid){
            CodeurSauvage* sauvage = new CodeurSauvage();
            for(int n = this->vectorCodeursSauvage.size() - 1; n >= 0 && validBoucleInterne;n--){
                if(!this->vectorCodeursSauvage[n]->estALinterieurDeToi(sauvage->getXMin(),sauvage->getXMax(),sauvage->getYMin(),sauvage->getYMax())-5){}
                else{
                    validBoucleInterne = false;
                }
            }
            if(validBoucleInterne){
                    valid = true;
                    this->vectorCodeursSauvage.push_back(sauvage);
            }
            //cout<<sauvage->getCodeurReference()->getId()<<" "<<sauvage->getXMin()<<" "<<sauvage->getXMax()<<" "<<sauvage->getYMin()<<" "<<sauvage->getYMax()<<"\n";
        }
    }
}


void Map::generationIngenieurs(unsigned int randCodeurs){
    this->vectorIngenieursSauvage.push_back(new Ingenieur());
    for(unsigned int i=0; i<randCodeurs/2; i++){
        bool valid = false;
        bool validBoucleInterne = true;
        bool validIngenieurNonSuperposeCodeur = true;
        while(!valid){
            Ingenieur* sauvage = new Ingenieur();
            for(int n = this->vectorIngenieursSauvage.size() - 1; n >= 0 && validBoucleInterne; n--){ //vérif que les ingénieur ne se superposent pas entre eux
                if((!this->vectorIngenieursSauvage[n]->estALinterieurDeToi(sauvage->getXMin(),sauvage->getXMax(),sauvage->getYMin(),sauvage->getYMax())-5)){
                    for(int tour=this->vectorCodeursSauvage.size() - 1; tour>= 0 && validIngenieurNonSuperposeCodeur; tour--){//vérif que les ingénieur ne se superposent pas aux codeurs
                        if(!this->vectorCodeursSauvage[tour]->estALinterieurDeToi(sauvage->getXMin(),sauvage->getXMax(),sauvage->getYMin(),sauvage->getYMax())-5){}
                        else{
                            validIngenieurNonSuperposeCodeur = false;
                        }
                    }
                }
                else{
                    validBoucleInterne = false;
                }
            }
            if(validBoucleInterne && validIngenieurNonSuperposeCodeur){
                    valid = true;
                    this->vectorIngenieursSauvage.push_back(sauvage);
            }
            //cout<<"\n\n"<<sauvage->getId()<<" "<<sauvage->getXMin()<<" "<<sauvage->getXMax()<<" "<<sauvage->getYMin()<<" "<<sauvage->getYMax()<<"\n";
        }
    }
}

CodeurSauvage* Map::getVectorCodeursSauvage(int i){
    return this->vectorCodeursSauvage[i];
}

Ingenieur* Map::getVectorIngenieursSauvage(int i){
    return this->vectorIngenieursSauvage[i];
}

void Map::replaceVectorCodeursSauvage(int i){
    this->vectorCodeursSauvage[i]=new CodeurSauvage();
}

void Map::replaceVectorIngenieursSauvage(int i){
    this->vectorIngenieursSauvage[i]=new Ingenieur();
}

unsigned int Map::getSizeVectorCodeursSauvage(){
    return this->vectorCodeursSauvage.size();
}

unsigned int Map::getSizeVectorIngenieursSauvage(){
    return this->vectorIngenieursSauvage.size();
}


