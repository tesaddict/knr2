#include "knr2_string.h"
#include <stdlib.h>
#include <string.h>

#define KNR2_STRING_DEFAULT_LIMIT 5

struct _knr2_string_t{
  char *data;
  size_t size;
  size_t limit;
};

knr2_string_t *knr2_string_init(void) {
  size_t limit = KNR2_STRING_DEFAULT_LIMIT;
  knr2_string_t *str = malloc(sizeof(struct _knr2_string_t));
  str->data = malloc(sizeof(char) * limit);
  str->size = 0U;
  str->data[str->size] = '\0';
  str->limit = limit;
  return str;
}

void knr2_string_free(knr2_string_t *str) {
  free(str->data);
  str->data = NULL;
  str->size = 0;
  str->limit = 0;
  free(str);
}

static void knr2_string_expand_limit(knr2_string_t *str) {
  size_t new_limit = str->limit * 1.5;
  char *new_data = malloc(sizeof(char) * new_limit);
  memcpy(new_data, str->data, str->size);
  free(str->data);
  str->data = new_data;
  str->data[str->size] = '\0';
  str->limit = new_limit;
}

void knr2_string_push(knr2_string_t *str, const char character)  {
  if ((str->limit - 1U) == str->size) {
    knr2_string_expand_limit(str);
  }
  str->data[str->size] = character;
  str->size++;
  // Size should always be pointing to the NULL terminator.
  str->data[str->size] = '\0';
}

char knr2_string_pop(knr2_string_t *str) {
  if (str->size == 0) {
    return '\0';
  }
  str->size--;
  char return_value = str->data[str->size];
  str->data[str->size] = '\0';
  return return_value;
}

void knr2_string_copy(knr2_string_t *dest, const knr2_string_t *src) {
  if (dest->limit < src->limit) {
    free(dest->data);
    dest->data = malloc(sizeof(char) * src->limit);
  }
  memcpy(dest->data, src->data, src->size);
  dest->limit = src->limit;
  dest->size = src->size;
  dest->data[dest->size] = '\0';
}

void knr2_string_clear(knr2_string_t *str) {
  str->size = 0;
  str->data[str->size] = '\0';
}

size_t knr2_string_get_size(const knr2_string_t *str) {
  return str->size;
}

const char* knr2_string_get_cstr(const knr2_string_t *str) {
  return str->data;
}


int knr2_string_getline(knr2_string_t *str) {
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
