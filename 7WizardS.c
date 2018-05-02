/********************************/
/*    Initialisation overlay    */
/********************************/


#include <huc.h>
#include "var.c"
#include "const.c"

main()
{
 gameState = 0;

 DexP[0]=50;
 AtkP[0]=70;
 DefP[0]=60;
 DexP[1]=70;
 AtkP[1]=50;
 DefP[1]=40;
 DexP[2]=50;
 AtkP[2]=70;
 DefP[2]=60;
 DexP[3]=70;
 AtkP[3]=50;
 DefP[3]=40;
 strcpy(NamP1,"Willy");
 strcpy(NamP2,"Yoko");
 strcpy(NamP3,"Sonny");
 strcpy(NamP4,"Gramps");
 MaxHP[0]=LIFEMAX;
 MaxMP[0]=MPMAX;
 MaxHP[1]=2*LIFEMAX/3;
 MaxMP[1]=3*MPMAX;
 MaxHP[2]=LIFEMAX;
 MaxMP[2]=MPMAX;
 MaxHP[3]=LIFEMAX;
 MaxMP[3]=MPMAX;
 set_screen_size(SCR_SIZE_32x32);

 FirstTime=1;
 cd_execoverlay(OVL_RPG);

}
