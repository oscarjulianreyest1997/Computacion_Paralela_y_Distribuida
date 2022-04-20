#!/usr/bin/perl
#   Fehca: 20/04/2022
#   Autor::Oscar Julian Reyes Torres.
#   Asignatura: Computación Paralela y distributiva.

$PATH = `pwd`;
chomp($PATH);
print("Source: ".$PATH. "\n\n");

#Variable que representa el número de repeticiones de cada archivo ejecutable  
$N = 36;
#Vector of executable benchmarks
@ejecutables = ("MMPosix", "MM1cOMP","MM1fOMP");

#Vector NxN para matriz
@matrix_size = ("100","800","1600","2400","3200");
#Subprocesos vectoriales para ejecutar
@threadsN = ("1","2","4");

foreach $exe (@ejecutables){
    foreach $size (@matrix_size){
        foreach $thread (@threadsN){
            $file = "$PATH/"."registros/"."$exe"."-$size"."-$thread".".txt";
            #print($file."\n");
            for ($i = 0; $i < $N; $i++){
                #print("$PATH/$exe $size $thread \n");
                system "$PATH/$exe $size $thread >> $file";
            }
            close $file; 
        }
    }
}
exit(0);

# To make this file executable
#   chmod +x launcher.pl