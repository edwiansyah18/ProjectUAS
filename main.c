#include <stdio.h>
#include <time.h>
#include <ctype.h>
#include <time.h>
#include <conio.h>
#include <windows.h>
//#include <SDL2/SDL.h>
//#include <SDL2/SDL_image.h>
//#include <SDL2/SDL_timer.h>


#define UP 72
#define DOWN 80
#define LEFT 75
#define RIGHT 77

int length;
int bend_no;
int len;
char key;
void gotoxy(int x, int y);
void GotoXY(int x,int y);
void setcolor();
void Print();
void rules();
void load();
void record();
int life;
void Delay(long double);
void Move();
void Food();
void Bend();
void Border();
void Down();
void Left();
void Up();
void Right();
int Score();
void ExitGame();
int Scoreonly();

struct coordinate{
    int x;
    int y;
    int direction;
};

struct scores{
    	char plname[20];
    	int px;
};

typedef struct coordinate coordinate;

coordinate head, bend[500],food,body[30];

int main(){
    char key;
    Print();
    system("cls");
    rules();
    system("cls");
    load();
    length=5;
    head.x=25;
    head.y=20;
    head.direction=RIGHT;
    Border();
    Food(); 
    life=3; 
    bend[0]=head;
    Move();   
    return 0;
}

void Print(){
	int i;
	setcolor(25);
    for(i=0;i<2;i++){
    	system("cls");
    	printf("\n\n\n\n");
		printf("\t\t      --------------------------------------------------------------------------\n");
		printf("\t\t     |                                                                          |\n");
		printf("\t\t     |  OOO   OOOOOOOOO   OOOOOOOOO   OOOOOOOOO   OOOOOOOOO   OOOOOOOOO   OOO   |\n");
		printf("\t\t     |  OOO   OOOOOOOOO   OOOOOOOOO   OOOOOOOOO   OOOOOOOOO   OOOOOOOOO   OOO   |\n");
		printf("\t\t     |  OOO   OOO   OOO   OOO   OOO   OOO   OOO   OOO   OOO   OOO   OOO   OOO   |\n");
		printf("\t\t     |  OOOOOOOOO   OOOOOOOOO   OOOOOOOO0   OOO   OOO   OOOOOOOOO   OOOOOOOOO   |\n");
		printf("\t\t     |  OOOOOOOOO   OOOOOOOOO   OOOOOOOOO   OOOOOOOOO   OOOOOOOOO   OOOOOOOOO   |\n");
		printf("\t\t     |                                                                          |\n");
		printf("\t\t      --------------------------------------------------------------------------\n");
 		printf("\t\t\t         *************************************************\n");
		printf("\t\t\t         *                                               *\n");
		printf("\t\t\t         *         -----------------------------         *\n");
		printf("\t\t\t         *             Sneaky Snake The Game             *\n");
		printf("\t\t\t         *         -----------------------------         *\n");
		printf("\t\t\t         *                                               *\n");
		printf("\t\t\t         *                                               *\n");
		printf("\t\t\t         *************************************************\n\n\n");
		
		Sleep(400);
		system("cls");
		
		printf("\n\n\n\n");
		printf("\t\t      --------------------------------------------------------------------------\n");
		printf("\t\t     |                                                                          |\n");
		printf("\t\t     |  OOOOOOOOO   OOOOOOOOO   OOOOOOOOO   OOOOOOOOO   OOOOOOOOO   OOOOOOOOO   |\n");
		printf("\t\t     |  OOOOOOOOO   OOOOOOOOO   OOOOOOOOO   OOOOOOOOO   OOOOOOOOO   OOOOOOOOO   |\n");
		printf("\t\t     |  OOO   OOO   OOO   OOO   OOO   OOO   OOO   OOO   OOO   OOO   OOO   OOO   |\n");
		printf("\t\t     |  OOO   OOOOOOOOO   OOOOOOOOO   OOOOOOOOO   OOOOOOOOO   OOOOOOOOO   OOO   |\n");
		printf("\t\t     |  OOO   OOOOOOOOO   OOOOOOOOO   OOOOOOOOO   OOOOOOOOO   OOOOOOOOO   OOO   |\n");
		printf("\t\t     |                                                                          |\n");
		printf("\t\t      --------------------------------------------------------------------------\n");
 		printf("\t\t\t         *************************************************\n");
		printf("\t\t\t         *                                               *\n");
		printf("\t\t\t         *         -----------------------------         *\n");
		printf("\t\t\t         *             UAS - Edwiansyah Z.A.             *\n");
		printf("\t\t\t         *         -----------------------------         *\n");
		printf("\t\t\t         *                                               *\n");
		printf("\t\t\t         *                                               *\n");
		printf("\t\t\t         *************************************************\n\n\n");

		Sleep(400);
	}
	for(i=0;i<240;i++){
        printf("-");
    }
    printf("\n\n");
    printf("\t\t\t\t\t    ");
    system("pause");
}

