#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

#define MAX_WORDS 1000
#define MAX_WORD_LENGTH 50

// Function to convert a word to lowercase
void convert_to_lowercase(char *word) {
    for (int i = 0; word[i]; ++i) {
        word[i] = tolower(word[i]);
    }
}

// Function to check if a character is a valid word character (alphanumeric or apostrophe)
bool is_valid_char(char c) {
    return isalnum(c) || c == '\'';
}

int main() {
    char input_paragraph[10000];
    printf("Enter a paragraph:\n");
    fgets(input_paragraph, sizeof(input_paragraph), stdin);

    int word_frequency[MAX_WORDS] = {0};
    char unique_words[MAX_WORDS][MAX_WORD_LENGTH];

    char *token = strtok(input_paragraph, " \n");
    int num_unique_words = 0;

    while (token != NULL) {
        // Convert the token to lowercase
        convert_to_lowercase(token);

        // Remove any trailing punctuation
        int len = strlen(token);
        while (len > 0 && !is_valid_char(token[len - 1])) {
            token[len - 1] = '\0';
            len--;
        }

        // Check if the token is already in our list of words
        int found = 0;
        for (int i = 0; i < num_unique_words; ++i) {
            if (strcmp(unique_words[i], token) == 0) {
                word_frequency[i]++;
                found = 1;
                break;
            }
        }

        // If not found, add it to the list
        if (!found) {
            strcpy(unique_words[num_unique_words], token);
            word_frequency[num_unique_words] = 1;
            num_unique_words++;
        }

        // Get the next token
        token = strtok(NULL, " \n");
    }

    printf("Word frequencies:\n");
    for (int i = 0; i < num_unique_words; ++i) {
        printf("%s: %d\n", unique_words[i], word_frequency[i]);
    }

    return 0;
}
