#include "../doomtype.h"
#include "../sounds.h"
#include "../i_system.h"
#include <stdlib.h>
int snd_card = 1;
int mus_card = 1;

dboolean I_SoundIsPlaying(int handle) {
    return false;
}
void I_StopSound(int handle) {}
void I_UnRegisterSong(int handle);
int I_RegisterSong(const void *data, size_t len) { return 0; }

void I_PauseSong (int handle) {}
void I_ResumeSong (int handle){}

void I_PlaySong(int handle, int looping) {}

int I_StartSound(int id, int channel, int vol, int sep, int pitch, int priority) {
    return channel;
}

dboolean I_AnySoundStillPlaying(void) {
    return false;
}

void I_SetMusicVolume(int volume) {}

void I_UpdateSoundParams(int handle, int volume, int seperation, int pitch) {}

int I_GetSfxLumpNum (sfxinfo_t *sfxinfo) {
    return 0;
}
char* I_FindFileInternal(const char* wfname, const char* ext, dboolean isStatic) {
    return "TODO";
}

char* I_FindFile(const char* wfname, const char* ext)
{
  return I_FindFileInternal(wfname, ext, false);
}

const char* I_FindFile2(const char* wfname, const char* ext)
{
  return (const char*) I_FindFileInternal(wfname, ext, true);
}

void I_uSleep(unsigned long usecs) {
    sleep_us( usecs);
}

#include "../i_sound.h"


//
// MUSIC API.
//

// placeholder for unused option
const char *snd_mididev;

const char *midiplayers[2] = {"quicktime", NULL};
const char *snd_midiplayer = "quicktime";
const char *snd_soundfont;
void M_ChangeMIDIPlayer(void)
{
}


int ticdup = 1;
int maketic;
dboolean realframe = false;


void I_Init2(void)
{}


void M_LoadDefaults (void);
#include "../lprintf.h"
//int main(int argc, const char * const * argv)

extern int myargc;
extern char** myargv;


int main(int argc, char **argv)
{
  myargc = argc;
  myargv = (char**)malloc(sizeof(myargv[0]) * myargc);
  memcpy(myargv, argv, sizeof(myargv[0]) * myargc);

  // e6y: was moved from D_DoomMainSetup
  // init subsystems
  //jff 9/3/98 use logical output routine
  lprintf(LO_INFO,"M_LoadDefaults: Load system defaults.\n");
  M_LoadDefaults();              // load before initing other systems

  /* Version info */
  lprintf(LO_INFO,"\n");
  PrintVer();

  D_DoomMain ();
  return 0;
}
