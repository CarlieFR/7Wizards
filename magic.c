int magic_damage(p_player,p_spellNumber,p_enemyResist)
unsigned char p_player,p_spellNumber;
unsigned int p_enemyResist;
{
  /*magic effect*/
  int l_factor;
  unsigned char l_nbFactors;
  l_factor = 0;
  l_nbFactors = 0;

  if (g_mp[p_player]>=c_magicmp[p_spellNumber])
  {
    if (c_magicelement[p_spellNumber] & FIRE_MASK) {
      /* Fire element */
      if (p_enemyResist & FIRE_STRONG) {
        l_factor += 1;
      } else if (p_enemyResist & FIRE_WEAK) {
        l_factor += 4;
      } else if (p_enemyResist & FIRE_ABSORB) {
        l_factor -= 1;
      } else if (p_enemyResist & FIRE_NULL) {
        /* no increase, resisting damage */
      } else {
        l_factor += 2;
      }
      l_nbFactors++;
    }
    
    if (c_magicelement[p_spellNumber] & ICE_MASK) {
      /* Ice element */
      if (p_enemyResist & ICE_STRONG) {
        l_factor += 1;
      } else if (p_enemyResist & ICE_WEAK) {
        l_factor += 4;
      } else if (p_enemyResist & ICE_ABSORB) {
        l_factor -= 1;
      } else if (p_enemyResist & ICE_NULL) {
        /* no increase, resisting damage */
      } else {
        l_factor += 2;
      }
      l_nbFactors++;
    }
    
    if (c_magicelement[p_spellNumber] & AIR_MASK) {
      /* Air element */
      if (p_enemyResist & AIR_STRONG) {
        l_factor += 1;
      } else if (p_enemyResist & AIR_WEAK) {
        l_factor += 4;
      } else if (p_enemyResist & AIR_ABSORB) {
        l_factor -= 1;
      } else if (p_enemyResist & AIR_NULL) {
        /* no increase, resisting damage */
      } else {
        l_factor += 2;
      }
      l_nbFactors++;
    }
    
    if (c_magicelement[p_spellNumber] & EARTH_MASK) {
      /* Earth element */
      if (p_enemyResist & EARTH_STRONG) {
        l_factor += 1;
      } else if (p_enemyResist & EARTH_WEAK) {
        l_factor += 4;
      } else if (p_enemyResist & EARTH_ABSORB) {
        l_factor -= 1;
      } else if (p_enemyResist & EARTH_NULL) {
        /* no increase, resisting damage */
      } else {
        l_factor += 2;
      }
      l_nbFactors++;
    }
    
    /* In case no element match, use standard factor */
    if (l_nbFactors == 0) {
      l_factor = 2;
      l_nbFactors++;
    }
    
    g_mp[p_player]-=c_magicmp[p_spellNumber];
    return (l_factor*c_magicmp[p_spellNumber]*g_maxMP[p_player]/l_nbFactors)/4;
    
  }/*end if*/

}/*end magic effect*/

/************************************************************/
/** Visual effect of a fireball going from caster to target */
/************************************************************/
magic_fireballVisual(p_xBegin, p_yBegin, p_xEnd, p_yEnd)
int p_xBegin, p_yBegin, p_xEnd, p_yEnd;
{
  int i,l_compteur;

  l_compteur=0;
  spr_set(MAGICSPR);
  spr_pal(FIRE_MAGICPAL);
  spr_pattern(FIREMAGICPTR);
  /* TODO manage fireball going from left to right */
  spr_ctrl(FLIP_MAS | SIZE_MAS,FLIP_X | SZ_16x16);
  spr_show();
  if (p_xBegin>p_xEnd)
  {
    for(i=p_xBegin;i>p_xEnd;i=i-2)
    {
      spr_x(i);
      spr_y(p_yBegin-((p_yBegin-p_yEnd)*(p_xBegin-i))/(p_xBegin-p_xEnd));
      spr_pattern(FIREMAGICPTR+l_compteur/2*0x40);
      l_compteur++;
      if (l_compteur==6) {
        l_compteur=0;
      }
      satb_update();
      vsync();
    }
  }
  else
  {
    for(i=p_xBegin;i<p_xEnd;i=i+2)
    {
      spr_x(i);
      spr_y(p_yBegin-((p_yBegin-p_yEnd)*(i-p_xBegin))/(p_xEnd-p_xBegin));
      spr_pattern(FIREMAGICPTR+l_compteur/2*0x40);
      l_compteur++;
      if (l_compteur==6) {
        l_compteur=0;
      }
      satb_update();
      vsync();
    }
  }
  spr_hide();

}

/*********************************************/
/** Visual effect of ice falling onto target */
/*********************************************/
magic_iceVisual(p_xTarget, p_yTarget)
int p_xTarget, p_yTarget;
{
  int i;

  spr_set(MAGICSPR);
  spr_show();
  spr_x(p_xTarget);
  spr_ctrl(FLIP_MAS | SIZE_MAS,NO_FLIP | SZ_16x16);
  spr_pattern(ICEMAGICPTR);
  spr_pal(ICE_MAGICPAL);
  for(i=28; i<p_yTarget-8; i+=2)
  {
    spr_y(i);
    satb_update();
    vsync();
  }
  
  spr_pattern(ICEMAGICPTR+0x40);
  for(i=p_yTarget-8; i<p_yTarget-4; i++)
  {
    spr_y(i);
    satb_update();
    vsync();
  }
  
  spr_pattern(ICEMAGICPTR+0x80);
  for(i=p_yTarget-4; i<p_yTarget; i++)
  {
    spr_y(i);
    satb_update();
    vsync();
  }
  
  spr_pattern(ICEMAGICPTR+0xC0);
  spr_y(p_yTarget);
  for(i=0;i<11;i++)
  {
    if((i/2)&1)
      spr_hide();
    else
      spr_show();
    satb_update();
    vsync();
  }
  
  spr_hide();
  satb_update();
}
