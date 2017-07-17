#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include <time.h>
#include <direct.h>


//SOURCE CODE.


/*
*Encrypter/Decrypter
*Date : 14-Jul-2017
*Author : Vertigo_101
*Version : 1.2
*See Readme.md for usage.
*/


void mainscreen();
void encrypt();
void decrypt();
//void display();//In beta.
void ex();
void about();
void gotoxy(int,int);
void delay();

//char p;

int i;
int option;
FILE *or ,*en ,*de;
char o[10000] ,e[10000] ,d[10000];;
char cd = 177,ce  =178;
char ch;


int main()
{

  mainscreen();
  return 0;
}
void mainscreen()
{
  system("cls");

  for(i=0;i<=167;i++) {

      delay();

      printf("=");
      }

  gotoxy(66,1);
  printf("||Welcome to Encrypter/Decrypter.||\n");

  for(i=0;i<=167;i++) {

      delay();
      printf("=");
      }

      gotoxy(66,6);
      printf("++{Please select a valid option :}++\n");

      gotoxy(75,8);
      printf("1.Encrypt a file");

      gotoxy(75,9);
      printf("2.Decrypt a file");

      gotoxy(75,10);
      printf("3.About");

      gotoxy(75,11);
      printf("4.Exit");

      gotoxy(75,13);
      printf("Choice :\t");
      scanf("%d",&option);
      fflush(stdin);

    while(1) {

        switch (option) {

          case 1 ://Encrypt
                  encrypt();
                  break;
          case 2 ://Decrypt
                  decrypt();
                  break;
          case 3 ://About
                  about();
                  break;
          case 4 ://Exit
                  ex();
                  break;
          default ://Invalid Option
                  gotoxy(69,15);
                  printf("[!] No valid option selected.");

                  gotoxy(69,16);
                  printf("[*] Exiting program.");

                  gotoxy(88,16);
                  for(i=0;i<=4;i++) {

                    sleep(1);

                    printf(".");
                  }

                  exit(EXIT_FAILURE);
                  break;
        }

    }

}
void encrypt()
{
  gotoxy(69,16);
  puts(" >Enter the file to be encrypted :");

  gotoxy(80,17);
  gets(o);

  gotoxy(69,19);
  puts(" >Enter the output file :");

  gotoxy(80,20);
  gets(e);

  or = fopen(o,"r");
  en = fopen(e,"w");

  if(or == NULL || en == NULL) {

    gotoxy(70,22);
    printf("[X] This file cannot be opened.");

    gotoxy(70,23);
    printf("[!] Reason : ");
    perror("");

    //Return to main menu.
    gotoxy(70,25);
    printf("[?] Press yy to retry. :\t");
    getch();

    if(getch()=='y')
      mainscreen();

    else
      ex();
  }
//Processing animation.

  gotoxy(69,25);
  printf("[*] Encrypting : " );

  gotoxy(86,25);
  for(i=0;i<=20;i++) {

    delay();
    printf("%c",cd);
  }

  gotoxy(86,25);
  for(i=0;i<=20;i++) {

    delay();
    printf("%c",ce);
  }

  while((ch = getc(or)) != EOF) {

  if(ch >= 32 && ch <= 122) {

  delay();

  ch = ch + 4;
  }

  fputc(ch,en);
  }

  fclose(or);
  fclose(en);

  fflush(stdin);
  printf("\a");

  gotoxy(69,27);
  printf("[+] Process Complete.");


  //Return to main menu.
  gotoxy(69,30);
  printf("[<] Press 99 to Return to main menu.");
  getch();

  if(getch()=='9')
    mainscreen();

  else {

    gotoxy(69,32);
    printf("[!] Invalid option Exiting.");
    ex();
  }


/* In beta

  printf("Do you want to read the created file?(y/n) : ");
  scanf("%c",&p);

  if(p == 'y') {

    while(fgets(e,10000,en)) {

      printf("%s",e);
    }
  }
*/


  system("pause");

}
void decrypt()
{

  gotoxy(69,16);
  puts(" >Enter the file to be decrypted :");

  gotoxy(80,17);
  gets(e);

  gotoxy(69,19);
  puts(" >Enter the output file :");

  gotoxy(80,20);
  gets(d);

  en = fopen(e,"r");
  de = fopen(d,"w");

if(en == NULL || de == NULL) {

  gotoxy(70,22);
  printf("[X] This file cannot be opened.");

  gotoxy(70,23);
  printf("[!] Reason : ");
  perror("");


  //Return to main menu.

  gotoxy(70,25);
  printf("[?] Press yy to retry. :\t");
  getch();

  if(getch()=='y')
    mainscreen();

  else
    ex();

}
//Processing animation.

  gotoxy(69,25);
  printf("[*] Decrypting : " );

  gotoxy(86,25);
  for(i=0;i<=20;i++) {

     delay();
     printf("%c",cd);
  }

  gotoxy(86,25);
  for(i=0;i<=20;i++) {

     delay();
     printf("%c",ce);
  }


while((ch = getc(en)) != EOF) {

  if(ch >= 36 && ch <= 126) {
    delay();

  ch = ch - 4;
  }

fputc(ch,de);

}

fclose(en);
fclose(de);

fflush(stdin);
printf("\a");

gotoxy(69,27);
printf("[+] Process Complete.");

gotoxy(80,29);

//Return to main menu.

gotoxy(69,30);
printf("[<] Press 99 to Return to main menu.");
getch();

if(getch()=='9')
  mainscreen();
else {
  gotoxy(69,32);
  printf("[!] Invalid option Exiting.");
  ex();
 }
}
void about()
{

  gotoxy(72,16);
  printf("*Encrypter/Decrypter");

  gotoxy(72,17);
  printf("*Date : 14-Jul-2017");

  gotoxy(72,18);
  printf("*Author : Vertigo_101");

  gotoxy(72,19);
  printf("*Version : 1.2");

  gotoxy(72,20);
  printf("*See Readme.md for usage.");

  //Return to main menu.

  gotoxy(69,23);
  printf("[<] Press 99 to Return to main menu.");
  getch();

  if(getch()=='9')
    mainscreen();

  else {

    gotoxy(69,25);
    printf("[!] Invalid option selected.");

    gotoxy(69,27);
    printf("[*] Exiting Program");

    gotoxy(88,27);
    for(i=0;i<=4;i++) {

      sleep(1);

      printf(".");
    }

    exit(EXIT_FAILURE);


  }

  sleep(20);
}
void ex()
{
  char ch;

  printf("\a");

  gotoxy(69,35);
  printf("[?] Are you sure you want to exit?(y/n) :\t");
  scanf("%c",&ch);

  if(ch == 'y') {

    gotoxy(69,37);
    printf("[*] Exiting Program");

    gotoxy(88,37);
    for(i=0;i<=4;i++) {

      sleep(1);

      printf(".");
  }

  exit(EXIT_FAILURE);
  }

else if(ch == 'n')
      mainscreen();

  printf("\n");
  exit(0);
}
void gotoxy(int x,int y)
{
  COORD c;

  c.X=x;
  c.Y=y;

  SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),c);
}
void delay()
{
  long double i;
  for(i=0;i <= 1999999;i++);
}
