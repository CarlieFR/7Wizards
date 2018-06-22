#include "strutils.c"
char text_buffer[512];

intro()
{
char* options[2];
cls();
text_buffer[0] = NULL;
cadre_border(0,0,32,28);
strcat(text_buffer,
  "In a time where, after endless magic battles, only priests are allowed to cast healing magic, wizards are feared, if not chased...\n");
strcat(text_buffer, "\nMost of the remaining magic caster have turned into sage master for everyone's sake.\n");
strcat(text_buffer, "\nHowever, a few of them decided to use their unique abilities for greed and power.\n");
strcat(text_buffer, "\nHere are {0} and {1}, two young friends travelling back home after hunting for some food.");

print_text2(text_buffer, 1, 1, 13, g_nameP1, g_nameP2);

}

help()
{
  cadre_border(0,0,32,10);
  cadre_blank(1,1,30,8);
  text_buffer[0] = NULL;
  strcat(text_buffer,
    "Here should start the quest of Bob the blob... If it wasn't a test rom for a next rpg game!\n");
  strcat(text_buffer, "Have some fun until the next release!\n");

  strcat(text_buffer, "If you want to help me, create your branch on git and submit your merge request");
  print_text(text_buffer, 1, 1, 4);

}

welcome_town1()
{
  spr_set(0);
  spr_hide();
  satb_update();
  cadre_border(0,0,32,10);
  cadre_blank(1,1,30,8);
  text_buffer[0] = NULL;
  strcat(text_buffer, "As you approach the village you hear a familliar voice.");
  print_text(text_buffer, 1, 1, 4);
  
  cadre_blank(1,1,30,8);
  text_buffer[0] = NULL;
  strcat(text_buffer, "You can see the elder coming toward you :\n");
  strcat(text_buffer, "Welcome back {0} !\nHow was your hunt?");
  print_text1(text_buffer, 1, 1, 4, g_nameP1);
  
  spr_show();
}

HouseText1()
{
  cadre_border(0,0,32,10);
  cadre_blank(1,1,30,8);
  put_string("Welcome to the first house",1,1);
  put_string("of the game!",1,2);
  put_string("If you like this game, buy it!",1,3);
  put_string("Just kidding!",1,5);
  put_string("You can send me a mail to tell",1,6);
  put_string("me what you think about it or",1,7);
  put_string("what you want in the next rlz!",1,8);
  vsync(30);
  while(!(joytrg(0)));
}