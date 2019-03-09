#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//from ananthakumaran

#define RAND_P(X) (rand() % (X) == 0)

const int frequency[] = {
  0, 8167, 9659, 12441, 16694, 29396, 31624, 33639, 39733, 46699, 46852,
  47624, 51649, 54055, 60804, 68311, 70240, 70335, 76322, 82649, 91705,
  94463, 95441, 97801, 97951, 99925, 99999
};

typedef struct Word {
  struct Word *next;
  char *text;
} Word;

char rand_letter()
{
  int f = rand() % 100000;
  int i;
  for(i = 25; i > 0; i--) {
    if(f >= frequency[i])
      break;
  }

  return 97 + i;
}

int rand_between(int a, int b)
{
  return rand() % (b - a + 1) + a;
}

char *generate_word(int capitalize, int period)
{
  int size = rand_between(1, 12);
  char *text = malloc(sizeof(char) * (size + 4));
  int i;

  int number = RAND_P(50);

  for(i = 0; i < size; i++) {

    if(number) {
      text[i] = rand_between(48, 57);
    } else {
      text[i] = rand_letter();

      if(i == 0 && capitalize) {
	text[i] -= 32;
      }
    }
  }

  if(period) {
    if(RAND_P(10)) {
      text[i++] = RAND_P(2) ? '!' : '?';
    } else {
      text[i++] = '.';
    }
  }


  if(period && RAND_P(7)) {
    if(RAND_P(2)) {
      text[i++] = '\n';
    }

    text[i++] = '\n';
  } else {

    if(RAND_P(10) && !period) {
      text[i++] = ',';
    }

    text[i++] = ' ';
  }

  text[i] = '\0';

  return text;
}

Word *generate_sentence(Word *top, size_t *word_size)
{
  *word_size = rand_between(3, 8);
  size_t i;
  Word *last = top;

  for(i = 0; i < *word_size; i++) {
    Word *temp = malloc(sizeof(Word));
    temp->text = generate_word(!i, !(*word_size - i - 1));
    temp->next = NULL;
    last->next = temp;
    last = temp;
  }

  return last;
};

Word *filler_text(int approx_words)
{
  Word *top = malloc(sizeof(Word));
  top->text = "";
  Word *last = top;
  size_t sentence_size = 0;

  while(approx_words > 0) {
    last = generate_sentence(last, &sentence_size);
    approx_words -= sentence_size;
  }

  return top;
}

int main() {
  srand(time(NULL));
  Word *garbage = filler_text(1000);

  while(garbage != NULL) {
    printf("%s", garbage->text);
    garbage = garbage->next;
  }

  printf("\n");
}
