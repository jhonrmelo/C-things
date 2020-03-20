#include <stdio.h>
#include <stdlib.h>

#include <string.h>
int palindromo(char *string, int ini, int fim);
int main()
{
  char strPalindromo[200];
  printf("Digite a expressao");
  gets(strPalindromo);
  int fim = strlen(strPalindromo);

  int retorno = palindromo(&strPalindromo, 0, fim - 1);

  if (retorno > 0)
  {
    printf("Palindromo");
  }
  else
  {
    printf("Nao e um palindromo");
  }
}

int palindromo(char *string, int ini, int fim)
{
  if (ini == fim)
  {
    return 1;
  }
  if (ini > fim)
  {
    return 1;
  }
  if (string[ini] == ' ')
  {
    return palindromo(string, ini + 1, fim);
  }
  if (string[fim] == ' ')
  {
    return palindromo(string, ini, fim - 1);
  }
  if (string[ini] == string[fim])
    return palindromo(string, ini + 1, fim - 1);
  else
  {
    return -1;
  }
}
