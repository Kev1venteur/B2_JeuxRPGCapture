#include "Jeux.h"
#include "map.h"
#include "Codeur.h"
#include "stdlib.h"
#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "Personne.h"
#include "windows.h"
#include <conio.h>
#include <limits>

#define         SPRITE_SPEED        1

using namespace std;

Jeux::Jeux()
{
    srand(time(NULL));
    this->monJoueur = new Ingenieur();
    this->maMap = new Map();
}

Jeux::~Jeux()
{
    //dtor
}

void Jeux::jouer(){
monJoueur->setForceC(0);
monJoueur->setForceCPP(0);
monJoueur->setForceJavaScript(0);
monJoueur->setForceHtmlCss(0);
monJoueur->setForcePhp(0);
monJoueur->setForceCSharp(0);
monJoueur->setForceScratch(0);
monJoueur->setVie(200);
monJoueur->setMontantArgent(2000);
while(monJoueur->getVie()>0){
    system("cls");
    //cout<<"A toi de jouer:\n\n"<<"Z: Avancer"<<"\nQ: Gauche"<<"\nS: Reculer"<<"\nD: Droite\n"<<"E: Menu\n"<<endl;
    monJoueur->coordUpdate();
    bool fin = false;
    while(!fin){
        bool KeyPressed=false;
        while(!KeyPressed){
            char key = getch(); //getchar() va permettre de faire plusieur mouvements d'un coup et est portable, mais moins fun /////// et getche() == getch() + echo de la lettre tapée
            if(key == 'z' || key == 'Z'){
                monJoueur->moveUp(1);
                KeyPressed=true;
                if(this->testOfBoundaries()){
                    monJoueur->moveDown(3);
                }
            }
            else if(key == 'q' || key == 'Q'){
                monJoueur->moveLeft(1);
                KeyPressed=true;
                if(this->testOfBoundaries()){
                    monJoueur->moveRight(3);
                }
            }
            else if(key == 's' || key == 'S'){
                monJoueur->moveDown(1);
                KeyPressed=true;
                if(this->testOfBoundaries()){
                    monJoueur->moveUp(3);
                }
            }
            else if(key == 'd' || key == 'D'){
                monJoueur->moveRight(1);
                KeyPressed=true;
                if(this->testOfBoundaries()){
                    monJoueur->moveLeft(3);
                }
            }
            else if(key == 'e' || key == 'E'){
                KeyPressed=true;
                this->menu();
            }
        }
        if(this->testCollisionMonJoueur()){
            this->combat();
            fin = true;
            cout<<"\nAppuyez sur entree pour continuer...";
            getchar();
        }
        Sleep(100);
    }
}
}

bool Jeux::testCollisionMonJoueur(){
    this->numCodeurCombat=0;
    this->numIngenieurCombat=0;
    bool collision = false;
    for(unsigned int n = 0; n<maMap->getSizeVectorCodeursSauvage(); n++){ //collision avec codeur sauvage
        if(monJoueur->estALinterieurDeToi(maMap->getVectorCodeursSauvage(n)->getXMin(),
                                          maMap->getVectorCodeursSauvage(n)->getXMax(),
                                          maMap->getVectorCodeursSauvage(n)->getYMin(),
                                          maMap->getVectorCodeursSauvage(n)->getYMax())){
            collision=true;
            cout<<"\n\nCollision! Combat engage avec un Codeur sauvage.\n";
            Sleep(1000);
            this->numCodeurCombat=n;
        }
    }

    for(unsigned int n = 0; n<maMap->getSizeVectorIngenieursSauvage(); n++){ //collision avec Ingenieur sauvage
        if(monJoueur->estALinterieurDeToi(maMap->getVectorIngenieursSauvage(n)->getXMin(),
                                          maMap->getVectorIngenieursSauvage(n)->getXMax(),
                                          maMap->getVectorIngenieursSauvage(n)->getYMin(),
                                          maMap->getVectorIngenieursSauvage(n)->getYMax())){
            collision=true;
            cout<<"\n\nCollision! Combat engage avec un Ingenieur.\n";
            Sleep(1000);
            this->numIngenieurCombat=n;
        }
    }
    return collision;
}

bool Jeux::testOfBoundaries(){
    bool outBoundaries = false;
    if(monJoueur->getXMax()>=171 || monJoueur->getXMin()<=(-1) || monJoueur->getYMax()>=116 || monJoueur->getYMin()<=(-1)){
        outBoundaries = true;
        //cout<<"\n\nHors des frontieres!\n\n";
    }
    return outBoundaries;
}

