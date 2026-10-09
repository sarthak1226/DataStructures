#include <stdio.h>
#include <stdlib.h>
struct edge
{
    char desitnation;
    struct edge *neighnour;
};

struct vertice
{
    char source;
    struct edge *head;
    struct vertice *next;
};
struct vertice *top = NULL;
struct vertice *cur = NULL;
struct vertice *parent = NULL;
struct edge *edge_cur = NULL;
struct edge *edge_cur_duplicate = NULL;

void insertAdjacentLl(char source, char destination)
{
    struct vertice *vertice;
    struct edge *edge;
    if (top == NULL)
    {
        vertice = malloc(sizeof(struct vertice));
        edge = malloc(sizeof(struct edge));
        vertice->source = source;
        edge->desitnation = destination;
        edge->neighnour = NULL;
        vertice->head = edge;
        top = vertice;
        vertice->next = NULL;
    }
    else
    {
        struct vertice *vertice_2;
        struct edge *edge_2;
        vertice_2 = malloc(sizeof(struct vertice));
        edge_2 = malloc(sizeof(struct edge));

        cur = top;
        int f = 0;
        while (cur != NULL)
        {
            parent = cur;
            if (cur->source == source)
            {
                f = 1;
                break;
            }
            cur = cur->next;
        }
        if (f)
        {
            edge_cur = cur->head;
            edge_cur_duplicate = edge_cur;
            while (edge_cur->neighnour != NULL)
            {

                edge_cur = edge_cur->neighnour;
            }
            while (edge_cur_duplicate != NULL)
            {
                if (edge_cur_duplicate->desitnation == destination)
                {
                    printf("ALready exist!!!!");
                    return;
                }
                edge_cur_duplicate = edge_cur_duplicate->neighnour;
            }
            edge_2->neighnour = NULL;
            edge_2->desitnation = destination;
            edge_cur->neighnour = edge_2;
        }
        else
        {
            vertice_2->source = source;
            edge_2->desitnation = destination;
            edge_2->neighnour = NULL;
            vertice_2->head = edge_2;
            parent->next = vertice_2;
        }
    }
}

int check(char source, char destination)
{
    struct edge *edge;
    struct vertice *vertice;

    vertice = top;
    int f = 0, ff = 0;
    while (vertice != NULL)
    {
        if (vertice->source == source)
        {
            f = 1;
            break;
        }
        vertice = vertice->next;
    }
    if (!f)
        return -1;
    edge = vertice->head;
    while (edge != NULL)
    {
        if (edge->desitnation == destination)
        {
            ff = 1;
            break;
        }
        check(edge->desitnation, destination);
        edge = edge->neighnour;
    }
    if (f && ff)
        return 1;
    return -1;
}

int dfs(char source, char destination, int visited[])
{
    struct vertice *vertice = top;
    struct edge *edge;
    if (source == destination)
        return 1;

    while ((vertice != NULL))
    {
        if (vertice->source == source)
            break;
        vertice = vertice->next;
    }

    if (vertice == NULL)
        return -1;

    edge = vertice->head;

    int x = source;
    if (visited[x] == 1)
        return -1;
    visited[x] = 1;

    while (edge != NULL)
    {
        if (edge->desitnation == destination)
            return 1;

        if (dfs(edge->desitnation, destination, visited) == 1)
            return 1;
        edge = edge->neighnour;
    }
    return -1;
}

int visited[256] = {0};



int matrice[4][4];
void insertAdjacentMatrices(char source, char destination){
    char element[]={source,destination};
    int index[2];
    for(int i=0;i<2;i++){
        switch (element[i])
        {
        case 'A':
            index[i]=0;
            break;
        case 'B':
            index[i]=1;
            break;
        case 'C':
            index[i]=2;
            break;
        case 'D':
            index[i]=3;
            break;
        
        default:
            break;
        }
    }

    matrice[index[0]][index[1]]=1;
}



int main()
{
}