#include "Zone.h"

Zone::Zone()
{
    //ctor
}

Zone::~Zone()
{
    //dtor
}

string Zone::getType(){
    return this->typeZone;
}

void Zone::setType(string type){
    this->typeZone=type;
}

unsigned short int Zone::getXmin(){
    return this->xMin;
}

unsigned short int Zone::getYmin(){
    return this->yMin;
}

unsigned short int Zone::getXmax(){
    return this->xMax;
}

unsigned short int Zone::getYmax(){
    return this->yMax;
}

void Zone::setXmin(unsigned int value){
    this->xMin=value;
}

void Zone::setYmin(unsigned int value){
    this->yMin=value;
}

void Zone::setXmax(unsigned int value){
    this->xMax=value;
}

void Zone::setYmax(unsigned int value){
    this->yMax=value;
}
