#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "printFileList.h"
#include "sleep.h"
//#include "selectRandomLine.h"
//#include "len.h"
//#include "compareIndexCharacterString.h"

enum Mode{
        easy = 1,
        medium = 2,
        hard =3
};

typedef struct PLAYERCONFIG{
        char* answer;
        int index;
        int life;
        int difficult;
}playerConfig;

char* country = "AnyContryInTxt";
char* encodedCountry = "*********";
char* difficultStr;
char* message =  "Loose!"; 

bool win = false;
int currentPoint =  0;
int pointToWin;


int main(){
        srand(time(NULL));
        
        //SeedGame//
        country = selectRandomLine("./paises.txt");  
        encodedCountry = encodeCountry( country, &currentPoint );
        pointToWin = len(country);


        playerConfig player1 = { (char*)malloc(sizeof(char))   , 0 , 7, easy };

        printf("Select Difficult\n1-. easy\n2-. medium\n3-.hard\n" );
        scanf(  "%d", &player1.difficult    );

        switch(   player1.difficult  ){
                case easy:
                        player1.life = 7;
                        difficultStr = "Easy";
                        printf("Difficult selected easy with %d lifes\n", player1.life );
                        break;
                case medium:
                        player1.life = 4;
                        difficultStr = "Medium";
                        printf("Difficult selected medium with %d lifes\n", player1.life);
                        break;
                case hard:
                        player1.life = 2;
                        difficultStr = "Diffult";
                        printf("Difficult selected hard with %d lifes\n", player1.life);
                        break;
        };
        
        sleep(3000);
        system("clear");

        while(player1.life){
                system("clear");
                //Validator to play
                if(win){
                        message = "Won!";
                        break;
                }
                
                //Some message
                printf("difficult: %s\tlife: %d\tword: %s\tScore: (%d/%d) \n",  difficultStr, player1.life, encodedCountry,pointToWin , currentPoint );

                //Input users answer
                printf("\tEnter a character:\t");
                scanf("%s", player1.answer );
                printf("\n\tEnter a index:\t");
                scanf("%d", &player1.index   );

                //Calculation//
                if(  compareIndexCharacterString( country, player1.index-1,  player1.answer[0])){ //Correct Answer
                        encodedCountry[player1.index-1] = player1.answer[0]; //Revelo
                        currentPoint++;
                        
                }else{ //Incorrect Answer
                        player1.life--;
                };

                //Validator to win!
                if(currentPoint == pointToWin) win = true;
                sleep(1500);
        }
        printf("You %s\n", message);
        return 0;
}
