#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int o, p, red, kolona, gub = 0, progress = 0; // Deklaracija par varijabla koje ce nam trebati za for petlje i deklarisanje "gub"(gubitak) i "progress" koji ce pratit koliko jos polja treba razotkrit da se pobjedi
int main()
{
    srand(time(0));
    printf("*****AMAR's MINE CLEANER v1.0*****\n\n\n\n"); // Ispisivanje naslova i smjeska

    char front[8][8] = {
        {254, 254, 254, 254, 254, 254, 254, 254},
        {254, 254, 254, 254, 254, 254, 254, 254},
        {254, 254, 254, 254, 254, 254, 254, 254},
        {254, 254, 254, 254, 254, 254, 254, 254},
        {254, 254, 254, 254, 254, 254, 254, 254},
        {254, 254, 254, 254, 254, 254, 254, 254},
        {254, 254, 254, 254, 254, 254, 254, 254},
        {254, 254, 254, 254, 254, 254, 254, 254} // Deklarisanje matrice "Front" koja ce ispisivat kockice tjst polja koja jos nismo otkrili
    };

    char mines[8][8] = {
        {48, 48, 48, 48, 48, 48, 48, 48},
        {48, 48, 48, 48, 48, 48, 48, 48},
        {48, 48, 48, 48, 48, 48, 48, 48},
        {48, 48, 48, 48, 48, 48, 48, 48},
        {48, 48, 48, 48, 48, 48, 48, 48},
        {48, 48, 48, 48, 48, 48, 48, 48},
        {48, 48, 48, 48, 48, 48, 48, 48},
        {48, 48, 48, 48, 48, 48, 48, 48} // Deklarisanje matrice "mines" koja ce ispisivati 1,2,3,4 i mine
    };

    for (o = 0; o < 8; o++)
    { // For petlja koja ispisuje matricu front, u ovom sucaju samo ce ispisat prethodno deklarisane kockice
        for (p = 0; p < 8; p++)
        {
            printf(" %c ", front[o][p]);
        }
        printf("\n\n");
    }

    int i, j, k, l, n; // jos deklarisanja varijabli za for petlje
    char m = 'X';      // Deklarisanje varijable m koja predstavlja minu sa vrijednosti 'X'

    int brojac = 0; // deklarisanje brojaca za brojanje koliko ima mina u matrici
    for (j = 0; j < 10; j++)
    { // Petlja za generisanje random koordinata koja se ponavlja 10 puta
        k = (rand() % 8);
        // printf("%d ", k);          //
        l = (rand() % 8); //
        // printf("%d\n", l);         // Ispisivanje koordinata gdje su mine randomizovane (red+1, kolona+1)
        mines[k][l] = m; // na kraju svakog prolazenja kroz petlju uzimaju se random koordinate i u mines matrici im se dodjeljuje vrijednost m('X')
    }

check:
    for (i = 0; i < 8; i++)
    {
        for (n = 0; n < 8; n++)
        {
            if (mines[i][n] == 'X')
            {
                brojac++; // Implementacija brojaca koji ce osigurat da u programu ima tacno 10 mina,
            }
        }
    }
    if (brojac == 10)
    { // Ako je brojac jednako 10 onda ga opcija goto salje dalje u program
        goto proceed;
    }
    else
    {                     // Ako nije brojac jedanko 10 onda se generisu ponovo x i y koordinate, za te koordinate se ubacuje 'X' brojac se resetuje i salje se
        k = (rand() % 8); // ponovo u check dio koda, i ovo ce se ponavljat sve dok nema tacno 10 'X' vrijednosti u kodu, sto znaci da ako izabere istu koordinatu
        l = (rand() % 8); // brojac se nece pomjerit
        mines[k][l] = m;
        brojac = 0;
        goto check;
    }
    //

proceed:
    for (i = 0; i < 8; i++)
    {
        for (n = 0; n < 8; n++)
        {
            if (mines[i][n] == 88 && mines[i][n - 1] != 88)
            {
                mines[i][n - 1]++;
            }
            if (mines[i][n] == 88 && mines[i - 1][n] != 88)
            {
                mines[i - 1][n]++;
            }
            if (mines[i][n] == 88 && mines[i][n + 1] != 88)
            {
                mines[i][n + 1]++;
            }
            if (mines[i][n] == 88 && mines[i + 1][n] != 88)
            {
                mines[i + 1][n]++;
            }
        }
    }

    for (i = 0; i < 8; i++)
    {
        for (n = 0; n < 8; n++)
        {
            // printf(" %c ", mines[i][n]);
        }
          // printf("\n\n");                // Ispisivanje tabele sa minama (Cheat Sheet)
    }

biranje_reda:
    printf("Unesite red(1-8):"); // Ispisivanje na ekran instrukcije da se unese broj red od 11 do 8
bred:
    scanf("%d", &red); // Unosenje od strane korisnika koji se pohranjuje u "red" varijablu
    getchar();         // funkcija koja uzima char i vraca je kao unsigned char intu
    if (red >= 1 && red <= 8 && red != 0)
    {                                                              // uslov da ako je red= 1 ili veci ali ne veci od 8 i da nije 0 ispisat ce sve sto se nalazi u petlji
        printf("Izabrali ste %d. red, unesite sad kolonu: ", red); // ispisivanje na ekran kao i za red samo sad za kolonu
    kolona:
        scanf("%d", &kolona); // unosenje od strane korisnika koji se pohranjuje u "kolona" varijablu
        getchar();
        if (kolona >= 1 && kolona <= 8 && kolona != 0)
        { // uslov da ako je kolona 1 ili veca ali ne veca od 8 i da nije 0 ispisat ce sve sto se nalazi u petlji
            printf("Izabrali ste %d. kolonu.\n\n", kolona);

            red = red - 1;       // psoto redovi u matrici pocinju od 0 do 7 (u nasoj matrici) korisnik nece unosit od 0-7 nego od 1-8 tako da ako korisnik unese 8 on je zapravo izabrao 7 red
            kolona = kolona - 1; // isto vazi kao i za gornju deklaraciju
        }
        else
        { // ako if petlja nije tacna onda se vracaa na ponovan upis sve dok korisnik ne unese korektni broj reda
            printf("Pogresan unos. Pokusajte ponovo(1-8): ");
            goto kolona;
        } // program napusta ovaj dio i ide u deklarisanji dio koda
    }
    else
    { // vazi kao i za prethdoni else
        printf("Pogresan unos. Unesite ponovo: ");
        goto bred;
    }
    for (o = 0; o < 8; o++)
    { // petlja za ispisivanje matrice front u koju dodjeljujemo vrijednost koordinata koje smo izabrali iznad
        for (p = 0; p < 8; p++)
        {
            if (o == red && p == kolona)
            { // ako je red jednak varijabli o i ako je kolona jednaka varijabli p ona ce iz matrice mines vrijednost kopirat u matricu front i ispisat
                printf(" %c ", mines[red][kolona]);
                front[red][kolona] = mines[red][kolona];
                progress++;
                // za svaku celiju koju smo izabrali a ada nije jednaka 'X' na progres se nadodjeljuje 1
                if (mines[red][kolona] == 'X')
                { // Ako je red i kolona koju smo izabrali jednaka 'X' onda varijabla gub(gubitak) dobija vrijednost 1 i kada se petlja zavrsi funkcija if koja je ispod petlje ce biti tacna i program napusta taj dio i dolazi dio programa za gubitak
                    gub = 1;
                }
            }
            else
            { // else ako nije red==o i kolona==p samo ce se ispisat vrijednost matrice front sto ce biti kockica ako prethodno nije otkrivena
                printf(" %c ", front[o][p]);
            }
        }
        printf("\n\n");
    }
    if (progress == 54)
    { // kada progress dostigne vrijednost 54 onda vise nema "sigurnih" polja i automatski pobjedjujemo igricu
        printf("\t\t\n\n\aCestitam! Pobjedili ste!!");
        goto end; // napustanje ovog dijela programa i prelazenje u red "end"
    }
    if (gub == 1)
    { // ako je vrijednost gub jednaka 1 onda program napusta liniju koda i odlazi u red gubitak i samim time ispise printf funkciju i zavrsava program
        goto gubitak;
    }
    goto biranje_reda; // ako nije ni jedna if nije tacna onda se ponavlja brianje reda sve dok jedna nije tacna
gubitak:
    printf("\n\n\n\t\tPronasli ste minu, izgubili ste!\n\t\tMolimo restartujte igricu.\n\n\n\a");
    for (o = 0; o < 8; o++)
    { // Ova for petlja ispise sve vrijednosti iz matrice koje su =='X'
        for (p = 0; p < 8; p++)
        { // i koje su prethodno otkrivene
            if (mines[o][p] == 'X')
            {
                printf(" %c ", mines[o][p]);
            }
            else
            {
                printf(" %c ", front[o][p]);
            }
        }
        printf("\n\n");
    }
end:
    return 0; // zavrsetak programa
}
