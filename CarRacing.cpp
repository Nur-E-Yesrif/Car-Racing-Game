#include <iostream>
#include <conio.h>
#include <windows.h>
#include <ctime>

using namespace std;

int width = 20;
int playerX = 10;
int enemyX = rand() % 20;
int enemyY = 0;
int score = 0;

void gotoxy(int x, int y) {
    COORD c;
    c.X = x;
    c.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);
}

void drawRoad() {
    system("cls");

    for(int i=0;i<20;i++) {
        cout << "|";
        for(int j=0;j<width;j++) {

            if(i==18 && j==playerX)
                cout<<"A";          // Player Car

            else if(i==enemyY && j==enemyX)
                cout<<"V";          // Enemy Car

            else
                cout<<" ";

        }
        cout<<"|"<<endl;
    }

    cout<<"\nScore : "<<score<<endl;
}

int main() {

    srand(time(0));

    while(true) {

        drawRoad();

        if(_kbhit()) {

            char ch = _getch();

            if(ch==75 && playerX>0)
                playerX--;

            if(ch==77 && playerX<width-1)
                playerX++;

            if(ch==27)
                break;
        }

        enemyY++;

        if(enemyY>18) {
            enemyY=0;
            enemyX=rand()%width;
            score++;
        }

        if(enemyY==18 && enemyX==playerX) {

            system("cls");

            cout<<"\n\n";
            cout<<"=============================="<<endl;
            cout<<"        GAME OVER"<<endl;
            cout<<"=============================="<<endl;
            cout<<"Final Score : "<<score<<endl;

            break;
        }

        Sleep(150);

    }

    system("pause");
    return 0;
}
