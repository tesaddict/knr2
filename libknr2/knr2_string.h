#ifndef __KNR2_STRING_H_
#define __KNR2_STRING_H_

#include <stdint.h>
#include <stdio.h>

typedef struct _knr2_string_t knr2_string_t;

knr2_string_t *knr2_string_init(void);
void knr2_string_free(knr2_string_t *str);
void knr2_string_push(knr2_string_t *str, const char character);
char knr2_string_pop(knr2_string_t *str);
void knr2_string_copy(knr2_string_t *dest, const knr2_string_t *src);
void knr2_string_clear(knr2_string_t *str);
size_t knr2_string_get_size(const knr2_string_t *str);
const char* knr2_string_get_cstr(const knr2_string_t *str);
int knr2_string_getline(knr2_string_t *str);

#endif // __KNR2_STRING_H_
