/****************************************/
/*            Item effect               */
/****************************************/
itemeffect(item,target)
char item,target;
{

switch(item)
  {
   case 0:
    HPp[target]+=50;
    if (HPp[target]>MaxHP[target]) HPp[target]=MaxHP[target];
    break;

   case 1:
    HPp[target]+=250;
    if (HPp[target]>MaxHP[target]) HPp[target]=MaxHP[target];
    break;
  }
}