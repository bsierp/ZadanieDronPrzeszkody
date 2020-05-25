#include "GraniastoslupHex.hh"
GraniastoslupHex::GraniastoslupHex(){
        for(double &wymiar:wym){
        wymiar=0;
    }
}
GraniastoslupHex::GraniastoslupHex(double base_edge,double height,drawNS::Draw3DAPI *api){
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
void GraniastoslupHex::ustaw_wierzcholki(){
    Wektor <double,3> pol_base_edge(this->wym[0]/2,0,0);
    Wektor <double,3> pol_height(0,this->wym[1]/2,0);
    Wektor <double,3> pol_hex_height(0,0,(this->wym[0]*sqrt(3))/2);
    this->wierzcholki[0]=this->srodek+this->orient*this->MacWir*((pol_base_edge+pol_height+pol_hex_height)*(-1));
    this->wierzcholki[1]=this->srodek+this->orient*this->MacWir*(pol_base_edge-pol_height-pol_hex_height);
    this->wierzcholki[2]=this->srodek+this->orient*this->MacWir*(pol_base_edge*2-pol_height);
    this->wierzcholki[3]=this->srodek+this->orient*this->MacWir*(pol_base_edge-pol_height+pol_hex_height);
    this->wierzcholki[4]=this->srodek+this->orient*this->MacWir*(pol_hex_height-pol_base_edge-pol_height);
    this->wierzcholki[5]=this->srodek+this->orient*this->MacWir*(pol_base_edge*(-2)-pol_height);
    this->wierzcholki[6]=this->srodek+this->orient*this->MacWir*(pol_height-pol_base_edge-pol_hex_height);
    this->wierzcholki[7]=this->srodek+this->orient*this->MacWir*(pol_base_edge+pol_height-pol_hex_height);
    this->wierzcholki[8]=this->srodek+this->orient*this->MacWir*(pol_base_edge*2+pol_height);
    this->wierzcholki[9]=this->srodek+this->orient*this->MacWir*(pol_base_edge+pol_height+pol_hex_height);
    this->wierzcholki[10]=this->srodek+this->orient*this->MacWir*(pol_hex_height+pol_height-pol_base_edge);
    this->wierzcholki[11]=this->srodek+this->orient*this->MacWir*(pol_base_edge*(-2)+pol_height);
}
void GraniastoslupHex::Rysuj(){
(*this).ustaw_wierzcholki();
this->id=this->gplt->draw_polyhedron(vector<vector<Point3D> > {{                                         
        drawNS::Point3D(this->wierzcholki[0][0],this->wierzcholki[0][1],this->wierzcholki[0][2]), drawNS::Point3D(this->wierzcholki[1][0],this->wierzcholki[1][1],this->wierzcholki[1][2]), drawNS::Point3D(this->wierzcholki[2][0],this->wierzcholki[2][1],this->wierzcholki[2][2]),drawNS::Point3D(this->wierzcholki[3][0],this->wierzcholki[3][1],this->wierzcholki[3][2]),drawNS::Point3D(this->wierzcholki[4][0],this->wierzcholki[4][1],this->wierzcholki[4][2]), drawNS::Point3D(this->wierzcholki[5][0],this->wierzcholki[5][1],this->wierzcholki[5][2])             
      },{                                                                                  
         drawNS::Point3D(this->wierzcholki[6][0],this->wierzcholki[6][1],this->wierzcholki[6][2]),drawNS::Point3D(this->wierzcholki[7][0],this->wierzcholki[7][1],this->wierzcholki[7][2]), drawNS::Point3D(this->wierzcholki[8][0],this->wierzcholki[8][1],this->wierzcholki[8][2]),drawNS::Point3D(this->wierzcholki[9][0],this->wierzcholki[9][1],this->wierzcholki[9][2]),drawNS::Point3D(this->wierzcholki[10][0],this->wierzcholki[10][1],this->wierzcholki[10][2]), drawNS::Point3D(this->wierzcholki[11][0],this->wierzcholki[11][1],this->wierzcholki[11][2])            
          }},"blue");
}
void GraniastoslupHex::Obroc(double kat){
    (*this).Wymaz();
    MacOb nowa_orient('z',kat);
    this->orient=this->orient*nowa_orient;
    (*this).Rysuj();
}
void GraniastoslupHex::Ruszaj(double odl){
    (*this).Wymaz();
    Wektor<double,3> przemieszczenie(0,odl,0);
    this->srodek=this->srodek+this->orient*przemieszczenie;
    (*this).Rysuj();
}
void GraniastoslupHex::Wiruj(double kat){
    (*this).Wymaz();
    MacOb nowa_wir('y',kat);
    this->MacWir=this->MacWir*nowa_wir;
    (*this).Rysuj();
}
void GraniastoslupHex::Wznies_Opusc(double odl){
    (*this).Wymaz();
    this->srodek[2]+=odl;
    (*this).Rysuj();
}
void GraniastoslupHex::Wymaz(){
    this->gplt->erase_shape(this->id);
}