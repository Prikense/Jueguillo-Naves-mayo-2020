#include "base.h"

class corvette: public ship{
public:
    corvette(int,int,string,string,int,int,int,int,int,int);

    int getBatDMG();

    int getmaxNoBat();
    double getmaxBatteryH();
    double getmaxArmour();
    double getmaxHealth();
    int getmaxNoEng();
    double getmaxEngineH();
    int getSpecial();
};

corvette::corvette(int f,int g,string t,string a="c",int b=12,int c=40,int d=1,int e=5,int h=10,int i=8):ship(a,b,c,d,e,f,g,t,h,i){}
int corvette::getBatDMG(){return 15;}

int corvette::getmaxNoBat(){return 12;}
double corvette::getmaxBatteryH(){return getmaxNoBat()*Cof;}
double corvette::getmaxArmour(){return 40;}
int corvette::getmaxNoEng(){return 10;}
double corvette::getmaxEngineH(){return getmaxNoEng()*Cof;}
double corvette::getmaxHealth(){return shipSize*10+getmaxBatteryH()+getmaxEngineH();}
int corvette::getSpecial(){return 0;}
