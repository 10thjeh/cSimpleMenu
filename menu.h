/*
Simple menu
02-01-2021

Installation:
Put this .h file (menu.h) on your project directory (Prefered)

OR

Put this .h file on MinGW\include (This doesn't work on my machine lmao)

Calling this header to your code:
#include <menu.h> (MinGW\include)
#include "menu.h" (On project directory)

General usage:

createMenu(4) for creating simple interactive menu
setTitle(1) to set the title of the menu
setHelp(1) to set the help text (default is = "Use arrow key to change highlighted option and press enter to select option")

createMenu(4) is using 2 dimensional array in order to do correctly, for example
you have 5 options, so you do:

char <your array name>[Number of options][Size of each options]

for Size of each options you can use our macro MENU_MAXBUF which is set to 1024

Syntax available:

createMenu(size_t a,char b, char c, char d);
where:
a is size of the 2d array
b is the 2d array of chars
c is prefix for highlighted option (only accepting single character, use single quote)
d is suffix for highlighted option (only accepting single character, use single quote)
returns integer (highlighted)

customBufferMenu(size_t a,size_t b, char c, char d, char e)
is the same as createMenu(4) but you decide each array size

setTitle(char a);
a is array of char / string (whatever you call it)

setHelp(char a);
a is array of char / string

This library is still on development and currently only tested in windows enviroment
NOTE : This library currently still depending on string.h (or cstring if you're working on cpp),please include string.h on your code
*/
#define MENU_MAXBUF 1024

char title[] = "";
char help[] = "Use arrow key to change highlighted option and press enter to select option";

void setTitle(char text[]){
  strcpy(title,text);
}

void setHelp(char text[]){
  strcpy(help,text);
}

void printHelp(){
  printf("%s\n",help);
}

void printTitle(){
  printf("%s\n",title);
}

int createMenu(size_t a,char text[a][MENU_MAXBUF],char highlight_start, char highlight_end){
  int highlighted = 0;
  int loop=1;
  int input,ans;
  while(loop){
    system("cls");
    printTitle();
    for(int i=0;i<5;i++){
      if(i==highlighted){
        printf("%c%s%c\n",highlight_start,text[i],highlight_end);
      }
      else printf("%s\n",text[i]);
    }
    printHelp();
    input=getch();
    switch (input) {
      case 72:
        if(highlighted==0) highlighted=a-1;
        else highlighted--;
        break;
      case 80:
        if(highlighted==a-1) highlighted=0;
        else highlighted++;
        break;
      case 13:
        ans=highlighted;
        loop=0;
        break;
      default:
        break;
    }
  }
  return ans+1;
}

int customBufferMenu(size_t a,size_t b,char text[a][b],char highlight_start, char highlight_end){
  int highlighted = 0;
  int loop=1;
  int input,ans;
  while(loop){
    system("cls");
    printTitle();
    for(int i=0;i<5;i++){
      if(i==highlighted){
        printf("%c%s%c\n",highlight_start,text[i],highlight_end);
      }
      else printf("%s\n",text[i]);
    }
    printHelp();
    input=getch();
    switch (input) {
      case 72:
        if(highlighted==0) highlighted=a-1;
        else highlighted--;
        break;
      case 80:
        if(highlighted==a-1) highlighted=0;
        else highlighted++;
        break;
      case 13:
        ans=highlighted;
        loop=0;
        break;
      default:
        break;
    }
  }
  return ans+1;
}
