# Multiplicacion de Matrices haciendo uso de hilos :arrow_down: :arrow_up:

## Modulo con función MM usando Pthreads haciendo uso del lenguaje de programación C, que realiza la multiplicación de matrices cuadradas NxN utilizando hilos, con el fin de optimizar tiempo de ejecución en un determinado nodo de cómputo al hacer uso de todos o algunos Cores del procesador. :computer:

## :warning: Para una correcta verificación se hace necesario seguir los siguientes pasos:

### Paso 1: Descargar la totalidad de archivos en este repositorio :floppy_disk: 
```ruby
https://github.com/oscarjulianreyest1997/Computacion_Paralela_y_Distribuida/tree/main/2do_Corte/Entorno%20y%20Benchmark/3.%20PorgramaSinVarGlobMMmulti
```

### Paso 2: Desde la terminar de cualquier distribución de linux y ubicándonos en la carpeta que contiene los archivos previamente descargados, escribimos el siguiente comando para compilar :white_check_mark:
```ruby
user@user:~$ make MMPosix
```

### Paso 3: Ejecutamos con el siguiente comando, el cual se hace necesario incluir los argumentos en el estricto orden de tamaño de matriz y numero de hilos :watch:
```ruby
user@user:~$./MMPosix <tamaño de matriz> <numero de hilos>
```
### :bulb: Nota:

### - Si se desea eliminar los objetos creados basta con usar el comando
```ruby
user@user:~$ make clean
```

### - Comandos para instalar el compilador de c, c++
```ruby
user@user:~$sudo apt install make
user@user:~$sudo apt install gcc
```


