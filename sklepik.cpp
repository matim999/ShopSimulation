#include "sklepik.h"

int main(){
        int i=1,otwarte=1,first,choose;
        int kn=0,km=0,ks=0,kp=0;
        int ilosc,kupuje;
        float suma = 0;
        string c;
        float portfel = 1000;
        nabial* ptrn = new nabial[70];
        mieso* ptrm = new mieso[70];
        slodycze* ptrs = new slodycze[70];

        nabial* nabialy = new nabial[5];
        mieso* miesa = new mieso[4];
        slodycze* slodkosci = new slodycze[5];
                        //NABIAL//
        nabialy[0] = nabial("Ser",17.49,25.99,dzis);
        nabialy[1] = nabial("Mleko",1.99,2.99,dzis);
        nabialy[2] = nabial("Jogurt",0.49,1.59,dzis);
        nabialy[3] = nabial("Jajka",3.50,5.60,dzis);
        nabialy[4] = nabial("Maslo",3.00,4.99,dzis);
                        //MIESO//
        miesa[0] = mieso("Szynka",13.99,22.99,dzis);
        miesa[1] = mieso("Kurczak",5.49,8.59,dzis);
        miesa[2] = mieso("Boczek",5.50,9.60,dzis);
        miesa[3] = mieso("Stejk",15.77,23.55,dzis);
                        //SLODYCZE//
        slodkosci[0] = slodycze("Czekolada",2.49,4.99,dzis);
        slodkosci[1] = slodycze("Cukierki",12.99,21.99,dzis);
        slodkosci[2] = slodycze("Batonik",1.49,2.59,dzis);
        slodkosci[3] = slodycze("Lizak",1.50,2.60,dzis);
        slodkosci[4] = slodycze("Ciastka",11.00,17.99,dzis);

        cout << "Zaczynamy sprzedawac..." << endl;
        cout << "Na poczatek dostajesz kilka produktow na polki i do magazynu." << endl;

        produkt* ptrp;
        ptrs[ks]=slodkosci[3];
        ptrp = &ptrs[ks]; ks++;
        ptrp->termin_waznosci();
        szelf<produkt> magazyn(ptrp);
        ptrs[ks]=slodkosci[4];
        ptrp = &ptrs[ks]; ks++;
        ptrp->termin_waznosci();
        magazyn.push(ptrp);
        ptrm[km]=miesa[3];
        ptrp = &ptrm[km]; km++;
        ptrp->termin_waznosci();
        magazyn.push(ptrp);
        ptrs[ks]=slodkosci[2];
        ptrp = &ptrs[ks]; ks++;
        ptrp->termin_waznosci();
        magazyn.push(ptrp);
        ptrn[kn]=nabialy[3];
        ptrn = &ptrn[kn]; kn++;
        ptrn->termin_waznosci();
        szelf<nabial> n(ptrn);
        ptrn[kn]=nabialy[2];
        ptrn = &ptrn[kn]; kn++;
        ptrn->termin_waznosci();
        n.push(ptrn);
        ptrn[kn]=nabialy[1];
        ptrn = &ptrn[kn]; kn++;
        ptrn->termin_waznosci();
        n.push(ptrn);
        ptrm[km]=miesa[0];
        ptrm = &ptrm[km]; km++;
        ptrm->termin_waznosci();
        szelf<mieso> m(ptrm);
        ptrm[km]=miesa[2];
        ptrm = &ptrm[km]; km++;
        ptrm->termin_waznosci();
        m.push(ptrm);
        ptrm[km]=miesa[3];
        ptrm = &ptrm[km]; km++;
        ptrm->termin_waznosci();
        m.push(ptrm);
        ptrs[ks]=slodkosci[0];
        ptrs = &ptrs[ks]; ks++;
        ptrs->termin_waznosci();
        szelf<slodycze> s(ptrs);
        ptrs[ks]=slodkosci[3];
        ptrs = &ptrs[ks]; ks++;
        ptrs->termin_waznosci();
        s.push(ptrs);
        ptrs[ks]=slodkosci[2];
        ptrs = &ptrs[ks]; ks++;
        ptrs->termin_waznosci();
        s.push(ptrs);

        while(otwarte)
        {
            cout << endl;
            cout << "Dzisiaj jest: " << dzis << endl;
            cout <<  "W tej chwili masz na koncie:" << portfel << "zl." << endl << endl
            << "Co teraz chcesz zrobic? Wcisnij odpowiednio:\n1. Sprawdzic produkty w sklepie\n2. Sprawdzic magazyn\n3. Isc do hurtowni\n4. Czekaj na klientow\n5. Sam zrob zakupy\n6. Zamknij sklep (nastepny dzien)\n7. Zakonczyc dzialalnosc" << endl;
            cin >> first;
            switch(first)
            {
            case 1:
                cout << endl;
                cout << "Ktora polke chcesz sprawdzic dokladnie?\n1. Polke z nabialem\n2. Polke z miesem\n3. Polke ze sloduczami\n4. Wyrzucic przeterminowane produkty\n5. Chce tylko wiedizec ile poszczegolnych produktow jest w sklepie" <<endl;
                cin >> first;
                switch(first)
                {
                case 1:
                    n.pokaz();
                    break;
                case 2:
                    m.pokaz();
                    break;
                case 3:
                    s.pokaz();
                    break;
                case 4:
                    n.usun_termin();
                    m.usun_termin();
                    s.usun_termin();
                    break;
                case 5:
                    n.ilosc_sztuk();
                    m.ilosc_sztuk();
                    s.ilosc_sztuk();
                    magazyn.ilosc_sztukmag();
                    //produkt::ilosc_sztuk();
                    break;
                }
                break;
            case 2:
                cout << endl << "Magazyn:" << endl;
                magazyn.wypisz();
                //magazyn.pokaz();
                if(magazyn.pusty())
                {
                    cout << "Dowolny znak aby powrocic" << endl;
                    cin >> c;
                    break;
                }
                cout << "Czy chcesz cos wziac z magazynu?\n1. TAK\n2. NIE\n3. Wyrzucic przeterminowane produkty\n4. Pokaz konkretny produkt za pomoca iteratora" << endl;
                cin >> first;
                switch(first)
                {
                case 1:
                    cout << endl;
                    cout << "Podaj nr produktu: ";
                    cin >> choose;
                    cout << endl;
                    {
                        produkt* magptr;
                        magptr = magazyn.wez(choose);
                        //cout << magptr;
                        //cout << typeid(*magptr).name() << endl;
                        //cout << typeid(*ptrs).name() << endl;
                        if((typeid(*magptr).name()) == (typeid(*ptrs).name()))
                        {
                            ptrs[ks] = (*(dynamic_cast<slodycze*>(magptr)));
                            ptrs = &ptrs[ks]; ks++;
                            //ptrs = ptrs[ks].kopia(*(dynamic_cast<slodycze*>(magptr))); ks++;
                            s.push(ptrs);
                            cout << "Biore z magazynu .." << ptrs->getnazwa() << ".. i klade na polce ze slodyczami." << endl;
                            delete magptr; ks--;
                        }
                        else if((typeid(*magptr).name()) == (typeid(*ptrm).name()))
                        {
                            ptrm[km] = (*(dynamic_cast<mieso*>(magptr)));
                            ptrm = &ptrm[km]; km++;
                            //ptrm = ptrm[km].kopia(*(dynamic_cast<mieso*>(magptr))); km++;
                            m.push(ptrm);
                            cout << "Biore z magazynu .." << ptrm->getnazwa() << ".. i klade na polce z miesem." << endl;
                            delete magptr; km--;
                        }
                        else if((typeid(*magptr).name()) == (typeid(*ptrn).name()))
                        {

                            ptrn[kn] = (*(dynamic_cast<nabial*>(magptr)));
                            ptrn = &ptrn[kn]; kn++;
                            //ptrn = ptrn[kn].kopia(*(dynamic_cast<nabial*>(magptr))); kn++;
                            n.push(ptrn);
                            cout << "Biore z magazynu .." << ptrn->getnazwa() << ".. i klade na polce z nabialem." << endl;
                            delete magptr; kn--;
                        }
                    }
                case 2:
                    break;
                case 3:
                    magazyn.usun_termin();
                    break;
                case 4:
                    cout << "Podaj nr:";
                    cin >> choose;
                    magazyn.wypisz2(choose);
                default:;
                }
                break;
            case 3:
                cout << endl;
                cout << "WITAMY W HURTOWNI!" << endl;
                int z,o,u;
                for(z=1;z<5;z++)
                {
                    cout << z << ". " << nabialy[z-1];
                }
                for(o=1;o<4;o++)
                {
                    cout << z << ". " << miesa[o-1];
                    z++;
                }
                for(u=1;u<5;u++)
                {
                    cout << z << ". " << slodkosci[u-1];
                    z++;
                }
                cout << "Czy chcesz cos kupic?\n1. TAK\n2. NIE" << endl;
                cin >> first;
                switch (first)
                {
                case 1:
                    suma = 0;
                    cout << endl << "Podaj nr produktu ktory chcesz kupic: ";
                    cin >> choose;
                    cout << endl << "Podaj ilosc: ";
                    cin >> ilosc;
                    //cout << "Podaj ilosc: ";
                    //cin >> ilosc;
                    if(choose < 5)
                    {
                        for(int h=0;h<ilosc;h++)
                        {
                            ptrn[kn] = nabialy[choose - 1];
                            ptrp = &ptrn[kn]; kn++;
                            ptrp->termin_waznosci();
                            suma += ptrp->getcena_kupna();
                            magazyn.push(ptrp);

                            /*ptrp = ptrn[kn].kopia(nabialy[choose-1]); kn++;
                            ptrp->termin_waznosci();
                            suma += ptrp->getcena_kupna();
                            magazyn.push(ptrp);*/
                        }
                    }
                    else if(choose < 8)
                    {
                        for(int h=0;h<ilosc;h++)
                        {
                            ptrm[km] = miesa[choose - 5];
                            ptrp = &ptrm[km]; km++;
                            ptrp->termin_waznosci();
                            suma += ptrp->getcena_kupna();
                            magazyn.push(ptrp);

                            /*ptrp = ptrm[km].kopia(miesa[choose-5]); km++;
                            ptrp->termin_waznosci();
                            suma += ptrp->getcena_kupna();
                            magazyn.push(ptrp);*/
                        }
                    }
                    else if(choose < 12)
                    {
                        for(int h=0;h<ilosc;h++)
                        {
                            ptrs[ks] = slodkosci[choose - 8];
                            ptrp = &ptrs[ks]; ks++;
                            ptrp->termin_waznosci();
                            suma += ptrp->getcena_kupna();
                            magazyn.push(ptrp);

                            /*ptrp = ptrs[ks].kopia(slodkosci[choose-8]); ks++;
                            ptrp->termin_waznosci();
                            suma += ptrp->getcena_kupna();
                            magazyn.push(ptrp);*/
                        }
                    }
                    cout << "Kupiles : " << ilosc << "x " << ptrp->getnazwa() << " za " << suma << "zl." << endl;
                    portfel -= suma;
                    break;
                default:
                    break;
                }
                break;
            case 4:
                //s.pop();
                srand(time(NULL));
                first = rand()%3;
                cout << endl << "Uwaga! Przychodza " << first << " klienci!!" << endl;
                for(i=0;i<first;i++)
                {
                    suma = 0;
                    ilosc = rand()%3+1;
                    for(int j=0;j<ilosc;j++)
                    {
                        choose = rand()%3+1;
                        switch(choose)
                        {
                        case 0:
                            //cout << "n.pusty" << n.pusty() << endl;
                            if(!n.pusty())
                            {
                                suma += n.kup(i);
                                //delete ptrn[kn]; kn--;
                            }
                            break;
                        case 1:
                            //cout << "m.pusty" << m.pusty() << endl;
                            if(!m.pusty())
                            {
                                suma += m.kup(i);
                                //delete ptrm[km]; km--;
                            }
                            break;
                        case 2:
                            //cout << "s.psty" << s.pusty() << endl;
                            if(!s.pusty())
                            {
                                suma += s.kup(i);
                                //delete ptrs[ks]; ks--;
                            }
                            break;
                        default:;
                        }
                        //cout << endl << "wyszedlem z switch" << endl;
                    }
                    if(suma == 0) cout << "Klient nr " << i+1 << " nic nie kupil. UWAGA! Mozliwe ze na ktorejs polce brakuje towaru." << endl;
                    portfel += suma;
                    //cout << endl << "Wyszedlem z j" << endl;
                }
                break;
            case 5:
                {
                    szelf<produkt> koszyk(ptrp);
                    koszyk.pop();
                    suma = 0;
                    i = 0;
                    kupuje = 1;
                    produkt* koszptr;
                    while(kupuje)
                    {
                        cout<< endl;
                        cout << "Twoj Koszyk:" << endl;
                        koszyk.rysuj();
                        cout << endl;
                        cout << "Ktora regal chcesz sprawdzic?\n1. Regal z nabialem\n2. Regal z miesem\n3. Regal ze slodyczami\n4. Odloz cos z koszyka\n5. Koniec kupowania, ide do kasy" <<endl;
                        cin >> first;
                        switch(first)
                        {
                        case 1:
                            n.pokaz();
                            cout << endl;
                            cout << "Podaj nr produktu ktory chcesz kupic lub kliknij 0 aby wrocic do wyboru regalu" <<endl;
                            cin >> choose;
                            if(!choose) break;
                            koszptr = n.wez(choose);
                            suma += koszptr->getcena_kupna();
                            cout << "Wkladasz do koszyka:" << koszptr;
                            koszyk.push(koszptr);
                            i++;
                            break;
                        case 2:
                            m.pokaz();
                            cout << endl;
                            cout << "Podaj nr produktu ktory chcesz kupic lub kliknij 0 aby wrocic do wyboru regalu" <<endl;
                            cin >> choose;
                            if(!choose) break;
                            koszptr = m.wez(choose);
                            suma += koszptr->getcena_kupna();
                            cout << "Wkladasz do koszyka:" << koszptr;
                            koszyk.push(koszptr);
                            i++;
                            break;
                        case 3:
                            s.pokaz();
                            cout << endl;
                            cout << "Podaj nr produktu ktory chcesz kupic lub kliknij 0 aby wrocic do wyboru regalu" <<endl;
                            cin >> choose;
                            if(!choose) break;
                            koszptr = s.wez(choose);
                            suma += koszptr->getcena_kupna();
                            cout << "Wkladasz do koszyka:" << koszptr;
                            koszyk.push(koszptr);
                            i++;
                            break;
                        case 4:
                            cout << endl;
                            cout << "Podaj nr produktu: ";
                            cin >> choose;
                            cout << endl;
                            {
                                produkt* kosz2ptr;
                                kosz2ptr->next = NULL;
                                kosz2ptr = koszyk.wez(choose);
                                suma -= kosz2ptr->getcena_kupna();
                                //cout << typeid(*kosz2ptr).name() << endl;
                                if((typeid(*kosz2ptr).name()) == (typeid(*ptrs).name()))
                                {
                                    ptrs[ks] = (*(dynamic_cast<slodycze*>(kosz2ptr)));
                                    ptrs = &ptrs[ks];
                                    ptrs->next = NULL;
                                    //ptrs = ptrs[ks].kopia(*(dynamic_cast<slodycze*>(magptr))); ks++;
                                    s.push(ptrs);
                                    cout << "Biore z koszyka .." << ptrs->getnazwa() << ".. i odkladam na polke ze slodyczami." << endl;
                                    delete kosz2ptr;
                                }
                                else if((typeid(*kosz2ptr).name()) == (typeid(*ptrm).name()))
                                {
                                    ptrm[km] = (*(dynamic_cast<mieso*>(kosz2ptr)));
                                    ptrm = &ptrm[km];
                                    ptrm->next = NULL;
                                    //ptrm = ptrm[km].kopia(*(dynamic_cast<mieso*>(magptr))); km++;
                                    m.push(ptrm);
                                    cout << "Biore z koszyka .." << ptrm->getnazwa() << ".. i odkladam na polke z miesem." << endl;
                                    delete kosz2ptr;
                                }
                                else if((typeid(*kosz2ptr).name()) == (typeid(*ptrn).name()))
                                {
                                    ptrn[kn] = (*(dynamic_cast<nabial*>(kosz2ptr)));
                                    ptrn = &ptrn[kn];
                                    ptrn->next = NULL;
                                    //ptrn = ptrn[kn].kopia(*(dynamic_cast<nabial*>(magptr))); kn++;
                                    n.push(ptrn);
                                    cout << "Biore z koszyka .." << ptrn->getnazwa() << ".. i odkladam na polke z nabialem." << endl;
                                    delete kosz2ptr;
                                }
                            }
                            break;
                        case 5:
                            kupuje = 0;
                        default:;
                        }
                    }
                    portfel += suma;
                    cout << "Placisz :" << suma << endl;
                }
                break;
            case 6:
                dzis + 1;
                break;
            case 7:
                otwarte = 0;
                break;
            default:;
            }
        }
        delete [] ptrn;
        delete [] ptrs;
        delete [] ptrm;
        delete [] miesa;
        delete [] slodkosci;
        delete [] nabialy;
        return 0;
}
