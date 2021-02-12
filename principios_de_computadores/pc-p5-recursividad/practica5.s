
#Trabajo realizado por Adrián González Galván del Grupo 2 de Tarde.

#Descripción:
#Programa que contenga una función que invierta una cadena de caracteres y compruebe si es palíndroma. En concreto debe implementarse lo siguiente:

#1) Una versión recursiva de la función con el nombre reverse_r que reciba dos parámetros. En el
#primer parámetro $a0 debe recibir la dirección de memoria donde se encuentra la cadena a
#invertir, y en el segundo parámetro $a1 el número de caracteres de la cadena. Debe devolver en
#$v0 un ‘1’ si la cadena es palíndroma y un ‘0’ si no lo es.

#2) Una versión iterativa de la función con el nombre reverse_i que reciba dos parámetros. En el
#primer parámetro $a0 debe recibir la dirección de memoria donde se encuentra la cadena a
#invertir, y en el segundo parámetro $a1 el número de caracteres de la cadena. Debe devolver en
#$v0 un ‘1’ si la cadena es palíndroma y un ‘0’ si no lo es.

#3) Una función strlen que calcule el número de caracteres que tiene una cadena de caracteres del
#tipo asciiz (es decir, que termine con la cadena con un byte 0). Esta función recibirá en $a0 la
#dirección de memoria donde se encuentra la cadena de la cual tiene que calcular la longitud, y
#devolverá en $v0 el número de caracteres de la misma.

size=1 #bytes que ocupa cada letra de la cadena

	.data
cadena: 	.asciiz "Practica 5 de Principios de Computadores. Quedate en casa!!"
cadena2:	.asciiz "roma tibi subito m otibus ibit amor"
cadtiene:	.asciiz " tiene "
cadcarac:	.asciiz " caracteres.\n"
cadespal:	.asciiz "Es palíndroma.\n\n"
cadnoespal:	.asciiz "No es palíndroma.\n\n"

cadnueva:       .asciiz "¿Le gustaría introducir una cadena por teclado?\n"
cadopcion:      .asciiz "<0> No, <1> Sí:"
cadintroduzca:  .asciiz "\nIntroduzca la cadena:\n"
cadversion:     .asciiz "\n¿Qué versión de la función desea utilizar para calcular si su cadena es palíndroma o no?\n"
cadversion2:    .asciiz "<0> La versión recursiva, <1> la versión iterativa: "
cadfin:         .asciiz "\n FIN DEL PROGRAMA "
	.text

strlen:  # numero de caracteres que tiene una cadena sin considerar el '\0'
		 # la cadena tiene que estar terminada en '\0'
		 # $a0 tiene la direccion de la cadena
		 # $v0 devuelve el numero de caracteres

         li $v0,0 #iniciliazamos el número de carácteres a cero

         bucle1:
                 li $t0,0 #iterador                 
                 lb $t0,0($a0)
                 beq $t0,0, finstrlen #leemos cada elemento, si este no es cero el bucle sigue avanzando
                 addi $v0,1 #sumamos 1 al tamaño de caracteres cada vez que leamos un elemento
                 addi $a0,size # y vamos recorriendo la cadena incrementando su valor en "size= 1 byte"
                 j bucle1 
         finstrlen:  
                 jr $ra #return
                 

		 
reverse_i:  # funcion que da la vuelta a una cadena
			# $a0 cadena a la que hay que dar la vuelta
			# $a1 numero de caracternes que tiene la cadena
			# $v0 1 Si es palíndroma 0 si no lo es

	    li $v0,1 #partimos de que sí que es palíndroma
            
            li $t4,2
            div $a1,$t4
            mflo $t7 #top de nuestro iterador
            
            sub $t4,$a1,size
            add $t2,$a0,$t4 #$t2 tiene la direccion en memoria de la última letra de la palabra/frase

            li $t3,0 #iterador i
            
         buclei:
                lb $t0,0($a0)
                lb $t1,0($t2)

                beq $t1,$t0,finbuclei #comparamos el elemento "i" con el "$a1-i"
                sb $t0,0($t2)
                sb $t1,0($a0)
                li $v0,0 # si no son iguales, los intercambiamos y pones un 0 en $v0

         finbuclei:              # si son iguales, solo seguimos recorriendo la cadena
                addi $a0,size
                sub $t2,$t2,size

         addi $t3,1
         blt $t3,$t7,buclei
           
         fin_reverse_i: jr $ra
				

