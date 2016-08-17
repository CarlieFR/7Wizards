/********************************/
/*    Header prog principal     */
/********************************/


#include "huc.h"
#include "var.c"
#include "const.c"
#include "text.c"
#include "musicsystem.c"
#include "silence.c"
#include "music5.c"
#include "essai.c"
/* #include "music4.c" */
#include "music1.c" 

/**************************************/
/*        MAIN         PROG           */
/**************************************/

main()
{
char select;

if(gameState==0)
{
  cls();
  set_font_color(1,2);
  load_default_font();

 while(1)
 {
 HPp[0]=MaxHP[0];
 HPp[1]=MaxHP[1];
 HPp[2]=0;
 HPp[3]=0;
 itemnb[0]=5;
 itemnb[1]=2;
 MPp[0]=MaxMP[0];
 MPp[1]=MaxMP[1];
 ExpP[0]=10;
 ExpP[1]=10;
 select=0;
 /* Music initialisation*/
 music5Init();
 count=0;

  load_background(titlegfx,titlepal,titlebat,32,28);

  init_satb();
  load_sprites(0X6000,sprgfx,2);
  load_sprites(PLAYER1PTR,p1gfx,2);
  load_sprites(PLAYER2PTR,p2gfx,2);

  set_sprpal(SPRITEPAL,spritepal);
  set_sprpal(P1PAL,p1pal);
  set_sprpal(P2PAL,p2pal);
  spr_set(MAGICSPR);
  spr_pri(1);
  spr_hide();
  put_string("Start a battle",11,22);
  put_string("Change name",11,20);
  put_string("Begin game",11,18);
  put_char('-',9,18);

  while (!(joytrg(0) & JOY_STRT))
  {
   if ((joytrg(0) & JOY_UP) && (select>0))
     {
      select--;
      put_char(' ',9,20+2*select);
      put_char('-',9,18+2*select);
     }
   if ((joytrg(0) & JOY_DOWN) && (select<2))
     {
      select++;
      put_char(' ',9,16+2*select);
      put_char('-',9,18+2*select);
     }
    vsync(1);
    music_update();
  }

 silence();
 count=0;

 switch (select)
 {
   case 2:
     monsterID=0;
     cd_execoverlay(OVL_BATTLE);
     break;

   case 1:
     strcpy(Entry,NamP1);
     enter();
     strcpy(NamP1,Entry);
     strcpy(Entry,NamP2);
     enter();
     strcpy(NamP2,Entry);
     strcpy(Entry,NamP3);
     enter();
     strcpy(NamP3,Entry);
     strcpy(Entry,NamP4);
     enter();
     strcpy(NamP4,Entry);
     break;

   case 0:
     battleEnd=1;
     game();
     break;
 }
 }
}
else
  game();

}

/*******************************************/
/*               Name Change               */
/*******************************************/
enter()
{
 char i,j,k;
 cls();
 border(0,0,32,28);
 border(11,10,8,3);

 put_string("Enter player name",7,4);
 border(6,3,19,3);

 border(2,20,28,6);
 for(i='A';i<'Z'+1;i++)
 {
  put_char(i,3+i-'A',21);
  put_char(i-'A'+'a',3+i-'A',23);
 }

 i=0;
 j=0;
 k=0;
 Entry[6]=0;
 while (!(joytrg(0) & JOY_STRT))
  {
   if ((joytrg(0) & JOY_RGHT) && (i<26)) i++;
    else
      if ((joytrg(0) & JOY_LEFT) && (i>0)) i--;
   if ((joytrg(0) & JOY_B) && (k>0))
      {Entry[k]=0;
      put_char(' ',12+k,13);
      k--;
      put_char('^',12+k,13);}
   if ((joytrg(0) & JOY_A) && (k==5)) Entry[k]=i+'A'+j*('a'-'A');
   if ((joytrg(0) & JOY_A) && (k<5))
      {Entry[k]=i+'A'+j*('a'-'A');
       put_char(' ',12+k,13);
       k++;
       put_char('^',12+k,13);}
   if ((joytrg(0) & JOY_UP) && (j>0)) j--;
    else
      if ((joytrg(0) & JOY_DOWN) && (j<1)) j++;
   put_string("      ",12,11);
   put_string(Entry,12,11);
   blank(3,22,26,1);
   blank(3,24,26,1);
   put_char('^',3+i,22+2*j);
   vsync(1);
  }

 return;
}
/************************************************/
#include "game.c"
/***********************************************/
#include "map.c"
/***********************************************/
#include "move.c"
/***********************************************/
#include "cadre.c"
/***********************************************/
#include "graph.c"

/***************************************/
/*             String copy             */
/***************************************/
/*strcpy(lhs,rhs)
char* lhs;
char* rhs;
{
  while (*rhs)
    *lhs++=*rhs++;
  *lhs=0;

}*/

/***************************************/
/*            Absolute valor           */
/***************************************/
/*abs(x)
int x;
{
if (x<0)
  return -x;
else
  return x;
}*/
