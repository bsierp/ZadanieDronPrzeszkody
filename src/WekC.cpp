#include "Wek.cpp"
template class Wektor<double,3>;
template std::istream & operator>>(std::istream & strm, Wektor<double,3> & W);
template std::ostream & operator<<(std::ostream & strm,const Wektor<double,3> & W);
