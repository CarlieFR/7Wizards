/********************************/
/*    Header battle system      */
/********************************/

#include <huc.h>
#include <st.h>

#include "const.c"
#include "var.c"
#include "monsters.c"
#include "magic.c"
#include "silence.c"
#include "cadre.c"
#include "itemeffect.c"

/********************************/
#include "graphbattle.c"

#incasm("TestFight.asm")
extern struct st_header TestFight[];

/****************************************/
/*          Battle System               */
/****************************************/
main()
{
  unsigned int l_exp;
  RESIST_TYPE l_enemyres;
  STAT_TYPE l_dexN,l_defN,l_atkN;
  HP_TYPE l_life_init,l_oldHP[4],l_life_enemy, l_wound;
  char turn,continu,target,i,playing;

  l_life_init = (c_monsterLifeMax[g_monsterID]*3 + (rand() % c_monsterLifeMax[g_monsterID]))/4;
  l_exp = c_monsterExp[g_monsterID];
  l_enemyres = c_monsterRes[g_monsterID];
  l_atkN = c_monsterAtk[g_monsterID];
  l_defN = c_monsterDef[g_monsterID];
  l_dexN = c_monsterDex[g_monsterID];
  cls();
  graphbattle_init();

  /*silence();*/
  /*music4Init();*/
  st_set_song(bank(TestFight), TestFight);
  /*st_reset();*/
  st_reset();

  st_song_repeat_on();
  st_play_song();

  set_font_color(1,2);
  load_default_font();

  for(i=0;i<4;i++)
    l_oldHP[i]=g_hp[i];

  while(1)
  {

    satb_update();
    cls();
    set_font_color(1,2);
    load_default_font();
    graphbattle_battlescreen();
    cadre_border(10,22,22,6);

    for(i=0;i<4;i++)
      g_hp[i]=l_oldHP[i];
    l_life_enemy=l_life_init;
    continu=1;
    battle_roundInit(l_dexN);

    for(i=0;i<4;i++)
    {
      if (g_hp[i])
      {
        g_battleX[i]=200;
        g_battleY[i]=16+(i+1)*32;
        spr_set(FIGHT_CHAR_SPR+i);
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
        spr_x(g_battleX[i]);
        spr_y(g_battleY[i]);
        spr_show();
      }
    }

    spr_set(FIGHT_CHAR_SPR+4);
    spr_pri(1);
    spr_pattern(0X6000);
    spr_ctrl(FLIP_MAS | SIZE_MAS,NO_FLIP | SZ_32x32);
    spr_pal(SPRITEPAL);
    g_battleX[4]=40;
    g_battleY[4]=80;
    spr_x(g_battleX[4]);
    spr_y(g_battleY[4]);
    spr_show();

    while ((g_hp[0]>0) && (g_hp[1]>0) && (l_life_enemy>0))
    {
      graphbattle_fightframe(l_life_enemy,turn);
      turn=battle_selectNextTurn(l_dexN);
      satb_update();

      switch(turn)
      {
        /*    PLAYER 1    */
        case 0:

          battle_playerAction(g_nameP1, turn, &l_life_enemy,l_defN,l_dexN,l_enemyres);
          break;

          /*    PLAYER 2    */
        case 1:

          battle_playerAction(g_nameP2, turn, &l_life_enemy,l_defN,l_dexN,l_enemyres);
          break;

          /*    PLAYER 3    */
          /*  case 2:

          battle_playerAction(g_nameP3, turn, &l_life_enemy,l_defN,l_dexN,l_enemyres);

  /*    PLAYER 4    */
          /*  case 3:

          battle_playerAction(g_nameP4, turn, &l_life_enemy,l_defN,l_dexN,l_enemyres);

  /*      ENEMY 1      */
        case 4:
          spr_set(FIGHT_CHAR_SPR+4);
          cadre_blank(1,23,8,4);
          cadre_border(0,22,10,6);
          put_string("PUSH",3,23);
          put_string("START",3,25);

          while(!(joytrg(0) & JOY_STRT))
          {
            rand();
            vsync();
          }

          cadre_blank(1,1,30,1);
          put_string("Enemy attacks",3,1);

          target=rand()%2;
          while(g_hp[target]<1) target=rand()%2;

          for(i=0;i<5;i++) {spr_x(spr_get_x()+1); vsync(); satb_update();}
          for(i=0;i<5;i++) {spr_x(spr_get_x()-1); vsync(); satb_update();}
          l_wound=battle_fight(l_atkN,l_dexN,g_defP[target],g_dexP[target]);
          if (l_wound)
          {
            g_hp[target]-=l_wound;
            battle_showDamage(l_wound,200,(target+1)*32);
            if (g_hp[target]<0) g_hp[target]=0;
          }
          else {
            cadre_blank(1,1,30,1);
            satb_update();
            vsync(1);
            put_string("He missed     ",3,1);
          }
          break;
      }
      
      vsync(2);
    }
    
    /* Fight ended, all players or monsters dead */

    graphbattle_fightframe(l_life_enemy,4);
    for(i=0;i<4;i++) {
      put_number(g_hp[i],5,25,23+i);
    }
    /* For debug purpose only */
    put_number(l_life_enemy,5,25,21);

    silence();
    g_battleEnd=1;
    vsync(60);
    cadre_blank(1,1,30,1);

    if (!(battle_bonus(l_exp)))
    {
      for(i=0;i<5;i++)
      {
        spr_set(FIGHT_CHAR_SPR+i);
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
/*            Fight Sequence                 */
/*********************************************/
unsigned int battle_fight(p_atk1,p_dex1,p_defTarget,p_dexTarget)
STAT_TYPE p_atk1,p_dex1,p_defTarget,p_dexTarget;
{
  int l_hit,l_wound;
  unsigned int l_randResult;
  /* Using randResult to be sure to have a positive random result until better random doc is found */
  l_randResult = rand();
  l_hit = l_randResult % p_dex1;
  l_randResult = rand();
  l_hit += l_randResult % p_dex1;
  l_randResult = rand();
  l_hit -= l_randResult % p_dexTarget;
  /*hit=2*(rand() % Dex1) - (rand() % Dex2);*/
  if (l_hit<0)
    return 0;
  else
  {
    l_randResult = rand();
    l_wound = l_randResult % p_atk1;
    l_randResult = rand();
    l_wound += l_randResult % p_atk1;
    l_randResult = rand();
    l_wound -= l_randResult % p_defTarget;
    /*wound=2*(rand() % Atk1) - (rand() % Def2);*/
    if (l_wound<=0)
      return 1;
    else if (l_wound > 9999)
      return 9999;
    else
      return l_wound;
  }
}
/*********************************************/
/*           Battle Option selection         */
/*********************************************/
battle_select()
{
  unsigned char l_select;

  l_select=1;
  put_char('>',1,23);
  put_string("Fight",2,23);
  put_string("Magic",2,24);
  put_string("Special",2,25);
  put_string("Item",2,26);
  cadre_border(0,22,10,6);

  while(!(joytrg(0) & JOY_A))
  {
    if ((joytrg(0) & JOY_DOWN) && (l_select<4))
    {
      put_char(' ',1,22+l_select);
      l_select++;
      put_char('>',1,22+l_select);
    }
    if ((joytrg(0) & JOY_UP) && (l_select>1))
    {
      put_char(' ',1,22+l_select);
      l_select--;
      put_char('>',1,22+l_select);
    }
    vsync(1);
    rand();
  }
  
  /* Selection done */
  put_char(' ',1,22+l_select);
  cadre_blank(1,1,30,1);

  return l_select;
}
/*********************************************/
/*              Battle Magic                 */
/*********************************************/
battle_magic(p_player,p_enemyHP,p_enemyres)
char p_player;
int *p_enemyHP;
RESIST_TYPE p_enemyres;
{
  unsigned char l_select,i,j;
  unsigned int l_basePattern;

  cadre_blank(1,23,30,4);
  cadre_border(0,22,24,6);
  cadre_border(24,22,8,6);
  put_string("MP Use",25,24);
  l_select=0;
  put_char('>',1,23+l_select);
  vsync();

  for(i=0; i<8; i++)
  {
    spr_set(BARBASESPR+i);
    spr_hide();
  }
  satb_update();

  /* get base character pattern */
  switch (p_player)
  {
    case 0: /* Player 1 */
      l_basePattern = PLAYER1PTR;
      break;
    case 1:
      l_basePattern = PLAYER2PTR;
      break;
    case 2 :
      l_basePattern = PLAYER1PTR;
      break;
    case 3 :
      l_basePattern = PLAYER1PTR;
      break;
  }

  /* Put initial magic names */
  for(i=0;i<4;i++) {
    put_string(c_magicname[i],2,23+i);
  }
  
  while(!(joytrg(0) & (JOY_STRT | JOY_B)))
  {
    /*music_update();*/
    put_number(c_magicmp[l_select],2,27,25);
    if (joytrg(0))
    {
      if (joytrg(0) & JOY_A)
      {
        /* Character magic animation */
        spr_set(FIGHT_CHAR_SPR+p_player);
        for(i=0;i<6;i++)
        {
          if (i&0X1)
          {
            spr_pattern(l_basePattern+0x240);
            satb_update();
            /*for(j=0;j<5;j++)*/
            {
              vsync(5);
            }
          }
          else
          {
            spr_pattern(l_basePattern+0x280);
            satb_update();
            vsync(2);
          }
        }
   
        /* Magic graphical effect */
        switch(l_select)
        {
          case 0:
          {
            magic_fireballVisual(g_battleX[p_player],g_battleY[p_player],g_battleX[4],g_battleY[4]);
            break;
          }
          case 1:
          {
            magic_iceVisual(g_battleX[4],g_battleY[4]);
            break;
          }
          default:
          {
            magic_fireballVisual(g_battleX[p_player],g_battleY[p_player],g_battleX[4],g_battleY[4]);
            break;
          }
        }/*end switch*/

        (*p_enemyHP) -= magic_damage(p_player,l_select,p_enemyres);
        
        for(i=0; i<8; i++)
        {
          spr_set(BARBASESPR+i);
          spr_show();
        }
        satb_update();
        return;
      }
          
      if ((joytrg(0) & JOY_UP) && (l_select>0))
        l_select--;
      if ((joytrg(0) & JOY_DOWN) && (l_select<9))
        l_select++;
      cadre_blank(1,23,22,4);
      if (l_select<2)
      {
        put_char('>',1,23+l_select);
        for(i=0;i<4;i++) put_string(c_magicname[i],2,23+i);
      }
      else
      {
        if (l_select==9)
        {
          put_char('>',1,26);
          for(i=l_select-3;i<l_select+1;i++) put_string(c_magicname[i],2,26+i-l_select);
        }
        else
        {
          put_char('>',1,25);
          for(i=l_select-2;i<l_select+2;i++) put_string(c_magicname[i],2,25+i-l_select);
        }
      }
    }

    vsync();
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
battle_special(p_player)
char p_player;
{
  cadre_blank(1,23,30,4);
  cadre_border(0,22,32,6);
  vsync();
  while(!(joy(0)))
  {
    vsync();
  }
}
/*********************************************/
/*               Battle Item                 */
/*********************************************/
battle_item(p_player)
char p_player;
{
  char l_select,i;
  cadre_blank(1,23,30,4);
  cadre_border(0,22,20,6);
  cadre_border(20,22,12,6);
  vsync();
  l_select=0;
  put_string("Items left",21,24);
  put_char('>',1,23+l_select);

  for(i=0; i<8; i++)
  {
    spr_set(BARBASESPR+i);
    spr_hide();
  }
  satb_update();
  vsync();

  for(i=0;i<4;i++)
    put_string(c_item[i],2,23+i);

  while(!(joytrg(0) & (JOY_STRT|JOY_B)))
  {
    put_number(g_itemnb[l_select],2,25,25);
    if (joytrg(0))
    {
      if (joytrg(0) & JOY_A)
        if (g_itemnb[l_select]>0)
        {
          g_itemnb[l_select]--;
          battle_itemEffect(l_select,p_player);
          return 1;
        }
      if ((joytrg(0) & JOY_UP) && (l_select>0))
        l_select--;
      if ((joytrg(0) & JOY_DOWN) && (l_select<6))
        l_select++;
      cadre_blank(1,23,18,4);
      if (l_select<2)
      {
        put_char('>',1,23+l_select);
        for(i=0;i<4;i++) put_string(c_item[i],2,23+i);
      }
      else
      {
        if (l_select==6)
        {
          put_char('>',1,26);
          for(i=l_select-3;i<l_select+1;i++) put_string(c_item[i],2,26+i-l_select);
        }
        else
        {
          put_char('>',1,25);
          for(i=l_select-2;i<l_select+2;i++) put_string(c_item[i],2,25+i-l_select);
        }
      }
    }
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
battle_bonus(p_exp)
int p_exp;
{
  char i,l_continu;
  l_continu=1;

  if ((g_hp[0]>0) || (g_hp[1]>0))
  {
    put_string("You won",8,1);
    vsync(60);
    cadre_blank(1,1,30,1);
    put_string("Got",1,1);
    put_number(p_exp,5,5,1);
    put_string("experience point(s)",11,1);
    for(i=0;i<4;i++) g_expP[i]+=p_exp;
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
        if (l_continu)
        {
          l_continu--;
          put_char('N',8,13);
        }
        else
        {
          l_continu++;
          put_char('Y',8,13);
        }
      }
      vsync();
    }
    return l_continu;
  }
}

/************************************/
/*            Select Turn           */
/************************************/
battle_selectNextTurn(p_dexMonster)
STAT_TYPE p_dexMonster;
{
  char i;
  char l_next;

  l_next = 100;

  while(l_next==100)
  {
    for(i=0;i<4;i++)
    {
      if(g_hp[i]>0)
      {
        g_roundCount[i] += g_dexP[i];
        if(g_roundCount[i]>3520) l_next=i;
      }
      spr_set(BARBASESPR+(i<<1));
      if((g_roundCount[i]>>7)<14)
      {
        spr_pattern(ACTIONBARPTR+0x40*(g_roundCount[i]>>7));
      }
      else
      {
        spr_pattern(ACTIONBARPTR+0x340);
      }
      spr_set(BARBASESPR+(i<<1)+1);
      if((g_roundCount[i]>>7)<14)
      {
        spr_pattern(ACTIONBARPTR+0x380);
      }
      else
      {
        if(g_roundCount[i]<=3520)
        {
          spr_pattern(ACTIONBARPTR+0x380+0x40*((g_roundCount[i]>>7)-14));
        }
        else
        {
          spr_pattern(ACTIONBARPTR+0x380+0x340);
        }
      }
    }
    g_roundCount[4] += p_dexMonster;
    if(g_roundCount[4]>3520) l_next=4;

    /*music_update();*/
    satb_update();
    vsync();
  }
  g_roundCount[l_next]=0;

  return l_next;
}
/************************************/
/*            Round Init            */
/************************************/
battle_roundInit(p_dexMonster)
STAT_TYPE p_dexMonster;
{
  char i;

  for(i=0;i<4;i++)
  {
    g_roundCount[i] = rand() % g_dexP[i];
    spr_set(BARBASESPR+(i<<1));
    spr_pri(1);
    spr_ctrl(FLIP_MAS | SIZE_MAS,NO_FLIP | SZ_16x16);
    spr_pal(BARPAL);
    spr_x(152);
    spr_y(184+(i<<3));
    if((g_roundCount[i]>>7)<14)
    {
      spr_pattern(ACTIONBARPTR+0x40*(g_roundCount[i]>>7));
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
    if((g_roundCount[i]>>7)<14)
    {
      spr_pattern(ACTIONBARPTR+0x380);
    }
    else
    {
      if(g_roundCount[i]<=3520)
      {
        spr_pattern(ACTIONBARPTR+0x380+0x40*((g_roundCount[i]>>7)-14));
      }
      else
      {
        spr_pattern(ACTIONBARPTR+0x380+0x340);
      }

    }
  }
  g_roundCount[4] = rand() % p_dexMonster;

}
/*****************************************************/
/*             Player battle system                */
/*****************************************************/
battle_playerAction(p_name_player,p_player_id,p_life_enemy,p_defMonster,p_dexMonster,p_enemyres)
char* p_name_player;
char p_player_id;
STAT_TYPE p_defMonster,p_dexMonster;
RESIST_TYPE p_enemyres;
int *p_life_enemy;
{
  unsigned char l_move,i;
  unsigned int l_wound;
  int l_res;
  l_move=1;

  while(l_move)
  {
    graphbattle_fightframe((*p_life_enemy),p_player_id);
    spr_set(FIGHT_CHAR_SPR+p_player_id);
    switch(battle_select())
    {
      case 1:
        l_wound=battle_fight(g_atkP[p_player_id],g_dexP[p_player_id],p_defMonster,p_dexMonster);
        for(i=0;i<5;i++)
        {
          spr_x(spr_get_x()-1);
          satb_update();
          vsync();
        }
        for(i=0;i<5;i++)
        {
          spr_x(spr_get_x()+1);
          satb_update();
          vsync();
        }
        if (l_wound)
        {
          put_string(p_name_player,2,1);
          put_string("attacks",9,1);
          (*p_life_enemy)-=l_wound;
          battle_showDamage(l_wound,40,80);
        }
        else
        {
          put_string(p_name_player,2,1);
          put_string("missed",9,1);
        }

        l_move=0;
        break;

      case 2:

        l_res=*p_life_enemy;
        battle_magic(p_player_id,p_life_enemy,p_enemyres);
        if (!(l_res==(*p_life_enemy)))
        {
          put_string(p_name_player,1,1);
          put_string("used magic",8,1);
          battle_showDamage(l_res-(*p_life_enemy),40,80);
          l_move=0;
        }
        break;
      case 3:
        battle_special(p_player_id);
        break;
      case 4:
        if (battle_item(p_player_id))
          l_move=0;
        break;
    }
  }
}

/********************************************/
/*        Graphique damage function         */
/********************************************/
battle_showDamage(p_numbers,x,y)
int p_numbers;
char x,y;
{
  unsigned char i,j,max;

  for(i=0;i<4;i++)
  {
    spr_set(10+i);
    spr_show();
    spr_pri(1);
    spr_ctrl(FLIP_MAS | SIZE_MAS,NO_FLIP | SZ_16x16);
    spr_pal(NUMPAL);
  }

  if (p_numbers<0)
  {
    set_color(256+16*NUMPAL+1,0171);
    p_numbers=-p_numbers;
  }
  else
  {
    set_color(256+16*NUMPAL+1,0777);
  }
  max=4;

  /* compute how many digits to show */
  if (p_numbers<1000)
  {
    spr_set(10);
    spr_hide();
    max=3;
    if (p_numbers<100)
    {
      spr_set(11);
      spr_hide();
      max=2;
      if (p_numbers<10)
      {
        spr_set(12);
        spr_hide();
        max=1;
      }
    }
  }

  /* init sprites with digit values */
  for(i=0;i<max;i++)
  {
    spr_set(13-i);
    spr_x(x+10-9*i);
    spr_y(y);
    spr_pattern(0x5500+0x40*(p_numbers%10));
    p_numbers/=10;
  }


  /* number go up */
  for(j=0;j<4;j++)
  {
    for(i=0;i<max;i++)
    {
      spr_set(13-i);
      spr_y(spr_get_y()-1);
      satb_update();
      vsync();
    }
  }

  /* number go down */
  for(j=0;j<10;j++)
  {
    for(i=0;i<max;i++)
    {
      spr_set(13-i);
      spr_y(spr_get_y()+1);
      satb_update();
      vsync();
    }
  }

  /*for(i=0;i<30;i++)
  {*/
  /* wait half a second to show number */
    vsync(30);
  /*}*/
  /* hide number */
  for(i=0;i<4;i++)
  {
    spr_set(10+i);
    spr_hide();
  }
  satb_update();

}

/*************************************/
/*       Battle item effect          */
/*************************************/
battle_itemEffect(item,target)
char item,target;
{
  /* TODO : add visuel effect */
  itemeffect_baseEffect(item,target);
}
