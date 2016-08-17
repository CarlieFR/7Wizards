intro()
{

cls();
border(0,0,32,28);
put_string("In a time where, after endless",1,1);
put_string("magic battles, only priests",1,3);
put_string("are allowed to cast healing",1,5);
put_string("magic, wizards are feared,",1,7);
put_string("if not chased...",1,9);
put_string("Most of the remaining magic",1,13);
put_string("caster have turned into sage",1,15);
put_string("master for everyone's sake...",1,17);
put_string("However, a few of them decided",1,21);
put_string("to use their unique abilities",1,23);
put_string("for greed and power...",1,25);
vsync(60);
put_char('>',30,26);
while(!(joy(0)));

}

help()
{
  border(0,0,32,10);
  blank(1,1,30,8);
  put_string("Here should start the quest",1,1);
  put_string("of Bob the blob...If it",1,2);
  put_string("wasn't a test rom for a next",1,3);
  put_string("rpg game! Have some fun until",1,4);
  put_string("the next release!",1,5);
  put_string("PUSH BUTTON",20,8);
  while(!(joytrg(0)));
  blank(1,1,30,8);
  put_string("If you want to help me",1,1);
  put_string("with the gfx or the music",1,2);
  put_string("just sent me a mail!",1,3);
  vsync(30);
  while(!(joytrg(0) & JOY_STRT));
}

Welcome()
{
  border(0,0,32,10);
  blank(1,1,30,8);
  put_string("As you approach the village",1,1);
  put_string("you hear a familliar voice.",1,2);
  vsync(20);
  put_string("You can see the elder",1,4);
  put_string("coming toward you :",1,5);
  put_string("Welcome back",1,6);
  put_string(NamP1,14,6);
  put_string("How was your hunt?",1,7);
  vsync(30);
  put_char('>',30,8);
  while(!(joytrg(0)));
}

HouseText1()
{
  border(0,0,32,10);
  blank(1,1,30,8);
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