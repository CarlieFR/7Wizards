/***********************************************/
/*           Create Border Function            */
/***********************************************/
border(x,y,i,j)
unsigned char x,y,i,j;
{
unsigned char a;

set_bgpal(0,screenpal);
load_sprites(0X1000,screengfx);
set_font_color(1,2);
load_default_font();

put_raw(0X100,x,y);
put_raw(0X102,x+i-1,y);
put_raw(0X106,x,y+j-1);
put_raw(0X108,x+i-1,y+j-1);
a=1;
while(a<i-1)
 {
  put_raw(0X101,x+a,y);
  put_raw(0X107,x+a,y+j-1);
  a++;
 }
a=1;
while(a<j-1)
 {
  put_raw(0X103,x,y+a);
  put_raw(0X105,x+i-1,y+a);
  a++;
 }
}
/***********************************************/
/*          Fill with blank Function           */
/***********************************************/
blank(x,y,i,j)
unsigned char x,y,i,j;
{
unsigned char a,b;
a=0;
while(a<i)
 {
  b=0;
  while(b<j)
  {
   put_char(' ',x+a,y+b);
   b++;
  }
  a++;
 }
}