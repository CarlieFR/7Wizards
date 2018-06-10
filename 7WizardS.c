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
 g_dexP[2]=50;
 g_atkP[2]=70;
 g_defP[2]=60;
 g_dexP[3]=70;
 g_atkP[3]=50;
 g_defP[3]=40;
 strcpy(g_nameP1,"Willy");
 strcpy(g_nameP2,"Yoko");
 strcpy(g_nameP3,"Sonny");
 strcpy(g_nameP4,"Gramps");
 g_maxHP[0]=LIFEMAX;
 g_maxMP[0]=MPMAX;
 g_maxHP[1]=2*LIFEMAX/3;
 g_maxMP[1]=3*MPMAX;
 g_maxHP[2]=LIFEMAX;
 g_maxMP[2]=MPMAX;
 g_maxHP[3]=LIFEMAX;
 g_maxMP[3]=MPMAX;
 set_screen_size(SCR_SIZE_32x32);
 
 st_init();

 g_firstTime=1;
 cd_execoverlay(OVL_RPG);

}
