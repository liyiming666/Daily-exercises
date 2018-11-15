#! /bin/bash

#打包前一天的log
cd ../log 
DATE=`date +"%Y-%m-%d" -d "-24hour"`
ALL_DATE="ssa.log."$DATE
CMD="tar zcvf $ALL_DATE".tar.gz"$ALL_DATE"*" --remove-file"
#echo $CMD
$CMD
