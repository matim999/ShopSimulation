#include <iostream>
#include <typeinfo>
#include <cstdlib>
#include <time.h>

using namespace std;

class data
{
public:
    int dzien;
    int miesiac;
    int rok;
    data():dzien(0),miesiac(0),rok(0){};
    data(int d, int m, int y):dzien(d),miesiac(m),rok(y){};
    data(const data &);
    data operator+(int);
    bool operator!=(const data&);
    int przeter(const data &);
    friend ostream& operator<< (ostream &, const data &);
    friend ostream& operator<< (ostream & out, const data *);
};

data dzis(19,1,2017);

int data::przeter(const data & termin)
{
    if (dzis.rok < termin.rok)
        return 0;
    else if (dzis.miesiac < termin.miesiac)
        return 0;
    else if (dzis.dzien < termin.dzien)
        return 0;
    return 1;
}


data::data(const data& da)
{
    dzien = da.dzien;
    miesiac = da.miesiac;
    rok = da.rok;
}

ostream& operator<< (ostream & out, const data & p)
{
    out << p.dzien << "." << p.miesiac << "." << p.rok <<"r";
    return out;
}

ostream& operator<< (ostream & out, const data* p)
{
    out << p->dzien << "." << p->miesiac << "." << p->rok << "r";
    return out;
}

bool data::operator!=(const data& da)
{
    if(dzien!=da.dzien) return 1;
    if(miesiac!=da.miesiac) return 1;
    if(rok!=da.rok) return 1;
    return 0;
}

data data::operator+(int n)
{
    dzien += n;
    while(dzien>31)
    {
        miesiac++;
        dzien -=31;
        if(miesiac>12)
        {
            rok++;
            miesiac-=12;
        }
    }
}

class produkt;
ostream& operator<< (ostream &, const produkt &);
ostream& operator<< (ostream & out, const produkt *);
istream& operator>> (istream &, produkt &);
istream& operator>> (istream & in, produkt *);

class produkt
{
        public:
                string nazwa;
                float cena_kupna;
                float cena_sprzedazy;
                data dzien_zakupu;
                data termin;
        public:
                static int ilosc_produktu;
                //static void ilosc_sztuk();
                produkt(){};
                produkt(const produkt&);
                //produkt():nazwa("Nieznany"),cena_kupna(0),cena_sprzedazy(0),dzien_zakupu(0,0,0),termin(0,0,0){ilosc_produktu++;};
                produkt(string nazwa,float cena_kupna, float cena_sprzedazy, data dzien_zakupu):nazwa(nazwa),
                                cena_kupna(cena_kupna),cena_sprzedazy(cena_sprzedazy),dzien_zakupu(dzien_zakupu),termin(dzien_zakupu){ilosc_produktu++;};
                virtual void termin_waznosci() = 0;
                produkt* next = NULL;
                //produkt* kopia(produkt &);
                friend ostream& operator<< (ostream &, const produkt &);
                friend ostream& operator<< (ostream & out, const produkt *);
                friend istream& operator>> (istream & in, produkt *);
                friend istream& operator>> (istream &, produkt &);
                string getnazwa(){return this->nazwa;};
                float getcena_kupna(){return this->cena_kupna;};
                virtual ~produkt(){/*{cout << "Destruktor produkt" << endl;*/ilosc_produktu--;};
};

/*produkt* produkt::kopia(produkt & pr)
{

    nazwa = pr.nazwa;
    cena_kupna = pr.cena_kupna;
    cena_sprzedazy = pr.cena_sprzedazy;
    dzien_zakupu = pr.dzien_zakupu;
    termin = pr.termin;
    ilosc_produktu++;
    next = NULL;
    return this;
}*/

produkt::produkt(const produkt& pr)
{
    nazwa = pr.nazwa;
    cena_kupna = pr.cena_kupna;
    cena_sprzedazy = pr.cena_sprzedazy;
    dzien_zakupu = pr.dzien_zakupu;
    termin = pr.termin;
    ilosc_produktu++;
    next = NULL;
}

