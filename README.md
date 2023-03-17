# Blackjack

O firmă v-a cerut ajutorul pentru a crea un demo al unei aplicații de Blackjack. Blackjack este unul dintre cele mai ușoare jocuri de înțeles cu cărți, regulile fiind următoarele:

Cărțile de la 2 la 10 au valoarea inscripționată pe ele, în timp ce figurile (J,Q,K) au valoarea 10, iar asul (A) poate avea valoarea 1 sau 11.
Jucătorii joacă împotriva unei persoane care este denumită Dealer și pentru a câștiga ei trebuie să aibă suma cărților mai mare decât cea a dealer-ului. Dacă suma cărților depășește valoarea 21 jucătorul respectiv pierde. Dacă dealer-ul depășește valoarea 21, atunci toată lumea prezentă la masă câștigă, cu excepția celor care au depășit 21 înaintea dealer-ului.
Fiecare jucător primește la început 2 cărți, iar dealer-ul primește tot 2 cărți, dar una este întoarsă (ATENTIE! În jocul real de Blackjack cărțile sunt date câte una la fiecare jucător și abia după și a doua la fiecare jucător, dar pentru a simplifica problema, vom considera că jucătorii primesc cele 2 cărți din prima, iar dealer-ul este ultima persoană care primește cele 2 cărți).
După ce cărțile au fost împărțite, fiecare jucător are dreptul de a trage o carte (HIT) sau de a se opri la suma pe care o are deja (STAND). Jucătorii pot trage orice câte cărți vor, dar dacă au depășit 21 au pierdut (ATENTIE! Pentru simplitate vom considera următorul scenariu: Dacă suma cărților dealer-ului sau a jucătorilor este mai mică decât 16, ei sunt obligați să tragă o carte. Dacă suma cărților este 17-21 ei trebuie să se oprească din a trage cărți. Dacă suma este mai mare ca 21 au pierdut).
Cerințe
1) Dacă command este "check_cards", să se verifice dacă un pachet de cărți este măsluit, dacă este un pachet normal sau dacă este un pachet pregătit pentru blackjack. Un pachet de cărți se consideră măsluit dacă există cărți ale căror numere sau steme nu există în realitate (numerele permise sunt cele de la 2 la 14, unde 11 este asul, iar stemele permise sunt rosu, negru, romb sau trefla) și se va afișa "Pachet măsluit". Un pachet de cărți este considerat OK dacă nu este măsluit, dacă toate cărțile din el sunt diferite și dacă în total sunt 52 de cărți, iar în acest caz se va afișa "Pachet OK". Un pachet este considerat bun pentru Blackjack dacă nu este măsluit, iar în acest caz se va afișa "Pregatit pentru Blackjack". Se va lăsa un newline (\n) după aceste printări.

2) Dacă command este "shuffle_cards", să se amestece cărțile folosind algoritmul Linear Congruential Generator (LCG). Generatorul este definit prin relația de recurență Xn+1 = (a * Xn + c) mod m. Dacă sunt date de la tastatură 2 perechi de numere a, c și X0, atunci se va genera o pereche de indecși și cărțile de pe pozițiile respective se vor interschimba, iar indexul curent va deveni index anterior pentru generator (Vezi exemplu!). Constanta m va reprezenta numărul de cărți din pachet. Acest algoritm va fi aplicat pachetului de 50 de ori. Se vor afișa cărțile din pachet amestecate în formatul <numar_carte>,<stema_carte>, separate prin newline (\n).

3) Dacă command este "play_game", să se joace jocuri de Blackjack până la EOF cu n jucători la o masă. Jocul se va desfăşura după regulile enunţate la începutul problemei. Se consideră că în pachet NU EXISTĂ ași! (Adică pachetul va fi format din 48 de cărți, nu 52!) Se va consulta exemplul pentru o înţelegere clară a problemei. Pachetul de cărți va fi amestecat la fiecare rundă de Blackjack folosind algoritmul LCG descris mai sus (aplicat tot de 50 de ori). Inițial pachetul de cărți este aranjat în ordinea următoare: vor exista 48 de cărți într-un pachet (deoarece nu avem ași) în ordinea 2 rosu, 3 rosu, ..., 14 rosu, 2 negru, ..., 14 negru, 2 romb, ..., 14 romb, 2 trefla, ..., 14 trefla (Atenție că nu există 11!). La fiecare rundă pachetul de cărți va fi amestecat folosind algoritmul LCG cu valorile curente citire de la tastatură. Miza este de 10 euro per jucător astfel că câștigul rundei aduce jucătorului 10 euro, iar dacă pierde va avea 10 euro pe minus. Dacă jucătorul rămâne fără bani (are sub 10 euro) acesta va părăsi masa. La final, se vor afișa persoanele rămase la masă în formatul nume_persoana: suma_bani, separate prin newline (\n).

