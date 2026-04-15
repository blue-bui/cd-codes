#include <stdio.h>
#include <string.h>

char sym[20][20];
int n;

void add(char s[]) { strcpy(sym[n++], s); }
int find(char s[]) {
    int i;
    for (i = 0; i < n; i++) if (!strcmp(sym[i], s)) return i;
    return -1;
}

int main(void) {
    int i, m;
    char s[20];

    printf("Enter number of symbols: ");
    scanf("%d", &m);
    printf("Enter symbols\n");
    for (i = 0; i < m; i++) {
        scanf("%s", s);
        add(s);
    }

    puts("Symbol table:");
    for (i = 0; i < n; i++) printf("%d %s\n", i + 1, sym[i]);

    printf("Enter symbol to search: ");
    scanf("%s", s);
    printf(find(s) >= 0 ? "Symbol found\n" : "Symbol not found\n");
}