#include <math.h>
#include <stdlib.h>
#include <stdio.h>
#include "pav_analysis.h"
#include "vad.h"

const float FRAME_TIME = 10.0F; /* in ms. */

/* 
 * As the output state is only ST_VOICE, ST_SILENCE, or ST_UNDEF,
 * only this labels are needed. You need to add all labels, in case
 * you want to print the internal state in string format
 */

const char *state_str[] = {
  "UNDEF", "S", "V", "INIT", "MS", "MV"
};

const char *state2str(VAD_STATE st) {
  return state_str[st];
}

/* Define a datatype with interesting features */
typedef struct {
  float zcr;
  float pow;
  float am;
} Features;

/* 
 * TODO: Delete and use your own features!
 */

Features compute_features(const float *x, int N) {
  /*
   * Input: x[i] : i=0 .... N-1 
   * Ouput: computed features
   */
  Features feat;
  feat.pow = compute_power(x,N);
  feat.zcr = compute_zcr(x,N,16000);
  feat.am = compute_am(x,N);

  return feat;
}

/* 
 * TODO: Init the values of vad_data
 */

VAD_DATA * vad_open(float rate, float alfa1, float alfa2, float t_voice, float t_silence, float zcr) {
  VAD_DATA *vad_data = malloc(sizeof(VAD_DATA));
  vad_data->state = ST_INIT;
  vad_data->sampling_rate = rate;
  vad_data->frame_length = rate * FRAME_TIME * 1e-3;
  vad_data->alfa1 = alfa1;
  vad_data->alfa2 = alfa2;
  vad_data->t_voice = t_voice;
  vad_data->t_silence = t_silence;
  vad_data->zcr = zcr;
  vad_data->mv = 0;
  vad_data->ms = 0;
  return vad_data;
}

VAD_STATE vad_close(VAD_DATA *vad_data) {
  /* 
   * TODO: decide what to do with the last undecided frames
   */
    VAD_STATE state = vad_data->state;
  if(state == ST_MAYBESILENCE) state = ST_VOICE;
  if(state == ST_MAYBEVOICE) state = ST_SILENCE;
  free(vad_data);
  return state;
}

unsigned int vad_frame_size(VAD_DATA *vad_data) {
  return vad_data->frame_length;
}

/* 
 * TODO: Implement the Voice Activity Detection 
 * using a Finite State Automata
 */

VAD_STATE vad(VAD_DATA *vad_data, float *x) {

  /* 
   * TODO: You can change this, using your own features,
   * program finite state automaton, define conditions, etc.
   */

  Features f = compute_features(x, vad_data->frame_length);
  vad_data->last_feature = f.pow; /* save feature, in case you want to show */

  vad_data->k1 = vad_data->k0 + vad_data->alfa1;
  vad_data->k2 = vad_data->k1 + vad_data->alfa2;

  switch (vad_data->state) {
  case ST_INIT:
    vad_data->state = ST_SILENCE;
    vad_data->k0 = f.pow;
    vad_data->k1 = vad_data->k0 + vad_data->alfa1;
    vad_data->k2 = vad_data->k1 + vad_data->alfa2;
    break;

  case ST_SILENCE:
    if (f.pow > vad_data->k2 && f.zcr){
      vad_data->state = ST_MAYBEVOICE;
      vad_data->mv++;
    }
    break;

  case ST_MAYBEVOICE:
    if (f.pow > vad_data->k2 && f.zcr){
      if(vad_data->mv*vad_data->frame_length/vad_data->sampling_rate > vad_data->t_voice){
        vad_data->state = ST_VOICE;
        vad_data->mv = 0;
      }else{
        vad_data->mv++;
      }
    }else{
      vad_data->state = ST_SILENCE;
      vad_data->ms = 0;
    }
    break;

  case ST_MAYBESILENCE:
    if (f.pow < vad_data->k1 && f.zcr > vad_data->zcr){
      if(vad_data->ms*vad_data->frame_length/vad_data->sampling_rate > vad_data->t_silence){
        vad_data->state = ST_SILENCE;
        vad_data->ms = 0;
      }else
        vad_data->ms++;
    }else{
      vad_data->state = ST_VOICE;
      vad_data->mv = 0;
    }
    break;

  case ST_VOICE:
    if (f.pow < vad_data->k1 && f.zcr > vad_data->zcr){
      vad_data->state = ST_MAYBESILENCE;
      vad_data->ms++;
    }
    break;

  case ST_UNDEF:
    break;
  }

  if (vad_data->state == ST_SILENCE ||
      vad_data->state == ST_VOICE){
    return vad_data->state;
  }else{
    return ST_UNDEF;
  }
}

void vad_show_state(const VAD_DATA *vad_data, FILE *out) {
  fprintf(out, "%d\t%f\n", vad_data->state, vad_data->last_feature);
}
