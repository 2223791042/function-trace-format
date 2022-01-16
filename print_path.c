#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
function_a()
    function_b()
        function_c()
            function_d()
            function_e()

function_a()
 |
 o--> function_b()
       |
       o--> function_c()
             |
             o--> function_d()
             |
             o--> function_e()
*/

typedef struct {
    int seq;
    char name[20];
    int indent;
} func_node;

func_node func_list[] = {
    { .seq = 1, .name = "function_a()", .indent = 0 },
    { .seq = 2, .name = "function_b()", .indent = 1 },
    { .seq = 3, .name = "function_c()", .indent = 2 },
    { .seq = 4, .name = "function_d()", .indent = 3 },
    { .seq = 5, .name = "function_e()", .indent = 3 },
};

int list_len = sizeof(func_list) / sizeof(func_node);

int main()
{
    int i, j;
    char **map = (char **)malloc(sizeof(char *) * (list_len * 2));
    for (i = 0; i < (list_len * 2 - 1); i++) {
        map[i] = (char *)malloc(sizeof(char) * 100);
        memset(map[i], 0, 100);
        if (i == 0) {
            sprintf(&map[i][0], "%s", func_list[0].name);
            continue;
        }

        if (i % 2  == 1) {
            int pre_pos = (i - 1) / 2;
            int next_pos = (i + 1) / 2;
            int indent = func_list[next_pos].indent;
            for (j = 0; j <= (indent - 1) * 6; j++) {
                map[i][j] = ' ';
            }
            map[i][j] = '|';
            continue;
        }

        int indent = func_list[i / 2].indent;
        char *name = func_list[i / 2].name;
        for (j = 0; j <= (indent - 1) * 6; j++) {
            map[i][j] = ' ';
        }
        sprintf(&map[i][j], "o--> %s", name);
    }

    for (i = 0; i < (list_len * 2 - 1); i++) {
        printf("%s\n", map[i]);
    }

    return 0;
}