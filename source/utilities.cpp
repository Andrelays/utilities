#include<math.h>
#include<stdlib.h>
#include"utilities.h"
#include"myassert.h"

FILE *check_isopen(const char *file_name, const char *opening_mode)
{
    MYASSERT(file_name != NULL, NULL_POINTER_PASSED_TO_FUNC, return NULL);
    MYASSERT(opening_mode != NULL,      NULL_POINTER_PASSED_TO_FUNC,    return NULL);
    MYASSERT(opening_mode != file_name, EQUAL_POINTERS_PASSED_TO_FUNC,  return NULL);

    FILE *file_pointer = NULL;

    if ((file_pointer = fopen (file_name, opening_mode)) == NULL || ferror (file_pointer)) {
        printf("ERROR! Could not open the file \"%s\"!\n", file_name);
    }

    return file_pointer;
}

bool check_isclose(FILE *file_pointer)
{
    MYASSERT(file_pointer != NULL, NULL_POINTER_PASSED_TO_FUNC, return false);

    if (fclose(file_pointer))
    {
        printf("ERROR! Could not close the file\n");
        return false;
    }

    return true;
}

bool check_argc(int argc, int correct_number_argc)
{
    if (argc != correct_number_argc)
    {
        printf("ERROR! Incorrect numbers of coomand line arguments: %d.\n", argc);
        return false;
    }

    return true;
}

FILE *check_isopen_html(const char *file_name, const char *opening_mode)
{
    MYASSERT(file_name    != NULL,      NULL_POINTER_PASSED_TO_FUNC,    return NULL);
    MYASSERT(opening_mode != NULL,      NULL_POINTER_PASSED_TO_FUNC,    return NULL);
    MYASSERT(opening_mode != file_name, EQUAL_POINTERS_PASSED_TO_FUNC,  return NULL);

    FILE *file_pointer = NULL;

    if ((file_pointer = fopen (file_name, opening_mode)) == NULL || ferror (file_pointer)) {
        printf("ERROR! Could not open the file \"%s\"!\n", file_name);
    }

    else {
        setbuf(file_pointer, NULL);
        fprintf(file_pointer, "<pre>\n");
    }

    return file_pointer;
}

void flush_buffer()
{
    int symbol = 0;

    while ((symbol = getchar()) != '\n' && symbol != EOF) {
        continue;
    }
}

bool check_equal_with_accuracy(double number_1, double number_2, double accuracy)
{
    MYASSERT(isfinite(number_1), NON_FINITE_NUM_PASSED_TO_FUNC, return false);
    MYASSERT(isfinite(number_2), NON_FINITE_NUM_PASSED_TO_FUNC, return false);
    MYASSERT(isfinite(accuracy), NON_FINITE_NUM_PASSED_TO_FUNC, return false);


    return (fabs (number_1 - number_2) < accuracy);
}




