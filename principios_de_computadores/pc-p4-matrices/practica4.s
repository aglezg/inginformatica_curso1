
#PRACTICA 4: Trabajando con matrices
#Trabajo realizado por: Adrián González Galván del Grupo 2 de Tarde

size = 4 #bytes que ocupa cada elemento
tamax = 400 #numero de bytes máximo que tendría la matriz personalizada

   .data
titulo:       .asciiz "Práctica 4. Trabajando con Matrices\n"
msgopcion:    .asciiz "Elija opción <0> Salir, <1> invertir fila, <2> invertir columna: "
msgfila1:     .asciiz "Seleccione fila ["
msgfila2:     .asciiz ","
msgfila3:     .asciiz "]: "
msgcolumna1:  .asciiz "Seleccione colummna ["
espacio:      .asciiz " "
enter:        .asciiz "\n"

matriz_personalizada: .asciiz "¿Desea usar una matriz personalizada? <1> Sí, <0> No: "
msg_filas_mp:         .asciiz "Introduce el número de filas de tu matriz: "
msg_col_mp:           .asciiz "Introduce el número de columnas: "
msg_intro_mp:         .asciiz "Introduzca los valores de su nueva matriz:\n"
corchete_abierto:     .asciiz "["
matriz_generada:      .asciiz "Su matriz ha sido generada correctamente, el resultado es:\n"
#Matriz en memoria:

matrix: .word 11, 12, 13 
        .word 21, 22, 23
        .word 31, 32, 33
        .word 41, 42, 43
        .space tamax #reservo 400 bytes para una posible matriz personalizada

nrows: .word 4 #filas
ncols: .word 3 #columnas

   .text

main:

#INICIALIZACION

        la $a0,titulo
        li $v0, 4
        syscall #imprimo "Practica 4. Trabajando con Matrices\n"        
        
        lw $s0,nrows #topes
        lw $s1,ncols
        
        li $t6,2

#MUESTRO LA MATRIZ POR PANTALLA

do_while: #bucle principal (se desarrolla más abajo)

        li $t0, 0  #iterador filas

        la $s2, matrix # $s2 primera dirección en memoria de la matriz


for_1:  li $t1, 0  #iterador columnas
        
for_2:  
          lw $a0, 0($s2) #elemento 0 de la matriz en $a0
          li $v0,1
          syscall        #mostramos por pantalla el elemento
          addi,$s2, size #desplazamos la base
  
          la $a0, espacio #imprimo espacios para separar los elementos de cada fila
          li $v0,4
          syscall
  
          add $t1,$t1, 1
          blt $t1,$s1, for_2 #$t1++
  
          la $a0, enter #imprimo un "salto de linea" para separar los elementos de cada columna
          li $v0,4
          syscall
  
          add $t0,$t0, 1     #$t0++
          blt $t0,$s0, for_1
          
          beq $t6,0,do_while_opcion #Si el usuario ha tecleado anteriormente que no desea usar la matriz personalizada
          beq $t6,1,do_while_opcion #o que ya la había cambiado anteriormente, saltamos directamente al "bucle de opcion"

matriz_usuario: la $a0, matriz_personalizada #muestro "¿Desea usar una matriz personalizada? <1> Sí, <0> No: "
                li $v0,4
                syscall
           
                li $v0,5 #leo la opción
                syscall

                blt $v0,0,matriz_usuario #si opcion<0 --> salta
                bgt $v0,1,matriz_usuario #si opcion>1 --> salta
                
                move $t6,$v0
                beq $t6,0,do_while_opcion #opcion=0 --> sigo con la matriz en memoria
                beq $t6,1,cambio_matriz   #opcion=1 --> Cambio la matriz por una que me pida el usuario (la etiqueta se encuentra al final)


#BUCLE DE OPCION

do_while_opcion:    la $a0, msgopcion #muestro "Elija opción <0> Salir, <1> invertir fila, <2> invertir columna: "
                    li $v0, 4
                    syscall
                    
                    li $v0,5 #leo el entero de la opción
                    syscall
                    blt $v0,0,do_while_opcion
                    bgt $v0,2,do_while_opcion

                    move $s3,$v0 #guardamos en $s3 la opción elegida                    

#BUCLE PRINCIPAL

        beq $s3,0,fin #if opcion=0, salimos del bucle principal (finalizamos programa)
        
        beq $s3,2,opcion_2 #if opcion=2 saltamos a la etiqueta "opcion_2" para cambiar de orden una columna

