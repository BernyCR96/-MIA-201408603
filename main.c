#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

struct particiones{
char status[10];
char tipo[50];
char fit[50];
int inicio;
int tamano;
char name[100];


}typedef PART;

struct extendida{
int status;
char fit[50];
int inicio;
int tamano;
int next;
char name[100];


}typedef EBR;

struct mbr{
int tamano;
char time[100];
int id;
PART part_1;
PART part_2;
PART part_3;
PART part_4;
}typedef MBR;




void guardar(MBR disk, char* Archivo){
FILE* file = fopen(Archivo,"ab");
        if(Archivo ==NULL){
            printf("No se pudo acceder al archivo");

        }
        else{
            fwrite(&disk, sizeof(MBR),1,file);
            printf("contacto guardado");
            fclose(file);
        }
}

void Leer_entrada()
    {
    //    printf("ingrese la direccion: ");
      //  fgets(dir,200,stdin);
        char *token=NULL;


   static const char filename[] = "archivo.txt";
   FILE *file = fopen ( filename, "r" );
   if ( file != NULL )
   {
      char line [ 300];
      while ( fgets ( line, sizeof line, file ) != NULL ) /* lee la linea completa */
      {
           char dir[200];
        char nueva[200] = "";
        char coman[200] = "";
          printf("entre");
         fputs ( line, stdout ); /* escribe */

        token=strtok(line, " ");

        while(token!=NULL){
                if(strcasecmp(token, "mkdisk")== 0){
                    printf("Dato: %s \n", token);
                    strcpy(coman,token);
                    token=strtok(NULL," ");
                }
                else if(strcasecmp(token, "rmdisk")== 0){

                     printf("Dato: %s \n", token);
                     strcpy(coman,token);
                    token=strtok(NULL," ");


                }
                else if(strcasecmp(token, "fdisk")==0){
                        printf("Dato: %s \n", token);
                        strcpy(coman,token);
                        token=strtok(NULL," ");

                }
                else{
                    strcat(nueva,token);
                    strcat(nueva," ");
                    token=strtok(NULL," ");
                }
            }
            separar(coman,nueva);
            coman[200]="";
            nueva[200]="";
      }
      fclose(file);
   }
   else
   {
      perror ( filename ); /* why didn't the file open? */
   }



    }



