#include <stdio.h>
#include <string.h>
#include "menu.h"

int main(int argc, char const *argv[]) {
  char my_menu[5][MENU_MAXBUF];
  strcpy(my_menu[0],"1. Volvo");
  strcpy(my_menu[1],"2. Nissan");
  strcpy(my_menu[2],"3. Toyota");
  strcpy(my_menu[3],"4. Mercedes");
  strcpy(my_menu[4],"5. Mazda");
  setTitle("Please select:");
  int selection = customBufferMenu(5,1024,my_menu,'<','>');

  printf("You selected  %s",my_menu[selection-1]);
  return 0;
}
