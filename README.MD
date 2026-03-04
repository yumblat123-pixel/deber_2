Nombre completo del estudiante: Thiago Yumbla

Curso o paralelo: CMP 1101 NRC 2684



El ejercicio consiste en desarrollar un programa en C++ que realiza conversiones de divisas.

El sistema permite al usuario elegir entre dos modos de operación:

Operación Continua: permite realizar múltiples conversiones ingresando los datos en cada iteración.

Operación por Sesión: permite fijar una tasa de cambio y realizar varias conversiones acumulando estadísticas como total, promedio, mínimo y máximo.

El programa valida que:

Los códigos de divisa tengan exactamente 3 letras.

La tasa sea mayor que 0.

El monto sea mayor que 0.

El sistema funciona mediante un menú principal repetitivo hasta que el usuario decide salir.

El programa inicia mostrando un menú con tres opciones:

Operación Continua

Operación por Sesión

Salir

El menú se repite hasta que el usuario elige la opción 3.

2️: Operación Continua

En este modo:

Se piden:

Divisa base

Divisa cotizada

Tasa de cambio

Monto a convertir

Se valida cada dato.

Se calcula:

convertido = monto × tasa

Se muestran los resultados.

Se pregunta si desea hacer otra conversión.

Si responde "sí", el proceso se repite.

Si responde "no", vuelve al menú principal.
No se guardan estadísticas en este modo.

3️: Operación por Sesión

En este modo:

Se ingresan una sola vez:

Divisa base

Divisa cotizada

Tasa

Luego comienza un ciclo donde:

El usuario ingresa montos sucesivos.

Puede escribir "q" para salir.

Cada monto válido:

Se convierte

Se acumula en totales

Se actualizan:

Contador

Total base

Total convertido

Mínimo

Máximo

Promedio

Al finalizar, el programa muestra un resumen final con todas las estadísticas de la sesión.
