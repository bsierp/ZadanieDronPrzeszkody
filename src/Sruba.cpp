#include "Sruba.hh"
Sruba::Sruba(){
           for(double &wymiar:wym){
        wymiar=0;
    } 
}
Sruba::Sruba(double base_edge,double height,drawNS::Draw3DAPI *api){
        if(base_edge>0&&height>0){
        wym[0]=base_edge;
        wym[1]=height;
        gplt=api;
    }
    else
    {
        cerr<<"Wprowadzono niedodatnia dlugosc boku"<<endl;
        exit(1);
    }
}
void Sruba::ustaw_srodek(const Wektor <double,3> & new_center){
    this->srodek=new_center;
}
void Sruba::wiruj_sruba(double kat){
    double pomkat;
    for(pomkat=0;pomkat<=kat;pomkat+=DRONE_ROTATION_FREQUENCY){
        (*this).Wiruj(DRONE_ROTATION_FREQUENCY);
    }
    (*this).Wiruj(DRONE_ROTATION_FREQUENCY*(1-((pomkat-kat)/DRONE_ROTATION_FREQUENCY)));    
}
void Sruba::ustaw_obrot(const MacOb & new_rotation){
    this->orient=new_rotation;
}

