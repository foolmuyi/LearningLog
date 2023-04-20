#!/bin/bash

BACKUP=/home/muyi/shell
DATETIME=$(date +%Y-%m-%d_%H_%M_%S)

# create backup dir
[ ! -d $BACKUP/$DATETIME ] && mkdir -p $BACKUP/$DATETIME

# copy files to backup dir
cp config.json $BACKUP/$DATETIME/

#tar and delete the backup dir
cd $BACKUP/
tar -zcf $DATETIME.tar.gz ./$DATETIME
rm -rf ./$DATETIME

# delete old backup files
find $BACKUP -ctime +10 -name "*.tar.gz" -exec rm {} \;
#find $BACKUP -ctime +10 -name "*.tar.gz" -delete  # also works
echo "success"
