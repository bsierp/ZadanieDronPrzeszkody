#ifndef DRON_HH
#define DRON_HH
/*!
 * \file
 * \brief Definicja klasy Dron
 *
 * Plik zawiera definicje klasy Dron,
 * oraz deklaracje metod tej klasy.
 */
#include "Prostopadloscian.hh"
#include "Interfejs.hh"
#include "Sruba.hh"
/*!
* \brief Model pojęcia Dron
*
* Klasa modeluje pojęcie drona, który
* dziedziczy publicznie po klasie Interfejs
* oraz klasie Prostopadloscian.
*/
class Dron:public Prostopadloscian,public Interfejs{
    protected:
    /*!
    * \brief Wirniki drona
    * 
    * W tablicy przechowywane są wirniki drona,
    * które obracają się podczas ruchu drona
    */
    Sruba wirnik[2];
    /*!
    * \brief Metoda ustawiająca wirniki
    * 
    * Metoda ustawia wirniki na podstawie
    * aktualnej pozycji i orientacji drona
    */
    void Ustaw_Sruby();
    public:
    /*!
    * \brief Konstruktor czteroparametryczny klasy Dron
    * 
    * Konstruktor wypełnia tablicę wymiarów drona parametrami konstruktora. \n
    * Dodatkowo na podstawie tych wymiarów tworzy śruby, znajdujące się z tyłu 
    * drona. Stosunek długości śruby do długości drona zdefiniowany jest przez stałą
    * PROPELLER_DRONE_LENGTH_RATIO \n
    * \param[in] width - szerokość drona (wymiar w osi x)
    * \param[in] length - długość drona (wymiar w osi y)
    * \param[in] height - wysokość drona (wymiar w osi z)
    * \param[in] api - wskaźnik do programu graficznego, w którym ma być rysowany dron
    */
    Dron(double width, double length, double height, drawNS::Draw3DAPI *api);
    /*!
    * \brief Metoda rysująca drona
    * 
    * Rysuje drona w programie graficznym, do którego
    * wskaźnik posiada obiekt. 
    */
    void rysuj_drona();
    /*!
    * \brief Metoda wymazująca drona
    * 
    * Wymazuje drona z programu graficznego.
    */
    void wymaz_drona();
    double zwroc_promien_drona()const override;
    void ruch_drona(double odl) override;
    void obrot_drona(double kat_obr) override;
    void wznies_opusc_drona(double odl) override;
    bool czy_kolizja(std::shared_ptr <Interfejs> drone)const override;
    const Wektor <double,3> & zwroc_srodek() const override;
};
#endif