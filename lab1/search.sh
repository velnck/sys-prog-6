#!/bin/bash

# set -x

iterate() {
	local dir="$1"
	shopt -s dotglob
	
	for file in "$dir"/*
	do
		if [ -f "$file" ] 
		then
			for pattern in "${patterns[@]}"
			do
				sed -n "/$pattern/Q 1" <<< $(basename "$file")
			       	if [ $? == 1 ]
				then
					echo "$file"
					sed -n '/# header/Q 1' "$file"
					if [ $? == 1 ]
					then
						cat -n "$file"
						echo; echo
					fi
					break
				fi	
			done
		elif [ -d "$file" ]
		then
			iterate "$file"
		fi
	done
}

patterns=( "$@" )

iterate $PWD


