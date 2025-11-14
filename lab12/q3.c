//  Problem 3: Town Judge

//  In a town, there are n people labeled from 1 to n. There is a rumor that one of these people is secretly the
//  town judge.
//  If the town judge exists, then: The town judge trusts nobody. Everybody (except for the town judge) trusts
//  the town judge. There is exactly one person that satisfies properties 1 and 2.
//  You are given an array trust where trust[i] = [ai,bi] representing that the person labeled ai trusts the person
//  labeled bi. If a trust relationship does not exist in trust array, then such a trust relationship does not exist.
//  Return the label of the town judge if the town judge exists and can be identified, or return −1 otherwise

#include <stdio.h>

int findJudge(int n, int trust[][2], int m) {
    int in[n+1], out[n+1];

    for (int i = 1; i <= n; i++) {
        in[i] = 0;
        out[i] = 0;
    }

    for (int i = 0; i < m; i++) {
        int a = trust[i][0];
        int b = trust[i][1];

        out[a]++;   // a trusts someone
        in[b]++;    // b is trusted by someone
    }

    for (int i = 1; i <= n; i++) {
        if (in[i] == n - 1 && out[i] == 0)
            return i;
    }
    
    return -1;
}

int main() {
    int n, m;
    printf("Enter number of people: ");
    scanf("%d", &n);

    printf("Enter number of trust relationships: ");
    scanf("%d", &m);

    int trust[m][2];
    printf("Enter trust pairs (a b):\n");
    for (int i = 0; i < m; i++)
        scanf("%d %d", &trust[i][0], &trust[i][1]);

    int judge = findJudge(n, trust, m);

    if (judge == -1)
        printf("No judge found\n");
    else
        printf("Town Judge = %d\n", judge);

    return 0;
}
