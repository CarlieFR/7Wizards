/********************************/
/*    Header prog principal     */
/********************************/


#include <huc.h>
#include <st.h>

#include "const.c"
#include "var.c"
#include "text.c"
#include "silence.c"

#incasm("TestMelancholia.asm")
extern struct st_header TestMelancholia[];

#include "graph.c"

/**************************************/
/*        MAIN         PROG           */
/**************************************/

main()
{
  char l_select;

  if(g_gameState==0)
  {
    /* Launch of the game, initialisation and main menu */
    cls();
    set_font_color(1,2);
    load_default_font();

    g_first_time_map4 = 1;

   /* while(1)*/
    {
      g_hp[0]=g_maxHP[0];
      g_hp[1]=g_maxHP[1];
      g_hp[2]=0;
      g_hp[3]=0;
      g_itemnb[0]=5;
      g_itemnb[1]=2;
      g_mp[0]=g_maxMP[0];
      g_mp[1]=g_maxMP[1];
      g_expP[0]=10;
      g_expP[1]=10;
      l_select=0;
      /* Music initialisation*/
      st_set_song(bank(TestMelancholia), TestMelancholia);

      st_reset();

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

      st_song_repeat_on();
      st_play_song();

      while (!(joytrg(0) & (JOY_STRT | JOY_A | JOY_B)))
      {
        if ((joytrg(0) & JOY_UP) && (l_select>0))
        {
          l_select--;
          put_char(' ',9,20+2*l_select);
          put_char('-',9,18+2*l_select);
        }
        if ((joytrg(0) & JOY_DOWN) && (l_select<2))
        {
          l_select++;
          put_char(' ',9,16+2*l_select);
          put_char('-',9,18+2*l_select);
        }
        vsync(1);
      }

      silence();

      switch (l_select)
      {
        case 2:
          g_monsterID=0;
          cd_execoverlay(OVL_BATTLE);
          break;

        case 1:
          rpg_changeName(g_nameP1);
          rpg_changeName(g_nameP2);
          rpg_changeName(g_nameP3);
          rpg_changeName(g_nameP4);
          break;

        case 0:
          g_battleEnd=1;
          game();
          break;
      }
    }
  } else {
    /* if coming back from a battle, directly go to the game mode */
    game();
  }

}

/*******************************************/
/*               Name Change               */
/*******************************************/
rpg_changeName(p_name)
char* p_name;
{
  char i,j,k;
  char l_entry[7];
  
  strcpy(l_entry,p_name);
  
  cls();
  cadre_border(0,0,32,28);
  cadre_border(11,10,8,3);

  put_string("Enter player name",7,4);
  cadre_border(6,3,19,3);

  cadre_border(2,20,28,6);
  for(i='A';i<'Z'+1;i++)
  {
    put_char(i,3+i-'A',21);
    put_char(i-'A'+'a',3+i-'A',23);
  }

  i=0;
  j=0;
  k=0;
  l_entry[6]=0;
  put_char('^',12+k,13);

  while (!(joytrg(0) & JOY_STRT))
  {
    if ((joytrg(0) & JOY_RGHT) && (i<25)) {
      i++;
    } else if ((joytrg(0) & JOY_LEFT) && (i>0)) {
      i--;
    }

    if ((joytrg(0) & JOY_B) && (k>0))
    {
      l_entry[k]=0;
      put_char(' ',12+k,13);
      k--;
      put_char('^',12+k,13);
    }

    if (joytrg(0) & JOY_A) {
      l_entry[k]=i+'A'+j*('a'-'A');
      if (k<5) {
        put_char(' ',12+k,13);
        k++;
        put_char('^',12+k,13);
      }
    }
    if ((joytrg(0) & JOY_UP) && (j>0)) {
      j--;
    } else if ((joytrg(0) & JOY_DOWN) && (j<1)) {
      j++;
    }

  
    put_string("      ",12,11);
    put_string(l_entry,12,11);
    cadre_blank(3,22,26,1);
    cadre_blank(3,24,26,1);
    put_char('^',3+i,22+2*j);
    vsync(1);
  }

  strcpy(p_name, l_entry);
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
