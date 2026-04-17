#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int x;
    int h;
} Point;

typedef struct {
    Point *arr;
    int size;
} Skyline;

typedef struct {
    int left, right, height;
} Building;

// Add a point to skyline, but avoid redundant points
void addPoint(Skyline *sky, int x, int h) {
    if (sky->size > 0) {
        // If same x, keep only the larger/latest meaningful height
        if (sky->arr[sky->size - 1].x == x) {
            sky->arr[sky->size - 1].h = h;
            return;
        }
        // If height is same as previous, no need to add
        if (sky->arr[sky->size - 1].h == h) {
            return;
        }
    }
    sky->arr[sky->size].x = x;
    sky->arr[sky->size].h = h;
    sky->size++;
}

// Merge two skylines
Skyline mergeSkyline(Skyline leftSky, Skyline rightSky) {
    Skyline res;
    res.arr = (Point *)malloc((leftSky.size + rightSky.size) * sizeof(Point));
    res.size = 0;

    int i = 0, j = 0;
    int h1 = 0, h2 = 0;

    while (i < leftSky.size && j < rightSky.size) {
        int x, maxH;

        if (leftSky.arr[i].x < rightSky.arr[j].x) {
            x = leftSky.arr[i].x;
            h1 = leftSky.arr[i].h;
            maxH = (h1 > h2) ? h1 : h2;
            addPoint(&res, x, maxH);
            i++;
        }
        else if (rightSky.arr[j].x < leftSky.arr[i].x) {
            x = rightSky.arr[j].x;
            h2 = rightSky.arr[j].h;
            maxH = (h1 > h2) ? h1 : h2;
            addPoint(&res, x, maxH);
            j++;
        }
        else {
            // same x-coordinate in both skylines
            x = leftSky.arr[i].x;
            h1 = leftSky.arr[i].h;
            h2 = rightSky.arr[j].h;
            maxH = (h1 > h2) ? h1 : h2;
            addPoint(&res, x, maxH);
            i++;
            j++;
        }
    }

    // Add remaining points from left skyline
    while (i < leftSky.size) {
        addPoint(&res, leftSky.arr[i].x, leftSky.arr[i].h);
        i++;
    }

    // Add remaining points from right skyline
    while (j < rightSky.size) {
        addPoint(&res, rightSky.arr[j].x, rightSky.arr[j].h);
        j++;
    }

    return res;
}

// Divide and conquer function
Skyline solve(Building buildings[], int l, int r) {
    // Base case: one building
    if (l == r) {
        Skyline sky;
        sky.arr = (Point *)malloc(2 * sizeof(Point));
        sky.size = 0;

        addPoint(&sky, buildings[l].left, buildings[l].height);
        addPoint(&sky, buildings[l].right, 0);

        return sky;
    }

    int mid = (l + r) / 2;

    Skyline leftSky = solve(buildings, l, mid);
    Skyline rightSky = solve(buildings, mid + 1, r);

    Skyline merged = mergeSkyline(leftSky, rightSky);

    free(leftSky.arr);
    free(rightSky.arr);

    return merged;
}

int main() {
    int n;
    scanf("%d", &n);

    Building buildings[n];
    for (int i = 0; i < n; i++) {
        scanf("%d %d %d", &buildings[i].left, &buildings[i].right, &buildings[i].height);
    }

    Skyline ans = solve(buildings, 0, n - 1);

    for (int i = 0; i < ans.size; i++) {
        printf("(%d %d)", ans.arr[i].x, ans.arr[i].h);
        if (i + 1 < ans.size) printf(" ");
    }
    printf("\n");

    free(ans.arr);
    return 0;
}