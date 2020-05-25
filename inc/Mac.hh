#ifndef MAC_HH
#define MAC_HH
/*!
 * \file
 * \brief Definicja szablonu klasy Macierz
 *
 * Plik zawiera definicje szablonu klasy Macierz
 * oraz deklaracje metod i funkcji działających na klasie
 */
#include "Wek.hh"
#include<cmath>
using std::abs;
using std::swap;
using std::endl;
/*!
* \brief Model pojęcia Macierzy kwadratowej
* 
* Klasa modeluje pojęcie macierzy kwadratowej
* z parametrami o informującymi
* o typie przechowywanych danych
* oraz rozmiarze macierzy. \n
* \param TYP - typ zmiennych przechowywanych w macierzy
* \param ROZMIAR - wymiar macierzy kwadratowej
*/
template<class TYP, int ROZMIAR>
class Macierz {
  protected:
   /*!
   * \brief Tablica zawierająca wiersze macierzy w postaci wektorów.
   * 
   * Tablica zawiera wiersze macierzy w postaci wektorów.
   * \param ROZMIAR - liczba wierszy macierzy.
   */
    Wektor<TYP,ROZMIAR> tab[ROZMIAR];
    public:
    /*!
   * \brief Konstruktor bezparametryczny macierzy
   *
   * Konstruktor inicjalizuje pola macierzy wartością 0. 
   */
    Macierz();            
    /*!
   * \brief Przeciążenie operatora mnożenia
   *
   * Przeciążenie operatora mnożenia dla macierzy i wektora 
   * o tych samych wymiarach i typach danych. \n
   * Mnoży każdy wiersz macierzy skalarnie przez wektor \n
   * \param[in] skl - czynnik w postaci wektora o takim samym wymiarze co macierz i typie danych
   * \return Zwraca wektor po dokonaniu operacji mnożenia.
   */                                                        
  Wektor<TYP,ROZMIAR> operator *(const Wektor<TYP,ROZMIAR> & skl) const;
    /*!
   * \brief Oblicza wyznacznik macierzy
   * 
   * Funkcja oblicza wyznacznik macierzy metodą Gaussa-Jordana. \n
   * \return Zwraca obliczony wyznacznik.
   */                                  
  TYP wyznacznik() const;       
  /*!
   * \brief Przeciążenie operatora dodawania
   *
   * Przeciążenie operatora dodawania dla dwóch macierzy o 
   * tych samych wymiarach i typach danych. \n
   * Dodaje odpowiadające sobie wiersze macierzy do siebie. \n
   * \param[in] skl - macierz do dodania.
   * \return Zwraca macierz po dokonaniu operacji dodawania.
   */                                             
  Macierz  operator + (const Macierz<TYP,ROZMIAR> & skl) const;   
  /*!
   * \brief Przeciążenie operatora odejmowania
   *
   * Przeciążenie operatora odejmowania dla dwóch macierzy o
   * tych samych wymiarach i typach danych. \n
   * Odejmuje odpowiadające sobie wiersze macierzy od siebie.  \n
   * \param[in] skl - macierz do odjęcia
   * \return Zwraca macierz po dokonaniu operacji odejmowania.
   */                           
  Macierz  operator - (const Macierz<TYP,ROZMIAR> & skl) const;
  /*!
   * \brief Przeciążenie operatora mnożenia
   *
   * Przeciążenie operatora mnożenia dla dwóch macierzy o 
   * tych samych wymiarach i typach danych. \n
   * Mnoży odpowiednie wiersze jednej macierzy z odpowiednimi kolumnami drugiej. \n
   * \param[in] skl - macierz przez którą będzie mnożona macierz
   * \return Zwraca macierz po dokonaniu operacji mnożenia.
   */                              
  Macierz operator * (const Macierz<TYP,ROZMIAR> & skl) const;  
  /*!
   * \brief Przeciążenie operatora mnożenia
   *
   * Przeciążenie operatora mnożenia dla macierzy oraz typu danych jaki przechowuje \n.
   * Dokonuje operacji mnożenie wartości argumentów. \n
   * \param[in] skl - czynnik o typie danych odpowiadający typowi danych w macierzy
   * \return Zwraca macierz po dokonaniu operacji mnożenia.
   */                             
  Macierz  operator * (TYP skl) const;   
    /*!
   * \brief Przeciążenie operatora porównania
   *
   * Przeciążenie operatora porównania dla dwóch macierzy o 
   * tych samych wymiarach i typach danych. \n
   * Sprawdza, czy macierze podane w argumentach są równe. \n
   * \param[in] skl - macierz do porównania.
   * \retval true - jeśli macierze są równe
   * \retval false - w przeciwyn wypadku
   */                                    
  bool operator == (const Macierz<TYP,ROZMIAR> & skl) const;
  /*!
   * \brief Przeciążenie operatora porównania
   *
   * Przeciążenie operatora porównania dla dwóch macierzy o 
   * tych samych wymiarach i typach danych. \n
   * Sprawdza, czy macierze podane w argumentach są różne. \n
   * \param[in] skl - macierz do porównania.
   * \retval true - jeśli macierze są różne
   * \retval false - w przeciwyn wypadku
   */                                 
  bool operator != (const Macierz<TYP,ROZMIAR> & skl) const;
  /*!
   * \brief Transponuje macierz
   *
   * Funkcja dokonuje operacji transpozycji
   * macierzy. \n
   * \return Zwraca macierz po dokonaniu operacji transpozycji
   */                                 
  Macierz Transponuj() const;      
    /*!
   * \brief Przeciążenie nawiasów kwadratowych
   *
   * Umożliwia odwołanie się do wybranego wiersza macierzy
   * ale nie pozwala na zmianę go. \n
   * \param[in] index - indeks wiersza do którego chcemy się odwołać.
   * \return Zwraca referencję do żądanego wiersza.
   */                                                 
  const Wektor<TYP,ROZMIAR> & operator [] (int index) const; 
  /*!
   * \brief Przeciążenie nawiasów kwadratowych
   *
   * Umożliwia odwołanie się do wybranego wiersza macierzy
   * oraz pozwala na zmianę go. \n
   * \param[in] index - indeks wiersza do którego chcemy się odwołać.
   * \return Zwraca referencję do żądanego wiersza.
   */                                
  Wektor<TYP,ROZMIAR> & operator[](int index);
};
/*!
 * \brief Przeciążenie operatora przesunięcia bitowego w prawo
 *
 * Umożliwia wczytywanie danych z wybranego strumienia do obiektów typu Macierz \n
 * \param[in] strm - strumień danych, z którego dane będą wczytywane.
 * \param[in] Mac - Macierz, do której wczytywane są wartości.
 * \return Zwraca referencję do strumienia danych.
 */
template<class TYP,int ROZMIAR>
std::istream & operator>>(std::istream & strm,Macierz<TYP,ROZMIAR> &Mac);
/*!
 * \brief Przeciążenie operatora przesunięcia bitowego w lewo
 *
 * Umożliwia wyświetlanie zmiennej typu Macierz na wybranym strumieniu danych \n
 * \param[in] strm - strumień danych na którym macierz ma zostać wyświetlona.
 * \param[in] Mac - macierz, której wartości są wyświetlane.
 * \return Zwraca referencję do strumienia danych.
 */
template<class TYP,int ROZMIAR>
std::ostream & operator<<(std::ostream & strm,const Macierz<TYP,ROZMIAR> &Mac);

#endif