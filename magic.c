Magiceffect(player,spell,enemyHP,target,enemyres)
char player,spell,target;
int *enemyHP,enemyres;
{/*magic effect*/
int factor;
factor=0;

 if (MPp[player]>=magicmp[spell])
 {/*if*/
   switch(magicelement[spell])
   {/*switch*/
    case 0:
     {/*case 0*/
	factor=-2;
	break;
     }
    case 0xf:
     {/*case 0xf*/
       if(enemyres & FIRE_STRONG)
	{
	  factor=-1;
	}
	else
	{
	  if(enemyres & FIRE_WEAK)
           {
 	     factor=-4;
           }
	  else
	  {
	    if(enemyres & FIRE_ABSORB)
	     {
	       factor=1;
	     }
	    else
	     {
	       if(!(enemyres & FIRE_NULL))
	        {
	         factor=-2;
 	 	}
	     }
	  }
	}
	break;
      }
    case 0xf0:
     {
       if(enemyres&ICE_STRONG)
	{
	  factor=-1;
	}
	else
	{
	  if(enemyres&ICE_WEAK)
           {
 	     factor=-4;
           }
	  else
	  {
	    if(enemyres&ICE_ABSORB)
	     {
	       factor=1;
	     }
	    else
	     {
	       if(!(enemyres&ICE_NULL))
	        {
	         factor=-2;
 	 	}
	     }
	  }
	}
	break;
      }
    case 0xf00:
     {
       if(enemyres&AIR_STRONG)
	{
	  factor=-1;
	}
	else
	{
	  if(enemyres&AIR_WEAK)
           {
 	     factor=-4;
           }
	  else
	  {
	    if(enemyres&AIR_ABSORB)
	     {
	       factor=1;
	     }
	    else
	     {
	       if(!(enemyres&AIR_NULL))
	        {
	         factor=-2;
 	 	}
	     }
	  }
	}
	break;
      }
    case 0xf000:
     {
       if(enemyres&EARTH_STRONG)
	{
	  factor=-1;
	}
	else
	{
	  if(enemyres&EARTH_WEAK)
           {
 	     factor=-4;
           }
	  else
	  {
	    if(enemyres&EARTH_ABSORB)
	     {
	       factor=1;
	     }
	    else
	     {
	       if(!(enemyres&EARTH_NULL))
	        {
	         factor=-2;
 	 	}
	     }
	  }
	}
	break;
      } /*end case*/
      default :
      {
	factor=-2;
	put_string("erreur",5,0);
	break;
      }
    }/*end switch*/
  (*enemyHP)+=factor*magicmp[spell]*MaxMP[player]/4;
  MPp[player]-=magicmp[spell];
 }/*end if*/

}/*end magic effect*/

Fireball(Xa,Ya,Xb,Yb)
int Xa,Ya,Xb,Yb;
{
int i,compteur;

 compteur=0;
 spr_set(MAGICSPR);
 spr_pal(FIRE_MAGICPAL);
 spr_pattern(FIREMAGICPTR);
 spr_ctrl(FLIP_MAS | SIZE_MAS,FLIP_X | SZ_16x16);
 spr_show();
 if (Xa>Xb)
  {
    for(i=Xa;i>Xb;i=i-2)
       {
         spr_x(i);
         spr_y(Ya-((Ya-Yb)*(Xa-i))/(Xa-Xb));
	 spr_pattern(FIREMAGICPTR+compteur/2*0x40);
	 compteur++;
	 if (compteur==6) compteur=0;
	 music_update();
         satb_update();
         vsync();
       }
  }
 else
  {
    for(i=Xa;i<Xb;i=i+2)
       {
         spr_x(i);
         spr_y(Ya-((Ya-Yb)*(i-Xa))/(Xb-Xa));
	 spr_pattern(FIREMAGICPTR+compteur/2*0x40);
	 compteur++;
	 if (compteur==6) compteur=0;
	 music_update();
         satb_update();
         vsync();
       }
  }
 spr_hide();

}

Icefall(X,Y)
int X,Y;
{
int i;

  spr_set(MAGICSPR);
  spr_show();
  spr_x(X);
  spr_ctrl(FLIP_MAS | SIZE_MAS,NO_FLIP | SZ_16x16);
  spr_pattern(ICEMAGICPTR);
  spr_pal(ICE_MAGICPAL);
  for(i=28;i<Y-8;i+=2)
   {
    spr_y(i);
    music_update();
    satb_update();
    vsync();
   }
  spr_pattern(ICEMAGICPTR+0x40);
  for(i=Y-8;i<Y-4;i++)
   {
    spr_y(i);
    music_update();
    satb_update();
    vsync();
   }
  spr_pattern(ICEMAGICPTR+0x80);
  for(i=Y-4;i>Y;i++)
   {
    spr_y(i);
    music_update();
    satb_update();
    vsync();
   }
  spr_pattern(ICEMAGICPTR+0xC0);
  spr_y(Y);
  for(i=0;i<11;i++)
  {
   if((i/2)&1)
     spr_hide();
   else
     spr_show();
   music_update();
   satb_update();
   vsync();
  }
 spr_hide();
 satb_update();
}
