#!/bin/bash

FILE="trains.txt"
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
        read -p "Enter Train Number: " num
        read -p "Enter Train Name: " name
        if grep -q "^$num," $FILE
        then
            echo "Record exists"
        else
            echo "$num,$name" >> $FILE
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
        read -p "Enter Train Number: " num
        grep "^$num," $FILE || echo "Not found"
        ;;
    4)
        read -p "Enter Train Number: " num
        if grep -q "^$num," $FILE
        then
            read -p "Enter new name: " name
            sed -i "s/^$num,.*/$num,$name/" $FILE
            echo "Updated"
        else
            echo "Not found"
        fi
        ;;
    5)
        read -p "Enter Train Number: " num
        if grep -q "^$num," $FILE
        then
            sed -i "/^$num,/d" $FILE
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
