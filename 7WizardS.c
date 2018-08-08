/********************************/
/*    Initialisation overlay    */
/********************************/


#include <huc.h>
#include <st.h>

#include "const.c"
#include "var.c"

main()
{
 g_gameState = 0;

 g_dexP[0]=50;
 g_atkP[0]=70;
 g_defP[0]=60;
 g_dexP[1]=70;
 g_atkP[1]=50;
 g_defP[1]=40;
 g_dexP[2]=30;
 g_atkP[2]=80;
 g_defP[2]=80;
 g_dexP[3]=60;
 g_atkP[3]=40;
 g_defP[3]=60;
 strcpy(g_nameP1,"Axel");
 strcpy(g_nameP2,"Yoko");
 strcpy(g_nameP3,"Choko");
 strcpy(g_nameP4,"Dina");
 g_maxHP[0]=LIFEMAX;
 g_maxMP[0]=MPMAX;
 g_maxHP[1]=2*LIFEMAX/3;
 g_maxMP[1]=3*MPMAX;
 g_maxHP[2]=2*LIFEMAX;
 g_maxMP[2]=MPMAX/3;
 g_maxHP[3]=LIFEMAX;
 g_maxMP[3]=2*MPMAX;
 g_activePlayer[0] = 1;
 g_activePlayer[1] = 0;
 g_activePlayer[2] = 1;
 g_activePlayer[3] = 1;
 set_screen_size(SCR_SIZE_32x32);
 
 st_init();

 g_firstTime=1;
 cd_execoverlay(OVL_RPG);

}
