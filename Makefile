#
# Makefile for HuC 7WizardS
#
CC = huc

CFLAGS = -v -scd -overlay
LIBS = -lst

SRC = rpg.c battle.c
OBJ = rpg.ovl battle.ovl
EXE = 7WizardS.iso

7WizardS.iso : 7WizardS.ovl rpg.ovl battle.ovl
	isolink 7WizardS.iso 7WizardS.ovl rpg.ovl battle.ovl

7WizardS.ovl : 7WizardS.c const.c var.c
	$(CC) $(CFLAGS) $(LIBS) 7WizardS.c

rpg.ovl : rpg.c move.c game.c const.c var.c map.c graph.c Merry.asm text.c silence.c util.c TestMelancholia.asm
	$(CC) $(CFLAGS) $(LIBS) rpg.c

battle.ovl : battle.c magic.c const.c var.c graphbattle.c TestFight.asm silence.c
	$(CC) $(CFLAGS) $(LIBS) battle.c

clean :
	rm -f *.s *.lst *.pce *.sym *.iso *.ovl *.asm core
  
TestMelancholia.asm : TestMelancholia.mod
	mod2mml -o $@ $<

# -d 11=4,12=3,13=1,15=2 -a -n -v 3=28,1=28 -f 3=.25

Merry.asm : Merry.mod
	mod2mml -o $@ $<
  
TestFight.asm : TestFight.mod
	mod2mml -o $@ $<

ackerlight.asm : ackerlight.mod
	mod2mml -d 11=4,12=3,13=1,15=2 -a -n -v 3=28,1=28 -f 3=.25 -o $@ $<
