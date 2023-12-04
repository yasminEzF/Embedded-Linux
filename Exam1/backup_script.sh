#!/bin/bash

echo "enter directories to compress"
read -a dir_list

if [ ! -d "backups" ];
then
	mkdir backups
fi

for d in "${dir_list[@]}"
do
	if test -e ${d} 
	then 
		tar -czf ./backups/backup_${d}_$(date '+%Y_%m_%d') ${d}
		echo "file ${d} compressed"	
	else
		echo "file ${d} doesn't exist, can't compress"	
	fi		
done


