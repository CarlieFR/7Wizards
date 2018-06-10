/****************************************/
/*            Item effect               */
/****************************************/
itemeffect(item,target)
char item,target;
{

switch(item)
  {
   case 0:
    g_hp[target]+=50;
    if (g_hp[target]>g_maxHP[target]) g_hp[target]=g_maxHP[target];
    break;

   case 1:
    g_hp[target]+=250;
    if (g_hp[target]>g_maxHP[target]) g_hp[target]=g_maxHP[target];
    break;
  }
}