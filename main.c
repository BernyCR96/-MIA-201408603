#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct particiones{
int status;
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


}typedef PART_EXT;

struct mbr{
int tamano;
char time[200];
int id;
PART part_1;
PART part_2;
PART part_3;
PART part_4;
}typedef MBR;




void Leer_entrada()
    {

        char dir[200];
        char nueva[200] = "";
        printf("ingrese la direccion: ");
        fgets(dir,200,stdin);
        char *token=NULL;
        token=strtok(dir, " ");

        while(token!=NULL){
                if(strcasecmp(token, "mkdisk")== 0){
                    printf("Dato: %s \n", token);
                    token=strtok(NULL," ");
                }
                if(strcasecmp(token, "mkdisk")!= 0){

                    strcat(nueva,token);
                    strcat(nueva," ");
                    token=strtok(NULL," ");


                }
            }
            separar(nueva);




    }



void separar(char cadena[200]){
    int tam;
    int bandera = 0;
    char pathnuevo[100] ="";
    char namenuevo[100] = "";
    char unidad[50] ="";
    char path[150] ="";
    char name[150] = "";
    char nuevo[50] ="";

    char *token1=NULL;
        char prueba[20] = " ";
        token1=strtok(cadena,prueba);
        while(token1!=NULL){
                strncpy(nuevo, &token1[0],7);
                if(strcasecmp(nuevo,"-path::")==0){

                    bandera = 1;
                }
                if(strcasecmp(nuevo,"-name::")==0){

                    bandera = 2;
                }

                if(bandera == 1 ){
                    strcat(pathnuevo,token1);
                    strcat(pathnuevo," ");
                    token1=strtok(NULL," ");


                }
                else if(bandera == 2 ){
                    strcat(namenuevo,token1);
                    strcat(namenuevo," ");
                    token1=strtok(NULL," ");


                }


                    else{

                    if(strcasecmp(token1, "-path")== 0){
                        printf("entro");
                        printf("Dato: %s \n", token1);
                        token1=strtok(NULL," ");
                    }
                    else {
                        printf("otro: %s \n", token1);
                        token1=strtok(NULL," ");

                    }
                    bandera = 0;

                }

            }
            printf("%s\n",pathnuevo);
            printf("%s\n",namenuevo);

}
void crear_disco(int tam, char uni[150], char path[150], char nombre[150]){

        FILE* file = fopen(nombre,"ab");
        char llenar[1024]="\0";
        if(nombre ==NULL){
            printf("No se pudo acceder al archivo");

        }
        else{
                if(strcmp(uni,"B")==0){
                 for(int x = 0;x<(tam/1024);x++){
                    fwrite(llenar,sizeof(llenar),1,file);
                    }
                }
                else if(strcmp(uni,"k")==0){
                    for(int x = 0;x<tam;x++){
                    fwrite(llenar,sizeof(llenar),1,file);
                }
                }
                else if(strcmp(uni,"M")==0){
                    for(int x = 0;x<(tam*1024);x++){
                    fwrite(llenar,sizeof(llenar),1,file);
                }
                }



            fclose(file);
        }


    }

int main()
    {

        Leer_entrada();
        crear_disco(10,"M","jfas","prueba.txt");



    }
