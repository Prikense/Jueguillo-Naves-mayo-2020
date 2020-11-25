

#include <iostream>
#include <ctime>
#include <cstdlib>
#include <windows.h>

using namespace std;
#include "portadora.h"
#include "fragata.h"
#include "crucero.h"
#include "destructor.h"
#include "corbeta.h"

class CDado {
public:
    CDado();
    int GetValorDado(int);
};
CDado::CDado() {
    srand(time(0));
}
int CDado::GetValorDado(int N) {
    return (rand() % N);
}

void PrintDatos(ship* Dships) {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    if (Dships->getTeam() == "1") { SetConsoleTextAttribute(hConsole, 10); }
    if (Dships->getTeam() == "2") { SetConsoleTextAttribute(hConsole, 9); }
    cout << "Type: " << Dships->getType();
    cout << " Position: " << Dships->getPosx() << "/" << Dships->getPosy();
    cout << " No Batteries: " << Dships->getNoBattery() << "/" << Dships->getmaxNoBat();
    cout << " Bat Health: " << Dships->getBatteryH() << "/" << Dships->getmaxBatteryH();
    cout << " Armour: " << Dships->getArmour() << "/" << Dships->getmaxArmour();
    cout << " No Engines: " << Dships->getNoEngines() << "/" << Dships->getmaxNoEng();
    cout << " Engines Health: " << Dships->getEnginesH() << "/" << Dships->getmaxEngineH();
    cout << " Speed: " << Dships->getSpeed();
    cout << " Movement Spent this turn: " << Dships->getTurnMove();
    cout << " Fire Range: " << Dships->getFireRange();

    cout << " Ship Health: " << Dships->getHealth() << "/" << Dships->getmaxHealth() << endl;
    SetConsoleTextAttribute(hConsole, 15);
};

void Special(ship* dShip, ship* firedShip, CDado elDadin) {//movimiento especial, solo aplica del carrier
    double dmg;
    double Armordmg;
    int roundDMG;
    if (dShip->getSpecial() == 1) { //1 bombarderos
        for (int i = 0; i < 6; i++) {
            cout << "Sending bomb squad ... ";
            Sleep(750);
            cout << "  ..  ";
            Sleep(750);
            cout << "  .  ";
            Sleep(750);
            cout << "Fire!" << endl;

            roundDMG = elDadin.GetValorDado(20) + 10;
            dmg = roundDMG * (100 - firedShip->getArmour()) / 150;
            Armordmg = roundDMG * (firedShip->getArmour()) / 100;
            firedShip->setArmour(Armordmg);
            firedShip->setHealth(dmg);
            cout << "DMG roll: " << roundDMG << " dmg: " << dmg << " armor dmg: " << Armordmg << endl;
            cout << "Remaining health: " << firedShip->getHealth() << " Remaining armour: " << firedShip->getArmour() << endl;
            Sleep(1200);
        }
    }
    else {//2 cazas armor piercing
        for (int i = 0; i < 10; i++) {
            cout << "Sending fighter squad ... ";
            Sleep(750);
            cout << "  ..  ";
            Sleep(750);
            cout << "  .  ";
            Sleep(750);
            cout << "Fire!" << endl;

            roundDMG = elDadin.GetValorDado(5) + 6;
            dmg = roundDMG * (100 - firedShip->getArmour()) / 50;
            Armordmg = roundDMG * (firedShip->getArmour()) / 450;
            firedShip->setArmour(Armordmg);
            firedShip->setHealth(dmg);
            cout << "DMG roll: " << roundDMG << " dmg: " << dmg << " armor dmg: " << Armordmg << endl;
            cout << "Remaining health: " << firedShip->getHealth() << " Remaining armour: " << firedShip->getArmour() << endl;
            Sleep(1200);
        }
    }
};

void ShotShip(ship* firingShip, ship* firedShip, int NoShots, CDado elDadin) {
    double dmg;
    double Armordmg;
    int shotDMG;
    for (int i = 0; i < NoShots; i++) {
        cout << "Loading Battery ... ";
        Sleep(750);
        cout << "  ..  ";
        Sleep(750);
        cout << "  .  ";
        Sleep(750);
        cout << "Fire!" << endl;

        shotDMG = elDadin.GetValorDado(firingShip->getBatDMG());
        dmg = shotDMG * (100 - firedShip->getArmour()) / 100;
        Armordmg = shotDMG * (firedShip->getArmour()) / 250;
        firedShip->setArmour(Armordmg);
        firedShip->setHealth(dmg);
        cout << "DMG roll: " << shotDMG << " dmg: " << dmg << " armor dmg: " << Armordmg << endl;
        cout << "Remaining health: " << firedShip->getHealth() << " Remaining armour: " << firedShip->getArmour() << endl;
        Sleep(1200);
    }
};

