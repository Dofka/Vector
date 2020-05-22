#ifndef HEADER_H
#define HEADER_H


#include <bits/stdc++.h>
#include <vector>
#include <limits>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <string>
#include <sys/time.h>


using std::string;
using std::deque;
using std::list;
using std::ofstream;
using std::ifstream;
using std::sort;
using std::cout;
using std::cin;
using std::endl;

template <class T> 
   class Vector {
    public: // interfeisas
      typedef T* iterator;
      typedef const T* const_iterator;
      typedef size_t size_type;
      typedef T value_type;
      // rule of three
      Vector() { create(); }
      explicit Vector(size_type n, const T& t = T{}) { create(n, t); }
      Vector(const Vector& v) { create(v.begin(), v.end()); }
  
      Vector& operator=(const Vector&);
      ~Vector() { uncreate(); }
  
      T& operator[](size_type i) { return data[i]; }
      const T& operator[](size_type i) const { return data[i]; }
      void push_back(const T& t) {
        if (avail == limit)
          grow();
        unchecked_append(t);
      }

      size_type size() const { return avail - data; }
      size_type capacity() const { return limit - data; }
      iterator begin() { return data; }
      const_iterator begin() const { return data; }
      iterator end() { return avail; }
      const_iterator end() const { return avail; }
      

    // likusi interfeiso realizacija
    private:
      iterator data; // pakeista iš T* į iterator
      iterator avail; // pirmasis po paskutiniojo sukonstruoto Vector elementas
      iterator limit; // pakeista iš T* į iterator

      // atminties išskyrimo valdymui
      std::allocator<T> alloc; // objektas atminties valdymui
      // išskirti atmintį (array) ir ją inicializuoti
      void create();
      void create(size_type, const T&);
      void create(const_iterator, const_iterator);
      // sunaikinti elementus array ir atlaisvinti atmintį
      void uncreate();
      // pagalbinės funkcijos push_back realizacijai
      void grow();
      void unchecked_append(const T&);
};

template <class T> 
  void Vector<T>::create() {
    data = avail = limit = nullptr;
  }
template <class T> 
  void Vector<T>::create(size_type n, const T& val) {
    data = alloc.allocate(n); // grąžina ptr į array pirmą elementą
    limit = avail = data + n; // sustato rodykles į vietas
    std::uninitialized_fill(data, limit, val); // inicializuoja elementus val reikšme
  }
template <class T>
  void Vector<T>::create(const_iterator i, const_iterator j) {
    data = alloc.allocate(j - i); // išskirti vietos j-i elementams
    limit = avail = std::uninitialized_copy(i, j, data); // nukopijuoja elementus iš intervalo
  }

template <class T> 
  void Vector<T>::uncreate() {
    if (data) {
    // sunaikinti (atbuline tvarka) sukonstruotus elementus
      iterator it = avail;
      while (it != data)
        alloc.destroy(--it);
      // atlaisvinti išskirtą atmintį. Turi būti data != nullptr
      alloc.deallocate(data, limit - data);
    }
    // reset'inam pointer'iuss - Vector'ius tuščias
    data = limit = avail = nullptr;
  }

template <class T> 
  void Vector<T>::grow() {
    // dvigubai daugiau vietos, nei buvo
    size_type new_size = std::max(2 * (limit - data), ptrdiff_t(1));
    // išskirti naują vietą ir perkopijuoti egzistuojančius elementus
    iterator new_data = alloc.allocate(new_size);
    iterator new_avail = std::uninitialized_copy(data, avail, new_data);
    // atlaisvinti seną vietą
    uncreate();
    // reset'int rodykles į naujai išskirtą vietą
    data = new_data;
    avail = new_avail;
    limit = data + new_size;
  }
// tariame, kad `avail` point'ina į išskirtą, bet neinicializuotą vietą
template <class T> 
  void Vector<T>::unchecked_append(const T& val) {
    alloc.construct(avail++, val);
  }

// priskyrimo operatoriaus realizacija
template <class T>
  Vector<T>& Vector<T>::operator=(const Vector& rhs) {
    // patikriname ar ne lygu
    if (&rhs != this) {
    // atlaisviname seną this objekto atmintį
      uncreate();
      // perkopijuojame elementus iš rhs į lhs (this)
      create(rhs.begin(), rhs.end());
    }
    return *this;
  }

template<class T> class allocator {
  public:
    T* allocate(size_t); // išskirti `raw` atmintį
    void deallocate(T*, size_t); // atlaisvinti atmintį
    void construct(T*, const T&); // sukonstruoti 1 objektą
    void destroy(T*); // sunaikinti 1 objektą
};


class Studentas {
// realizacija
private:
  string vardas;
  string pavarde;
  double egzaminas, galutinis;
  Vector<double> C;
// interfeisas
public:
  const Studentas operator=(const Studentas &stud){
      if(this == &stud)
      return *this;

      this->vardas = stud.vardas;
      this->pavarde = stud.pavarde;
      this->galutinis = stud.galutinis;
      this->egzaminas = stud.egzaminas;

      return *this;
  }
  void setVardas(string v)
  {
      vardas = v;
  }
  void setPavarde(string p)
  {
      pavarde = p;
  }
  void setGalutinis(double g)
  {
      galutinis = g;
  }
  void setEgzaminas(double e)
  {
      egzaminas = e;
  }
  string getVardas(){
      return vardas;
  }
  string getPavarde(){
      return pavarde;
  }
  double getGalutinis(){
      return galutinis;
  }
  double getEgzaminas(){
      return egzaminas;
  }
};

/*struct Studentas{
string vardas, pavarde;
vector<int> C;
int egzaminas;
float galutinis;
};*/

ofstream& operator<<(ofstream& , Studentas&);
string IntToStr(int );
Vector<Studentas> skirstykStudentusNetrinant(Vector<Studentas>&);
Vector<Studentas> skirstykStudentusTrinant(Vector<Studentas>&);
//void GalBalas(deque<Studentas>& );
bool comparePagalVarda( Studentas& ,  Studentas& );
bool comparePagalPavarde( Studentas& ,  Studentas& );
bool comparePagalGalutini( Studentas& ,  Studentas& );

#endif
