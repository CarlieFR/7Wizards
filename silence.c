const char silenceTrack0[]={0x00};
const int silenceTrackLength0[]={0};
const char silenceTrack1[]={0x00};
const int silenceTrackLength1[]={0};
const char silenceTrack2[]={0x00};
const int silenceTrackLength2[]={0};
const char silenceTrack3[]={0x00};
const int silenceTrackLength3[]={0};
const char silenceTrack4[]={0x00};
const int silenceTrackLength4[]={0};
const char silenceTrack5[]={0x00};
const int silenceTrackLength5[]={0};

silence()
{
Track0=silenceTrack0;
TrackLength0=silenceTrackLength0;
Track1=silenceTrack1;
TrackLength1=silenceTrackLength1;
Track2=silenceTrack2;
TrackLength2=silenceTrackLength2;
Track3=silenceTrack3;
TrackLength3=silenceTrackLength3;
Track4=silenceTrack4;
TrackLength4=silenceTrackLength4;
Track5=silenceTrack5;
TrackLength5=silenceTrackLength5;

Mus_Length=0;
Mus_Repeat=0;

initmusic();
initchannelnoise(0);
initchannelnoise(1);
initchannelnoise(2);
initchannelnoise(3);
initchannelnoise(4);
initchannelnoise(5);
playmusic();

}