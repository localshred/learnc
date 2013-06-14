#include <stdio.h>

int main(int argc, char *argv[])
{
  char *states[] = {
    "California",
    "Oregon",
    "Washington",
    "Texas"
  };
  int num_states = 4;

  int i = 0;
  while(i < argc) {
    printf("arg %d: %s\n", i, argv[i]);
    if (i < num_states)
      states[i] = argv[i];
    i++;
  }

  i = 0;
  while(i < num_states) {
    printf("state %d: %s\n", i, states[i]);
    i++;
  }

  return 0;
}
