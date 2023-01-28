#include <iostream>
#include <vector>
using namespace std;


struct badGuy{
    string name;
    int health = 100;

};
struct Weapon{
    string name;
    int cost;
    int damage;
    //this func outputs name and damage of weapon
    void info(){
        cout << name << " damage: up to " << damage << " cost: " << cost << " health points.\n";
    }
};

struct Hero{
    string name;
    int health = 100;
    //array weapon
    Weapon weapons [3];
    void attack(Weapon w, badGuy &bg){
        //want to get instance of bad guy so must pass by refernce
        int attackDamage = (rand()%w.damage) + 1;
        cout << "Attack power = " << attackDamage << endl;
        //this docs point based on max damage input
        bg.health -= attackDamage;
        //just put health instead of hero.health bc we are in hero struct
        health -= w.cost;
    }
};

//to create multiple weapons
Weapon createWeapon(string name, int damage, int cost){
    //this func outside of all structs
    //weapon instance
    Weapon w;
    //these equal to whatever we recieve in param list
    w.name = name;
    w.damage = damage;
    w.cost = cost;
    return w;
}

int main(){
    cout << "Welcome to CS 135 Hero Game\n";
    char again;
    do{
        cout << "Enter a name for the hero:\n";
        Hero h1;
        string heroName = "";
        getline(cin, heroName);
        //hero name is whatever we got from user
        h1.name = heroName;
        cout << "Great!\nNow lets create weapons for the hero\n";
        //close loop to what we neeed to do for assign
        //hit when we hit count three

        int wCount = 0;
        do{
            cout << "Enter weapon name:\n";
            string wname = "";
            getline(cin, wname);
            cout << "Enter max damage (this will affect heros health:\n";
            int damage;
            //can do input validation here
            cin >> damage;
            //we already have heros array in hero struct
            //not reading from user input but reading from input file for assign
            //should do vector for assign
            h1.weapons[wCount] = createWeapon(wname, damage, damage/3); //dam/3 is cost
            wCount++;
            cin.clear();
            cin.ignore(100,'\n');
        }while(wCount < 3);

        cout << "Cool!\nNow we need a bad guy to fight\n"
        << "First, let's give the bad guy a name:\n";
        badGuy b1;
        string bgName = "";
        getline(cin, bgName);
        //name bc bad guy has attricbute name
        b1.name = bgName;

        //implement fighting in thee game
        do{
            cout << h1.name<< "'s health: " << h1.health<<
            "\t\t\t\t" << b1.name << "'s health: " << b1.health
            << endl;
            //implement hero attack
            //display weapons and once one is selected we use that weapon to attack bad guy
            cout << "Select a weapon:\n";
            for(int i = 0; i < 3; i++){
                //have semi colon in middle for readability
                //info is a coid func so cannot place in cout
                //h1 has weapons array inside hero struct
                //getting weapon in every iteration and calling info to it
                cout << i+1 << " : "; h1.weapons[i].info();
            }
            int selection = 0;
            cin >> selection;
            //in array have 0,1,2 and three weapons so need selection-1
            //hero attack
            //how to pass weapon:
            h1.attack(h1.weapons[(selection-1)], b1);
            //bad guy attack
            h1.health -= 5;
            cout << "Evil attack -5\n";


        }while(h1.health > 0 && b1.health > 0);
        //as long as both are alive we should stay in loop
        cout << "________Game Over_______"<< endl;
        cout << h1.name<< "'s health: " << h1.health<<
            "\t\t\t\t" << b1.name << "'s health: " << b1.health
            << endl;
        if(h1.health <= 0){
            //the hero is dead
            //in this scenario both could be dead bc if hero dead game over
            cout << "RIP " << h1.name << endl;

        }else{
            //the hero is alive
            //if get out of loop and alive u won game
            cout << h1.name << " saved the day\n";
        }
        cout << "Would you like to play again?\n";
        cin >> again;
        cin.clear();
        cin.ignore(100, '\n');
        if(again == 'N' || again == 'n'){
            cout << "Thank you for playing!\n";
            return 0;
        }
    }while(again == 'Y' || again == 'y');

    return 0;
}