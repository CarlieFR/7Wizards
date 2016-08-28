#
# Makefile for HuC 7WizardS
#
CC = huc

CFLAGS = -v -scd -overlay

SRC = rpg.c battle.c
OBJ = rpg.ovl battle.ovl
EXE = 7WizardS.iso

7WizardS.iso : 7WizardS.ovl rpg.ovl battle.ovl
	isolink 7WizardS.iso 7WizardS.ovl rpg.ovl battle.ovl

7WizardS.ovl : 7WizardS.c
	$(CC) $(CFLAGS) 7WizardS.c

rpg.ovl : rpg.c move.c game.c const.c var.c map.c graph.c
	$(CC) $(CFLAGS) rpg.c

battle.ovl : battle.c magic.c const.c var.c graphbattle.c
	$(CC) $(CFLAGS) battle.c

clean :
	rm -f *.s *.lst *.pce *.sym *.iso *.ovl core


