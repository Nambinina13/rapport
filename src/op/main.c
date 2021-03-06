#include <stdio.h> 
#include <stdlib.h>

typedef float float2 __attribute__((ext_vector_type(2)));
typedef float float4 __attribute__((ext_vector_type(4)));
typedef float float8 __attribute__((ext_vector_type(8)));
typedef float float16 __attribute__((ext_vector_type(16)));
typedef double double2 __attribute__((ext_vector_type(2)));
typedef double double4 __attribute__((ext_vector_type(4)));
typedef double double8 __attribute__((ext_vector_type(8)));
typedef double double16 __attribute__((ext_vector_type(16)));


REAL perform_vector_binary_op(unsigned long long size, char op, REAL a, REAL b) {
  switch (size) {
  case 2:
  case 4:
  case 8:
  case 16:
    switch (op) {
    case '+':
      return (a) + (b);
    case '*':
      return (a) * (b);
    case '-':
      return (a) - (b);
    case '/':
      return (a) / (b);
    default:
      fprintf(stderr, "Bad op %c\n", op);
      exit(EXIT_FAILURE);
    };
  default:
    fprintf(stderr, "Bad size %llu\n", size);
    exit(EXIT_FAILURE);
  };
}


int main(int argc, char **argv)
{
  char *precision = argv[1];
  char op = argv[2][0];
  unsigned long long size = strtoll(argv[3], NULL, 10);

  printf("\nexample:\n");
  REAL a;
  for (int i = 0; i < size; i++)
    a[i] = (strtod(argv[4], NULL)) + i;

  for (int i = 0; i < size; i++)
    printf("a: %lf\n", a[i]);


  REAL b;
  for (int i = 0; i < size; i++)
    b[i] = (strtod(argv[5], NULL)) + i;

  for (int i = 0; i < size; i++)
    printf("b: %lf\n", b[i]);

  printf("\n");

  REAL c = perform_vector_binary_op(size, op, a, b);

  printf("\nexample:\n");
  for (int i = 0; i < size; i++)
    printf("c: %lf\n", c[i]);
  
  return 0;
}
