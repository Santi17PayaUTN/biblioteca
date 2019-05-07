#include "BibliotecaFuncionesBasicas.h"

int pediryDevolverEntero(char texto[])
{
    int numeroIngresado;
    printf("%s", texto);
    scanf("%d", &numeroIngresado);

    return numeroIngresado;
}

float pediryDevolverFloat(char texto[])
{
    float numeroIngresado;
    printf("%s", texto);
    scanf("%f", &numeroIngresado);
    return numeroIngresado;
}
char pediryDevolverChar(char texto[])
{
    char letraIngresada;
    printf("%s", texto);
    scanf("%c", &letraIngresada);
    return letraIngresada;
}
void cargarSujetoObjeto(eAbonados lista[], int tam)
{
    int i;

    i = buscarLibre(lista, tam);
    if(i!=-1)
    {
        printf("Ingrese numero telefonico: ");
        scanf("%f", &lista[i].numeroTelefonico);
        printf("Ingrese nombre: ");
        fflush(stdin);
        gets(lista[i].nombre);
        printf("Ingrese apellido: ");
        fflush(stdin);
        gets(lista[i].apellido);

        lista[i].identificacion = i+1;
        lista[i].tipoDeProblema = SINPROBLEMAS;
        lista[i].estadoProblema = SOLUCIONADO;
        lista[i].estadoEspacio = OCUPADO;

    }
    else
    {
        printf("No hay espacio");
    }
}
int textoMenuDeOpciones(char mensaje[])
{
    int opcion;
    printf("%s", mensaje);
    scanf("%d", &opcion);

    return opcion;
}


void mostrarSujetosObjetos(eAbonados lista[], int tam)
{
    int i;
    for(i=0; i<tam; i++)
    {
        if(lista[i].estadoEspacio!=LIBRE)
        {
            mostrarSujetoObjeto(lista[i]);
        }

    }
}
void mostrarSujetoObjeto(eAbonados unAbonado)
{
    printf("%d- %f - %s - %s \n", unAbonado.identificacion,unAbonado.numeroTelefonico,unAbonado.nombre,unAbonado.apellido);

}
int buscarLibre(eAbonados lista[], int tam)
{
    int i;
    int index=-1;
    for(i=0; i<tam; i++)
    {
        if(lista[i].estadoEspacio==LIBRE)
        {
            index = i;
            break;
        }
    }
    return index;
}
void inicializarEstructura(eAbonados lista[], int tam)
{
    int i;
    for(i=0; i<tam; i++)
    {
        lista[i].estadoEspacio = LIBRE;
    }
}

void hardcodearDatos(eAbonados lista[], int tam)
{
    int i;
    int identificaciones[]= {1,2,3,4,5,6};
    char nombres[][50]= {"Maria","Pedro","Jose","Pedro","Pablo","Mateo"};
    char apellidos[][50]= {"Juarez","Miranda","Albornoz","Urquiza","Velez","Jorge"};
    float telefonos[]= {1000,2000,3000,4000,5000,6000};

    for(i=0; i<tam; i++)
    {
        lista[i].identificacion = identificaciones[i];
        strcpy(lista[i].nombre, nombres[i]);
        strcpy(lista[i].apellido, apellidos[i]);
        lista[i].numeroTelefonico=telefonos[i];
        lista[i].tipoDeProblema = SINPROBLEMAS;
        lista[i].estadoProblema = SOLUCIONADO;
        lista[i].estadoEspacio = OCUPADO;

    }
}
void modificarDatos(eAbonados lista[],int tam)
{
    int i;
    int identificaciones;
    int opcion;
    char nombreNuevo[20];
    char apellidoNuevo[20];
    float numeroTelefonicoNuevo;
    float sueldoNetoNuevo;
    int flag=0;

    printf("Ingrese la identificacion del abonado: ");
    fflush(stdin);
    scanf("%d",&identificaciones);
    for(i=0; i<tam; i++)
    {
        if(lista[i].identificacion==identificaciones)
        {
            flag=1;
            opcion= textoMenuDeOpciones("1_Cambiar nombre\n 2_Cambiar apellido\n 3_Cambiar numero telefonico\n Elija una opcion: ");
            switch(opcion)
            {
            case 1:
                printf("Reingrese el nombre: ");
                fflush(stdin);
                scanf("%s",nombreNuevo);
                strcpy(lista[i].nombre, nombreNuevo);
                break;
            case 2:
                printf("Reingrese el apellido: ");
                scanf("%s", apellidoNuevo);
                strcpy(lista[i].apellido, apellidoNuevo);
                break;
            case 3:
                printf("Reingrese el numero telefonico: ");
                scanf("%f", &numeroTelefonicoNuevo);
                lista[i].numeroTelefonico= numeroTelefonicoNuevo;

                break;

            }
        }
    }
    if(flag==0)
    {
        printf("No se encontro ninguna coincidencia\n");

    }
}
void MenuOpciones(eAbonados lista[],int tam)
{
    int opcion;
    do
    {
        opcion = textoMenuDeOpciones("1.Alta\n2.Baja\n3.Modificar\n4.Mostrar\n5.Salir\nElija una opcion: ");
        switch(opcion)
        {
        case 1:
            cargarSujetoObjeto(lista,  tam);

            break;
        case 3:
            modificarDatos(lista,tam);
            break;
        case 4:
            mostrarSujetosObjetos(lista, tam);
            break;

        }
    }
    while(opcion!=5);


}
void cargaAleatoriaSujetoObjeto()
{
    int j[5],pos;
    char seguir;
    do
    {
        printf("Ingrese legajo");
        scanf("%d",&pos);
        printf("Ingrese");
        scanf("%d",&j[pos]);
        printf("¿Desea ingresar otro dato S/N?\n");
        scanf("%c",&seguir);
    }
    while(seguir=='s');
}
int buscarMayor(eEstructura nombre, int tam)
{   int mayor=nombre[0];
        for(i=0;i<tam;i++)
        {
            if(nombre[i]>mayor)
            {
                mayor=vec[i];
            }
        }
}
int buscarEnElVector (eEstructura nombre, int tam)
{   int num;
    flag=0;
    printf("Ingrese numero a buscar");
    scanf("%d",&num);
    for(i=0; i<tam; i++)
    {
        if(num==nombre[i])
        {
            printf("Se encontro el numero en la posicion %d", nombre[i].identificacion);
            flag=1;
        }
    }
    if(flag==0)
        printf("El numero no se encontro");

}
void insertarNumero(int listaNumeros[],int tam)
{   int i,j;
    int temp;
    for(i=1;i<tam;i++)
    {
        temp = listaNumeros[i];
        j=i-1;
        while(temp<listaNumeros[j] && j>=0)
        {
            listaNumeros[j+1] = listaNumeros[j];
            j--;
        }
        listaNumeros[j+1]=temp;
    }

}
