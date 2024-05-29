#! bin/bash

ifconfig | grep -o -E '([0-9a-fA-F]{2}:){5}([0-9a-fA-F]{2})'

#Muestra la configuracion de red de todas las interfaces de red disponibles enntre ellas la MAC ip
#grep -o -E 
#-o indica a grep que solo muestre las lineas con el patron establecido 
#-E hablita el uso de expresiones regulares
#[0-9a-fA-F]: Coincide con cualquier carácter hexadecimal (0-9, a-f, A-F).
#{2}: Indica que el patrón [0-9a-fA-F] debe aparecer exactamente dos veces consecutivas.
#: : Coincide con el carácter dos puntos literal (:). 
#{5} busca exactamente 5 repeticiones del patron anterior 
#y lo siguiente lo mismo pero sin seguir por :
