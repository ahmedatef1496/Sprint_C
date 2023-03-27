//////includes/////////
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
typedef unsigned char  uint8_t ;
//Global variables//
uint8_t boardM[] =  { '0','1','2','3','4','5','6','7','8','9' };
uint8_t Player1_S='A';
uint8_t Player2_S='B';
uint8_t Player_sign;
uint8_t configArray[2];
int playCount = 0;
//Functions headers/////
void Menu();
void ExitProject();
void GoBackOrExit();
void drawBoard( uint8_t *board);
void updateBoard (uint8_t*board, uint8_t position, uint8_t value);
uint8_t getPlayerSymbol(uint8_t playerNumber, uint8_t * symbol);
void setPlayerConfig(uint8_t *configArray);
void getGameState(uint8_t *board,int *gameState ) ;
void loadAndUpdate(uint8_t playerNumber);
void play_X_O();
void reset_game() ;
////main////
int main()
{
    while(1)
    {
        Menu();
        int Option;
        scanf("%d",&Option);
        switch(Option)
        {
        case 0:
            ExitProject();
            break;
        case 1:
            system("cls");
            system("COLOR 02");
            reset_game();
            printf("\n\t\t **** Set Player Configruiton ****\n\n");
            setPlayerConfig(configArray);
            play_X_O();
            break;
        default:
            printf("\n\t\t **** Wrong Entry ****\n\n");

        }
    }



}






///////////////////////Functions body ////////////////////////////////////

void Menu()
{  system("cls");
    system("COLOR 09");
    printf("\n\n\n\n\n\t\t\t\t\t\t\t MENU\n");
    printf("\t\t\t\t\t\t=======================\n");
    printf("\t\t\t\t\t\t[1] Start New Game.\n");
    printf("\t\t\t\t\t\t[0] Exit the Program.\n");
    printf("\t\t\t\t\t\t=======================\n");
    printf("\t\t\t\t\t\t  Enter The Choice: ");
}
void ExitProject()
{
    system("cls");
    int i;
    char ThankYou[100]     = " ========= Thank You =========\n";
    for(i=0; i<strlen(ThankYou); i++)
    {
        printf("%c",ThankYou[i]);
        Sleep(30);
    }
    exit(1);
}
void GoBackOrExit()
{
    getchar();
    char Option;
    printf(" Go back(b)? or Exit(0)?: ");
    fflush(stdin);
    scanf(" %c",&Option);
    if(Option == '0')
    {
        ExitProject();
    }
    else
    {
        system("cls");
    }
    fflush(stdin);
}
void drawBoard( uint8_t *board)
{
    uint8_t i;
    system("cls");
    printf("\n\n-------------\n");

    for (i = 0; i < 9; i++)
    {
        printf("| %c ", board[i+1]);
        if (((i + 1) % 3) == 0)
        {
            printf("|\n-------------\n");
        }
    }
}

void updateBoard (uint8_t*board, uint8_t position, uint8_t value)
{
    board[position]=value;
}

uint8_t getPlayerSymbol(uint8_t playerNumber, uint8_t * symbol)
{
    uint8_t flag =0;
    if((*symbol!='X')&&(*symbol!='O'))
    {

        printf("\nWrong Symbol Please Enter (X OR O) \n");
        flag=1;
        return 1;


    }
    if (playerNumber=='1')
    {

        if(*symbol==Player2_S)
        {
            printf("\nUsed Symbol\n");
            flag=1;
            return 1;

        }
        else
        {
            Player1_S=*symbol;
            printf("\nYour Symbol : %c\n",*symbol);
        }
    }
    if (playerNumber=='2')
    {
        if(*symbol==Player1_S)
        {

            printf("\nUsed Symbol\n");
            flag=1;
            return 1;
        }
        else
        {
            Player2_S=*symbol;
            printf("\nYour Symbol : %c\n",*symbol);
        }
    }
    flag =0 ;
    return 0;
    // return flag ;
}


void setPlayerConfig(uint8_t *configArray)
{
    uint8_t  symboal_holder;
    int wrong_entry_flag=1 ;
    while (wrong_entry_flag)
    {
        printf(" Player 1 Please Enter your Symbol (X OR O)\n");
        fflush(stdin);
        scanf (" %c",&symboal_holder);
        wrong_entry_flag =getPlayerSymbol('1',&symboal_holder) ;
    }
    configArray[1]=symboal_holder;
    wrong_entry_flag=1;
    while (wrong_entry_flag)
    {
        printf("Player 2 Please Enter your Symbol (X OR O) \n");
        fflush(stdin);
        scanf (" %c",&symboal_holder);
        wrong_entry_flag =getPlayerSymbol('2',&symboal_holder) ;
    }
    configArray[2]=symboal_holder;

}


