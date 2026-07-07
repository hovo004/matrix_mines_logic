#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define SIZE 5

char** create_mat ();
void print (char**);
void modifate_matrix (char**);
void check_and_change (char**, int, int);
void destroy (char **);

int main ()
{
    char **mat = create_mat ();
    printf ("\nOriginal Matrix >>>\n");
    print (mat);

    modifate_matrix (mat);
    printf("\nModifated Matrix >>>\n");
    print (mat);
    destroy (mat);

    return 0;
}

char **create_mat ()
{
    char **mat = (char**)malloc (SIZE * sizeof (char*));
    
    for (int i = 0; i < SIZE; i++)
    {
        mat[i] = (char*) malloc (SIZE * sizeof (char));
    }

    srand (time (NULL));

    for (int i = 0; i < SIZE; ++i)
    {
        for (int j = 0; j < SIZE; ++j)
        {
            mat [i][j] = (rand () % 5) != 3 ? '0' : 'M';
        }
    }

    return mat;
}

void print (char **mat)
{
    for ( int i = 0; i < SIZE; ++i, printf ("\n"))
    {
        for(int j = 0; j < SIZE; ++j)
        {
            printf("%c ", mat[i][j]);
        }
    }   
}

void modifate_matrix (char **mat)
{
    int try = 0;
    
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            check_and_change(mat, i, j);
        }
    }
}



void  check_and_change (char** mat, int _i, int _j)
{
    for (int off_i = -1; off_i <= 1; off_i++ )
    {
        for (int off_j = -1; off_j <= 1; off_j++ )
        {
            if (_i + off_i == -1 || _j + off_j == -1 || _j + off_j == SIZE || _i + off_i == SIZE) {continue;}
            else if (off_i == 0 && off_j == 0 ) {continue;}
            else if (mat[_i + off_i][_j + off_j] == 'M') 
            {
                if (mat[_i][_j] != 'M')
                {
                    mat[_i][_j]++;
                } 
            }
        }
    }
}

void destroy (char ** mat)
{
    for (int i = 0; i < SIZE; i++)
    {
        free (mat [i]);
    }
    free (mat);
}
