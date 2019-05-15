#include <stdio.h>
#include <stdint.h>
#include <stddef.h>

int main(void)
{
	printf("\n_______ PADDING TEST _______\n");
	printf(" Type:        Size in bytes:\n");
	printf("  void             %lu\n", sizeof(void));
	printf("  char             %lu\n", sizeof(unsigned char));
	printf("  short            %lu\n", sizeof(short));
	printf("  int              %lu\n", sizeof(int));
	printf("  float            %lu\n", sizeof(float));
	printf("  double           %lu\n", sizeof(double));
	printf("  size_t           %lu\n", sizeof(size_t));
	printf("  intmax_t         %lu\n", sizeof(intmax_t));
	printf("  ptrdiff_t        %lu\n", sizeof(ptrdiff_t));
	printf("  pointer          %lu\n", sizeof(void*));
	printf("  long long        %lu\n", sizeof(long long));
	printf("  long double      %lu\n", sizeof(long double));
	printf("  va_list          %lu\n", sizeof(va_list));
	printf("‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾\n\n");
	return (0);
}