#Opcion 1: invertir fila

while_1: la $a0,msgfila1 #imprimo por pantalla "Seleccione fila ["
         li $v0, 4
         syscall
 
         li $a0,1        #imprimo un '1'
         li $v0,1
         syscall
 
         la $a0,msgfila2 #imprimo ","
         li $v0,4
         syscall
 
         lw $a0,nrows    #imprimo "nrows"=4 para la matriz en memoria
         li $v0,1
         syscall
 
         la $a0,msgfila3 #imprimo "]: "
         li $v0,4
         syscall
 
         li $v0,5 #leo un entero 
         syscall

         lw  $a0,nrows       #uso temporalmente $a0 para guardar "nrows" y establecer el bucle
         blt $v0,1,while_1   #si $v0<1 saltará de nuevo al bucle
         bgt $v0,$a0,while_1 #si $v0>nrows saltará también de nuevo al bucle

#Modifiquemos ahora la matriz dado a la fila correspondiente

         sub $s4,$v0,1       #guardo en $s4 la fila elegida (restándole '1' ya que los vectores van de 0 a 'n') 
         mul $s4,$s4,$s1
         mul $s4,$s4,size    # $s4 = (fila-1)*ncols*size = número de bytes a desplazar para el 1º elemento de la fila

         sub $s5,$s1,1
         mul $s5,$s5,size
         add $s5,$s5,$s4     # $s5 = (fila-1)*ncols*size + (ncols-1)*size = número de bytes a desplazar para el último elemento de la fila
        

         lw $t3,ncols
         sub $t3,$t3,1 
         div $t3,$t3,2 # $t3 = tope del iterador "for_opcion_1" = (ncols-1)/2

         li $t1, 0 #iterador por columnas
         
         la $s2, matrix
         add $s4,$s2,$s4 # $s4 = direccion base de la matriz ($s2) + desplazamiento en bytes del primer elemento de la fila elegida
         add $s5,$s2,$s5 # $s5 = direccion base de la matriz ($s2) + desplazamiento en bytes del ultimo elemento de la fila elegida

for_opcion_1:
              lw $t2, 0($s4) #$t2= primer elemento de la fila elegida
              lw $t4, 0($s5) #$t4= ultimo elemento de la fila elegida
              
              sw $t4, 0($s4) #altero el orden de los elementos de la matriz 
              sw $t2, 0($s5)

              addi $s4, size     #incremento la posición de memoria del primer elemento de la fila en 4 bytes para ir al siguiente a cambiar 
              sub $s5, $s5, size #hago lo mismo por el otro lado, pero decrementando en este caso
              
              addi $t1,1
              ble $t1,$t3,for_opcion_1 #if $t1<=(ncols-1) --> salta a "for_opcion_1"

         j fin #fin de la opcion 1 --> Nos vamos de vuelta al bucle do_while principal
        

#Opcion 2: invertir columna
opcion_2:

while_2: la $a0,msgcolumna1 #imprimo por pantalla "Seleccione columna ["
         li $v0, 4
         syscall
 
         li $a0,1        #imprimo un '1'
         li $v0,1
         syscall
 
         la $a0,msgfila2 #imprimo ","
         li $v0,4
         syscall
 
         lw $a0,ncols    #imprimo "ncols"=3 para la matriz en memoria
         li $v0,1
         syscall
 
         la $a0,msgfila3 #imprimo "]: "
         li $v0,4
         syscall
 
         li $v0,5 #leo un entero 
         syscall

         lw  $a0,ncols       #uso temporalmente $a0 para guardar "ncols" y establecer el bucle
         blt $v0,1,while_2   #si $v0<1 saltará de nuevo al bucle
         bgt $v0,$a0,while_2 #si $v0>ncols saltará también de nuevo al bucle

#Modifiquemos ahora la matriz dado a la columna correspondiente

         sub $s4,$v0,1       #guardo en $s4 la columna elegida (restándole '1' ya que los vectores van de 0 a 'n') 
         mul $s4,$s4,size    # $s4 = (columna-1)*size = número de bytes a desplazar para el 1º elemento de la columna elegida

         sub $s5,$s0,1
         mul $s5,$s5,$s1
         mul $s5,$s5,size
         add $s5,$s5,$s4    # $s5 = (columna-1)*size + (nrows-1)*ncols*size = número de bytes a desplazar para el último elemento de la columna elegida

         lw $t3,nrows
         sub $t3,$t3,1
         div $t3,$t3,2 # $t3 = tope del iterador "for_opcion_2" = (nrows-1)/2

         
         li $t0, 0 #iterador por filas

         la $s2, matrix
         add $s4,$s2,$s4 # $s4 = direccion base de la matriz ($s2) + desplazamiento en bytes del primer elemento de la columna elegida
         add $s5,$s2,$s5 # $s5 = direccion base de la matriz ($s2) + desplazamiento en bytes del ultimo elemento de la columna elegida

