#! /bin/bash

# regn (bruker CPU hele tiden)

(( max = 900000 ))
(( i = 0  ))
(( sum = 0  ))

echo $0 : regner....
while (($i < $max))
do
        (( i += 1 ))
        (( sum += i  ))
done
echo $0, resultat: $sum

