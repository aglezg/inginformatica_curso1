# practica 2. Principio de computadoras
# OBJETIVO: introduce el codigo necesario para reproducir el comportamiento del programa
# C++ que se adjunta como comentarios

##include <iostream>
#
#int main()
#{
#    std::cout << "Encuentra el número de veces que aparece una cifra en un entero." << std::endl;
#
#    int cifra;
#    do {
#        std::cout << "Introduzca la cifra a buscar (numero de 0 a 9): ";
#        std::cin >> cifra;
#    } while ((cifra < 0) || (cifra > 9));
#
#    int numero;
#    do {
#        std::cout << "Introduzca un entero positivo donde se realizará la búsqueda: ";
#        std::cin >> numero;
#    } while (numero < 0);
#
#    std::cout << "Buscando " << cifra << " en " << numero << " ... " << std::endl;
#    int encontrado = 0;
#    do {
#        int resto = numero % 10;
#        if (resto == cifra) encontrado++;
#        numero = numero / 10;
#    } while (numero != 0);
#
#    std::cout << "La cifra buscada se encontró en " << encontrado <<" ocasiones." << std::endl;
#    return 0;
#}

# Adrián Glez Galván, DNI:43491148B, PE205, Grupo:2

	.data		# directiva que indica la zona de datos
titulo: 	.asciiz	"Encuentra el numero de veces que aparece una cifra en un entero.\n"
msgcifra:	.asciiz	"Introduzca la cifra a buscar (numero de 0 a 9): "
msgnumero:	.asciiz	"Introduzca un entero positivo donde se realizara la busqueda: "
msgbusqueda1:	.asciiz	"Buscando cifra "
msgbusqueda2:	.asciiz	" en el numero "
msgresultado1:	.asciiz	" ...\nLa cifra buscada se encontro en "
msgresultado2:	.asciiz	" ocasiones\n"


	.text		# directiva que indica la zona de código
main:
	# IMPRIME EL TITULO POR CONSOLA
	#    std::cout << "Encuentra el número de veces que aparece una cifra en un entero." << std::endl;
	la	$a0,titulo
	li	$v0,4
	syscall


	# INTRODUCE AQUI EL CODIGO EQUIVALENTE A:
	#    do {
	#        std::cout << "Introduzca la cifra a buscar (numero de 0 a 9): ";
	#        std::cin >> cifra;
	#    } while ((cifra < 0) || (cifra > 9));
	# NOTA: utiliza $s0 para almacenar la cifra

bucle_cifra:  la $a0,msgcifra
              li $v0,4
              syscall                         #imprime la cadena "msgcifra"

              li $v0,5
              syscall                         #lee un entero por pantalla y lo almacena en $v0
              move $s0,$v0                    #muevo el entero a $s0
              blt $s0,$zero, bucle_cifra      #hago las pertinentes comparaciones
              bgt $s0,9, bucle_cifra


	# INTRODUCE AQUI EL CODIGO EQUIVALENTE A:
	#    do {
	#        std::cout << "Introduzca un entero positivo donde se realizará la búsqueda: ";
	#        std::cin >> numero;
	#    } while (numero < 0);
	# NOTA: utiliza $s1 para almacenar el numero donde buscar la cifra

bucle_numero:  la $a0,msgnumero
               li $v0, 4
               syscall                         #imprime la cadena "msgnumero"

               li $v0,5
               syscall                         #lee otro entero por pantalla y lo almacena en $v0
               move $s1,$v0                    #muevo ese entero a $s1
               blt $s1, $zero, bucle_numero    #hago la comparacion $s1<0
        

	#IMPRIME MENSAJE DE BUSQUEDA POR CONSOLA, suponiendo que en $s0 esta la cifra a buscar
	# y en $s1 el numero en el que buscar la cifra
	la	$a0,msgbusqueda1
	li	$v0,4
	syscall

	move	$a0,$s0
	li	$v0,1
	syscall

	la	$a0,msgbusqueda2
	li	$v0,4
	syscall

	move	$a0,$s1
	li	$v0,1
	syscall

	# INTRODUCE AQUI EL CODIGO EQUIVALENTE A:
	#    int encontrado = 0;
	#    do {
	#        int resto = numero % 10;
	#        if (resto == cifra) encontrado++;
	#        numero = numero / 10;
	#    } while (numero != 0);
	# NOTA: utiliza $s2 para almacenar el contador encontrado

        move $s2,$zero                              #inicio entrado($s2) a cero
        li $t2, 10                                  #cargo en un registro temporal "10" para poder efectuar la divisón

bucle_operacion: div $s1,$t2                        #divido $s1/$t2
                 mfhi $t3                           #copio el resto de la división en otro registro temporal
                 bne $t3,$s0,else                   #comparo si el resto($t3) no es igual a la cifra($s0) que estamos buscando
                 addi $s2,$s2,1                     #añado "1" a "encontrado"($s2) si el resto y la cifra son iguales
else:            mflo $s1                           #actualizamos el número($s1) colocando el cociente de la división en el mismo
                 bne $s1,0,bucle_operacion          #comparamos si el número($s1) no es igual a "0"(cero) para poder seguir efectuándo el bucle

	#IMPRIME EL RESULTADO POR CONSOLA, suponiendo que en $s2 tenemos el contador de econtrados
	la	$a0,msgresultado1
	li	$v0,4
	syscall

	move	$a0,$s2
	li	$v0,1
	syscall

	la	$a0,msgresultado2
	li	$v0,4
	syscall

	# las siguientes dos instrucciones finalizan el programa
	li $v0,10
	syscall
 
