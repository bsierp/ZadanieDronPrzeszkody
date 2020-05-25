#ifndef WEK_HH
#define WEK_HH
/*!
* \file
* \brief Definicja szablonu klasy Wektor
*
* Plik zawiera definicję szablonu klasy Wektor 
* oraz deklaracje jego metod i funkcji działających
* na klasie
*/
#include <cmath>
#include <iostream>
using std::cerr;
using std::endl;
/*!
* \brief Model pojęcia Wektor
* 
* Klasa modeluje pojęcie wektora,
* z parametrami o informującymi
* o typie przechowywanych danych
* oraz rozmiarze wektora. \n
* \param TYP - typ zmiennych przechowywanych w wektorze
* \param ROZMIAR - ilość zmiennych w wektorze
*/
template<class TYP, int ROZMIAR>
class Wektor{
 /*!
   * \brief Tablica zawierająca elementy wektora.
   * 
   * Tablica zawiera elementy wektora.
   * \param ROZMIAR - wielkość tablicy elementów.
   */
    TYP tab[ROZMIAR];
    public:
    /*!
   * \brief Konstruktor bezparametryczny wektora 
   *
   * Konstruktor incijalizuje pola wektora wartością 0
   */
    Wektor();
     /*!
   * \brief Konstruktor trójparametryczny wektora 
   *
   * Konstruktor inicjalizuje elementy wektora wartościami
   * argumentów. Używane tylko do wektora trójwymiarowego \n
   * \param[in] x - wartość współrzędnej X.
   * \param[in] y - wartość współrzędnej Y.
   * \param[in] z - wartość współrzędnej Z.
    */
    Wektor(TYP x,TYP y,TYP z):tab{x,y,z}{}
    /*!
   * \brief Przeciążenie nawiasów kwadratowych
   *
   * Pozwala na odwoływanie się do wybranego elementu wektora, 
   * ale nie pozwala na zmianę go \n
   * \param[in] index - indeks elementu wektora 
   * \return Zwraca referencję do wybranego elementu wektora.
   */
    const TYP & operator[](int index) const;
    /*!
   * \brief Przeciążenie nawiasów kwadratowych
   *
   * Pozwala na odwołanie się do wybranego elementu wektora 
   * oraz zmianę go \n
   * \param[in] index - indeks elementu wektora 
   * \return Zwraca referencję do wybranego elementu wektora.
   */
    TYP & operator[](int index);
    /*!
   * \brief Przeciążenie operatora dodawania
   *
   * Przeciążenie operatora dodawania dla dwóch wektorów. \n
   * Dodaje odpowiadające sobie miejsca wektora do siebie. \n
   * \param[in] W2 - Wektor do dodania
   * \return Zwraca wektor po dokonaniu operacji dodawania.
   */
    Wektor operator+(const Wektor<TYP,ROZMIAR> & W2) const;
    /*!
   * \brief Przeciążenie operatora odejmowania
   *
   * Przeciążenie operatora odejmowania dla dwóch wektorów. \n
   * Odejmuje odpowiadające sobie miejsca wektora od siebie. \n
   * \param[in] W2 - Wektor do odjęcia
   * \return Zwraca wektor po dokonaniu operacji odejmowania.
   */
    Wektor operator-(const Wektor<TYP,ROZMIAR> & W2) const;
    /*!
   * \brief Przeciążenie operatora mnożenia
   *
   * Przeciążenie operatora mnożenia dla dwóch wektorów. \n
   * Wykonuje mnożenie skalarne dwóch wektorów. \n
   * \param[in] W2 - Wektor do przemnożenia
   * \return Zwraca wynik po dokonaniu operacji mnożenia skalarnego.
   */
    TYP operator*(const Wektor<TYP,ROZMIAR> & W2) const;
    /*!
   * \brief Przeciążenie operatora mnożenia
   *
   * Przeciążenie operatora odejmowania dla wektora oraz
   * typu danych który przechowuje \n
   * Dokonuje operacji mnożenia wartości argumentów. \n
   * \param[in] skl - czynnik o typie odpowiadającym typowi danych w wektorze
   * \return Zwraca wektor po dokonaniu operacji mnożenia.
   */
    Wektor operator*(TYP skl) const;
    /*!
   * \brief Przeciążenie operatora porównania
   *
   * Przeciążenie operatora porównującego dwa wektory. \n
   * Sprawdza, czy wektory podane w argumentach są równe. \n
   * \param[in] W2 - Wektor do porównania
   * \retval true - jeśli wektory są równe,
   * \retval false - w przeciwyn wypadku
   */
    bool operator==(const Wektor<TYP,ROZMIAR> & W2) const;
    /*!
   * \brief Przeciążenie operatora porównania
   *
   * Przeciążenie operatora porównującego dwa wektory. \n
   * Sprawdza, czy wektory podane w argumentach są różne. \n
   * \param[in] W2 - Wektor do porównania
   * \retval true - jeśli wektory są różne,
   * \retval false - w przeciwyn wypadku
   */
    bool operator!=(const Wektor<TYP,ROZMIAR> & W2) const;
    /*!
   * \brief Wyliczenie długości wektora
   *
   * Funkcja wylicza długość wektora \n
   * \return Zwraca długość wektora.
   */
    double dlugosc() const{
         return sqrt(*this * *this);
    }
};
/*!
 * \brief Przeciążenie operatora przesunięcia bitowego w prawo
 *
 * Umożliwia wczytywanie danych z wybranego strumienia do obiektów typu Wektor \n
 * \param[in] strm - strumień danych, z którego dane będą wczytywane.
 * \param[in] W - wektor, do którego wczytywane są wartości.
 * \return Zwraca referencję do strumienia danych.
 */
template<class TYP, int ROZMIAR>                                                
std::istream & operator>>(std::istream & strm, Wektor<TYP,ROZMIAR> & W);
/*!
 * \brief Przeciążenie operatora przesunięcia bitowego w lewo
 *
 * Umożliwia wyświetlanie zmiennej typu Wektor na wybranym strumieniu danych \n
 * \param[in] strm - strumień danych na którym wektor ma zostać wyświetlony.
 * \param[in] W - wektor, ktorego wartości są wyświetlane.
 * \return Zwraca referencję do strumienia danych.
 */
template<class TYP, int ROZMIAR>          
std::ostream & operator<<(std::ostream & strm,const Wektor<TYP,ROZMIAR> & W);
#endif