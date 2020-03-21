#!/bin/sh
echo File has been accessed

module load gnu geant4 root
echo modules loaded

export CRYHOME=/lustre/work/perez90/hep/cry/cry_v1.7/
export CRYDATAPATH=/lustre/work/perez90/hep/cry/cry_v1.7/data
echo cry loaded
#  setup GEANT4 environment
#. /lustre/work/perez90/hep/g4/Geant4-10.5.1-Darwin/bin/geant4.sh
. /opt/ohpc/pub/libs/gnu/geant4/10.04.p02/bin/geant4.sh
echo geant4.sh executed

export G4BASE=/opt/ohpc/pub/libs/gnu/geant4/10.04.p02
export G4INSTALL=/opt/ohpc/pub/libs/gnu/geant4/10.04.p02/share/Geant4-10.4.2/geant4make
echo more g4 shit

source /opt/ohpc/pub/libs/gnu/geant4/10.04.p02/share/Geant4-10.4.2/geant4make/geant4make.sh
#source /lustre/work/perez90/hep/g4/Geant4-10.5.1-Darwin/share/Geant4-10.5.1/geant4make/geant4make.sh
echo g4 make stuff
export G4BIN="$PWD"

#export LD_LIBRARY_PATH=/opt/ohpc/pub/libs/gnu/geant4/10.04.p02/lib64
#export DYLD_LIBRARY_PATH=/opt/ohpc/pub/libs/gnu/geant4/10.04.p02/lib64:/opt/ohpc/pub/libs/gnu/root/6.14.04/lib
#export SHLIB_PATH=/opt/ohpc/pub/libs/gnu/geant4/10.04.p02/lib64
#export LIBPATH=/opt/ohpc/pub/libs/gnu/geant4/10.04.p02/lib64
echo libraries

#make -DGEANT4_USE_OPENGL_X11=ON
