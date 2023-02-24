#include <stdio.h>

void
read (int a[], int n)
{
  printf ("Enter the elements : ");
  for (int i = 0; i < n; i++)
    scanf ("%d", &a[i]);
}

void
simpleMerge (int a[], int f, int s, int t)
{
  int i = f, j = s, B[10], k = 0;
  while (i < s && j <= t)
    {
      if (a[i] < a[j])
	B[k++] = a[i++];
      else
	B[k++] = a[j++];
    }
  while (i < s)
    B[k++] = a[i++];
  while (j <= t)
    B[k++] = a[j++];
  for (int i = f, k = 0; i <= t;)
    a[i++] = B[k++];
}

void
Msort (int a[], int l, int r)
{
  if (l < r)
    {
      int mid = (l + r) / 2;
      Msort (a, l, mid);
      Msort (a, mid + 1, r);
      simpleMerge (a, l, mid + 1, r);
    }
}

void
print (int a[], int n)
{
  printf ("Sorted array : ");
  for (int i = 0; i < n; i++)
    printf ("%d\t", a[i]);
}


void
main ()
{
  int a[10], n;
  printf ("Ente the array size :");
  scanf ("%d", &n);
  read (a, n);
  Msort (a, 0, n - 1);
  print (a, n);
}
