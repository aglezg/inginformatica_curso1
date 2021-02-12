
# practica 3. Principio de computadoras // Adrián González Galván con DNI 43491148B
# OBJETIVO:
# Te proponemos realizar en ensamblador un programa para realizar la evaluación de un polinomio
# de tercer grado en un rango de enteros.
# Enunciado: Realiza un programa en ensamblador MIPS que evalúe un polinomio de segundo grado de la forma
# f(x) = a x3 + b x2 + c x + d en un rango de valores enteros [r,s]
# El programa debe pedir por consola:
# - tres números flotantes en simple: a, b, c y d
# - dos números enteros r y s.

	.data		# directiva que indica la zona de datos
titulo: 	.asciiz	"Evaluación polinomio f(x)= a x³ + b x² + c x + d en un intervalo [r,s]. \n"
msgvalores:	.asciiz	"Introduzca los valores de a,b,c y d (separados por retorno de carro):\n"
msgrango:	.asciiz	"Introduzca [r,s] (r y s enteros, r<=s) (separados por retorno de carro):\n"
funcion_1:      .asciiz "\nf("
funcion_2:      .asciiz ")="

        .text		# directiva que indica la zona de código
main:
	la	$a0,titulo
	li	$v0,4
	syscall #imprime la cadena "titulo"


	la	$a0,msgvalores
	li	$v0,4
	syscall #imprime la cadena "msgvalores"

#LEO LOS VALORES: a, b, c y d

        li      $v0,6
        syscall #lee flotante y lo guarda en $f0
        mov.s $f4,$f0 #muevo el flotante a un nuevo registro  

        li      $v0,6
        syscall 
        mov.s $f5,$f0 

        li      $v0,6        #repito el proceso para los otros 3 flotantes
        syscall 
        mov.s $f6,$f0   

        li      $v0,6
        syscall
        mov.s $f7,$f0   

#LEO EL RANGO EN ENTEROS DE LA FUNCIÓN

bucle_while: la	$a0,msgrango
	     li	$v0,4
	     syscall #imprime la cadena "msgrango"

             li      $v0,5
             syscall #lee entero y lo guarda en $v0
             move $t1,$v0 #muevo el entero a un nuevo registro

             li      $v0,5
             syscall           #repito el proceso para el otro entero de rango   
             move $t2,$v0 

             bgt $t1,$t2, bucle_while #comparo y salto si $t1>$t2

#CONVIERTO DE ENTERO A FLOTANTE PARA PODER OPERAR

bucle_for:   mtc1 $t1,$f8 #hago una copia "cruda" del registro $t1 en $f8
             cvt.s.w $f9,$f8 #convierto ese entero en flotante
             
#BUCLE DE LA FUNCION

             mul.s $f16,$f6,$f9 #valor c($f6)*x

             mov.s $f10,$f9   
             mul.s $f9,$f9,$f9 #actualizo la x --> x=x²
             mul.s $f17,$f9,$f5 #valor b($f5)*x*x

             mul.s $f10,$f10,$f9 #actualizo la x --> x=x³
             mul.s $f18,$f4,$f10 #valor a($f4)*x*x*x

             add.s $f12,$f18,$f17  #f=a*x*x*x + b*x*x
             add.s $f12,$f12,$f16 #f=a*x*x*x + b*x*x + c*x
             add.s $f12,$f12,$f7 #f=a*x*x*x + b*x*x + c*x + d
             
             la	$a0,funcion_1
	     li	$v0,4
	     syscall #imprime la cadena "funcion_1"

             move $a0,$t1
             li     $v0,1
             syscall #imprimo el entero valor actual de la funcion

             la	$a0,funcion_2
	     li	$v0,4
	     syscall #imprime la cadena "funcion_2"

             li$v0,2
             syscall #imprime el valor de $f12(nuestra función "f(x)")

             add $t1,$t1,1 #incremento la "x" de la funcion
             ble $t1,$t2, bucle_for #establezco un bucle con la condicion $t1<=$t2



#SALGO DEL PROGRAMA

             li     $v0,10
             syscall #finalizo el programa (exit)




