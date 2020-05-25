#include "Woda.hh"
Woda::Woda(){
            for(double &wymiar:granice){
        wymiar=0;
    }
}
Woda::Woda(double max_x, double min_x, double max_y, double min_y,double z, drawNS::Draw3DAPI * api){
    granice[0]=max_x;
    granice[1]=min_x;
    granice[2]=max_y;
    granice[3]=min_y;
    granice[4]=z;
    gplt=api;
}
void Woda::Wymaz(){
    this->gplt->erase_shape(this->id);
}
void Woda::Poziom(double level){
    this->granice[4]=level;
}
void Woda::Rysuj(){
    this->id=this->gplt->draw_surface(vector<vector<Point3D> > {{
	drawNS::Point3D(this->granice[0],this->granice[2],this->granice[4]), drawNS::Point3D(this->granice[0],0,this->granice[4]), drawNS::Point3D(this->granice[0],this->granice[3],this->granice[4])
	  },{
	drawNS::Point3D(this->granice[0]/2,this->granice[2],this->granice[4]+2), drawNS::Point3D(this->granice[0]/2,0,this->granice[4]+2), drawNS::Point3D(this->granice[0]/2,this->granice[3],this->granice[4]+2)       
	  },{
	drawNS::Point3D(0,this->granice[2],this->granice[4]), drawNS::Point3D(0,0,this->granice[4]), drawNS::Point3D(0,this->granice[3],this->granice[4])       
	  },{
	drawNS::Point3D(this->granice[1]/2,this->granice[2],this->granice[4]+2), drawNS::Point3D(this->granice[1]/2,0,this->granice[4]+2), drawNS::Point3D(this->granice[1]/2,this->granice[3],this->granice[4]+2)       
	  },{
	drawNS::Point3D(this->granice[1],this->granice[2],this->granice[4]), drawNS::Point3D(this->granice[1],0,this->granice[4]), drawNS::Point3D(this->granice[1],this->granice[3],this->granice[4])       
	  }},"blue");
}
bool Woda::czy_kolizja(std::shared_ptr<Interfejs> drone) const{
    return (this->granice[4]<drone->zwroc_srodek()[2]);
}