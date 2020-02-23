 #!/bin/bash
 DATAFILE=$1
 ./filedump.out -x $DATAFILE >list-x.txt
 ./filedump.out -X $DATAFILE >>list-x.txt
 ./filedump.out -d $DATAFILE >>list-x.txt
 ./filedump.out -D $DATAFILE >>list-x.txt
 ./filedump.out -b $DATAFILE >>list-x.txt
 ./filedump.out -B $DATAFILE >>list-x.txt
 ./filedump.out -m $DATAFILE >>list-x.txt
./filedump.out >>list-x.txt
  