int produkt::ilosc_produktu = 0;

ostream& operator<< (ostream & out, const produkt & p)
{
    out << p.nazwa << ". Kupno za: " << p.cena_kupna << ". Sprzedaz za: " << p.cena_sprzedazy <<
            ". Data zakupu: " << p.dzien_zakupu << ". Termin waznosci: " << p.termin << "." << endl;
    return out;
}

ostream& operator<< (ostream & out, const produkt* p)
{
    out << "Produkt: " << p->nazwa << ". Kupiono za: " << p->cena_kupna << ". Sprzedawane za: " << p->cena_sprzedazy <<
            ". Data zakupu: " << p->dzien_zakupu << ". Termin waznosci: " << p->termin << "." << endl;
    return out;
}

istream& operator>> (istream & in, produkt & p)
{
    cout << "Podaj nazwe: ";
    in >> p.nazwa;
    cout << endl;
    cout << "Podaj cene kupna: ";
    in >> p.cena_kupna;
    cout << endl;
    cout << "Podaj cene sprzedazy: ";
    in >> p.cena_sprzedazy;
    cout << endl;
    return in;
}

istream& operator>> (istream & in, produkt*  p)
{
    cout << "Podaj nazwe: ";
    in >> p->nazwa;
    cout << endl;
    cout << "Podaj cene kupna: ";
    in >> p->cena_kupna;
    cout << endl;
    cout << "Podaj cene sprzedazy: ";
    in >> p->cena_sprzedazy;
    cout << endl;
    return in;
}

class nabial:public produkt
{
    public:
        static int ilosc_produktu;
        nabial():produkt(){};
        nabial(const nabial&);
        nabial(string nazwa,float cena_kupna, float cena_sprzedazy, data dzien_zakupu):
                    produkt(nazwa,cena_kupna,cena_sprzedazy,dzien_zakupu){ilosc_produktu++;};
        void termin_waznosci();
        static void ilosc_sztuk();
        nabial* next = NULL;
        //nabial* kopia(nabial &);
        ~nabial(){/*cout << "Destruktor nabial" << endl;*/ilosc_produktu--;};
};

nabial::nabial(const nabial& pr)
{
    nazwa = pr.nazwa;
    cena_kupna = pr.cena_kupna;
    cena_sprzedazy = pr.cena_sprzedazy;
    dzien_zakupu = pr.dzien_zakupu;
    termin = pr.termin;
    ilosc_produktu++;
    next = NULL;
}

int nabial::ilosc_produktu = 0;

void nabial::ilosc_sztuk()
{
    cout << "W tej chwili posiadasz " << ilosc_produktu << " sztuk nabialu." << endl;
}

void nabial::termin_waznosci()
{
        //cout << endl << "wykonuje termin waznosci" << endl;
        dzien_zakupu = dzis;
        termin = dzis;
        termin + 2;
}

class mieso:public produkt
{
    public:
        static int ilosc_produktu;
        mieso():produkt(){};
        mieso(const mieso&);
        mieso(string nazwa,float cena_kupna, float cena_sprzedazy, data dzien_zakupu):
                    produkt(nazwa,cena_kupna,cena_sprzedazy,dzien_zakupu){ilosc_produktu++;};
        void termin_waznosci();
        static void ilosc_sztuk();
        mieso* next = NULL;
        //mieso* kopia(mieso &);
        ~mieso(){/*cout << "Destruktor mieso" << endl;*/ilosc_produktu--;};
};

/*mieso* mieso::kopia(mieso & pr)
{
    nazwa = pr.nazwa;
    cena_kupna = pr.cena_kupna;
    cena_sprzedazy = pr.cena_sprzedazy;
    dzien_zakupu = pr.dzien_zakupu;
    termin = pr.termin;
    ilosc_produktu++;
    mieso* next = NULL;
    return this;
}*/

