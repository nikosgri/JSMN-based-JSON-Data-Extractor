/*
 * json_extracter.h
 *
 *  Created on: Nov 9, 2024
 *      Author: Nikolaos Grigoriadis
 *      Email : n.grigoriadis09@gmail.com
 *      Title : Embedded software engineer
 *      Degree: BSc and MSc in computer science, university of Ioannina
 */

#ifndef JSON_EXTRACTER_H_
#define JSON_EXTRACTER_H_

#include <jsmn.h>

#define TOKEN_SIZE                                                             \
  256 /**< Defines the maximum number of tokens for the JSON parsing */

/**
 * @struct VariableHolder
 * @brief Structure to hold parsed data either as integers or strings.
 *
 * This structure stores both the integer and string representations of
 * extracted values. It also includes a flag (`is_int`) to indicate whether the
 * value is an integer or a string.
 */
struct VariableHolder {
  int int_val; /**< Integer value for storing parsed integers. */
  char string_val[TOKEN_SIZE]; /**< String value for storing parsed strings. */
  int is_int; /**< Flag to indicate whether the value is an integer (1) or a
                 string (0). */
};

typedef struct VariableHolder VariableHolderType;

/*Function prototype*/
int extract_json_data(const char *json_string, const char *keys[],
                      int key_count, VariableHolderType *variables);

#endif /* JSON_EXTRACTER_H_ */
