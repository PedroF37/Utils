#include "utils.h"


bool is_directory_created(char *dirname)
{
    mode_t mask = umask(0);
    umask(mask);

    if (mkdir(dirname, 0777 - mask) == -1)
    {
        umask(mask);
        return(false);
    }

    umask(mask);
    return(true);
}


bool is_valid_directory(char *dirname)
{
    DIR *dhandle;
    if ((dhandle = opendir(dirname)) == NULL)
    {
        return(false);
    }

    closedir(dhandle);
    return(true);
}


bool is_dot_directory(char *dirname)
{
    if (strcmp(dirname, ".") != 0 && strcmp(dirname, "..") != 0)
    {
        return(false);
    }

    return(true);
}


char *has_extension(char *filename)
{
    char *ext = strrchr(filename, '.');
    return((ext != NULL && ext[1] != '\0') ? ext + 1 : NULL);
}


char *rev_strstr(char *haystack, char *needle, size_t len)
{
    size_t haystack_len = strlen(haystack);
    if (haystack_len < len || len == 0)
    {
        return(NULL);
    }

    /* Coloca-nos na posição certa */
    char *end_of_haystck = haystack + haystack_len - len;
    if (memcmp(end_of_haystck, needle, len) == 0)
    {
        return(end_of_haystck);
    }
    else
    {
        return(NULL);
    }
}


char *duplicate(char *source)
{
    size_t source_len = strlen(source) + 1;
    char *dest = (char *)malloc(source_len);
    if (dest == NULL)
    {
        return(NULL);
    }

    memmove(dest, source, source_len);
    return(dest);

}


char *create_pathname(char *base, char *name)
{
    size_t pathname_len = strlen(base) + strlen(name) + 2;
    char *pathname = (char *)malloc(pathname_len);
    if (pathname == NULL)
    {
        return(NULL);
    }

    snprintf(pathname, pathname_len, "%s/%s", base, name);
    return(pathname);
}


void remove_last_char(char *itemname, int reject)
{
    size_t itemname_len = strlen(itemname);
    if (itemname[itemname_len - 1] == reject)
    {
        itemname[itemname_len - 1] = '\0';
    }
}


void title_case_word(char *word)
{
    if (*word != '\0')
    {
        *word = (char)toupper((unsigned char)*word);
    }
}


void title_case_sentence(char *sentence)
{
    char *word = sentence;

    while (*word)
    {
        while (*word && !isalpha(*word))
        {
            word++;
        }

        if (*word)
        {
            *word = (char)toupper((unsigned char)*word);
        }

        while (*word && isalpha(*word))
        {
            word++;
        }
    }
}
