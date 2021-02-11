#include <stdio.h>
#include <windows.h>

void print_table(int *n, int *m, char tableA[100][100], char tableB[100][100]) {

    for (int k = 0; k < (*n) ; k++) {
        printf(".--");
    }
    for (int i = 0; i < *n; i++) {
        for (int j = 0; j < *m; j++) {
            tableA[j][i] = 0;
            tableB[j][i] = 0;
        }
    }
    for (int i = 0; i < *m; i++) {
        printf("\n");
        for (int j = 0; j < *n+1 ; j++) {
            printf("|  ");
        }
    }
    printf("\n");
    for (int k = 0; k <  (*n) ; k++) {
        printf(".--");
    }
    printf("\n");
}

void swap(int *n, int *m, char tableA[100][100], char tableB[100][100]) {
    for (int i = 0; i < *n; i++) {
        for (int j = 0; j < *m; j++)
            tableA[j][i] = tableB[j][i];
    }
}

void clear_screen(void) {
    for (int i = 0; i < 10; ++i) {
        printf("\n");
    }
}

void cells_location(int *n, int *m, char tableA[100][100], char tableB[100][100]) {
    int b;
    int x, y;
    for (int i = 0; i < *n; i++) {
        for (int j = 0; j < *m; j++) {
            tableA[j][i] = 0;
            tableB[j][i] = 0;
        }
    }

    printf("How many living cells?: ");
    scanf("%d", &b);
    for (int i = 0; i < b; i++) {
        printf("Enter dimensions (row  column) where cell %d will live: ", i + 1);
        scanf("%d %d", &x, &y);
        tableA[x][y] = 1;
    }
}

void drow(int *n, int *m, char tableA[100][100], char tableB[100][100]) {
    for (int j = 0; j < 3 * (*n) + 1; j++) {
        printf("=");
    }
    for (int i = 0; i < *m; i++) {
        printf("\n");
        for (int j = 0; j < *n + 1; j++) {
            if (tableA[i][j] == 1) {
                printf("|* ");
            } else {
                printf("|  ");
            }
        }
    }
    printf("\n");

    for (int j = 0; j < 3 * (*n) + 1; j++) {
        printf("=");
    }
    printf("\n");
}

void check(int *n, int *m, char tableA[100][100], char tableB[100][100]) {
    int neighbor;
    for (int i = 0; i < *m; i++) {
        for (int j = 0; j < *n; j++) {
            neighbor = 0;
            if (j != (*n) - 1) {
                if (tableA[i][j + 1] == 1) {
                    neighbor++;
                }
            }
            if (i != (*m) - 1 && j != (*n) - 1) {
                if (tableA[i + 1][j + 1] == 1) {
                    neighbor++;
                }
            }
            if (i != (*m) - 1) {
                if (tableA[i + 1][j] == 1) {
                    neighbor++;
                }
            }
            if (i != (*m) - 1 && j != 0) {
                if (tableA[i + 1][j - 1] == 1) {
                    neighbor++;
                }
            }
            if (j != 0) {
                if (tableA[i][j - 1] == 1) {
                    neighbor++;
                }
            }
            if (j != 0 && i != 0) {
                if (tableA[i - 1][j - 1] == 1) {
                    neighbor++;
                }
            }
            if (i != 0) {
                if (tableA[i - 1][j] == 1) {
                    neighbor++;
                }
            }
            if (i != 0 && j != (*n) - 1) {
                if (tableA[i - 1][j + 1] == 1) {
                    neighbor++;
                }
            }
            if (tableA[i][j] == 1 && neighbor < 2) {
                tableB[i][j] = 0;
            }
            if (tableA[i][j] == 1 && neighbor > 3) {
                tableB[i][j] = 0;
            }
            if (tableA[i][j] == 1 && (neighbor == 2 || neighbor == 3)) {
                tableB[i][j] = 1;
            }
            if (tableA[i][j] == 0 && neighbor == 3) {
                tableB[i][j] = 1;
            }
        }
    }
}

void check_x_up(int *n, int *m, char tableA[100][100], char tableB[100][100]) {
    for (int i = 0; i < *n; ++i) {
        if (tableA[0][i] == 1) {
            (*m)++;
            for (int c = 0; c < *m; c++) {
                for (int d = 0; d < *n; d++) {
                    tableB[c + 1][d] = tableA[c][d];
                }
            }
            for (int i = 0; i < *n; i++) {
                tableB[0][i] = 0;
            }
            swap(n, m, tableA, tableB);
            break;
        }
    }
}

void check_y_left(int *n, int *m, char tableA[100][100], char tableB[100][100]) {
    for (int i = 0; i < *m; ++i) {
        if (tableA[i][0]) {
            (*n)++;
            for (int c = 0; c < *m; c++) {
                for (int d = 0; d < *n; d++) {
                    tableB[c][d + 1] = tableA[c][d];
                }
            }
            for (int i = 0; i < *n; i++) {
                tableB[i][0] = 0;
            }
            swap(n, m, tableA, tableB);
            break;
        }
    }
}

void check_x_down(int *n, int *m, char tableA[100][100], char tableB[100][100]) {
    for (int i = 0; i < *n; ++i) {
        if (tableA[*m - 1][i] == 1) {
            (*m)++;
            break;
        }
    }
}

void check_y_right(int *n, int *m, char tableA[100][100], char tableB[100][100]) {
    for (int i = 0; i < *m; ++i) {
        if (tableA[i][*n - 1]) {
            (*n)++;
            break;
        }
    }
}


int main() {
    int t, n;
    printf("Enter Size Of Table:");
    scanf("%d", &n);
    printf("Enter Number Of Simulations:");
    scanf("%d", &t);
    int m = n;
    int fn = n;
    char tableA[100][100], tableB[100][100];
    print_table(&n, &m, tableA, tableB);
    cells_location(&n, &m, tableA, tableB);
    drow(&n, &m, tableA, tableB);
    Sleep(1000);
    clear_screen();
        for (int i = 0; i < t; ++i) {
            check_x_up(&n, &m, tableA, tableB);
            check_y_left(&n, &m, tableA, tableB);
            check_x_down(&n, &m, tableA, tableB);
            check_y_right(&n, &m, tableA, tableB);
            if(n > 2*fn || m > 2*fn)
                break;
            check(&n, &m, tableA, tableB);
            swap(&n, &m, tableA, tableB);
            drow(&n, &m, tableA, tableB);
            Sleep(1000);
            clear_screen();
    }
    return 0;
}