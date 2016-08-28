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
  Tile_WaterSky, Tile_WaterSky, Tile_WaterSky, Tile_WaterSky, Tile_WaterSky, Tile_WaterSky, Tile_WaterSky, Tile_WaterSky,
     Tile_WaterSky, Tile_WaterSky, Tile_WaterSky, Tile_WaterSky, Tile_WaterSky, Tile_WaterSky, Tile_WaterSky, Tile_WaterSky,
  Tile_WaterSky, Tile_WaterSky, Tile_WaterSky, Tile_WaterSky, Tile_WaterSky, Tile_WaterSky, Tile_WaterSky, Tile_WaterSky,
     Tile_WaterSky, Tile_WaterSky, Tile_WaterSky, Tile_WaterSky, Tile_WaterSky, Tile_WaterSky, Tile_WaterSky, Tile_WaterSky,
  Tile_WaterSky, Tile_WaterSky, Tile_WaterSky, Tile_WaterSky, Tile_WaterSky, Tile_WaterSky, Tile_WaterSky, Tile_WaterSky,
     Tile_WaterSky, Tile_WaterSky, Tile_WaterSky, Tile_WaterSky, Tile_WaterSky, Tile_WaterSky, Tile_WaterSky, Tile_WaterSky,
  Tile_Plain, Tile_Plain, Tile_Plain, Tile_Plain, Tile_Plain, Tile_Plain, Tile_Plain, Tile_Plain,
     Tile_Plain, Tile_PlainPuddle, Tile_Plain, Tile_Plain, Tile_Plain, Tile_Plain, Tile_Plain, Tile_Plain,
  Tile_Plain, Tile_Plain, Tile_Plain, Tile_Plain, Tile_PlainTrunk, Tile_Plain, Tile_Plain, Tile_Plain,
     Tile_Plain, Tile_Plain, Tile_Plain, Tile_Plain, Tile_Plain, Tile_Plain, Tile_Plain, Tile_Plain,
  Tile_Plain, Tile_Plain, Tile_Plain, Tile_Plain, Tile_Plain, Tile_Plain, Tile_Plain, Tile_Plain,
     Tile_Plain, Tile_Plain, Tile_Plain, Tile_Plain, Tile_Plain, Tile_Plain, Tile_Plain, Tile_Plain,
  Tile_Plain, Tile_Plain, Tile_Plain, Tile_Plain, Tile_Plain, Tile_Plain, Tile_Plain, Tile_Plain,
     Tile_Plain, Tile_Plain, Tile_Plain, Tile_PlainPuddle, Tile_Plain, Tile_Plain, Tile_Plain, Tile_Plain,
  Tile_Plain, Tile_Plain, Tile_Plain, Tile_Plain, Tile_Plain, Tile_Plain, Tile_Plain, Tile_Plain,
     Tile_Plain, Tile_Plain, Tile_Plain, Tile_Plain, Tile_Plain, Tile_Plain, Tile_Plain, Tile_Plain,
  Tile_Plain, Tile_Plain, Tile_Plain, Tile_Plain, Tile_Plain, Tile_Plain, Tile_Plain, Tile_Plain,
     Tile_Plain, Tile_Plain, Tile_Plain, Tile_Plain, Tile_Plain, Tile_Plain, Tile_Plain, Tile_Plain,
  Tile_Plain, Tile_Plain, Tile_Plain, Tile_Plain, Tile_Plain, Tile_Plain, Tile_Plain, Tile_Plain,
     Tile_PlainPuddle, Tile_Plain, Tile_Plain, Tile_Plain, Tile_Plain, Tile_Plain, Tile_Plain, Tile_Plain,
  Tile_Plain, Tile_Plain, Tile_Plain, Tile_Plain, Tile_Plain, Tile_Plain, Tile_Plain, Tile_Plain,
     Tile_Plain, Tile_Plain, Tile_Plain, Tile_Plain, Tile_Plain, Tile_Plain, Tile_Plain, Tile_Plain};

init_graph() {
  char i;
  
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
fightframe(life_enemy,turn)
int life_enemy,turn;
{
char i;

 blank(1,23,30,4);
 border(10,22,22,6);
 put_string(NamP1,12,23);
 put_string(NamP2,12,24);
 put_string(NamP3,12,25);
 put_string(NamP4,12,26);
 put_string("Enemy",12,21);
 for(i=0;i<4;i++)
 {
   put_number(HPp[i],5,25,23+i);
   /*spr_set(BARBASESPR+2*i);
   spr_show();
   spr_set(BARBASESPR+2*i+1);
   spr_show();*/
 }
 put_number(life_enemy,5,25,21);
 blank(11,23,1,4);
 if (turn<4) put_char('>',11,23+turn);
}

/*********************************************/
/*         Battle Background Display         */
/*********************************************/
battlescreen()
{
  cls();
  
  switch(battle_bg) {
    case PLAIN_BG :
      set_map_data(plain_bg, 16,11);
      break;
    default :
      set_map_data(plain_bg, 16,11);
      break;
  }

  load_map(0,0, 0,0, 16,11);
 
  blank(1,1,30,1);

  border(0,0,32,3);
}