void getGameState(uint8_t *board,int *gameState )
{
    // check all rows
    if (    (boardM[1] == Player_sign && boardM[2] ==Player_sign && boardM[3] ==Player_sign ) ||
            (boardM[4] == Player_sign && boardM[5] ==Player_sign && boardM[6] ==Player_sign ) ||
            (boardM[7] == Player_sign && boardM[8] ==Player_sign && boardM[9] ==Player_sign)  )
    {
        *gameState= 0;
        //    printf("\nrow\n");

    }
    // check all columns
    else if  ((boardM[1] == Player_sign && boardM[4] ==Player_sign && boardM[7] ==Player_sign) ||
              ( boardM[2] == Player_sign && boardM[5] ==Player_sign && boardM[8] ==Player_sign) ||
              (  boardM[3] == Player_sign && boardM[6] ==Player_sign && boardM[9] ==Player_sign ))
    {
        *gameState= 0;
        //   printf("\ncol\n");
    }
    // check both diagonals
    else if  ((boardM[1] == Player_sign && boardM[5] ==Player_sign && boardM[9] ==Player_sign) ||
              ( boardM[3] == Player_sign && boardM[5] ==Player_sign && boardM[7] ==Player_sign ))
    {
        *gameState =0;
        //  printf("\ndiag\n");
    }
    //////////////////////////////////////////////////////////////////////////////

    else if  (boardM[1] == 'O' && boardM[2] =='X' && boardM[3] =='O' &&
              boardM[4] == 'O' && boardM[5] =='X' && boardM[6] =='X'  &&
              boardM[7] == '7' && boardM[8] =='X' && boardM[9] =='O'  )
    {
        *gameState =1;


    }
    else if  (boardM[1] == '1' && boardM[2] =='O' && boardM[3] =='O' &&
              boardM[4] == 'O' && boardM[5] =='X' && boardM[6] =='X'  &&
              boardM[7] == 'X' && boardM[8] =='X' && boardM[9] =='O'  )
    {
        *gameState =1;


    }
    else if  (boardM[1] == 'O' && boardM[2] =='O' && boardM[3] =='O' &&
              boardM[4] == 'X' && boardM[5] =='X' && boardM[6] =='O'  &&
              boardM[7] == '7' && boardM[8] =='O' && boardM[9] =='X'  )
    {
        *gameState =1;


    }








    /////////////////////////////////////////////////////////////////////////////////





    // There is no winner
    else
    {
        *gameState= 2;
        // printf("\nno wineer\n");
    }
}



void loadAndUpdate(uint8_t playerNumber)
{
    uint8_t pos;
    int wrong_entry_flag = 1;
    while(wrong_entry_flag)
    {
        //  printf("Enter Position %c \n",playerNumber);
        printf("Enter Position \n");
        fflush(stdin);
        scanf(" %d",&pos);
        if (boardM[pos]=='X'|| boardM[pos]=='O')
        {
            wrong_entry_flag = 1;
            printf("Full place choose another\n");

            continue ;


        }
        else
        {
            if (pos > 0 && pos < 10)
            {
                if (playerNumber=='1')
                {

                    updateBoard (boardM, pos,Player1_S);
                    wrong_entry_flag = 0;
                }
                if (playerNumber=='2')
                {
                    updateBoard (boardM, pos,Player2_S);
                    wrong_entry_flag = 0;
                }
            }
            else
            {
                printf("Wrong Entry please enter number from 1 to 9 \n");
                wrong_entry_flag = 1;
                continue ;
            }
        }

    }
}




void play_X_O()
{
    int gameResult = 2;
    //int playCount = 0;
    int updationResult = 1;
    uint8_t playerNumberM='1';
    system("cls");
    drawBoard(boardM);
    // start playing the game
    while (playCount < 9 && gameResult==2)  //while (gameResult==2 && playCount < 9)
    {
        if (playCount % 2 == 0)
        {
            // player 1
            playerNumberM='1';
            // playerSign=Player1_S
            Player_sign=Player1_S;
            printf("\nPlayer 1 [ %c ] : \n",Player1_S);
        }
        else
        {
            // player 2
            playerNumberM='2';
            // playerSign=Player2_S
            Player_sign=Player2_S;
            printf("\nPlayer 2 [ %c ] : \n",Player2_S);

        }
        loadAndUpdate(playerNumberM);
        drawBoard(boardM);
        getGameState(boardM,&gameResult);
        // print the winner of the game
        if (!gameResult)
        {
            printf("\n\t ** Player %c Won!! **\n\n",Player_sign );

            GoBackOrExit();
            continue ;



        }
        else if (gameResult==1||playCount==8)
        {
            printf("\t *** Draw  Game Over!! ***\n");

            GoBackOrExit();
            continue ;



        }
        playCount++;
        // printf("\n%d\n",playCount);


    }

}

void reset_game()
{
    boardM[1]='1';
    boardM[2]='2';
    boardM[3]='3';
    boardM[4]='4';
    boardM[5]='5';
    boardM[6]='6';
    boardM[7]='7';
    boardM[8]='8';
    boardM[9]='9';
    playCount=0;
    Player1_S='A';
    Player1_S='B';
}