void ShotBattery(ship* firingShip, ship* firedShip, int NoShots, CDado elDadin) {
    double dmg;
    double Armordmg;
    int shotDMG;
    for (int i = 0; i < NoShots; i++) {
        cout << "Loading Battery ... ";
        Sleep(750);
        cout << "  ..  ";
        Sleep(750);
        cout << "  .  ";
        Sleep(750);
        cout << "Fire!" << endl;

        shotDMG = elDadin.GetValorDado(firingShip->getBatDMG());
        dmg = shotDMG * (100 - firedShip->getArmour()) / 100;
        Armordmg = shotDMG * (firedShip->getArmour()) / 400;
        firedShip->setArmour(Armordmg);
        firedShip->setBatteryH(dmg * 3 / 4);
        firedShip->setHealth(dmg / 4);
        cout << "DMG roll: " << shotDMG << "dmg: " << dmg << " armor dmg: " << Armordmg << endl;
        cout << "Remaining health: " << firedShip->getHealth() << " Remaining Battery health: " << firedShip->getBatteryH() << " Remaining armour: " << firedShip->getArmour() << endl;
        Sleep(1200);
    }
};

void ShotEngine(ship* firingShip, ship* firedShip, int NoShots, CDado elDadin) {
    double dmg;
    double Armordmg;
    int shotDMG;
    for (int i = 0; i < NoShots; i++) {
        cout << "Loading Battery ... ";
        Sleep(750);
        cout << "  ..  ";
        Sleep(750);
        cout << "  .  ";
        Sleep(750);
        cout << "Fire!" << endl;

        shotDMG = elDadin.GetValorDado(firingShip->getBatDMG());
        dmg = shotDMG * (100 - firedShip->getArmour()) / 100;
        Armordmg = shotDMG * (firedShip->getArmour()) / 350;
        firedShip->setArmour(Armordmg);
        firedShip->setEnginesH(dmg * 5 / 8);
        firedShip->setHealth(dmg * 3 / 8);
        cout << "DMG roll: " << shotDMG << "dmg: " << dmg << " armor dmg: " << Armordmg << endl;
        cout << "Remaining health: " << firedShip->getHealth() << " Remaining Engine health: " << firedShip->getEnginesH() << " Remaining armour: " << firedShip->getArmour() << endl;
        Sleep(1200);
    }
};

void cleanSpace(string ElPrint[81][41]) {
    for (int j = 0; j < 41; j++) {
        for (int i = 0; i < 81; i++) {
            ElPrint[i][j] = { " " };
        }
    }
};

void positions(string ElPrint[81][41], ship* shipPos, ship* OshipPos) {
    for (int j = 0; j < 41; j++) {
        for (int i = 0; i < 81; i++) {
            if (ElPrint[i][j] == "C1" || ElPrint[i][j] == "K1" || ElPrint[i][j] == "D1" || ElPrint[i][j] == "F1" || ElPrint[i][j] == "c1" || ElPrint[i][j] == "C2" || ElPrint[i][j] == "K2" || ElPrint[i][j] == "D2" || ElPrint[i][j] == "F2" || ElPrint[i][j] == "c2") { continue; }
            else if (i == OshipPos->getPosx() && j == OshipPos->getPosy()) { ElPrint[i][j] = { OshipPos->getType() + OshipPos->getTeam() }; }
            else if (i == shipPos->getPosx() && j == shipPos->getPosy()) { ElPrint[i][j] = { shipPos->getType() + shipPos->getTeam() }; }
            else { ElPrint[i][j] = { " " }; }
        }
    }
};

void DisplayScreen(CDado elDadin, string ElPrint[81][41]) {
    for (int i = 0; i < 82; i++) { cout << "--"; }
    cout << endl;

    for (int j = 0; j < 41; j++) {
        for (int i = 0; i < 81; i++) {
            if (elDadin.GetValorDado(25) == 0 && ElPrint[i][j] == " ") { ElPrint[i][j] = { "*" }; }
        }
    }
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    for (int j = 0; j < 41; j++) {
        cout << "|";
        for (int i = 0; i < 81; i++) {
            if (ElPrint[i][j] == "C1" || ElPrint[i][j] == "K1" || ElPrint[i][j] == "D1" || ElPrint[i][j] == "F1" || ElPrint[i][j] == "c1") {
                SetConsoleTextAttribute(hConsole, 10);
                cout << ElPrint[i][j];
                SetConsoleTextAttribute(hConsole, 15);
            }
            else if (ElPrint[i][j] == "C2" || ElPrint[i][j] == "K2" || ElPrint[i][j] == "D2" || ElPrint[i][j] == "F2" || ElPrint[i][j] == "c2") {
                SetConsoleTextAttribute(hConsole, 9);
                cout << ElPrint[i][j];
                SetConsoleTextAttribute(hConsole, 15);
            }
            else { cout << ElPrint[i][j] << " "; }
        }
        cout << "|" << endl;
    }
    for (int i = 0; i < 82; i++) { cout << "--"; }
    cout << endl;
};

