#include <stdio.h>
#include <string.h>

#define MAX_SENTENCE 1000
#define MAX_WORD 30

int main()
{
    char sentence[MAX_SENTENCE];

    scanf("%[^\n]", sentence); // Không bao gồm dấu \n ở trong chuỗi
    // fgets(sentence, MAX_SENTENCE, stdin); // Có bao gồm dấu \n ở trong chuỗi
    
    int freq[MAX_WORD + 1] = {};

    char* word = strtok(sentence, " ");
    while (word != NULL) {
        int length = strlen(word);
        freq[length]++;

        word = strtok(NULL, " ");
    }

    int numerator = 0;
    int denominator = 0;

    for (int i = 1; i <= MAX_WORD; i++) {
        if (freq[i] > 0) {
            numerator += i * freq[i];
            denominator += i;
        }
    }

    double average = (double)numerator / denominator;

    printf("%.2f", average);

    return 0;
}