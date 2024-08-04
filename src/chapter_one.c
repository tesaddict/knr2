#include "knr2_string.h"
#include <stdio.h>
#include <string.h>

void chapter_one_exercise_1(void) {
  printf("hello world!\n\v");
}

void chapter_one_exercise_3(void) {
  int fahr, celsius;
  int lower, upper, step;
  lower = 0;
  upper = 200;
  step = 20;
  fahr = lower;
  printf("Convert F to C using Integers.\n");
  while (fahr <= upper) {
    celsius = 5 * (fahr - 32) / 9;
    printf("%5d%10d\n", fahr, celsius);
    fahr += step;
  }

  printf("\n");
  float f_fahr, f_celsius;
  lower = 0;
  f_fahr = lower;

  printf("Convert F to C using Floats.\n");
  while (f_fahr <= upper) {
    f_celsius = (5.0 / 9.0) * (f_fahr - 32.0);
    printf("%6.2f%10.2f\n", f_fahr, f_celsius);
    f_fahr += step;
  }
}

void chapter_one_exercise_4(void) {
  float cel, fahr;
  int upper, step;
  upper = 200;
  step = 20;
  cel = 0.0;
  printf("\nConvert C to F using Floats!\n");
  while (cel <= upper) {
    fahr = (9.0 / 5.0) * cel + 32;
    printf("%5.0f%12.2f\n", cel, fahr);
    cel += step;
  }
}

void chapter_one_exercise_5(void) {
  printf("\nReverse the list for F to C conversion!\n");
  for (float fahr = 300; fahr >= 0; fahr -= 20) {
    printf("%5.0f%10.2f\n", fahr, (5.0 / 9.0) * fahr - 32.0);
  }
}

void chapter_one_exercise_7(void) {
  char c[] = { '\n', 't', EOF, '\n', '\0' };
  printf("test\n");
  printf("%s", c);
}

void chapter_one_exercise_8(void) {
  char c;
  long count = 0;
  while ((c = getchar()) != EOF) {
    if (c == '\n' || c == '\t' || c == ' ')
      count++;
  }
  printf("I have counted: \n%ld\n tabs, spaces or newlines!\n", count);
}

void chapter_one_exercise_9(void) {
  char c;
  char last_char;
  while ((c = getchar()) != '\n') {
    if (c == ' ') {
      last_char = ' ';
      continue;
    } 
    if (last_char == ' ') {
      putchar(last_char);
      last_char = c;
    }
    putchar(c);
  }
}

void chapter_one_exercise_10(void) {
  char c;
  while ((c = getchar()) != EOF) {
    if (c == '\b') {
      putchar('\\');
      putchar('b');
    } else if (c == '\t') {
      putchar('\\');
      putchar('t');
    } else if (c == '\\') {
      putchar('\\');
      putchar('\\');
    } else {
      putchar(c);
    }
  }
}

#define INSIDE_WORD 1
#define OUTSIDE_WORD 0
void chapter_one_exercise_12(void) {
  char c;
  int state = INSIDE_WORD;
  while ((c = getchar()) != EOF) {
    if (c == ' ') {
      state = OUTSIDE_WORD;
    } else if (state == OUTSIDE_WORD) {
      state = INSIDE_WORD;
      putchar('\n');
      putchar(c);
    } else {
      putchar(c);
    }
  }
}

#define MAXIMUM_WORD_LENGTH 30
void chapter_one_exercise_13(void) {
  char c;
  int state = INSIDE_WORD;
  int word_length_count[MAXIMUM_WORD_LENGTH] = { 0 };
  int current_word_length = 0;
  while ((c = getchar()) != '\n') {
    if (c == ' ') {
      state = OUTSIDE_WORD;
    } else if (state == OUTSIDE_WORD) {
      state = INSIDE_WORD;
      if (current_word_length < MAXIMUM_WORD_LENGTH) {
        word_length_count[current_word_length]++;
      }
      current_word_length = 0;
    } else {
      current_word_length++;
    }
  }

  for (int i = 0; i < MAXIMUM_WORD_LENGTH; i++) {
    if (word_length_count[i] == 0) {
      continue;
    }
    printf("Word Length %d : ", i);
    for (int j = 0; j < word_length_count[i]; j++) {
      printf("|");
    }
    printf("\n");
  }
}