mieso::mieso(const mieso& pr)
{
    nazwa = pr.nazwa;
    cena_kupna = pr.cena_kupna;
    cena_sprzedazy = pr.cena_sprzedazy;
    dzien_zakupu = pr.dzien_zakupu;
    termin = pr.termin;
    ilosc_produktu++;
    next = NULL;
}

int mieso::ilosc_produktu = 0;

void mieso::ilosc_sztuk()
{
    cout << "W tej chwili posiadasz " << ilosc_produktu << " sztuk miesa." << endl;
}

void mieso::termin_waznosci()
{
        //cout << endl << "wykonuje termin waznosci" << endl;
        dzien_zakupu = dzis;
        termin = dzis;
        termin + 2;
}

class slodycze:public produkt
{
    public:
        slodycze():produkt(){};
        slodycze(const slodycze&);
        static int ilosc_produktu;
        slodycze(string nazwa,float cena_kupna, float cena_sprzedazy, data dzien_zakupu):
                    produkt(nazwa,cena_kupna,cena_sprzedazy,dzien_zakupu){ilosc_produktu++;};
        void termin_waznosci();
        static void ilosc_sztuk();
        slodycze* next = NULL;
        //slodycze* kopia(slodycze &);
        ~slodycze(){/*cout << "Destruktor slodycze" << endl;*/ilosc_produktu--;};
};

slodycze::slodycze(const slodycze& pr)
{
    nazwa = pr.nazwa;
    cena_kupna = pr.cena_kupna;
    cena_sprzedazy = pr.cena_sprzedazy;
    dzien_zakupu = pr.dzien_zakupu;
    termin = pr.termin;
    ilosc_produktu++;
    next = NULL;
}

/*slodycze* slodycze::kopia(slodycze & pr)
{
    nazwa = pr.nazwa;
    cena_kupna = pr.cena_kupna;
    cena_sprzedazy = pr.cena_sprzedazy;
    dzien_zakupu = pr.dzien_zakupu;
    termin = pr.termin;
    ilosc_produktu++;
    slodycze* next = NULL;
    return this;
}*/

int slodycze::ilosc_produktu = 0;

void slodycze::ilosc_sztuk()
{
    cout << "W tej chwili posiadasz " << ilosc_produktu << " sztuk slodyczy." << endl;
}

void slodycze::termin_waznosci()
{
        //cout << "wykonuje termin waznosci" << endl;
        dzien_zakupu = dzis;
        termin = dzis;
        termin + 10;
}

//class szelf;
//iterator& operator++();

template<typename t1>class szelf
{
        public:
                class iterator {
                public:
                    // aby interator by³ kompatybilny z STL’em nale¿y zdefiniowaæ poni¿sze typdef’y
                    typedef std::forward_iterator_tag iterator_category;
                    typedef t1 value_type;
                    typedef t1* pointer;
                    typedef t1& reference;
                    typedef size_t size_type;
                    typedef ptrdiff_t difference_type;
                    iterator( t1* init = 0 ) : current(init) {}
                    t1& operator*() { return current->data; }
                    const t1& operator*() const {
                    return current->data;
                    }
                    iterator& operator++() {
                    if ( current ) current = current->next;
                    return *this;
                    }
                    iterator operator++(int) {
                    iterator temp = *this;
                    ++*this;
                    return temp;
                    }
                    bool operator==(const iterator& x) const {
                    return current == x.current;
                    }
                    bool operator!=(const iterator& x) const {
                    return current != x.current;
                    }
                    t1* current;
                };
        private:
                //typedef szelf<t1>::
                iterator ptri;
                t1* pocz = NULL;
                t1* koniec = NULL;
                t1* ptr = NULL;
                int ilosc_produktu = 0;
        public:
                //iterator& operator++(t1*);
                //int ilosc_produktu;
                void ilosc_sztuk();
                void ilosc_sztukmag();
                szelf();
                szelf(t1* el);
                void push(t1* el);
                void pop(t1* el);
                void pop();
                void usun_termin();
                void rysuj();
                float kup(int);
                void wypisz();
                void wypisz2(int);
                void pokaz();
                t1* wez(int);
                bool pusty();
                ~szelf();
};

