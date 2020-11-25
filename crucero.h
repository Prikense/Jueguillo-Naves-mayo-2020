#include "base.h"

class cruiser: public ship{
public:
    cruiser(int,int,string,string,int,int,int,int,int,int);

    int getBatDMG();

    int getmaxNoBat();
    double getmaxBatteryH();
    double getmaxArmour();
    double getmaxHealth();
    int getmaxNoEng();
    double getmaxEngineH();
    int getSpecial();
};

cruiser::cruiser(int f,int g,string t, string a="K",int b=15,int c=65,int d=4,int e=3,int h=10,int i=16):ship(a,b,c,d,e,f,g,t,h,i){}
int cruiser::getBatDMG(){return 12;}

int cruiser::getmaxNoBat(){return 15;}
double cruiser::getmaxBatteryH(){return getmaxNoBat()*Cof;}
double cruiser::getmaxArmour(){return 65;}
double cruiser::getmaxHealth(){return shipSize*10+getmaxBatteryH()+getmaxEngineH();}
int cruiser::getmaxNoEng(){return 10;}
double cruiser::getmaxEngineH(){return getmaxNoEng()*Cof;}
int cruiser::getSpecial(){return 0;}