void Jeux::combat(){
    bool dead = false;
    //system("cls"); //effacer la console sous windows, "clear" sous linux
    system("cls");
    monJoueur->coordUpdate();
    if(this->numIngenieurCombat!=0){
        cout<<"\n\nL adversaire possede: "<<maMap->getVectorIngenieursSauvage(this->numIngenieurCombat)->getForceC()<<"% de skill en C\n"<<endl;
        cout<<"L adversaire possede: "<<maMap->getVectorIngenieursSauvage(this->numIngenieurCombat)->getForceCPP()<<"% de skill en CPP\n"<<endl;
        cout<<"L adversaire possede: "<<maMap->getVectorIngenieursSauvage(this->numIngenieurCombat)->getForceCSharp()<<"% de skill en CSharp\n"<<endl;
        cout<<"L adversaire possede: "<<maMap->getVectorIngenieursSauvage(this->numIngenieurCombat)->getForceHtmlCss()<<"% de skill en HTML\n"<<endl;
        cout<<"L adversaire possede: "<<maMap->getVectorIngenieursSauvage(this->numIngenieurCombat)->getForceJavaScript()<<"% de skill en JavaScript\n"<<endl;
        cout<<"L adversaire possede: "<<maMap->getVectorIngenieursSauvage(this->numIngenieurCombat)->getForcePhp()<<"% de skill en PHP\n"<<endl;
        cout<<"L adversaire possede: "<<maMap->getVectorIngenieursSauvage(this->numIngenieurCombat)->getForceScratch()<<"% de skill en Scratch\n"<<endl;
        cout<<"L adversaire possede: "<<maMap->getVectorIngenieursSauvage(this->numIngenieurCombat)->getTeamSize()<<" codeur(s) dans son equipe\n\n";
        Sleep(3000);
        bool fuite = false;
        while(!dead){
            while((maMap->getVectorIngenieursSauvage(this->numIngenieurCombat)->getEquipeIndexN(0)->getVie()>=0) || (!fuite)){
                for(int i=maMap->getVectorIngenieursSauvage(this->numIngenieurCombat)->getTeamSize()-1; i>=0 || !fuite; i--){
                    fuite = false;
                    while((maMap->getVectorIngenieursSauvage(this->numIngenieurCombat)->getEquipeIndexN(i)->getVie()>=0) || (!fuite)){
                        this->numCodeurDeIngenieurSauvage=i;
                        system("cls");
                        monJoueur->coordUpdate();
                        cout<<"\n\nVie de l'ingenieur: "<<maMap->getVectorIngenieursSauvage(this->numIngenieurCombat)->getVie()<<endl;
                        cout<<"\n\n\nCodeur numero : "<<i+1<<"\n\nVie du codeur: "<<maMap->getVectorIngenieursSauvage(this->numIngenieurCombat)->getEquipeIndexN(i)->getVie()<<endl;
                        int numAttaque = this->attaque();
                        if(numAttaque!=5){
                            this->degats(numAttaque);
                            if(maMap->getVectorIngenieursSauvage(this->numIngenieurCombat)->getEquipeIndexN(i)->getVie()>0){
                                int degatDuCodeur = rand()%3+1;
                                this->monJoueur->degats(maMap->getVectorIngenieursSauvage(this->numIngenieurCombat)->getEquipeIndexN(i)->getCapacite(degatDuCodeur)->getPuissance());
                                system("cls");
                                monJoueur->coordUpdate();
                                cout<<"\n\n"<<"l'adversaire utilise "<<maMap->getVectorIngenieursSauvage(this->numIngenieurCombat)->getEquipeIndexN(i)->getCapacite(degatDuCodeur)->getNom()
                                    <<", cela vous inflige "<<maMap->getVectorIngenieursSauvage(this->numIngenieurCombat)->getEquipeIndexN(i)->getCapacite(degatDuCodeur)->getPuissance()<<" degats";
                                Sleep(2000);
                            }
                            else{
                                cout<<"\nL'adversaire est mort, voulez-vous l'empailler? (o)Oui (n)Non : ";
                                bool KeyPressed = false;
                                while(!KeyPressed){
                                    char key = getch();
                                    if(key == 'o' || key == 'O'){
                                        KeyPressed=true;
                                        monJoueur->addEquipe(maMap->getVectorIngenieursSauvage(this->numIngenieurCombat)->getEquipeIndexN(i));
                                        cout<<"\nCodeur ajoute a la collection\n";
                                        Sleep(1000);
                                    }
                                    else if(key == 'n' || key == 'N'){
                                        KeyPressed=true;
                                        cout<<"\nCodeur trop faible surement...\n";
                                    }
                                }
                            }
                        }
                        if(numAttaque==5){
                            if(monJoueur->getMontantArgent()>=50){
                                monJoueur->setMontantArgent(monJoueur->getMontantArgent()-50);
                                cout<<"\nVous prenez la fuite.\n"<<endl;
                                maMap->getVectorIngenieursSauvage(this->numIngenieurCombat)->getEquipeIndexN(i)->setVie(-15);
                            }
                            else{
                                system("cls");
                                monJoueur->coordUpdate();
                                cout<<"\nPas assez d argent pour fuir"<<endl;
                                Sleep(1000);
                                system("cls");
                                monJoueur->coordUpdate();
                            }
                        }
                        if(maMap->getVectorIngenieursSauvage(this->numIngenieurCombat)->getEquipeIndexN(i)->getVie()<=0){
                            fuite=true;
                        }
                    }
                }
                system("cls");
                monJoueur->coordUpdate();
                cout<<"\n\n\nVous attaquez maintenant l'ingenieur\n"<<endl;
                Sleep(2000);
                system("cls");
                monJoueur->coordUpdate();
            }
            cout<<"\n\n\nVie de l'ingenieur: "<<maMap->getVectorIngenieursSauvage(this->numIngenieurCombat)->getVie()<<endl;
            int numAttaque = this->attaque();
            if(numAttaque!=5){
                this->degats(numAttaque);
//            system("cls");
//            monJoueur->moveDown(1);
//            monJoueur->moveUp(1);
                if(maMap->getVectorIngenieursSauvage(this->numIngenieurCombat)->getVie()>0){
                    int degatDuCodeur = rand()%3+1;
                    this->monJoueur->degats(maMap->getVectorIngenieursSauvage(this->numIngenieurCombat)->getCapacite(degatDuCodeur)->getPuissance());
                    system("cls");
                    monJoueur->coordUpdate();
                    cout<<"\n\n"<<"l'adversaire utilise "<<maMap->getVectorIngenieursSauvage(this->numIngenieurCombat)->getCapacite(degatDuCodeur)->getNom()
                        <<", cela vous inflige "<<maMap->getVectorIngenieursSauvage(this->numIngenieurCombat)->getCapacite(degatDuCodeur)->getPuissance()<<" degats";
                    Sleep(2000);
                }
                else{
                    monJoueur->setForceC((maMap->getVectorIngenieursSauvage(this->numIngenieurCombat)->getForceC())/2);
                    monJoueur->setForceCPP((maMap->getVectorIngenieursSauvage(this->numIngenieurCombat)->getForceCPP())/2);
                    monJoueur->setForceCSharp((maMap->getVectorIngenieursSauvage(this->numIngenieurCombat)->getForceCSharp())/2);
                    monJoueur->setForceHtmlCss((maMap->getVectorIngenieursSauvage(this->numIngenieurCombat)->getForceHtmlCss())/2);
                    monJoueur->setForceJavaScript((maMap->getVectorIngenieursSauvage(this->numIngenieurCombat)->getForceJavaScript())/2);
                    monJoueur->setForcePhp((maMap->getVectorIngenieursSauvage(this->numIngenieurCombat)->getForcePhp())/2);
                    monJoueur->setForceScratch((maMap->getVectorIngenieursSauvage(this->numIngenieurCombat)->getForceScratch())/2);
                }
            }
            system("cls");
            monJoueur->coordUpdate();
            if(maMap->getVectorIngenieursSauvage(this->numIngenieurCombat)->getVie()<=0){
                dead=true;
                maMap->replaceVectorIngenieursSauvage(this->numIngenieurCombat);
                cout<<"\n\n\nAdversaire mort.\n"<<endl;
            }
            else if(numAttaque==5){
                if(monJoueur->getMontantArgent()>=50){
                    monJoueur->setMontantArgent(monJoueur->getMontantArgent()-50);
                    cout<<"\nVous prenez la fuite.\n"<<endl;
                    dead=true;
                    maMap->replaceVectorIngenieursSauvage(this->numIngenieurCombat);
                }
                else{
                    system("cls");
                    monJoueur->coordUpdate();
                    cout<<"\nPas assez d argent pour fuir"<<endl;
                    Sleep(1000);
                    system("cls");
                    monJoueur->coordUpdate();
                }
            }
        }
    }
    else if(this->numCodeurCombat!=0){
        //system("cls");
        while(!dead){
            cout<<"\n\nL adversaire possede: "<<maMap->getVectorCodeursSauvage(this->numCodeurCombat)->getCodeurReference()->getPoucentageSkill()<<"% de skill "
                <<"en "<<maMap->getVectorCodeursSauvage(this->numCodeurCombat)->getCodeurReference()->getTypeSkill()<<endl;
            cout<<"Vie de l'adversaire: "<<maMap->getVectorCodeursSauvage(this->numCodeurCombat)->getCodeurReference()->getVie()<<endl;
            int numAttaque = this->attaque();
            if(numAttaque!=5){
                this->degats(numAttaque);
                if(maMap->getVectorCodeursSauvage(this->numCodeurCombat)->getCodeurReference()->getVie()>0){
                    int degatDuCodeur = rand()%3+1;
                    this->monJoueur->degats(maMap->getVectorCodeursSauvage(this->numCodeurCombat)->getCodeurReference()->getCapacite(degatDuCodeur)->getPuissance());
                    system("cls");
                    monJoueur->coordUpdate();
                    cout<<"\n\n"<<"l'adversaire utilise "<<maMap->getVectorCodeursSauvage(this->numCodeurCombat)->getCodeurReference()->getCapacite(degatDuCodeur)->getNom()
                        <<", cela vous inflige "<<maMap->getVectorCodeursSauvage(this->numCodeurCombat)->getCodeurReference()->getCapacite(degatDuCodeur)->getPuissance()<<" degats";
                    Sleep(2000);
                }
                else{
                    cout<<"\nL'adversaire est mort, voulez-vous l'empailler? (o)Oui (n)Non : ";
                    bool KeyPressed = false;
                    while(!KeyPressed){
                        char key = getch();
                        if(key == 'o' || key == 'O'){
                            KeyPressed=true;
                            monJoueur->addEquipe(maMap->getVectorCodeursSauvage(this->numCodeurCombat)->getCodeurReference());
                            cout<<"\n\nCodeur ajoute a la collection\n";
                            Sleep(1000);
                        }
                        else if(key == 'n' || key == 'N'){
                            KeyPressed=true;
                            cout<<"\n\nCodeur trop faible surement...\n";
                            Sleep(1000);
                        }
                    }
                }
            }
            system("cls");
            monJoueur->coordUpdate();
            if(maMap->getVectorCodeursSauvage(this->numCodeurCombat)->getCodeurReference()->getVie()<=0){
                dead=true;
                maMap->replaceVectorCodeursSauvage(this->numCodeurCombat);
                cout<<"\n\nCombat termine.\n"<<endl;
            }
            else if(numAttaque==5){
                if(monJoueur->getMontantArgent()>=50){
                    monJoueur->setMontantArgent(monJoueur->getMontantArgent()-50);
                    cout<<"\nVous prenez la fuite.\n"<<endl;
                    dead=true;
                    maMap->replaceVectorCodeursSauvage(this->numCodeurCombat);
                }
                else{
                    system("cls");
                    monJoueur->coordUpdate();
                    cout<<"\nPas assez d argent pour fuir"<<endl;
                    Sleep(1000);
                    system("cls");
                    monJoueur->coordUpdate();
                }
            }
        }
    }
}

