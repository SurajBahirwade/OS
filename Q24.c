#!/bin/bash

FILE="students.txt"
touch $FILE

while true
do
    echo "1. Add Record"
    echo "2. View Records"
    echo "3. Search Record"
    echo "4. Update Record"
    echo "5. Delete Record"
    echo "6. Exit"
    read -p "Enter choice: " ch

    case $ch in
    1)
        read -p "Enter Roll Number: " roll
        read -p "Enter Name: " name
        if grep -q "^$roll," $FILE
        then
            echo "Record exists"
        else
            echo "$roll,$name" >> $FILE
            echo "Record added"
        fi
        ;;
    2)
        if [ -s $FILE ]
        then
            cat $FILE
        else
            echo "No records"
        fi
        ;;
    3)
        read -p "Enter Roll Number: " roll
        grep "^$roll," $FILE || echo "Not found"
        ;;
    4)
        read -p "Enter Roll Number: " roll
        if grep -q "^$roll," $FILE
        then
            read -p "Enter new name: " name
            sed -i "s/^$roll,.*/$roll,$name/" $FILE
            echo "Updated"
        else
            echo "Not found"
        fi
        ;;
    5)
        read -p "Enter Roll Number: " roll
        if grep -q "^$roll," $FILE
        then
            sed -i "/^$roll,/d" $FILE
            echo "Deleted"
        else
            echo "Not found"
        fi
        ;;
    6)
        exit 0
        ;;
    *)
        echo "Invalid choice"
        ;;
    esac
done