void chapter_one_exercise_14(void) {
  printf("Exercise 14 will count all character occurences in a line and output a histogram of occurences.\nPlease pass EOF to program when you are done using CTRL-D.\n");
  char c;
  int c_occurence[26] = { 0 };
  while ((c = getchar()) != '\n') {
    if (c >= 'a' && c <= 'z') {
      c_occurence[c - 'a']++;
    } else if (c >= 'A' && c <= 'Z') {
      c_occurence[c - 'A']++;
    }
  }

  for (int i = 0; i < 26; i++) {
    if (c_occurence[i] == 0) continue;
    printf("%c : ", 'a' + i);
    for (int j = 0; j < c_occurence[i]; j++) {
      printf("|");
    }
    printf("\n");
  }
}

static int chapter_one_getline(knr2_string_t *str) {
  char c;
  size_t idx = 0;
  while(1) {
    c = getchar();
    if (c == EOF) {
      return 0;
    }
    knr2_string_push(str, c);
    if (c == '\n') {
      break;
    }
  }
  return 1;
}

#define STARTING_LIMIT 5
void chapter_one_exercise_16(void) {
  printf("Exercise 16 will return the longest line a user enters.\nPlease pass EOF to program when you are done using CTRL-D.\n");
  knr2_string_t *line = knr2_string_init();
  knr2_string_t *longest = knr2_string_init();
  while (chapter_one_getline(line)) {
    if (knr2_string_get_size(line) > knr2_string_get_size(longest)) {
      knr2_string_copy(longest, line);
      knr2_string_clear(line);
    }
  }
  printf("%s", knr2_string_get_cstr(longest));
}

void chapter_one_exercise_17(void) {
  printf("Exercise 17 will only echo line inputs larger than 80 characters.\nPlease pass EOF to program when you are done using CTRL-D.\n");
  knr2_string_t *string = knr2_string_init();
  while(chapter_one_getline(string)) {
    if (knr2_string_get_size(string) > 80U) {
      printf("%s", knr2_string_get_cstr(string));
    }
    knr2_string_clear(string);
  }
}

static knr2_string_t *chapter_one_get_string_with_escape_chars_visible(knr2_string_t *str) {
  knr2_string_t *return_str = knr2_string_init();
  const char *cstr = knr2_string_get_cstr(str);
  while(*cstr != '\0') {
    if (*cstr == '\b') {
      knr2_string_push(return_str, '\\');
      knr2_string_push(return_str, 'b');
    } else if (*cstr == '\t') {
      knr2_string_push(return_str, '\\');
      knr2_string_push(return_str, 't');
    } else if (*cstr == ' ') {
      knr2_string_push(return_str, '\\');
      knr2_string_push(return_str, 's');
    } else if (*cstr == '\n') {
      knr2_string_push(return_str, '\\');
      knr2_string_push(return_str, 'n');
      knr2_string_push(return_str, '\n');
    } else {
      knr2_string_push(return_str, *cstr);
    }
    cstr++;
  }
  return return_str;
}

void chapter_one_exercise_18(void) {
  printf("Exercise 18 will remove trailing tabs or spaces from each line.\nPlease pass EOF to program when you are done using CTRL-D.\n");
  knr2_string_t *str = knr2_string_init();
  char c;
  while(chapter_one_getline(str)) {
    // remove newline
    knr2_string_pop(str);
    char previous;
    while ((previous = knr2_string_pop(str)) == '\t' || previous == ' ') {
      // keep removing characters until we encounter something other than tab or space.
    }
    knr2_string_push(str, previous);
    knr2_string_push(str, '\n');
    knr2_string_t *formatted = chapter_one_get_string_with_escape_chars_visible(str);
    printf("%s", knr2_string_get_cstr(formatted));
    knr2_string_free(formatted);
    knr2_string_clear(str);
  }
}