Date de intrare
Pe prima linie se află un cuvânt command, reprezentând subpunctul pe care vreţi să îl faceţi. Pentru subpunctul 1), se citesc de la tastatură, până la EOF, linii de norma <numar_carte>,<stema_carte>, unde numar_carte este un număr întreg, fără semm, pe 8 biți, iar stema_carte este un șir de caractere de maximum 30 de caractere. Pentru subpunctul 2), se citesc de la tastatură 6 numere întregi, 3 pe o linie și 3 pe alta, reprezentând constantele a, c și X0. Apoi, se citesc cărți până la EOF în formatul specificat la subpunctul punctul 1). Pentru subpunctul 3), se citeşte un număr întreg n care reprezintă numărul de jucători prezenţi la masa de Blackjack. Pe următoarele n linii se găsesc cei n jucători în formatul <nume> <suma_bani>, unde nume este un şir de caractere ce reprezintă numele jucătorului, format dintr-un singur cuvânt, iar suma_bani reprezintă suma de bani cu care intră acesta la masă, număr întreg fără semn pe 32 de biți. Pe următoarele linii până la EOF se citesc câte 6 valori pe linie, reprezentând intrările generatorului LCG pentru amestecarea cărților din jocul curent.

Date de ieşire
Valorile se vor afișa la ieșire conform specificației din cerință, fără a afişa altfel de text suplimentar în consolă! Afişaţi doar rezultatul cerut!


Restricții și precizări
1 <= n <= 20;
nume și stema_carte au maxim 30 de caractereș
suma_bani este un număr fractionar pe simplă precizie;
NU se acceptă soluţii hardcodate!


-------------------------------------------------------------------------------------------------------------------------------------------------------------

//Cerinta 1:
Intrare:

check_cards
4,romb
3,rosu
12,trefla
17,negru
7,rosu
9,telefon
7,negru

Iesire:

Pachet masluit

Explicatie:

Pe prima linie se află string-ul corespunzător subpunctului pe care vrem să îl abordăm (1). 
Pe următoarele linii până la EOF se află cărți de joc în formatul specificat la secțiunea Date de intrare. 
Se poate observa că pachetul este măsluit deoarece avem o carte cu valoarea 17 sau avem o carte cu stema telefon, deci trebuie afișat "Pachet masluit".

-------------------------------------------------------------------------------------------------------------------------------------------------------------


//Cerinta 2:

Intrare:

check_cards
4,romb
3,rosu
12,trefla
10,negru
7,rosu
9,romb
7,negru
3,rosu

Iesire:

Pregatit pentru Blackjack

Explicatie:

Pe prima linie se află string-ul corespunzător subpunctului pe care vrem să îl abordăm (1).
Pe următoarele linii până la EOF se află cărți de joc în formatul specificat la secțiunea Date de intrare. 
Toate cărțile din pachet sunt în regulă, deci pachetul nu este măsluit. 
Deoarece nu sunt 52 de cărți în pachet și avem cărți care se repetă, pachetul NU este OK, dar este pregătit pentru Blackjack deoarece nu este măsluit. 
Deci, se va afișa "Pregatit pentru Blackjack"


-------------------------------------------------------------------------------------------------------------------------------------------------------------

//Cerinta 3:

Intrare:

shuffle_cards
1 5 4
2 2 3
4,romb
3,rosu
12,trefla
10,negru
7,rosu
9,romb
7,negru
3,rosu

Iesire:

7,negru
10,negru
7,rosu
9,romb
12,trefla
3,rosu
3,rosu
4,romb

Explicatie:

Pe prima linie se află string-ul corespunzător subpunctului pe care vrem să îl abordăm (2). 
Pe a doua și pe a treia linie se află constantele a, c și X0, corespunzătoare generatorului celor 2 indecși.  
Apoi, până la EOF, se află cărți de joc. Deoarece avem un total de 8 cărți de joc, constanta m va fi 8.
La prima iterație vom calcula X1 în ambele situații și avem X1 = (1 * 4 + 5) mod 8 = 1 și X1 = (2 * 3 + 2) mod 8 = 0.
Cărțile de la indecși 1 și 0 trebuie interschimbate, adică cărțile 3 rosu și 4 romb. La a doua iterație avem X1 = (1 * 1 + 5) mod 8 = 6 și X1 = (2 * 0 + 2) mod 8 = 2.
Cărțile de la indecși 6 și 2 trebuie interschimbate, adică cărțile 7 negru și 12 treflă. Și așa mai departe, de 50 de ori. 


-------------------------------------------------------------------------------------------------------------------------------------------------------------

//Cerinta 4:


Intrare:

play_game
4
Mihai 100
Maria 50
Matei 176
Andrei 100
10 26 33 34 37 45
2 4 30 32 38 48
3 24 27 34 45 48

Iesire:

Mihai: 70
Maria: 20
Matei: 146
Andrei: 80

Explicatie:

Pe prima linie se află string-ul corespunzător subpunctului pe care vrem să îl abordăm (3). 
Pe a doua linie se află numărul de jucători care participă la jocul de Blackjack, în cazul exemplului acest fiind 4.
 Apoi, pe următoarele 4 linii se află cei 4 jucători cu numele şi suma de bani de care dispun. 
Apoi până la EOF, se citesc câte 6 valori care specifică intrările algoritmului LCG. 
Având 3 linii cu câte 6 valori înseamnă că se vor juca 3 jocuri, pachetul amestecându-se la fiecare joc. 
La ieșire se afișează numele și suma de bani cu care a răas fiecare jucător. 
În acest caz niciun jucător nu a fost lăsat fără bani, deci la ieșire au fost afișați toți în ordinea în care au fost citiți de la tastatură.
