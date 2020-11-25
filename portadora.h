#include "base.h"

class carrier: public ship{
private:
    int Special;
public:
    carrier(int,int,int,string,string,int,int,int,int,int,int);

    int getBatDMG();

    int getmaxNoBat();
    double getmaxBatteryH();
    double getmaxArmour();
    double getmaxHealth();
    int getmaxNoEng();
    double getmaxEngineH();
    int getSpecial();
};

carrier::carrier(int f,int g,int spe,string t,string a="C",int b=4,int c=15,int d=5, int e=4,int h=12,int i=20):ship(a,b,c,d,e,f,g,t,h,i){Special=spe;}
int carrier::getBatDMG(){return 8;}

int carrier::getmaxNoBat(){return 4;}
double carrier::getmaxBatteryH(){return getmaxNoBat()*Cof;}
double carrier::getmaxArmour(){return 15;}
double carrier::getmaxHealth(){return shipSize*10+getmaxBatteryH()+getmaxEngineH();}
int carrier::getmaxNoEng(){return 12;}
double carrier::getmaxEngineH(){return getmaxNoEng()*Cof;}
int carrier::getSpecial(){return Special;}
