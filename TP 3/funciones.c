#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include "funciones.h"

void inicializar(EMovie* movie, int lenght)
{
    if(movie != NULL && lenght>0)
    {
        int i;
        for(i=0; i<lenght; i++)
        {
            movie[i].estado=1;
        }
    }
}

int agregarPelicula(EMovie* movie, FILE* aMovie)
{

    if(movie != NULL)
    {


                if(movie->estado==1)
                {
                    printf("Ingrese titulo de la pelicula: ");
                    fflush(stdin);
                    gets(movie->titulo);

                    printf("Ingrese genero de la pelicula: ");
                    fflush(stdin);
                    gets(movie->genero);

                    printf("Ingrese duracion: ");
                    fflush(stdin);
                    scanf("%d", &movie->duracion);

                    printf("Ingrese descripcion: ");
                    fflush(stdin);
                    gets(movie->descripcion);

                    printf("Ingrese puntaje: ");
                    fflush(stdin);
                    scanf("%d",&movie->puntaje);

                    printf("Ingrese link de la imagen: ");
                    fflush(stdin);
                    gets(movie->linkImagen);

                    movie->estado=0;


            aMovie=fopen("movie.bin", "ab");
            if(aMovie!=NULL)
            {
                fwrite(movie,sizeof(EMovie),1,aMovie);
            }
            fclose(aMovie);
        }

    }


}


int borrarPelicula(EMovie* movie,FILE* aMovie)
{
    if(movie != NULL)
    {
        char auxT[50];
       printf("ingrese titulo");
       gets(auxT);
       aMovie=fopen("movie.bin", "r");
        if(aMovie!=NULL)
        {
            while((fread(movie,sizeof(EMovie),1,aMovie))!=0)
            {
                if(movie->estado==1)
                    {
                        strlwr(movie->titulo);
                        if(strcmp(movie->titulo,auxT)==0)
                        {
                            fseek(aMovie,-sizeof(EMovie),SEEK_CUR);
                            movie->estado=0;
                            fwrite(movie,sizeof(EMovie),1,aMovie);
                            printf("Se borro la pelicula!");

                            break;
                        }
                    }
            }

        }
    }

}

void generarPagina(EMovie* movie,FILE* aMovie)
{
    FILE* htmlFile;
    aMovie=fopen("movie.bin","rb");
    if(aMovie!=NULL)
    {
        htmlFile=fopen("movieHtml.bin","wb");
        if(htmlFile!=NULL)
        {
            fprintf(htmlFile,
            "<!DOCTYPE html>\n"
            "<html lang='en'>\n"
            "<head>\n"
            "    <meta charset='utf-8'>\n"
            "    <meta http-equiv='X-UA-Compatible' content='IE=edge'>\n"
            "    <meta name='viewport' content='width=device-width, initial-scale=1'>\n"
            "    <title>Lista peliculas</title>\n"
            "    <link href='css/bootstrap.min.css' rel='stylesheet'>\n"
            "    <link href='css/custom.css' rel='stylesheet'>\n"
            "</head>\n"
            "<body>\n"
            "    <div class='container'>\n"
            "        <div class='row'>\n");
            while((fread(movie,sizeof(EMovie),1,aMovie))!=0)
            {

               if(movie->estado==1)
               {
                    fprintf(htmlFile,
                    "<article class='col-md-4 article-intro'>\n"
                    "<a href='#'>\n"
                    "<img class='img-responsive img-rounded' src='%s' alt=''>\n"
                    "</a>\n"
                    "<h3>\n"
                    "<a href='#'>%s</a>\n"
                    "</h3>\n"
                    "<ul>\n"
                    "<li>Genero:%s</li>\n"
                    "<li>Puntaje:%d</li>\n"
                    "<li>Duracion:%d minutos</li>\n"
                    "</ul>\n"
                    "<p>%s</p>\n"
                    " </article>\n",movie->linkImagen,movie->titulo,movie->genero,movie->puntaje,movie->duracion,movie->descripcion);
               }

            }

            fprintf(htmlFile,
            "</div>\n"
            "</div>\n"
            "<script src='js/jquery-1.11.3.min.js'></script>\n"
            "<script src='js/bootstrap.min.js'></script>\n"
            "<script src='js/ie10-viewport-bug-workaround.js'></script>\n"
            "<script src='js/holder.min.js'></script>\n"
            "</body>\n"
            "</html>\n");
        }
        else
        {
            printf("El archivo no fue cargado");
            return 0;
        }
    }

    printf("Se genero la pagina web");
    fclose(aMovie);
    fclose(htmlFile);


    return 0;
}