for_opcion_2:
              lw $t2, 0($s4) #$t2= primer elemento de la columna elegida
              lw $t4, 0($s5) #$t4= ultimo elemento de la columna elegida
              
              sw $t4, 0($s4) #altero el orden de los elementos extremos de la columna elegida de la matriz
              sw $t2, 0($s5)

              mul $t5,$s1,size # $t5 = (ncols * size) = número de bytes a sumar o restar para posicionarte en el siguiente o anterior elemento de la columna

              add $s4,$s4,$t5   #sumamos $t5 a $s4 para avanzar al siguiente elemento de la columna elegida
              sub $s5, $s5, $t5 #restamos $t5 a $s5 para retrocoder al anterior elemento de la columna elegida
              
              addi $t0,1
              ble $t0,$t3,for_opcion_2 #if $t0<=(nrows-1) --> salta a "for_opcion_2"
         

#FIN DEL BUCLE PRINCIPAL

fin:    bne $s3,0,do_while #fin del bucle principal --> si $s3=0 <salir>
         

#SALGO DEL PROGRAMA

             li     $v0,10
             syscall #finalizo el programa (exit, return 0)

#CAMBIO DE MATRIZ

cambio_matriz:

#Pidamos primero el número de filas y columnas de la nueva matriz:             
 
bucle_tamax:  
             la $a0,msg_filas_mp #Imprimo "Introduce el número de filas de tu matriz: "
             li $v0,4
             syscall

             li $v0,5
             syscall
             move $s0,$v0 #leo el número de filas y compruebo que sea mayor que cero
             ble $s0,0,bucle_tamax
             sw $s0, nrows #cambio nrows por el nuevo número de filas

bucle_tamax_2:
             la $a0, msg_col_mp #Imprimo "Introduce el número de columnas:"
             li $v0,4
             syscall

             li $v0,5
             syscall
             move $s1,$v0 #leo el número de columnas y compruebo que sea mayor que cero
             ble $s1,0,bucle_tamax_2
             sw $s1, ncols #cambio ncols por el nuevo número de columnas

             mul $t7, $s0, $s1 #$t7= numero de elementos de la matriz
             mul $t7, $t7, size # $t7 = numero en bytes que ocupan los elementos de la matriz
             bgt $t7,tamax,bucle_tamax
             
#Rellenemos ahora la nueva matriz

             la $s2, matrix

             li $t0, 0  #iterador filas
             
             la $a0,msg_intro_mp #Imprimo "Introduzca los valores de su nueva matriz:\n"
             li $v0,4
             syscall            

bucle_relleno: li $t1,0 #iterador columnas
                             
bucle_relleno2:
               
               la $a0,corchete_abierto #Imprimo "["
               li $v0,4
               syscall

               add $t8,$t0,1
               move $a0,$t8 #Imprimo $t0+1 (supuesto iterador "i")
               li $v0,1
               syscall

               la $a0,msgfila2 #imprimo ","
               li $v0,4
               syscall

               add $t9,$t1,1
               move $a0,$t9 #Imprimo $t1+1 (supuesto iterador "j")
               li $v0,1
               syscall
             
               la $a0,msgfila3 #imprimo "]: "
               li $v0,4
               syscall                 
               
               li $v0,5 #leo el valor escrito
               syscall

               sw $v0,0($s2) # almaceno dicho valor en la posición "i,j" de la matriz
               addi $s2, size  #incremento 4 bytes para seguir rellenando la matriz     
               
               addi $t1,1
               blt $t1,$s1,bucle_relleno2 #bucle j
               
              addi $t0,1
              blt $t0,$s0,bucle_relleno #bucle i

               la $a0,matriz_generada #Imprimo "Su matriz ha sido generada correctamente, el resultado es:\n"
               li $v0,4
               syscall

             j do_while #fin de la transformacion, volvemos de nuevo al menú