void rules(){
	printf("\n\n\n");
	printf("\n\t\t\t  ----------------------------------------------------------------------");
    printf("\n\t\t\t  |    Rules:                                                           |\n");
    printf("\t\t\t  |  1. One game one life, so play wisely.                              |\n");
    printf("\t\t\t  |  2. You will lose as soon as the snake tries to eat the wall        |\n");
    printf("\t\t\t  |  3. Eat as much as you can and get fat to pass other player score!  |");
    printf("\n\t\t\t  ----------------------------------------------------------------------");
    printf("\n\n\t\t\t   ");
	printf("Control : Use PAGE UP/DOWN/LEFT/RIGHT as control to move the snake");
    printf("\n\n\n\t\t\t   ");
    system("pause");
}

void load(){
    int row,col,r,c,q;
    gotoxy(50,12);
    printf("Preparing....");
    gotoxy(45,13);
    for(r=1; r<=20; r++){
        for(q=0; q<=100000000; q++);
        printf("%c",177);
    }
    gotoxy(40,17);
    system("pause");
}

void Move(){
    int a,i;
    do{
        Food();
        fflush(stdin);
        len=0;
        for(i=0; i<30; i++){
            body[i].x=0;
            body[i].y=0;
            if(i==length)
                break;
        }
        Delay(length);
        Border();
        if(head.direction==RIGHT)
            Right();
        else if(head.direction==LEFT)
            Left();
        else if(head.direction==DOWN)
            Down();
        else if(head.direction==UP)
            Up();
        ExitGame();
	}
    while(!kbhit());
    a=getch();
    if(a==27){
       	system("cls");
    	exit(0);
    }
    
    key=getch();

    if((key==RIGHT&&head.direction!=LEFT&&head.direction!=RIGHT)||(key==LEFT&&head.direction!=RIGHT&&head.direction!=LEFT)||(key==UP&&head.direction!=DOWN&&head.direction!=UP)||(key==DOWN&&head.direction!=UP&&head.direction!=DOWN)){
        bend_no++;
        bend[bend_no]=head;
        head.direction=key;

        if(key==UP)
            head.y--;

        if(key==DOWN)
            head.y++;

        if(key==RIGHT)
            head.x++;
            
        if(key==LEFT)
            head.x--;

        Move();
    }

    else if(key==27){
        system("cls");
        exit(0);
    }

    else{
        printf("\a");
        Move();
    }
}

