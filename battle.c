#include "huc.h"
#include "monsters.c"
#include "var.c"
#include "const.c"
#include "magic.c"
#include "musicsystem.c"
#include "music4.c"
#include "silence.c"
#include "cadre.c"
#include "itemeffect.c"

/********************************/
#include "graphbattle.c"

/****************************************/
/*          Battle System               */
/****************************************/
main()
{
int Life,Exp,enemyres;
char DexN,DefN,AtkN;
int oldHP[4],life_enemy,select,wound,res;
char turn,continu,target,i,playing;

Life = (monsterLifeMax[monsterID]*2)/3 + (rand() % (monsterLifeMax[monsterID]/3));
Exp = monsterExp[monsterID];
enemyres = monsterRes[monsterID];
AtkN = monsterAtk[monsterID];
DefN = monsterDef[monsterID];
DexN = monsterDex[monsterID];

load_sprites(FIREMAGICPTR,fire_magicgfx,2);
load_sprites(ICEMAGICPTR,ice_magicgfx,2);
set_sprpal(ICE_MAGICPAL,ice_magicpal);
set_sprpal(FIRE_MAGICPAL,fire_magicpal);
load_sprites(NUMBERPTR,numgfx,2);
set_sprpal(NUMPAL,numpal);
load_sprites(ACTIONBARPTR,bargfx,4);
set_sprpal(BARPAL,barpal);

load_palette(TILE_PAL, tilespal, 1);
  for(i=0; i<250; i++) {
    tiles_pal_ref[i] = TILE_PAL <<4;
  }
  set_tile_data(tilesgfx, 250, tiles_pal_ref);
  load_tile(Ram_tiles);

silence();
music4Init();
count=0;

set_font_color(1,2);
load_default_font();

for(i=0;i<4;i++)
oldHP[i]=HPp[i];

while(1)
{

  satb_update();
  cls();
  battlescreen();
  border(10,22,22,6);

  for(i=0;i<4;i++)
   HPp[i]=oldHP[i];
  life_enemy=Life;
  continu=1;
  RInit(DexN);

for(i=0;i<4;i++)
 {
  if (HPp[i])
  {
   BattleX[i]=200;
   BattleY[i]=(i+1)*32;
   spr_set(50+i);
   spr_pri(1);
   if (i==0)
   	spr_pattern(PLAYER1PTR+0x240);
   else
	spr_pattern(PLAYER2PTR+0x240);
   spr_ctrl(FLIP_MAS | SIZE_MAS,NO_FLIP | SZ_16x16);
   if(i==0)
   	spr_pal(P1PAL);
   else
   	spr_pal(P2PAL);
   spr_x(BattleX[i]);
   spr_y(BattleY[i]);
   spr_show();
  }
 }

   spr_set(54);
   spr_pri(1);
   spr_pattern(0X6000);
   spr_ctrl(FLIP_MAS | SIZE_MAS,NO_FLIP | SZ_32x32);
   spr_pal(SPRITEPAL);
   BattleX[4]=40;
   BattleY[4]=80;
   spr_x(BattleX[4]);
   spr_y(BattleY[4]);
   spr_show();

 while ((HPp[0]>0) && (HPp[1]>0) && (life_enemy>0))
 {
   fightframe(life_enemy,turn);
   turn=STurn(DexN);
   /*play[turn]=0;*/
   /*spr_set(50+turn);*/
   satb_update();

switch(turn)
  {
/*    PLAYER 1    */
  case 0:

  BattleP1(&life_enemy,DefN,DexN,enemyres);
  /*turn=STurn(turn);*/

  break;

/*    PLAYER 2    */
  case 1:

  BattleP2(&life_enemy,DefN,DexN,enemyres);
  /*turn=STurn(turn);*/

  break;

/*    PLAYER 3    */
/*  case 2:

  switch(battleselect())
  {
   case 1:
    wound=fight(AtkP[turn],DexP[turn],DefN,DexN);
    if (wound)
     {
      put_string(NamP3,2,1);
      put_string("hit for      points",9,1);
      life_enemy-=wound;
      put_number(wound,4,16,1);
     }
      else
       {
	put_string(NamP3,2,1);
	put_string("missed",9,1);
       }

     turn=STurn(turn);
     break;

   case 2:
       Magicbattle(turn,life_enemy,enemyres);
       break;
   case 3:
       Special(turn);
       break;
   case 4:
       Battleitem(turn);
       break;
   }
  break;

/*    PLAYER 4    */
/*  case 3:

  switch(battleselect())
  {
   case 1:
    wound=fight(AtkP[turn],DexP[turn],DefN,DexN);
    if (wound)
     {
      put_string(NamP4,2,1);
      put_string("hit for      points",9,1);
      life_enemy-=wound;
      put_number(wound,4,16,1);
     }
      else
       {
	put_string(NamP4,2,1);
	put_string("missed",9,1);
       }

     turn=STurn(turn);
     break;

   case 2:
       Magicbattle(turn,life_enemy,enemyres);
       break;
   case 3:
       Special(turn);
       break;
   case 4:
       Battleitem(turn);
       break;
   }
  break;

/*      ENEMY 1      */
 case 4:
   spr_set(54);
   /*spr_pal(SPRITEPAL);*/
   blank(1,23,8,4);
   border(0,22,10,6);
   put_string("PUSH",3,23);
   put_string("START",3,25);


   while(!(joytrg(0) & JOY_STRT))
   {
     music_update();
     rand();
     vsync();
   }

   blank(1,1,30,1);
   target=rand()%2;
   while(HPp[target]<1) target=rand()%2;

    for(i=0;i<5;i++) {spr_x(spr_get_x()+1); vsync(); satb_update();}
    for(i=0;i<5;i++) {spr_x(spr_get_x()-1); vsync(); satb_update();}
     wound=fight(AtkN,DexN,DefP[target],DexP[target]);
     if (wound)
       {
	put_string("Enemy attacks",5,1);
	HPp[target]-=wound;
        damage(wound,200,(target+1)*32);
	if (HPp[target]<0) HPp[target]=0;
       }
       else
	put_string("He missed",5,1);

   /*turn=STurn(turn);*/
   break;
  }

   /*playing=0;
   for(i=0;i<5;i++) playing+=play[i];
   if (!(playing))
     {
      RInit(DexN);
      turn=STurn(DexN);
     }*/
   music_update();
   vsync(2);
 }

   fightframe(life_enemy,4);
   for(i=0;i<4;i++)
     put_number(HPp[i],5,25,23+i);
   put_number(life_enemy,5,25,21);

  silence();
  battleEnd=1;
  vsync(60);
  blank(1,1,30,1);

 if (!(bonus(Exp)))
    {
     for(i=0;i<5;i++)
     {
      spr_set(50+i);
      spr_hide();
     }
     for(i=0;i<4;i++)
     {
      spr_set(10+i);
      spr_hide();
     }
     for(i=0;i<8;i++)
     {
      spr_set(BARBASESPR+i);
      spr_hide();
     }
     satb_update();

     spr_set(0);
     spr_pal(P1PAL);
     /*return;*/
     cd_execoverlay(OVL_RPG);
    }
  }



}
/*********************************************/
/*           Fight low frame                 */
/*********************************************/
fightframe(life_enemy,turn)
int life_enemy,turn;
{
char i;

 blank(1,23,30,4);
 border(10,22,22,6);
 put_string(NamP1,12,23);
 put_string(NamP2,12,24);
 put_string(NamP3,12,25);
 put_string(NamP4,12,26);
 put_string("Enemy",12,21);
 for(i=0;i<4;i++)
 {
   put_number(HPp[i],5,25,23+i);
   /*spr_set(BARBASESPR+2*i);
   spr_show();
   spr_set(BARBASESPR+2*i+1);
   spr_show();*/
 }
 put_number(life_enemy,5,25,21);
 blank(11,23,1,4);
 if (turn<4) put_char('>',11,23+turn);
}
/*********************************************/
/*            Fight Sequence                 */
/*********************************************/
fight(Atk1,Dex1,Def2,Dex2)
int Atk1,Dex1,Def2,Dex2;
{
int hit,wound;
 hit=2*(rand() % Dex1) - (rand() % Dex2);
     if (hit<0)
	return 0;
      else
       {
       wound=2*(rand() % Atk1) - (rand() % Def2);
       if (wound<=0)
	 return 1;
	else
	 return wound;
	}
}
/*********************************************/
/*              Battle Option                */
/*********************************************/
battleselect()
{
char select;

  select=1;
  put_char('>',1,23);
  put_string("Fight",2,23);
  put_string("Magic",2,24);
  put_string("Special",2,25);
  put_string("Item",2,26);
  border(0,22,10,6);

  while(!(joytrg(0) & JOY_A))
    {
     if ((joytrg(0) & JOY_DOWN) && (select<4))
       { put_char(' ',1,22+select);
	 select++;
	 put_char('>',1,22+select);
       }
     if ((joytrg(0) & JOY_UP) && (select>1))
       { put_char(' ',1,22+select);
	 select--;
	 put_char('>',1,22+select);
       }
     music_update();
     vsync(1);
     rand();
    }
  put_char(' ',1,22+select);
  blank(1,1,30,1);

return select;
}
/*********************************************/
/*              Battle Magic                 */
/*********************************************/
Magicbattle(Player,enemyHP,enemyres)
char Player;
int *enemyHP,enemyres;
{
char select,i,j;
  blank(1,23,30,4);
  border(0,22,24,6);
  border(24,22,8,6);
  put_string("MP Use",25,24);
  select=0;
  put_char('>',1,23+select);
  vsync();

for(i=0; i<8; i++)
{
  spr_set(BARBASESPR+i);
  spr_hide();
}
satb_update();

switch (Player)
{
 case 0: /* Player 1 magic */
 {
  for(i=0;i<4;i++) put_string(magicname[i],2,23+i);

  while(!(joytrg(0) & (JOY_STRT | JOY_B)))
  {
  music_update();
  put_number(magicmp[select],2,27,25);
    if (joytrg(0))
   {
     if (joytrg(0) & JOY_A)
      {
       spr_set(50);
        for(i=0;i<6;i++)
	  {
	   if (i&0X1)
	    {
	      spr_pattern(PLAYER1PTR+0x240);
	      satb_update();
	      for(j=0;j<5;j++)
	      {
	        music_update();
	        vsync(1);
	      }
	    }
	   else
	    {
	      spr_pattern(PLAYER1PTR+0x280);
	      satb_update();
	      for(j=0;j<2;j++)
	      {
	        music_update();
	        vsync(1);
	      }
	    }
	  }
	switch(select)
	{
	 case 0:
	  {
	   Fireball(BattleX[Player],BattleY[Player],BattleX[4],BattleY[4]);
	   break;
	  }
	 case 1:
	  {
	   Icefall(BattleX[4],BattleY[4]);
	   break;
	  }
	 default:
	  {
	   Fireball(BattleX[Player],BattleY[Player],BattleX[4],BattleY[4]);
	   break;
	  }
	}/*end switch*/
        Magiceffect(Player,select,enemyHP,0,enemyres);
	for(i=0; i<8; i++)
	{
	  spr_set(BARBASESPR+i);
	  spr_show();
	}
	satb_update();
	return;
      }
     if ((joytrg(0) & JOY_UP) && (select>0)) select--;
     if ((joytrg(0) & JOY_DOWN) && (select<9)) select++;
     blank(1,23,22,4);
   if (select<2)
    {
     put_char('>',1,23+select);
     for(i=0;i<4;i++) put_string(magicname[i],2,23+i);
    }
   else
    {
     if (select==9)
      {
       put_char('>',1,26);
       for(i=select-3;i<select+1;i++) put_string(magicname[i],2,26+i-select);
      }
     else
      {
       put_char('>',1,25);
       for(i=select-2;i<select+2;i++) put_string(magicname[i],2,25+i-select);
      }
    }
   }

   vsync();
  }
 }


 case 1: /* Player 2 magic */
 {
  for(i=0;i<4;i++) put_string(magicname[i],2,23+i);

  while(!(joytrg(0) & (JOY_STRT | JOY_B)))
  {
  music_update();
  put_number(magicmp[select],2,27,25);
  if (joytrg(0))
   {
     if (joytrg(0) & JOY_A)
      {
       spr_set(51);
        for(i=0;i<6;i++)
	  {
	   if (i&0X1)
	    {
	      spr_pattern(PLAYER2PTR+0x240);
	      satb_update();
	      for(j=0;j<5;j++)
	      {
	        music_update();
	        vsync(1);
	      }
	    }
	   else
	    {
	      spr_pattern(PLAYER2PTR+0x280);
	      satb_update();
	      for(j=0;j<2;j++)
	      {
	        music_update();
	        vsync(1);
	      }
	    }
	  }
	switch(select)
	{
	 case 0:
	  {
	   Fireball(BattleX[Player],BattleY[Player],BattleX[4],BattleY[4]);
	   break;
	  }
	 case 1:
	  {
	   Icefall(BattleX[4],BattleY[4]);
	   break;
	  }
	 default:
	  {
	   Fireball(BattleX[Player],BattleY[Player],BattleX[4],BattleY[4]);
	   break;
	  }
	}/*end switch*/
	Magiceffect(Player,select,enemyHP,0,enemyres);
	for(i=0; i<8; i++)
	{
	  spr_set(BARBASESPR+i);
	  spr_show();
	}
	satb_update();
	return;
      }
     if ((joytrg(0) & JOY_UP) && (select>0)) select--;
     if ((joytrg(0) & JOY_DOWN) && (select<9)) select++;
     blank(1,23,22,4);
   if (select<2)
    {
     put_char('>',1,23+select);
     for(i=0;i<4;i++) put_string(magicname[i],2,23+i);
    }
   else
    {
     if (select==9)
      {
       put_char('>',1,26);
       for(i=select-3;i<select+1;i++) put_string(magicname[i],2,26+i-select);
      }
     else
      {
       put_char('>',1,25);
       for(i=select-2;i<select+2;i++) put_string(magicname[i],2,25+i-select);
      }
    }
   }

   vsync();
  }
/*  case 2:
 {
  for(i=0;i<4;i++) put_string(magicname[i],2,23+i);

  while(!(joytrg(0) & JOY_STRT))
  {
  put_number(magicmp[select],2,27,25);
    if (joytrg(0))
   {
     if (joytrg(0) & JOY_A)
      {
       magiceffect(player,select,enemyHP,0,enemyres);
      }
     if ((joytrg(0) & JOY_UP) && (select>0)) select--;
     if ((joytrg(0) & JOY_DOWN) && (select<9)) select++;
   blank(1,23,22,4);
   if (select<2)
    {
     put_char('>',1,23+select);
     for(i=0;i<4;i++) put_string(magicname[i],2,23+i);
    }
   else
    {
     if (select==9)
      {
       put_char('>',1,26);
       for(i=select-3;i<select+1;i++) put_string(magicname[i],2,26+i-select);
      }
     else
      {
       put_char('>',1,25);
       for(i=select-2;i<select+2;i++) put_string(magicname[i],2,25+i-select);
      }
    }
   }

   vsync();
  }
 }
 case 3:
 {
  for(i=0;i<4;i++) put_string(magicname[i],2,23+i);

  while(!(joytrg(0) & JOY_STRT))
  {
  put_number(magicmp[select],2,27,25);
  if (joytrg(0))
   {
     if (joytrg(0) & JOY_A)
      {
       magiceffect(player,select,enemyHP,0,enemyres);
      }
     if ((joytrg(0) & JOY_UP) && (select>0)) select--;
     if ((joytrg(0) & JOY_DOWN) && (select<9)) select++;
      blank(1,23,22,4);
   if (select<2)
    {
     put_char('>',1,23+select);
     for(i=0;i<4;i++) put_string(magicname[i],2,23+i);
    }
   else
    {
     if (select==9)
      {
       put_char('>',1,26);
       for(i=select-3;i<select+1;i++) put_string(magicname[i],2,26+i-select);
      }
     else
      {
       put_char('>',1,25);
       for(i=select-2;i<select+2;i++) put_string(magicname[i],2,25+i-select);
      }
    }
   }
   vsync();
   }
 } */
}
}
for(i=0; i<8; i++)
{
  spr_set(BARBASESPR+i);
  spr_show();
}
satb_update();
}
/*********************************************/
/*             Battle Special                */
/*********************************************/
Special(Player)
char Player;
{
  blank(1,23,30,4);
  border(0,22,32,6);
  vsync();
  while(!(joy(0)))
  {
    music_update();
    vsync();
  }
}
/*********************************************/
/*               Battle Item                 */
/*********************************************/
Battleitem(Player)
char Player;
{
char select,i;
  blank(1,23,30,4);
  border(0,22,20,6);
  border(20,22,12,6);
  vsync();
  select=0;
  put_string("Items left",21,24);
  put_char('>',1,23+select);

  for(i=0; i<8; i++)
  {
    spr_set(BARBASESPR+i);
    spr_hide();
  }
  satb_update();
  vsync();

  for(i=0;i<4;i++) put_string(item[i],2,23+i);

  while(!(joytrg(0) & (JOY_STRT|JOY_B)))
  {
   put_number(itemnb[select],2,25,25);
    if (joytrg(0))
   {
     if (joytrg(0) & JOY_A)
       if (itemnb[select]>0)
         {
          itemnb[select]--;
          itemeffect(select,Player);
          return 1;
         }
     if ((joytrg(0) & JOY_UP) && (select>0)) select--;
     if ((joytrg(0) & JOY_DOWN) && (select<6)) select++;
     blank(1,23,18,4);
   if (select<2)
    {
     put_char('>',1,23+select);
     for(i=0;i<4;i++) put_string(item[i],2,23+i);
    }
   else
    {
     if (select==6)
      {
       put_char('>',1,26);
       for(i=select-3;i<select+1;i++) put_string(item[i],2,26+i-select);
      }
     else
      {
       put_char('>',1,25);
       for(i=select-2;i<select+2;i++) put_string(item[i],2,25+i-select);
      }
    }
   }
   music_update();
   vsync();
  }
for(i=0; i<8; i++)
{
  spr_set(BARBASESPR+i);
  spr_show();
}
satb_update();

return 0;
}
/*********************************************/
/*              Battle Bonus                 */
/*********************************************/
bonus(Exp)
int Exp;
{
char i,continu;
continu=1;

if ((HPp[0]>0) || (HPp[1]>0))
     {
     put_string("You won",8,1);
     vsync(60);
     blank(1,1,30,1);
     put_string("Got",1,1);
     put_number(Exp,5,5,1);
     put_string("experience point(s)",11,1);
     for(i=0;i<4;i++) ExpP[i]+=Exp;
     vsync(60);
     while(!(joy(0)));
     return 0;
     }
   else
     {
     put_string("You lost",8,1);
     put_string("Play again?",7,10);
     put_char('Y',8,13);

     vsync(60);

     while (!(joytrg(0) & JOY_STRT))
       {
	if (joytrg(0) & 0xf7)
	  {
	    if (continu)
		{
		 continu--;
		 put_char('N',8,13);
		}
	      else
		{
		 continu++;
		 put_char('Y',8,13);
		}
	  }
       vsync();
     }
     return continu;
     }
}

