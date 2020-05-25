#include "Mac.hh"
template<class TYP,int ROZMIAR>
Macierz<TYP,ROZMIAR>::Macierz(){
     for(int i=0;i<ROZMIAR;i++){                                                 
        for(int j=0;j<ROZMIAR;j++){                                             
        tab[i][j]=0;                                                            
        }                                                                       
    }             
}
template<class TYP,int ROZMIAR>
Wektor<TYP,ROZMIAR> Macierz<TYP,ROZMIAR>::operator*(const Wektor<TYP,ROZMIAR> & skl) const{
    Wektor<TYP,ROZMIAR> wynik;
    for(int i=0;i<ROZMIAR;i++){                                                
         wynik[i]=this->tab[i]*skl;
}
return wynik;
}
template<class TYP,int ROZMIAR>
TYP Macierz<TYP,ROZMIAR>::wyznacznik() const{
    Macierz<TYP,ROZMIAR> wynik=*this;
    int pom=0;
    int k=0;
    double epsilon=0.0000000001;
    TYP det(1);
     for(int j=0;j<ROZMIAR;j++){                                               
          if(wynik[j].dlugosc()<epsilon||(wynik.Transponuj()[j].dlugosc()<epsilon)){                                                                       
            det=0;                                                              
            return det;                                                         
          } 
           while (abs(wynik[j][j])<epsilon)                                      
          {                                                                     
              swap(wynik[j],wynik[++pom]);                                      
              ++k;                                                              
          }                                                                     
          pom=0;
           for(int i=(j+1);i<ROZMIAR;i++){                                       
            wynik[i]=wynik[i]-(wynik[j]*(wynik[i][j]/wynik[j][j]));             
          }                                                                     
      }                                                                         
      for(int i=0;i<ROZMIAR;i++){                                               
          int j;                                                                
          j=i;                                                                  
              det*=wynik[i][j];                                                 
          }                                                                     
      if(k%2==0)                                                                
      return det;
      else                                                                      
        return det*(-1);                                                 
}
template<class TYP,int ROZMIAR>
Macierz<TYP,ROZMIAR> Macierz<TYP,ROZMIAR>::operator+(const Macierz<TYP,ROZMIAR> & skl) const{
    Macierz<TYP,ROZMIAR> wynik;
     for(int i=0;i<ROZMIAR;i++){                                               
          wynik[i]=this->tab[i]+skl[i];                                         
      }                                                                         
      return wynik;                                                             
  }
template<class TYP,int ROZMIAR>
Macierz<TYP,ROZMIAR> Macierz<TYP,ROZMIAR>::operator-(const Macierz<TYP,ROZMIAR> & skl) const{
    Macierz<TYP,ROZMIAR> wynik;
     for(int i=0;i<ROZMIAR;i++){                                               
          wynik[i]=this->tab[i]-skl[i];                                         
      }                                                                         
      return wynik;  
}
template<class TYP,int ROZMIAR>
Macierz<TYP,ROZMIAR> Macierz<TYP,ROZMIAR>::operator*(const Macierz<TYP,ROZMIAR> & skl) const {
    Macierz<TYP,ROZMIAR> wynik;
     for(int i=0;i<ROZMIAR;i++){                                              
            for(int j=0;j<ROZMIAR;j++){                                         
                wynik[i][j]=this->tab[i]*(skl.Transponuj()[j]);                 
            }                                                                   
        }                                                                       
       return wynik;  
}
template<class TYP,int ROZMIAR>
Macierz<TYP,ROZMIAR> Macierz<TYP,ROZMIAR>::operator*(TYP skl) const{
    Macierz<TYP,ROZMIAR> wynik;
     for(int i=0;i<ROZMIAR;i++){                                               
          wynik[i]=this->tab[i]*skl;                                            
      }                                                                         
      return wynik;     
}
template<class TYP,int ROZMIAR>
bool Macierz<TYP,ROZMIAR>::operator==(const Macierz<TYP,ROZMIAR> & skl) const{                                       
      for(int i=0;i<ROZMIAR;i++){                                               
      if(!(this->tab[i]==skl[i]))
      return false;
}
return true;
}
template<class TYP,int ROZMIAR>
bool Macierz<TYP,ROZMIAR>::operator!=(const Macierz<TYP,ROZMIAR> & skl) const{
    return !(*this==skl);
}
template<class TYP,int ROZMIAR>
Macierz<TYP,ROZMIAR> Macierz<TYP,ROZMIAR>::Transponuj() const{
    Macierz<TYP,ROZMIAR> MTrans;
    for(int i=0;i<ROZMIAR;i++){                                                
         for(int j=0;j<ROZMIAR;j++){                                            
             MTrans[i][j]=this->tab[j][i];                                      
         }                                                                      
     }                                                                          
      return MTrans; 
}
template<class TYP,int ROZMIAR>
const Wektor<TYP,ROZMIAR> & Macierz<TYP,ROZMIAR>::operator[](int index) const{
     if(index<0||index>ROZMIAR){                                               
          cerr<<"Indeks macierzy poza zakresem";                                
          exit(1);                                                              
      }                                                                         
      return tab[index];
}
template<class TYP,int ROZMIAR>
Wektor<TYP,ROZMIAR> & Macierz<TYP,ROZMIAR>::operator[](int index) {
     if(index<0||index>ROZMIAR){                                               
          cerr<<"Indeks macierzy poza zakresem";                                
          exit(1);                                                              
      }                                                                         
      return tab[index];
}
template<class TYP,int ROZMIAR>
std::istream & operator>>(std::istream & strm,Macierz<TYP,ROZMIAR> &Mac){
    for (int i=0;i<ROZMIAR;++i){                                              
strm>>Mac[i];                                                                   
      }                                                                         
return strm;
}
template<class TYP,int ROZMIAR>
std::ostream & operator<<(std::ostream & strm,const Macierz<TYP,ROZMIAR> &Mac){
     for(int i=0;i<ROZMIAR;i++){                                                 
    strm<<Mac[i]<<endl;                                                         
    }
}
