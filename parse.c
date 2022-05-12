#include "monty.h"

/**
 * readline - Parse line into tokens
 *
 * @buf: String to tokenize
 * @line: Struct line_t
 * Return: void
 */
void readline(char *buf, line_t *line)
{
        int i;
        char *token = NULL;

        line->tokens = malloc(sizeof(char *) * 3);
        if (line->tokens == NULL)
        {
                fprintf(stderr, "Error: malloc failed\n");
                exit(EXIT_FAILURE);
        }

        token = strtok(buf, " \n");
        for (i = 0; token && i < 2; i++)
        {
                line->tokens[i] = token;
                token = strtok(NULL, " \n");
        }

        line->tokens[i] = NULL;
}

/**
 * readfile - Read and parse file
 *
 * @fp: File descriptor
 * Return: void
 */
void readfile(FILE *fp)
{
        char *l = NULL;
        size_t len = 0;
        ssize_t read;
        line_t line;
        global_t *global = malloc(sizeof(global_t));
        if (!global)
        {
                fprintf(stderr, "Error: malloc failed\n");
                exit(EXIT_FAILURE);
        }

        line.number = 0;
        line.tokens = NULL;

        global->file = fp;
        global->stack = NULL;
        global->buf = NULL;

        while ((read = getline(&(global->buf), &len, fp)) != -1)
        {
                line.number++;
                readline(global->buf, &line);
                if (line.tokens)
                {
                        get_op_func(line, global)(&(global->stack), line.number);
                }
        }

        fclose(global->file);
        free_stack(&(global->stack));
	if (global->buf)
		free(global->buf);
        free(global);
}
