#include"Mac.cpp"
template class Macierz<double,3>;
template std::istream & operator>>(std::istream & strm,Macierz<double,3> &Mac);
template std::ostream & operator<<(std::ostream & strm,const Macierz<double,3> &Mac);