void chapter_one_exercise_19(void) {
  printf("Exercise 19 will reverse the input string line-by-line.\nPlease pass EOF to program when you are done using CTRL-D.\n");
  knr2_string_t *str = knr2_string_init();
  knr2_string_t *rev_str = knr2_string_init();
  while(chapter_one_getline(str)) {
    while(knr2_string_get_size(str)) {
      knr2_string_push(rev_str, knr2_string_pop(str));
    }
    knr2_string_clear(str);
    printf("%s\n", knr2_string_get_cstr(rev_str));
    knr2_string_clear(rev_str);
  }
}

// N should be a parameter with a reasonable default. This would allow a user
// to change how many spaces a tab represents without having to re-compile to 
// program if they wish to change the symbolic variable. I have not designed
// a mechanism to pass in parameters to these exercise, so in the below example
// I used a symbolic variable.
void chapter_one_exercise_20(void) {
  printf("Exercise 20 replace tabs with spaces.\nPlease pass EOF to program when you are done using CTRL-D.\n");
  knr2_string_t *str = knr2_string_init();
  knr2_string_t *ans_str = knr2_string_init();
  const size_t TABS_TO_SPACES = 4;
  while(chapter_one_getline(str)) {
    const char *cstr = knr2_string_get_cstr(str);
    while (*cstr != '\0') {
      if (*cstr == '\t') {
        for (size_t i = 0; i < TABS_TO_SPACES; i++) {
          knr2_string_push(ans_str, ' ');
        }
      } else {
        knr2_string_push(ans_str, *cstr);
      }
      cstr++;
    }
    knr2_string_clear(str);
    knr2_string_t *formatted = chapter_one_get_string_with_escape_chars_visible(ans_str);
    knr2_string_clear(ans_str);
    printf("%s", knr2_string_get_cstr(formatted));
    knr2_string_free(formatted);
  }
}

// When either a tab or space would suffice to reach a tab stop I think 
// the space should be given priority. A tab is not rendered the same way
// on all machines. It is meant to compress a program to use less space,
// but if the tab stop and space is equivalent no compression is possible.
void chapter_one_exercise_21(void) {
  printf("Exercise 21 replace spaces with tabs and spaces.\nPlease pass EOF to program when you are done using CTRL-D.\n");
  printf("If the number of spaces is 5 and a tab stop is 2, there should be 2 tabs and 1 space after processing.\n");
  knr2_string_t *str = knr2_string_init();
  knr2_string_t *ans_str = knr2_string_init();
  const size_t TABSTOP = 2;
  while(chapter_one_getline(str)) {
    const char *cstr = knr2_string_get_cstr(str);
    size_t space_cnt = 0U;
    while (*cstr != '\0') {
      if (*cstr == ' ') {
        space_cnt++;        
      } else {
        size_t tab_cnt = space_cnt / TABSTOP;
        space_cnt = space_cnt % TABSTOP;
        while (tab_cnt != 0) {
          knr2_string_push(ans_str, '\t');
          tab_cnt--;
        }
        while (space_cnt != 0) {
          knr2_string_push(ans_str, ' ');
          space_cnt--;
        }
        knr2_string_push(ans_str, *cstr);
      }
      cstr++;
    }
    knr2_string_clear(str);
    knr2_string_t *formatted = chapter_one_get_string_with_escape_chars_visible(ans_str);
    knr2_string_clear(ans_str);
    printf("%s", knr2_string_get_cstr(formatted));
    knr2_string_free(formatted);
  }
}

