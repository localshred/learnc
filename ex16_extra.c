// stdio gives NULL macro, printf()
#include <stdio.h>

// gives us assert()
#include <assert.h>

// stdlib gives us NULL macro, size_t type that is the result of sizeof keyword,
//        malloc(), and free()
#include <stdlib.h>

// gives us strdup()
#include <string.h>

struct Person {
  char *name;
  int age;
  int height;
  int weight;
};

struct Person Person_create(char *name, int age, int height, int weight)
{
  // Allocate the size of a Person struct in memory
  // and store the pointer to that new block.
  struct Person who;

  // Ensure that the new pointer is valid.
  assert(&who != NULL);

  // Dereference each member of the person struct
  // and assign the value to that block of memory.
  who.name = strdup(name);
  who.age = age;
  who.height = height;
  who.weight = weight;

  // Return the pointer to the new person memory block.
  return who;
}

void Person_destroy(struct Person who)
{
  // Make sure this pointer is not already freed.
  assert(&who != NULL);

  // Release the memory for the stored name.
  free(who.name);
}

// Dereference each member of the given person object
// and print it.
void Person_print(struct Person who)
{
  printf("Name: %s\n", who.name);
  printf("\tAge: %d\n", who.age);
  printf("\tHeight: %d\n", who.height);
  printf("\tWeight: %d\n", who.weight);
}

int main(int argc, char *argv[])
{
  // Create joe and frank people.
  struct Person joe = Person_create("Joe Alex", 32, 64, 140);
  struct Person frank = Person_create("Frank Blank", 20, 72, 180);

  // print them out and where they are in memory
  printf("Joe is at memory location %p:\n", &joe);
  Person_print(joe);

  printf("Frank is at memory location %p:\n", &frank);
  Person_print(frank);

  // make everyone age 20 years and print them again
  joe.age += 20;
  joe.height -= 2;
  joe.weight += 40;
  Person_print(joe);

  frank.age += 20;
  frank.weight += 20;
  Person_print(frank);

  Person_destroy(joe);
  Person_destroy(frank);

  return 0;
}

