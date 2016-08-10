#include <stdio.h>
#include <stdlib.h>
#include <string.h>



void Leer_entrada()
    {

        char dir[200];
        char nueva[200] = "";
        printf("ingrese la direccion: ");
        fgets(dir,200,stdin);
        char *token;
        char cadena[100] = "mkdisk pedro jau";
        token=strtok(dir, " ");

        while(token!=NULL){
                if(strcasecmp(token, "mkdisk")== 0){
                    printf("Dato: %s \n", token);
                    token=strtok(NULL," ");
                }
                if(strcmp(token, "mkdisk")!= 0){

                    strcat(nueva,token);
                    strcat(nueva," ");
                    token=strtok(NULL," ");


                }
            }
            printf("%s",nueva);



    }

int main()
    {

        Leer_entrada();



    }
