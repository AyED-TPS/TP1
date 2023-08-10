# Solicitudes de Turnos Médicos

Este trabajo práctico es de la materia Algoritmos y Estructuras de Datos de la carrera de Ing. en Sistema de Información. Trata de un proceso que asigna turnos por servicios médicos según especialidad, día y turno (mañana, tarde o noche) de acuerdo a la solicitud de quien requiere el servicio.

## Funcionamiento

Este programa en lineas generales trata de la conversión de una estructura de datos a otras. En rigor descarga la información de archivos y las carga en estructuras de datos internas estaticas para el proceso computacional de los datos. Trata de un archivo maestro viejo, un archivo de novedades y luego un maestro nuevo. Justamente este tp consiste en la impresión de estos archivos en un único archivo. Ademas de estos archivos tenemos otros más para relacionar los datos entre los archivos con ED internas.

Estos son algunos temas que se tratan en el programa:

- Tratamiento de archivos (lectura y escritura)
- Estructuras de datos estáticas (arrays y struct)
- Métodos de ordenamiento
- Paradigma de programación Imperativo
- Paradigma de programación Estructurada
- Paradigma de programación Modular

En principio empezamos con los datos y los resultados junto con sugerencias/trampas de acciones a realizar para realizar el tp. Los datos o la Muestra de Datos habia que crearla:
Especialidades.Txt: Nombres de especialidades.
Medicos.Txt: Apellidos y nombres de medicos, su especialidad, turno y matricula.
TurnosDiaHora.Txt: Especialidad, dia, hora exacta, obra social y credencial.
SolicitudTurnos.Txt: Edad, Nombre y apellido del paciente, especialidad, obra social, credencial, nombre del medico, dia y turno (sin hora exacta).

El proyecto consiste en emitir en funcion de la muestra de datos:

1. Listado de las solicitudes previas al proceso, ordenado por Especialidades, Días y Turnos todos ascendentes. (Maestro Viejo)
2. Listado de las solicitudes actuales al proceso, ordenado cronológico de las transacciones. (Novedades)
3. Listado de las solicitudes actualizadas una vez finalizado el proceso de las solicitudes actuales, ordenado por Especialidades, Días y Turnos todos ascendentes. (Maestro Nuevo)

## Detalles

Lenguaje Empleado: C++

Compilador: [Borland C++ Compiler V5.5](https://jeremiascuello.000webhostapp.com/Tools/Borland%20C++%20V5.5%20Compiler.zip)

Editor usado: CodeBlocks. Empleado al proceso como archivo, no como proyecto de CodeBlocks (.cbs)
