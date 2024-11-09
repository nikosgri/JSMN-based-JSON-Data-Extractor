/*
 * main.c
 *
 *  Created on: Nov 9, 2024
 *      Author: Nikolaos Grigoriadis
 *      Email : n.grigoriadis09@gmail.com
 *      Title : Embedded software engineer
 *      Degree: BSc and MSc in computer science, university of Ioannina
 */

#include <jsmn_json_extractor.h>

/**
 * @brief Main entry point for the program that demonstrates the JSON
 * extraction.
 *
 * This function creates a sample JSON string, defines a list of keys to
 * extract, and uses the `extract_json_data` function to extract the
 * corresponding values. It then prints the extracted values to the console.
 *
 * @return 0 on success.
 */
int main() {
  // Sample JSON string containing various data types (integers and strings)
  const char *json_string =
      "{\"1\":123,\"2\":\"0x1\",\"3\":23,\"5\":\"device\",\"6\":\"example_"
      "string\",\"7\":456,\"8\":\"0x2A\",\"9\":789,\"10\":\"another_device\"}";

  // Keys to extract from the JSON string
  const char *keys[] = {"1", "5", "6", "7", "10"};
  int key_count = 5; /**< Number of keys to extract */

  VariableHolderType
      variables[key_count]; /**< Array to hold the extracted values */

  /*Call the extraction function*/
  int result = extract_json_data(json_string, keys, key_count, variables);
  if (result == 0) {
    /*Print the extracted values*/
    for (int i = 0; i < key_count; i++) {
      printf("Key: %s, Value: ", keys[i]);
      if (variables[i].is_int) {
        printf("%d\n",
               variables[i]
                   .int_val); /**< Print as integer if value is an integer */
      } else {
        printf("%s\n",
               variables[i]
                   .string_val); /**< Print as string if value is a string */
      }
    }
  } else {
    printf("Error extracting JSON data\n");
  }

  return 0; /**< Return success */
}