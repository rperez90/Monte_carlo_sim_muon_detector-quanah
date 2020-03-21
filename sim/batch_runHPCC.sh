#!/bin/bash
#   XSHFIT 0 for camera 1,  -40000 in mm= -40mm for camera 2, 40000 for camera 3
export G4CRYXSHIFT=0     # in mm
export G4CRYYSHIFT=0     # in mm
export G4CRYZSHIFT=1500  # in mm
export G4CRYPCUT=1    # in MeV
#export G4CRYOUTFILE=B4job1Room200cm100ev_XXXXPARAM1
export CRYRANDOMSEED=1236 # rp-changed 03.08.2020 from 1236
# env
export DYLD_LIBRARY_PATH=/opt/ohpc/pub/libs/gnu/root/6.14.04/lib

/home/perez90/geant4_workdir/bin/Linux-g++/exampleB4a  -m batch_numbereventsHPCC.mac

#for file in /lustre/work/perez90/hep/MuonSC8/mc/v4/sim
#do
#  mv muonTree01.root muonTree06_$1deg_$2sim$3.root
#done

