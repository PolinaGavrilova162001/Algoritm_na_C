#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MAX_VERTICES 100000
#define MAX_EDGE_LENGTH 1000

int N, L;
int A[MAX_VERTICES], B[MAX_EDGE_LENGTH];
int dp[MAX_VERTICES];

void readlnput() {
    scanf("%d %d", &N, &L);
    for (int i=1; i<N; ++i) {
        scanf("%d", &A[i]);
    }
    for (int i=0; i<N-1; ++i) {
        scanf("%d", &B[i]);
    }
}

void solve() {
    dp[0]=0;
    for (int i=1; i<N; ++i) {
        dp[i]=INT_MAX;
    }
    dp[0]=1;
    
    for (int i=1; i<N; ++i) {
        int vertex = A[i];
        int edgeLength = B[i-1];
        dp[vertex] = min(dp[vertex], dp[i-1]+1);
    }
    
    int maxWorms = 0;
    for (int i=0; i<N; ++i) {
        maxWorms = max(maxWorms, dp[i]);
    }
    printf("%d\n", maxWorms);
}

int main() {
    readlnput();
    solve();
    return 0;
}