/*template<typename t1>iterator<t1>& operator++()
{
    if (current) current = current->next;
    return *this;
}*/
//typedef Kontener<T>::iterator ptri;


template<typename t1>szelf<t1>::~szelf()
{
    //cout << "usuwam stos" << endl;
    /*t1* p;
    p = pocz;
    while(p != NULL)
    {
        pocz = p;
        p = pocz->next;
        delete pocz;
    }
    /*t1* pocz = NULL;
    t1* koniec = NULL;
    t1* ptr = NULL;
    delete pocz;
    delete koniec;
    delete ptr;*/
}

//int szelf::ilosc_produktu = 0;

template<typename t1>void szelf<t1>::ilosc_sztuk()
{
    cout << "W tej chwili posiadasz " << ilosc_produktu << " sztuk na polce z " << typeid(t1).name() << "." << endl;
}

template<typename t1>void szelf<t1>::ilosc_sztukmag()
{
    cout << "W tej chwili posiadasz " << ilosc_produktu << " sztuk w magazynie." << endl;
}

template<typename t1>szelf<t1>::szelf()
{
    ilosc_produktu = 1;
}

template<typename t1>szelf<t1>::szelf(t1* el)
{
        //cout << "inicjuje szelf o poczatku: " << el->getnazwa() << endl;
        koniec = el;
        pocz = el;
        ilosc_produktu = 1;
}

template<typename t1>void szelf<t1>::push(t1* el)
{
        if(ilosc_produktu==0)
        {
                koniec = el;
                pocz = el;
                ilosc_produktu = 1;
        }
        else
        {
            //cout << "Dodaje do stosu: " << el->getnazwa()  << el->getcena_kupna() << endl;
            if(ilosc_produktu==1) pocz->next = el;
            else koniec->next = el;
            koniec = el;
            ilosc_produktu++;
        }
}

template<typename t1>void szelf<t1>::pop()
{
        ptr = pocz;
        if(pocz == koniec)
        {
            //cout << "Usuwam ze stosu poczatek: " << pocz->getnazwa() << pocz->getcena_kupna() << endl;
            ilosc_produktu--;
            this->~szelf();
        }
        else
        {
            while((ptr->next)->next != NULL)
            {
                    ptr = ptr->next;
                    //ptr++;
            }
            //cout << "Usuwam ze stosu: " << (ptr->next)->getnazwa() << (ptr->next)->getcena_kupna() << endl;
            koniec = ptr;
            koniec->next = NULL;
            ilosc_produktu--;
        }
}

template<typename t1>void szelf<t1>::pop(t1* el)
{
        ptr = pocz;
        if(el == pocz)
        {
            //cout << "Usuwam ze stosu poczatek: " << pocz->getnazwa() << pocz->getcena_kupna() << endl;
            pocz = pocz->next;
            delete el;
            ilosc_produktu--;
        }
        else if(el == koniec)
        {
            //cout << "Usuwam ze stosu poczatek: " << pocz->getnazwa() << pocz->getcena_kupna() << endl;
            pop();
            ilosc_produktu--;
        }
        else
        {
            while(ptr->next != el)
            {
                    ptr = ptr->next;
                    //ptr++;
            }
            //cout << "Usuwam ze stosu: " << (ptr->next)->getnazwa() << (ptr->next)->getcena_kupna() << endl;
            ptr->next = el->next;
            delete el;
            ilosc_produktu--;
        }
}

