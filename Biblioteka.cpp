	//10/04/2002
	//Projekat iz predmeta Napredne tehnike programiranja
	//Tema: radBiblioteke
#include <iostream>
#include <iomanip>
#include <ctime>
#include <stdlib.h>
#include <conio.h>
#include <string>
#include <cstring>
#include <vector>

using namespace std;

struct Knjiga {

    string imeAutora;
    string prezimeAutora;
    string naslovKnjige;
    char godinaIzdavanja[10];
    char isbn[20];
};

struct Korisnik {

    string imePrezime;
    int brojKarte;
    Knjiga podignutaKnjiga;
    };

void unosKnjiga(Knjiga *knjiga) {

    bool nastavakUnosa = true;

    for (int i = 0; i < 20; i++){

        char ponovniUnos;

        cout << "Unijeti ime autora: ";
        cin >> knjiga[i].imeAutora;

        cout << "Unijeti prezime autora: ";
        cin >> knjiga[i].prezimeAutora;

        cin.ignore();

        cout << "Unijeti naslov knjige: ";
        getline(cin, knjiga[i].naslovKnjige);

        cout << "Unijeti godinu (broj cifara mora biti 4 i godina mora sadrzavati tacku na kraju): ";
        cin >> knjiga[i].godinaIzdavanja;

        int duzinaGodinaIzdavanja = strlen(knjiga[i].godinaIzdavanja);

        while (duzinaGodinaIzdavanja != 5 || knjiga[i].godinaIzdavanja[4] != '.') // godina može biti i poslije 2000.

        {   cout << "Format unesene godine nije ispravan! ";

            cout << "\nUnijeti godinu ponovo: ";

            cin >> knjiga[i].godinaIzdavanja;

            duzinaGodinaIzdavanja = strlen(knjiga[i].godinaIzdavanja);
        }

        cout << "Unijeti isbn (ISBN ima 13 karaktera): ";

        cin >> knjiga[i].isbn;

        int duzinaISBN = strlen(knjiga[i].isbn);

        while (duzinaISBN < 13 || duzinaISBN > 13)

        {   cout << "Nije unesen ispravan ISBN kod. Pokusajte ponovo: ";

            cin >> knjiga[i].isbn;

            duzinaISBN = strlen(knjiga[i].isbn);
        }

        cout << "Da li zelite unos nove knjige (D / N)? " << endl;

        cin >> ponovniUnos;

        if (ponovniUnos == 'd' || ponovniUnos == 'D') {

            nastavakUnosa = true;

        } else {

            nastavakUnosa = false;
        }

        if (nastavakUnosa == false) break;

    }

}

void ispisKnjiga(Knjiga *knjiga){

    cout<< " - - - - - Ispis knjiga - - - - - " << endl;

    int brojKnjiga;

    cout << "\nUnesite broj knjiga o kojima su vam potrebne informacije:";

    cin >> brojKnjiga;

    cout << "\nIme autora--------- Prezime autora ----------- Godina izdavanja --------------------- ISBN" << endl;

    for (int i = 0; i < brojKnjiga; i++)
    
    {
        cout <<left<<setw(20)<< knjiga[i].imeAutora << left<<setw(27) <<knjiga[i].prezimeAutora << left <<setw(30)<< knjiga[i].godinaIzdavanja << setw(3) << knjiga[i].isbn << endl;
        
    }

}

void ispisKorisnika(Korisnik *korisnik){

    cout<< " - - - - - Ispis korisnika - - - - - - " << endl;

    int brojKorisnika;

    cout << "\nUnesite broj korisnika o kojima su vam potrebne informacije:";

    cin >> brojKorisnika;

    cout << "\nIme i prezime ------------------ Broj clanske karte ------------------ " << endl;

    for (int i = 0; i < brojKorisnika; i++)
    {
        cout <<left<<setw(33)<< korisnik[i].imePrezime <<left<<setw(3)<<korisnik[i].brojKarte << endl;
    }

}

void registracijaKorisnika(Korisnik korisnik[])
{

    cout << "- - - - - - - Registracija korisnika - - - - - - - " << endl;

   bool nastavakUnosa = true;

   for (int i = 0; i < 10; i++) {

       cin.ignore();

       cout << "Unesite ime i prezime korisnika: ";

        getline(cin, korisnik[i].imePrezime);

       char ponovniUnos;

       korisnik[i].brojKarte = rand() % 99 + 100;

       cout << "Generisani broj clanske karte je:" << korisnik[i].brojKarte;

       cout << "\nDa li zelite unos novog korisnika (D ili N): " << endl;

       cin >> ponovniUnos;

       if (ponovniUnos == 'd' || ponovniUnos == 'D') {

           nastavakUnosa = true;

       } else {

           nastavakUnosa = false;
       }

       if (nastavakUnosa == false) break;

   }

}

