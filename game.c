/************************************************/
/*               Game Program                   */
/************************************************/
game()
{
unsigned char i;

  if(gameState==0) {
    vsync(20);
    intro();

    pos=1;

    spriteX=16;
    spriteY=16;


    spr_set(0);
    spr_pri(1);
    spr_ctrl(FLIP_MAS | SIZE_MAS,NO_FLIP | SZ_16x16);
    spr_pal(0);
    spr_x(spriteX);
    spr_y(spriteY);
    gameState=1;
    
    /*load_sprites(Ram_tiles,tilesgfx,16);*/
    /*set_bgpal(1,tilespal);*/
     
      
    /*spr_show();
    SPRPATTERN=FR_Face;
    spr_pattern(SPRPATTERN);*/
    /*map1();*/
    oldpos=1;
  }
  
  load_palette(TILE_PAL, tilespal, 1);
  for(i=0; i<250; i++) {
    tiles_pal_ref[i] = TILE_PAL <<4;
  }
  set_tile_data(tilesgfx, 250, tiles_pal_ref);
  load_tile(Ram_tiles);

while (1)
{
  st_reset();
  
 switch (pos)
 {
 case -1:
    spr_hide();
    menu();
    spr_show();
    pos=oldpos;
    break;
 default:
    teleport(oldpos);
    pos = move();
    break;
 /*case 2:
    oldpos=2; 
    pos=move();
    break;
 case 3:
    oldpos=3;
    pos=move();
    break;
 case 4:
    oldpos=4;
    silence();
    pos=move();
    break;
 case 20000:
    oldpos=20000;
    silence();
    pos=move();
    break;*/
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
put_string(item[select],3,2+select*2);
put_char(':',15,2+select*2);
put_number(itemnb[select],2,17,2+select*2);
}
select=0;
put_char('>',1,2);
vsync();

while (!(joytrg(0) & (JOY_STRT | JOY_B)))
{
 blank(1,26,30,1);
 put_string(itemdesc[select],1,26);
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
 if ((joytrg(0) & JOY_A) && (itemnb[select]>0))
 {
  itemnb[select]--;
  cls();
  border(0,0,32,28);
  GlobalStatus();
  vsync();
  player=SelectP();
  put_number(itemnb[select],2,17,2+select*2);
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
 {put_string(magicname[select],3,4+2*select);}
select=0;

while(!(joytrg(0) & (JOY_STRT | JOY_B)))
 {
  put_number(magicmp[select],2,29,1);
  blank(1,26,30,1);
  put_string(magicdesc[select],1,26);
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
case 0: put_string(NamP1,13,2); break;
case 1: put_string(NamP2,13,2); break;
case 2: put_string(NamP3,13,2); break;
case 3: put_string(NamP4,13,2); break;
}
put_number(1,2,17,4);
put_number(AtkP[i],3,16,6);
put_number(DefP[i],3,16,8);
put_number(DexP[i],3,16,10);
put_number(ExpP[i],4,15,12);
vsync();
}
}
/***********************************************/
/*           4-player Global Status            */
/***********************************************/
GlobalStatus()
{
char i;

 put_string(NamP1,2,2);
 put_string(NamP2,2,8);
 put_string(NamP3,2,14);
 put_string(NamP4,2,20);

 for(i=0;i<4;i++)
 {
 put_string("HP :",4,4+i*6);
 put_string("MP :",4,6+i*6);
 put_number(HPp[i],4,9,4+i*6);
 put_number(MPp[i],4,9,6+i*6);
 put_char('/',13,4+i*6);
 put_char('/',13,6+i*6);
 put_number(MaxHP[i],4,14,4+i*6);
 put_number(MaxMP[i],4,14,6+i*6);
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
