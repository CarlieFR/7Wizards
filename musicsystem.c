/*

  music.c interface:
	initmusic() // call before any other music calls

   //channel initialization (channel 0-5 available)
	initchannelsquare(channel_number) //buzzy, good for bass
	initchannelsaw(channel_number)  //buzzy, good for lead
	initchannelsine(channel_number)  //soft, good for pads  
	initchannelnoise(channel_number)  //noise, good for drums
   
   //call every 16th note to update playhead  	
	playmusic()
*/

/*#define Mus_Length 558*/ /*time index of last note - 4*beat*/

/*#define Mus_Repeat 16*/  /*on repeat, go to this value - skip intros that shouldn't be repeated */

/*in stereo, 4 bits for left channel and 4 bits for right channel*/ 
#define Mus_Pan0 0xF8  /*pan left*/  
#define Mus_Pan1 0x8F  /*pan right*/
#define Mus_Pan2 0xFF  /*pan center*/
#define Mus_Pan3 0xFF
#define Mus_Pan4 0xCC  /*drums are set slightly quieter*/
#define Mus_Pan5 0xCC  /*so they don't overwhelm the music*/


/* ----anything below here shouldn't need editing ------*/

/*translate from standard midi note value to frequency*/
/*midi notes can be stored in a char, whereas frequency must use int, this allows for more notes*/
const int Mus_Notes[]= {
   0,3228,3047,2876,2715,2592,2419,2283,2155,2034,2330,3839,3624
	,3420,3228,3047,2876,2715,2592,2419,2283,2155,2034,2330,3839,3624
	,3420,3228,3047,2876,2715,2592,2419,2283,2155,2034,2330,1919,1812
	,1710,1614,1523,1438,1357,1281,1206,1141,1077,1017,959, 906
	,855, 807, 761, 719, 678, 640, 604, 570, 538, 508, 479, 453
	,427, 403, 381, 359, 340, 320, 303, 286, 269, 254, 240, 226
	,213, 201, 190, 179, 169, 160, 151, 142, 134, 127, 119, 113 
	,106, 100, 95,  89,  84,  80,  75,  71,  67,  63,  59,  56
	,53,  50,  47,  44,  42,  40,  37,  35,  33,  31,  29,  28
	,53,  50,  47,  44,  42,  40,  37,  35,  33,  31,  29,  28
	,53,  50,  47,  44,  42,  40,  37,  35
};

/*translate from standard midi drum value to noise frequency*/
const int Mus_Drum[]= {
	 0x04,0x04,0x04,0x04,0x04,0x04,0x04,0x04,0x04,0x04,0x04,0x04
	,0x04,0x04,0x04,0x04,0x04,0x04,0x04,0x04,0x04,0x04,0x04,0x04
	,0x04,0x04,0x04,0x04,0x04,0x04,0x04,0x04,0x04,0x04,0x04,0x04
	,0x04,0x04,0x1A,0x04,0x1A,0x04,0x04,0x04,0x04,0x04,0x04,0x04
	,0x04,0x1C,0x04,0x1C,0x1C,0x1C,0x1C,0x1C,0x1C,0x1C,0x1C,0x1C
	,0x1C,0x1C,0x1C,0x1C,0x1C,0x1C,0x1C,0x1C,0x1C,0x1C,0x1C,0x1C
	,0x1C,0x1C,0x1C,0x1C,0x1C,0x1C,0x1C,0x1C,0x1C,0x1C,0x1C,0x1C
	,0x1C,0x1C,0x1C,0x1C,0x1C,0x1C,0x1C,0x1C,0x1C,0x1C,0x1C,0x1C
	,0x1C,0x1C,0x1C,0x1C,0x1C,0x1C,0x1C,0x1C,0x1C,0x1C,0x1C,0x1C
	,0x1C,0x1C,0x1C,0x1C,0x1C,0x1C,0x1C,0x1C,0x1C,0x1C,0x1C,0x1C
	,0x1C,0x1C,0x1C,0x1C,0x1C,0x1C,0x1C,0x1C,0x1C,0x1C,0x1C,0x1C

};

#define Mus_Off 0
#define Mus_Sine 1
#define Mus_Square 2
#define Mus_Saw 3
#define Mus_Noise 4

int Mus_Count; /*keeps track of position in song*/
int Mus_Channel[6];/*channel info*/