template<typename t1>float szelf<t1>::kup(int kli)
{
        float kasa;
        if(ilosc_produktu==0)
        {
             cout << "Niestety brakuje " << typeid(t1).name() << endl;
             return 0;
        }
        else if(ilosc_produktu==1)
        {
             kasa = pocz->getcena_kupna();
             ilosc_produktu--;
             if(dzis.przeter(pocz->termin))
             {
                 cout << "UWAGA! Klient kupil produkt przeterminowany placisz kaucie 100zl" << endl;
                 kasa -=100;
             }
             return kasa;
        }
        ptr = pocz;
        while((ptr->next)->next != NULL)
        {
                ptr = ptr->next;
        }
        cout << "Klient nr " << kli+1 << " kupil " << (ptr->next)->getnazwa() << " za " << (ptr->next)->getcena_kupna() << endl;
        kasa = (ptr->next)->getcena_kupna();
        if(dzis.przeter((ptr->next)->termin))
             {
                 cout << "UWAGA! Klient kupil produkt przeterminowany placisz kaucie 100zl" << endl;
                 kasa -=100;
             }
        koniec = ptr;
        koniec->next = NULL;
        delete ptr->next;
        ilosc_produktu--;
        return kasa;
}

template<typename t1>bool szelf<t1>::pusty()
{
    if(ilosc_produktu == 0) return 1;
    return 0;
}

template<typename t1>void szelf<t1>::usun_termin()
{
        ptr = pocz;
        if(ilosc_produktu)
        {
            while(ptr != NULL)
                {
                    if(dzis.przeter(ptr->termin))
                    {
                        cout << "Wyrzucam: " << ptr->getnazwa() << endl;
                        pop(ptr);
                    }
                    ptr = ptr->next;
                }
        }
}


template<typename t1>void szelf<t1>::wypisz()
{
        ptri = pocz;
        if(ilosc_produktu == 0)
        {
            cout << "JEST PUSTY" << endl;
        }
        else
        {
            while(ptri != NULL)
                {
                    cout << ptri.current;
                    ptri++;
                    //ptr = ptr->next;
                }
        }
}
template<typename t1>void szelf<t1>::wypisz2(int n)
{
        ptri = pocz;
        if(ilosc_produktu == 0)
        {
            cout << "JEST PUSTY" << endl;
        }
        else
        for(int i=0;i<n-1;i++) ptri++;
        cout << ptri.current;
}

template<typename t1>void szelf<t1>::rysuj()
{
        string* t = new string[10];
        int npr = 0;
        ptr = pocz;
        while(ptr != NULL)
        {
            t[npr] = ptr->getnazwa();
            ptr = ptr->next;
            npr++;
        }
        int lspace = 20, mspace = 0;
        for(int i=0;i<6;i++)
        {
            cout.width(lspace);
            cout << right << "*";
            cout.width(mspace);
            cout << right << "*";
            lspace--;
            if(i==0) mspace+=3;
            else mspace+=2;
            cout << endl;
        }
        cout.width(39);
        cout << right << "**************************************"  << endl;
        lspace = 2;
        mspace = 37;
        for(int i=0;i<9-npr;i++)
        {
            cout.width(lspace);
            cout << right << "*";
            cout.width(mspace);
            cout << right << "*";
            lspace++;
            mspace-=2;
            cout << endl;
        }
        int j=npr;
        if(ilosc_produktu)
        {
            for(int i=0;i<j;i++)
            {
                cout.width(lspace);
                cout << right << "*";
                cout.width(2);
                cout << right << npr;
                cout.width(10);
                cout << right << t[npr-1];
                cout.width(mspace-12);
                cout << right << "*";
                lspace++;
                mspace-=2;
                cout << endl;
                npr--;
            }
        }
        else
        {
                cout.width(lspace);
                cout << right << "*";
                cout.width(mspace);
                cout << right << "*";
                lspace++;
                mspace-=2;
                cout << endl;
        }
        cout.width(30);
        cout << right << "********************" << endl;
}

