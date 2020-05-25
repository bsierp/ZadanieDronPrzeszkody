#ifndef PROSTOPADLOSCIAN_HH
#define PROSTOPADLOSCIAN_HH
/*!
 * \file
 * \brief Definicja klasy Prostopadloscian
 *
 * Plik zawiera definicje klasy Prostopadloscian,
 * oraz deklaracje metod tej klasy.
 */
#include "Przeszkoda.hh"
#include "Obiekt3D.hh"
#include "Interfejs.hh"
using drawNS::Point3D;
using std::vector;
/*!
* \brief Model pojęcia Prostopadłościan
*
* Klasa modeluje pojęcie prostopadłościanu
* dziedzicząc publicznie po klasie Obiekt3D.
*/
class Prostopadloscian:public Obiekt3D,public Przeszkoda {
    protected:
/*!
* \brief Wymiary prostopadłościanu
* 
* W tablicy przechowywane są wymiary 
* prostopadloscianu w kolejności: \n
* wym[0] - szerokość(w osi x) \n
* wym[1] - długość(w osi y) \n
* wym[2] - wysokość(w osi z)
*/
    double wym[3];
    /*!
    * \brief Współrzędne wierzchołków prostopadłościanu
    * 
    * W tablicy przechowywane są współrzędne wierzchołków
    * prostopadłościanu w postaci wektora. Wierzchołki nie
    * są używane podczas poruszania obiektem, służą jedynie 
    * jako pomoc podczas rysowania prostopadłościanu
    */
    Wektor<double,3> wierzcholki[8];
    /*!
    * \brief Metoda ustawiająca wierzchołki prostopadłościanu
    * 
    * Metoda odpowiada za ustawienie wierzchołków prostopadłościanu
    * na podstawie aktualnej orientacji obiektu, wymiarów prostopadłościanu,
    * oraz współrzędnych środka obiektu. Jest to metoda używana jedynie
    * podczas metody Rysuj().
    */
    void ustaw_wierzcholki();
    public:
    /*!
   * \brief Konstruktor bezparametryczny klasy Prostopadloscian
   *
   * Kontruktor wypełnia tablicę wymiarów wartością zero.
   */
    Prostopadloscian();
    /*!
    * \brief Konstruktor czteroparametryczny klasy Prostopadloscian
    * 
    * Konstruktor wypełnia tablicę wymiarów parametrami konstruktora. \n
    * \param[in] width - szerokość prostopadłościanu (wymiar w osi x)
    * \param[in] length - długość prostopadłościanu (wymiar w osi y)
    * \param[in] height - wysokość prostopadłościanu (wymiar w osi z)
    * \param[in] api - wskaźnik do programu graficznego, w którym ma być rysowany obiekt
    */
    Prostopadloscian(double width,double length,double height,drawNS::Draw3DAPI *api);
    void Rysuj() override;
    /*!
    * \brief Metoda obracająca prostopadłościan
    * 
    * Zmienia macierz orientacji obiektu o wybrany kat
    * (W osi z). Obrót następuje błyskawicznie(nie jest 
    * animowany) \n
    * \param[in] kat - wartość kąta, o który ma zostać obrócony obiekt 
    */
    void Obroc(double kat);
    /*!
    * \brief Metoda przesuwająca prostopadłościan
    * 
    * Zmienia położenie obiektu w przód
    * o wybraną odległość. Ruch następuje błyskawicznie
    * (nie jest animowany) \n
    * \param[in] odl - odległość o jaką obiekt ma się przesunąć
    */
    void Ruszaj(double odleglosc);
    /*!
    * \brief Metoda ruszająca prostopadłościanem w osi z
    * 
    * Zmienia położenie obiektu w osi z
    * o wybraną wartość. Ruch następuje błyskawicznie
    * (nie jest animowany) \n
    * \param[in] odl - odleglosc o jaka ma sie wzniesc/opasc obiekt
    */
    void Wznies_Opusc(double odl);
    void Wymaz() override;
    bool czy_kolizja(std::shared_ptr<Interfejs> drone) const override;
};
#endif