Mus_sinesample() {
	/*write sine wave 32 samples*/
	poke(0x0806, 0x0F);
	poke(0x0806, 0x12);
	poke(0x0806, 0x15);
	poke(0x0806, 0x17);
	poke(0x0806, 0x19);
	poke(0x0806, 0x1b);
	poke(0x0806, 0x1d);
	poke(0x0806, 0x1e);
	poke(0x0806, 0x1e);
	poke(0x0806, 0x1e);
	poke(0x0806, 0x1d);
	poke(0x0806, 0x1b);
	poke(0x0806, 0x19);
	poke(0x0806, 0x17);
	poke(0x0806, 0x15);
	poke(0x0806, 0x12);
	poke(0x0806, 0x0F);
	poke(0x0806, 0x0C);
	poke(0x0806, 0x09);
	poke(0x0806, 0x07);
	poke(0x0806, 0x05);
	poke(0x0806, 0x03);
	poke(0x0806, 0x01);
	poke(0x0806, 0x00);
	poke(0x0806, 0x00);
	poke(0x0806, 0x00);
	poke(0x0806, 0x01);
	poke(0x0806, 0x03);
	poke(0x0806, 0x05);
	poke(0x0806, 0x07);
	poke(0x0806, 0x09);
	poke(0x0806, 0x0C);
}

Mus_sawsample() {
	/*write saw wave 32 samples*/
	poke(0x0806, 0x00);
	poke(0x0806, 0x01);
	poke(0x0806, 0x02);
	poke(0x0806, 0x03);
	poke(0x0806, 0x04);
	poke(0x0806, 0x05);
	poke(0x0806, 0x06);
	poke(0x0806, 0x07);
	poke(0x0806, 0x08);
	poke(0x0806, 0x09);
	poke(0x0806, 0x0A);
	poke(0x0806, 0x0B);
	poke(0x0806, 0x0C);
	poke(0x0806, 0x0D);
	poke(0x0806, 0x0E);
	poke(0x0806, 0x0F);
	poke(0x0806, 0x10);
	poke(0x0806, 0x11);
	poke(0x0806, 0x12);
	poke(0x0806, 0x13);
	poke(0x0806, 0x14);
	poke(0x0806, 0x15);
	poke(0x0806, 0x16);
	poke(0x0806, 0x17);
	poke(0x0806, 0x18);
	poke(0x0806, 0x19);
	poke(0x0806, 0x1A);
	poke(0x0806, 0x1B);
	poke(0x0806, 0x1C);
	poke(0x0806, 0x1D);
	poke(0x0806, 0x1E);
	poke(0x0806, 0x1F);
}

Mus_squaresample() {
	/*write square wave, 32 samples*/
	poke(0x0806, 0x00);
	poke(0x0806, 0x00);
	poke(0x0806, 0x00);
	poke(0x0806, 0x00);
	poke(0x0806, 0x00);
	poke(0x0806, 0x00);
	poke(0x0806, 0x00);
	poke(0x0806, 0x00);
	poke(0x0806, 0x00);
	poke(0x0806, 0x00);
	poke(0x0806, 0x00);
	poke(0x0806, 0x00);
	poke(0x0806, 0x00);
	poke(0x0806, 0x00);
	poke(0x0806, 0x00);
	poke(0x0806, 0x00);
	poke(0x0806, 0x1F);
	poke(0x0806, 0x1F);
	poke(0x0806, 0x1F);
	poke(0x0806, 0x1F);
	poke(0x0806, 0x1F);
	poke(0x0806, 0x1F);
	poke(0x0806, 0x1F);
	poke(0x0806, 0x1F);
	poke(0x0806, 0x1F);
	poke(0x0806, 0x1F);
	poke(0x0806, 0x1F);
	poke(0x0806, 0x1F);
	poke(0x0806, 0x1F);
	poke(0x0806, 0x1F);
	poke(0x0806, 0x1F);
	poke(0x0806, 0x1F);
}

initchannelsquare(num) 
char num;
{
	poke(0x0800, num);/*select voice 1*/
	poke(0x0805, 0x00);/*pan volume off*/
	poke(0x0804, 0x0F);/*off*/
	Mus_squaresample();
	poke(0x0804, 0x8F);/*off*/
	Mus_Channel[num]=Mus_Square;
}

initchannelsine(num) 
char num;
{
	poke(0x0800, num);/*select voice 1*/
	poke(0x0805, 0x00);/*pan volume off*/
	poke(0x0804, 0x0F);/*off*/
	Mus_sinesample();
	poke(0x0804, 0x8F);/*off*/
	Mus_Channel[num]=Mus_Sine;
}

initchannelsaw(num) 
char num;
{
	poke(0x0800, num);/*select voice 1*/
	poke(0x0805, 0x00);/*pan volume off*/
	poke(0x0804, 0x0F);/*off*/
	Mus_sawsample();
	poke(0x0804, 0x8F);/*off*/
	Mus_Channel[num]=Mus_Saw;
}

initchannelnoise(num) 
char num;
{
	poke(0x0800, num);/*select voice 1*/
	poke(0x0805, 0x00);/*pan volume off*/
	poke(0x0804, 0x0F);/*off*/
	poke(0x0804, 0x8F);/*off*/
	Mus_Channel[num]=Mus_Noise;
}