void gotoxy(int x, int y){
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void GotoXY(int x, int y){
    HANDLE a;
    COORD b;
    fflush(stdout);
    b.X = x;
    b.Y = y;
    a = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleCursorPosition(a,b);
}

void setcolor(int ForgC){ 
	WORD wColor;
	HANDLE hStdOut=GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_SCREEN_BUFFER_INFO csbi;

	if(GetConsoleScreenBufferInfo(hStdOut,&csbi)){
	wColor=(csbi.wAttributes & 0xB0)+(ForgC & 0x0B);
	SetConsoleTextAttribute(hStdOut,wColor);
	}
}

void Up(){
    int i;
    for(i=0; i<=(bend[bend_no].y-head.y)&&len<length; i++){
        GotoXY(head.x,head.y+i);{
            if(len==0)
                printf("^");
            else
                printf("*");
        }
        body[len].x=head.x;
        body[len].y=head.y+i;
        len++;
    }
    Bend();
    if(!kbhit())
        head.y--;
}

void Down(){
    int i;
    for(i=0; i<=(head.y-bend[bend_no].y)&&len<length; i++){
        GotoXY(head.x,head.y-i);{
            if(len==0)
                printf("v");
            else
                printf("*");
        }
        body[len].x=head.x;
        body[len].y=head.y-i;
        len++;
    }
    Bend();
    if(!kbhit())
        head.y++;
}

void Left(){
    int i;
    for(i=0; i<=(bend[bend_no].x-head.x)&&len<length; i++){
        GotoXY((head.x+i),head.y);{
            if(len==0)
                printf("<");
            else
                printf("*");
        }
        body[len].x=head.x+i;
        body[len].y=head.y;
        len++;
    }
    Bend();
    if(!kbhit())
        head.x--;
}

void Right(){
    int i;
    for(i=0; i<=(head.x-bend[bend_no].x)&&len<length; i++){
        body[len].x=head.x-i;
        body[len].y=head.y;
        GotoXY(body[len].x,body[len].y);{
            if(len==0)
                printf(">");
            else
                printf("*");
        }
        len++;
    }
    Bend();
    if(!kbhit())
        head.x++;
}

void Delay(long double k){
    Score();
    long double i;
    for(i=0; i<=(15000000); i++);
}

void Food(){
    if(head.x==food.x&&head.y==food.y){
        length++;
        time_t a;
        a=time(0);
        srand(a);
        food.x=rand()%70;
        if(food.x<=10)
            food.x+=11;
        food.y=rand()%25;
        if(food.y<=5)
            food.y+=6;
    }
    else if(food.x==0){
        food.x=rand()%70;
        if(food.x<=10)
            food.x+=11;
        food.y=rand()%25;
        if(food.y<=5)
            food.y+=6;
    }
}

void Bend(){
    int i,j,diff;
    for(i=bend_no; i>=0&&len<length; i--){
        if(bend[i].x==bend[i-1].x){
            diff=bend[i].y-bend[i-1].y;
            if(diff<0)
                for(j=1; j<=(-diff); j++){
                    body[len].x=bend[i].x;
                    body[len].y=bend[i].y+j;
                    GotoXY(body[len].x,body[len].y);
                    printf("*");
                    len++;
                    if(len==length)
                        break;
                }
            else if(diff>0)
                for(j=1; j<=diff; j++){
                    body[len].x=bend[i].x;
                    body[len].y=bend[i].y-j;
                    GotoXY(body[len].x,body[len].y);
                    printf("*");
                    len++;
                    if(len==length)
                        break;
                }
        }
        else if(bend[i].y==bend[i-1].y){
            diff=bend[i].x-bend[i-1].x;
            if(diff<0)
                for(j=1; j<=(-diff)&&len<length; j++){
                    body[len].x=bend[i].x+j;
                    body[len].y=bend[i].y;
                    GotoXY(body[len].x,body[len].y);
                    printf("*");
                    len++;
                    if(len==length)
                        break;
                }
            else if(diff>0)
                for(j=1; j<=diff&&len<length; j++){
                    body[len].x=bend[i].x-j;
                    body[len].y=bend[i].y;
                    GotoXY(body[len].x,body[len].y);
                    printf("*");
                    len++;
                    if(len==length)
                        break;
                }
        }
    }
}

void Border(){
    system("cls");
    int i;
    GotoXY(food.x,food.y);   
    printf("O");
    for(i=10; i<=70; i++){
        GotoXY(i,5);
        printf("-");
        GotoXY(i,25);
        printf("-");
    }
    for(i=6; i<=24; i++){
        GotoXY(10,i);
        printf("|");
        GotoXY(70,i);
        printf("|");
    }
    //system("pause");
}
void ExitGame(){
    int i,check=0;
    
    for(i=4; i<length; i++){
        if(body[0].x==body[i].x&&body[0].y==body[i].y){
            check++;    
        }
        if(i==length||check!=0)
            break;
    }
    
    if(head.x<=10||head.x>=70||head.y<=5||head.y>=25||check!=0){
        life--;
        if(life>=0){
            head.x=25;
            head.y=20;
            bend_no=0;
            head.direction=RIGHT;
            Move();
        }
        else{
            system("cls");
            gotoxy(50,13);
            printf("GAME OVER");
            Sleep(2000);
            gotoxy(40,17);
            system("pause");
            record();
            exit(0);
        }
    }
}

void record(){
	int i,j;
	char nplname[20],cha,c;
    long int recsize;
    FILE *info;
    info=fopen("record.txt","a+");
    system("cls");
    
	struct scores a;
    printf("Masukkan Nama	:\n");
    scanf("%[^\n]",a.plname);
    a.px=Scoreonly();
	
    time_t mytime;
    mytime = time(NULL);
    fprintf(info,"\nNama :%s \nPlayed Date :%s \nScore: %d",a.plname,ctime(&mytime),a.px);
    
    for(i=0; i<=50; i++)
        fprintf(info,"%c",'_');
    fprintf(info,"\n");
    fclose(info);
    printf("Wanna see past records press 'y'\n");
    cha=getch();
    system("cls");
    
    if(cha=='y'){
        info=fopen("record.txt","r");
        do{
            putchar(c=getc(info));
        }
        while(c!=EOF);
    }
    fclose(info);
}

int Score(){
    int score;
    GotoXY(80,13);
    score=length-5;
    printf("SCORE : %d",(length-5));
    score=length-5;
    GotoXY(80,15);
    printf("Chance left : %d",life);
    return score;
}

int Scoreonly(){
    int score=Score();
    system("cls");
    return score;
}
