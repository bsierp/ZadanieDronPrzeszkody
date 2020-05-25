#ifndef SRUBA_HH
#define SRUBA_HH
#define DRONE_MOVEMENT_FREQUENCY 0.01
#define DRONE_ROTATION_FREQUENCY 0.1
/*!
 * \file
 * \brief Definicja klasy Sruba
 *
 * Plik zawiera definicje klasy Sruba,
 * oraz deklaracje metod tej klasy.
 */
#include "GraniastoslupHex.hh"
/*!
* \brief Model pojęcia Śruba
*
* Klasa modeluje pojęcie śruby, która
* dziedziczy publicznie po klasie GraniastoslupHex.
*/
class Sruba: public GraniastoslupHex {
    public:
    /*!
   * \brief Konstruktor bezparametryczny klasy Sruba
   *
   * Kontruktor wypełnia tablicę wymiarów wartością zero.
   */
    Sruba();
    /*!
    * \brief Konstruktor trójparametryczny klasy Sruba
    * 
    * Konstruktor wypełnia tablicę wymiarów parametrami konstruktora. \n
    * \param[in] base_edge - krawędź podstawy graniastosłupa \n
    * \param[in] height - wysokość graniastosłupa 
    * \param[in] api - wskaźnik do programu graficznego, w którym ma być rysowany obiekt
    */
    Sruba(double base_edge,double height,drawNS::Draw3DAPI *api);
    /*!
    * \brief Metoda wirująca śrubą
    * 
    * Zmienia macierz orientacji śruby o wybrany kat
    * (W osi y). Obrót jest animowany. \n
    * \param[in] kat - wartość kąta, o który ma zostać obrócona śruba
    */
    void wiruj_sruba(double kat);
    /*!
    *\brief Metoda ustawiająca nowy środek śruby
    * 
    * Metoda zmienia środek śruby na środek podany 
    * w parametrze \n
    * \param[in] new_center - współrzędne nowego środka w postaci wektora
    */
    void ustaw_srodek(const Wektor <double,3> & new_center);
    /*!
    *\brief Metoda ustawiająca nową orientację
    * 
    * Metoda zmienia macierz orientacji śruby na macierz podaną
    * w parametrze (w osi z) \n
    * \param[in] new_rotation - nowa macierz orientacji obiektu
    */
    void ustaw_obrot(const MacOb & new_rotation);
};
#endif