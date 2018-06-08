
silence()
{
  st_stop_song();
  st_reset();
  irq_disable_user(IRQ_VSYNC);

  
  currentMusic = 0;
}