/*********************************************/
/*         Battle Background Display         */
/*********************************************/
const char battle_bg[] = {
  Tile_WaterSky, Tile_WaterSky, Tile_WaterSky, Tile_WaterSky, Tile_WaterSky, Tile_WaterSky, Tile_WaterSky, Tile_WaterSky,
     Tile_WaterSky, Tile_WaterSky, Tile_WaterSky, Tile_WaterSky, Tile_WaterSky, Tile_WaterSky, Tile_WaterSky, Tile_WaterSky,
  Tile_WaterSky, Tile_WaterSky, Tile_WaterSky, Tile_WaterSky, Tile_WaterSky, Tile_WaterSky, Tile_WaterSky, Tile_WaterSky,
     Tile_WaterSky, Tile_WaterSky, Tile_WaterSky, Tile_WaterSky, Tile_WaterSky, Tile_WaterSky, Tile_WaterSky, Tile_WaterSky,
  Tile_Plain, Tile_Plain, Tile_Plain, Tile_Plain, Tile_Plain, Tile_Plain, Tile_Plain, Tile_Plain,
     Tile_Plain, Tile_Plain, Tile_Plain, Tile_Plain, Tile_Plain, Tile_Plain, Tile_Plain, Tile_Plain,
  Tile_Plain, Tile_Plain, Tile_Plain, Tile_Plain, Tile_Plain, Tile_Plain, Tile_Plain, Tile_Plain,
     Tile_Plain, Tile_Plain, Tile_Plain, Tile_PlainPuddle, Tile_Plain, Tile_Plain, Tile_Plain, Tile_Plain,
  Tile_Plain, Tile_Plain, Tile_Plain, Tile_Plain, Tile_Plain, Tile_Plain, Tile_Plain, Tile_Plain,
     Tile_Plain, Tile_Plain, Tile_Plain, Tile_Plain, Tile_Plain, Tile_Plain, Tile_Plain, Tile_Plain,
  Tile_Plain, Tile_Plain, Tile_Plain, Tile_Plain, Tile_Plain, Tile_Plain, Tile_Plain, Tile_Plain,
     Tile_Plain, Tile_Plain, Tile_Plain, Tile_Plain, Tile_Plain, Tile_Plain, Tile_Plain, Tile_Plain,
  Tile_Plain, Tile_Plain, Tile_Plain, Tile_Plain, Tile_Plain, Tile_Plain, Tile_Plain, Tile_Plain,
     Tile_Plain, Tile_Plain, Tile_Plain, Tile_PlainPuddle, Tile_Plain, Tile_Plain, Tile_Plain, Tile_Plain,
  Tile_Plain, Tile_Plain, Tile_Plain, Tile_Plain, Tile_Plain, Tile_Plain, Tile_Plain, Tile_Plain,
     Tile_Plain, Tile_Plain, Tile_Plain, Tile_Plain, Tile_Plain, Tile_Plain, Tile_Plain, Tile_Plain,
  Tile_Plain, Tile_Plain, Tile_Plain, Tile_Plain, Tile_Plain, Tile_Plain, Tile_Plain, Tile_Plain,
     Tile_Plain, Tile_Plain, Tile_Plain, Tile_Plain, Tile_Plain, Tile_Plain, Tile_Plain, Tile_Plain,
  Tile_Plain, Tile_Plain, Tile_Plain, Tile_Plain, Tile_Plain, Tile_Plain, Tile_Plain, Tile_Plain,
     Tile_PlainPuddle, Tile_Plain, Tile_Plain, Tile_Plain, Tile_Plain, Tile_Plain, Tile_Plain, Tile_Plain,
  Tile_Plain, Tile_Plain, Tile_Plain, Tile_Plain, Tile_Plain, Tile_Plain, Tile_Plain, Tile_Plain,
     Tile_Plain, Tile_Plain, Tile_Plain, Tile_Plain, Tile_Plain, Tile_Plain, Tile_Plain, Tile_Plain,
  Tile_Plain, Tile_Plain, Tile_Plain, Tile_Plain, Tile_Plain, Tile_Plain, Tile_Plain, Tile_Plain,
     Tile_Plain, Tile_Plain, Tile_Plain, Tile_Plain, Tile_Plain, Tile_Plain, Tile_Plain, Tile_Plain};
     
