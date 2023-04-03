#include <iostream>
#include <windows.h>
#include <string>

using namespace std;

void HUD();
void Combat();
void CombatHUD();
void Moving();
void CreateMonster();

///BASIC THINGS FOR A RPG///
std::string name = " ", race = " ", sex = " ";
int level = 0, xp = 0, health = 0, totalHealth = 0, nextLevel = 0, heal = 0, maxHealth = 0;
int monsterHp = 0;
int monsterXp = 0;
int monsterLevel = 0;

///MONSTERS///
std::string monsterName[] = {"Goblin","Dwarf","Orge","Witch","Demon","Wizard"};
int currentMonsterNames = 5;
std::string currentMonster = " ";

int main(){


    level = 1;
    xp = 0;
    nextLevel = 76;
    health = 100;
    totalHealth = health;
    maxHealth = totalHealth;


    ///crearea personajului
    std::cout << "Enter Characters Name: ";
    std::cin >> name;

    std::cout << "Enter Characters race: ";
    std::cin >> race;

    std::cout << "Enter Characters sex: ";
    std::cin >> sex;


    ///design de dialog
    std::cout << "Creating Character.\n";
    Sleep(200);
    system("cls");

    std::cout << "Creating Character..\n";
    Sleep(200);
    system("cls");

    std::cout << "Creating Character...\n";
    Sleep(200);
    system("cls");

    HUD();
    Moving();




    return 0;

}
///HUD///
void HUD() { Sleep(500);
    system("cls");
    std::cout << "Name: " << name << "      Health: " << totalHealth << "\nRace: "
        << race << "\nSex: " << sex << "\nLevel: " << level << "\nxp: " << xp << "\nXp to next Level: " << nextLevel <<std::endl;
        Moving();}

void CombatHUD(){
    Sleep(500);
    system("cls");
    std::cout << "Name: " << name << "          |       Monster Name: " << currentMonster << "\nHealth: " << totalHealth << "        |       Monster Health: " << monsterHp << "\nLevel: " << level
    << "         |       Monster Level: " << monsterLevel << std::endl;

}
void Combat(){

    CombatHUD();

    int playerAttack;
    int playerDamage = 8 * level /2;
    int monsterAttack = 6 * monsterLevel /2;

    if(totalHealth >= 1 && monsterHp >= 1){
        std::cout << "\n";
        std::cout << "1.Attack\n";
        std::cout << "2.Block\n";
        std::cout << "3.RUN!\n";
        std:cout << "\n";
        std::cin >> playerAttack;

        if(playerAttack == 1){
            ///ATTACK
            std::cout << "Attacking... you did " << playerDamage << " to the " << currentMonster << std::endl;
            monsterHp = monsterHp - playerDamage;
            Sleep(1000);
            Combat();

            if(monsterHp >= 1) {
                std::cout << "\n";
                std::cout << "Monster is Attacking..\n";
                totalHealth = totalHealth - monsterAttack;
                std::cout << "You suffered " << monsterAttack <<" hp " << totalHealth << std::endl;

                if(totalHealth <= 0){
                    totalHealth = 0;
                }
            }else if(monsterHp <= 0){
                monsterHp = 0;
            }
            Sleep(1000);
            Combat();
        }
        else if(playerAttack == 2){
            ///BLOCK
            std::cout << "Blocking\n";
            int i = rand() % 100+1;
            if (i >= 50){
                std::cout << "You Blocked the incoming attacking\n";
                heal = level * 10 / 2;
                std::cout << "You have been healed for " << heal << std::endl;
                totalHealth += heal;
                Sleep(1000);
                Combat();
            }
            else{
                std::cout << "You failed to block the savage attack\n";
                totalHealth -= monsterAttack;
                std::cout << "You were stabbed in the back for " << monsterAttack << " current hp " << totalHealth << std::endl;
                Sleep(1000);
                Combat();

            }
        }
        else if(playerAttack ==3){
            ///RUN
            std::cout << "You try to run\n";
            int x = rand() % 100 + 1;
            if(x >= 50){
                std::cout << "You run away\n";
                HUD();
        }
            else{
                std::cout << "You failed to run away\n";
                std::cout << "Monster does a savage attack on you\n";
                totalHealth -= monsterAttack + 10;
                std::cout << "You sufferd " << monsterAttack +10 << "Your current HEALTH is " << totalHealth <<std::endl;
                Sleep(1000);
                Combat();
            }
        }else{
            std::cout << "Invalid Number\n";
            Sleep(500);
            Combat();
        }
    }
}


void Moving(){


    int choice;

    std::cout << "\n\n";
    std::cout << "1.Move Forward\n";
    std::cout << "2.Relax\n";
    std::cout << "3.MoveBackwards\n";
    std::cout <<"\n";

    std::cin >> choice;

    if(choice == 1){
        int temp = rand() % 100 + 1;
        std::cout << "You begin moving forward...\n";
        if(temp >= 50){
            ///ENCOUNTER MONSTER///
            CreateMonster();
            std::string tempName = monsterName[rand() % currentMonsterNames];
            std::cout << "A " << tempName << " Prepare to fight!\n";
            currentMonster = tempName;
            Sleep(1000);
            Combat();

        }
        std::cout << "You find nothing of intrest\n";
        Sleep(1000);
        HUD();


    }else if(choice == 2){
        std::cout << "You want to set up a camp for the evning\n";
        if(totalHealth <= 99){
            totalHealth += 10*level;
        }
        std::cout << "You healed by resting. HEALTH is now " << totalHealth << std::endl;
        Sleep(1000);
        HUD();


    }else if(choice == 3){
        int temp = rand() % 100 + 1;
        std::cout << "You begin moving backwards...\n";
        if(temp >= 50){

            CreateMonster();
            std::string tempName = monsterName[rand() % currentMonsterNames];
            std::cout << "A " << tempName << " Prepare to fight!\n";
            currentMonster = tempName;
            Sleep(1000);
            Combat();
        }
        std::cout << "You find nothing of intrest\n";
        Sleep(1000);
        HUD();

    }else{

    }std::cout << "Invalid Number\n";
    Sleep(500);
    Moving();


}
void CreateMonster(){

    monsterHp = 30;

    monsterLevel = (rand() % 3) +level;

    monsterHp = (rand()% 30) + totalHealth;

    monsterXp = monsterHp;

    if(monsterHp == 0)
        CreateMonster();
    if(monsterLevel == 0)
        CreateMonster();


}
