#include "Dron.hh"
#include "Woda.hh"
#include "Dno.hh"
#include <iostream>
using drawNS::APIGnuPlot3D;
using std::cout;
using std::endl;
using std::cin;
void wait4key() {                                                               
  do {                                                                          
    std::cout << "\n Press a key to continue..." << std::endl;                  
  } while(std::cin.get() != '\n');                                              
}        
int main(){
cout<<"Podaj wymiary przestrzeni x,y,z"<<endl;
double x,y,z;
cin>>x>>y>>z;
drawNS::Draw3DAPI * api = new APIGnuPlot3D(-x,x,-y,y,-z,z,0);
Dno bottom(x,-x,y,-y,-z,api);
Woda tafla(x,-x,y,-y,z,api);
Dron drone(7,5,4,api);
char wybor;
api->change_ref_time_ms(-1);
tafla.Rysuj();
drone.rysuj_drona();
bottom.Rysuj();
tafla.Rysuj();
api->redraw();
int a=0;

api->redraw();
while (a!=1){
cout<<endl<<"Prosze wybrac opcje:"<<endl<<"r-ruch dronem"<<endl<<"o-obrot drona"<<endl<<"u-unoszenie/opadanie drona"<<endl<<"q-wyjscie"<<endl;
     cin>>wybor;
   switch (wybor)
   {
   case 'r':
    {
      double odl;
      cout<<"Podaj odleglosc"<<endl;
      cin>>odl;
      drone.ruch_drona(odl);
      break;
    }
    case 'o':
    { 
      double kat;
      cout<<"Podaj kat obrotu"<<endl;
      cin>>kat;
      drone.obrot_drona(kat);
      break;
    }
    case 'q':
    {
      cout<<"Konczenie pracy programu"<<endl;
      a=1;
      break;
    }
    case 'u':
    {
      double odl;
      cout<<"Podaj odleglosc"<<endl;
      cin>>odl;
      drone.wznies_opusc_drona(odl);
      break;
    }
    case ' ':
    break;
   
   default:
     {
     cout<<"Nie rozpoznano opcji"<<endl;
     break;
     }
   }
}
delete api;
return 0;
}