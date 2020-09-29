#include "CodeurSauvage.h"
#include "time.h"
#include "stdlib.h"

CodeurSauvage::CodeurSauvage()
{
    this->codeurReference=new Codeur();
    int coordValid = 0;
    while(coordValid!=1){
        setXMin(rand()%170);
        setXMax(this->xMin+4);
        setYMin(rand()%115);
        setYMax(this->yMin+4);
        if((this->xMin>95&&this->yMin>12)||(this->xMax<70&&this->yMax>12)){
            coordValid=1;
        }
    } //Boucle d'anti spawn des codeurs dans la zona de java
    if((this->getXMin() >= 150 && this->getYMin() >= 0)  && (this->getXMax() <= 170 && this->getYMax() <= 15)){
        this->getCodeurReference()->setTypeSkill("C");
    }
    else if((this->getXMin() >= 0 && this->getYMin() >= 105)  && (this->getXMax() <= 10 && this->getYMax() <= 115)){
        this->getCodeurReference()->setTypeSkill("CSharp");
    }
    else if((this->getXMin() >= 147 && this->getYMin() >= 98)  && (this->getXMax() <= 170 && this->getYMax() <= 115)){
        this->getCodeurReference()->setTypeSkill("PHP");
    }
    else if((this->getXMin() >= 0 && this->getYMin() >= 0)  && (this->getXMax() <= 10 && this->getYMax() <= 10)){
        this->getCodeurReference()->setTypeSkill("JS");
    }
    else if((this->getXMin() >= 87 && this->getYMin() >= 105)  && (this->getXMax() <= 112 && this->getYMax() <= 115)){
        this->getCodeurReference()->setTypeSkill("CPP");
    }
    else if((this->getXMin() >= 70 && this->getYMin() >= 0)  && (this->getXMax() <= 95 && this->getYMax() <= 12)){
        this->getCodeurReference()->setTypeSkill("Java");
    }
    else if((this->getXMin() >= 61 && this->getYMin() >= 46)  && (this->getXMax() <= 97 && this->getYMax() <= 72)){
        this->getCodeurReference()->setTypeSkill("EPSI");
    }
    else if((this->getXMin() >= 150 && this->getYMin() >= 36)  && (this->getXMax() <= 170 && this->getYMax() <= 98)){
        this->getCodeurReference()->setTypeSkill("HTML");
    }
    else if((this->getXMin() >= 120 && this->getYMin() >= 72)  && (this->getXMax() <= 150 && this->getYMax() <= 98)){
        this->getCodeurReference()->setTypeSkill("HTML");
    }
    else if((this->getXMin() >= 112 && this->getYMin() >= 93)  && (this->getXMax() <= 147 && this->getYMax() <= 115)){
        this->getCodeurReference()->setTypeSkill("HTML");
    }
    else if((this->getXMin() >= 82 && this->getYMin() >= 93)  && (this->getXMax() <= 121 && this->getYMax() <= 105)){
        this->getCodeurReference()->setTypeSkill("HTML");
    }
    else if((this->getXMin() >= 82 && this->getYMin() >= 93)  && (this->getXMax() <= 87 && this->getYMax() <= 115)){
        this->getCodeurReference()->setTypeSkill("HTML");
    }
    else if((this->getXMin() >= 0 && this->getYMin() >= 33)  && (this->getXMax() <= 26 && this->getYMax() <= 105)){
        this->getCodeurReference()->setTypeSkill("Scratch");
    }
    else if((this->getXMin() >= 10 && this->getYMin() >= 95)  && (this->getXMax() <= 40 && this->getYMax() <= 115)){
        this->getCodeurReference()->setTypeSkill("Scratch");
    }
    else if((this->getXMin() >= 26 && this->getYMin() >= 55) && (this->getXMax() <= 53 && this->getYMax() <= 95)){
        this->getCodeurReference()->setTypeSkill("Scratch");
    }
    else{
        this->getCodeurReference()->setTypeSkill("Omni");
    }
}

CodeurSauvage::~CodeurSauvage()
{
    //dtor
}

int CodeurSauvage::getXMin(){
    return this->xMin;
}

void CodeurSauvage::setXMin(unsigned int value){
    this->xMin=value;
}

int CodeurSauvage::getYMin(){
    return this->yMin;
}

void CodeurSauvage::setYMin(unsigned int value){
    this->yMin=value;
}

int CodeurSauvage::getXMax(){
    return this->xMax;
}

void CodeurSauvage::setXMax(unsigned int value){
    this->xMax=value;
}

int CodeurSauvage::getYMax(){
    return this->yMax;
}

void CodeurSauvage::setYMax(unsigned int value){
    this->yMax=value;
}

Codeur* CodeurSauvage::getCodeurReference(){
    return this->codeurReference;
}

bool CodeurSauvage::estALinterieurDeToi(int xMin, int xMax, int yMin, int yMax){
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