void pretragaKnjiga (Knjiga *knjiga) {

    /* Funkcija radi sljedece:
    - unose se pristupni podaci zato što pristupu svim knjigama ima samo admin (username: admin, password: admin)
    - unosi se naziv knjige
    - ispisuju se informacije o knjizi*/

    string username1 = "admin";

    string password1 = "admin";

    string username2, password2, knjigaNaziv;

    cout << "- - - - - - - - - Pretrazivanje knjiga - - - - - - - - -" << endl;

    cout << "\nKako biste mogli da pristupite informacijama o podignutim knjigama, potrebno je da se logujete kao admin" << endl;

    do
    {   cout << "Unesite username: " << endl;

        cin >> username2;

        cout << "Unesite password: " << endl;

        cin >> password2;

        if (password1 == password2 && username1 == username2) {

            cout << "\n\nUspjesno ste se prijavili. U nastavku mozete pristupiti informacijama o knjigama." << endl;
            
			int br=0;
			
            string pretragaKnjige;

            cout << "\nUnesite naslov knjige o kojoj zelite vise informacija: " << endl;

            cin >> pretragaKnjige;
            
            cout<<endl;

            for (int i = 0; i < 20; i++) {

                if (pretragaKnjige == knjiga[i].naslovKnjige) {
                	
                	cout << "\nIme autora--------- Prezime autora ----------- Godina izdavanja --------------------- ISBN" << endl;
                	
                	 cout <<left<<setw(20)<< knjiga[i].imeAutora << left<<setw(27) <<knjiga[i].prezimeAutora << left <<setw(30)<< knjiga[i].godinaIzdavanja << setw(3) << knjiga[i].isbn << endl;
                   	
					br++;
					
					break;

            	}
                	
			}
    
        	if(br==0){
        		
        		cout<<"Knjiga pod tim nazivom nije evidentirana u bazi!"<<endl;
        			
			}

        	
    	}
    	

    } while (password1 != password2 || username1 != username2);

}


void pretragaKorisnika(Korisnik *korisnik)

{
    
    int br3=0;
    
    string pretrazi_korisnika;
    
    cout<<"Unesite ime i prezime korisnika: "<<endl;
    
    cin.ignore();
    
    getline(cin, pretrazi_korisnika);
    
    cout<<endl;
    
	for (int i = 0; i < 10; i++) {

                if (pretrazi_korisnika == korisnik[i].imePrezime) {

                    cout << "\nUneseni korisnik postoji!" << endl;
                    
                    cout<<"\nBroj njegove kartice je: "<<korisnik[i].brojKarte;

                    cout<<endl;

                   
                    br3++;

                    break;

                }

            }

            if(br3==0){

                cout<<"Uneseni korisnik ne postoji!"<<endl;

            }


        }
        
void unosPodignutihKnjiga (Korisnik korisnik[], Knjiga *knjiga) {

    string imePrezimeKorisnika;
    
    string naslovKnjige;
    
    int br1=0;
    
    int br2=0;

    cout << " - - - - - - - Unos podataka o podignutim knjigama - - - - - - - " << endl;

    cout << "Unesite ime i prezime korisnika: " << endl;
    
    cin.ignore();

    getline(cin, imePrezimeKorisnika);
    
    cout<<endl;

    for ( int i = 0; i < 10; i++) {

        if (imePrezimeKorisnika == korisnik[i].imePrezime) {

            cout << "\nKorisnik je registrovan u bazi. U nastavku unesite naslov podignute knjige: " << endl;

            cin >> naslovKnjige;

cout<<endl;
            
			br1++;
            
            for ( int j = 0; j < 20; j++) {
            	
            	if (naslovKnjige == knjiga[j].naslovKnjige){
            		
            		cout << "Korisniku " << korisnik[i].imePrezime << " je dodijeljena knjiga " << knjiga[j].naslovKnjige<< "!" << endl;
				
					br2++;
					
					break;
				}
				
			}
			
			if(br2==0){
				
				cout<<"Knjiga pod tim nazivom nije registrovana u bazi!"<<endl;
			}

        }
	}
	
	if (br1==0) {

        cout << "Taj korisnik nije registrovan u bazi! " << endl;
	
	}
	      
        }


int main(){

    Knjiga knjiga [20];

    Korisnik korisnik[10];

    srand(time(NULL));

    rand();

    bool meni = true;

    do {
		
        int unos;

        char izbor;
        
        cout<<"=================================================================================="<<endl;

        
        cout<<setw(50)<<"DOBRO DOSLI U BIBLIOTEKU"<<endl;
        
        cout<<"=================================================================================="<<endl;

        cout << "1 - Unos knjiga u bazu" << endl;

        cout << "2 - Registracija korisnika" << endl;

        cout << "3 - Ispis knjiga iz baze" << endl;

        cout << "4 - Ispis korisnika iz baze" << endl;

        cout << "5 - Pretraga knjiga" << endl;

        cout << "6 - Pretraga korisnika" << endl;

         cout << "7 - Unos podignutih knjiga " << endl;

        cout << "8 - Izlaz" << endl;
        
        cout<<endl;
        
        cout<<"Izaberite jednu od ponudjenih opcija: "<<endl;

        cin >> unos;
        
        cout<<endl;

        switch (unos)

        {
            case 1:

                unosKnjiga(knjiga);
                break;

            case 2:

               registracijaKorisnika(korisnik);
               break;

            case 3:

                ispisKnjiga(knjiga);
                break;

            case 4:

                ispisKorisnika(korisnik);
                break;


            case 5:

                pretragaKnjiga(knjiga);
                break;

            case 6:

            	pretragaKorisnika(korisnik);
                break;

            case 7:
            	
                unosPodignutihKnjiga(korisnik, knjiga);
                break;

            case 8:
            	
	   			_Exit(0);
                break;
        }
		
        cout << "\nDa li zelite izbor neke druge opcije iz pocetnog menija (D/N)? " << endl;

        cin >> izbor;

        if (izbor=='D' || izbor=='d') {

            meni = true;
        }

        else {

            meni = false;
        }

    } while (meni == true);

    return 0;
}