battlescreen()
{
char i,j;

cls();

set_map_data(battle_bg, 16,12);
 load_map(0,0, 0,0, 16,12);
 
 blank(1,1,30,1);
/*i=0;
while(i<32)
 {
  j=3;
  while(j<22)
   {
    put_raw(0X104,i,j);
    j++;
   }
  i++;
 }*/
border(0,0,32,3);
}
/************************************/
/*            Select Turn           */
/************************************/
STurn(DexN)
int DexN;
{
char i;
char next;

next = 100;

while(next==100)
{
  for(i=0;i<4;i++)
  {
    if(HPp[i]>0)
    {
      roundCount[i] += DexP[i];
      if(roundCount[i]>3520) next=i;
    }
    spr_set(BARBASESPR+(i<<1));
    if((roundCount[i]>>7)<14)
    {
      spr_pattern(ACTIONBARPTR+0x40*(roundCount[i]>>7));
    }
    else
    {
      spr_pattern(ACTIONBARPTR+0x340);
    }
    spr_set(BARBASESPR+(i<<1)+1);
    if((roundCount[i]>>7)<14)
    {
      spr_pattern(ACTIONBARPTR+0x380);
    }
    else
    {
      if(roundCount[i]<=3520)
      {
        spr_pattern(ACTIONBARPTR+0x380+0x40*((roundCount[i]>>7)-14));
      }
      else
      {
        spr_pattern(ACTIONBARPTR+0x380+0x340);
      }
    }
  }
  roundCount[4] += DexN;
  if(roundCount[4]>3520) next=4;

  music_update();
  satb_update();
  vsync();
}
roundCount[next]=0;

return next;
}
/*
for (i=0;i<4;i++)
   if (play[i])
      if (round[i]==round[turn]+1) turn=i;
	    else if (round[i]<round[turn]) turn=i;

if (((round[4]<round[turn]) || (round[4]==round[turn]+1)) && (play[4])) turn=4;

round[turn]=10;

return turn;
}*/
/************************************/
/*            Round Init            */
/************************************/
RInit(DexN)
char DexN;
{
char i;/*,j,Max;*/
/*for(i=0;i<4;i++)
 {
  round[i]=5;
  if (HPp[i]>0) play[i]=1;
 }
 round[4]=5;
 play[4]=1;

*/
for(i=0;i<4;i++)
{
  roundCount[i] = rand() % DexP[i];
  spr_set(BARBASESPR+(i<<1));
  spr_pri(1);
  spr_ctrl(FLIP_MAS | SIZE_MAS,NO_FLIP | SZ_16x16);
  spr_pal(BARPAL);
  spr_x(152);
  spr_y(184+(i<<3));
  if((roundCount[i]>>7)<14)
  {
    spr_pattern(ACTIONBARPTR+0x40*(roundCount[i]>>7));
  }
  else
  {
    spr_pattern(ACTIONBARPTR+0x340);
  }
  spr_set(BARBASESPR+(i<<1)+1);
  spr_pri(1);
  spr_ctrl(FLIP_MAS | SIZE_MAS,NO_FLIP | SZ_16x16);
  spr_pal(BARPAL);
  spr_x(168);
  spr_y(184+(i<<3));
  if((roundCount[i]>>7)<14)
  {
    spr_pattern(ACTIONBARPTR+0x380);
  }
  else
  {
    if(roundCount[i]<=3520)
    {
      spr_pattern(ACTIONBARPTR+0x380+0x40*((roundCount[i]>>7)-14));
    }
    else
    {
      spr_pattern(ACTIONBARPTR+0x380+0x340);
    }

  }
}
roundCount[4] = rand() % DexN;

/*for(i=0;i<5;i++)
 {
  Max=0;
  for(j=0;j<4;j++)
       if ((DexP[j]>=DexP[Max]) && (round[j]>i)) Max=j;

    if ((DexP[Max]<=DexN) && (round[5]<i)) round[5]=i;
    else round[Max]=i;
 }*/
}
/*****************************************************/
/*             Player 1 battle system                */
/*****************************************************/
BattleP1(life_enemy,DefN,DexN,enemyres)
int *life_enemy,DefN,DexN,enemyres;
{
char wound,move,i;
int res;
move=1;

while(move)
 {
 music_update();
 fightframe((*life_enemy),0);
 spr_set(50);
 switch(battleselect())
  {
   case 1:
    wound=fight(AtkP[0],DexP[0],DefN,DexN);
    for(i=0;i<5;i++)
    {
      spr_x(spr_get_x()-1);
      music_update();
      satb_update();
      vsync();
    }
    for(i=0;i<5;i++)
    {
      spr_x(spr_get_x()+1);
      music_update();
      satb_update();
      vsync();
    }
    if (wound)
     {
      put_string(NamP1,2,1);
      put_string("attacks",9,1);
      (*life_enemy)-=wound;
      damage(wound,40,80);
     }
      else
       {
	put_string(NamP1,2,1);
	put_string("missed",9,1);
       }

     move=0;
     break;

   case 2:

       res=*life_enemy;
       Magicbattle(0,life_enemy,enemyres);
       if (!(res==(*life_enemy)))
	{
        /*for(i=0;i<6;i++)
	  {
	   if (i&0X1)
	    { spr_pattern(0x5000); satb_update(); vsync(5);}
	   else
	    { spr_pattern(0x5040); satb_update(); vsync(2);}
	  }*/
	 /*Fireball(BattleX[0],BattleY[0],BattleX[4],BattleY[4]);*/
	 put_string(NamP1,1,1);
         put_string("used magic",8,1);
         damage(res-(*life_enemy),40,80);
	 move=0;}
       break;
   case 3:
       Special(0);
       break;
   case 4:
       if (Battleitem(0)) move=0;
       break;
   }
 }
}