reverse_r:  # funcion que da la vuelta a una cadena                       REVISAR!!!! LONKOL SALE PALINDROMA!!!!
			# $a0 cadena a la que hay que dar la vuelta
			# $a1 numero de caracteres que tiene la cadena
			# $v0 1 Si es palíndroma 0 si no lo es

#caso trivial:

	bge $a1,2,notrivial #si la cadena tiene una longitud menor que 2, será palíndroma
        li $v0,1 
        jr $ra		
			
#caso no trivial:

        notrivial:
                  #push
                        addi $sp,$sp,-8 #guardamos en la pila $ra y $a1(longitud cadena)
                        sw $ra,0($sp)
                        sw $a1,4($sp)                        
                        
                        sub $a1,$a1,2   #decrementamos el tamaño de cadena en 2 ya que vamos quitar todo el rato los extremos y los compararemos
                        add $a0,$a0,size #así pues también incrementamos la dirección en size
                        jal reverse_r

                  #pop
                        lw $ra,0($sp) #sacamos los elementos guardados de la pila
                        lw $a1,4($sp)
                        addi $sp,$sp,8
          #fin pop-push
                        sub $a0,$a0,size # $t0 = primer elemento de la sub_cadena generada 
                        lb $t0,0($a0)

                        sub $t4,$a1,size # $t1 = ultimo elemento de la sub_cadena generada
                        add $t2,$a0,$t4
                        lb $t1,0($t2)
                        
                        sb $t0,0($t2) #intercambiamos elementos
                        sb $t1,0($a0)            

                        bne $t1,$t0,nopalindroma_r #si son iguales solo salto a la sub_cadena de la que provino esta otra sub_cadena
                        j finreverse_r

          nopalindroma_r: li $v0,0   # si no son iguales cargo un 0 en $v0                                  

          finreverse_r: jr $ra #return
				

main:

#PRIMERA CADENA

#strlen			
      la $a0,cadena
      jal strlen    #llamamos a la función "strlen" con "$a0=cadena" como parametro
      move $s0,$v0  #$s0 contiene el número de carácteres
      
      la $a0,cadena #Imprimimos: "cadena" tiene "$s0" carácteres
      li $v0,4
      syscall
      la $a0,cadtiene
      li $v0,4
      syscall
      move $a0,$s0
      li $v0,1
      syscall
      la $a0,cadcarac
      li $v0,4
      syscall

#reverse_i
      la $a0,cadena
      move $a1,$s0
      jal reverse_i

      la $a0,cadena
      # $a0 cadena dada la vuelta
      # $v0 si es palindroma o no

      move $s1,$v0 # $s1 = si es palíndroma o no

      li $v0,4 #Imprimimos: "cadena(invertida)" tiene "$s0" carácteres
      syscall
      la $a0,cadtiene
      li $v0,4
      syscall
      move $a0,$s0
      li $v0,1
      syscall
      la $a0,cadcarac
      li $v0,4
      syscall

      beq $s1,1,palindroma1 #Si $s1=1 --> es palíndroma
      la $a0,cadnoespal #la cadena no es palindroma
      li $v0,4
      syscall
      j fin1

palindroma1:

       la $a0,cadespal #la cadena no es palindroma
       li $v0,4
       syscall
fin1:

#SEGUNDA CADENA

#strlen			
      la $a0,cadena2
      jal strlen    #llamamos a la función "strlen" con "$a0=cadena2" como parametro
      move $s0,$v0  #$s0 contiene el número de carácteres
      
      la $a0,cadena2 #Imprimimos: "cadena2" tiene "$s0" carácteres
      li $v0,4
      syscall
      la $a0,cadtiene
      li $v0,4
      syscall
      move $a0,$s0
      li $v0,1
      syscall
      la $a0,cadcarac
      li $v0,4
      syscall
	
