#incchr(screengfx,SCREEN,3,3);
#incpal(screenpal,SCREEN,0,1);

#inctile(tilesgfx,TILES);
#incpal(tilespal,TILES);

#incspr(sprgfx,SPRITE,2,2);
#incpal(spritepal,SPRITE,0,1);

#incspr(p1gfx,PERSO1PCX,3,4);
#incpal(p1pal,PERSO1PCX,0,1);

#incspr(p2gfx,PERSO2PCX,3,4);
#incpal(p2pal,PERSO2PCX,0,1);

#incspr(numgfx,NUMBERS,10,1);
#incpal(numpal,NUMBERS,0,1);

#incspr(bargfx,BAR,1,28);
#incpal(barpal,BAR,0,1);

#incspr(fire_magicgfx,FIRE_MAGIC,2,2);
#incpal(fire_magicpal,FIRE_MAGIC,0,1);

#incspr(ice_magicgfx,ICE_MAGIC,2,2);
#incpal(ice_magicpal,ICE_MAGIC,0,1);

const char plain_bg[] = {
  T_WaterSky, T_WaterSky, T_WaterSky, T_WaterSky, T_WaterSky, T_WaterSky, T_WaterSky, T_WaterSky,
     T_WaterSky, T_WaterSky, T_WaterSky, T_WaterSky, T_WaterSky, T_WaterSky, T_WaterSky, T_WaterSky,
  T_WaterSky, T_WaterSky, T_WaterSky, T_WaterSky, T_WaterSky, T_WaterSky, T_WaterSky, T_WaterSky,
     T_WaterSky, T_WaterSky, T_WaterSky, T_WaterSky, T_WaterSky, T_WaterSky, T_WaterSky, T_WaterSky,
  T_WaterSky, T_WaterSky, T_WaterSky, T_WaterSky, T_WaterSky, T_WaterSky, T_WaterSky, T_WaterSky,
     T_WaterSky, T_WaterSky, T_WaterSky, T_WaterSky, T_WaterSky, T_WaterSky, T_WaterSky, T_WaterSky,
  T_Plain, T_Plain, T_Plain, T_Plain, T_Plain, T_Plain, T_Plain, T_Plain,
     T_Plain, T_PlainPuddle, T_Plain, T_Plain, T_Plain, T_Plain, T_Plain, T_Plain,
  T_Plain, T_Plain, T_Plain, T_Plain, T_PlainTrunk, T_Plain, T_Plain, T_Plain,
     T_Plain, T_Plain, T_Plain, T_Plain, T_Plain, T_Plain, T_Plain, T_Plain,
  T_Plain, T_Plain, T_Plain, T_Plain, T_Plain, T_Plain, T_Plain, T_Plain,
     T_Plain, T_Plain, T_Plain, T_Plain, T_Plain, T_Plain, T_Plain, T_Plain,
  T_Plain, T_Plain, T_Plain, T_Plain, T_Plain, T_Plain, T_Plain, T_Plain,
     T_Plain, T_Plain, T_Plain, T_PlainPuddle, T_Plain, T_Plain, T_Plain, T_Plain,
  T_Plain, T_Plain, T_Plain, T_Plain, T_Plain, T_Plain, T_Plain, T_Plain,
     T_Plain, T_Plain, T_Plain, T_Plain, T_Plain, T_Plain, T_Plain, T_Plain,
  T_Plain, T_Plain, T_Plain, T_Plain, T_Plain, T_Plain, T_Plain, T_Plain,
     T_Plain, T_Plain, T_Plain, T_Plain, T_Plain, T_Plain, T_Plain, T_Plain,
  T_Plain, T_Plain, T_Plain, T_Plain, T_Plain, T_Plain, T_Plain, T_Plain,
     T_PlainPuddle, T_Plain, T_Plain, T_Plain, T_Plain, T_Plain, T_Plain, T_Plain,
  T_Plain, T_Plain, T_Plain, T_Plain, T_Plain, T_Plain, T_Plain, T_Plain,
     T_Plain, T_Plain, T_Plain, T_Plain, T_Plain, T_Plain, T_Plain, T_Plain};

graphbattle_init() {
  unsigned char i;
  
  set_screen_size(SCR_SIZE_32x32);
  
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
}

/*********************************************/
/*           Fight low frame                 */
/*********************************************/
graphbattle_fightframe(p_life_enemy, p_turn)
int p_life_enemy;
char p_turn;
{
  char i;

  cadre_blank(1,23,30,4);
  cadre_border(10,22,22,6);
  
  if (g_activePlayer[0]) {
    put_string(g_nameP1,12,23);
  }
  if (g_activePlayer[1]) {
    put_string(g_nameP2,12,24);
  }
  if (g_activePlayer[2]) {
    put_string(g_nameP3,12,25);
  }
  if (g_activePlayer[3]) {
    put_string(g_nameP4,12,26);
  }
  if (DEBUG) {
    put_string("Enemy",12,21);
  }
  
  for(i=0;i<4;i++) {
    if (g_activePlayer[i]) {
      put_number(g_hp[i],5,25,23+i);
    }
  }
  if (DEBUG) {
    put_number(p_life_enemy,5,25,21);
  }
  cadre_blank(11,23,1,4);
  if (p_turn<4) {
    put_char('>',11,23+p_turn);
  }
}

/*********************************************/
/*         Battle Background Display         */
/*********************************************/
graphbattle_battlescreen()
{
  cls();
  
  switch(g_battle_bg) {
    case PLAIN_BG :
      set_map_data(plain_bg, 16,11);
      break;
    default :
      set_map_data(plain_bg, 16,11);
      break;
  }

  load_map(0,0, 0,0, 16,11);
 
  cadre_blank(1,1,30,1);
  cadre_border(0,0,32,3);
}