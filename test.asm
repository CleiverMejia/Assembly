load a, 'H'
store a, 256
load a, 'e'
store a, 257
load a, 'l'
store a, 258
store a, 259
store a, 265
load a, 'o'
store a, 260
store a, 263
load a, ' '
store a, 261
load a, 'w'
store a, 262
load a, 'r'
store a, 264
load a, 'd'
store a, 266
load a, 10 # \n
store a, 267
load a, 4 # Sys_write
load b, 1 # Stdout
load c, 256 # Puntero de donde incia el texto
load d, 12 # Longitud del texto
sys # Syscall (Ejecutar)
half # Terminar el proceso
