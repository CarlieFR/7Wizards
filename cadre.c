/***********************************************/
/*           Create Border Function            */
/***********************************************/
cadre_border(p_x,p_y,p_nbRows,p_nbLines)
unsigned char p_x,p_y,p_nbRows,p_nbLines;
{
  unsigned char l_index;

  set_bgpal(0,screenpal);
  load_sprites(0X1000,screengfx);
  set_font_color(1,2);
  load_default_font();

  /* Draw the 4 corners */
  put_raw(0X100,p_x,p_y);
  put_raw(0X102,p_x+p_nbRows-1,p_y);
  put_raw(0X106,p_x,p_y+p_nbLines-1);
  put_raw(0X108,p_x+p_nbRows-1,p_y+p_nbLines-1);

  /* Draw top and bottom lines */
  l_index=1;
  while(l_index<p_nbRows-1)
   {
    put_raw(0X101,p_x+l_index,p_y);
    put_raw(0X107,p_x+l_index,p_y+p_nbLines-1);
    l_index++;
   }
   
  /* Draw left and right lines */
  l_index=1;
  while(l_index<p_nbLines-1)
   {
    put_raw(0X103,p_x,p_y+l_index);
    put_raw(0X105,p_x+p_nbRows-1,p_y+l_index);
    l_index++;
  }
}
/***********************************************/
/*          Fill with blank Function           */
/***********************************************/
cadre_blank(p_x,p_y,p_nbRows,p_nbLines)
unsigned char p_x,p_y,p_nbRows,p_nbLines;
{
  unsigned char l_rowIndex,l_lineIndex;
  
  l_rowIndex=0;
  while(l_rowIndex<p_nbRows)
  {
    l_lineIndex=0;
    while(l_lineIndex<p_nbLines)
    {
      put_char(' ',p_x+l_rowIndex,p_y+l_lineIndex);
      l_lineIndex++;
    }
    l_rowIndex++;
  }
}