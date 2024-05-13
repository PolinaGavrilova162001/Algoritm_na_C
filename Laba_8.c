#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct point
{
    double x;
    double y;
    int num;
} POINT;

int compare_points(const void*a, const void*b)
{
    POINT*point1 = (POINT *)a;
    POINT*point2 = (POINT *)b;
    
    if (point->x == point2->x)
    {
        return (point1->y - point2->y);
    }
    else
    {
        return (point1->x - point2->x);
    }
}

int orientation (POINT p, POINT q, POINT r)
{
    double val = (q.y - p.y) * (r.x - q.x) - (q.x - p.x) * (r.y - q.y);
    
    if (val == 0)
    {
        return 0;
    }
    else
    {
        return (val > 0) ? 1 : 2;
    }
}

void convex_hull (POINT *points, int n)
{
    if (n < 3)
    {
        return;
    }
    
    int hull[n];
    int idx = 0;
    
    qsort (points, n, sizeof(POINT), compare_points);
    
    int min_idx = 0;
    for (int i = 1; i < n; i++)
    {
        if (points[i].y < points[min_idx].y || (points[i].y == points[min_idx].y && points[i].x < points[min_idx].x))
        {
            min_idx = i;
        }
    }
    
    int p = min_idx, q;
    
    do
    {
        hull[idx++] = p;
        q = (p + 1) % n;
        
        for (int i = 0; i < n; i++)
        {
            if (orientation(points[p], points[i], points[q]) == 2)
            {
                q = i;
            }
        }
        
        p = q;
    }
    while (p != min_idx);
    
    FILE *outfile = fopen("OUT.txt", "w");
    if (outfile == NULL)
    {
        printf("Error\n");
        return;
    }
    
    for (int i = 0; i < idx; i++)
    {
        fprintf(outfile, "%d\n", points[hull[i].num);
    }
    
    fclose(outfile);
}

int main()
{
    FILE *infile = fopen("IN.txt", "r");
    if (infile == NULL)
    {
        printf("Error\n");
        return 1;
    }
    
    int n;
    fscanf(infile, "%d", &n);
    POINT points[n];
    
    for (int i = 0; i < n; i++)
    {
        fscanf(infile, "%lf %lf", &points[i].x, &points[i].y);
        points[i].num = i;
    }
    
    fclose (infile);
    
    convex_h_hull(points, n);
    
    return 0;
}
