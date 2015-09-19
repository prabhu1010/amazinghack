#!/bin/bash
var_lastchecked=`cat lastchecked.file`
cp lastchecked.file lastchecked.file.bak #backup in case something happens
echo Comparing to $var_lastchecked

# This really should be redirected to lastchecked but for testing we dont want to do that
date +%s > new_lastchecked.file 
echo Current time is `cat new_lastchecked.file`

for i in `ls -R *.csv`
do
seconds=`stat -c%Z $i`
if [ $seconds -gt $var_lastchecked ]
then
echo "File $i qualifies with last modified time of $seconds"
fi
done
