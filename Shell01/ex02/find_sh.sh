#! /bin/sh

find . -type f  -name '*.sh'  -exec basename {} .sh \; 

#-name '*.sh' busca archivos cuyos nombres terminen en .sh
#-exec basename {} .sh \; este comando ejecutara basename para mostrar solo los nombres del archivo sin el .sh
