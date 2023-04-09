#!/bin/bash

if [ $# -ne 4 ]; then
    echo "Usage: $0 missing parameters"
    exit -1
fi
    alfa1=$1
    alfa2=$2
    t_voice=$3
    t_silence=$4

# Be sure that this file has execution permissions:
# Use the nautilus explorer or chmod +x run_vad.sh

# Write here the name and path of your program and database
DIR_P2=$HOME/PAV/P2
DB=$DIR_P2/db.v4
CMD="$DIR_P2/bin/vad --alfa1=$alfa1 --alfa2=$alfa2 --t_voice=$t_voice --t_silence=$t_silence"

for filewav in $DB/*/*wav; do
#    echo
    echo "**************** $filewav ****************"
    if [[ ! -f $filewav ]]; then 
	    echo "Wav file not found: $filewav" >&2 #si el fitxer no existeix
	    exit 1
    fi


    

    filevad=${filewav/.wav/.vad} #coge la variable de entorno filewav y susituye el .wav por el .vad

    $CMD -i $filewav -o $filevad || exit 1   

# Alternatively, uncomment to create output wave files
#    filewavOut=${filewav/.wav/.vad.wav}
#    $CMD $filewav $filevad $filewavOut || exit 1

done

scripts/vad_evaluation.pl $DB/*/*lab