short Jeux::attaque(){
    cout<<"\n\nVos Capacites:"<<endl;
    for(int c=0; c<4; c++){
        cout<<c<<" "<<monJoueur->getCapacite(c)->getNom()<<" : "<<monJoueur->getCapacite(c)->getPuissance()<<endl;
    }
    cout<<"\n5 Prendre la fuite"<<endl;
    short numAttaque;
    bool numOk = false;
    while(!numOk){
        cout<<"\n\nQuelle attaque voulez-vous effectuer? (entre 0 et 3) \n:";
        cin>>numAttaque;
        while(cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(),'\n');
            cout<<"\nMauvaise valeur\n";
            cout<<"\n\nQuelle attaque voulez-vous effectuer? (entre 0 et 3) \n:";
            cin >> numAttaque;
        }
        cin.clear();
        fflush(stdin);
        if(numAttaque>=0 && numAttaque<=3){
            numOk=true;
            //cout<<"\nAttaque valide\n\n\n";
        }
        else if(numAttaque==5){
            numOk=true;
            //cout<<"Vous prenez la fuite"<<endl;
        }
        else{
            cout<<"\nMauvaise valeur\n";
        }
    }
    return numAttaque;
}

void Jeux::degats(int numAttaque){
    if(this->numIngenieurCombat!=0){
         if(maMap->getVectorIngenieursSauvage(this->numIngenieurCombat)->getEquipeIndexN(this->numCodeurDeIngenieurSauvage)->getVie()>=0){
            maMap->getVectorIngenieursSauvage(this->numIngenieurCombat)->getEquipeIndexN(this->numCodeurDeIngenieurSauvage)->degats(monJoueur->getCapacite(numAttaque)->getPuissance());
        }
        else{
            maMap->getVectorIngenieursSauvage(this->numIngenieurCombat)->degats(monJoueur->getCapacite(numAttaque)->getPuissance());
        }
    }
    else if(this->numCodeurCombat!=0){
        maMap->getVectorCodeursSauvage(this->numCodeurCombat)->getCodeurReference()->degats(monJoueur->getCapacite(numAttaque)->getPuissance());
    }
}

