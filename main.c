/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarthel <abarthel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/06 13:09:39 by abarthel          #+#    #+#             */
/*   Updated: 2018/11/10 13:53:09 by abarthel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <ctype.h>
#include <string.h> // if not included in libft.h
#include "libft.h"

int		main(int argc, char **argv)
{
	(void)argc;
	(void)argv;

	// Test strlen
	printf("strlen: %lu\tft_strlen: %lu\n", strlen("Hello, we are here for the 42prog!\0"), ft_strlen("Hello, we are here for the 42prog!\0"));
	printf("strlen: %lu\tft_strlen: %lu\n", strlen("\0"), ft_strlen("\0"));

	// Test strcmp
	printf("strcmp: %d\tft_strcmp: %d\n", strcmp("aab\0", "aac\0"), ft_strcmp("aab\0", "aac\0"));
	
	// Test strncmp
	printf("strncmp: %d\tft_strncmp: %d\n", strncmp("aab\0", "aac\0", 4), ft_strncmp("aab\0", "aac\0", 4));
	
	// Test strstr
	printf("strstr: %s\tft_strstr: %s\n", strstr("sssaaaaallllut !\0", "llut\0"), ft_strstr("sssaaaaallllut !\0", "llut\0"));
	
	// Test strcat
	char string1[10] = "hello";
	char string2[10] = "hello";
	string1[9] = '\0';
	string2[9] = '\0';
	printf("strcat: %s\tft_strcat: %s\n", strcat(string1, "OK"), ft_strcat(string2, "OK"));
	
	// Test strncat
	char stringn1[10] = "hello";
	char stringn2[10] = "hello";
	stringn1[9] = '\0';
	stringn2[9] = '\0';
	printf("strncat: %s\tft_strncat: %s\n", strncat(stringn1, "OK", 5), ft_strncat(stringn2, "OK", 5));
	
	// Test strlcat
	char stringl1[10] = "hello";
	char stringl2[10] = "hello";
	stringl1[9] = '\0';
	stringl2[9] = '\0';
	printf("strlcat: %lu\tft_strlcat: %lu\n", strlcat(stringl1, "OKoklpointhiu\0", 4), ft_strlcat(stringl2, "OKoklpointhiu\0", 4));
	
	// Test strcpy
	char stringc1[10] = "hello";
	char stringc2[10] = "hello";
	stringc1[9] = '\0';
	stringc2[9] = '\0';
	printf("strcpy: %s\tft_strcpy: %s\n", strcpy(stringc1, "OKo\0"), ft_strcpy(stringc2, "OKo\0"));
	
	// Test strncpy
	char stringcn1[10] = "hello";
	char stringcn2[10] = "hello";
	stringcn1[9] = '\0';
	stringcn2[9] = '\0';
	printf("strncpy: %s\tft_strncpy: %s\n", strncpy(stringcn1, "OKo2", 1), ft_strncpy(stringcn2, "OKo2", 1));

	// No test for strdup

	// Test isalpha
	printf("isalpha: %d\tft_isalpha: %d\n", isalpha('z'), ft_isalpha('z'));

	// Test isdigit
	printf("isdigit: %d\tft_isdigit: %d\n", isdigit(5), ft_isdigit(0));

	// Test isalnum
	printf("isalnum: %d\tft_isalnum: %d\n", isalnum('0'), ft_isalnum('0'));

	// Test isascii
	printf("isascii: %d\tft_isascii: %d\n", isascii('\t'), ft_isascii('\t'));

	// Test isprint
	printf("isprint: %d\tft_isprint: %d\n", isprint(0), ft_isprint(0));

	// Test toupper
	printf("toupper: %c\tft_toupper: %c\n", toupper('a'), ft_toupper('a'));

	// Test tolower
	printf("tolower: %c\tft_tolower: %c\n", tolower('Z'), ft_tolower('Z'));
	printf("tolower: %c\tft_tolower: %c\n", tolower('1'), ft_tolower('1'));
	printf("tolower: %c\tft_tolower: %c\n", tolower('a'), ft_tolower('a'));

	// Test atoi
	printf("atoi: %d\tft_atoi: %d\n", atoi("     \t  -4218989898989898985auhljh"), ft_atoi("     \t  -4218989898989898985auhljh"));
	printf("atoi: %d\tft_atoi: %d\n", atoi("     \t  -4218989898989898986auhljh"), ft_atoi("     \t  -4218989898989898986auhljh"));
	printf("atoi: %d\tft_atoi: %d\n", atoi("+42"), ft_atoi("+42"));
	printf("atoi: %d\tft_atoi: %d\n", atoi("+2147483647"), ft_atoi("+2147483647"));
	printf("atoi: %d\tft_atoi: %d\n", atoi("-2147483648"), ft_atoi("-2147483648"));
	printf("atoi: %d\tft_atoi: %d\n", atoi("+2147483648"), ft_atoi("+2147483648"));
	printf("atoi: %d\tft_atoi: %d\n", atoi("+2147483647op"), ft_atoi("+2147483647op"));
	printf("atoi: %d\tft_atoi: %d\n", atoi("-2147483648op"), ft_atoi("-2147483648op"));
	printf("atoi: %d\tft_atoi: %d\n", atoi("+2147483648op"), ft_atoi("+2147483648op"));
	printf("atoi: %d\tft_atoi: %d\n", atoi("u     \t  -4218989898989898985auhljh"), ft_atoi("u     \t  -4218989898989898985auhljh"));
	printf("atoi: %d\tft_atoi: %d\n", atoi("99999999999999999999999999"), ft_atoi("99999999999999999999999999"));
	printf("atoi: %d\tft_atoi: %d\n", atoi("-99999999999999999999999999"), ft_atoi("-99999999999999999999999999"));
	printf("atoi: %d\tft_atoi: %d\n", atoi(" \t 99999999999999999999999998ppp"), ft_atoi(" \t 99999999999999999999999998ppp"));
	printf("atoi: %d\tft_atoi: %d\n", atoi(" \t -99999999999999999999999998ppp"), ft_atoi(" \t -99999999999999999999999998ppp"));


	// Test strnstr
	const char *largestring = "Foo Bar Baz";
	const char *smallstring = "Bar";
	char *ptr;
	char *fptr;
	ptr = strnstr(largestring, smallstring, 4);
	fptr = ft_strnstr(largestring, smallstring, 4);
	printf("strnstr: %s\tft_strnstr: %s\n", ptr, fptr);
	ptr = strnstr(largestring, smallstring, 3);
	fptr = ft_strnstr(largestring, smallstring, 3);
	printf("strnstr: %s\tft_strnstr: %s\n", ptr, fptr);
	ptr = strnstr(largestring, "", 0);
	fptr = ft_strnstr(largestring, "", 0);
	printf("strnstr: %s\tft_strnstr: %s\n", ptr, fptr);
	ptr = strnstr(largestring, smallstring, 8);
	fptr = ft_strnstr(largestring, smallstring, 8);
	printf("strnstr: %s\tft_strnstr: %s\n", ptr, fptr);
	ptr = strnstr(largestring, smallstring, 28);
	fptr = ft_strnstr(largestring, smallstring, 28);
	printf("strnstr: %s\tft_strnstr: %s\n", ptr, fptr);

	// Test strchr	
	printf("strchr: %s\tft_strchr: %s\n", strchr("sssaaaaallllut !\0", 108), ft_strchr("sssaaaaallllut !\0", 108));
	printf("strchr: %s\tft_strchr: %s\n", strchr("sssaaaaallllut !\0", 300), ft_strchr("sssaaaaallllut !\0", 300));
	printf("strchr: %s\tft_strchr: %s\n", strchr("", 108), ft_strchr("", 108));

	// Test strrchr	
	printf("strrchr: %s\tft_strrchr: %s\n", strrchr("sssaaaaallllut !\0", 108), ft_strrchr("sssaaaaallllut !\0", 108));
	printf("strrchr: %s\tft_strrchr: %s\n", strrchr("sssaaaaallllut !\0", 300), ft_strrchr("sssaaaaallllut !\0", 300));
	printf("strrchr: %s\tft_strrchr: %s\n", strrchr("", 108), ft_strrchr("", 108));

	// Test memset
	int data[3] = {1, 2, 3};
	char str[] = "almost every programmer should know memset!";
	int data1[3] = {1, 2, 3};
	char str1[] = "almost every programmer should know memset!";
	memset(data, 97, 2);
	ft_memset(data1, 97, 2);
	printf("memset: %d, %d, %d\tft_memset: %d, %d, %d\n", data[0], data[1], data[2], data1[0], data1[1], data1[2]);

	memset (str, '-', 2);
	ft_memset (str1, '-', 2);
	printf("memset: %s\tft_memset: %s\n", str, str1);

	char str2[] = "almost every programmer should know memset!";
	char str3[] = "almost every programmer should know memset!";
	memset ("okok", '-', 0);
	ft_memset ("okok", '-', 0);
	printf("memset: %s\tft_memset: %s\n", str2, str3);
	
	// Test bzero
	int datab[3] = {1, 2, 3};
	char strb[] = "almost every programmer should know memset!";
	int data1b[3] = {1, 2, 3};
	char str1b[] = "almost every programmer should know memset!";
	bzero(datab, 2);
	ft_bzero(data1b, 2);
	printf("bzero: %d, %d, %d\tft_bzero: %d, %d, %d\n", datab[0], datab[1], datab[2], data1b[0], data1b[1], data1b[2]);
	bzero(strb, 2);
	ft_bzero(str1b, 2);
	printf("bzero: %s\tft_bzero: %s\n", strb, str1b);
	
	// Test memcpy
	int datacsr[3] = {1, 2, 3};
	int datacde[3] = {999999, 2, 3};
	char strcsr[] = "every programmer should know memset!";
	char strcde[] = "X";
	int data1csr[3] = {1, 2, 3};
	int data1cde[3] = {999999, 2, 3};
	char strstrstr[] = "\n";
	char str1csr[] = "every programmer should know memset!";
	char str1cde[] = "X";
	memcpy(datacde, datacsr, 2);
	ft_memcpy(data1cde, data1csr, 2);
	printf("memcpy: %d, %d, %d\tft_memcpy: %d, %d, %d\n", datacde[0], datacde[1], datacde[2], data1cde[0], data1cde[1], data1cde[2]);
	memcpy(strcde, strcsr, 2); //conflict
	ft_memcpy(str1cde, str1csr, 2); //conflict
	printf("memcpy: %s\tft_memcpy: %s\n", strcde, str1cde);
	char str2csr[] = "programmer should know memset!";
	char str2cde[] = "abcdefghijklmnop";
	(void)strstrstr;
	char str3csr[] = "programmer should know memset!";
	char str3cde[] = "abcdefghijklmnop";
	memcpy(str2cde, str2csr, 4);
	ft_memcpy(str3cde, str3csr, 4);
	printf("memcpy: %s\tft_memcpy: %s\n", str2cde, str3cde);

	// Test memccpy
	int cdatacsr[3] = {1, 200, 3};
	int cdatacde[3] = {999999, 200, 3};
	char cstrcsr[] = "programmer should know memset!";
	char cstrcde[] = "Xioioioioio";
	int cdata1csr[3] = {1, 200, 3};
	int cdata1cde[3] = {999999, 200, 3};
	char cstrstrstr[] = "\n";
	char cstr1csr[] = "programmer should know memset!";
	char cstr1cde[] = "Xioioioioio";
	memccpy(cdatacde, cdatacsr, '\200',2);
	ft_memccpy(cdata1cde, cdata1csr, '\200', 2);
	printf("memccpy: %d, %d, %d\tft_memccpy: %d, %d, %d\n", cdatacde[0], cdatacde[1], cdatacde[2], cdata1cde[0], cdata1cde[1], cdata1cde[2]);
	memccpy(cstrcde, cstrcsr, 'o', 6);
	ft_memccpy(cstr1cde, cstr1csr, 'o', 6);
	printf("memccpy: %s\tft_memccpy: %s\n", cstrcde, cstr1cde);
	char cstr2csr[] = "programmer should know memset!";
	char cstr2cde[] = "abcdefghijklmnop";
	(void)cstrstrstr;
	char cstr3csr[] = "programmer should know memset!";
	char cstr3cde[] = "abcdefghijklmnop";
	memccpy(cstr2cde, cstr2csr, 0600, 4);
	ft_memccpy(cstr3cde, cstr3csr, 0600, 4);
	printf("memccpy: %s\tft_memccpy: %s\n", cstr2cde, cstr3cde);

	// Test memmove
	int mdatacsr[3] = {1, 2, 3};
	int mdatacde[3] = {999999, 2, 3};
	char mstrcsr[] = "every programmer should know memset!";
	char mstrcde[] = "X";
	int mdata1csr[3] = {1, 2, 3};
	int mdata1cde[3] = {999999, 2, 3};
	char mstrstrstr[] = "\n";
	char mstr1csr[] = "every programmer should know memset!";
	char mstr1cde[] = "X";
	memmove(mdatacde, mdatacsr, 2);
	ft_memmove(mdata1cde, mdata1csr, 2);
	printf("memmove: %d, %d, %d\tft_memmove: %d, %d, %d\n", mdatacde[0], mdatacde[1], mdatacde[2], mdata1cde[0], mdata1cde[1], mdata1cde[2]);
	memmove(mstrcde, mstrcsr, 2); //conflict
	ft_memmove(mstr1cde, mstr1csr, 2); //conflict
	printf("memmove: %s\tft_memmove: %s\n", mstrcde, mstr1cde);
	char mstr2csr[] = "programmer should know memset!";
	char mstr2cde[] = "abcdefghijklmnop";
	(void)mstrstrstr;
	char mstr3csr[] = "programmer should know memset!";
	char mstr3cde[] = "abcdefghijklmnop";
	memmove(mstr2cde, mstr2csr, 4);
	ft_memmove(mstr3cde, mstr3csr, 4);
	printf("memmove: %s\tft_memmove: %s\n", mstr2cde, mstr3cde);
	
	// Test memchr
	char ch[] = "Hello World !";
	printf("memchr: %s\tft_memchr:%s\n", memchr(ch, 'o', 10), ft_memchr(ch, 'o', 10));
	printf("memchr: %s\tft_memchr:%s\n", memchr(ch, 'o', 100), ft_memchr(ch, 'o', 100));
	printf("memchr: %s\tft_memchr:%s\n", memchr(ch, 'a', 10), ft_memchr(ch, 'a', 10));
	printf("memchr: %s\tft_memchr:%s\n", memchr(ch, 'o', 0), ft_memchr(ch, 'o', 0));
	printf("memchr: %s\tft_memchr:%s\n", memchr(ch, 0600, 20), ft_memchr(ch, 0600, 20));

	// Test memcmp
	printf("memcmp: %d\tft_memcmp: %d\n", memcmp("aaa", "aaa", 4), ft_memcmp("aaa", "aaa", 4));
	printf("memcmp: %d\tft_memcmp: %d\n", memcmp("aa", "aa", 4), ft_memcmp("aa", "aa", 4));
	printf("memcmp: %d\tft_memcmp: %d\n", memcmp("a", "a", 0), ft_memcmp("a", "a", 0));
	printf("memcmp: %d\tft_memcmp: %d\n", memcmp("a", "b", 2), ft_memcmp("a", "b", 2));
	printf("memcmp: %d\tft_memcmp: %d\n", memcmp("a", "aa", 2), ft_memcmp("a", "aa", 2));
	printf("memcmp: %d\tft_memcmp: %d\n", memcmp("", "aa", 1), ft_memcmp("", "aa", 1));
	printf("memcmp: %d\tft_memcmp: %d\n", memcmp("b", "a", 1), ft_memcmp("b", "a", 1));
	

	return (0);
}
