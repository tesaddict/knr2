#include <stdio.h>
#include <stdlib.h>

extern void chapter_one_entrypoint(int idx);

#define EXPECTED_ARGUMENTS 3
int main(int argc, char *argv[]) {
  if (argc != EXPECTED_ARGUMENTS) {
    printf("Program expects arguments in the form: ./knr2 1 15\nFirst argument is chapter, second argument is exercise number.\nPlease try again!\n");
    return -1;
  }
  char *end;
  int chapter = strtol(argv[1], &end, 10);
  if (argv[1] == end) {
    printf("First parameter (chapter parameter) must be integer!\n");
    return -1;
  }

  int exercise = strtol(argv[2], &end, 10);
  if (argv[2] == end) {
    printf("Second parameter (exercise parameter) must be integer!\n");
    return -1;
  }
  chapter_one_entrypoint(exercise);
}