void Jeux::menu(){
    system("cls");
    bool menuOpen = true;
    while(menuOpen){
        system("cls");
        bool KeyPressed=false;
        cout<< "Menu" <<endl;
        cout<< "R : retour" <<endl;
        cout<< "1 : XP" <<endl;
        cout<< "2 : Collection" <<endl;
        cout<< "3 : Magazin" <<endl;
        while(!KeyPressed){
            char key = getch();
            if(key == 'r' || key == 'R'){
                KeyPressed=true;
                menuOpen=false;
                system("cls");
               // cout<<"A toi de jouer:\n\n"<<"Z: Avancer"<<"\nQ: Gauche"<<"\nS: Reculer"<<"\nD: Droite\n"<<"E: Menu\n"<<endl;
               monJoueur->coordUpdate();
            }
            else if(key == '1'){
                KeyPressed=true;
                system("cls");
                cout <<monJoueur->getForceC()<<" XP C\n"<<
                        monJoueur->getForceCPP()<<" XP Cpp\n"<<
                        monJoueur->getForceCSharp()<<" XP CSharp\n"<<
                        monJoueur->getForceHtmlCss()<<" XP Html\n"<<
                        monJoueur->getForceJavaScript()<<" XP Js\n"<<
                        monJoueur->getForcePhp()<<" XP Php\n"<<
                        monJoueur->getForceScratch()<<" XP Scratch\n";
                        cout<<"\nAppuyez sur entree pour revenir au menu...";
                        getchar();
            }
            else if(key == '2'){
                KeyPressed=true;
                system("cls");
                cout << "Codeurs Obtenus :" <<endl;
                if(monJoueur->returnVectorEquipe().empty()){
                    cout<<"\nPas de codeurs dans votre collection\n";
                }
                else{
                    for(unsigned short i=0;i<monJoueur->getTeamSize()-1;i++){
                        cout<<"\nCodeur "<<i+1<<"\nSkill: "<<monJoueur->getEquipeIndexN(i)->getPoucentageSkill()<<"%\n";
                    }
                }
                cout<<"\nAppuyez sur entree pour revenir au menu...";
                getchar();
            }
            else if(key == '3'){
                KeyPressed=true;
                bool KeyPressed2=false;
                system("cls");
                cout << "Boire : \n1 : Potion de soin x1 : $500" <<endl;
                cout<< "\nR : retour" <<endl;
                while(!KeyPressed2){
                    char key2 = getch();
                    if(key2 == '1'){
                        KeyPressed2=true;
                        system("cls");
                        if(monJoueur->getMontantArgent()>=500){
                            if(monJoueur->getVie()<=100){
                                monJoueur->setVie(monJoueur->getVie()+100);
                                monJoueur->setMontantArgent(monJoueur->getMontantArgent()-500);
                                cout<<"\nPotion achetee\n";
                            }
                            else{
                                cout<<"Trop de vie (redonne 100 pv)";
                            }
                        }
                        else{
                            cout<<"Pas assez d'argent";
                        }
                        Sleep(1000);
                    }
                    else if(key2 == 'R' || key2 =='r'){
                        KeyPressed2=true;
                    }
                }
                system("cls");
            }
        }
    }
}