void separar(char comando[200],char cadena[200]){
    char  tam[100]="";
    int bandera = 0;
    char pathnuevo[100] ="";
    char namenuevo[100] = "";
    char unidad[50] ="";
    char nuevo[50] ="";
    char nuevo1[50] ="";
    char nuevo2[50] ="";
    char tipo[50]="";
    char fit[50]="";
    char eliminar[50]="";
    char agregar[50]="";

    printf("\n*****%s",comando);
    printf("\n%s",cadena);

    if(strcasecmp(comando,"mkdisk")== 0){

    char *token1=NULL;
        char prueba[20] = " ";
        token1=strtok(cadena,prueba);
        printf("\n\n%s",cadena);
        while(token1!=NULL){
                strncpy(nuevo, &token1[0],7);
                printf("\n/////////%s",nuevo);
                if(strcasecmp(nuevo,"-path::")==0){

                    bandera = 1;
                }
                if(strcasecmp(nuevo,"-name::")==0){

                    bandera = 2;
                }
                if(strcasecmp(nuevo,"-size::")==0){

                    bandera = 3;
                }
                if(strcasecmp(nuevo,"+unit::")==0){

                    bandera = 4;
                }

                if(bandera == 1){



                        strcat(pathnuevo,token1);
                        strcat(pathnuevo," ");
                        //printf("-----%s",pathnuevo);
                        token1=strtok(NULL," ");



                    }



                    if(bandera == 2 ){
                        strcat(namenuevo,token1);
                        strcat(namenuevo," ");
                        //printf("-----%s",namenuevo);
                        token1=strtok(NULL," ");


                        }


                    if(bandera == 3){
                        //printf("entro");
                        //printf("Dato: %s \n", token1);
                        strcpy(tam,token1);
                        token1=strtok(NULL," ");

                    }
                    if (bandera == 4){
                            //printf("otro: %s \n", token1);
                            strcpy(unidad,token1);
                            token1=strtok(NULL," ");

                    }


                    }


            crear_disco(tam,unidad,pathnuevo,namenuevo);

            }

            else if(strcasecmp(comando,"rmdisk")== 0)
            {


        int a = 0;
        char *dire = cadena;

        char direcc[200]="";

        a = ("%d", strlen(dire));
        //printf("%d",a);
        strncpy(direcc, &dire[8],a-11);
        printf("\n------%s",direcc);
            remove(direcc);

            }

            else if(strcasecmp(comando, "fdisk")==0){

                char *token1=NULL;
                char prueba[20] = " ";
                token1=strtok(cadena,prueba);
                printf("\n\n%s",cadena);
                    while(token1!=NULL){
                        strncpy(nuevo, &token1[0],7);
                        strncpy(nuevo1, &token1[0],6);
                        strncpy(nuevo2, &token1[0],9);
                        //printf("\n/////////%s",nuevo);
                            if(strcasecmp(nuevo,"-path::")==0){

                                bandera = 1;
                                }
                                if(strcasecmp(nuevo,"-name::")==0){

                                    bandera = 2;
                                }
                                if(strcasecmp(nuevo,"-size::")==0){

                                bandera = 3;
                                }
                                if(strcasecmp(nuevo,"+unit::")==0){

                                bandera = 4;
                                }
                                 if(strcasecmp(nuevo,"+type::")==0){

                                        bandera = 5;
                                        }
                                        if(strcasecmp(nuevo1,"+fit::")==0){

                                        bandera = 6;
                                        }
                                        if(strcasecmp(nuevo2,"+delete::")==0){

                                        bandera = 7;
                                        }
                                        if(strcasecmp(nuevo1,"+add::")==0){

                                        bandera = 8;
                                            }


                                    if(bandera == 1){
                                        strcat(pathnuevo,token1);
                                        strcat(pathnuevo," ");
                                        //printf("-----%s",pathnuevo);
                                        token1=strtok(NULL," ");
                                        }
                                    if(bandera == 2 ){
                                        strcat(namenuevo,token1);
                                        strcat(namenuevo," ");
                                        //printf("-----%s",namenuevo);
                                        token1=strtok(NULL," ");
                                       }
                                    if(bandera == 3){
                                        //printf("entro");
                                        //printf("Dato: %s \n", token1);
                                        strcpy(tam,token1);
                                        token1=strtok(NULL," ");

                                        }
                                    if (bandera == 4){
                                        //printf("otro: %s \n", token1);
                                        strcpy(unidad,token1);
                                        token1=strtok(NULL," ");

                                        }
                                    if(bandera ==5){
                                        strcpy(tipo,token1);
                                        token1=strtok(NULL," ");

                                    }
                                    if(bandera == 6){
                                            printf("------------%s",token1);
                                        strcpy(fit,token1);
                                        token1=strtok(NULL," ");
                                    }
                                    if(bandera == 7){
                                        strcpy(agregar,token1);
                                        token1=strtok(NULL," ");
                                    }
                                    if(bandera == 8){
                                        strcpy(eliminar,token1);
                                        token1=strtok(NULL," ");
                                    }

                                }
                                agregar_particion(tam,unidad,pathnuevo,namenuevo,fit,agregar,eliminar,tipo);

                        }
}


