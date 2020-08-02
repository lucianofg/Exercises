#include <stdio.h>
#include <string.h>
#include <stdbool.h>

/* (x,y) for the coordinates of the certer of the circle, d for
 * de diameter */
bool they_overlap(int x1, int y1, int r1, int x2, int y2, int r2) 
{
    float radius = (r1 + r2) * (r1 + r2);
    float distance = (x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1);

    if (distance <= radius) {
        return true;
    } else {
        return false;
    }
}

int main(void)
{
    int m, n, k;
    scanf("%d %d %d", &m, &n, &k);
    int x[k], y[k], s[k];

    for (int i = 0; i < k; i++) {
        scanf("%d %d %d", &x[i], &y[i], &s[i]);
    }

    bool adjacency_matrix[k+2][k+2];
    memset(adjacency_matrix, false, sizeof adjacency_matrix);

    for (int i = 0; i < k; i++) {
        if (y[i] <= s[i] || x[i] + s[i] >= m) {
            adjacency_matrix[i+2][0] = true;
            adjacency_matrix[0][i+2] = true;
        }
        if (x[i] <= s[i] || y[i] + s[i] >= n) {
            adjacency_matrix[i+2][1] = true;
            adjacency_matrix[1][i+2] = true;
        }
    }

    for (int i = 0; i < k; i++) {
        for (int j = 0; j < k; j++) {
            if (they_overlap(x[i], y[i], s[i], x[j], y[j], s[j])) {
                adjacency_matrix[i+2][j+2] = true;
                adjacency_matrix[j+2][i+2] = true;
            }
        }
    }

    bool blocked = false;
    bool discovered[k+2];
    memset(discovered, false, sizeof discovered);

    for (int i = 0, j = 1; j < k + 2 && i < k + 2; j++) {
        if (adjacency_matrix[i][j]) {
            if (j == 1) {
                blocked = true;
                break;
            } else if (i != j && !discovered[j]) {
                discovered[j] = true;
                i = j;
                j = 0;
            }
        }
    }

    if (blocked) {
        printf("N\n");
    } else {
        printf("S\n");
    }

    return 0;
}