/***************************************************/
/*            Player 2 battle system               */
/***************************************************/
BattleP2(life_enemy,DefN,DexN,enemyres)
int *life_enemy,DefN,DexN,enemyres;
{
char wound,move,i;
int res;
move=1;

while(move)
 {
 music_update();
 fightframe((*life_enemy),1);
 spr_set(51);
 switch(battleselect())
  {
   case 1:
    wound=fight(AtkP[1],DexP[1],DefN,DexN);
    for(i=0;i<5;i++)
    {
      spr_x(spr_get_x()-1);
      music_update();
      satb_update();
      vsync();
    }
    for(i=0;i<5;i++)
    {
      spr_x(spr_get_x()+1);
      music_update();
      satb_update();
      vsync();
    }
    if (wound)
     {
      put_string(NamP2,2,1);
      put_string("attacks",9,1);
      damage(wound,40,80);
      (*life_enemy)-=wound;
     }
      else
       {
	put_string(NamP2,2,1);
	put_string("missed",9,1);
       }

     move=0;
     break;

   case 2:
       res=*life_enemy;
       Magicbattle(1,life_enemy,enemyres);

       if (res!=*life_enemy)
	{
	/*for(i=0;i<6;i++)
	{
	  if (i&0X1)
           { spr_pattern(0x5000); satb_update(); vsync(5);}
          else
           { spr_pattern(0x5040); satb_update(); vsync(2);}
        }*/
	/*Fireball(BattleX[1],BattleY[1],BattleX[4],BattleY[4]);*/
         /*spr_set(MAGICSPR);
         spr_show();
	 for(i=BattleX[1];i>BattleX[4];i=i-2)
	   {
	      spr_x(i);
	      spr_y(BattleY[1]-abs(BattleY[4]-BattleY[1])*(BattleX[1]-i)/(BattleX[1]-BattleX[4]));
	      satb_update();
	      vsync();
	   }
 	 spr_hide();*/
	 put_string(NamP2,1,1);
         put_string("used magic",8,1);
         damage(res-(*life_enemy),40,80);
	 move=0;}
       break;
   case 3:
       Special(1);
       break;
   case 4:
       if (Battleitem(1)) move=0;
       break;
   }
 }
}

