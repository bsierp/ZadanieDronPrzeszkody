#ifndef GRANIASTOSLUPHEX_HH
#define GRANIASTOSLUPHEX_HH
/*!
 * \file
 * \brief Definicja klasy GraniastoslupHex
 *
 * Plik zawiera definicje klasy GraniastoslupHex,
 * oraz deklaracje metod tej klasy.
 */
#include "Obiekt3D.hh"
using drawNS::Point3D;
using std::vector;
/*!
* \brief Model pojęcia graniastosłupa prawidłowego sześciokątnego
*
* Klasa modeluje pojęcie graniastosłupa prawidłowego sześciokątnego
* dziedzicząc publicznie po klasie Obiekt3D.
*/
class GraniastoslupHex:public Obiekt3D {
    protected:
    /*!
    * \brief Orientacja graniastosłupa
    * 
    * Reprezentuje orientację obiektu
    * względem osi y globalnego układu współrzędnych
    */
    MacOb MacWir;
/*!
* \brief Wymiary graniastosłupa
* 
* W tablicy przechowywane są wymiary 
* graniastosłupa w kolejności: \n
* wym[0] - krawędź podstawy \n
* wym[1] - wysokość (w graficznej interpretacji jest to dlugość) 
*/
    double wym[2];
    /*!
    * \brief Współrzędne wierzchołków graniastosłupa
    * 
    * W tablicy przechowywane są współrzędne wierzchołków
    * graniastosłupa w postaci wektora. Wierzchołki nie
    * są używane podczas poruszania obiektem, służą jedynie 
    * jako pomoc podczas rysowania graniastosłupa
    */
    Wektor <double,3> wierzcholki[12];
    /*!
    * \brief Metoda ustawiająca wierzchołki graniastosłupa
    * 
    * Metoda odpowiada za ustawienie wierzchołków graniastosłupa
    * na podstawie aktualnej orientacji obiektu, wymiarów graniastosłupa,
    * oraz współrzędnych środka obiektu. Jest to metoda używana jedynie
    * podczas metody Rysuj().
    */
    void ustaw_wierzcholki();
    public:
    /*!
   * \brief Konstruktor bezparametryczny klasy GraniastoslupHex
   *
   * Kontruktor wypełnia tablicę wymiarów wartością zero.
   */
    GraniastoslupHex();
    /*!
    * \brief Konstruktor trójparametryczny klasy GraniastoslupHex
    * 
    * Konstruktor wypełnia tablicę wymiarów parametrami konstruktora. \n
    * \param[in] base_edge - krawędź podstawy graniastosłupa \n
    * \param[in] height - wysokość graniastosłupa 
    * \param[in] api - wskaźnik do programu graficznego, w którym ma być rysowany obiekt
    */
    GraniastoslupHex(double base_edge,double height,drawNS::Draw3DAPI *api);
    /*!
    * \brief Metoda obracająca trójwymiarowy obiekt
    * 
    * Zmienia macierz orientacji obiektu o wybrany kat
    * (W osi y). Obrót następuje błyskawicznie(nie jest 
    * animowany) \n
    * \param[in] kat - wartość kąta, o który ma zostać obrócony obiekt 
    */
    void Wiruj(double kat);
    void Rysuj() override;
    /*!
    * \brief Metoda obracająca graniastosłup
    * 
    * Zmienia macierz orientacji obiektu o wybrany kat
    * (W osi z). Obrót następuje błyskawicznie(nie jest 
    * animowany) \n
    * \param[in] kat - wartość kąta, o który ma zostać obrócony obiekt 
    */
    void Obroc(double kat);
    /*!
    * \brief Metoda przesuwająca graniastosłup
    * 
    * Zmienia położenie obiektu w przód
    * o wybraną odległość. Ruch następuje błyskawicznie
    * (nie jest animowany) \n
    * \param[in] odl - odległość o jaką obiekt ma się przesunąć
    */
    void Ruszaj(double odleglosc);
    /*!
    * \brief Metoda ruszająca graniastosłupem w osi z
    * 
    * Zmienia położenie obiektu w osi z
    * o wybraną wartość. Ruch następuje błyskawicznie
    * (nie jest animowany) \n
    * \param[in] odl - odleglosc o jaka ma sie wzniesc/opasc obiekt
    */
    void Wznies_Opusc(double odl);
    void Wymaz() override;
};
#endif