# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    test.sh                                            :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: matle-br <matle-br@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/07/15 10:58:04 by matle-br          #+#    #+#              #
#    Updated: 2024/07/15 11:20:50 by matle-br         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#!/bin/bash

# Nombre de listes à tester
num_tests=15
# Taille des listes
n=500

total_moves=0

generate_random_list()
{
	shuf -i 1-10000 -n $1
}

echo "Testing $num_tests random lists of size $n"
echo "-------------------------------------------"

for ((i = 1; i <= num_tests; i++)); do
	#Générer une liste aléatoire
	random_list=$(generate_random_list $n | tr '\n' ' ')
	echo "Test $i: $random_list"

	moves=$(./push_swap $random_list | wc -l)

	result=$(./push_swap $random_list | ./checker_linux $random_list)

	echo "Result: $result"
	echo "Number of moves: $moves"
	echo "----------------------------------------"

	total_moves=$((total_moves + moves))
done

average_moves=$((total_moves / num_tests))
echo "Average number of moves: $average_moves"
