#include "Dron.hh"
#include "Woda.hh"
#include "Dno.hh"
#include <iostream>
#include <memory>
using drawNS::APIGnuPlot3D;
using std::cout;
using std::endl;
using std::cin;
using std::shared_ptr;
using std::make_shared;
using std::vector;
void wait4key() {                                                               
  do {                                                                          
    std::cout << "\n Press a key to continue..." << std::endl;                  
  } while(std::cin.get() != '\n');                                              
}
void PrezentujDrony(vector<shared_ptr<Dron> > drony){
  int i=0;
  cout<<"Drony obracaja sie po kolei"<<endl;
  for(auto elem : drony){
    cout<<"Dron nr "<<++i<<endl;
    elem->obrot_drona(360);
  }
}        
int main(){
cout<<"Podaj wymiary przestrzeni x,y,z"<<endl;
double x,y,z;
cin>>x>>y>>z;
cout<<"Nastapi inicjalizacja sceny"<<endl;
drawNS::Draw3DAPI * api = new APIGnuPlot3D(-x,x,-y,y,-z,z,-1);
vector<shared_ptr<Przeszkoda> > kolekcja_przeszkod;
vector<shared_ptr<Dron> > kolekcja_Dronow;
shared_ptr<Woda> tafla = make_shared<Woda>(x,-x,y,-y,z-2,api);
tafla->Rysuj();
tafla->Rysuj();//Pierwszy narysowany obiekt zawsze znika (dlaczego ?)
kolekcja_przeszkod.push_back(tafla);
shared_ptr<Dno> bottom = make_shared<Dno>(x,-x,y,-y,-z,api);
bottom->Rysuj();
kolekcja_przeszkod.push_back(bottom);
shared_ptr<Prostopadloscian> Pr1 = make_shared<Prostopadloscian>(1,2*y,1,api);
Pr1->Wznies_Opusc(-(z-5));
Pr1->Obroc(-90);
Pr1->Ruszaj(x-4);
Pr1->Obroc(90);
kolekcja_przeszkod.push_back(Pr1);
shared_ptr<Prostopadloscian> Pr2 = make_shared<Prostopadloscian>(10,2,7,api);
Pr2->Obroc(45);
Pr2->Ruszaj(y-4);
Pr2->Obroc(-45);
kolekcja_przeszkod.push_back(Pr2);
shared_ptr<Prostopadloscian> Pr3 = make_shared<Prostopadloscian>(1,1,2*z,api);
Pr3->Obroc(90);
Pr3->Ruszaj(x-4);
Pr3->Obroc(90);
Pr3->Ruszaj(y-4);
kolekcja_przeszkod.push_back(Pr3);
shared_ptr<Prostopadloscian> Pr4 = make_shared<Prostopadloscian>(2*x,1,1,api);
Pr4->Ruszaj(y-5);
Pr4->Wznies_Opusc(z-5);
kolekcja_przeszkod.push_back(Pr4);
shared_ptr<Dron> Dr1 = make_shared<Dron>(7,5,4,api);
Dr1->obrot_drona(90);
Dr1->ruch_drona(8+2*PROPELLER_DRONE_LENGTH_RATIO,0);
Dr1->obrot_drona(90);
Dr1->ruch_drona(5,45);
kolekcja_Dronow.push_back(Dr1);
kolekcja_przeszkod.push_back(Dr1);
shared_ptr<Dron> Dr2 = make_shared<Dron>(7,5,4,api);
Dr2->obrot_drona(-90);
Dr2->ruch_drona(8+2*PROPELLER_DRONE_LENGTH_RATIO,0);
Dr2->ruch_drona(-5,-45);
kolekcja_Dronow.push_back(Dr2);
kolekcja_przeszkod.push_back(Dr2);
shared_ptr<Dron> Dr3 = make_shared<Dron>(7,5,4,api);
Dr3->rysuj_drona();
kolekcja_Dronow.push_back(Dr3);
cout<<"Inicjalizacja zakonczona"<<endl;
char wybor;
int a=0;
int pick_drone=2; //domyślnie - środkowy dron
while (a!=1){
cout<<endl<<"Prosze wybrac opcje:"<<endl<<"r-ruch dronem"<<endl<<"o-obrot drona"<<endl<<"w-wybierz drona"<<endl<<"q-wyjscie"<<endl;
     cin>>wybor;
   switch (wybor)
   {
   case 'r':
    {
      double odl,kat;
      bool kolizja = false;
      cout<<"Podaj odleglosc"<<endl;
      cin>>odl;
      cout<<"Podaj kat wznoszenia/opadania:"<<endl;
      cin>>kat;
      if(odl<0){
        odl*=-1;
        kolekcja_Dronow[pick_drone]->obrot_drona(180);
      }
    for(double j=0;j<=odl;j+=DRONE_MOVEMENT_FREQUENCY){
      for(auto elem: kolekcja_przeszkod){
        kolizja=elem->czy_kolizja(kolekcja_Dronow[pick_drone]);
        if(kolizja==true){
          break;
        }
          }

          if(kolizja==false){
            kolekcja_Dronow[pick_drone]->ruch_drona(DRONE_MOVEMENT_FREQUENCY,kat);
          }
          else
          {
            cout<<"Wykryto możliwość kolizji!"<<endl;
            break;
          }
          
    }
      break;
    }
    case 'o':
    { 
      double kat;
      cout<<"Podaj kat obrotu"<<endl;
      cin>>kat;
      kolekcja_Dronow[pick_drone]->obrot_drona(kat);
      break;
    }
    case 'q':
    {
      cout<<"Konczenie pracy programu"<<endl;
      a=1;
      break;
    }
    case ' ':
    break;
    case 'w':
    {
      cout<<"Prosze wybrac drona sposrod podanych"<<endl;
      PrezentujDrony(kolekcja_Dronow);
      kolekcja_przeszkod.pop_back();
      kolekcja_przeszkod.pop_back();
      cout<<"Twoj wybor:"<<endl;
      cin>>pick_drone;
      if(pick_drone>3||pick_drone<1){
        srand(time(0));
        pick_drone=(rand()%3);
        cout<<"Nie rozpoznano numeru drona.Losowo wybrano drona nr "<<pick_drone+1<<endl;
      }
      --pick_drone;
      if(pick_drone==0){
        kolekcja_przeszkod.push_back(kolekcja_Dronow[1]);
        kolekcja_przeszkod.push_back(kolekcja_Dronow[2]);
      }
      if(pick_drone==1){
        kolekcja_przeszkod.push_back(kolekcja_Dronow[0]);
        kolekcja_przeszkod.push_back(kolekcja_Dronow[2]);
      }
      if(pick_drone==2){
        kolekcja_przeszkod.push_back(kolekcja_Dronow[1]);
        kolekcja_przeszkod.push_back(kolekcja_Dronow[0]);
      }
      break;
    }
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