#reverse_r
      la $a0,cadena2
      move $a1,$s0
      jal reverse_r

      # $a0 cadena dada la vuelta
      # $v0 si es palindroma o no

      move $s1,$v0 # $s1 = si es palíndroma o no

      li $v0,4 #Imprimimos: "cadena2(invertida)" tiene "$s0" carácteres
      syscall
      la $a0,cadtiene
      li $v0,4
      syscall
      move $a0,$s0
      li $v0,1
      syscall
      la $a0,cadcarac
      li $v0,4
      syscall

      beq $s1,1,palindroma2 #Si $s1=1 --> es palíndroma
      la $a0,cadnoespal #la cadena es palindroma
      li $v0,4
      syscall
      j fin2

palindroma2:

       la $a0,cadespal #la cadena no es palindroma
       li $v0,4
       syscall
fin2:      

#MODIFICACIÓN: Pedir frase/palabra por teclado

 la $a0,cadnueva
 li $v0,4
 syscall

bucle_opcion:

 la $a0,cadopcion
 li $v0,4
 syscall

 li $v0,5 #leo la opción
 syscall

 blt $v0,0,bucle_opcion
 bgt $v0,1,bucle_opcion

 beq $v0,0,fin_del_programa

 la $a0,cadintroduzca
 li $v0,4
 syscall

 li $v0,8
 syscall # $a0 = dirección de memoria donde se almacena la cadena leída
 move $s4,$a0 #movemos la cadena a $s4 para no perderla

#strlen

 jal strlen
 sub $s2,$v0,1 #$s2 = numero de carácteres -1 (ya que lee el "Enter" también)

 move $a0,$s4
 li $v0,4 #Imprimimos la cadena
 syscall

 la $a0,cadtiene #Imprimimos: "...tiene $s2 carácteres"
 li $v0,4  
 syscall
 move $a0,$s2
 li $v0,1
 syscall
 la $a0,cadcarac
 li $v0,4
 syscall


#version iterativa o recursiva?

 la $a0,cadversion
 li $v0,4
 syscall

bucle_version:

 la $a0,cadversion2
 li $v0,4
 syscall

 li $v0,5 #leo la opción
 syscall

 blt $v0,0,bucle_version
 bgt $v0,1,bucle_version

 beq $v0,1,version_iterativa

 
#reverse_r:
       move $a0,$s4
       move $a1,$s2
       jal reverse_r

      # $a0 cadena dada la vuelta
      # $v0 si es palindroma o no

      move $s1,$v0 # $s1 = si es palíndroma o no

      li $v0,4 #Imprimimos: "cadena2(invertida)" tiene "$s2" carácteres
      syscall
      la $a0,cadtiene
      li $v0,4
      syscall
      move $a0,$s2
      li $v0,1
      syscall
      la $a0,cadcarac
      li $v0,4
      syscall

      beq $s1,1,palindroma3 #Si $s1=1 --> es palíndroma
      la $a0,cadnoespal #la cadena es palindroma
      li $v0,4
      syscall
      j fin3

palindroma3:

       la $a0,cadespal #la cadena no es palindroma
       li $v0,4
       syscall
fin3:  
       j fin_del_programa    


#reverse_i
version_iterativa:
      move $a0,$s4
      move $a1,$s2
      jal reverse_i

      # $s4 cadena dada la vuelta
      # $v0 si es palindroma o no

      move $s1,$v0 # $s1 = si es palíndroma o no

      move $a0,$s4
      li $v0,4 #Imprimimos: "cadena(invertida)" tiene "$s2" carácteres
      syscall
      la $a0,cadtiene
      li $v0,4
      syscall
      move $a0,$s2
      li $v0,1
      syscall
      la $a0,cadcarac
      li $v0,4
      syscall

      beq $s1,1,palindroma4 #Si $s1=1 --> es palíndroma
      la $a0,cadnoespal #la cadena no es palindroma
      li $v0,4
      syscall
      j fin4

palindroma4:

       la $a0,cadespal #la cadena no es palindroma
       li $v0,4
       syscall
fin4:

#Fin del programa

fin_del_programa:  la $a0,cadfin
                   li $v0,4
                   syscall

                   li $v0,10
                   syscall
       





