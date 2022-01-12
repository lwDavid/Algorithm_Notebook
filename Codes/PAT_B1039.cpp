#include <stdio.h>
#include <string.h>
int main() {
    int len1 = 0, len2 = 0, extra = 0, lack = 0;
    char owner[1001], AvA[1001], beads[256] = {0};
    if (scanf("%s %s", owner, AvA))
        len1 = strlen(owner), len2 = strlen(AvA);
    for (int i = 0; i < len1; i++) {
        beads[(int)owner[i]]++;
    }
    for (int i = 0; i < len2; i++) {
        beads[(int)AvA[i]]--;
    }
    for (int i = 48; i < 123; i++) {
        if (beads[i] > 0)
            extra += beads[i];
        else
            lack -= beads[i];
    }
    if (lack)
        printf("No %d\n", lack);
    else
        printf("Yes %d\n", extra);
    return 0;
}
