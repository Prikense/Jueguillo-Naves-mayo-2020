#ifndef base
#define base

class ship{
protected:
    int NoBattery;
    int Cof;
    double BatteryHealth; //daño recibido en total a los cañones
    double Armour; //armadura de la nave
    double Health; //vida util de la nave
    int shipSize; //tamaño de la nave, sirve para saber la vida total
    int Noengines; //numero de motores
    double enginesH; //vida util de los motores
    int Speed; //velocidad de la nave, cuantos espacios se puede mover en un turno
    int FireRange; //rango de disparo en tiles

    int Special; //valor especial para carrier
    int turnMove; //cuanto se ha movido en este turno
    int turnShot; //Numero de cañones utilizados en el turno
    string team; //equipo al que pertenece
    string TypeShip; //tipo de nave
    int xPos; //posicion en x
    int yPos; //posicion en y
public:
    ship(string,int,int,int,int,int,int,string,int,int);

    //metodos para recuperar el valor de las variables
    string getType();

    virtual int getBatDMG()=0;

    int getFireRange();
    int getNoBattery();
    double getBatteryH();
    int getNoEngines();
    double getEnginesH();
    int getSpeed();

    double getArmour();
    double getHealth();
    int getPosx();
    int getPosy();
    string getTeam();
    int getTurnMove();
    int getTurnShot();

    virtual int getSpecial()=0;
    virtual int getmaxNoBat()=0;
    virtual double getmaxBatteryH()=0;
    virtual int getmaxNoEng()=0;
    virtual double getmaxEngineH()=0;
    virtual double getmaxArmour()=0;
    virtual double getmaxHealth()=0;

    //metodos para insertar un nuevo valor
    int setNoBattery();
    double setBatteryH(double);
    int setNoEngies();
    double setEnginesH(double);

    double setArmour(double);
    double setHealth(double);
    int setPosx(int);
    int setPosy(int);
    int setTurnMove(int);
    int setTurnShot(int);
};

ship::ship(string tipo, int numBat,int armor,int H,int cf,int x, int y, string T,int numEng,int frange){
    TypeShip=tipo;

    FireRange=frange;
    team=T;
    Cof=cf;
    NoBattery=numBat;
    BatteryHealth=NoBattery*Cof;
    Noengines=numEng;
    enginesH=Noengines*Cof;
    shipSize=H;
    Speed=Noengines*4/shipSize+2;
    Armour=armor;
    Health=shipSize*10+BatteryHealth+enginesH;
    xPos=x;
    yPos=y;
    turnMove=0;
    turnShot=0;
}

string ship::getType(){return TypeShip;}

int ship::getNoBattery(){return NoBattery;}
double ship::getBatteryH(){return BatteryHealth;}
int ship::getNoEngines(){return Noengines;}
double ship::getEnginesH(){return enginesH;}
int ship::getSpeed(){return Speed;}

int ship::getFireRange(){return FireRange;}
double ship::getArmour(){return Armour;}
double ship::getHealth(){return Health;}
int ship::getPosx(){return xPos;}
int ship::getPosy(){return yPos;}
string ship::getTeam(){return team;}
int ship::getTurnMove(){return turnMove;}
int ship::getTurnShot(){return turnShot;}

double ship::setArmour(double a) { Armour -= a; if (Armour <= 0) { Armour = 0;}return 0;}
double ship::setHealth(double a){Health-=a; if (Health<=0){Health=0;}return 0;}
double ship::setBatteryH(double a){BatteryHealth-=a; if (BatteryHealth<=0){BatteryHealth=0;} NoBattery=BatteryHealth/Cof; return 0;}
double ship::setEnginesH(double a){enginesH-=a; if (enginesH<=0){enginesH=0;} Noengines=enginesH/Cof; Speed=Noengines*4/shipSize+2; return 0;}


int ship::setTurnMove(int a){turnMove=a; return 0;}
int ship::setTurnShot(int a){turnShot=a; return 0;}
int ship::setPosx(int a){xPos=a; return 0;}
int ship::setPosy(int a){yPos=a; return 0;}


#endif
