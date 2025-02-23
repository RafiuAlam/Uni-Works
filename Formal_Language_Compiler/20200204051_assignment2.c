#include<stdio.h>

int kw_rec(char *lex)
{
    int i, s;
    i=0;

    if(     (lex[i] == 'i' && lex[i+1] == 'f') ||
            (lex[i] == 'i' && lex[i+1] == 'n' && lex[i+2] == 't') ||
            (lex[i] == 'c' && lex[i+1] == 'h' && lex[i+2] == 'a' && lex[i+3] == 'r') ||
            (lex[i] == 'e' && lex[i+1] == 'l' && lex[i+2] == 's' && lex[i+3] == 'e') ||
            (lex[i] == 'v' && lex[i+1] == 'o' && lex[i+2] == 'i' && lex[i+3] == 'd') ||
            (lex[i] == 'f' && lex[i+1] == 'l' && lex[i+2] == 'o' && lex[i+3] == 'a' && lex[i+4] == 't') ||
            (lex[i] == 'd' && lex[i+1] == 'o' && lex[i+2] == 'u' && lex[i+3] == 'b' && lex[i+4] == 'l' && lex[i+5] == 'e') ||
            (lex[i] == 'r' && lex[i+1] == 'e' && lex[i+2] == 't' && lex[i+3] == 'u' && lex[i+4] == 'r' && lex[i+5] == 'n')
      )
    {
        s=1;
    }

    else s=0;

    return s;
}

int id_rec(char *lex)
{
    int i, l, s;
    i=0;
    if(isalpha(lex[i]) || lex[i] == '_')
    {
        s=1;
        i++;
    }

    else s=0;
    l=strlen(lex);

    if(s==1)
        for(; i<l; i++)
        {
            if(isdigit(lex[i]) || isalpha(lex[i]) || lex[i] == '_')
                s=1;
            else
            {
                s=0;
                break;
            }
        }

    return s;
}

int op_rec(char *lex)
{
    int s, i;
    i=0;

    if( lex[i] == '+' || lex[i] == '-' || lex[i] == '*' || lex[i] == '/' || lex[i] == '!' ||
            lex[i] == '&' || lex[i] == '%' || lex[i] == '=' || lex[i] == '<' || lex[i] == '>' ||
            lex[i] == '~' || lex[i] == '|' || lex[i] == '^' || (lex[i] == '-' && lex[i+1] == '>') ||
            (lex[i] == '&' && lex[i+1] == '&') || (lex[i] == '|' && lex[i+1] == '|') ||
            (lex[i] == '+' && lex[i+1] == '+') || (lex[i] == '-' && lex[i+1] == '-') ||
            (lex[i] == '<' && lex[i+1] == '=') || (lex[i] == '>' && lex[i+1] == '=') ||
            (lex[i] == '=' && lex[i+1] == '=') || (lex[i] == '!' && lex[i+1] == '=')
      )
    {
        s=1;
    }

    else s=0;

    return s;
}

int sep_rec(char *lex)
{
    int s, i;
    i=0;

    if( lex[i] == ':' || lex[i] == ';' || lex[i] == ',' || lex[i] == '"' || (strlen(lex) == 1 && lex[i] == '\''))
    {
        s=1;
    }

    else s=0;

    return s;
}

int par_rec(char *lex)
{
    int s, i;
    i=0;

    if( lex[i] == '(' || lex[i] == ')' || lex[i] == '{' || lex[i] == '}' || lex[i] == '[' || lex[i] == ']')
    {
        s=1;
    }

    else s=0;

    return s;
}

int num_rec(char *lex)
{
    int i, l, s;
    i=0;
    if(isdigit(lex[i]))
    {
        s=1;
        i++;
    }
    else if(lex[i]=='.')
    {
        s=2;
        i++;
    }
    else s=0;
    l=strlen(lex);

    if(s==1)
        for(; i<l; i++)
        {
            if(isdigit(lex[i]))
                s=1;
            else if(lex[i]=='.')
            {
                s=2;
                i++;
                break;
            }
            else
            {
                s=0;
                break;
            }
        }

    if(s==2)
        if(isdigit(lex[i]))
        {
            s=3;
            i++;
        }
        else
            s=0;
    if(s==3)
        for(; i<l; i++)
        {
            if(isdigit(lex[i]))
                s=3;
            else
            {
                s=0;
                break;
            }
        }
    if(s==3) s=1;
    return s;
}

int main()
{
    FILE *p1, *p2, *p3, *p4;
    char c, lex[93];
    int i;

    p1 = fopen("20200204051_A1_Assignment_01.c", "r");
    p2 = fopen("assignment2_text.txt", "w");

    if(!p1)
    {
        printf("\nFile can't be opened!");
    }

    //step-1:
    else
    {
        fputc(' ', p2);
        while((c = fgetc(p1)) != EOF)
        {
            if(c == '+' || c == '-' || c == '*' || c == '/' || c == '%' || c == '=' || c == '>' || c == '\'' ||
                    c == '<' || c == '!' || c == '&' || c == '|' || c == '(' || c == ')' || c == '{' ||
                    c == '}' || c == '[' || c == ']' || c == ',' || c == ';' || c == '"' || c == ':')
            {
                fputc(' ', p2);
                fputc(c, p2);
                fputc(' ', p2);
            }
            else
                fputc(c, p2);

        }
    }
    fclose(p1);
    fclose(p2);

//step-2:
    p3 = fopen("assignment2_text.txt", "r");
    p4 = fopen("output.txt", "w");

    if(!p3)
    {
        printf("\nFile can't be opened!");
    }
    else
    {
        while (fscanf(p3, "%s", lex) != EOF)
        {
            if (kw_rec(lex))
            {
                fprintf(p4, "\t[kw %s]", lex);
                printf("\t[kw %s]", lex);
            }
            else if (id_rec(lex))
            {
                fprintf(p4, "\t[id %s]", lex);
                printf("\t[id %s]", lex);
            }
            else if (op_rec(lex))
            {
                fprintf(p4, "\t[op %s]", lex);
                printf("\t[op %s]", lex);
            }
            else if (sep_rec(lex))
            {
                fprintf(p4, "\t[sep %s]", lex);
                printf("\t[sep %s]", lex);
            }
            else if (par_rec(lex))
            {
                fprintf(p4, "\t[par %s]", lex);
                printf("\t[par %s]", lex);
            }
            else if (num_rec(lex))
            {
                fprintf(p4, "\t[num %s]", lex);
                printf("\t[num %s]", lex);
            }
            else
            {
                fprintf(p4, "\t[unkn %s]", lex);
                printf("\t[unkn %s]", lex);
            }
        }
    }

    fclose(p3);

    return 0;
}

