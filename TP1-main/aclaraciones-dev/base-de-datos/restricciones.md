# Restricciones de los datos

Este archivo es para saber cuales son las restricciones, no es para integrarle un sistema de validación.

1. Todos los archivos deben tener los datos desordenados.

## Turnos

1. Cada dia no puede tener más de 24 turnos.
2. Cada turno debe estar entre 08:00 a 19:30
3. Cada turno debe ocupar 30' de tiempo.

### TurnosDiaHora.Txt

- Debe tener turnos de días previos al actual.
- La especialidad  debe pertener a las especialidades de Especialidades.Txt

### SolicitudTurnos.Txt

- Debe tener maximo 24 turnos del día actual.

## Medicos.Txt

- La especialidad de los médicos debe pertener a las especialidades de Especialidades.Txt
- Turno = { M || T || N }
- Para todo médico: un turno y todos los días.
- Debe haber tres medicos por especialidad como minimo. Para que haya un medico por cada turno de cada especialidad
  - La cantidad minima de medicos es el triple de la cantidad de especialidades.
