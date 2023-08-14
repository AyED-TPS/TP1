# Datos

Información sobre qué infomación tenemos.

## Especialidades

Maximo: 20.

## Medicos

Maximo: 60.
Cantidad: Max. de Especialidades x 3.
Es una trampa que los medicos sean 100 maximo, porque en realidad con un maximo de 20 especialidades podemos maximizar 60 medicos... porque "Para todo médico un solo turno y todos los días." **Y** 24 turnos en total por dia. Esta ultima parte es fundmental porque podriamos decir que puede haber 4 medicos por especialidad ya que hay tres por turno (tres) y el otro faltante puede estar en otro mismo turno que otro pero atender a las personas en consultorios diferentes... pero no, porque sino se podrian atender a 16 personas por turno cuando solo se puede atender 8 porque cuadraria

8+8+8 = 24 turnos en total

invalidando la teoria de que puede haber mas de tres medicos por especialidad.

Hay tres medicos por especialidad.

## Restricciones de los datos

Estas aclaraciones son aclaraciones, no es para integrarle un sistema de validación.

1. Todos los archivos deben tener los datos desordenados.

## Turnos

1. Cada dia, por especialidad, no puede tener más de 24 turnos. En total, el maximo de turnos son 31x24x20 porque son 24 turnos que pueden entrar en la franja horaria (8:00 a 19;30 con 30' de sesion), pero este intervalo son los horarios de disponibilidad de un medico, y un medico es de una especialidad, entonces esta cantidad de turnos (24) es correspondiente por especialidad y hay 20 especialidades, entonces 20x24, pero falta algo mas, porque este intervalo de horario es correspondiente por dia, entonces falta multiplicar esta cantidad de turnos por especialidad por los 31 dias.

2. Cada turno debe estar entre 8:00 a 19:30

3. Cada turno debe ocupar 30' de tiempo.

### TurnosDiaHora.Txt

- Debe tener turnos de días previos al actual.
- La especialidad  debe pertener a las especialidades de Especialidades.Txt

### SolicitudTurnos.Txt

- Este archivo contiene los turnos de 1(un) dia. entonces como maximo puede tener 20x24x1 turnos, porque puede haber 24 turnos por especialidad en un dia.

### Dia establecido actual

Es 17. Es decir SolicitudTurnos.Txt debe tener todos los turnos en dia 17.
Luego TurnosDiaHora.Txt dias previos al 17 [1; 16].

## Medicos.Txt

- La especialidad de los médicos debe pertener a las especialidades de Especialidades.Txt
- Para todo médico: un turno y todos los días.
- Debe haber tres medicos por especialidad. Para que haya un medico por cada turno de cada especialidad
