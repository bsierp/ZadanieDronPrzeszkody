#include "MacOb.hh"
using std::cerr;
using std::endl;
MacOb::MacOb(){
    for(int i=0;i<3;++i){
        for(int j=0;j<3;++j){
            tab[i][j]=0;
            if(i==j){
                tab[i][j]=1;
            }
        }
    }
}
MacOb::MacOb(const Macierz<double,3> & Mac):Macierz<double,3>(Mac){
double epsilon=0.00000001;
if(abs(tab[0]*tab[1])>epsilon||abs(tab[1]*tab[2])>epsilon||abs(tab[0]*tab[2])>epsilon||abs((*this).wyznacznik()-1>epsilon)){
    cerr<<"Macierz nie jest ortogonalna"<<endl;
    exit(1);
}
}
MacOb::MacOb(char os, double kat){
    switch (os)
    {
    case 'x':{
        tab[0][0]=1;
        tab[0][1]=0;
        tab[0][2]=0;
        tab[1][0]=0;
        tab[1][1]=cos(kat*PI/180);
        tab[1][2]=-sin(kat*PI/180);
        tab[2][0]=0;
        tab[2][1]=sin(kat*PI/180);
        tab[2][2]=cos(kat*PI/180);
        break;
}
    case 'y':{
        tab[0][0]=cos(kat*PI/180);
        tab[0][1]=0;
        tab[0][2]=sin(kat*PI/180);
        tab[1][0]=0;
        tab[1][1]=1;
        tab[1][2]=0;
        tab[2][0]=-sin(kat*PI/180);
        tab[2][1]=0;
        tab[2][2]=cos(kat*PI/180);
        break;
    }
    case 'z':{
        tab[0][0]=cos(kat*PI/180);
        tab[0][1]=-sin(kat*PI/180);
        tab[0][2]=0;
        tab[1][0]=sin(kat*PI/180);
        tab[1][1]=cos(kat*PI/180);
        tab[1][2]=0;
        tab[2][0]=0;
        tab[2][1]=0;
        tab[2][2]=1;
        break;
    }
    default:
    {
        cerr<<"Wybor osi nieprawidlowy. Macierz nie zostala utworzona"<<endl;
        exit(1);
    }
        break;
    }
}