void crear_disco(char* tam, char* unidad, char* path, char* nombre){



            printf("\n****%s",tam);
            printf("\n****%s",unidad);
            printf("\n****%s",path);
            printf("\n****%s",nombre);


        MBR disco;

        int tamano = 0;
        int t = 0;
        int a = 0;
        int b = 0;
        char *tama= tam;
        char *uni = unidad;
        char *dire = path;
        char *nom = nombre;


        char taman[150]="";
        char unit[150]="";
        char direcc[200]="";
        char direccion[200]="";
        char name[150]="";

        a = ("%d", strlen(dire));
        //printf("%d",a);
        strncpy(direcc, &dire[8],a-10);
        printf("\n------%s",direcc);

        strncpy(taman, &tama[7],sizeof(tama));
        //printf("\n%s", taman);
        tamano = atoi(taman);
        printf("\n------%d", tamano);

        strncpy(unit, &uni[7],sizeof(uni));
        printf("\n------%s",unit);

        b = ("%d", strlen(nom));
        strncpy(name, &nom[8],b-11);
        printf("\n------%s",name);

        strcat(direccion,direcc);
        strcat(direccion,name);
        printf("\n la direccion es: %s",direccion);


        mkdir(direcc,0777);
        FILE* file = fopen(direccion,"wb+");
        char llenar[1000]="\0";
        if(name ==NULL){
            printf("No se pudo acceder al archivo");

        }
        else{

                if(strcmp(unit,"k")==0){
                    for(int x = 0;x<tamano;x++){
                    fwrite(llenar,sizeof(llenar),1,file);
                }
                    t = tamano*1000;
                }
                else if(strcmp(unit,"M")==0){
                    for(int x = 0;x<(tamano*1000);x++){
                    fwrite(llenar,sizeof(llenar),1,file);
                }
                    t = tamano*1000*1000;
                }
                else{
                    for(int x = 0;x<tamano;x++){
                    fwrite(llenar,sizeof(llenar),1,file);
                }
                    t = tamano*1000;
                }



            time_t tiempo = time(0);
            struct tm *tlocal = localtime(&tiempo);
            char salida[100];
            strftime(salida,100,"%d/%m/%y %H:%M:%S",tlocal);
            strcpy(disco.time,salida);



            int no_random;
            no_random = rand() % 75 +1;
            disco.id = no_random;
            disco.tamano = t;

            strcpy(disco.part_1.status,"0");
            strcpy(disco.part_2.status,"0");
            strcpy(disco.part_3.status,"0");
            strcpy(disco.part_4.status,"0");

            fseek(file,0,SEEK_SET);
            fwrite(&disco, sizeof(MBR),1,file);


            fclose(file);
        }


    }

void agregar_particion(char* tam, char* unidad, char* path, char* nombre, char* fit, char* agregar, char*eliminar, char* tipo){


        int tamano = 0;
        int t = 0;
        int a = 0;
        int b = 0;
        char *tama= tam;
        char *uni = unidad;
        char *dire = path;
        char *nom = nombre;

        char taman[150]="";
        char unit[150]="";
        char direcc[200]="";
        char direccion[200]="";
        char name[150]="";
        char type[150]="";
        char addnuevo[150]="";
        char delnuevo[150]="";
        char fitnuevo[150]="";

        a = ("%d", strlen(dire));
        strncpy(direcc, &path[8],a-10);
        printf("\n------%s",direcc);

        strncpy(taman, &tam[7],sizeof(tam));
        tamano = atoi(taman);
        printf("\n------%d", tamano);

        strncpy(unit, &unidad[7],sizeof(unidad));
        printf("\n------%s",unit);

        strncpy(fitnuevo, &fit[6],sizeof(fit));
        printf("\n------%s",fitnuevo);

        strncpy(delnuevo, &agregar[9],sizeof(agregar));
        printf("\n------%s",delnuevo);

        strncpy(addnuevo, &eliminar[6],sizeof(eliminar));
        printf("\n------%s",addnuevo);

        strncpy(type, &tipo[7],sizeof(tipo));
        printf("\n------%s",type);

        b = ("%d", strlen(nombre));
        strncpy(name, &nombre[8],b-11);
        printf("\n------%s",name);


}

int main()
    {

        Leer_entrada();
        //crear_disco(10,"M","jfas","prueba.txt");



    }
