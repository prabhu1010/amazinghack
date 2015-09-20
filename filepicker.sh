#!/bin/bash
var_lastchecked=`cat lastchecked.file`
cp lastchecked.file lastchecked.file.bak #backup in case something happens
echo Comparing to $var_lastchecked

# This really should be redirected to lastchecked but for testing we dont want to do that
date +%s > new_lastchecked.file 
echo Current time is `cat new_lastchecked.file`

if test -s candidates.file
then
#rm candidates.file
echo ""
fi
touch candidates.file

for i in `ls -R *.csv`
do
seconds=`stat -c%Z $i`
if [ $seconds -gt $var_lastchecked ]
then
echo "File $i qualifies with last modified time of $seconds"
#numsuffix=`echo $i | cut -d "_" -f2 | cut -d "." -f1`
#echo "$numsuffix" >> candidates.file
echo "$i" >> candidates.file
fi
done
