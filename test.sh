#!/bin/bash 
 
for var in "$@" 
do 
  echo $var 
  echo $var  >test.txt
  
done