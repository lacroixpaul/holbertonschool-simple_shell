#!/bin/bash

# Définition des fonctions
function welcome_message {
    echo "Bienvenue dans le script Bash !"
}

function add_numbers {
    local num1=$1
    local num2=$2
    local sum=$((num1 + num2))
    echo "La somme de $num1 et $num2 est : $sum"
}

# Appel des fonctions
welcome_message
add_numbers 3 5
