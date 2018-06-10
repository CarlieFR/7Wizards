#incasm("Merry.asm")
extern struct st_header Merry[];

/************************************************/
/*               Game Program                   */
/************************************************/
game()
{
unsigned char i;

  if(g_gameState==0) {
    vsync(20);
    intro();

    g_pos=1;

    g_spriteX=16;
    g_spriteY=16;


    spr_set(0);
    spr_pri(1);
    spr_ctrl(FLIP_MAS | SIZE_MAS,NO_FLIP | SZ_16x16);
    spr_pal(0);
    spr_x(g_spriteX);
    spr_y(g_spriteY);
    g_gameState=1;
    
    /*load_sprites(Ram_tiles,tilesgfx,16);*/
    /*set_bgpal(1,tilespal);*/
     
      
    /*spr_show();
    SPRPATTERN=FR_Face;
    spr_pattern(SPRPATTERN);*/
    /*map1();*/
    g_oldpos=1;
  }
  
  load_palette(TILE_PAL, tilespal, 1);
  for(i=0; i<250; i++) {
    tiles_pal_ref[i] = TILE_PAL <<4;
  }
  set_tile_data(tilesgfx, 250, tiles_pal_ref);
  load_tile(Ram_tiles);

  st_reset();
  
while (1)
{
  
 switch (g_pos)
 {
 case -1:
    spr_hide();
    menu();
    spr_show();
    g_pos=g_oldpos;
    vsync(1);
    break;
 default:
    teleport(g_oldpos);
    g_pos = move();
    break;
 }
}


}
/***********************************************/
/*             Start Button Menu               */
/***********************************************/
menu()
{
char i;

  satb_update();
while (1)
 {
  cls();
  border(0,0,23,28);
  border(23,0,9,28);

  put_string("Item",25,2);
  put_string("Magic",25,4);
  put_string("Equip",25,6);
  put_string("Status",25,8);

  GlobalStatus();

  vsync();

  i=1;
  put_char('>',24,2*i);
  while(!(joytrg(0) & JOY_A) && !(joytrg(0) & JOY_STRT))
   {
    if ((joytrg(0) & JOY_DOWN) && (i<4))
      {
       put_char(' ',24,2*i);
       i++;
       put_char('>',24,2*i);
      }
    if ((joytrg(0) & JOY_UP) && (i>1))
      {
       put_char(' ',24,2*i);
       i--;
       put_char('>',24,2*i);
      }
     vsync(1);
   }
if (joytrg(0) & JOY_A)
   {
    switch (i)
     {
     case 1:Item(); break;
     case 2:Magic(); break;
     case 3:Equip(); break;
     case 4:Status(); break;
     }
   }
if (joytrg(0) & JOY_STRT) return;
 }
}
/***********************************************/
/*            Adventure Item Menu              */
/***********************************************/
Item()
{
char select,player;

cls();
border(0,0,32,25);
border(0,25,32,3);

for(select=0;select<11;select++)
{
put_string(c_item[select],3,2+select*2);
put_char(':',15,2+select*2);
put_number(g_itemnb[select],2,17,2+select*2);
}
select=0;
put_char('>',1,2);
vsync();

while (!(joytrg(0) & (JOY_STRT | JOY_B)))
{
 blank(1,26,30,1);
 put_string(c_itemdesc[select],1,26);
 if ((joytrg(0) & JOY_DOWN) && (select<10))
   {
    put_char(' ',1,2+2*select);
    select++;
    put_char('>',1,2+2*select);
   }
 if ((joytrg(0) & JOY_UP) && (select>0))
   {
    put_char(' ',1,2+2*select);
    select--;
    put_char('>',1,2+2*select);
   }
 if ((joytrg(0) & JOY_A) && (g_itemnb[select]>0))
 {
  g_itemnb[select]--;
  cls();
  border(0,0,32,28);
  GlobalStatus();
  vsync();
  player=SelectP();
  put_number(g_itemnb[select],2,17,2+select*2);
  itemeffect(select,player);
  }
 vsync();
}
vsync();
return;
}
/***********************************************/
/*           Adventure Magic Menu              */
/***********************************************/
Magic()
{
char select;
cls();
border(0,3,32,22);
border(0,25,32,3);
border(20,0,12,3);
put_string("MP use :",21,1);
put_number(0,2,29,1);
border(0,0,20,3);
put_string("White",3,1);
put_string("Black",12,1);
vsync();
put_char('>',2,1);
while(!(joytrg(0) & (JOY_STRT | JOY_B)))
{
select=0;
if (joytrg(0) & JOY_RGHT)
  {
   put_char(' ',2,1);
   put_char('>',11,1);
  }
if (joytrg(0) & JOY_LEFT)
  {
   put_char('>',2,1);
   put_char(' ',11,1);
  }
if (joytrg(0) & JOY_A)
{
for(select=0;select<10;select++)
 {put_string(c_magicname[select],3,4+2*select);}
select=0;

while(!(joytrg(0) & (JOY_STRT | JOY_B)))
 {
  put_number(c_magicmp[select],2,29,1);
  blank(1,26,30,1);
  put_string(c_magicdesc[select],1,26);
  put_char('>',1,select*2+4);
  if ((joytrg(0) & JOY_DOWN) && (select<9))
    {
     put_char(' ',1,select*2+4);
     select++;
    }
  if ((joytrg(0) & JOY_UP) && (select>0))
    {
     put_char(' ',1,select*2+4);
     select--;
    }
  vsync();
 }
blank(1,4,30,20);

}
put_char(' ',1,select*2+4);
vsync();
}
return;
}
/***********************************************/
/*               Equipement Menu               */
/***********************************************/
Equip()
{
char select;
cls();
border(0,0,32,9);
border(0,9,32,18);
put_string("Head       :",1,1);
put_string("Right arm  :",1,3);
put_string("Left arm   :",1,5);
put_string("Body       :",1,7);
put_char('>',14,1);
select=0;
vsync();

while (!(joytrg(0) & JOY_STRT))
{
 if ((joytrg(0) & JOY_DOWN) && (select<3))
  {
   put_char(' ',14,1+select*2);
   select++;
   put_char('>',14,1+select*2);
  }
 if ((joytrg(0) & JOY_UP) && (select>0))
  {
   put_char(' ',14,1+select*2);
   select--;
   put_char('>',14,1+select*2);
  }
 vsync();
}
vsync();
return;
}
/***********************************************/
/*                Status Menu                  */
/***********************************************/
Status()
{
char i;
cls();
border(0,0,32,28);
i=0;

put_string("Name :",2,2);
put_string("Level :",2,4);
put_string("Attack :",2,6);
put_string("Defense :",2,8);
put_string("Dexterity :",2,10);
put_string("Experience :",2,12);

while(!(joytrg(0) & JOY_STRT))
{
if ((joytrg(0) & JOY_LEFT) && (i>0))
 {
   put_string("      ",13,2);
   i--;
 }
if ((joytrg(0) & JOY_RGHT) && (i<3))
 {
   put_string("      ",13,2);
   i++;
 }
switch(i)
{
case 0: put_string(g_nameP1,13,2); break;
case 1: put_string(g_nameP2,13,2); break;
case 2: put_string(g_nameP3,13,2); break;
case 3: put_string(g_nameP4,13,2); break;
}
put_number(1,2,17,4);
put_number(g_atkP[i],3,16,6);
put_number(g_defP[i],3,16,8);
put_number(g_dexP[i],3,16,10);
put_number(g_expP[i],4,15,12);
vsync();
}
}
/***********************************************/
/*           4-player Global Status            */
/***********************************************/
GlobalStatus()
{
char i;

 put_string(g_nameP1,2,2);
 put_string(g_nameP2,2,8);
 put_string(g_nameP3,2,14);
 put_string(g_nameP4,2,20);

 for(i=0;i<4;i++)
 {
 put_string("HP :",4,4+i*6);
 put_string("MP :",4,6+i*6);
 put_number(g_hp[i],4,9,4+i*6);
 put_number(g_mp[i],4,9,6+i*6);
 put_char('/',13,4+i*6);
 put_char('/',13,6+i*6);
 put_number(g_maxHP[i],4,14,4+i*6);
 put_number(g_maxMP[i],4,14,6+i*6);
 }

}
/***********************************************/
/*               Player Select                 */
/***********************************************/
SelectP()
{
char i;

i=0;

while(!(joytrg(0) & JOY_B))
 {
  blank(1,1,1,26);
  put_char('>',2,2+6*i);
  if ((joytrg(0) & JOY_UP) && (i>0)) i--;
  if ((joytrg(0) & JOY_DOWN) && (i<3)) i++;
 }

}
#include "itemeffect.c"
