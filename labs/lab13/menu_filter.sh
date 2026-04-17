#!/bin/bash

while true; do
    echo "1) Show all active employees"
    echo "2) Show all inactive employees"
    echo "3) Show employees hired before 2020"
    echo "4) Show highest paid employee"
    echo "5) Exit"
    read -rp "Enter choice: " choice

    case "$choice" in
        1) awk -F',' 'NR==1 || $10=="active"' employees.csv
         ;;
        2) awk -F',' 'NR==1 || $10=="inactive"' employees.csv
         ;;
        3) awk -F',' 'NR==1 || $7 < "2020-01-01"' employees.csv
         ;;
        4) awk -F',' 'NR==1 {header=$0; next} $6+0 > max {max=$6+0; line=$0} END {print header; if (line!="") print line}' employees.csv
         ;;
        5) exit 0
         ;;
        *) echo "Error: Invalid input. please try again."
         ;;
    esac

done