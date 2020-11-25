#include "base.h"

class destroyer: public ship{
public:
    destroyer(int,int,string,string,int,int,int,int,int,int);

    int getBatDMG();

    int getmaxNoBat();
    double getmaxBatteryH();
    double getmaxArmour();
    double getmaxHealth();
    int getmaxNoEng();
    double getmaxEngineH();
    int getSpecial();
};

destroyer::destroyer(int f,int g,string t, string a="D",int b=8,int c=50,int d=3,int e=4,int h=8,int i=12):ship(a,b,c,d,e,f,g,t,h,i){}
int destroyer::getBatDMG(){return 30;}

int destroyer::getmaxNoBat(){return 8;}
double destroyer::getmaxBatteryH(){return getmaxNoBat()*Cof;}
double destroyer::getmaxArmour(){return 50;}
double destroyer::getmaxHealth(){return shipSize*10+getmaxBatteryH()+getmaxEngineH();}
int destroyer::getmaxNoEng(){return 8;}
double destroyer::getmaxEngineH(){return getmaxNoEng()*Cof;}
int destroyer::getSpecial(){return 0;}
