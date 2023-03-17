#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include <iomanip>

using namespace std;


void LinearCongruentialMethod(vector<pair<int,string>>&myVec,int X01,int X02, int m, int a1,int a2, int c1,int c2) {
    //X0-the seed
    //m-the number of cards
    //a-the multiplier
    //c-the increment

    // Traverse to generate required
    // numbers of random numbers
    for (int i = 0; i < 50; i++) {
        // Follow the linear congruential method for two pairs of numbers a, c și X0:
        X01 = (X01 * a1 + c1) % m;
        X02 = (X02 * a2 + c2) % m;
        myVec[X01].swap(myVec[X02]);

        //Verificare afisare
        /*cout<<i<<endl;
        for (auto itt: myVec) {
                 cout << itt.first << "," << itt.second << endl;
           }*/

    }
}

int main() {
    string command,line;
    char c;
    vector<pair<int,string>>myVec,myVec1;
    int  number;
    string type;
    cin>>command;
    getchar();

    //Verificare citire
    /*for(auto it:myVec){
        cout<<it.first<<","<<it.second<<endl;
    }*/

    //primul subpunct
    if(command=="check_cards") {
        while(cin>>number>>c>>type){
            myVec.emplace_back(number,type);

        }
        int S=0;
        int ok;
        for(auto it:myVec){
            S++;
            if ((it.first > 2 || it.first > 14) && (it.second != "rosu" && it.second != "romb" && it.second != "trefla" && it.second!="negru")) {
                ok=0;}

        }

        if(ok==0)
            cout<<"Pachet masluit"<<endl;
        else if(S==52 && ok!=0)
            cout<<"Pachet OK"<<endl;
        else if(S!=52 && ok!=0)
            cout<<"Pregatit pentru Blackjack"<<endl;

    }

    //al doilea subpunct
    if(command=="shuffle_cards") {
        int X01,X02,a1,a2,c1,c2,m;
        cin>>a1>>c1>>X01;
        cin>>a2>>c2>>X02;
        while(cin>>number>>c>>type){
            myVec1.emplace_back(number,type);

        }
        /*
        for(auto it:myVec1){
            cout<<it.first<<","<<it.second<<endl;
        }*/

        m=myVec1.size();
        LinearCongruentialMethod(myVec1, X01,X02, m,  a1, a2,  c1, c2);

        for (auto it: myVec1) {
            cout<<it.first<<","<<it.second<<endl;
        }
    }

    vector<pair<string,float>>players;//vectorul de jucatori, care retine numele si suma de care dispune
    //al treilea subpunct

    if(command=="play_game") {
        int n;
        cin >> n;
        string name_player;
        float money;

        for (int i = 0; i < n; i++) {
            cin >> name_player >> money;
            players.emplace_back(pair<string, float>(name_player, money));
        }



        //Am format pachetul de carti, exceptand asul (1 sau 11)
        vector<pair<int, string> > cards;
        for (int i = 2; i <= 14; i++) {
            if (i!= 11) {
                if(i<10)
                cards.emplace_back(pair<int, string>(i, "rosu"));
                else
                cards.emplace_back(pair<int, string>(10, "rosu"));
            }
        }


        for (int i = 2; i <= 14; i++) {
            if (i != 11) {
                if(i<10)
                cards.emplace_back(pair<int, string>(i, "negru"));
                else
                cards.emplace_back(pair<int, string>(10, "negru"));
            }
        }

        for (int i = 2; i <= 14; i++) {
            if (i != 11) {
                if(i<10)
                cards.emplace_back(pair<int, string>(i, "romb"));
                else
                cards.emplace_back(pair<int, string>(10, "romb"));
            }
        }
        for (int i = 2; i <= 14; i++) {
            if (i != 11) {
                if(i<10)
                cards.emplace_back(pair<int, string>(i, "trefla"));
                else
                cards.emplace_back(pair<int, string>(10, "trefla"));
            }
        }



        int X01, X02, a1, a2, c1, c2;
        int k = 0;
        while (cin >> a1 >> c1 >> X01 >> a2 >> c2 >> X02) {
           k++;
            int m = cards.size();
            LinearCongruentialMethod(cards, X01, X02, m, a1, a2, c1, c2);

            //Verificari afisari
           /*cout << "My deck of cards for "<<k<<" game is: " << endl;
             for (auto itt: cards)
             cout << itt.first << "," << itt.second << endl;*/




            vector<pair<string, int>> players_cards;// vector pentru mana jucatorilor

             int j=0;
             //Am impartit fiecarui jucator 2 carti;
            for (int i = 0; i < players.size(); i++) {
                players_cards.emplace_back(pair<string, int>(players[i].first, cards[j].first + cards[j+1].first));
                j=j+2;

            }

            //I-am oferit si dealer-ului 2 carti succesive
             int dealer_cards = cards[j].first + cards[j+1].first;
             j=j+2;

            //Daca suma cartilor dealer-ului>21, jucatorii cu suma cartilor <=21 castiga 10 euro
            if (dealer_cards > 21) {
                for (int i = 0; i < players.size(); i++) {
                    if (players_cards[i].second <= 21) {
                        players[i].second = players[i].second + 10;}
                    else{//Altfel pierd 10 euro
                         players[i].second = players[i].second - 10;
                    }
                }
            } else {
                     //Cat timp este parcurs vectorul de jucatori
                for (int i = 0; i < players.size(); i++) {
                    //Cat timp jucatorul are in mana mai putin de 17 puncte acesta trebuie sa traga carte, pana atinge maximul de 17 puncte, la care se opreste
                    while(players_cards[i].second <=16){
                        players_cards[i].second += cards[j].first;
                        j++;}}
                        //Cat timp dealer-ul are in mana mai putin de 17 puncte acesta trebuie sa traga carte, pana atinge maximul de 17 puncte, la care se opreste
                    while(dealer_cards <= 16) {
                        dealer_cards += cards[j].first;
                        j++;
                    }
                    //Daca dealer-ul are mai mult de 21 de puncte in mana
                    if (dealer_cards > 21) {
                        for (int i = 0; i < players.size(); i++) {
                            //Si daca si jucatorul are mai putin de 21 de puncte, acesta castiga 10 euro
                            if (players_cards[i].second <= 21) {
                                players[i].second = players[i].second + 10;}
                                //Altfel pierde zece euro
                            else{
                                players[i].second = players[i].second - 10;
                    }
                }
            }
                }
            //Daca dealer-ul are intre 17 si 21 de puncte in mana
            if(dealer_cards>=17 && dealer_cards<=21){
                for (int i = 0; i < players.size(); i++) {
                    //Si jucatorul are mai putine puncte decat dealer-ul sau jucatorul are mai mult de 21 de puncte, acesta pierde 10 euro
                        if (players_cards[i].second < dealer_cards ||  players_cards[i].second>21) {
                            players[i].second = players[i].second - 10;
                        }
                        //Daca jucatorul are mai multe puncte decat dealer-ul si jucatorul are mai putin de 21 de puncte, acesta castiga 10 euro
                         if (players_cards[i].second > dealer_cards && players_cards[i].second<=21 ) {
                            players[i].second = players[i].second + 10;
                        }
                        // else if(players_cards[i].second > dealer_cards && players_cards[i].second>21){
                        //      players[i].second = players[i].second - 10;
                        // }
                    }
            }



             //Daca suma de bani a jucatorului <10, acesta iese de la masa
            for (int i = 0; i < players.size(); i++) {
                if (players[i].second < 10) {
                    players.erase(players.begin() + i);
                    i--;
                }
            }
            //Verificari la afisari
            //j=0,y=0,t=0,z=0;
        // for (auto it: players_cards) {
        //         cout << it.first << " " << it.second << endl;
        //     }
        //     cout<<dealer_cards<<endl<<endl;
        // for(auto itt:players){
        //     cout<<itt.first<<" "<<itt.second<<endl;
        // }
        //  cout<<endl;
        }

    }
    //Afisarea numelui jucatorului si suma ramasa
     for(auto i : players){
         cout << i.first << ": " << i.second << endl;
     }
    return 0;
}