#include "Wek.hh"
template<class TYP,int ROZMIAR>
Wektor<TYP,ROZMIAR>::Wektor(){
    for(int i=0;i<ROZMIAR;i++){
        tab[i]=0;
    }
}
template<class TYP, int ROZMIAR>
const TYP & Wektor<TYP,ROZMIAR>::operator[](int index) const{
 if(index<0||index>ROZMIAR){                                                 
        cerr<<"Skladowa wektora pozaś zakresem"<<endl;                          
        exit(1);                                                                
    }                                                                           
    return this->tab[index];                                                    
    }                 
template<class TYP, int ROZMIAR>
TYP & Wektor<TYP,ROZMIAR>::operator[](int index){
    if(index<0||index>ROZMIAR){                                                 
        cerr<<"Skladowa wektora poza zakresem"<<endl;                           
        exit(1);                                                                
    }                                                                           
    return this->tab[index];                                                    
}       

template<class TYP, int ROZMIAR>
Wektor<TYP,ROZMIAR> Wektor<TYP,ROZMIAR>::operator+(const Wektor<TYP,ROZMIAR> & W2) const{
Wektor <TYP,ROZMIAR> Wynik;
 for(int i=0;i<ROZMIAR;i++){                                         
                Wynik[i]=this->tab[i]+W2[i];                                   
            }                                                                   
                                                                                
        return Wynik;    
}
template<class TYP, int ROZMIAR>
Wektor<TYP,ROZMIAR> Wektor<TYP,ROZMIAR>::operator-(const Wektor<TYP,ROZMIAR> & W2) const{
    Wektor<TYP,ROZMIAR> wynik;                                                              
            for(int i=0;i<ROZMIAR;i++){                                         
                wynik[i]=this->tab[i]-W2[i];                                   
            }                                                                   
        return wynik;                                                           
  }                           
template<class TYP,int ROZMIAR>
bool Wektor<TYP,ROZMIAR>::operator==(const Wektor<TYP,ROZMIAR> & W2) const{
        double epsilon=0.00000000001;
for(int i=0;i<ROZMIAR;i++){                                               
      if(!(abs(this->tab[i]-W2[i])<epsilon))
      return false;
}
     return true; 
}

template<class TYP, int ROZMIAR>                                                
TYP Wektor<TYP,ROZMIAR>::operator*(const Wektor<TYP,ROZMIAR> & W2) const {      
  TYP wynik(0);                                                                                                                                   
  for (int i=0;i<ROZMIAR;++i)                                                   
    wynik += this->tab[i]*W2[i];                                                  
  return wynik;                                                                   
}                               
template<class TYP,int ROZMIAR>
Wektor<TYP,ROZMIAR> Wektor<TYP,ROZMIAR>::operator*(TYP skl) const{
    Wektor<TYP,ROZMIAR> Wynik;
     for(int i=0;i<ROZMIAR;i++){                                         
                Wynik[i]=this->tab[i]*skl;                                      
            }                                                                   
      return Wynik;                                                             
  }                   
template<class TYP,int ROZMIAR>
bool Wektor<TYP,ROZMIAR>::operator!=(const Wektor<TYP,ROZMIAR> & W2) const{
    return !(*this==W2);
}

  template<class TYP, int ROZMIAR>                                                
std::istream & operator>>(std::istream & strm, Wektor<TYP,ROZMIAR> & W){
    for(int i=0;i<ROZMIAR;++i){
        strm>>W[i];
    }
    return strm;
}
template<class TYP, int ROZMIAR>          
std::ostream & operator<<(std::ostream & strm,const Wektor<TYP,ROZMIAR> & W){
    for(int i=0;i<ROZMIAR;++i){
        strm<<W[i]<<' ';
    }
}