template<typename t1>void szelf<t1>::pokaz()
{
        string* t = new string[10];
        float cena[10] = {0};
        data* ter = new data[10];
        data d(0,0,0);
        int i=0;
        ptr = pocz;
        while(ptr != NULL)
        {
            t[i] = ptr->getnazwa();
            cena[i] = ptr->getcena_kupna();
            ter[i] = ptr->termin;
            i++;
            //cout.width(10);
            //cout << ptr->getnazwa();
            ptr = ptr->next;
        }
        for(i=0;i<10;i++)
        {
            cout.width( 13 );
            cout << left << "_____________";
            cout << "_";
        }
        cout << endl;
        for(int j=0;j<5;j++)
        {
            if(j==1)
            {
                for(i=0;i<10;i++)
                {
                    cout << "|";
                    if(ilosc_produktu)
                    {
                        if(t[i]!="")
                        {
                            cout.width( 1 );
                            cout << i+1 <<".";
                        }
                        else
                        {
                            cout.width( 2 );
                            cout << "";
                        }
                        cout.width( 10 );
                        cout << t[i];
                        cout << "|";
                    }
                    else
                    {
                        cout.width( 13 );
                        cout << right << "|";
                    }
                }
            }
            else if(j==2)
            {
                for(i=0;i<10;i++)
                {
                    cout << "|";
                    if(ilosc_produktu)
                    {
                        cout.width( 12 );
                        if(cena[i]>0.01) cout << cena[i];
                        else cout << "";
                        cout << "|";
                    }
                    else
                    {
                        cout.width( 13 );
                        cout << right << "|";
                    }
                }
            }
            else if(j==3)
            {
                for(i=0;i<10;i++)
                {
                    cout << "|";
                    if(ilosc_produktu)
                    {
                        if(ter[i] != d)
                        {
                            cout << ter[i];
                            cout.width( 3 );
                            cout << right <<"|";
                        }
                        else
                        {
                            cout.width( 13 );
                            cout << right <<"|";
                        }
                    }
                    else
                    {
                        cout.width( 13 );
                        cout << right << "|";
                    }
                }
            }
            else
            {
                for(i=0;i<10;i++)
                {
                    cout.width( 13 );
                    cout << left << "|";
                    cout << "|";
                }
            }
            cout << endl;
        }
        for(i=0;i<10;i++)
        {
            cout.width( 13 );
            cout << left << "*************";
            cout << "*";
        }
        cout << endl;
}

template<typename t1>t1* szelf<t1>::wez(int n)
{
    int i;
    ptr = pocz;
    t1* point;
    if(pocz == koniec)
    {
        point = pocz;
        ilosc_produktu --;
        this->~szelf();
    }
    else if(n==1)
    {
        point = pocz;
        pocz = pocz -> next;
        ilosc_produktu --;
    }
    else if(n==ilosc_produktu)
    {
        point = koniec;
        pop();
        ilosc_produktu --;
    }
    else
    {
        for(i=1;i<n-1;i++)
        {
            ptr = ptr->next;
        }
        point = ptr->next;
        ptr->next = (ptr->next)->next;
        ilosc_produktu --;
    }
    return point;
}
/*void operator++ (produkt & el)
{
    el = el->next;
}*/
produkt* kopia(produkt & pr)
{
    produkt* nowy;
    nowy->nazwa = pr.nazwa;
    nowy->cena_kupna = pr.cena_kupna;
    nowy->cena_sprzedazy = pr.cena_sprzedazy;
    nowy->dzien_zakupu = pr.dzien_zakupu;
    nowy->termin = pr.termin;
    nowy->ilosc_produktu++;
    nowy->next = NULL;
    return nowy;
}

/*void produkt::ilosc_sztuk()
{
    cout << "W tej chwili posiadasz " << slodycze::ilosc_produktu+nabial::ilosc_produktu+mieso::ilosc_produktu+produkt::ilosc_produktu << " wszystkich produktow." << endl;
}*/

