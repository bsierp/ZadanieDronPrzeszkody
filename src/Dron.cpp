#include "Dron.hh"
Dron::Dron(double width, double length, double height, drawNS::Draw3DAPI *api){
if(width>0&&length>0&&height>0){
    wym[0]=width;
    wym[1]=length;
    wym[2]=height;
    gplt=api;
    Sruba pom(PROPELLER_BASE_EDGE,this->wym[1]/PROPELLER_DRONE_LENGTH_RATIO,api);
    wirnik[0]=pom;
    wirnik[1]=pom;  
    }
    else
    {
        cerr<<"Wprowadzono niedodatnia dlugosc boku"<<endl;
        exit(1);
    }

}
void Dron::rysuj_drona(){
    (*this).Rysuj();
    this->Ustaw_Sruby();
}
void Dron::wymaz_drona(){
    (*this).Wymaz();
    this->wirnik[0].Wymaz();
    this->wirnik[1].Wymaz();
}
void Dron::ruch_drona(double odl){
    double j;
    this->gplt->change_ref_time_ms(-1);
    if(odl>=0){
    for(j=0;j<=odl;j+=DRONE_MOVEMENT_FREQUENCY){
    (*this).Ruszaj(DRONE_MOVEMENT_FREQUENCY);
    (*this).Ustaw_Sruby();
    this->wirnik[0].wiruj_sruba(DRONE_MOVEMENT_FREQUENCY*PROPELLER_DEGREE_PER_UNIT);
    this->wirnik[1].wiruj_sruba(DRONE_MOVEMENT_FREQUENCY*PROPELLER_DEGREE_PER_UNIT);
    this->gplt->redraw();
}
    (*this).Ruszaj(DRONE_MOVEMENT_FREQUENCY*(1-((j-odl)/DRONE_MOVEMENT_FREQUENCY)));
     (*this).Ustaw_Sruby();
     this->gplt->redraw();
    }
    else
    {
    (*this).obrot_drona(180);
    this->gplt->change_ref_time_ms(-1);
    odl*=(-1);
    for(j=0;j<=odl;j+=DRONE_MOVEMENT_FREQUENCY){
    (*this).Ruszaj(DRONE_MOVEMENT_FREQUENCY);
    (*this).Ustaw_Sruby();
    this->wirnik[0].wiruj_sruba(DRONE_MOVEMENT_FREQUENCY*PROPELLER_DEGREE_PER_UNIT);
    this->wirnik[1].wiruj_sruba(DRONE_MOVEMENT_FREQUENCY*PROPELLER_DEGREE_PER_UNIT);
    this->gplt->redraw();    
}
    (*this).Ruszaj(DRONE_MOVEMENT_FREQUENCY*(1-((j-odl)/DRONE_MOVEMENT_FREQUENCY)));
    (*this).Ustaw_Sruby();
    this->wirnik[0].wiruj_sruba(DRONE_MOVEMENT_FREQUENCY*PROPELLER_DEGREE_PER_UNIT);
    this->wirnik[1].wiruj_sruba(DRONE_MOVEMENT_FREQUENCY*PROPELLER_DEGREE_PER_UNIT);
    this->gplt->redraw();
    }
    this->gplt->change_ref_time_ms(0);
}
void Dron::obrot_drona(double kat_obr){
    this->gplt->change_ref_time_ms(-1);
    double pomkat;
    for(pomkat=0;pomkat<=kat_obr;pomkat+=DRONE_ROTATION_FREQUENCY){
        (*this).Obroc(DRONE_ROTATION_FREQUENCY);
        (*this).Ustaw_Sruby();
        this->gplt->redraw();
        }
    (*this).Obroc(DRONE_ROTATION_FREQUENCY*(1-((pomkat-kat_obr)/DRONE_ROTATION_FREQUENCY)));
    (*this).Ustaw_Sruby();
    this->gplt->redraw();
    this->gplt->change_ref_time_ms(0);
}
void Dron::wznies_opusc_drona(double odl){
    this->gplt->change_ref_time_ms(-1);
    double j;
    if(odl>0){
    for(j=0;j<=odl;j+=DRONE_MOVEMENT_FREQUENCY){
        (*this).Wznies_Opusc(DRONE_MOVEMENT_FREQUENCY);
        (*this).Ustaw_Sruby();
        this->wirnik[0].wiruj_sruba(DRONE_MOVEMENT_FREQUENCY*PROPELLER_DEGREE_PER_UNIT);
        this->wirnik[1].wiruj_sruba(DRONE_MOVEMENT_FREQUENCY*PROPELLER_DEGREE_PER_UNIT);
        this->gplt->redraw();
    }
    (*this).Wznies_Opusc(DRONE_MOVEMENT_FREQUENCY*(1-((j-odl)/DRONE_MOVEMENT_FREQUENCY)));
    (*this).Ustaw_Sruby();
    this->gplt->redraw();    
    }
    else
    {
    for(j=0;j>=odl;j-=DRONE_MOVEMENT_FREQUENCY){
        (*this).Wznies_Opusc(-DRONE_MOVEMENT_FREQUENCY);
        (*this).Ustaw_Sruby();
        this->wirnik[0].wiruj_sruba(DRONE_MOVEMENT_FREQUENCY*PROPELLER_DEGREE_PER_UNIT);
        this->wirnik[1].wiruj_sruba(DRONE_MOVEMENT_FREQUENCY*PROPELLER_DEGREE_PER_UNIT);
        this->gplt->redraw();
    }
    (*this).Wznies_Opusc(-DRONE_MOVEMENT_FREQUENCY*(1-((j-odl)/DRONE_MOVEMENT_FREQUENCY)));
    (*this).Ustaw_Sruby();
    this->gplt->redraw();
    }
    this->gplt->change_ref_time_ms(0);
}
void Dron::Ustaw_Sruby(){
    this->wirnik[0].Wymaz();
    this->wirnik[1].Wymaz();
    Wektor<double,3> left(this->srodek[0]-this->wym[0]/4,this->srodek[1]-this->wym[1]/2-this->wym[1]/PROPELLER_DRONE_LENGTH_RATIO/2,this->srodek[2]);
    Wektor<double,3> right(this->srodek[0]+this->wym[0]/4,this->srodek[1]-this->wym[1]/2-this->wym[1]/PROPELLER_DRONE_LENGTH_RATIO/2,this->srodek[2]);
    this->wirnik[0].ustaw_obrot(this->orient);
    this->wirnik[1].ustaw_obrot(this->orient);
    this->wirnik[0].ustaw_srodek(this->srodek+this->orient*(left-this->srodek));
    this->wirnik[1].ustaw_srodek(this->srodek+this->orient*(right-this->srodek));
    this->wirnik[0].Rysuj();
    this->wirnik[1].Rysuj();
}
bool Dron::czy_kolizja(std::shared_ptr <Interfejs> drone)const {
    return((this->srodek-drone->zwroc_srodek()).dlugosc()<(this->zwroc_promien_drona()+drone->zwroc_promien_drona()));
}
double Dron::zwroc_promien_drona() const{
    Wektor<double,3> promien(this->srodek[0]+this->wym[0]/4+PROPELLER_BASE_EDGE,this->srodek[1]-this->wym[1]/2-this->wym[1]/PROPELLER_DRONE_LENGTH_RATIO,this->srodek[2]+PROPELLER_BASE_EDGE*sqrt(3)/2);
    return promien.dlugosc();
}
const Wektor<double,3> & Dron::zwroc_srodek() const{
    return this->srodek;
}