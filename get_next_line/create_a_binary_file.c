#include <stdio.h>
#include <fcntl.h>

int main() 
{
	/* Create the file */
	char x = 'a';
	FILE *fh = fopen ("file2.bin", "wb");
	if (fh != NULL) 
	{
		fwrite (&x, sizeof (x), 1, fh);
		fclose (fh);
	}

	/* Read the file back in */
	x = 'b';
	fh = fopen ("file2.bin", "rb");
	if (fh != NULL) 
	{
		fread (&x, sizeof (x), 1, fh);
		fclose (fh);
	}

	/* Check that it worked */
	printf ("Value is: %c\n", x);

	return (0);
}
