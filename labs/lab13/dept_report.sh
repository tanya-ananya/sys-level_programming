#!/bin/bash

departments=("Engineering" "Marketing" "Finance" "HR")

for department in "${departments[@]}" do
    echo "=== $department ==="

    awk -F',' -v department="$department" 'NR>1 && $4==department {printf "%s %s - $%s\n", $2, $3, $6}' employees.csv

    count=$(awk -F',' -v department="$department" 'NR>1 && $4==department {x++} END {print x+0}' employees.csv)
    echo "Total number of employees: $count"
    echo "-----"
done