void Movement(ship* MovShip, int dir, int dist) {//1 up 2 down 3 right 4 left
    switch (dir) {
    case 1://arriba y+
        MovShip->setPosy((MovShip->getPosy() - dist));
        break;
    case 2://abajo y-
        MovShip->setPosy((MovShip->getPosy() + dist));
        break;
    case 3://derecha x+
        MovShip->setPosx((MovShip->getPosx() + dist));
        break;
    case 4: //izquierda x-
        MovShip->setPosx((MovShip->getPosx() - dist));
        break;
    }

};


int main() {
    CDado elDadin;
    string ElPrint[81][41];
    int dir;//direccion del movimiento
    int dist;//distancia a moverse ahora
    int SSS = 7;
    int posCinx;
    int posCiny;
    int distAcum;//distancia acumulada

//    cout<<"Start, select fleet size (deafult is 5): ";
//    cin>>SSS;

    ship* OtherShips[7];
    ship* FriendlyShips[7];


    /*//    FriendlyShips[0]=new frig(0,0,"1");
    //    FriendlyShips[1]=new cruiser(1,0,"1");
    //    FriendlyShips[2]=new carrier(2,0,1,"1");
    //    FriendlyShips[3]=new destroyer(3,0,"1");
    //    FriendlyShips[4]=new corvette(4,0,"1");
    //
    //    OtherShips[0]=new frig(0,40,"2");
    //    OtherShips[1]=new cruiser(1,40,"2");
    //    OtherShips[2]=new carrier(2,40,1,"2");
    //    OtherShips[3]=new destroyer(3,40,"2");
    //    OtherShips[4]=new corvette(4,40,"2");*/


    cout << "Choose x and y position of your Capital ship, your Frigate. Remember, x must be between 0 and 10, y between 0 and 40" << endl;
    cout << "x: ";
    cin >> posCinx;
    cout << "y: ";
    cin >> posCiny;
    FriendlyShips[0] = new frig(posCinx, posCiny, "1");
    int ShipCustom;
    int extraVar;

    for (int i = 1; i < SSS; i++) {//creacion de flota team 1 Player
    //Creacion de naves
        cout << "Customize your fleet" << endl << "Carrier [1] the bigest ship, can launch deadly fighter ships with armour piercing capabilities, or obliterate enemy ships with a bomb squad" << endl << "Cruiser [2] a defensive ship built to sustain damage and defend other ships" << endl << "Destroyer [3] offensive ship, fast and can deal the most damage" << endl << "Corvette [4] small scout or hit and run ship" << endl;
        cin >> ShipCustom;
        switch (ShipCustom)
        {
        case 1:
            cout << "Choose, bomb squad [1] or fighter squad [2]" << endl;
            cin >> extraVar;
            cout << "Choose x and y position of your ship, x must be between 0 and 10, y between 0 and 40" << endl;
            cout << "x: ";
            cin >> posCinx;
            cout << "y: ";
            cin >> posCiny;
            FriendlyShips[i] = new carrier(posCinx, posCiny, extraVar, "1");
            break;
        case 2:
            cout << "Choose x and y position of your ship, x must be between 0 and 10, y between 0 and 40" << endl;
            cout << "x: ";
            cin >> posCinx;
            cout << "y: ";
            cin >> posCiny;
            FriendlyShips[i] = new cruiser(posCinx, posCiny, "1");
            break;
        case 3:
            cout << "Choose x and y position of your ship, x must be between 0 and 10, y between 0 and 40" << endl;
            cout << "x: ";
            cin >> posCinx;
            cout << "y: ";
            cin >> posCiny;
            FriendlyShips[i] = new destroyer(posCinx, posCiny, "1");
            break;
        case 4:
            cout << "Choose x and y position of your ship, x must be between 0 and 10, y between 0 and 40" << endl;
            cout << "x: ";
            cin >> posCinx;
            cout << "y: ";
            cin >> posCiny;
            FriendlyShips[i] = new corvette(posCinx, posCiny, "1");
            break;
        }
        cout << endl;
    }

    cout << "CPU making its fleet..." << endl;
    Sleep(2000);
    OtherShips[0] = new frig(80 - elDadin.GetValorDado(10), elDadin.GetValorDado(2) - elDadin.GetValorDado(2) + 20, "2");
    //    OtherShips[0]= new frig(10,10,"2");

    for (int i = 1; i < SSS; i++) {//creacion de flota team 2 CPU

    //Creacion de naves
        ShipCustom = elDadin.GetValorDado(3) + 1; //escoger nave, int entre 0 y 3
        switch (ShipCustom)
        {
        case 0:
            break;
        case 1:
            posCiny = elDadin.GetValorDado(40);
            posCinx = 80 - elDadin.GetValorDado(10);
            extraVar = elDadin.GetValorDado(1) + 1;
            OtherShips[i] = new carrier(posCinx, posCiny, extraVar, "2");
            break;
        case 2:
            posCiny = elDadin.GetValorDado(40);
            posCinx = 80 - elDadin.GetValorDado(10);
            OtherShips[i] = new cruiser(posCinx, posCiny, "2");
            break;
        case 3:
            posCiny = elDadin.GetValorDado(40);
            posCinx = 80 - elDadin.GetValorDado(10);
            OtherShips[i] = new destroyer(posCinx, posCiny, "2");
            break;
        case 4:
            posCiny = elDadin.GetValorDado(40);
            posCinx = 80 - elDadin.GetValorDado(10);
            OtherShips[i] = new corvette(posCinx, posCiny, "2");
            break;
        }
    }



    //Display command
    cleanSpace(ElPrint);
    for (int k = 0; k < SSS; k++) { positions(ElPrint, FriendlyShips[k], OtherShips[k]); }
    system("cls");
    DisplayScreen(elDadin, ElPrint);

    //status commands
    for (int j = 0; j < SSS; j++) { cout << j << " | "; PrintDatos(FriendlyShips[j]); }
    for (int j = 0; j < SSS; j++) { PrintDatos(OtherShips[j]); }

    //Inicializamos variables
    int actionPlay = 0;
    int moves = 0;
    int commandingShip = 0;
    int otherCommandShip = 0;
    int marcador = 0;


    while (true) {
        //turno jug
        actionPlay = 0;
        moves = 0;
        commandingShip = 0;
        otherCommandShip = 0;
        marcador = 0;
        for (int j = 0; j < SSS; j++) { FriendlyShips[j]->setTurnMove(0); }
        cout << "Player Phase" << endl;
        while (moves < SSS) {//Player Phase
            moves = 0;
            cout << "Admiral, what should be our course of action?" << endl << "[1] Select Ship to command" << endl << "[2] Show map and status of all ships" << endl << "[0] Pass turn" << endl;
            cin >> actionPlay;
            switch (actionPlay) { //---done---
            case 0://pass turn ---done---
                moves = SSS;
                break;
            case 2://Show map ---done---
                //Display command
                cleanSpace(ElPrint);
                for (int k = 0; k < SSS; k++) { positions(ElPrint, FriendlyShips[k], OtherShips[k]); }
                system("cls");
                DisplayScreen(elDadin, ElPrint);

                //status commands
                for (int j = 0; j < SSS; j++) { cout << j << " | "; PrintDatos(FriendlyShips[j]); }
                for (int j = 0; j < SSS; j++) { PrintDatos(OtherShips[j]); }
                break;

            case 1://do stuff ---main done check branches---
                //Display command
                cleanSpace(ElPrint);
                for (int k = 0; k < SSS; k++) { positions(ElPrint, FriendlyShips[k], OtherShips[k]); }
                system("cls");
                DisplayScreen(elDadin, ElPrint);

                //display status ONLY player
                for (int j = 0; j < SSS; j++) { cout << j << " | "; PrintDatos(FriendlyShips[j]); }

                cout << "Select the number of the ship to command: " << endl;
                cin >> commandingShip;
                cout << "You selected: " << commandingShip << " | ";;
                PrintDatos(FriendlyShips[commandingShip]);
                if (FriendlyShips[commandingShip]->getHealth() == 0) { break; }
                cout << "What is your command?" << endl << "[1] Fire (it uses 2 movement)" << endl << "[2] Move " << endl << "[3] Special move (only with (C)arriers)" << endl << "[0] Return to previous menu" << endl;
                cin >> actionPlay;

                switch (actionPlay) { //not done
                case 0://cancel, returns to previous menu ---done---
                    break;
                case 1://Fire ---done---
                    distAcum = FriendlyShips[commandingShip]->getTurnMove();

                    if (FriendlyShips[commandingShip]->getSpeed() - FriendlyShips[commandingShip]->getTurnMove() < 2) { cout << "That Ship doesnt have enough resources, it can no longer fire this turn" << endl; break; }//en casos donde ya se usaron todos los movimientos de la nave
                    if (FriendlyShips[commandingShip]->getNoBattery() - FriendlyShips[commandingShip]->getTurnShot() <= 0) { cout << "That Ship doesnt have its batteries available, it can no longer fire this turn" << endl; break; }//en casos donde ya se usaron todos los movimientos de la nave

                    cout << "These are the enemies in range, Admiral, select the target" << endl;
                    marcador = 0;//contamos el numero de naves en rango
                    for (int j = 0; j < SSS; j++) {
                        //enemies in range
                        int cuadrado = FriendlyShips[commandingShip]->getFireRange() * FriendlyShips[commandingShip]->getFireRange();
                        int distancia = ((FriendlyShips[commandingShip]->getPosx() - OtherShips[j]->getPosx()) * (FriendlyShips[commandingShip]->getPosx() - OtherShips[j]->getPosx()))
                            + ((FriendlyShips[commandingShip]->getPosy() - OtherShips[j]->getPosy()) * (FriendlyShips[commandingShip]->getPosy() - OtherShips[j]->getPosy()));
                        if (cuadrado >= distancia) {
                            cout << j << " | "; PrintDatos(OtherShips[j]); marcador++;
                        }
                    }

                    if (marcador == 0) { cout << "No enemies in range" << endl; break; }
                    else { cout << "Select a target: "; }
                    cin >> otherCommandShip;

                    while (true) {//Select area to fire
                        cout << "Where should we aim our batteries? [1] The hull, [2] Engines, [3] Batteries: ";
                        cin >> actionPlay;
                        if (actionPlay < 4 && actionPlay>0) { break; }
                    }

                    if (actionPlay == 1) {//disparo normal 1
                        while (true) {
                            cout << "We have " << FriendlyShips[commandingShip]->getNoBattery() - FriendlyShips[commandingShip]->getTurnShot() << " batteries available and ready to fire. How many cannons should fire? : ";
                            cin >> actionPlay;
                            if (actionPlay <= FriendlyShips[commandingShip]->getNoBattery() - FriendlyShips[commandingShip]->getTurnShot()) { break; }
                        }

                        //Shooting command
                        ShotShip(FriendlyShips[commandingShip], OtherShips[otherCommandShip], actionPlay, elDadin);

                        distAcum += 2;//guardamos la distancia que se movio, se agrega 2 cada ronda de combate
                        FriendlyShips[commandingShip]->setTurnMove(distAcum);
                        FriendlyShips[commandingShip]->setTurnShot(FriendlyShips[commandingShip]->getTurnShot() + actionPlay);
                        cout << "Barrage Finished, Admiral" << endl;
                        break;
                    }

                    if (actionPlay == 2) {//disparo a motores 2
                        while (true) {
                            cout << "We have " << FriendlyShips[commandingShip]->getNoBattery() - FriendlyShips[commandingShip]->getTurnShot() << " batteries available and ready to fire. How many cannons should fire? : ";
                            cin >> actionPlay;
                            if (actionPlay <= FriendlyShips[commandingShip]->getNoBattery() - FriendlyShips[commandingShip]->getTurnShot()) { break; }
                        }

                        //Shooting command
                        ShotEngine(FriendlyShips[commandingShip], OtherShips[otherCommandShip], actionPlay, elDadin);

                        distAcum += 2;//guardamos la distancia que se movio, se agrega 2 cada ronda de combate
                        FriendlyShips[commandingShip]->setTurnMove(distAcum);
                        FriendlyShips[commandingShip]->setTurnShot(FriendlyShips[commandingShip]->getTurnShot() + actionPlay);
                        cout << "Barrage Finished, Admiral" << endl;
                        break;
                    }

                    if (actionPlay == 3) {//disparo a cañones enemigos 3
                        while (true) {
                            cout << "We have " << FriendlyShips[commandingShip]->getNoBattery() - FriendlyShips[commandingShip]->getTurnShot() << " batteries available and ready to fire. How many cannons should fire? : ";
                            cin >> actionPlay;
                            if (actionPlay <= FriendlyShips[commandingShip]->getNoBattery() - FriendlyShips[commandingShip]->getTurnShot()) { break; }
                        }

                        //Shooting command
                        ShotBattery(FriendlyShips[commandingShip], OtherShips[otherCommandShip], actionPlay, elDadin);

                        distAcum += 2;//guardamos la distancia que se movio, se agrega 2 cada ronda de combate
                        FriendlyShips[commandingShip]->setTurnMove(distAcum);
                        FriendlyShips[commandingShip]->setTurnShot(FriendlyShips[commandingShip]->getTurnShot() + actionPlay);
                        cout << "Barrage Finished, Admiral" << endl;
                        break;
                    }
                case 2://Moving ---done---
                    distAcum = FriendlyShips[commandingShip]->getTurnMove();
                    if (FriendlyShips[commandingShip]->getTurnMove() >= FriendlyShips[commandingShip]->getSpeed()) { cout << "That Ship has used all of its movement, it can no longer move or fire this turn" << endl; break; }//en casos donde ya se usaron todos los movimientos de la nave
                    else {
                        while (FriendlyShips[commandingShip]->getTurnMove() - FriendlyShips[commandingShip]->getSpeed() != 0) {
                            //Movement comands
                            cout << "Set the Direction, [1] up, [2] down [3] right [4] left: ";//1 up 2 down 3 right 4 left
                            cin >> dir;
                            while (true) {
                                cout << "Set the Distance, it cant be greater than " << FriendlyShips[commandingShip]->getSpeed() - FriendlyShips[commandingShip]->getTurnMove() << " : ";
                                cin >> dist;
                                if (dist <= FriendlyShips[commandingShip]->getSpeed()) { break; }
                            }
                            Movement(FriendlyShips[commandingShip], dir, dist);//movimiento de la nave
                            distAcum += dist;//guardamos la distancia que se movio
                            FriendlyShips[commandingShip]->setTurnMove(distAcum);
                            //imprimimos el espacio
                            cleanSpace(ElPrint);
                            for (int k = 0; k < SSS; k++) { positions(ElPrint, FriendlyShips[k], OtherShips[k]); }//se guarda para la impresion
                            system("cls");
                            DisplayScreen(elDadin, ElPrint);

                            for (int j = 0; j < SSS; j++) { cout << j << " | "; PrintDatos(FriendlyShips[j]); }
                            while (true) { cout << "Continue moving, Admiral? [1] Yes [2] No: "; cin >> actionPlay; if (actionPlay == 2 || actionPlay == 1) { break; } }
                            if (actionPlay == 2) { break; }
                        }
                    }
                    break;
                case 3://Special, only carrier ---to do---
                    distAcum = FriendlyShips[commandingShip]->getTurnMove();
                    if (FriendlyShips[commandingShip]->getTurnMove() >= FriendlyShips[commandingShip]->getSpeed()) { cout << "That Ship has used all of its movement, it can no longer move or fire this turn" << endl; break; }//en casos donde ya se usaron todos los movimientos de la nave
                    if (FriendlyShips[commandingShip]->getType() != "C") { cout << "That is not a Carrier, sir, it doesnt have special abilities" << endl; break; }

                    cout << "These are the enemies in range, Admiral, select the target" << endl;
                    marcador = 0;//contamos el numero de naves en rango
                    for (int j = 0; j < SSS; j++) {
                        //enemies in range
                        int cuadrado = FriendlyShips[commandingShip]->getFireRange() * FriendlyShips[commandingShip]->getFireRange();
                        int distancia = ((FriendlyShips[commandingShip]->getPosx() - OtherShips[j]->getPosx()) * (FriendlyShips[commandingShip]->getPosx() - OtherShips[j]->getPosx()))
                            + ((FriendlyShips[commandingShip]->getPosy() - OtherShips[j]->getPosy()) * (FriendlyShips[commandingShip]->getPosy() - OtherShips[j]->getPosy()));
                        if (cuadrado >= distancia) {
                            cout << j << " | "; PrintDatos(OtherShips[j]); marcador++;
                        }
                    }

                    if (marcador == 0) { cout << "No enemies in range" << endl; break; }
                    else { cout << "Select a target: "; }
                    cin >> otherCommandShip;

                    Special(FriendlyShips[commandingShip], OtherShips[otherCommandShip], elDadin);

                    distAcum = FriendlyShips[commandingShip]->getSpeed();//guardamos la distancia que se movio, se agrega 2 cada ronda de combate
                    FriendlyShips[commandingShip]->setTurnMove(distAcum);
                    break;
                }
                for (int j = 0; j < SSS; j++) { if (FriendlyShips[j]->getTurnMove() == FriendlyShips[j]->getSpeed()) { moves++; } }
                cout << "Ships moved (not very reliable, its better to refer to status): " << moves << endl;
                break;//breaks el primer swtich
            }
            continue;//continue while
        }
        /*---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/
        cout << "Player Turn Finished, initializing AI..." << endl;
        Sleep(2000);

        actionPlay = 0;
        moves = 0;
        commandingShip = 0;
        otherCommandShip = 0;
        marcador = 0;
        for (int j = 0; j < SSS; j++) { OtherShips[j]->setTurnMove(0); }

        commandingShip = 0;
        //    while(commandingShip<SSS){//CPU Phase
        while (true) {//CPU Phase
            //do stuff ---main done check branches---
            while (true) {
                if (OtherShips[commandingShip]->getHealth() == 0) { commandingShip++; }
                if (OtherShips[commandingShip]->getSpeed() - OtherShips[commandingShip]->getTurnMove() < 2) { commandingShip++; break; }//en casos donde ya se usaron todos los movimientos de la nave
                if (OtherShips[commandingShip]->getNoBattery() - OtherShips[commandingShip]->getTurnShot() == 0) { commandingShip++; break; }//en casos donde ya se usaron todos los movimientos de la nave

                //Display command
                cleanSpace(ElPrint);
                for (int k = 0; k < SSS; k++) { positions(ElPrint, FriendlyShips[k], OtherShips[k]); }
                system("cls");
                DisplayScreen(elDadin, ElPrint);
                cout << "enemy ship number: " << commandingShip << endl;

                //status commands
                for (int j = 0; j < SSS; j++) { cout << j << " | "; PrintDatos(FriendlyShips[j]); }
                for (int j = 0; j < SSS; j++) { PrintDatos(OtherShips[j]); }

                Sleep(750);

                marcador = 0;//contamos el numero de naves en rango
                for (int j = 0; j < SSS; j++) {
                    //enemies in range
                    int cuadrado = OtherShips[commandingShip]->getFireRange() * OtherShips[commandingShip]->getFireRange();
                    int distancia = ((OtherShips[commandingShip]->getPosx() - FriendlyShips[j]->getPosx()) * (OtherShips[commandingShip]->getPosx() - FriendlyShips[j]->getPosx()))
                        + ((OtherShips[commandingShip]->getPosy() - FriendlyShips[j]->getPosy()) * (OtherShips[commandingShip]->getPosy() - FriendlyShips[j]->getPosy()));
                    if (cuadrado >= distancia) { marcador++; otherCommandShip = j; }
                }

                if (marcador == 0) { cout << "Too Far-" << endl; Sleep(750); actionPlay = 1; }
                else {
                    actionPlay = 2;
                    if (OtherShips[commandingShip]->getType() == "C") { actionPlay = elDadin.GetValorDado(2) + 2; }
                }
                Sleep(750);

                switch (actionPlay) { // ---done---
                case 2://Fire ---done---
                    distAcum = OtherShips[commandingShip]->getTurnMove();
                    cout << "Enemies in range-" << endl << "Admiral! The enemy " << OtherShips[commandingShip]->getType() << " is aiming their batteries at " << FriendlyShips[otherCommandShip]->getType() << "!" << endl;
                    Sleep(750);



                    //cout<<"Where should we aim our batteries? [1] The hull [2] Engines [3] Batteries: ";
                    actionPlay = elDadin.GetValorDado(3) + 1;//Choose fire location

                    if (actionPlay == 1) {//disparo normal 1
                        cout << "They have " << OtherShips[commandingShip]->getNoBattery() - OtherShips[commandingShip]->getTurnShot() << " batteries available and ready to fire. How many cannons will they fire? ";
                        actionPlay = elDadin.GetValorDado(OtherShips[commandingShip]->getNoBattery() - OtherShips[commandingShip]->getTurnShot() + 1);
                        Sleep(750);
                        cout << actionPlay << endl;

                        //Shooting command
                        ShotShip(OtherShips[commandingShip], FriendlyShips[otherCommandShip], actionPlay, elDadin);

                        distAcum += 2;//guardamos la distancia que se movio, se agrega 2 cada ronda de combate
                        OtherShips[commandingShip]->setTurnMove(distAcum);
                        OtherShips[commandingShip]->setTurnShot(OtherShips[commandingShip]->getTurnShot() + actionPlay);
                        cout << "Enemy Barrage Finished, Admiral" << endl;
                        break;
                    }
                    if (actionPlay == 2) {//disparo a motores 2
                        cout << "They have " << OtherShips[commandingShip]->getNoBattery() - OtherShips[commandingShip]->getTurnShot() << " batteries available and ready to fire. How many cannons will they fire? ";
                        actionPlay = elDadin.GetValorDado(OtherShips[commandingShip]->getNoBattery() - OtherShips[commandingShip]->getTurnShot() + 1);
                        Sleep(750);
                        cout << actionPlay << endl;

                        //Shooting command
                        ShotEngine(OtherShips[commandingShip], FriendlyShips[otherCommandShip], actionPlay, elDadin);

                        distAcum += 2;//guardamos la distancia que se movio, se agrega 2 cada ronda de combate
                        OtherShips[commandingShip]->setTurnMove(distAcum);
                        OtherShips[commandingShip]->setTurnShot(OtherShips[commandingShip]->getTurnShot() + actionPlay);
                        cout << "Enemy Barrage Finished, Admiral" << endl;
                        break;
                    }
                    if (actionPlay == 3) {//disparo a cañones enemigos 3
                        cout << "They have " << OtherShips[commandingShip]->getNoBattery() - OtherShips[commandingShip]->getTurnShot() << " batteries available and ready to fire. How many cannons will they fire? ";
                        actionPlay = elDadin.GetValorDado(OtherShips[commandingShip]->getNoBattery() - OtherShips[commandingShip]->getTurnShot() + 1);
                        Sleep(750);
                        cout << actionPlay << endl;

                        //Shooting command
                        ShotBattery(OtherShips[commandingShip], FriendlyShips[otherCommandShip], actionPlay, elDadin);

                        distAcum += 2;//guardamos la distancia que se movio, se agrega 2 cada ronda de combate
                        OtherShips[commandingShip]->setTurnMove(distAcum);
                        OtherShips[commandingShip]->setTurnShot(OtherShips[commandingShip]->getTurnShot() + actionPlay);
                        cout << "Enemy Barrage Finished, Admiral" << endl;
                        break;
                    }
                case 1://Moving ---done---
                    distAcum = OtherShips[commandingShip]->getTurnMove();
                    //Movement comands
                    //cout<<"Set the Direction, [1] up, [2] down [3] right [4] left: ";//1 up 2 down 3 right 4 left
                    if (FriendlyShips[0]->getPosx() - OtherShips[commandingShip]->getPosx() <= FriendlyShips[0]->getPosy() - OtherShips[commandingShip]->getPosy()) {//logic to find Enemy Frigate!
                        if (FriendlyShips[0]->getPosx() <= OtherShips[commandingShip]->getPosx()) { dir = 4; cout << "going left" << endl; }
                        else { dir = 3; cout << "going right" << endl; }
                    }
                    else if (FriendlyShips[0]->getPosy() <= OtherShips[commandingShip]->getPosy()) { dir = 1; cout << "going up" << endl; }
                    else { dir = 2; cout << "going down" << endl; }

                    cout << "The enemy is setting course" << endl;//OtherShips[commandingShip]->getSpeed()-OtherShips[commandingShip]->getTurnMove()<<" : ";
                    dist = elDadin.GetValorDado(OtherShips[commandingShip]->getSpeed() - OtherShips[commandingShip]->getTurnMove()) + 1;
                    cout << "Distance: " << dist << endl;
                    Sleep(750);

                    Movement(OtherShips[commandingShip], dir, dist);//movimiento de la nave
                    distAcum += dist;//guardamos la distancia que se movio
                    OtherShips[commandingShip]->setTurnMove(distAcum);
                    break;
                case 3://Special, only carrier ---to do---
                    distAcum = OtherShips[commandingShip]->getTurnMove();
                    if (OtherShips[commandingShip]->getTurnMove() >= OtherShips[commandingShip]->getSpeed()) { break; }//en casos donde ya se usaron todos los movimientos de la nave
                    if (OtherShips[commandingShip]->getType() != "C") { break; }

                    marcador = 0;//contamos el numero de naves en rango
                    for (int j = 0; j < SSS; j++) {
                        //enemies in range
                        int cuadrado = OtherShips[commandingShip]->getFireRange() * OtherShips[commandingShip]->getFireRange();
                        int distancia = ((OtherShips[commandingShip]->getPosx() - FriendlyShips[j]->getPosx()) * (OtherShips[commandingShip]->getPosx() - FriendlyShips[j]->getPosx()))
                            + ((OtherShips[commandingShip]->getPosy() - FriendlyShips[j]->getPosy()) * (OtherShips[commandingShip]->getPosy() - FriendlyShips[j]->getPosy()));
                        if (cuadrado >= distancia) { marcador++; otherCommandShip = marcador - 1; }
                    }

                    if (marcador == 0) { cout << "Too Far-" << endl; Sleep(750); break; }
                    else { cout << "Enemies in range-" << endl << "Admiral! The enemy is sending an attack squad at " << FriendlyShips[otherCommandShip]->getType() << "! they should brace for impact!" << endl; }
                    Sleep(750);

                    //inicio especial
                    Special(OtherShips[commandingShip], FriendlyShips[otherCommandShip], elDadin);

                    distAcum = OtherShips[commandingShip]->getSpeed();//guardamos la distancia que se movio, se agrega 2 cada ronda de combate
                    OtherShips[commandingShip]->setTurnMove(distAcum);
                    break;
                }
                //        cout<<"reset"<<endl;
                //        Sleep(1200);
                if (OtherShips[commandingShip]->getTurnMove() >= OtherShips[commandingShip]->getSpeed()) { commandingShip++; break; }
            }
            if (commandingShip == SSS) { break; }
        }

        for (int k = 0; k < SSS; k++) { FriendlyShips[k]->setTurnShot(0); OtherShips[k]->setTurnShot(0); }

        if (FriendlyShips[0]->getHealth() == OtherShips[0]->getHealth() && OtherShips[0]->getHealth() == 0) { cout << "Draw! The admirals lay dead in the chaos!"; break; }
        if (FriendlyShips[0]->getHealth() == 0) { cout << "Player loses! your frigate is destroyed"; break; }
        if (OtherShips[0]->getHealth() == 0) { cout << "Player Wins! The enemy frigate is destroyed"; break; }
    }
}