/********************************************/
/*        Graphique damage function         */
/********************************************/
damage(numbers,x,y)
int numbers;
char x,y;
{
char i,j,max;

for(i=0;i<4;i++)
{
spr_set(10+i);
spr_show();
spr_pri(1);
spr_ctrl(FLIP_MAS | SIZE_MAS,NO_FLIP | SZ_16x16);
spr_pal(NUMPAL);
}

if (numbers<0)
{
 set_color(256+16*NUMPAL+1,0171);
 numbers=-numbers;
}
else
{
 set_color(256+16*NUMPAL+1,0777);
}
max=4;

if (numbers<1000)
 {
  spr_set(10);
  spr_hide();
  max=3;
  if (numbers<100)
   {
    spr_set(11);
    spr_hide();
    max=2;
    if (numbers<10)
     {
      spr_set(12);
      spr_hide();
      max=1;
     }
   }
 }

for(i=0;i<max;i++)
{
 spr_set(13-i);
 spr_x(x+10-9*i);
 spr_y(y);
 spr_pattern(0x5500+0x40*(numbers%10));
 numbers/=10;
}



for(j=0;j<4;j++)
{
 for(i=0;i<max;i++)
  {
   spr_set(13-i);
   spr_y(spr_get_y()-1);
   music_update();
   satb_update();
   vsync();
  }
}

for(j=0;j<10;j++)
{ for(i=0;i<max;i++)
  {
   spr_set(13-i);
   spr_y(spr_get_y()+1);
   music_update();
   satb_update();
   vsync();
  }
}

for(i=0;i<30;i++)
{
  music_update();
  vsync(1);
}
for(i=0;i<4;i++)
{
 spr_set(10+i);
 spr_hide();
}
satb_update();

}

