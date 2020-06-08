#include "Prostopadloscian.hh"
Prostopadloscian::Prostopadloscian(){
    for(double &wymiar:wym){
        wymiar=0;
    }
}
Prostopadloscian::Prostopadloscian(double width,double length, double height,drawNS::Draw3DAPI *api){
    if(width>0&&length>0&&height>0){
    wym[0]=width;
    wym[1]=length;
    wym[2]=height;
    this->gplt=api;
    }
    else
    {
        cerr<<"Wprowadzono niedodatnia dlugosc boku"<<endl;
        exit(1);
    }
    
}

void Prostopadloscian::ustaw_wierzcholki(){
    Wektor <double,3> pol_width(this->wym[0]/2,0,0);
    Wektor <double,3> pol_length(0,this->wym[1]/2,0);
    Wektor <double,3> pol_height(0,0,this->wym[2]/2);
    this->wierzcholki[0]=this->srodek+this->orient*((pol_width+pol_length+pol_height)*(-1));
    this->wierzcholki[1]=this->srodek+this->orient*(pol_width-pol_length-pol_height);
    this->wierzcholki[2]=this->srodek+this->orient*(pol_width+pol_length-pol_height);
    this->wierzcholki[3]=this->srodek+this->orient*(pol_length-pol_width-pol_height);
    this->wierzcholki[4]=this->srodek+this->orient*(pol_height-pol_length-pol_width);
    this->wierzcholki[5]=this->srodek+this->orient*(pol_width-pol_length+pol_height);
    this->wierzcholki[6]=this->srodek+this->orient*(pol_width+pol_length+pol_height);
    this->wierzcholki[7]=this->srodek+this->orient*(pol_length-pol_width+pol_height);
    }
void Prostopadloscian::Rysuj(){
    (*this).ustaw_wierzcholki();
    this->id=this->gplt->draw_polyhedron(vector<vector<Point3D> > {{                                         
        drawNS::Point3D(this->wierzcholki[0][0],this->wierzcholki[0][1],this->wierzcholki[0][2]), drawNS::Point3D(this->wierzcholki[1][0],this->wierzcholki[1][1],this->wierzcholki[1][2]), drawNS::Point3D(this->wierzcholki[2][0],this->wierzcholki[2][1],this->wierzcholki[2][2]),drawNS::Point3D(this->wierzcholki[3][0],this->wierzcholki[3][1],this->wierzcholki[3][2])             
      },{                                                                                  
        drawNS::Point3D(this->wierzcholki[4][0],this->wierzcholki[4][1],this->wierzcholki[4][2]), drawNS::Point3D(this->wierzcholki[5][0],this->wierzcholki[5][1],this->wierzcholki[5][2]), drawNS::Point3D(this->wierzcholki[6][0],this->wierzcholki[6][1],this->wierzcholki[6][2]),drawNS::Point3D(this->wierzcholki[7][0],this->wierzcholki[7][1],this->wierzcholki[7][2])             
          }},"orange");
}
void Prostopadloscian::Obroc(double kat){
    (*this).Wymaz();
    MacOb nowa_orient('z',kat);
    this->orient=this->orient*nowa_orient;
    (*this).Rysuj();
}
void Prostopadloscian::Ruszaj(double odl){
    (*this).Wymaz();
    Wektor<double,3> przemieszczenie(0,odl,0);
    this->srodek=this->srodek+this->orient*przemieszczenie;
    (*this).Rysuj();
}
void Prostopadloscian::Wznies_Opusc(double odl){
    (*this).Wymaz();
    this->srodek[2]+=odl;
    (*this).Rysuj();
}
void Prostopadloscian::Wymaz(){
    this->gplt->erase_shape(this->id);
}
PrzeszkodaProstopadloscian::PrzeszkodaProstopadloscian(double width,double length,double height,drawNS::Draw3DAPI *api){
    if(width>0&&length>0&&height>0){
    wym[0]=width;
    wym[1]=length;
    wym[2]=height;
    this->gplt=api;
    }
    else
    {
        cerr<<"Wprowadzono niedodatnia dlugosc boku"<<endl;
        exit(1);
    }
        
}
bool PrzeszkodaProstopadloscian::czy_kolizja(std::shared_ptr<Interfejs> drone) const {
if (drone->zwroc_srodek()[0]>this->wierzcholki[0][0]-drone->zwroc_promien_drona() && drone->zwroc_srodek()[0]<this->wierzcholki[1][0]+drone->zwroc_promien_drona()
    && drone->zwroc_srodek()[1]>this->wierzcholki[0][1]-drone->zwroc_promien_drona() && drone->zwroc_srodek()[1]<this->wierzcholki[3][1]+drone->zwroc_promien_drona()
    && drone->zwroc_srodek()[2]>this->wierzcholki[0][2]-drone->zwroc_promien_drona() && drone->zwroc_srodek()[2]<this->wierzcholki[4][2]+drone->zwroc_promien_drona())
{
    return true;
}
else
{
    return false;
}
}