void chapter_one_exercise_22(void) {
  printf("Exercise 22 fold line at n characters.\nPlease pass EOF to program when you are done using CTRL-D.\n");
  const size_t FOLD = 20;
  int state = INSIDE_WORD;
  char prev_c;
  knr2_string_t *str = knr2_string_init();
  knr2_string_t *ans_str = knr2_string_init();
  while (chapter_one_getline(str)) {
    const char *cstr = knr2_string_get_cstr(str);
    size_t count = 0;
    while (*cstr != '\0') {
      if (*cstr == ' ') {
        state = OUTSIDE_WORD;
      } else {
        state = INSIDE_WORD;
      }
      if (count >= FOLD && state == INSIDE_WORD && prev_c == ' ') {
        count = 0;
        knr2_string_push(ans_str, '\n');
      } else if (state == INSIDE_WORD && count >= FOLD && prev_c != ' ') {
        count = 0;
        knr2_string_push(ans_str, '-');
        knr2_string_push(ans_str, '\n');
      }
      knr2_string_push(ans_str, *cstr);
      prev_c = *cstr;
      count++;
      cstr++;
    }
    printf("%s", knr2_string_get_cstr(ans_str));
    knr2_string_clear(ans_str);
    knr2_string_clear(str);
  }
}

#define ENCOUNTERED_NONE 0
#define ENCOUNTERED_ONE 1
#define ENCOUNTERED_BLOCK 2
void chapter_one_exercise_23(void) {
  printf("Exercise 23 removes comments from a C program.\nPlease pass EOF to program when you are done using CTRL-D.\n");
  knr2_string_t *str = knr2_string_init();
  knr2_string_t *ans_str = knr2_string_init();
  while(chapter_one_getline(str)) {
    int state = ENCOUNTERED_NONE;
    const char *cstr = knr2_string_get_cstr(str);
    while(*cstr != '\0') {
      if (*cstr == '/' && state == ENCOUNTERED_ONE) {
        knr2_string_push(ans_str, '\n');
        break;
      } else if (*cstr == '/') {
        state = ENCOUNTERED_ONE;
      } else if (state == ENCOUNTERED_ONE){
        knr2_string_push(ans_str, '/');
      } else {
        state = ENCOUNTERED_NONE;
        knr2_string_push(ans_str, *cstr);
      }
      cstr++;
    }
    printf("%s", knr2_string_get_cstr(ans_str));
    knr2_string_clear(ans_str);
    knr2_string_clear(str);
  }

}

static void (*exercise_func_ptr[])(void) = {
  &chapter_one_exercise_1,
  NULL,
  &chapter_one_exercise_3,
  &chapter_one_exercise_4,
  &chapter_one_exercise_5,
  NULL,
  &chapter_one_exercise_7,
  &chapter_one_exercise_8,
  &chapter_one_exercise_9,
  &chapter_one_exercise_10,
  NULL,
  &chapter_one_exercise_12,
  &chapter_one_exercise_13,
  &chapter_one_exercise_14,
  NULL,
  &chapter_one_exercise_16,
  &chapter_one_exercise_17,
  &chapter_one_exercise_18,
  &chapter_one_exercise_19,
  &chapter_one_exercise_20,
  &chapter_one_exercise_21,
  &chapter_one_exercise_22,
  &chapter_one_exercise_23,
};

void chapter_one_entrypoint(int idx) {
  if (idx == 0) {
    printf("Exercise number 0 does not exist!\n");
    return;
  }
  idx -= 1;
  if (idx >= sizeof(exercise_func_ptr)) {
    printf("Exercise number %d does not exist!\n", idx + 1);
    return;
  }
  void (*requested_func_ptr)(void) = exercise_func_ptr[idx];
  if (requested_func_ptr == NULL) {
    printf("Exercise number %d has not been implemented!\n", idx + 1);
    return;
  }
  requested_func_ptr();
}
