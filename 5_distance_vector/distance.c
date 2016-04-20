/*
 * Distance Vector routing (Bellman Ford)
 */
#include <stdio.h>
struct node {
    int dist[10];
    int from[10];
} router[10];

int main() {
    int cost[10][10];
    int i,j,k, nodes, count = 0;

    printf("No.of routers: ");
    scanf("%d", &nodes);

    printf("Enter cost matrix:\n");
    for (i=0; i<nodes; i++) {
        for (j=0; j<nodes; j++) {
            scanf("%d", &cost[i][j]);
            cost[i][i] = 0;
            // Initialize distance = Cost matrix
            router[i].dist[j] = cost[i][j];
            router[i].from[j] = j;
        }
    }

    // Belman ford algorithm
    do {
        count = 0;
        for (i=0; i<nodes; i++)
            for (j=0; j<nodes; j++)
                for (k=0; k<nodes; k++)
                    if (router[i].dist[j] > cost[i][k] + router[k].dist[j]) {
                        // Calculate minimum distance
                        router[i].dist[j] = router[i].dist[k] + router[k].dist[j];
                        router[i].from[j] = k;
                        count++;
                    }
    } while (count != 0);

    printf("Distance vector\n");
    // Print the distance vector
    for (i=0; i<nodes; i++) {
        printf("\nRouter: %d\n", i+1);
        for (j=0; j<nodes; j++)
            printf("Node %d via %d, Distance %d\n", j+1, router[i].from[j] + 1, router[i].dist[j]);

    }
}