initmusic() 
{
	Mus_Count=0;
	poke(0x0801, 0xFF);/*main volume on*/

	Mus_Channel[0]=Mus_Off;
	Mus_Channel[1]=Mus_Off;
	Mus_Channel[2]=Mus_Off;
	Mus_Channel[3]=Mus_Off;
	Mus_Channel[4]=Mus_Off;
	Mus_Channel[5]=Mus_Off;

}


playmusic()
{
	poke(0x0800, 0x0);/*select track 0*/
	if (Mus_Count<TrackLength0[0] && Mus_Channel[0]!=Mus_Off) {
		if (Track0[Mus_Count]==0) {
			poke(0x0805, 0x00);/*volume off*/
		}else{
			poke(0x0805, Mus_Pan0);/*volume on*/
			poke(0x0803, (Mus_Notes[Track0[Mus_Count]]>>8)&0xF);/*frequency msb*/
			poke(0x0802, (Mus_Notes[Track0[Mus_Count]])&0xFF);/*frequency lsb*/
		}
	}else{
		poke(0x0805, 0x00);/*volume off*/
	}

	poke(0x0800, 0x1);
	if (Mus_Count<TrackLength1[0] && Mus_Channel[1]!=Mus_Off) {
		if (Track1[Mus_Count]==0) {
			poke(0x0805, 0x00);
		}else{
			poke(0x0805, Mus_Pan1);
			poke(0x0803, (Mus_Notes[Track1[Mus_Count]]>>8)&0xF);
			poke(0x0802, (Mus_Notes[Track1[Mus_Count]])&0xFF);
		}
	}else{
		poke(0x0805, 0x00);
	}

	poke(0x0800, 0x2);
	if (Mus_Count<TrackLength2[0] && Mus_Channel[2]!=Mus_Off) {
		if (Track2[Mus_Count]==0) {
			poke(0x0805, 0x00);
		}else{
			poke(0x0805, Mus_Pan2);
			poke(0x0803, (Mus_Notes[Track2[Mus_Count]]>>8)&0xF);
			poke(0x0802, (Mus_Notes[Track2[Mus_Count]])&0xFF);
		}
	}else{
		poke(0x0805, 0x00);
	}

	poke(0x0800, 0x3);
	if (Mus_Count<TrackLength3[0] && Mus_Channel[3]!=Mus_Off) {
		if (Track3[Mus_Count]==0) {
			poke(0x0805, 0x00);
		}else{
			poke(0x0805, Mus_Pan3);
			poke(0x0803, (Mus_Notes[Track3[Mus_Count]]>>8)&0xF);
			poke(0x0802, (Mus_Notes[Track3[Mus_Count]])&0xFF);
		}
	}else{
		poke(0x0805, 0x00);
	}

	poke(0x0800, 0x4);
	if (Mus_Count<TrackLength4[0] && Mus_Channel[4]!=Mus_Off) {
		if (Track4[Mus_Count]==0) {
			poke(0x0805, 0x00);
		}else{
			poke(0x0805, Mus_Pan4);
			if (Mus_Channel[4]==Mus_Noise) {
				poke(0x0807, 0x80|(Mus_Drum[Track4[Mus_Count]]) );/*noise*/
			}else{
				poke(0x0803, (Mus_Notes[Track4[Mus_Count]]>>8)&0xF);
				poke(0x0802, (Mus_Notes[Track4[Mus_Count]])&0xFF);
			}
		}
	}else{
		poke(0x0805, 0x00);
	}

	poke(0x0800, 0x5);
	if (Mus_Count<TrackLength5[0] && Mus_Channel[5]!=Mus_Off) {
		if (Track5[Mus_Count]==0) {
			poke(0x0805, 0x00);
		}else{
			poke(0x0805, Mus_Pan5);
			if (Mus_Channel[5]==Mus_Noise) {
				poke(0x0807, 0x80|(Mus_Drum[Track5[Mus_Count]]) );/*noise*/
			}else{
				poke(0x0803, (Mus_Notes[Track5[Mus_Count]]>>8)&0xF);
				poke(0x0802, (Mus_Notes[Track5[Mus_Count]])&0xFF);
			}
		}
	}else{
		poke(0x0805, 0x00);
	}



	Mus_Count++;
	if (Mus_Count>Mus_Length) Mus_Count=Mus_Repeat;

}

/**********************************************/
/*     Undine add on for the 7WizardS iso     */
/*       play music each COUNTMAX call        */
/* set COUNTMAX lower to increase sound speed */
/*    set it greater to slow sound speed      */
/*        better use it with vsync()          */
/*        count is a global variable          */
/**********************************************/
music_update()
{
  count++;
  if (count>COUNTMAX)
  {
    playmusic();
    count=0;
  }
}