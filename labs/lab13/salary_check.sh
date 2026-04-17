#!/bin/bash
read -p "Please enter your annual salary here: " salary

if ! [[ "$salary" =~ ^-?[0-9]+$ ]] ; then 
    echo "Error: Entered value '$salary' is not valid. Please enter a number."
    exit 1
fi

if [ "$salary" -lt 60000 ]; then echo "Entry Level"
elif [ "$salary" -lt 90000 ]; then echo "Mid Level"
elif [ "$salary" -lt 120000 ]; then echo "Senior Level"
else echo "Executive Level"
fi