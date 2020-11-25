#include "base.h"

class frig: public ship{
public:
    frig(int,int,string,string,int,int,int,int,int,int);

    int getBatDMG();

    int getmaxNoBat();
    double getmaxBatteryH();
    double getmaxArmour();
    double getmaxHealth();
    int getmaxNoEng();
    double getmaxEngineH();
    int getSpecial();
};

frig::frig(int f,int g,string t,string a="F",int b=8,int c=80,int d=2,int e=5,int h=5,int i=14):ship(a,b,c,d,e,f,g,t,h,i){}
int frig::getBatDMG(){return 16;}

int frig::getmaxNoBat(){return 8;}
double frig::getmaxBatteryH(){return getmaxNoBat()*Cof;}
double frig::getmaxArmour(){return 80;}
double frig::getmaxHealth(){return shipSize*10+getmaxBatteryH()+getmaxEngineH();}
int frig::getmaxNoEng(){return 5;}
double frig::getmaxEngineH(){return getmaxNoEng()*Cof;}
int frig::getSpecial(){return 0;}
