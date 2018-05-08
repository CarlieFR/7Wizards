
silence()
{
  st_stop_song();
  irq_disable_user(IRQ_VSYNC);

  
  currentMusic = 0;
}