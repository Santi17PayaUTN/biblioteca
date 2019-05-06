#include <stdio.h>
#include <stdlib.h>
#define LIBRE 0
#define OCUPADO 1
#define INHABILITADO 2
#define SOLUCIONADO 0
#define NOSOLUCUINADO 1
#define CURSO 2
#define FALLA3G 0
#define FALLALTE 1
#define FALLAEQUIPO 2
#define SINPROBLEMAS 3
typedef struct
{
    int legajo;
    char nombre[20];
    char sexo;
    float sueldoBruto;
    float sueldoNeto;
    int estado;
} eEmpleado;
typedef struct
{   char nombre[20];
    float precio;
    int stock;

    int estado;
} eObjeto;
typedef struct
{   int identificacion;
    float numeroTelefonico;
    char nombre[20];
    char apellido[20];
    int tipoDeProblema;
    int estadoProblema;
    int estadoEspacio;
} eAbonados;
int pediryDevolverEntero (char[]);
float pediryDevolverFloat (char[]);
char pediryDevolverChar(char[]);
void cargarSujetoObjeto(eAbonados[], int);
int textoMenuDeOpciones(char[]);
void mostrarSujetosObjetos(eAbonados[], int);
void mostrarSujetoObjeto(eAbonados);
int buscarLibre(eAbonados[], int);
void inicializarEstructura(eAbonados[], int);
void hardcodearDatos(eAbonados[], int);
void modificarDatos(eAbonados[],int);
void MenuOpciones(eAbonados[],int);
